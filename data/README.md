# Dataset Overview

This project uses motion sensor data collected from an Arduino Nano 33 BLE Sense Rev2 to train and evaluate a gesture recognition model. Data was collected and managed using the Edge Impulse platform.

## Data Source
- Device: Arduino Nano 33 BLE Sense Rev2  
- Sensors: Accelerometer (accX, accY, accZ), Gyroscope (gyrX, gyrY, gyrZ)  
- Sampling Rate: 100 Hz  
- Collection Platform: Edge Impulse Studio  

Raw sensor data is stored and labeled within Edge Impulse and is not duplicated in this repository.

## Gesture Classes
The dataset includes the following labeled gestures:
- Play  
- Pause  
- Skip  
- Back  
- Idle  

Each sample represents a short time window of natural hand movement corresponding to one gesture.

## Dataset Size
- Total samples: 233  
- Sample length: ~2 seconds per gesture  

## Preprocessing
Signal processing and feature extraction were handled automatically by Edge Impulse using time-series feature blocks. The final deployed model was quantized for efficient on-device inference.

## Access
Due to size and format constraints, raw datasets are hosted on Edge Impulse.  
Dataset access can be provided upon request or reproduced by following the data collection procedure described in the project report.

## Notes
This dataset was collected specifically for an academic project and is intended for research and educational purposes only.
