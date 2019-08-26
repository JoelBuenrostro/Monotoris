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

  Chrono:
  Chrono timer(Chrono::SECONDS) = Create a Chrono that counts in seconds
  timer.stop()                  = Stops/pauses the chronometer
  timer.elapsed()               = Returns the elapsed time
  timer.restart()               = Starts/restarts the chronometer 

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
#include <Chrono.h>
#include <Wire.h>
#include <DFRobot_RGBLCD.h>

#define ONE_WIRE_BUS 3

const int colorR = 0;
const int colorG = 0;
const int colorB  = 255;

OneWire oneWire (ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Chrono timer(Chrono::SECONDS);
DFRobot_RGBLCD lcd(16,2);

int buzzer_pin = 2;
int water_temp = 0;
int water_level_min = 0;
int water_level_max = 0;
int minutes = 0;

void setup() {
  lcd.init();
  lcd.setRGB(colorR, colorG, colorB);
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  sensors.begin();
}

void loop() {
  water_level_min = digitalRead(4);
  water_level_max = digitalRead(5);
  sensors.requestTemperatures();
  water_temp = sensors.getTempCByIndex(0);
  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.setCursor(7,0);
  lcd.print(water_temp);
  lcd.setCursor(10,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Time : ");
  lcd.setCursor(7,1);
  lcd.print(minutes);
  lcd.setCursor(10,1);
  lcd.print("min");

  switch (water_level_min) {
    case 0:
      digitalWrite(buzzer_pin, LOW);
      delay(50);
      digitalWrite(buzzer_pin, HIGH);
      delay(200);
      digitalWrite(buzzer_pin, LOW);
      delay(50);
      digitalWrite(buzzer_pin, HIGH);
      delay(200);
      digitalWrite(buzzer_pin, LOW);
      delay(50);
      digitalWrite(buzzer_pin, HIGH);
      delay(200);
      digitalWrite(buzzer_pin, LOW);
      delay(50);
      timer.stop();
      break;
    case 1:
      digitalWrite(buzzer_pin, LOW);
  }

  switch (water_level_max) {
    case 0:
      minutes = timer.elapsed() / 60;
      break;
    case 1:
      timer.restart();
      break;
  }
}
