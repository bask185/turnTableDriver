#include "src/basics/io.h"
#include "roundRobinTasks.h"


void setup() 
{
	initIO();
	Serial.begin(115200);
}

void loop() 
{
	processRoundRobinTasks();
}