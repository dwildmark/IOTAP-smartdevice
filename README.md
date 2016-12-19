# IOTAP-smartdevice

This is a simple two-part application that uses a CLI to communicate between a serial device and an Arduino. It can so far measure distance if a HC-SR04 is connected to it.

### Python
The python client is configured to connect to Bluemix and listen for commands.
### Usage

Commands:
* 'D': returns the distance detected by HC-SR04. E.g. Send 'D', receive 'D:54'.
