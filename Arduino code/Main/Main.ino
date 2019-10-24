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

  DFRobot_RGBLCD:
  DFRobot_RGBLCD lcd() = Set the dimensions of the LCD display
  lcd.init()           = Start the display
  lcd.setRGB()         = Set the color of the background in RGB format
  lcd.setCursor()      = Define the position to print
  lcd.print()          = Write one or a set of characters
  lcd.clear()          = Clear the display

  SD:
  SD.open()   = Open a File in the SD root
  SD.remove() = Remove a file from the SD cards

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
  D0=RX D1=TX D2=Buzzer D3=water_temp D4=water_level_min D5=water_level_max D10=CS D11=MOSI D12=MISO D13=SCK
  A4=SDA A5=SCL
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Chrono.h>
#include <Wire.h>
#include <DFRobot_RGBLCD.h>
#include <SPI.h>
#include <SD.h>

#define ONE_WIRE_BUS 3

OneWire oneWire (ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Chrono timer(Chrono::SECONDS);
DFRobot_RGBLCD lcd(16, 2);

const int chipSelect = 10;
int buzzer_pin = 2;
int water_temp = 0;
int water_level_min = 0;
int water_level_max = 0;
int minutes = 0;

void setup() {
  lcd.init();
  lcd.setRGB(0, 255, 155);
  lcd.setCursor(3, 0);
  lcd.print("MONOTORIS");
  SD.remove("DATALOG.CSV");
  delay(5000);
  lcd.setRGB(0, 0, 255);
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(chipSelect, OUTPUT);
  sensors.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initializing SD");
  delay(1000);
  lcd.clear();
  if (!SD.begin(chipSelect)) {
    lcd.setCursor(0, 0);
    lcd.print("SDCard failed or");
    lcd.setCursor(0, 1);
    lcd.print("not present");
    while (1);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Card initialized");
  delay(1000);
  lcd.clear();
  String titleString = "";
  titleString += String("Wmin,Wmax,Temp,Time");
  File dataFile = SD.open("DATALOG.CSV", FILE_WRITE);
  if (dataFile) {
    dataFile.println(titleString);
    dataFile.close();
    Serial.println(titleString);
  }
  else {
    Serial.println("Error opening datalog.csv");
  }
}

void loop() {
  String dataString = "";
  lcd.setRGB(0, 0, 255);
  water_level_min = digitalRead(4);
  dataString += String(water_level_min);
  dataString += ",";
  water_level_max = digitalRead(5);
  dataString += String(water_level_max);
  dataString += ",";
  sensors.requestTemperatures();
  water_temp = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(6, 0);
  lcd.print(water_temp);
  dataString += String(water_temp);
  dataString += ",";
  lcd.setCursor(13, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.setCursor(6, 1);
  lcd.print(minutes);
  dataString += String(minutes);
  lcd.setCursor(13, 1);
  lcd.print("min");
  delay(4000);
  File dataFile = SD.open("DATALOG.CSV", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
  }
  else {
    Serial.println("Error opening datalog.csv");
  }

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
      lcd.clear();
      lcd.setRGB(255, 0, 0);
      lcd.setCursor(0, 0);
      lcd.print("Water min level");
      lcd.setCursor(0, 1);
      lcd.print("Refill water");
      delay(2000);
      lcd.clear();
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
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Water max level");
      delay(1000);
      lcd.clear();
      break;
  }
}
