#include <p30f3012.h>

/*
 * 
 */

_FOSC(CSW_FSCM_OFF & FRC);
_FWDT(WDT_OFF);
_FBORPOR(MCLR_DIS & PBOR_OFF & BORV27 & PWRT_4);
_FGS(CODE_PROT_OFF & GWRP_OFF);

void __attribute__((interrupt, no_auto_psv)) _INT0Interrupt(void) {
    IFS0bits.INT0IF = 0;
    _LATC13 = 0; // Blue LED OFF
    d1();
}

void __attribute__((interrupt, no_auto_psv)) _INT1Interrupt(void) {
    IFS1bits.INT1IF = 0;
    _LATC13 = 1; // Blue LED ON
    d2();
}

void __attribute__((interrupt, no_auto_psv)) _INT2Interrupt(void) {
    IFS1bits.INT2IF = 0;

    _LATC14 = 0; // Red LED OFF
    d3();
    
}

void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void) {
    IFS0bits.CNIF = 0;
    _LATC14 = 1; // Red LED ON
    d4();
}

void Wait1S(void) {
    int i, j;

    for (i = 0; i < 125; i++) {
        for (j = 0; j < 3000; j++) {
        }
    }
}

void d1(void) {
    _LATB0 = 1;
    _LATB1 = 0;
    _LATB2 = 0;
    _LATB3 = 0;

}

void d2(void) {
    _LATB0 = 0;
    _LATB1 = 1;
    _LATB2 = 0;
    _LATB3 = 0;
}

void d3(void) {
    _LATB0 = 1;
    _LATB1 = 1;
    _LATB2 = 0;
    _LATB3 = 0;   
}

void d4(void) {
    _LATB0 = 0;
    _LATB1 = 0;
    _LATB2 = 1;
    _LATB3 = 0;
}

int main(void) {
    TRISB = 0x00d0; // LATB4, LATB6, LATB7 for input
    // 0000_0000_1101_0000
    ADPCFG = 0x00ff; // LATB7 - LATB0 digital input enabled
    LATB = 0x0000; // LATB7 - LATB0 output '0'
    TRISC = 0x0000; // RC13 - RC15 for all output
    LATC = 0x0000; // RC13 - RC15 output '0'
    TRISD = 0x0001; // RD0 for input

    _LATC14 = 1;
    Wait1S();
    _LATC14 = 0;

    INTCON2bits.INT0EP = 1; // negative edge trigger
    INTCON2bits.INT1EP = 1;
    INTCON2bits.INT2EP = 1;

    IFS0bits.CNIF = 0;
    IFS0bits.INT0IF = 0;
    IFS1bits.INT1IF = 0;
    IFS1bits.INT2IF = 0;
    CNEN1bits.CN6IE = 1;
    IEC0bits.CNIE = 1;
    IEC0bits.INT0IE = 1;
    IEC1bits.INT1IE = 1;
    IEC1bits.INT2IE = 1;

    while (1) {
        _LATC13 = 1;
        
        Wait1S();
        _LATC13 = 0;
        _LATB0 = 0;
    _LATB1 = 0;
    _LATB2 = 1;
    _LATB3 = 0;   
        Wait1S();
        
    }


    return 0;
}

