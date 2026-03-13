#include <Mhz19.h>

Mhz19 myMHZ19;

HardwareSerial mySerial(2);   // UART2

void setup()
{
  Serial.begin(115200);

  mySerial.begin(9600, SERIAL_8N1, 16, 17);

  myMHZ19.begin(&mySerial);

  myMHZ19.disableAutoBaseCalibration();
}

void loop()
{
  int CO2 = myMHZ19.getCarbonDioxide();

  Serial.print("CO2: ");
  Serial.print(CO2);
  Serial.println(" ppm");

  delay(2000);
}
