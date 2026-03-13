#include <Mhz19.h>

Mhz19 myMHZ19;

HardwareSerial mySerial(2);   // UART2

const int MHZ19_RX_PIN = 17;
const int MHZ19_TX_PIN = 16;

void setup()
{
  Serial.begin(115200);

  mySerial.begin(9600, SERIAL_8N1, MHZ19_RX_PIN, MHZ19_TX_PIN);

  myMHZ19.begin(&mySerial);

  myMHZ19.setMeasuringRange(Mhz19MeasuringRange::Ppm_5000);
  myMHZ19.disableAutoBaseCalibration(); // Disable auto-calibration for constant indoor use
}

void loop()
{
  if (myMHZ19.isReady()) {
    int CO2 = myMHZ19.getCarbonDioxide();

    if (CO2 < 0) {
      Serial.println("Error: CO2 read returned -1 (communication issue after warmup).");
    } else {
      Serial.print("CO2: ");
      Serial.print(CO2);
      Serial.println(" ppm");
    }
  } else {
    Serial.println("Sensor warming up (please wait)...");
  }

  delay(2000);
}
