/*
 * adc.c
 *
 *  Created on: 8 Oct 2022
 *      Author: Nardeen
 */

#include "lm35_sensor.h"
#include "lcd.h"
#include "dc_motor.h"
#include "adc.h"

int main(){
	ADC_ConfigType * Config_Ptr= {INTERNAL_VOLTAGE,F_CPU_8};

	     ADC_init(&Config_Ptr);
		 DcMotor_Init();
		 LCD_init();
		LCD_displayStringRowColumn(1,3,"Temp=     C");

	while(1){
    uint8 temperature_Value = LM35_getTemperature();

    if(temperature_Value >= 100)
    		{
    			LCD_moveCursor(1,9);
    			LCD_intgerToString(temperature_Value);
    		}
    		else
    		{
    			LCD_moveCursor(1,9);
    			LCD_intgerToString(temperature_Value);
    			LCD_displayCharacter(' ');
    		}

    if(temperature_Value < 30 ){
    	 DcMotor_Rotate( STOP , 0);
    	 LCD_displayStringRowColumn(0,3,"Fan is OFF");
    }

    else
    	{
    	LCD_displayStringRowColumn(0,3,"Fan is ON");
    	if(temperature_Value >= 30 && temperature_Value < 60){
    	DcMotor_Rotate( CLOCKWISE , 25);

    }
    else if(temperature_Value >= 60 && temperature_Value < 90){
    	DcMotor_Rotate( CLOCKWISE , 50);

        }
    else if(temperature_Value >= 90 && temperature_Value < 120){
    	DcMotor_Rotate( CLOCKWISE , 75);

        }
    else if(temperature_Value >= 120){
    	DcMotor_Rotate( CLOCKWISE , 100);
        }

	}

	}
}

