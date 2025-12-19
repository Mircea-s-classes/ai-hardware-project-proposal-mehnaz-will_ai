# Gesture-Based Music Control Using Arduino

## Team Information
**Team Name:** Arduino Accelerators  
**Team Members:**  
- Mehnaz Tasnim
- Will Goodwin 

---

## Motivation
Modern user interfaces rely heavily on touchscreens and physical buttons, which can be inefficient, distracting, or unsafe in hands-busy environments such as driving, lecturing, or exercising. In these situations, users often struggle to interact with devices without diverting attention from their primary task. Gesture-based interaction offers a hands-free alternative, but early commercial systems lacked the low latency, accuracy, and robustness required for widespread adoption due to hardware limitations.

This project investigates whether modern embedded AI hardware can enable real-time, intuitive gesture recognition directly on-device. By leveraging TinyML techniques on a resource-constrained microcontroller, we aim to demonstrate that gesture-based control can be both practical and efficient. 


---

## Project Overview
This project implements a gesture-based music controller using the Arduino Nano 33 BLE Sense Rev2. A machine learning model trained on motion sensor data performs real-time gesture classification on the microcontroller. Recognized gestures are mapped to media control actions such as play, pause, skip, and back, which are transmitted to a host device using Bluetooth Low Energy (BLE).

The system is designed to run entirely on-device, emphasizing low latency, low power consumption, and user privacy. The project integrates embedded sensing, on-device inference, and wireless communication to form a complete end-to-end AI hardware system.

All inference runs locally on the Arduino, demonstrating efficient embedded AI performance without reliance on cloud computation.

---

## Hardware Platform
- **Board:** Arduino Nano 33 BLE Sense Rev2  
- **Sensors:** Accelerometer and gyroscope (BMI270)  
- **Connectivity:** Bluetooth Low Energy (BLE)  

A camera-based approach was intentionally avoided to preserve mobility, reduce power consumption, and minimize inference latency.

---

## AI / Software Stack
- **ML Platform:** Edge Impulse  
- **Model Type:** Time-series gesture classification  
- **Input:** Accelerometer + gyroscope data (100 Hz)  
- **Deployment:** Quantized TinyML model (int8)  
- **Framework:** Arduino / C++  

---
## Dataset and Data Collection
Gesture data was collected using the onboard motion sensors of the Arduino Nano 33 BLE Sense Rev2 and labeled using Edge Impulse Studio.

**Dataset characteristics:**
- **Total samples:** 233  
- **Gesture classes:**  
  - Play  
  - Pause  
  - Skip  
  - Back  
  - Idle  
- **Sample length:** Approximately 2 seconds per gesture  
- **Sensors:** Accelerometer (X, Y, Z) and gyroscope (X, Y, Z)

Data collection focused on natural hand movements while holding the device. Raw sensor data is stored and managed within Edge Impulse and is not duplicated in this repository.

---

## Model Performance
- **Validation accuracy:** 94.6%  
- **Test accuracy:** 91.3%  
- **On-device latency:** ~40 ms  
- **Peak RAM usage:** 5.6 KB  
- **Flash usage:** 22.6 KB  

These results demonstrate accurate, low-latency inference on resource-constrained hardware.

---

## How To Use (Hardware + Software)

### Hardware Setup
1. Connect the Arduino Nano 33 BLE Sense Rev2 to your computer via USB.
2. Ensure the board is powered and recognized.

### Software Setup
1. Install the Arduino IDE or PlatformIO.
2. Install required libraries:
   - ArduinoBLE  
   - Arduino_BMI270_BMM150  
3. Import the Edge Impulse Arduino library generated from the Deployment section in Edge Impulse.

### Running the System
1. Upload the firmware from `gesture_ble_controller/`.
2. Open the Serial Monitor at 115200 baud to verify live inference output.
3. Pair your computer or phone with the BLE device named `GestureController`.
4. Perform trained hand gestures while holding the Arduino board to control media playback.

---

## Challenges Encountered
While gesture recognition and on-device inference were validated successfully through serial output, Bluetooth communication was occasionally unreliable after pairing with a host device. These issues are likely related to BLE timing constraints, HID compatibility, and the challenge of maintaining responsive wireless communication alongside real-time inference on constrained hardware.

This highlighted that system integration and communication reliability can be as challenging as model development in embedded AI projects.

---

## Future Work
Several extensions could improve the system:
- Improve BLE stability and HID compatibility across operating systems  
- Collect additional data to improve robustness across different users   
- Transition to a true wearable form factor, such as a ring or wrist-based device  
- Expand the gesture set to support additional interactions  

---

## Repository Structure
data/                   Dataset documentation
docs/                   Project proposal and planning
gesture_ble_controller/ Arduino firmware
presentations/          Presentation slides
src/                    Hardware and model documentation

