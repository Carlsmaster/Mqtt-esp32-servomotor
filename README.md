# ESP32 MQTT Servo Control

This project enables control of a servo motor connected to an ESP32 microcontroller through MQTT messages. The servo motor's position is adjusted based on the received MQTT messages "a" and "b."

## Hardware Requirements

- ESP32 microcontroller
- Servo motor
- WiFi connection
- MQTT broker (e.g., on Jetson Nano)
- LEDs for status indicators (optional)

- Open the project in the Arduino IDE.

Adjust the following variables in the code to match your configuration:
1 Open the project in the Arduino IDE.
2 Adjust the following variables in the code to match your configuration:

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
const char* mqtt_server = "YourBrokerIPAddress";
const char* mqtt_user = "YourMQTTUser";
const char* mqtt_password = "YourMQTTPassword";

****************Usage**********************
Connect the servo motor to the specified pin (servoPin) on the ESP32.

Power on the ESP32.

The ESP32 will attempt to connect to your WiFi network and the MQTT broker.

Once connected, it will subscribe to the "control_servo_topic" on the MQTT broker.

Send MQTT messages "a" and "b" to control the servo motor:

"a": Rotate the servo to position 160.
"b": Rotate the servo to position 0.
Status LEDs (Optional)
You can use LEDs for status indicators:

led_Mqtt: Indicates MQTT connection status.
led_wifi: Indicates WiFi connection status.

