#include "stm32f10x.h"
#include "sys.h"
	
/*------------------------------------------------------------
                           ������
------------------------------------------------------------*/
int main()
{
    
  Stm32_Clock_Init();//ϵͳʱ������
	RCC->APB2ENR |= 0x00000001; //����afioʱ��
  //AFIO->MAPR = (0x00FFFFFF & AFIO->MAPR)|0x04000000;          //�ر�JTAG 
				

	RCC->APB2ENR|=0X0000001c;//��ʹ������IO PORTa,b,cʱ��
	
	GPIOB->CRH=0X33333333;    //�������
	GPIOB->CRL=0X33333333;    //�������
	GPIOC->CRH=0X33333333;    //�������
	GPIOC->CRL=0X33333333;    //�������
	GPIOD->CRH=0X33333333;    //�������
	GPIOD->CRL=0X33333333;    //�������
	GPIOA->CRH=0X33333333;    //�������
	GPIOA->CRL=0X33333333;    //�������

	while (1)
  {			
	delay_ms(100);     	 
	GPIOB->ODR=0;	  		 //ȫ�����0
	GPIOA->ODR=0;		
	GPIOC->ODR=0;
	GPIOD->ODR=0;
	delay_ms(100);
	GPIOB->ODR=0xffffffff;	 //ȫ�����1 
	GPIOA->ODR=0xffffffff;	  
	GPIOC->ODR=0xffffffff;
	GPIOD->ODR=0xffffffff;
	}
}
