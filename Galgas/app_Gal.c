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

 /******************************************
 * Private Macros
 ******************************************/

#define APP_ADC_CHANNEL_GROUP 	0u

#define APP_Gal1_CHANNEL 	0u
#define APP_Gal2_CHANNEL    4u
#define APP_Gal3_CHANNEL    3u
#define APP_Gal4_CHANNEL    7u

 /******************************************
 * Private Variables
 ******************************************/
T_UWORD ruw_ADCValue[4];
static T_UBYTE rub_ConversionInProgressFlag = FALSE;
T_UBYTE rub_ADCIndex=0;


 /******************************************
 * Private Prototypes
 ******************************************/
static void app_Gal_Trigger(unsigned int Channel);

static T_UBYTE app_ADC_IsConversionCompleted(void);
static T_UWORD app_ADC_GetValue(void);

 /******************************************
 * Code
 ******************************************/

/***********************************************
 * Initialization of the ADC module
 * Function Name: app_Gal1_Init
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
 * Function Name: app_Gal2_ Trigger
 ***********************************************/
static void app_Gal_Trigger(unsigned int Channel )
{
	adc16_channel_config_t ls_ChannelConfig;

	//Channel Selection
	ls_ChannelConfig.channelNumber = Channel;

	//Disable Interrupt when Conversion is completed
	ls_ChannelConfig.enableInterruptOnConversionCompleted = FALSE;

	//Disable Differential Conversion
	ls_ChannelConfig.enableDifferentialConversion = FALSE;

	ADC16_SetChannelConfig(ADC0, APP_ADC_CHANNEL_GROUP, &ls_ChannelConfig);
}


/***********************************************
 * Waiting flag or conversion interruption
 * Function Name: app_Gal1_IsConversionCompleted
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
 * Function Name: app_Gal1_GetValue
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
				ruw_ADCValue[rub_ADCIndex] = app_ADC_GetValue();




				//Clear conversion in progress flag
				rub_ConversionInProgressFlag = FALSE;
				rub_ADCIndex++;
				if(rub_ADCIndex>4)
					rub_ADCIndex=0;
			}
			else
			{
				/* Do nothing */
			}
		}
		else
		{
			//Trigger the ADC Conversion
			if(rub_ADCIndex==0)
				app_Gal_Trigger(APP_Gal1_CHANNEL);

			else if (rub_ADCIndex==1)
				app_Gal_Trigger(APP_Gal2_CHANNEL);

			else if (rub_ADCIndex==2)
				app_Gal_Trigger(APP_Gal3_CHANNEL);

			else if (rub_ADCIndex==3)
				app_Gal_Trigger(APP_Gal4_CHANNEL);

			ruw_ADCValue[rub_ADCIndex] = app_ADC_GetValue();




			//Set Conversion in progress flag
			rub_ConversionInProgressFlag = TRUE;
		}





}
