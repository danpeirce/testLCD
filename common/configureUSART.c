//****************************************************************************************
#include <xc.h>
#include <usart.h>       // library containing serial communtication functions
#include <delays.h>      // library containing delays - i.e. wait for time t

void configureUSART(unsigned long baudrate, unsigned char osc_freq_MHz)
{
  unsigned int spbrg;
	
  TRISCbits.TRISC6 = 0;     // set TX (RC6) as output 
  TRISCbits.TRISC7 = 1;     // and RX (RC7) as input

  // For a 16-bit sbprg value with USART_BRIGH_HIGH setting.
  // Formula from datasheet is Baudrate = FOSC/ (4 * (spbrg + 1 ))
  spbrg = (unsigned int)( ((float)osc_freq_MHz * 1.0e6) /(4.0*(float)baudrate) + 0.5 - 1.0); 

 
  OpenUSART( USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & 
             USART_CONT_RX & USART_BRGH_HIGH, spbrg );  
  // OpenUSART is part of the C18 usart.h library        
  
  BAUDCONbits.BRG16 = 1;  	// needed so we can use a 16-bit spbrg
							// Note that this is not discussed in the c18 Compiler Libraries guide
  Delay10KTCYx(1); // small 0.0125 s delay to allow communication speed to stabilize
					// part of the C18 delays.h library
}          
          
