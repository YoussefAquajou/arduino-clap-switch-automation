Acoustic Automation Switch (Arduino)
An embedded systems project featuring a sound-activated control interface. This system utilizes an Arduino Uno and a KY-038 acoustic sensor to toggle electrical outputs (LEDs/Relays) via specific double-clap audio patterns.

Overview
The "Clap Switch" is designed to provide hands-free control over devices. Unlike simple sound detectors, this project implements a temporal filtering algorithm to distinguish between intentional double-claps and random background noise.

Hardware Requirements
Microcontroller: Arduino Uno R3

Sensor: KY-038 High-Sensitivity Sound Sensor (Digital Output mode)

Actuator: 5V LED (Replaceable with a Relay Module for 220V appliances)

Connectivity: Jumper wires and breadboard

Technical Implementation
1. Pattern Recognition Logic
The software monitors the digital state of the KY-038. It uses the millis() function to track the time delta between high-signal spikes.

Double-Clap Window: Both sounds must occur within a 500ms window.

Noise Rejection: A 50ms debounce delay prevents the system from misinterpreting echoes or single long sounds as multiple claps.

2. Sensitivity Calibration
The KY-038 features an onboard potentiometer. For this project, the hardware was calibrated to trigger only on high-decibel, short-duration impulses (claps) while ignoring ambient conversation.

Repository Structure
Plaintext
├── clap_switch.ino      # Main Arduino source code (C++)
├── docs/                # Project documentation and schematics
│   └── project_report.pdf 
└── assets/              # Wiring diagrams and project photos
Installation & Setup
Wiring: Connect the KY-038 VCC to 3.3V, GND to GND, and DO to Pin 2. Connect the LED Anode to Pin 13.

Software: Open clap_switch.ino in the Arduino IDE.

Upload: Select your board and port, then click Upload.

Monitor: Open the Serial Monitor (9600 baud) to view real-time detection logs.

Future Enhancements
Relay Integration: Transitioning from an LED to a 5V Relay for controlling lamps or fans.

Rhythm Coding: Programming specific sequences (e.g., 3 claps) to trigger secondary devices.

Analog Analysis: Switching to the sensor's Analog Output for more precise sound-level thresholding.