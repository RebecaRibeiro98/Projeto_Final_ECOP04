#include "delay.h"

void Tempo (unsigned int a)
{
    volatile unsigned char j, k; 
    unsigned int i; 
    for (i = 0; i < a; i++) {
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
}


