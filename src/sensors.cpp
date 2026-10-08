#include "sensors.h"
#include <cmath>

SensorReading generateSensorReading(int sampleNumber) {
    SensorReading reading;

    // Simulated embedded-system telemetry.
    // The values change gradually so the output resembles real sensor data.
    reading.temperature = 48.0 + 7.0 * std::sin(sampleNumber / 5.0);
    reading.cpuUsage = 45.0 + 25.0 * std::sin(sampleNumber / 4.0);
    reading.memoryUsage = 55.0 + 18.0 * std::cos(sampleNumber / 6.0);
    reading.voltage = 5.0 + 0.12 * std::sin(sampleNumber / 3.0);

    // Create occasional spikes so anomaly detection can be demonstrated.
    if (sampleNumber % 17 == 0 && sampleNumber != 0) {
        reading.temperature += 25.0;
    }

    if (sampleNumber % 23 == 0 && sampleNumber != 0) {
        reading.cpuUsage += 35.0;
    }

    return reading;
}

bool isAbnormal(const SensorReading& reading) {
    return reading.temperature > 70.0 ||
           reading.cpuUsage > 90.0 ||
           reading.memoryUsage > 90.0 ||
           reading.voltage < 4.75 ||
           reading.voltage > 5.25;
}
