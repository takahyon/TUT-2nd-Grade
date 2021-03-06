// Timer test program
//
#include "p30F3012.h"
_FOSC(CSW_FSCM_OFF & FRC);      // Internal RC Oscillator 7.37MHz
_FWDT(WDT_OFF);                 // Watchdog timer off
_FBORPOR(MCLR_DIS & PBOR_OFF & BORV27 & PWRT_4);
_FGS(CODE_PROT_OFF & GWRP_OFF);

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
    IFS0bits.T1IF = 0;  // Flag clear
    T1CONbits.TON = 1;  // TMR1 start

    while(1){
        LATCbits.LATC13 = 1;
        TMR1wait();
        LATCbits.LATC13 = 0;
        TMR1wait();
    }
    return 0;
}

