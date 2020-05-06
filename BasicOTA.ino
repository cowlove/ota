#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFiManager.h>
#include <NTPClient.h>

const char* ssid = "Flora_2GEXT";
const char* password = "maynards";


WiFiUDP udp;
WiFiManager wman;
NTPClient ntp(udp);

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  wman.autoConnect();

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    //ESP.restart();
  }

  ArduinoOTA.begin();
  ntp.begin();
  
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

uint64_t lastMillis;
void loop() {
	if (millis() / 1000 != lastMillis / 1000)  {
		udp.beginPacket("255.255.255.255", 9000);
		char b[128];
		snprintf(b, sizeof(b), "%d %s %s\n", (int)(millis() / 1000), WiFi.localIP().toString().c_str(), ntp.getFormattedTime().c_str());
		udp.write((const uint8_t *)b, strlen(b));
		udp.endPacket();
	}
	lastMillis = millis();
	ArduinoOTA.handle();
	ntp.update();
}
