#ifndef SENSORS_H
#define SENSORS_H

struct SensorReading {
    double temperature;
    double cpuUsage;
    double memoryUsage;
    double voltage;
};

SensorReading generateSensorReading(int sampleNumber);
bool isAbnormal(const SensorReading& reading);

#endif
