/* 
 * File:   main.c
 * Author: Rebeca Ribeiro
 *
 * Created on 4 de Julho de 2021, 15:06
 * Tema: Mesa giratória furadora e testadora de peças
 * Funcionalidades: LEDS representando atuadores 
                    Display 7 segmentos agindo como contador de peças
                    LCD sinalizando o processo 
 *                  Cooler para representação do giro da mesa 
 *                  Teclado Numérico para setar quantidade de peças
 *                  Buzzer como alarme sonoro.
 */

#include<pic18f4520.h>
#include "led.h"
#include"bits.h"
#include"config.h"
#include"io.h"
#include"keypad.h"
#include"ssd.h"
#include"lcd.h"
#include "stdio.h"
#include "functions.h"
#include "delay.h"
#include "atraso.h"
#define cooler PORTCbits.RC2;

int main(void) {
    TRISC = 0x00;
    PORTCbits.RC2 = 0;
    PORTCbits.RC1 = 1;
    int temp, temp2,temp3, temp4;
    int estado = 0;
    int flag = 0;
    int flag1 = 0 ;
    int flag2 = 0;
    int tempo = 0;
    int def = 0;
    int count= -1;
    char msg[40] = "Pressione *\nPara Ligar           ";
    lcdInit();
    ssdInit();
    kpInit();
    printf(msg);
    TRISD = 0x00;
    PORTD = 0x00;
    TRISB = 0x0F;
    PORTB = 0x40;
    
    for(;;){

        while(count <def){
            kpInit();
            if(kpRead()!=temp){
                 temp = kpRead();
                 if(bitTst(kpRead(), 0) && flag==0) {
                     turn_on();
                     //PORTB = 0x80;
                     flag = 1;
                     estado = 1;
                     setup();
                     //turn_on();
                     TRISD = 0x00;
                     PORTD = 0x00;
                 }
             }
           
    
             if(estado==1 && flag ==1){
                 kpInit();
                 if(kpRead()!=temp2){
                     temp2 = kpRead();
                     if(bitTst(kpRead(), 4)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 0;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 3)) {
                         //turn_on();
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 1;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 7)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 2;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 11)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 3;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 2)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 4;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 6)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 5;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 10)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 6;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 1)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 7;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 5)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 8;
                         estado = 2;
                     }
                     if(bitTst(kpRead(), 9)) {
                         TRISD = 0x00;
                         PORTD = 0x00;
                         count = 0;
                         def = 9;
                         estado = 2;
                     }
                 }
             }
            if(estado==2 && flag==1){
                input();
                estado = 3;
            }
             if(estado==3 && flag==1){
                 move();
                 estado = 4;
             }
            if(estado == 4 && flag ==1){
                drill();
                estado = 5;
            }
            if(estado==5 && flag==1){
                 move();
                 estado = 6;
             }
            if(estado==6 && flag==1){
                 test();
                 estado = 7;
            }
            if(estado==7 && flag==1){     
                 kpInit(); 
                 //while(flag1==0){
                 if(kpRead()!=temp3){
                     temp3 = kpRead();
                     if(bitTst(kpRead(),8)){
                         //error();
                         //turn_on();
                         TRISD = 0x00;
                         PORTD = 0x00;
                         flag1 = 1;
                         estado = 8;
                     }
                     if(bitTst(kpRead(),0)){
                         //turn_on();
                         TRISD = 0x00;
                         PORTD = 0x00;
                         estado = 9;
                     }
                 }
              
            }
            if(estado==8 && flag==1 &&flag1==1){
                error();
                count++;
                estado = 9;
            }
            
            if(estado==9 && flag==1){
                 move();
                 estado = 10;
             }
            if(estado==10 && flag==1){
                 take();
                 estado = 2;

            }

        
        kpDebounce();

    }
        
    if(def==count){
        PORTCbits.RC1 = 0;
        ssdInit();
        ssdDigit(count,3);
        //atraso_ms(20);
        //ssdUpdate;
        //PORTD = 0x80;
    }    
        
    kpInit();     
    if(kpRead()!=temp4){
        temp4 = kpRead();
        if(bitTst(kpRead(),0)){
            flag2 = 1;
        }
    }
    ssdUpdate();   
    kpDebounce();
    for (tempo = 0; tempo <550; tempo++); 
    if(flag2 == 1){
        PORTCbits.RC1 = 1;
        //atraso_ms(4);
        turn_off();
        //PORTD = 0x40;
    }
    //ssdUpdate();

                 
   
    for (tempo = 0; tempo <420; tempo++);    

    }
    return 0;
}

