
//***************************************************************************************
 
#include <stdio.h>          // library containing printf() function
#include <delays.h>
#include "common\osc.h"            // library for set_osc_32MHz()
#include "common\configureUSART.h" // library for configureUSART(baud)


// These are not C statements but directives to the C18 compiler. They result in configuration
// bits in the PIC18F4525 being set in the flash memory. This configuration is set when the 
// PIC is programmed by the PICkit2 programmer and before any program starts to run in the PIC.

#pragma config WDT = OFF
#pragma config OSC = INTIO7      // puts osc/4 on pin 10 on 28 pin package) to check freq
#pragma config MCLRE = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF      // PORTB<4:0> are digital IO 


void WaitOneSecond(void);

void main(void)  // a C project can only have one main() function
{

	
    set_osc_8MHz(); // set MCU to run at 8 MHz
    configureUSART(9600ul, 8); 
    printf("%c%c",0x7C,128); // dim backlight to min to save power       
 //   Delay10KTCYx(190);
    WaitOneSecond();
    WaitOneSecond();
    WaitOneSecond();
    Delay10KTCYx(200); // wait 10 000 * 200 * TCY = 0.250 seconds 
//    printf("%c",0x12); // reset to 9600 bps
    
 

//    printf("%c%c",0x7C,0x04); // 16 character (w) display  
//    printf("%c%c",0x7C,0x06); // 2 line display  

    printf("%c%c",0xFE,0x01); //Command - clear and zero display
                                  
    Delay10KTCYx(200); 
    printf("%c%c",0x7C,128); // dim backlight to min to save power       
    Delay10KTCYx(190);  
//    Delay10KTCYx(190);                                
 //   printf("%c%c",0xFE,0x09);    // toggle splash screen
 //   printf("%c%c",0xFE,0x0E);    // turn on underline cursor
//   printf("%c%c",0xFE   ,0x0C);    // turn cursor off
                              
    printf("PIC18LF2620@3.3V");
    printf("KPU PHYS1600  ");
//    printf("test    APSC129");
    
//  	printf("  Sparkfun.com  "); // 16 chars wide to fill top line of LCD
//    printf("  SerLCD v2     "); 
//    printf("%c%c",0x7C,0x0A);
  

    while(1)
    {
       WaitOneSecond(); 
    }	

}

void WaitOneSecond(void)
{
    Delay10KTCYx(200); // wait 10 000 * 200 * TCY = 1.0 seconds

}


