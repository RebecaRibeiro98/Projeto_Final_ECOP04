#include "stdio.h"
#include "lcd.h"

void printf(char S[40]){
    int count = 1;
    for (int i=0; i<40;i++){
        if(S[i]=='\n')
        {
            if(count==1)
                lcdCommand(0xC0); //linha dois
            else if (count == 2)
            {
                lcdCommand(0x90); // linha tres
            }
            else if (count == 3){
                lcdCommand(0xD0);//linha quatro
            }
            count++;
        }
        else{
        lcdData(S[i]);
        }
        
    }
}
