#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>



// ================= CONFIG =================
#define DEBOUNCE_MS 1500
unsigned long lastActionTime = 0;

// ================= BLE HID =================
BLEService hidService("1812");

const uint8_t hidReportMap[] = {
  0x05, 0x0C,
  0x09, 0x01,
  0xA1, 0x01,
  0x15, 0x00,
  0x25, 0x01,
  0x09, 0xCD, // Play/Pause
  0x09, 0xB5, // Next
  0x09, 0xB6, // Previous
  0x75, 0x01,
  0x95, 0x03,
  0x81, 0x06,
  0x95, 0x05,
  0x81, 0x01,
  0xC0
};

BLECharacteristic reportMapChar("2A4B", BLERead, sizeof(hidReportMap));
BLECharacteristic consumerChar("2A4D", BLERead | BLENotify, 1);

// ================= HELPERS =================
bool canTrigger() {
  return (millis() - lastActionTime) > DEBOUNCE_MS;
}

void sendKey(uint8_t key) {
  consumerChar.writeValue(&key, 1);
  delay(20);
  uint8_t release = 0;
  consumerChar.writeValue(&release, 1);
  lastActionTime = millis();
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  delay(2000);

  if (!IMU.begin()) {
    Serial.println("IMU failed");
    while (1);
  }

  BLE.begin();
  BLE.setLocalName("GestureController");
  BLE.setAdvertisedService(hidService);

  hidService.addCharacteristic(reportMapChar);
  hidService.addCharacteristic(consumerChar);
  BLE.addService(hidService);

  reportMapChar.writeValue(hidReportMap, sizeof(hidReportMap));
  BLE.advertise();

  Serial.println("BLE Gesture Controller Ready");
}

// ================= LOOP =================
void loop() {
  if (!BLE.central()) return;

  float ax, ay, az;
  IMU.readAcceleration(ax, ay, az);

  Serial.print("AX: ");
  Serial.println(ax);

  if (!canTrigger()) return;

  // FAKE GESTURE LOGIC (TEMPORARY)
  if (ax > 1.2) {
    Serial.println("Play/Pause");
    sendKey(0x01);
  } 
  else if (ax < -1.2) {
    Serial.println("Next Track");
    sendKey(0x02);
  }
}
