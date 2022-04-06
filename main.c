#include<reg552.h>
#include<stdio.h>
void tempo10ms(unsigned short i);
void decalage_droite(void);
void decalage_gauche(void);
void tempo_variable(void);

void main(void)
{
	P4 = 0b00000111;
	
	while(1)
	{
		while((P1&(1<<7))!=0){}
		
		if ((P1&(1<<6))==0)
		{
			decalage_droite();
		}
		else
		{
			decalage_gauche();
		}
		tempo_variable();
	}
}


void tempo10ms(unsigned short i)
{
		unsigned short k,j;
		for ( j=0 ; j<i;j++)
		{
			for(k=0; k<4950;k++)
			{
			}
		}
} 

void decalage_gauche(void)
{	
		if ((P4&(1<<7))==0)
		{
				P4 = P4 <<1;
		}
		else
		{
				P4 = P4<<1;
				P4=P4|0b00000001;
		}
} 

void decalage_droite(void)
{	
		if ((P4&(1<<0))==0)
		{
				P4 = P4 >>1;
		}
		else
		{
				P4 = P4>>1;
				P4=P4|0b10000000;
		}
} 

void tempo_variable(void)
{
		
		
		if ((P1&(1<<5))==0)
		{
			if ((P1&(1<<4))==0)
			{
				tempo10ms(1);
			}
			else
			{
				tempo10ms(5);
			}
		}
		else
		{
			if ((P1&(1<<4))==0)
			{
				tempo10ms(100);
			}
			else
			{
				tempo10ms(200);
			}
		}
} 
