# University of Virginia
## Department of Electrical and Computer Engineering

**Course:** ECE 4332 / ECE 6332 — AI Hardware Design and Implementation  
**Semester:** Fall 2025  
**Proposal Deadline:** November 5, 2025 — 11:59 PM  
**Submission:** Upload to Canvas (PDF) and to GitHub (`/docs` folder)

---

# AI Hardware Project Proposal

## 1. Gesture-Controlled Devices on TinyML
**Team Name:** Arduino Accelerators  

**Team Members:**  
Mehnaz Tasnim, Will Goodwin

---

## 2. Platform Selection
For this project, we chose to work with TinyML on the Arduino Nano 33 BLE Sense. This platform provides a compact, low-power embedded system with integrated sensing and Bluetooth capabilities, making it well-suited for real-time gesture recognition tasks.

The Arduino Nano 33 BLE Sense includes a built-in 9-axis IMU, allowing us to track user motion without requiring additional external sensors. Leveraging the board’s onboard hardware minimizes system complexity while enabling efficient on-device inference.

**Undergraduates:** Edge-AI, TinyML, or Neuromorphic platforms  
**Graduates:** Open-source AI accelerators (Ztachip, VTA, Gemmini, VeriGOOD-ML, NVDLA), or any of the above  

---

## 3. Problem Definition
Traditional touchscreens and physical buttons can be inefficient or unsafe in hands-busy environments such as driving or lecturing. Users often struggle with button layouts or device interaction when attention must remain focused elsewhere. While early gesture-control systems—such as those explored by BMW—attempted to address this issue, hardware limitations at the time prevented low-latency and intuitive performance.

This project aims to deploy an AI-based gesture recognition system on embedded hardware, enabling users to control media playback without physical interaction with buttons or screens. Recognized gestures will allow users to play, pause, skip, rewind, and adjust volume. From an AI hardware perspective, this project focuses on evaluating inference latency, efficiency, and memory usage of TinyML models running entirely on-device.

---

## 4. Technical Objectives
The following measurable objectives define the success of the project:

1. Collect and label IMU training data for multiple hand gestures.  
   - At least 4 gesture classes  
   - Approximately 200 samples per gesture class  

2. Train and deploy a TinyML model capable of real-time gesture classification.  
   - Minimum target accuracy: 85%  

3. Achieve low-latency on-device inference.  
   - Target inference time ≤ 250 ms  

4. Minimize memory usage on embedded hardware.  
   - Target memory usage ≤ 300 KB  

---

## 5. Methodology

### Hardware Setup
- Platform: Arduino Nano 33 BLE Sense with built-in IMU  
- LED used for basic visualization and debugging  

### Software Tools
- **Edge Impulse:** Data collection, labeling, model training, and deployment  
- **Arduino IDE:** Firmware upload and on-device inference  
- **Edge Impulse CLI:** Live data collection and testing  

### Model Design
- **Input:** IMU sensor data (accelerometer and gyroscope)  
- **Preprocessing:** Normalization and time-series feature extraction  
- **Model Architecture:** 1D Convolutional Neural Network (CNN)  

### Performance Metrics
- Inference latency (ms)  
- Classification accuracy (%)  
- Memory usage (KB)  

### Validation Strategy
- Dataset split:  
  - Training: 70%  
  - Validation: 20%  
  - Test: 10%  

---

## 6. Expected Deliverables
- Fully functional gesture-controlled media system  
- Trained TinyML model running on embedded hardware  
- GitHub repository with source code and documentation  
- Presentation slides (midterm and final)  
- Final written report  

---

## 7. Team Responsibilities

| Name | Responsibilities |
|------|------------------|
| Mehnaz Tasnim & Will Goodwin | Documentation, hardware setup, data collection |
| Mehnaz Tasnim | GitHub organization, model training |
| Will Goodwin | Model integration, testing, and evaluation |

---

## 8. Timeline and Milestones

| Week | Milestone | Deliverable |
|------|-----------|-------------|
| 2 | Proposal | PDF + GitHub submission |
| 4 | Midterm presentation | Slides and preliminary results |
| 6 | Integration and testing | Working prototype |
| Dec. 18 | Final presentation | Report, demo, GitHub archive |

---

## 9. Resources Required
- Arduino Nano 33 BLE Sense  
- USB connection to host device  
- Arduino IDE  
- Edge Impulse platform  

---

## 10. References
- TinyML Considerations:  
  https://www.renesas.com/en/blogs/four-metrics-you-must-consider-when-developing-tinyml-systems  
- Arduino IMU Documentation:  
  https://docs.arduino.cc/tutorials/nano-33-ble-sense/imu-accelerometer/  
- Gesture-Based Media Control Examples:  
  https://www.hackster.io/jithinsanal1610/gesture-based-media-player-controller-using-arduino-b78647  

