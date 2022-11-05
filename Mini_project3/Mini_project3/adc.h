/*
 * adc.h
 *
 *  Created on: 8 Oct 2022
 *      Author: Nardeen
 */

#ifndef ADC_H_
#define ADC_H_


#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
} ADC_Prescaler;

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL_VOLTAGE
} ADC_ReferenceVolatge;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
