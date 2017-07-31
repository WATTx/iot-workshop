/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>

int led = D5;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "get_it_from_your_app_or_check_your_email";



// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WATTx_WiFi";
char pass[] = "check_the_screen";


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}


void loop()
{
  Blynk.run(); // Initiates Blynk
}
