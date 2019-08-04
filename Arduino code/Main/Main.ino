/*
  Reference:

  Arduino:
  Serial.begin() = Sets the data rate in bits per second (baud) for serial data transmission.
  Serial.println() = Prints data to the serial port followed by a carriage return and a newline

  Connections:
  Arduino Nano
  0 = RX 1 = TX

*/
int baudRate = 9600;

void setup() {
  Serial.begin(baudRate);
  Serial.println("Serial port open");
}

void loop() {
  Serial.println("test");
}
