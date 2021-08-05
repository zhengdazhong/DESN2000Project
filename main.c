#include "lpc24xx.h"

extern void udelay(unsigned int delay_in_us);
extern void setup_ADC(void);

int main(void) {
	int rate = 52000; 
	
	int i = 0;

	// Setup the DAC 
	setup_DAC();
	
	// while timer != match
	while(1) {
		if () { 		
								
		} else { 
			
		}
	}

}
