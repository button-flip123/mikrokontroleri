#include "mcc_generated_files/mcc.h"

/*
    * PORTB bit 0 ulaz
    * PORTB bit 1 ulaz
    * PORTD bit od 0 do 6 output
    * PORTC bit od 0 do 6 output
*/

uint8_t i;
uint8_t j;

bool uvecaj_button = 0;
bool umanji_button = 0;

uint8_t maska(uint8_t kombinacija) {
  switch (kombinacija) {
    case 0 : return 0x3F;
    case 1 : return 0x06;
    case 2 : return 0x5B;
    case 3 : return 0x4F;
    case 4 : return 0x66;
    case 5 : return 0x6D;
    case 6 : return 0x7D;
    case 7 : return 0x07;
    case 8 : return 0x7F;
    case 9 : return 0x6F;
  }
}

void main(void)
{
    SYSTEM_Initialize();
    
    uint8_t num = 0;
    PORTC = PORTD = maska(num);
    do
    {
        if(PORTBbits.RB0 == 0){
            uvecaj_button = 1;
        }
        
        if(PORTBbits.RB1 == 0){
            umanji_button = 1;
        }
        
        if(uvecaj_button && PORTBbits.RB0 == 1){
            uvecaj_button = 0;
            if(num >= 9){
                num = 0;
                break;
            }
            num++;
        }
    
        if(umanji_button && PORTBbits.RB1 == 1){
            umanji_button = 0;
            if(num <= 0){
                num = 0;
                break;
            }
            num--;
        }
        PORTC = PORTD = maska(num);
    }while(1);
    
}