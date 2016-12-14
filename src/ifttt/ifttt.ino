/*
 *  This sketch sends data via HTTP GET requests to IFTTT Maker channel service.
 *
 *  You need to  privateKey from the Maker channel on IFTTT and paste it
 *  below. 
 *
 * Based on the example code for WiFi client and button debounce example from Arduno IDE
 */

#include <ESP8266WiFi.h>

void send_event(const char *event);

// constants won't change. They're used here to
// set pin numbers:

// Wifi setup
const char *ssid     = "XXXX";
const char *password = "XXXXX";

// IFTTT setup
const char *host = "maker.ifttt.com";
const char *privateKey = "mGHBR8ACguChSfwY38WHLBj46ercITqKMlFhacszvOx";

// Hardware setup
const int ledPin = 0;        // the number of the LED pin

void setup() 
{
  // Set your pin modes
  pinMode(ledPin, OUTPUT);
  
  // Bring up the serial for a bit of debugging
  Serial.begin(9600);
  delay(10);

  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for the connection, flashing the LED while we wait
  int led = HIGH;  
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    digitalWrite(ledPin, led);
    led = !led;
  }
  digitalWrite(ledPin, LOW);

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  
  send_event("wemos");
  delay(1000);
}

void send_event(const char *event)
{
  // set the LED on whle we are sending the event
  digitalWrite(ledPin, HIGH);

  Serial.print("Connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/trigger/";
  url += event;
  url += "/with/key/";
  url += privateKey;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  // Read all the lines of the reply from server and print them to Serial,
  // the connection will close when the server has sent all the data.
  while(client.connected())
  {
    if(client.available())
    {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    } else {
      // No data yet, wait a bit
      delay(50);
    };
  }
  
  // All done
  Serial.println();
  Serial.println("closing connection");

  client.stop();
  
  // Finished sending the message, turn off the LED
  digitalWrite(ledPin, LOW);
}