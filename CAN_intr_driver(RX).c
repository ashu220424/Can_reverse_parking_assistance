#include <lpc21xx.h>
#include "proj_header.h"
extern u32 flag;
extern u32 dummy;
extern CAN2 RN;

void CAN_Handler(void) __irq
{
	RN.id=C2RID;
	RN.dlc=(C2RFS>>16)&0xF;
	RN.rtr=(C2RFS>>30)&1;
	if(RN.rtr==0)
	{
		RN.byteA=C2RDA;
		RN.byteB=C2RDB;
	}
	C2CMR|=4;
	if (RN.id==0x1AB)
	flag=!flag;
	VICVectAddr=0;
	}

void config_vic (void)
{
	VICIntSelect=0;
	VICVectCntl0=27|(1<<5);
	VICVectAddr0=(int)CAN_Handler;
	VICIntEnable|=(1<<27);
	C2CMR &= ~(0x6);
}

void en_CAN_intr (void)
{
	C2IER=1;
}
