#include "extension.h"

const int LATCH_PIN = 5;	// RCLK (Register Clock / Latch) Pin des 74HC595 ist verbunden mit dem digitalen Pin 5
const int CLOCK_PIN = 6;	// SRCLK (Shit Register Clock) Pin des 74HC595 ist verbunden mit dem digitalen Pin 6
const int DATA_PIN = 4;		// SER (Serial input) Pin des 74HC595 ist verbunden mit dem digitalen Pin 4

PortExtension port(LATCH_PIN, CLOCK_PIN, DATA_PIN);

void setup() 
{
}

void loop() 
{
  	port.writeByte(0x00);
  	delay(500);
  
  	for (int i = 0; i < 8; i++)	
  	{
    	port.setBit(i);
    	delay(500);
  	}
}