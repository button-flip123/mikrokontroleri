#include "mcc_generated_files/mcc.h"

uint8_t maska(uint8_t kombinacija); 

uint8_t i; 
uint8_t j;


void main() {
  SYSTEM_Initialize();
  do
  {
      for(i = 0; i<= 9; i++)
      {
          for(j = 0; j<= 9; j++)
          {
              PORTD = PORTC = maska(j);
              __delay_ms(1000);
          }
      }
    /*
    while(i<=9){
        PORTD = PORTC = maska(i);
        __delay_ms(500);
        i++;
    }
    if(i>= 9){
        i=0;
    }
    */
  }while (1);
}

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