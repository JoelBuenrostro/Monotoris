/*
  Reference:

  Arduino:
  Serial.begin() = Sets the data rate in bits per second (baud) for serial data transmission.
  Serial.println() = Prints data to the serial port followed by a carriage return and a newline

  Connections:
  Arduino Nano
  0 = RX 1 = TX

*/

void setup() {
  Serial.begin(9600);
  Serial.println("Serial port open");
}

void loop() {
  
}
