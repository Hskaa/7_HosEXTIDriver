/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer :	 MCAL         		***************/
/***************   		SWC : 	 APP           		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "PORT_Interface.h"
#include "DIO_Interface.h"
#include "EXTI_Interface.h"
#include "GIE_Interface.h"

volatile u8 state  ;
u8 value = 0 ;
u8 swap = 1 ;

void INT0_ISR(void);

void main (void)
{
	PORT_voidInit();
	DIO_u8SetPortValue(DIO_PORTC ,DIO_OUTPUT);
	EXTI_voidInt0Init();

	EXTI_u8Int0SetCallBack(&INT0_ISR);

	GIE_voidEnable();
	while(1)
	{
		switch(state)
		{
		case 0 :
			DIO_u8SetPortValue(DIO_PORTC , value);
			value = ~value;
			break;
		case 1 :
			DIO_u8SetPortValue(DIO_PORTC , swap);
			swap *=2;
			if (swap == 0)
			{
				swap = 1;
			}
			break;
		}
		_delay_ms(500);
	}

}

void INT0_ISR(void)
{
	state = !state ;
}

