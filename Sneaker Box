#include <16f887.h> //definimos el microcontrolador a utilizar
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT //de forma inicial mantenga esta configuración
#use delay(clock=20M) //configuramos el cristal de cuarzo a utilizar
#use I2C(MASTER, SDA=PIN_C4, SCL=PIN_C3, FAST) //definicion de los pines para establecer comunicacion I2C
#use standard_io(B)

#define ADDRESS_LCD 0x4E //direccion del modulo LCD por protocolo i2C
#include <LCD_I2C.c>
#include <NEC_ir.c>
#define led_1 PIN_E0// Led 1
#define motor_1 PIN_B1


void main()
{
  output_low(led_1);
  output_low(motor_1);
  lcd_init();
  nec_ir_init();
 
  lcd_clear();
  lcd_gotoxy(1,1);
  lcd_putc("Address: 0x0000");
  lcd_gotoxy(1,2);
  lcd_putc("Code: 0x0000");
 
  while(true)
  {
    if(nec_data_read == 1)
    {
      nec_data_read = 0;
      nec_get_data();
      unsigned long address = read_ir_address();
      unsigned long ir_code = read_ir_code();
     
       if(ir_code == 0x926D){                          // Tecla 1, enciende el led 1
            output_high(led_1);
         }
         if(ir_code == 0x936C){                          // Tecla 2, apaga el led 1
            output_low(led_1);
         }
         
         if(ir_code == 0xCC33)
         {
         
           output_high(motor_1);
         }
         
         if(ir_code == 0x8E71)
         {
         output_low(motor_1);
         }
         
         
       
     
      lcd_clear();
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Address: 0x%LX",address);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Code: 0x%LX", ir_code);  
    }
  }
}
