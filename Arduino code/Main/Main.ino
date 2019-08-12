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
#include <EEPROM.h>

#define ONE_WIRE_BUS 3

OneWire oneWire (ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int buzzer_pin = 2;
int water_temp = 0;
int water_level_min = 0;
int water_level_max = 0;
int store_time_address = 0;



void setup() {
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  sensors.begin();
}

void loop() {
  digitalWrite(buzzer_pin, LOW);
  water_level_min = digitalRead(4);
  water_level_max = digitalRead(5);
  sensors.requestTemperatures();
  water_temp = sensors.getTempCByIndex(0);
  Serial.println("Temp : " + water_temp);
  delay(500);

  if(water_level_max == 1) {
    unsigned long start_time = millis();
    if(water_level_min == 0) {
      unsigned long current_time = millis();
      unsigned long elapsed_time = current_time - start_time / 1000;
      EEPROM.write(store_time_address, elapsed_time);
      }
    }

  if(water_level_min == 0) {
    digitalWrite(buzzer_pin, LOW);
    delay(100);
    digitalWrite(buzzer_pin, HIGH);
    delay(250);
    digitalWrite(buzzer_pin, LOW);
    delay(100);
    digitalWrite(buzzer_pin, HIGH);
    delay(250);
    Serial.println(EEPROM.read(store_time_address));
    }
    else {
      digitalWrite(buzzer_pin, LOW);
      }
}
