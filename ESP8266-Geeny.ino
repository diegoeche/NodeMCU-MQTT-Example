
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <FS.h>

// Replace these with your WiFi network settings
const char* ssid = "Telefonica NEXT Guest"; //replace this with your WiFi network name
const char* password = "geenyguest"; //replace this with your WiFi network password

const char* mqttServer = "mqtt.geeny.io";
const char* topic = "human_message";

const int mqttPort = 8883;

WiFiClientSecure espClient;
PubSubClient client(espClient);

bool isConnected = false;

void setup()
{
  delay(1000);
  
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
 
  Serial.println();
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("success!");
  
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());

  SPIFFS.begin();
  File ca = SPIFFS.open("/thing-crt.der", "r");
  
  if(!ca) {
    Serial.println("Couldn't load cert");
    return;  
  }

  if(espClient.loadCertificate(ca)) {
    Serial.println("Loaded Cert");
  } else {
    Serial.println("Didn't load cert");
    return;
  }
  
  File key = SPIFFS.open("/thing-key.der", "r");
  if(!key) {
    Serial.println("Couldn't load key");
    return;  
  }

  if(espClient.loadPrivateKey(key)) {
    Serial.println("Loaded Key");
  } else {
    Serial.println("Didn't load Key");
  }
  
  digitalWrite(LED_BUILTIN, HIGH);

  client.setServer(mqttServer, mqttPort);
  
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("3508f3a4-4902-4f69-96e8-2438eb901c84")) {
      Serial.println("connected");
      isConnected = true;
      
    } else {
 
      Serial.print("failed with state ");
      Serial.println(client.state());
      delay(2000);
    }
  }
 
  
}

void loop() {
  if(isConnected) {
    client.publish(topic, "Hello from ESP8266");
    Serial.println("Publishing...");
  }
  delay(1000);
}
