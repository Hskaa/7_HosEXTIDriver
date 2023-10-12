/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : MCAL         		***************/
/***************   		SWC : EXTI           		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_Interface.h"
#include "EXTI_Cfg.h"
#include "EXTI_Reg.h"
#include "EXTI_Private.h"

/* Global Pointer to function to hold INT0 ISR adress */
void (*EXTI_pvInt0Func)(void) = NULL;
void(* EXTI_pvInt1Func)(void) = NULL ;
void(* EXTI_pvInt2Func)(void) = NULL ;

void EXTI_voidInt0Init(void)
{
	/*1- Check Sense Control */
#if INT0_SENSE   == LOW_LEVEL
	CLR_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);

#else
#error (" Wrong Configuration !!")

#endif

	/*CHECK PERIPHERAL enable interrupt state */
#if INT0_INITIAL_STATE   == ENABLE
	SET_BIT(GICR , GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLE
	CLR_BIT(GICR , GICR_INT0);

#else
#error (" Wrong Configuration !!")
#endif

}

u8 EXTI_u8Int0SenseControl(u8 Cpy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Cpy_u8Sense)
	{
	case LOW_LEVEL   :  CLR_BIT(MCUCR , MCUCR_ISC00); CLR_BIT(MCUCR , MCUCR_ISC01);		 break;
	case ON_CHANGE	 :  SET_BIT(MCUCR , MCUCR_ISC00); CLR_BIT(MCUCR , MCUCR_ISC01);      break;
	case FALLING_EDGE:  CLR_BIT(MCUCR , MCUCR_ISC00); SET_BIT(MCUCR , MCUCR_ISC01);      break;
	case RISING_EDGE :  SET_BIT(MCUCR , MCUCR_ISC00); SET_BIT(MCUCR , MCUCR_ISC01);      break;
	default 		 : Local_u8ErrorState=NOK;											 break;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8Int0SetCallBack (void (*Cpy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Cpy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func=Cpy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState =NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/* ISR of INT0 */
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		//do something
	}
}




/******************************************************************************************************************/


void EXTI_voidInt1Init(void)
{
	/* Init Sense Control */
#if INT1_SENSE   == LOW_LEVEL
	CLR_BIT(MCUCR , MCUCR_ISC10);
	CLR_BIT(MCUCR , MCUCR_ISC11);

#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR , MCUCR_ISC10);
	CLR_BIT(MCUCR , MCUCR_ISC11);

#elif INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR , MCUCR_ISC10);
	SET_BIT(MCUCR , MCUCR_ISC11);

#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR , MCUCR_ISC10);
	SET_BIT(MCUCR , MCUCR_ISC11);

#else
#error (" Wrong Configuration !!")

#endif

	/* Init initial interrupt state */
#if INT1_INITIAL_STATE   == ENABLE
	SET_BIT(GICR , GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLE
	CLR_BIT(GICR , GICR_INT1);
#else
#error (" Wrong Configuration !!")
#endif
}


u8 EXTI_u8Int1SenseControl(u8 Cpy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Cpy_u8Sense)
	{
	case LOW_LEVEL   :  CLR_BIT(MCUCR , MCUCR_ISC10);CLR_BIT(MCUCR , MCUCR_ISC11);		 break;
	case ON_CHANGE	 :  SET_BIT(MCUCR , MCUCR_ISC10);CLR_BIT(MCUCR , MCUCR_ISC11);       break;
	case FALLING_EDGE:  CLR_BIT(MCUCR , MCUCR_ISC10);SET_BIT(MCUCR , MCUCR_ISC11);       break;
	case RISING_EDGE :  SET_BIT(MCUCR , MCUCR_ISC10);SET_BIT(MCUCR , MCUCR_ISC11);       break;
	default 		 : Local_u8ErrorState=NOK;											 break;
	}
	return Local_u8ErrorState;
}


/****************************************************************************************************/



void EXTI_voidInt2Init(void)
{
	/* Init Sense Control */
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR , MCUCSR_ISC2);

#elif INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR , MCUCSR_ISC2);

#else
#error (" Wrong Configuration !!")
#endif

	/* Init initial interrupt state */
#if INT2_INITIAL_STATE    == ENABLE
	SET_BIT(GICR , GICR_INT2);

#elif INT2_INITIAL_STATE  == DISABLE
	CLR_BIT(GICR , GICR_INT2);

#else
#error (" Wrong Configuration !!")
#endif
}


u8 EXTI_u8Int1SetCallBack (void (*Cpy_pvInt1Func)(void))
{
	u8 Local_error = OK ;
	if (Cpy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Cpy_pvInt1Func ;
	}
	else
	{
		Local_error = NOK;
	}
	return Local_error ;
}

u8 EXTI_u8Int2SetCallBack (void (*Cpy_pvInt2Func)(void))
{
	u8 Local_error = OK ;
	if (Cpy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Cpy_pvInt2Func ;
	}
	else
	{
		Local_error = NOK;
	}
	return Local_error ;
}


/* ISR  for External interrupt 1 */
void __vector_2 (void) __attribute__((signal)) ;
void __vector_2 (void)
{
	EXTI_pvInt1Func();
}

/* ISR  for External interrupt 2 */
void __vector_3 (void) __attribute__((signal)) ;
void __vector_3 (void)
{
	EXTI_pvInt2Func();
}


u8 EXTI_u8IntEnable(u8 Cpy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Cpy_u8Int)
	{
	case INT0 :SET_BIT(GICR , GICR_INT0);		break;
	case INT1 :SET_BIT(GICR , GICR_INT1);		break;
	case INT2 :SET_BIT(GICR , GICR_INT2);		break;
	default   : Local_u8ErrorState=NOK;			break;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8IntDisable(u8 Cpy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Cpy_u8Int)
	{
	case INT0 :CLR_BIT(GICR , GICR_INT0);		break;
	case INT1 :CLR_BIT(GICR , GICR_INT1);		break;
	case INT2 :CLR_BIT(GICR , GICR_INT2);		break;
	default   : Local_u8ErrorState=NOK;			break;
	}
	return Local_u8ErrorState;
}
