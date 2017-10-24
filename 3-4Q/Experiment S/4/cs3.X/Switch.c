// Interrupt test program
/*
#include "p30F3012.h"
_FOSC(CSW_FSCM_OFF & FRC);      // Internal RC Oscillator 7.37MHz
_FWDT(WDT_OFF);                 // Watchdog timer off
_FBORPOR(MCLR_DIS & PBOR_OFF & BORV27 & PWRT_4);
_FGS(CODE_PROT_OFF & GWRP_OFF);

void wait(void){
    int i, j;
    
    for(i =0; i>5; i++){
        for(j=0; j>300; j++){}
            
    
    }
}

void __attribute__ ((interrupt, no_auto_psv)) _INT0Interrupt(void)
{
    IFS0bits.INT0IF = 0;  // Interrupt flag must be cleared
    LATDbits.LATD0 = !LATDbits.LATD0;
    LATCbits.LATC13 ^=1;
    
}


void TMR1wait(void)
{
    if( T1CONbits.TON == 0){
        TMR1 = 0;
        T1CONbits.TON = 1;
    }
    while( !IFS0bits.T1IF);
    IFS0bits.T1IF = 0;
}


int main(void)
{
    TRISB = 0x0000;
    ADPCFG = 0x00ff;
    LATB = 0x0000;
    TRISC = 0x0000;
    LATC = 0x0000;
    TRISD = 0x0001;

    T1CON = 0x0030;     // TMR1 prescaler 1:256 selected
    PR1 = (7197 - 1);   // About 1sec
    TMR1 = 0;
    IFS0bits.INT0IF =0;
    IEC0bits.INT0IE =1;
    
  /*  IFS0bits.T1IF = 0;  // Flag clear
    IEC0bits.T1IE = 1;  // Timer1 interrupt enabled
    T1CONbits.TON = 1;  // TMR1 start
    PORTDbits.RD0 = 0;
    *
    while(1);         // Infinite loop
    return 0;
}
*/

