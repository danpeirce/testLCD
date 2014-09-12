# testLCD


For testing a 2x16 serial LCD display with a PIC18F MCU

Target PIC18LF2620 running at 3.3 volts.
May add other PIC targets.

testLCD33.c is just a short simple file. Some of the lines are commented out. So far I am simply uncommenting the 
lines I need for different purposes depending on the current state of a LCD module I am testing. In this way I can

* change the splash screen
* change the cursor type
* change the baud rate

The goal is to make sure the display works and get them all in a common condition. 
