# Hardware Design

This directory documents the hardware platform and design decisions used in the gesture-based embedded AI system.

---

## Hardware Overview
The system is built around the Arduino Nano 33 BLE Sense Rev2, a low-power embedded development board with integrated motion sensors and Bluetooth Low Energy (BLE) connectivity. The board enables real-time sensing, on-device inference, and wireless communication within a compact and portable form factor.

---

## Microcontroller
- **Board:** Arduino Nano 33 BLE Sense Rev2  
- **SoC:** Nordic nRF52840  
- **CPU:** ARM Cortex-M4F @ 64 MHz  
- **Memory:**  
  - 256 KB RAM  
  - 1 MB Flash  

The Cortex-M4F provides hardware floating-point support, making it well-suited for signal processing and TinyML inference tasks.

---

## Sensors
Gesture recognition relies on onboard motion sensors:

- **BMI270 Accelerometer**
  - Measures linear acceleration along X, Y, and Z axes
- **BMI270 Gyroscope**
  - Measures angular velocity along X, Y, and Z axes

Sensor data is sampled at 100 Hz and used as input to the gesture recognition model.

---

## Connectivity
- **Bluetooth Low Energy (BLE)**

BLE is used to transmit gesture-based control commands from the Arduino to a host device (e.g., laptop or phone). The system emulates media control behavior using BLE HID, enabling interaction with common media applications without additional software on the host.

---

## Design Decisions and Trade-Offs

### Motion Sensors vs. Camera
A camera-based gesture recognition approach was intentionally avoided. The Arduino Nano 33 BLE Sense Rev2 does not include a camera, and vision-based inference would significantly increase power consumption, latency, and system complexity. Motion-sensor-based gestures provide a more efficient and mobile solution for embedded hardware.

### On-Device Inference
All gesture classification is performed directly on the microcontroller. This eliminates the need for cloud connectivity, reduces latency, improves user privacy, and aligns with the constraints of embedded AI systems.

### Wearable Inspiration
While the final prototype requires holding the Arduino board, the hardware design was inspired by wearable gesture-control devices such as smart rings. The chosen platform allows rapid prototyping while maintaining portability and low power consumption.

---

## Limitations
- Limited onboard memory restricts model size and complexity  
- BLE communication can be sensitive to timing and system load  
- The prototype form factor is not fully wearable  

These limitations informed both the system design and proposed future improvements.

---

## Summary
The selected hardware platform provides an effective balance between sensing capability, computational performance, and power efficiency. It enables real-time embedded AI inference and wireless interaction, making it well-suited for exploring gesture-based human–computer interaction on constrained hardware.
