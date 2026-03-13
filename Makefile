FQBN = esp32:esp32:esp32
SKETCH = AirMonitor.ino
PORT ?= /dev/ttyUSB0

all: compile

compile:
	arduino-cli compile --fqbn $(FQBN) $(SKETCH)

upload: compile
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

.PHONY: all compile upload monitor

monitor:
	arduino-cli monitor -p $(PORT) --config baudrate=115200
