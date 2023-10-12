/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : MCAL         		***************/
/***************   		SWC : EXTI           		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/
#ifndef  EXTI_CFG_H_
#define  EXTI_CFG_H_

/********** Configurations of Int0 **********/
/* Choose :
			LOW_LEVEL
			ON_CHANGE
			FALLING_EDGE
			RISING_EDGE
*/
#define    INT0_SENSE 			   FALLING_EDGE

/* Choose :
			ENABLE
			DISABLE
*/
#define    INT0_INITIAL_STATE  		ENABLE


/********** Configurations of Int1 **********/
/* Choose :
			LOW_LEVEL
			ON_CHANGE
			FALLING_EDGE
			RISING_EDGE
*/
#define    INT1_SENSE 			 ON_CHANGE

/* Choose :
			ENABLE
			DISABLE
*/
#define    INT1_INITIAL_STATE 	 ENABLE

/********** Configurations of Int2 **********/
/* Choose :
			FALLING_EDGE
			RISING_EDGE
*/
#define    INT2_SENSE 			 FALLING_EDGE

/* Choose :
			ENABLE
			DISABLE
*/
#define    INT2_INITIAL_STATE 	 DISABLE


#define INT0	0
#define INT1	1
#define INT2	2


#endif
