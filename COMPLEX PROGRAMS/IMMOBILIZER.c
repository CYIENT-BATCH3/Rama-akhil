/*
* File:   immobilizer.c
* Author: sk69648
*
* Created on September 24, 2022, 10:35 AM
*/




// PIC18F458 Configuration Bit Settings



// 'C' source line config statements



// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))



// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bit (Brown-out Reset disabled)
#pragma config BORV = 25        // Brown-out Reset Voltage bits (VBOR set to 2.5V)



// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)



// CONFIG4L
#pragma config STVR = OFF       // Stack Full/Underflow Reset Enable bit (Stack Full/Underflow will not cause Reset)
#pragma config LVP = OFF        // Low-Voltage ICSP Enable bit (Low-Voltage ICSP disabled)



// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-001FFFh) not code protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code protected)



// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code protected)



// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-001FFFh) not write protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write protected)



// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write protected)



// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-001FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from Table Reads executed in other blocks)



// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from Table Reads executed in other blocks)



// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


//.............................TILL NOW THE THE SETTING CONFIGURATION FOR MC IS HAPPENED..........................................................................
#include <xc.h>
#define ENABLE 1          //MACRO FOR ENABLE
#define DISABLE 0        //MACRO FOR DISABLE



#define _XTAL_FREQ 20000000   //SETTING FREQ AS PER CRYSTALL ON CHIP



enum modes{CONFIG_MODE = 0X80,NORMAL_MODE = 0X08};         //SETTING VALUE STATIC FOR MODE PERPOSE



char data_byte[11];        //ARRAY FOR STORE THE VALUES FROM THE BUFFERS
char door_status=0;        //BOOL FOR CHECKING THE DOOR STATUS 



void sys_init();          //SYSTEM INITIALISATION FUNCTON DECLARATION
void can_init();          //CAN INITIALISATION FUNCTON DECLARATION
void set_mode(char);      //SET MODE  FUNCTON DECLARATION
void get_mode(char);        //GET MODE  FUNCTON DECLARATION
void set_baudrate();          //SET BAURDRATE  FUNCTON DECLARATION



void set_mask();             //SET MASK  FUNCTON DECLARATION
void set_filter();            //SET FILER  FUNCTON DECLARATION
void can_read();             //CAN READ FUNCTION DECLARATION
//void led_fun();



void can_write(char);          //WRITE FUNCTION DECLARATION



void check_door_status();        //CHECK DOOR STATUS FUNCTION DECLARATION




void main(void)//.......................MAIN FUNCTUION........................
{
    
    TRISBbits.RB1 = 0;          //for trouble shooting purpose
    PORTBbits.RB1 = 0;
    
    TRISBbits.RB0 = 0;           //FOR DOOR STATUS BLINK LED ON THIS PORT
    PORTBbits.RB0 = 0;          //INITIALLY SETTING LOW
     
    sys_init();                //CALLING
    can_init();                         //CALLING
    set_baudrate();                //CALLING
    set_mask();                     //CALLING
    set_filter();                    //CALLING
    
    
    while(1)
    {                      //INFINATE LOOP
        if(door_status)      //CHECKING THE CONDITION
            PORTBbits.RB0 = ENABLE;              //LED ON
        else
            PORTBbits.RB0 = DISABLE;             //ELSE LED OFF
        can_write(door_status);                  //CALLING FUNCTION 
        __delay_ms(2000);                         //WAIT 2SEC 
        
        
        
    }
    
    
}
/*-------------- initialization of can bus -----------------------------------*/
void sys_init()               //DEFINATION FUNCTION
{
    GIE = ENABLE;
    PEIE = ENABLE;
    PIE3bits.RXB0IE =ENABLE;
    IPR3bits.RXB0IP=ENABLE;
    
}



void can_init()                     //DEFINATION FUNCTION
{
    TRISBbits.RB3 = ENABLE;
    TRISBbits.RB2 = DISABLE;
}



void set_baudrate()                    //DEFINATION FUNCTION
{
   
    set_mode(CONFIG_MODE);
    get_mode(CONFIG_MODE);
    BRGCON1 = 0XC1;
    BRGCON2 = 0XAE;
    BRGCON3 = 0X45;
    CIOCON = 0X20;
    set_mode(NORMAL_MODE);
   
    
   
}



