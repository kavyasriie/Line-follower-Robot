#include <16F72.h>

#use delay(clock=20000000)

void Robot_Forward()
{
   output_high(pin_C0);
   output_low(pin_C1);
   output_high(pin_C2);
   output_low(pin_C3);
}
void Robot_Left()
{
   output_high(pin_C0);
   output_low(pin_C1);
   output_low(pin_C2);
   output_high(pin_C3);
}
void Robot_Right()
{
   output_low(pin_C0);
   output_high(pin_C1);
   output_high(pin_C2);
   output_low(pin_C3);
}

void main()
{

   char ch;
   unsigned long flag = 0, count = 0;
   lcd_init();
   
   output_high(PIN_C5);  
   output_high(PIN_C4);
   delay_ms(700);
   output_low(PIN_C5);  
   output_low(PIN_C4);  
   delay_ms(700);
   output_high(PIN_C5);  
   output_high(PIN_C4);
   delay_ms(700);
   output_low(PIN_C5);  
   output_low(PIN_C4);     
   
   while(1)
   {     
            
      if((!input(PIN_B0)) && (!input(PIN_A0))) 
      {
         Robot_Forward();
      }
      else if((input(PIN_B0)) && (!input(PIN_A0))) 
      {
         Robot_Left();
      }
      
      else if((!input(PIN_B0)) && (input(PIN_A0))) 
      {
         Robot_Right();
      }
            
      delay_ms(100);
   }         
}
