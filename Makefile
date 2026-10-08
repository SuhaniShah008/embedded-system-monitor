CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

monitor: src/monitor.cpp src/sensors.cpp
	$(CXX) $(CXXFLAGS) src/monitor.cpp src/sensors.cpp -o monitor

run: monitor
	./monitor

clean:
	rm -f monitor
