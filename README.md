# Embedded System Performance Monitor

A lightweight telemetry monitoring project that simulates an embedded device, records system metrics in C++, detects abnormal readings, and visualizes the data in a Python dashboard.

## Overview

Embedded systems often need continuous monitoring to detect overheating, resource spikes, or unstable power conditions. This project simulates that workflow by generating telemetry for:

- Temperature
- CPU utilization
- Memory utilization
- Supply voltage
- System health status

The C++ monitor generates readings and performs simple threshold-based anomaly detection. Measurements are written to a CSV file and displayed in an interactive Streamlit dashboard.

## Features

- C++ telemetry generation
- Threshold-based anomaly detection
- CSV data logging
- Python data processing with pandas
- Interactive Streamlit dashboard
- Temperature, CPU, memory, and voltage visualization
- Automatic alert table for abnormal readings

## Project Structure

```text
embedded-system-monitor/
├── src/
│   ├── monitor.cpp
│   ├── sensors.cpp
│   └── sensors.h
├── dashboard/
│   └── app.py
├── data/
│   └── system_metrics.csv
├── Makefile
├── requirements.txt
├── .gitignore
└── README.md
```

## How It Works

1. `monitor.cpp` requests simulated telemetry readings.
2. `sensors.cpp` generates changing system measurements.
3. Each reading is checked against safety thresholds.
4. Data is written to `data/system_metrics.csv`.
5. The Streamlit dashboard loads the CSV and visualizes the results.

Current alert thresholds include:

- Temperature above 70 °C
- CPU usage above 90%
- Memory usage above 90%
- Voltage outside the 4.75 V to 5.25 V range

## Build and Run the C++ Monitor

### macOS / Linux / WSL

```bash
make
./monitor
```

Or compile manually:

```bash
g++ -std=c++17 src/monitor.cpp src/sensors.cpp -o monitor
./monitor
```

### Windows with g++

```bash
g++ -std=c++17 src/monitor.cpp src/sensors.cpp -o monitor.exe
monitor.exe
```

## Run the Dashboard

Install the Python dependencies:

```bash
pip install -r requirements.txt
```

Then launch Streamlit from the project root:

```bash
streamlit run dashboard/app.py
```

## Example Use Case

This project models a simplified health-monitoring pipeline that could be used in an IoT device, robotics controller, edge-computing platform, or other embedded system.

A real hardware implementation could replace the simulated readings with measurements from components such as:

- temperature sensors
- current or voltage sensors
- microcontroller diagnostics
- Raspberry Pi system telemetry
- robotics control hardware

## Technologies

- C++17
- Python
- pandas
- Streamlit
- CSV-based telemetry logging

## Future Improvements

- Read live hardware sensor data instead of simulated telemetry
- Publish readings through MQTT
- Store telemetry in SQLite
- Add moving-average anomaly detection
- Add real-time serial communication with a microcontroller
- Create automated tests for sensor thresholds

## Why I Built This

I wanted to explore how embedded systems can collect telemetry, detect abnormal operating conditions, and make low-level device information easier to understand through a higher-level monitoring interface.
