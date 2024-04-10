#include <LPC21XX.H>
#include "proj_header.h"
#define TCS ((C2SR>>3)&1)
#define RBS ((C2GSR>>0)&1)

void can2_init (void)
{
	PINSEL1|=0x14000;  // P0.25 -> RD1
	VPBDIV=1;   // PCLK=60MHZ
	C2MOD=1;   // RESET MODE
	C2BTR=0x001C001D;   // SET BIT TIMING
	AFMR=2;   // ALL INCOMING MSGS
  C2MOD=0;   // NORMAL MODE/CANCEL RESET MODE
}

void can2_tx (CAN2 m1)
{
	C2TID1=m1.id;
	C2TFI1=m1.dlc<<16;
	if (m1.rtr==0)
	{
		C2TDB1=m1.byteB;
		C2TDA1=m1.byteA;
	}
	else
	{
		C2TFI1|=(1<<30);
	}
	C2CMR=1|(1<<5);
	while (TCS==0);
}

void can2_rx (CAN2*ptr)
{
		while (RBS==0);
		ptr->id=C2RID;
		ptr->dlc=(C2RFS>>16)&0xF;
		ptr->rtr=(C2RFS>>30)&1;
		if (ptr->rtr==0)
		{
			ptr->byteA=C2RDA;
			ptr->byteB=C2RDB;
		}
		C2CMR=(1<<2);
}
