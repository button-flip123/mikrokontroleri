

#include "mcc_generated_files/mcc.h"

bool button1_stanje = 0;
bool button2_stanje = 0;
void main(void)
{
    //RD1 i RC2 input
    //RC0 output
    
    SYSTEM_Initialize();
    
    do{
        if(PORTDbits.RD1 == 0){
            button1_stanje = 1;
        }
        
        if(PORTCbits.RC2 == 0){
            button2_stanje = 1;
        }
        
        if((button1_stanje && PORTDbits.RD1==1) || (button2_stanje && PORTCbits.RC2==1)){
            
            if(button1_stanje){ button1_stanje = 0; }
            if(button2_stanje){ button2_stanje = 0; }
            PORTCbits.RC0 = ~PORTCbits.RC0;
        }
    }while(1);
}