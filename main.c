

#define _XTAL_FREQ 4000000
#define BAUD_RATE 9600
#include <xc.h>
#include "Serial.h"


void main(void)
{
    char * d;
    serial_init();
    
        serial_reads(d ,2);
        //  serial_prints(d);
    while(1)
    {
          if(serial_readc()=='d'){
    serial_prints("hello serial stated at 9600");
          }
      
    }

    
}
