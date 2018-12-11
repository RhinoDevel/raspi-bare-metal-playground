
// Marcel Timm, RhinoDevel, 2018nov14

#include <stdbool.h>

#include "ui.h"
#include "ui_send_sample.h"
#include "../console/console.h"

void ui_enter()
{
    while(true)
    {
        char c[2];

        console_writeline("s - Send a sample.");
        console_write("? ");
        console_read(c, 2);
        console_writeline("");

        switch(c[0])
        {
            case 's':
                ui_send_sample();
                break;
            default:
                console_writeline("Please select a menu entry.");
                break;
        }
    }
}