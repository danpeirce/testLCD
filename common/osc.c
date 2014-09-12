/* file osc.c */
//***********************************************************************************
//                          set_osc_8MHz()
//    sets the oscillator from the default 1 MHz to 8 MHz
//***********************************************************************************

#include <xc.h>
#include "osc.h"

void set_osc_8MHz(void)
{
  int i;
 
  OSCCONbits.IRCF2 = 1;     // Set the OSCILLATOR Control Register to 8 MHz
  OSCCONbits.IRCF1 = 1;      
  OSCCONbits.IRCF0 = 1;     

    
}
