
void send_event(const char *event);


// IFTTT setup
const char *host = "maker.ifttt.com";
const char *privateKey = "mGHBR8ACguChSfwY38WHLBj46ercITqKMlFhacszvOx";



void sendSensor() 
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