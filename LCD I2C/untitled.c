
#include <millis.h>

volatile unsigned long int timer0_overflow_count = 0;
volatile unsigned long int timer0_millis = 0;
static unsigned char timer0_fract = 0;

interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
// Place your code here
//TCNT0=0xF0;
//m++;

    unsigned long int m = timer0_millis;
    unsigned char f = timer0_fract;

    m += MILLIS_INC;
    f += FRACT_INC;
    if (f >= FRACT_MAX) {
        f -= FRACT_MAX;
        m += 1;
    }

    timer0_fract = f;
    timer0_millis = m;
    timer0_overflow_count++;
    
}

void millis_begin(){
  TCCR0 = (1<<CS01) | (1<<CS00);
  TIMSK = (1<<OCIE0);   
  #asm("sei")
}

unsigned long int millis()
{
 unsigned long int w;
 uint8_t oldSREG = SREG;
 
 #asm("cli")
 
 w = timer0_millis;
 SREG = oldSREG;
 
 return w;
}
