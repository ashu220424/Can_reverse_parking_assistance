#include <LPC21xx.h>
#include "proj_header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
#define delay                   \
    for (i = 0; i < 65000; i++) \
        ;
unsigned int range = 0, i;
u32 flag = 0;
u32 dummy;
CAN2 RN,TN;
int main()
{
    VPBDIV = 0x01; // PCLK = 60MHz
    IODIR1 = 0xffffffff;
    us_init();
    uart0_init(9600);
    can2_init();
    config_vic();
    en_CAN_intr();
    uart0_tx_string("REVERSE PARK ASSIST\r\n");
    while (1)
    {
        if (RN.id==0x1AB)
        {
            while (flag == 1)
            {
                uart0_tx_string("in loop\r\n");
//								IOCLR0=LED1|LED2|LED3;
//								range=get_range();
//								TN.id=0x2BC;
//								TN.rtr=0;
//								TN.dlc=4;
//								if (range>=150)
//								{
//									TN.byteA=0x11;
//								}
//								else if (range>=100 && range<150)
//								{
//									TN.byteA=0x22;
//								}
//								else if (range>=50 && range<100)
//								{
//									TN.byteA=0x33;
//								}
//								else if (range>=3 && range<50)
//								{
//									TN.byteA=0x44;
//								}
//								else if (range<3)
//								{
//									TN.byteA=0x11;
//								}
//								can2_tx(TN);
//								delay_ms(500,1);
            }
        }
				else{
        dummy = 0;
        flag = 0;
				}
    }
}

