#include "lpc24xx.h"

struct _bit_fields{
    unsigned int    a:4,
                    b:8,
                    c:20;
};
// Initialize ADC.
void setup_ADC(void) {
	PINSEL1 |= (1 <<21);
    PINSEL1 &= ~(1 <<20); 
    FIO0DIR |= (1<<26);
	
}

// udelay should delay the processor for 'delay_in_us' number of microseconds.
// * LPC24XX.h contains a definition for the PCLK, "Fpclk"
//   use this definition for PCLK as defined in the manual.
// * Use Timer 0. This means you MUST use the prefix T0 for every control
//   register, i.e. T0TCR.
// * Make sure you reset the timer, and when you start the timer ENSURE you
//   set the reset bit back to zero!
void udelay(unsigned int delay_in_us) {
		T0PR = 71;
		T0MR0 = delay_in_us;
		T0MCR |= 4; // stop when TC = MR0	
	    T0TCR = 2; // reset timer
		T0TCR = 1; // start timer;
	
		while ((T0TCR & 1) > 0); // check if the timer is enable
		
		T0TCR = 2; // reset timer
		
		
}