#include "sensors.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <thread>

int main() {
    std::ofstream output("data/system_metrics.csv");

    if (!output.is_open()) {
        std::cerr << "Unable to open data/system_metrics.csv\n";
        return 1;
    }

    output << "sample,temperature_c,cpu_percent,memory_percent,voltage_v,status\n";

    std::cout << "Embedded System Performance Monitor\n";
    std::cout << "Collecting 60 telemetry samples...\n\n";

    for (int i = 0; i < 60; i++) {
        SensorReading reading = generateSensorReading(i);
        bool abnormal = isAbnormal(reading);

        output << i << ","
               << std::fixed << std::setprecision(2)
               << reading.temperature << ","
               << reading.cpuUsage << ","
               << reading.memoryUsage << ","
               << reading.voltage << ","
               << (abnormal ? "ALERT" : "NORMAL")
               << "\n";

        std::cout << "Sample " << std::setw(2) << i
                  << " | Temp: " << std::setw(6) << reading.temperature << " C"
                  << " | CPU: " << std::setw(6) << reading.cpuUsage << "%"
                  << " | Memory: " << std::setw(6) << reading.memoryUsage << "%"
                  << " | Voltage: " << reading.voltage << " V"
                  << " | " << (abnormal ? "ALERT" : "NORMAL")
                  << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
    }

    output.close();

    std::cout << "\nTelemetry saved to data/system_metrics.csv\n";
    return 0;
}
