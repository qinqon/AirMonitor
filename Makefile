FQBN = esp32:esp32:esp32
SKETCH = AirMonitor.ino
PORT ?= /dev/ttyUSB0

all: compile

compile:
	arduino-cli compile --fqbn $(FQBN) $(SKETCH)

upload: compile
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

.PHONY: all compile upload monitor esphome-compile esphome-upload esphome-logs

monitor:
	arduino-cli monitor -p $(PORT) --config baudrate=115200

esphome-compile:
	esphome compile air_monitor.yaml

esphome-upload: esphome-compile
	esphome upload air_monitor.yaml --device $(PORT)

esphome-logs:
	esphome logs air_monitor.yaml --device $(PORT)
