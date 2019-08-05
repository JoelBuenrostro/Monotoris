/*
Libraries reference:
OneWire:
OneWire() = Setup a oneWire instance to communicate with any oneWire device.

DallasTemperature:
ONE_WIRE_BUS 3                = Data wire is plugged into pin 3 on the arduino.
DallasTemperature()           = Pass our oneWire reference to Dallas Temperatue.
sensors.begin()               = Start up the library.
sensors.requestTemperatures() = Request to all devices on the bus.
sensors.getTempByIndex()      = 0 refers to the first IC on the wire.

Arduino:
Serial.begin()   = Set the data rate in bits per second for serial data transmission.
Serial.print()   = Prints data to the serial port as human-readable ASCII text.
Serial.println() = Prints data to the serial port as human-readable ASCII text followed by a carriage return .
pinMode()        = Configures the specified pin to behave either as an input or an output.
digitalRead()    = Reads the value from a specified digital pin, either HIGH or LOW.
digitalWrite()   = Write a HIGH or LOW value to a digital pin.
delay()          = Pauses the program for the amount of time (in milliseconds) specified as parameter.

Connections:
Arduino Nano
0=RX 1=TX 2=Buzzer 3=water_temp 4=water_level_min 5=water_level_max

*/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 3

OneWire oneWire (ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int buzzer_pin = 2;
int water_temp = 0;
int water_level_min = 0;
int water_level_max = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  sensors.begin();
  Serial.println("Serial communication open");
}

void loop() {
  digitalWrite(buzzer_pin, LOW);
  water_level_min = digitalRead(4);
  water_level_max = digitalRead(5);
  sensors.requestTemperatures();
  water_temp = sensors.getTempCByIndex(0);
  Serial.println("Temperature : ");
  Serial.println(water_temp);
  Serial.println("Water level minimum read : ");
  Serial.println(water_level_min);
  Serial.println("Water level maximum read : ");
  Serial.println(water_level_max);
  delay(1000);

  if(water_level_min == 0) {
    digitalWrite(buzzer_pin, LOW);
    delay(100);
    digitalWrite(buzzer_pin, HIGH);
    delay(250);
    digitalWrite(buzzer_pin, LOW);
    delay(100);
    digitalWrite(buzzer_pin, HIGH);
    delay(250);
    }
    else {
      digitalWrite(buzzer_pin, LOW);
      }
}
