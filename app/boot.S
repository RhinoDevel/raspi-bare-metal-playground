
// Marcel Timm, RhinoDevel, 2019aug22

// See: https://sourceware.org/binutils/docs-2.29/as/index.html

.section ".text.boot"

.globl _start

// Kernel entry point.
//
// r15: Execution should start at 0x8000 (r15 is the program counter pc).
//
// r0 : 0 = Boot device code.
// r1 : 0x00000C42 = ARM Linux Machine Type,
//                   see: http://www.arm.linux.org.uk/developer/machines/
// r2 : 0x00000100 = ATAGs beginning,
//                   see: http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html#appendix_tag_reference
//
// Preserve registers r0, r1 and r2 (above) to be used as parameters of
// kernel_main().
//
_start:

_handler_arm_reset:

/*
    // ****************************************
    // *** Uncomment for PERI_BASE_PI2AND3! *** START
    // ****************************************

    // Return CPU ID (0, 1, 2 or 3) of the CPU currently executing this code:
    //
    mrc     p15, #0, r3, c0, c0, #5 // R3 <= Multiprocessor affinity register (MPIDR).
    and     r3, r3, #3 // R3 = CPU ID (bits 0 and 1).
    cmp     r3, #0

    bne     halt // If CPU ID is NOT 0, branch to infinite loop.
    //
    // Code to test, if starting secondary cores worked (it works on Raspi 2):
    //
//    cmp     r3, #1
//    bne     halt // If CPU ID is neither 0, nor 1, branch to infinite loop.
//    //
//    // Set stack address for CPU 1 (grows downwards to address 0):
//    //
//    // * TODO: Test / find out, if we already are in supervisor mode, here
//    //         (otherwise setting SP won't work, here..)!
//    //
//	mov sp, #0x02F00000 // Above 32kB address.
//    //ldr sp, =0x04000000 // Above 64MB address.
//    //
//    bal     act_led_blink_loop // Let CPU 1 blink ACT LED infinitely.

    // Switch from hypervisor to supervisor mode, if necessary:
    //
    .arch_extension virt
    mrs		r3, cpsr // Copies current program status register content to R3.
    and		r3, r3, #0b11111//#0x1F // Get processor mode bits from CPSR-copy
                                    // held in R3.
    cmp		r3, #0b10011//#0x13 // Are we in SVR (supervisor) mode, yet?
    beq		is_supervisor // We are already in SVR mode. Go on below.
    //
    // We are assuming to be in hypervisor mode:
    //
    mov		r3, #0b10011//#0x13 // Set R3's "mode bits" to SVR mode.
    msr		spsr_cxsf, r3 // Update whole [by adding "c" (bits 0-7), "x" (bits
                          // 8-15), "s" (bits 16-23) and "f" (bits 24-31) as
                          // fields - order is not important] saved program
                          // status register with contents of R3. 
    add		r3, pc, #4
    msr		ELR_hyp, r3 // ELR_hyp holds the address to return to, when an
                        // exception-taken-to-HYP.
    eret // Return from an exception-taken-to-HYP. This instructions belongs to
         // virtualization extensions. In HYP mode, PC will be loaded from
         // ELR_hyp, CPSR from SPSR_hyp.

is_supervisor:

    // On a Raspberry Pi 2, at least L1 instruction cache is necessary for speed
    // (without it, e.g a simple loop counting from 0 <= 50 takes ~16us!):
    //
    mrc p15, #0, r3, c1, c0, #0 // R3 <= System control register
    orr r3, #0x0800 // Branch prediction (bit 11).
    orr r3, #0x1000 // L1 instruction caches (Bit 12).
    orr r3, #0x0004 // L1 data cache (bit 2).
    mcr p15, #0, r3, c1, c0, #0 // System control register <= R3
*/

    // *****************************************
    // *** Uncomment for PERI_BASE_PI2AND3!  *** END
    // *****************************************

    // TODO: Make sure that enabled branch prediction and L1 caches (see above)
    //       do not make problems. If not, enable them for Pi 1, too.

    // Copy interrupt vector table and constants into position:

    ldr r3, =ivt_src
    mov r4, #0 // Copy to 0x00000000.

    // Vector table:
    //
    ldmia r3!, {r5, r6, r7, r8, r9, r10, r11, r12}
    stmia r4!, {r5, r6, r7, r8, r9, r10, r11, r12}

    // Constants:
    //
    ldmia r3!, {r5, r6, r7, r8, r9, r10, r11, r12}
    stmia r4!, {r5, r6, r7, r8, r9, r10, r11, r12}

    // Switch to correct mode to set IRQ stack pointer:
    //
    mov r3, #0xD2 // #(0x12 | 0x80 | 0x40) // IRQ mode | IRQ inhibit | FIRQ inhibit.
    msr cpsr_c, r3

    // Set IRQ stack address (grows downwards to address 0):
    //
    mov sp, #0x03F00000 // Above 32kB address.
    //ldr sp, =0x06000000 // Above 64MB address.

    // Switch back to supervisor mode:
    //
    mov r3, #0xD3 // #(0x13 | 0x80 | 0x40)  // SVR mode | IRQ inhibit | FIRQ inhibit.
    msr cpsr_c, r3

	// Set stack address (grows downwards to address 0):
    //
	mov sp, #0x03700000 // Above 32kB address.
    //ldr sp, =0x04000000 // Above 64MB address.

	// Set whole BSS section to zero (it is optional, but C standard):

	ldr r4, =__bss_start // See: https://community.arm.com/processors/b/blog/posts/how-to-load-constants-in-assembly-for-arm-architecture
	ldr r9, =__bss_end
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	b       2f

1:
	stmia r4!, {r5-r8}

2:
	cmp r4, r9
	blo 1b

	// Call kernel_main():
    //
	ldr r3, =kernel_main
	blx r3

	// Halt (also used for unused cores in multiprocessor system - see above):
    //
halt:
	wfe // Wait for event (hint). Allows a core to enter low-power state!
	b halt

ivt_src:

    // Interrupt vector table (must be copied to 0x00000000, followed by
    // constants below, because LDR uses relative adressing):
    //
    ldr pc, _vector_arm_reset // Also jumps to reset handler on start-up.
    ldr pc, _vector_undefined_instruction
    ldr pc, _vector_swi
    ldr pc, _vector_abort_prefetch
    ldr pc, _vector_abort_data
    ldr pc, _vector_addr_exception
    ldr pc, _vector_irq
    ldr pc, _vector_fiq

    // Constants for interrupt vector table:
    //
_vector_arm_reset:
    .word _handler_arm_reset
_vector_undefined_instruction:
    .word handler_undefined_instruction
_vector_swi:
    .word handler_swi
_vector_abort_prefetch:
    .word handler_abort_prefetch
_vector_abort_data:
    .word handler_abort_data
_vector_addr_exception:
    .word handler_addr_exception
_vector_irq:
    .word handler_irq
_vector_fiq:
    .word handler_fiq
