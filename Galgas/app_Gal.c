/*
 * app_Gal.c
 *
 *  Created on: 02/04/2018
 *      Author: luisi_000
 */


 /******************************************
 * Interfaces
 ******************************************/
#include "stdtypedef.h"
#include "fsl_adc16.h"
#include "app_Gal.h"
#include "app_LED.h"


 /******************************************
 * Private Macros
 ******************************************/

#define APP_ADC_CHANNEL_GROUP 	0u
#define APP_ADC_Gal1_CHANNEL 	0u
//#define APP_ADC_Gal2_CHANNEL    4u
//#define APP_ADC_Gal3_CHANNEL    3u
//#define APP_ADC_Gal4_CHANNEL    7u

 /******************************************
 * Private Variables
 ******************************************/
static T_UWORD ruw_ADCValue = 0u;
static T_UBYTE rub_ConversionInProgressFlag = FALSE;


 /******************************************
 * Private Prototypes
 ******************************************/
static void app_ADC_Gal1_Trigger(void);
/*static void app_ADC_Gal2_Trigger(void);
static void app_ADC_Gal3_Trigger(void);
static void app_ADC_Gal4_Trigger(void);
static T_UBYTE app_ADC_IsConversionCompleted(void);
static T_UWORD app_ADC_GetValue(void);*/

 /******************************************
 * Code
 ******************************************/

/***********************************************
 * Initialization of the ADC module
 * Function Name: app_ADC_Gal1_Init
 ***********************************************/

void app_ADC_Init(void)
{
	adc16_config_t ls_ADCConfig;

	//Initialize structure with default values
	ADC16_GetDefaultConfig(&ls_ADCConfig);

	//Init ADC Module
	ADC16_Init(ADC0, &ls_ADCConfig);

	//Disable Hardware Trigger
	ADC16_EnableHardwareTrigger(ADC0, FALSE); /* Make sure the software trigger is used. */

	//Perform Autocalibration
	(void)ADC16_DoAutoCalibration(ADC0);
}

/***********************************************
 * Generate trigger to start conversion
 * Function Name: app_ADC_Gal2_ Trigger
 ***********************************************/

/*static void app_ADC_Gal2_Trigger(void)
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = APP_ADC_Gal2_CHANNEL;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}

*/



/***********************************************
 * Generate trigger to start conversion
 * Function Name: app_ADC_Gal1_ Trigger
 ***********************************************/

static void app_ADC_Gal1_Trigger(void)
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = APP_ADC_Gal1_CHANNEL;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}



/***********************************************
 * Generate trigger to start conversion
 * Function Name: app_ADC_Gal3_ Trigger
 ***********************************************/

/*static void app_ADC_Gal3_Trigger(void)
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = APP_ADC_Gal3_CHANNEL;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}
*/

/***********************************************
 * Generate trigger to start conversion
 * Function Name: app_ADC_Gal4_ Trigger
 ***********************************************/

/*static void app_ADC_Gal4_Trigger(void)
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = APP_ADC_Gal4_CHANNEL;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}

*/
/***********************************************
 * Waiting flag or conversion interruption
 * Function Name: app_ADC_Gal1_IsConversionCompleted
 ***********************************************/

static T_UBYTE app_ADC_IsConversionCompleted(void)
{
	T_UBYTE lub_Return;

	lub_Return = FALSE;

	//Check if Conversion was completed
	if(kADC16_ChannelConversionDoneFlag &
			ADC16_GetChannelStatusFlags(ADC0, APP_ADC_CHANNEL_GROUP))
	{
		//Conversion Completed
		lub_Return = TRUE;
	}
	else
	{
		//Conversion not completed
		lub_Return = FALSE;
	}

	return lub_Return;
}

/***********************************************
 * Read conversion value
 * Function Name: app_ADC_Gal1_GetValue
 ***********************************************/

static T_UWORD app_ADC_GetValue(void)
{
	//Return Last Conversion Value
	return ADC16_GetChannelConversionValue(ADC0, APP_ADC_CHANNEL_GROUP);
}

/***********************************************
 * Function Name: app_ADC_Task
 ***********************************************/
void app_ADC_Task(void)
{
	//Check if a conversion is in progress
	if(TRUE == rub_ConversionInProgressFlag)
	{
		//Check if Conversion was completed
		if(TRUE == app_ADC_IsConversionCompleted())
		{
			//Store the ADC Value
			ruw_ADCValue = app_ADC_GetValue();

			if(ruw_ADCValue <= 1365)
			{
			LED_RED_OFF();
			LED_BLUE_OFF();
			LED_GREEN_ON();
			}
			else if(ruw_ADCValue > 1365 && ruw_ADCValue <= 2730)
			{
			LED_RED_OFF();
		    LED_BLUE_ON();
			LED_GREEN_OFF();
			}
			else if(ruw_ADCValue > 2730)
			{
			LED_RED_ON();
		    LED_BLUE_OFF();
			LED_GREEN_OFF();
			}

			//Clear conversion in progress flag
			rub_ConversionInProgressFlag = FALSE;
		}
		else
		{
			/* Do nothing */
		}
	}
	else
	{
		//Trigger the ADC Conversion
		app_ADC_Gal1_Trigger();
		//app_ADC_Gal2_Trigger();
		//app_ADC_Gal3_Trigger();
		//app_ADC_Gal4_Trigger();

		//Set Conversion in progress flag
		rub_ConversionInProgressFlag = TRUE;
	}
}
