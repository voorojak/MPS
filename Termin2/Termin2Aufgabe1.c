// Loesung zu Termin2
// Aufgabe 1
// von:
// vom: 
// 

#include "../h/pmc.h"
#include "../h/pio.h"

int main(void)
{
  StructPMC* pmcbase = PMC_BASE;	// Basisadresse des PMC
  StructPIO* piobaseB = PIOB_BASE;	// Basisadresse PIOB
  piobaseB->PIO_PER = ALL_LEDS;
  piobaseB->PIO_OER = ALL_LEDS;
  
  while(1)
  {
    piobaseB->PIO_CODR = ALL_LEDS;
    piobaseB->PIO_SODR = ALL_LEDS;
  }
    
  return 0;
}
