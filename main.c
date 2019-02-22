

#include "mcc_generated_files/mcc.h"
#include "font.h"


#define _XTAL_FREQ 16000000

   #define DC PORTCbits.RC5
   #define RST PORTCbits.RC6
#define CS PORTCbits.RC4


#define PAGE0 0xB0
#define PAGE1 0xB1
#define PAGE2 0xB2
#define PAGE3 0xB3
#define PAGE4 0xB4
#define PAGE5 0xB5
#define PAGE6 0xB6
#define PAGE7 0xB7






uint8_t     readDummy;

void oledrst(void);
void oledcmd(char data);
void oledwriteram(char data);
void oledsetpage(char page);
void oledinit(void);
void oledclear(void);


/*
                         Main application
 */
void main(void)
{
 
    // initialize the device
    SYSTEM_Initialize();
    SPI_Initialize();
    oledinit();

    while(1){
    
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c0[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c1[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c2[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c3[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c4[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c5[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
oledsetpage(PAGE0);   
for(int i = 87; i > 0; i--){       
oledwriteram(c6[i]);
if(i == 66 )
oledsetpage(PAGE1); 
if(i == 44 )
oledsetpage(PAGE2);
if(i == 22 )
oledsetpage(PAGE3);
}
__delay_ms(1000);
    }

SLEEP();

   
}

void oledrst(void){
    CS = 0;
    RST = 1;
    __delay_ms(10);
    RST = 0;
    __delay_ms(10);
    RST = 1;
    __delay_ms(10);
    CS = 1;
}

void oledcmd(char data){
    CS = 0;
    DC = 0;
    readDummy = SPI_Exchange8bit(data);
    DC = 1;
    CS = 1;
}



void oledwriteram(char data){
CS = 0;
DC = 1;
readDummy = SPI_Exchange8bit(data);
CS = 1;
}

void oledsetpage(char page){
oledcmd(0x00);                     // Set Lower Column
oledcmd(0x10);                     // Set Higher Column
oledcmd(page);                     // Set Page Start
}

void oledinit(void){
    oledrst();
    oledcmd(0xAE);
    oledcmd(0x81);
    oledcmd(0xCF);
    oledcmd(0xA4);
    oledcmd(0xA6);
    
oledcmd(0x20); 
oledcmd(0x02); // Set Memory Addressing Mode

oledcmd(0x00);                     // Set Lower Column
oledcmd(0x10);                     // Set Higher Column
oledcmd(0xB0);                     // Set Page Start

oledcmd(0x40);                     // Set Display Start Line
oledcmd(0xA0);                     // Set Segment Re-map
oledcmd(0xA8); 
oledcmd(0x3F); // Set Multiplex Ratio
oledcmd(0xC0);                     // Set COM Output
oledcmd(0xD3); 
oledcmd(0x00); // Set Display Offset
oledcmd(0xDA); 
oledcmd(0x12); // Set COM Pins Hardware Configuration

oledcmd(0xD5); 
oledcmd(0x80); // Set Display Clock
oledcmd(0xD9); 
oledcmd(0xF1); // Set Pre-charge Period
oledcmd(0xDB);
oledcmd(0x40); // Set VCOMH Deselect Level
oledcmd(0x8D); 
oledcmd(0x14); // Charge Pump Setting
oledclear();
oledcmd(0xAF);
}

void oledclear(void){
    
int page = 0xB0;
oledsetpage(page);

for(int x = 8; x > 0; x--){
for(int i = 128; i > 0; i--){       
oledwriteram(0x00);
}
page++;
oledsetpage(page);
}
}

/**
 End of File
*/