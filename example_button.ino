#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "yourssid";
const char* password = "yourpass";

const byte button_pin = 5; // pin D2
const byte relay_pin = 4; // pin D2

byte button_pressed;

void setup() {
  Serial.begin(115200);
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);  //put the Relays "OFF" at start

  WiFi.begin(ssid, password);
  Serial.print("Connecting ...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected! : ");
  Serial.println(WiFi.localIP());

  server.onNotFound([](){
    server.send(404, "text/plain", "404 not found!");  
  });

  server.on("/", []() {
    server.send(200, "text/plain", "Hello World ! Wemos D1 is working :)");
  });

  server.on("/relay_on", []() {
    server.send(200, "text/plain", "relay is on");
    digitalWrite(relay_pin, HIGH);
  });

  server.on("/relay_off", []() {
    server.send(200, "text/plain", "relay is off");
    digitalWrite(relay_pin, LOW);
  });

  server.on("/relay_status", []() {
    server.send(200, "text/plain", String(digitalRead(relay_pin)));
  });

  server.begin();
  Serial.println("server begin.");
}

void loop() {
  button_script();
  server.handleClient();  
}

void button_script() {
  int button_data = digitalRead(button_pin);
    if (button_data != button_pressed) {
        button_pressed = button_data;
        delay (50);             // debounce

        if (button_pressed == LOW)
            digitalWrite(relay_pin, !digitalRead(relay_pin));
    }
  
}
