/*
 * adc.c
 *
 *  Created on: 8 Oct 2022
 *      Author: Nardeen
 */

#include "avr/io.h"
#include "adc.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr){

		ADMUX = (ADMUX & 0X3F) | (Config_Ptr->ref_volt << REFS0 );
		 /* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 0 Disable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
		 */
		SET_BIT(ADCSRA,ADEN);
		ADCSRA =( ADCSRA & 0xF8) | (Config_Ptr->prescaler);
}
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}

