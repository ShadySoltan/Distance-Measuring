/*
 * Distance Measuring.c
 *
 * Created: 7/13/2023 11:38:03 AM
 * Author : Administrator
 */ 

#include <avr/io.h>
#include "Clock.h"
#include "BitMath.h"
#include "STD_Types.h"
#include "DIO.h"
#include "Ultrasonic.h"
#include "LCD.h"
#include <stdlib.h>

int main(void)
{
	DIO_Init();
	LCD_Init();
	s8 distance[20] = {STD_Low};
	double ddistance = STD_Low;
    while (1) 
    {
		ddistance = Ultrasonic_Read(); // This function return the distance but in double we need to convert it to string first to pring on LCD
		dtostrf(ddistance,2,2,distance);
		LCD_String(distance);
		_delay_ms(200);
		LCD_Cmd(0x01);
    }
}

