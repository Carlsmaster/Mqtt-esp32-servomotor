"
ESP32 Control Servomotor using mqtt protocol

This project enables control of a servo motor connected to an ESP32 microcontroller through MQTT messages. 
The servo motor's position is adjusted based on the received MQTT messages "a" and "b."

Requirements:
- ESP32 microcontroller
- Servo motor
- WiFi connection
- MQTT broker (e.g., on Raspberry or other you chose)
- LEDs for status indicators (optional)

Note: Adjust  pin numbers according to your hardware configuration.

Author: [Eduardo Valdez] date:11/29/2023
"""
#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h>

Servo myServo;
int servoPin = 13;
int led_Mqtt = ;
int led_wifi = ;
int led_status= ;

const char* ssid = "Your ssid";
const char* password = "your password";
const char* mqtt_server = "IP adress of your broker"; 
const int mqtt_port = 1883; // Puerto predeterminado para MQTT

const char* mqtt_user = "Broker user name"; // Usuario configurado en tu broker MQTT
const char* mqtt_password = "Broker password"; // Contraseña configurada en tu broker MQTT
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  connectToWiFi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  // Actuar según el mensaje recibido
  if (message == "a") {
    Serial.println("Recibido el mensaje 'a'");
    delay(1000);
    int angle  = 160;
    myServo.write(angle);
  } else if (message == "b") {
    Serial.println("Recibido el mensaje 'b'");
    delay(1000);
    int angle  = 0;
    myServo.write(angle);
  }
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Conectando a MQTT...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("Conectado a MQTT");
      client.subscribe("control_servo_topic");
    } else {
      delay(1000);
    }
  }
}
