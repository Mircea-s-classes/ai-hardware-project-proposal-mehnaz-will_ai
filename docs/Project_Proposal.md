# University of Virginia
## Department of Electrical and Computer Engineering

**Course:** ECE 4332 / ECE 6332 — AI Hardware Design and Implementation  
**Semester:** Fall 2025  
**Proposal Deadline:** November 5, 2025 — 11:59 PM  
**Submission:** Upload to Canvas (PDF) and to GitHub (`/docs` folder)

---

# AI Hardware Project Proposal Template

## 1. Gesture-Controlled Devices on TinyML
Arduino Accelerators

Mehnaz Tasnim, Will Goodwin

Provide a clear and concise title for your project. 

## 2. Platform Selection
For our project, we decided to work with TinyML. More specifcially, we chose the Arduino Nano 33 BLE Sense. This platform has many built in features and sensors, such as a 9-axis IMU, which allows us track user movements and other inputs. The variety of sensors on this platform helps to limit the amount of extra hardware we need to effectively deploy the project. 

**Undergraduates:** Edge-AI, TinyML, or Neuromorphic platforms  
**Graduates:** open-source AI accelerators (Ztachip, VTA, Gemmini, VeriGOOD-ML, NVDLA) or any of the above 

## 3. Problem Definition
Describe the AI or hardware design problem you aim to address and its relevance to AI hardware (e.g., efficiency, latency, scalability).
Traditional touch screens and buttons can often be unreliable or inefficient when completing certain tasks in busy environments. Users often struggle with certain button layouts and other user actions on their devices when completing tasks such as lecturing or driving their vehicles. BMW actually addressed this issue years ago, but the technology of the time was not capable of low latency and intuitive response. Our project aims to deploy an AI system that runs gesture recognition on embedded hardware with the goal of allowing users control over their devices without ever having to interact with a touch screen or button. These gesture controls will allow the user to change the volume, skip, play, pause, and rewind controls of their music. This project directly relates to AI hardware by allowing us to analyze the inference efficiency and latency of models using an on-device TinyML platform. 

## 4. Technical Objectives
List 3–5 measurable objectives with quantitative targets when possible.

1. Collect and label IMU training data for various hand gestures.
   - 4 or more gestures classes 
   - 200 samples per gesture class
2. Train and deploy TinyML model with the ability to detect and classify hand gestures in real time.
   - 85% minimum recognition accuracy
3. Reach low-latency inference times.
   - Achieve inference times less than or equal to 250ms
4. Minimize power and memory usage on hardware
   - Less than 300kB memory usage


## 5. Methodology
Describe your planned approach: hardware setup, software tools, model design, performance metrics, and validation strategy.
Hardware Setup:
- Platform: Arduino Nano 33 BLE Sense with built-in IMU
- LED for visualization
Software Tools:
- Edge Impulse: for model training, data collection, and model deployment
- Arduino IDE: for coding the model
- TensorFlow: quantization and inference
Model Design:
Model Perfomance Metrics:
- Latency (ms)
- Accuracy (%)
- Memory Usage (KB)
Validation Strategy:
- Collect samples from various users
- Data Split: Training - 70%, Validation - 20%, Test - 10%

## 6. Expected Deliverables
List tangible outputs: working demo, GitHub repository, documentation, presentation slides, and final report.

## 7. Team Responsibilities
List each member’s main role.

| Name | Role | Responsibilities |
|------|------|------------------|
| [Student A] | Team Lead | Coordination, documentation |
| [Student B] | Hardware | Setup, integration |
| [Student C] | Software | Model training, inference |
| [Student D] | Evaluation | Testing, benchmarking |

## 8. Timeline and Milestones
Provide expected milestones:

| Week | Milestone | Deliverable |
|------|------------|-------------|
| 2 | Proposal | PDF + GitHub submission |
| 4 | Midterm presentation | Slides, preliminary results |
| 6 | Integration & testing | Working prototype |
| Dec. 18 | Final presentation | Report, demo, GitHub archive |

## 9. Resources Required
List special hardware, datasets, or compute access needed.

## 10. References
Include relevant papers, repositories, and documentation.

Temporary links: 
- TinyML Considerations: https://www.renesas.com/en/blogs/four-metrics-you-must-consider-when-developing-tinyml-systems?srsltid=AfmBOorvVIQH1DA60rOIk2xxC1-hCXHDlXCVZJQzHSADJstbeDEpeneR
- Arduino IMU: https://docs.arduino.cc/tutorials/nano-33-ble-sense/imu-accelerometer/


