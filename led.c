#include "config.h"
#include"led.h"
#define TRISB *(volatile __near unsigned char*) 0xF93
#define PORTB *(volatile __near unsigned char*) 0xF81

void ConfiguraLed(void)
{
    TRISB = 0x00;
    PORTB = 0x00;
}
void LigaLed(char a)
{
    if(a=='0')
    {
        PORTB =PORTB| 0x01;
    }
    else if(a=='1')
    {
       PORTB = PORTB|0x02; 
    }
    else if(a=='2')
    {
       PORTB = PORTB|0x04; 
    }
    else if(a=='3')
    {
       PORTB = PORTB|0x08; 
    }
    else if(a=='4')
    {
       PORTB = PORTB|0x10; 
    }
    else if(a=='5')
    {
       PORTB = PORTB|0x20; 
    }
    else if(a=='6')
    {
       PORTB = PORTB|0x40; 
    }
    else if(a=='7')
    {
       PORTB = PORTB|0x80; 
    }
}

void DesligaLed(char a)
{
    if(a=='0')
    {
        PORTB = PORTB&0xFE;
    }
    else if(a=='1')
    {
       PORTB = PORTB&0xFD; 
    }
    else if(a=='2')
    {
       PORTB = PORTB&0xFB; 
    }
    else if(a=='3')
    {
       PORTB = PORTB&0xF7; 
    }
    else if(a=='4')
    {
       PORTB = PORTB&0xEF; 
    }
    else if(a=='5')
    {
       PORTB = PORTB&0xDF; 
    }
    else if(a=='6')
    {
       PORTB = PORTB&0xBF; 
    }
    else if(a=='7')
    {
       PORTB = PORTB&0x7F; 
    }
}

