/*
 Smart Waste Bin Node Firmware
 Platform: ESP32
 Function: Fill-level monitoring and event-based reporting
*/

#include <WiFi.h>
#include <PubSubClient.h>

#define TRIG_PIN 5
#define ECHO_PIN 18
#define BIN_HEIGHT_CM 100
#define FILL_THRESHOLD 80   // percentage

WiFiClient espClient;
PubSubClient client(espClient);

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

int calculateFillPercentage(long distance) {
  int fill = ((BIN_HEIGHT_CM - distance) * 100) / BIN_HEIGHT_CM;
  return constrain(fill, 0, 100);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin("SSID", "PASSWORD");
  client.setServer("broker.hivemq.com", 1883);
}

void loop() {
  if (!client.connected()) {
    client.connect("BinNode01");
  }

  long distance = measureDistance();
  int fillLevel = calculateFillPercentage(distance);

  if (fillLevel >= FILL_THRESHOLD) {
    String payload = String("{\"bin_id\":\"B01\",\"fill\":") + fillLevel + "}";
    client.publish("waste/bin/status", payload.c_str());
  }

  delay(60000); // sample every 1 minute
}
