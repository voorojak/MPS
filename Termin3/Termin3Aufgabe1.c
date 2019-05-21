// Loesung zu Termin3
// Aufgabe 1
// von:
// vom: 
// 

#include "../h/pmc.h"
#include "../h/tc.h"
#include "../h/pio.h"
#include "../h/aic.h"

void taste_irq_handler (void) __attribute__ ((interrupt));

// Interruptserviceroutine f�r die Tasten SW1 und SW2
void taste_irq_handler (void)
{
  StructPIO* piobaseB   = PIOB_BASE;		// Basisadresse PIO B
  StructAIC* aicbase  = AIC_BASE;		//__
	
// ab hier entsprechend der Aufgabestellung erg�nzen
// *************************************************

	
	
	aicbase->AIC_EOICR = piobaseB->PIO_ISR;	//__
}

// Timer3 initialisieren
void Timer3_init( void )
{
  StructTC* timerbase3  = TCB3_BASE;	// Basisadressse TC Block 1
  StructPIO* piobaseA   = PIOA_BASE;	// Basisadresse PIO B

	timerbase3->TC_CCR = TC_CLKDIS;	// Disable Clock
 
  // Initialize the mode of the timer 3
  timerbase3->TC_CMR =
    TC_ACPC_CLEAR_OUTPUT  |    //ACPC    : Register C clear TIOA
    TC_ACPA_SET_OUTPUT    |    //ACPA    : Register A set TIOA
    TC_WAVE               |    //WAVE    : Waveform mode
    TC_CPCTRG             |    //CPCTRG  : Register C compare trigger enable
    TC_CLKS_MCK1024;           //TCCLKS  : MCKI / 1024

  // Initialize the counter:
  timerbase3->TC_RA = 400;	//__
  timerbase3->TC_RC = 800;	//__

  // Start the timer :
  timerbase3->TC_CCR = TC_CLKEN ;	//__
  timerbase3->TC_CCR = TC_SWTRG ;	//__
  piobaseA->PIO_PER  = (1<<PIOTIOA3) ;	//__
  piobaseA->PIO_OER  = (1<<PIOTIOA3) ;	//__
  piobaseA->PIO_CODR = (1<<PIOTIOA3) ;	//__
}

int main(void)
{

	StructPMC* pmcbase	= PMC_BASE;		// Basisadresse des PMC
	StructPIO* piobaseA   	= PIOA_BASE;		// Basisadresse PIO A
	StructPIO* piobaseB   	= PIOB_BASE;		// Basisadresse PIO B

	pmcbase->PMC_PCER	= 0x4000;	// Peripheral Clocks einschalten f�r PIOB, _____ 
	
// ab hier entsprechend der Aufgabestellung erg�nzen
//**************************************************



	
	while(1)
	{

	}
	
	return 0;
}
