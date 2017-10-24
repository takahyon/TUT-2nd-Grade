#include <p30f3012.h>
#include <libpic30.h>           // __delay_ms()????????
/*
// ??????????????
_FOSC(CSW_FSCM_OFF & FRC);      // Internal RC Oscillator 7.37MHz
_FWDT(WDT_OFF);                 // Watchdog timer off
_FBORPOR(MCLR_DIS & PBOR_OFF & BORV27 & PWRT_4);
_FGS(CODE_PROT_OFF & GWRP_OFF);


//##### INT0???? #####
void StartINT0(void);       // INT0????
void StopINT0(void);        // INT0 ????

// INT0??????
void __attribute__((interrupt, shadow, auto_psv)) _INT0Interrupt(void)
{
    IFS0bits.INT0IF = 0;     // INT0??????????
    LATDbits.LATD0 = !LATDbits.LATD0;         // RD0 high <=> low
    LATCbits.LATC13 ^= 1;
}

//##### main #####
int main(void)
{
    int dmmy;
    
    TRISBbits.TRISB6 = 1;       // RD0(17pin)??????
    TRISDbits.TRISD0 = 0;       // RD0(34pin)??????
    TRISCbits.TRISC14 =0 ;
    StartINT0();              // INT1????
    while(1){
        dmmy = 0;
    }

    return (0);
}

//##### INT0???? #####
void StartINT0(void)
{
 INTCON2bits.INT0EP = 1; // 1 = ???????????????
 IEC0bits.INT0IE = 1; // INT0 ??
 
}

void StopINT0(void)
{
 IEC0bits.INT0IE = 0; // INT1 ???
}
 * */