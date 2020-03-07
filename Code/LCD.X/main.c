/* 
 * File:   main.c
 * Author: IBRAHIM LABS
 *
 * Website: http://ibrahimlabs.blogspot.com/
 *
 * Created on September 7, 2013, 1:05 PM
 */

#include <xc.h>
#include <plib.h>

#include "LCD.h"

#ifndef OVERRIDE_CONFIG_BITS


    #pragma config FPLLIDIV = DIV_2         // PLL Input Divider
    #pragma config FPLLODIV = DIV_1         // PLL Output Divider
    #pragma config FPBDIV   = DIV_1         // Peripheral Clock divisor
    #pragma config FWDTEN   = OFF           // Watchdog Timer
    #pragma config POSCMOD  = HS            // Primary Oscillator
    #pragma config FNOSC    = PRIPLL        // Oscillator Selection
    #pragma config FPLLMUL  = MUL_20        // PLL Multipler

    /*  System clock = 80MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV) */

#endif // OVERRIDE_CONFIG_BITS
/*
 * 
 */
// PreProcessors
#define SYS_FREQ            (80000000L)                     // 80MHz system clock

int main() {

    /*  Configure device for max performance
     *  Warning!!!
     *          Do not change PBDIV configuration bit.
     *
     * This function changes ROM, RAM wait states and enable Prefetch
     * cache
     */
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
      
    Initialize_LCD();
    MoveCursorToPosition(FirstLine);
    WriteString_LCD("    Welcome to");
    MoveCursorToPosition(SecondLine);
    WriteString_LCD("IbrahimLabs.blogspot");
    MoveCursorToPosition(ThirdLine);
    WriteString_LCD("  This is LCD demo");
    MoveCursorToPosition(FourthLine);
    WriteString_LCD("   using PIC32MX");
    while(1);

    return 0;
}
