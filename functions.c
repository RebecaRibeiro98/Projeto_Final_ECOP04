#include<pic18f4520.h>
#include"bits.h"
#include"config.h"
#include"io.h"
#include"keypad.h"
#include"ssd.h"
#include"lcd.h"
#include "stdio.h"
#include "functions.h"
#include "led.h"
#include "delay.h"



void turn_on(){
    TRISB = 0x0F;
    PORTB = 0x80;
}
void turn_off(){
    TRISB = 0x0F;
    TRISD = 0x00;
    PORTB = 0x40;
    PORTD = 0x00;
    lcdCommand(0x01);
    
}
void setup(void){
    int temp;
    int def=0;
    lcdInit();
    char msg[40] = "Insira numero\nmaximo de\ndefeitos\n1 a 9:";
    printf(msg);
}
void input(){
    lcdInit();
    char msg[40] = "      Peca\n sendo inserida\n    aguarde";
    printf(msg);
    Tempo(3000);
}
void move(void){
    PORTCbits.RC2 = 1;
    lcdInit();
    char msg[40] = "    Mesa esta\n  movimentando\n    aguarde";
    printf(msg);
    Tempo(3000);
    PORTCbits.RC2 = 2;
}
void drill(){
    lcdInit();
    char msg[40] = "   Peca sendo\n     furada\n     aguarde";
    printf(msg);
    Tempo(3000);
}
void test(){
    lcdInit();
    int flag = 0;
    int tmp;
    char msg[40] = "   Furo sendo\n     testado\n     ";
    printf(msg);
    Tempo(3000);

}
void error(){
    lcdInit();
    char msg[40] = "      Peca\n      com    \n    Defeito       ";
    printf(msg);
    Tempo(3000);
}
void take(){
    lcdInit();
    char msg[40] = "   Peca sendo \n    retirada\n      ";
    printf(msg);
    Tempo(3000);
    
}