void set_mode(char mode)                 //DEFINATION FUNCTION
{
   CANCON = mode;  
}




void get_mode(char mode)                    //DEFINATION FUNCTION
{
    while(CANCON != mode);
}



/*---------------- receiver code ----------------------------------------------*/
void set_mask()            //DEFINATION FUNCTION
{
    RXM0SIDH = 0x00;
    RXM0SIDL = 0x00;
}




void set_filter()              //DEFINATION FUNCTION
{
    RXF0SIDH = 0x00;
    RXF0SIDL = 0x00;
    RXF1SIDH = 0x00;
    RXF1SIDL = 0x00;
    
    //RXB0CON = 0x00;     //check at compilation
    
}




void can_read()                //DEFINATION FUNCTION
{
    CANCON = 0x0E;            //SETTING IN NORMAL MODE
    RXB0CON = 0x00;           //RECIVE BUFFER 
    
   
      data_byte[0] = RXB0D0;           //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[1] = RXB0D1;             //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[2] = RXB0D2;             //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[3] = RXB0D3;              //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[4] = RXB0D4;              //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[5] = RXB0D5;                 //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[6] = RXB0D6;               //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[7] = RXB0D7;               //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[8] = RXB0DLC;               //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[9] = RXB0SIDL;               //SAVING VALUE FROM THE BUFFER TO ARRAY
      data_byte[10]= RXB0SIDH;                //SAVING VALUE FROM THE BUFFER TO ARRAY
      
    
    RXB0CONbits.RXFUL = 0;                   //CLEARING RECIVE BUFFER
    
    check_door_status();                   //CHECKING DOOR STATUS
    
}



void __interrupt() ISR1()                      //FUNCTION DEFINATION
{
    if(PIR3bits.RXB0IF)                         //CHECKING THE ISR
    {
         
        PIR3bits.RXB0IF = DISABLE;              //IF IT IS OCCURS IT WILL COME TO INSIDE AND AGAIN IAM SETTING LOW AT THAT PERTICULAR REGISTER
        can_read();                              //CALLING CAN READ FUNCTION
        
    }
}



void check_door_status()                     //FUNCTION DEFINATION
{
    if(data_byte[3] == 0xAA &&  data_byte[4] == 0xAA && data_byte[5] == 0xAA && data_byte[6] == 0xAA && data_byte[7] == 0xAA)///CHECKING THE CONDITIONS AS PER REQUIREMENTS
        {
            door_status = 1;            //SETTING THE DOOR OPEN (SET LED TURN ON)
        }
        else
        {
            door_status = 0;             //SETTING THE DOOR CLOSE (SET LED TURN OFF)
        }
}




/*----------------------------- transmitter code ----------------------*/



void can_write(char door_status)            //WRITE FUNCTION
{
    __delay_ms(500);                          //WAIT 500MS
     CANCON = NORMAL_MODE;                       //SETTING IN NORMAL MODE 
     //while(CANSTAT != NORMAL_MODE); 
     CIOCON = 0X20;                              //CONTROLL REGISTER SETTING 
    
     
     TXB0SIDH = 0x00;                   //for address 66 for 77 it will be 0x0d high  0xd0 low
     TXB0SIDL = 0x08;                  //WRITING SOME VALUE TO BUFFER
     TXB0EIDH = 0x09;                    //WRITING SOME VALUE TO BUFFER
     TXB0EIDL = 0x32;                    //WRITING SOME VALUE TO BUFFER
     TXB0DLC = 0X08;                     //WRITING SOME VALUE TO BUFFER
     TXB0D0  = 0X00;                     //WRITING SOME VALUE TO BUFFER
     TXB0D1  = 0X00;                     //WRITING SOME VALUE TO BUFFER
     TXB0D2  = 0X00;                      //WRITING SOME VALUE TO BUFFER
     TXB0D3  = door_status;                 //WRITING SOME VALUE TO BUFFER
     TXB0D4  = 0X00;                       //WRITING SOME VALUE TO BUFFER
     TXB0D5  = 0X00;                       //WRITING SOME VALUE TO BUFFER
     TXB0D6  = 0X00;                       //WRITING SOME VALUE TO BUFFER
     TXB0D7  = 0X00;                         //WRITING SOME VALUE TO BUFFER
     TXB0CON = 0x08;                        //WRITING SOME VALUE TO BUFFER
}
