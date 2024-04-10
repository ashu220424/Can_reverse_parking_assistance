#include<lpc21xx.h>
#include "proj_header.h"
void delay_ms (unsigned int ms, unsigned int vpbdiv)
{
	int a[]={60,15,30,0,15};
	unsigned int pclk=a[vpbdiv]*1000;
	T1PC=0;
	T1PR=pclk-1;
	T1TC=0;
	T1TCR=1;
	while(T1TC<ms);
	T1TCR=0;
}

void delay_sec (unsigned int sec, unsigned int vpbdiv)
{
	int a[]={60,15,30,0,15};
	unsigned int pclk=a[vpbdiv]*1000000;
	T1PC=0;
	T1PR=pclk-1;
	T1TC=0;
	T1TCR=1;
	while(T1TC<sec);
	T1TCR=0;
}
