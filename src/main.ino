/*
* Project Cabin Monitor
* Description: Simple temp/humidity monitor for monitoring ___
* Author: Torban Peterson
* Date: 2017/08/15
*/


#include "ClosedCube_HDC1080.h"

double temperature;
double humidity;


ClosedCube_HDC1080 hdc1080;
Timer timer(60000, update);

void setup() {
	Particle.variable("temp_1", &temperature, DOUBLE);
	Particle.variable("humid_1", &humidity, DOUBLE);

	Serial.begin(115200);

	//  - 14 bit Temperature and Humidity Measurement Resolutions
	hdc1080.begin(0x40);
	pinMode(D7, OUTPUT); // turn D7 into a ground pin to bypass soldering error
	digitalWrite(D7, LOW);
	timer.start();
}

void loop() {

}

void update() {
	temperature = hdc1080.readTemperature();
	humidity = hdc1080.readHumidity();
	Serial.print("T=");
	Serial.print(temperature);
	Serial.print("C, RH=");
	Serial.print(humidity);
	Serial.println("%");
}
