#include <LPC21xx.h>
#include "proj_header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
#define BUZ (1<<21)
#define SW ((IOPIN0>>14)&1)
#define delay                   \
    for (i = 0; i < 65000; i++) \
        ;
u32 flag = 0;
CAN2 RN,TN;
int main()
{
    VPBDIV = 0x01; // PCLK = 60MHz
    IODIR1 = 0xffffffff;
    uart0_init(9600);
    can2_init();
    config_vic();
    en_CAN_intr();
		RN.id=0x1AB;
		RN.rtr=1;
		RN.dlc=4;
		IOSET0=LED1|LED2|LED3|BUZ;
    uart0_tx_string("REVERSE PARK ASSIST\r\n");
    while (1)
    {
					switch (TN.byteA)
					{
						case 0x11:
							if (flag==1)
							{
								uart0_tx_string("CASE 11");
								IOCLR0=LED1|LED2|LED3;
								IOSET0=BUZ;
							}
							else if (flag==0)
							IOSET0=LED1|LED2|LED3|BUZ;
							break;
							
						case 0x22:
							
							if (flag==1)
							{
								uart0_tx_string("CASE 22");
								IOCLR0=LED1|LED2|LED3|BUZ;
								delay_sec(3,1);
								IOSET0=LED1|LED2|LED3|BUZ;
								delay_sec(3,1);
							}
							else if (flag==0)
							IOSET0=LED1|LED2|LED3|BUZ;
							break;

							
						case 0x33:
							
							if (flag==1)
							{
								uart0_tx_string("CASE 33");
								IOCLR0=LED1|LED2|LED3|BUZ;
								delay_sec(2,1);
								IOSET0=LED1|LED2|LED3|BUZ;
								delay_sec(2,1);
							}
							else if (flag==0)
							IOSET0=LED1|LED2|LED3|BUZ;
							break;
							
						case 0x44:
							
							if (flag==1)
							{
								uart0_tx_string("CASE 44");
								IOCLR0=LED1|LED2|LED3|BUZ;
								delay_sec(1,1);
								IOSET0=LED1|LED2|LED3|BUZ;
								delay_sec(1,1);
							}
							else if (flag==0)
							IOSET0=LED1|LED2|LED3|BUZ;
							break;
							
						default:
							if (flag==1)
							{
							IOSET0=LED1|LED2|LED3|BUZ;
							}
							else if (flag==0)
							IOSET0=LED1|LED2|LED3|BUZ;
							break;
				}
			}
		}
							
							
