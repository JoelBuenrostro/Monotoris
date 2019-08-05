/*
  Reference:

  Arduino:
  pinMode()        = Configures the specified pin to behave either as an input or an output.
  Serial.begin()   = Sets the data rate in bits per second (baud) for serial data transmission.
  Serial.println() = Prints data to the serial port followed by a carriage return and a newline

  Connections:
  Arduino Nano
  0=RX 1=TX 2=Buzzer

*/
int buzzer_pin = 2;

void setup() {
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  
}
