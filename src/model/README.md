# Gesture Recognition Model

This directory documents the machine learning model used for gesture recognition in the embedded music control system. Model development, training, and deployment were performed using the Edge Impulse platform.

---

## Model Overview
The model is a time-series gesture classification neural network designed to run entirely on embedded hardware. It classifies short windows of motion sensor data into discrete gesture commands that are mapped to media control actions.

- **Target Device:** Arduino Nano 33 BLE Sense Rev2  
- **Inference Location:** On-device (TinyML)  
- **Model Type:** Multi-class neural network classifier  

---

## Input Data
The model uses motion sensor data collected from the onboard BMI270 sensor.

- **Sensors:**
  - Accelerometer (accX, accY, accZ)
  - Gyroscope (gyrX, gyrY, gyrZ)
- **Sampling Rate:** 100 Hz
- **Window Length:** ~2 seconds per inference
- **Input Format:** Time-series sensor fusion data

---

## Gesture Classes
The model classifies the following gestures:

- Play  
- Pause  
- Skip  
- Back  
- Idle  

Each class corresponds to a distinct hand motion performed while holding the device.

---

## Model Training
Model training was performed using Edge Impulse Studio. Signal processing and feature extraction were handled using Edge Impulse’s time-series feature pipeline, followed by supervised neural network training.

- **Training Platform:** Edge Impulse
- **Optimization:** Post-training quantization (int8)
- **Loss Function:** Categorical cross-entropy
- **Evaluation:** Validation and test datasets

Raw training scripts are not included in this repository, as Edge Impulse manages the training pipeline internally.

---

## Model Performance
The trained model achieved the following performance metrics:

- **Validation Accuracy:** 94.6%
- **Test Accuracy:** 91.3%

### On-Device Performance
Measured on the Arduino Nano 33 BLE Sense Rev2:

- **Inference Latency:** ~40 ms
- **Peak RAM Usage:** 5.6 KB
- **Flash Usage:** 22.6 KB

These results demonstrate that the model meets real-time constraints for embedded gesture recognition.

---

## Deployment
The trained model was exported from Edge Impulse as an Arduino-compatible C++ library and integrated directly into the firmware.

- **Deployment Format:** Edge Impulse Arduino Library
- **Inference Framework:** Edge Impulse runtime
- **Quantization:** Enabled for efficiency

---

## Notes
This project focuses on on-device inference and does not rely on cloud-based computation. The model and system design emphasize low latency, power efficiency, and portability for embedded and wearable use cases.
