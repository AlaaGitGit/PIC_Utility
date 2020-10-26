#ifndef SERIAL_H
#define SERIAL_H
#endif 

#ifndef _XTAL_FREQ
#error "You must decleare _XTAL_FREQ""
#endif

#ifndef BAUD_RATE 
#error "You must decleare BAUD_RATE"
#endif

#include <string.h>
int version = 0x1;

void serial_init(void);
void serial_printc(char);
void serial_prints(char*);
char serial_readc(void);
void serial_reads(char* ,int);


void serial_init(){
    TRISB1 = 0;  // RX pin
    TRISB2 = 1;  // TX pin
    SPBRG = ((_XTAL_FREQ/16)/BAUD_RATE) - 1;  // set baud rate
    BRGH = 1;  // high speed mode
    SPEN = 1;
    SYNC = 0;
    TXEN = 1;  // transmit enable 
  //  RXEN = 1;  // receive enable 
    CREN = 1;  // continues transmit receive enable 
    
    TX9 = 0; //....................
    RX9 = 0; // 8-bit mode reception 
}

void serial_printc(char _char)
{
    while(!TXIF); // wait until transmit buffer free
    TXREG = _char; // put data to register 
}

void serial_prints(char * _string)
{
    while(*_string) // if have char
    {
        serial_printc(*_string++); // split string and print as char
    }
}

char serial_readc(void)
{
    if(OERR) // if have error 
    {
        CREN = 0; // disable continues transmit receive 
        CREN = 1; // enable ..........................
    }
    return RCREG;  //return serial receive data
}

void serial_reads(char *_data ,int size)
{
    int i = 0;
    char *d;
    
    //_data = "good bye";
    while((d=serial_readc())!= 'o'){
       // serial_printc(_data[i]);
       
        
        serial_prints("in scanning");
        serial_printc(t);
        i++;
        
    }
    
    serial_prints("end of scan");
   serial_prints(_data);
}
