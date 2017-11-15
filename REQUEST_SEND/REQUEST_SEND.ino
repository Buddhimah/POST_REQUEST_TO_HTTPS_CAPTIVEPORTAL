#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <WiFiClientSecure.h>
#include <ESP8266Ping.h>

const char* ssid     = "SSID";
const int httpsPort = 443;

const char* url="https://url";

String data="username=####&password=####&buttonClicked=4";



const char* host = "host";

void setup() {
  Serial.begin(115200);
  delay(100);
  
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid);

 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
   client.print(String("POST ") + url + " HTTPS/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "Content-Type: application/x-www-form-urlencoded\r\n" +
                 "Content-Length: " + data.length() + "\r\n" +
                 "\r\n" + // This is the extra CR+LF pair to signify the start of a body
                 data + "\n");
    //Delay
    delay(1000);

     bool ret = Ping.ping("iot.eclipse.org");
        Serial.println(ret);


       


 

}

void loop() {

}
