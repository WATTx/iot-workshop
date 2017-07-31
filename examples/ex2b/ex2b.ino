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
int motionSensorPin = D1;
int motionState;
//bool alarmTriggered = false; // We're adding this boolean variable so you don't get too many notifications

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "get_it_from_your_app_or_check_your_email";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WATTx_WiFi";
char pass[] = "check_the_screen";

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT); 
  Serial.begin(9600); // We'll use Serial to talk with the computer
  Blynk.begin(auth, ssid, pass);
}


void loop()
{
  Blynk.run(); // Initiates Blynk
  motionState = digitalRead(motionSensorPin); // Reading the state of the sensor

  if (motionState == LOW) // if value is LOW, then no motion has been detected
  {
    Serial.println("No motion detected");   
  }
  else  // if value is something other than LOW then it must be HIGH meaning motion has been detected
  {
    Serial.println("Motion detected!! Someone is here!");
    Blynk.notify("ALARM! Your motion detector has sensed someone!");
    // This will trigger a notification on your phone
    
    blinkLeds();
    digitalWrite(LED_BUILTIN, HIGH); // Turn off the built-in LED
  }
  delay(2000);
}

void blinkLeds() {
  digitalWrite(LED_BUILTIN, HIGH);   // the built-in LED is unusual 
  digitalWrite(led, HIGH);            // (it turns on when it's low and off when it's high)
  delay(300); // The program stops for 0.3 seconds. The value inside the () is in milliseconds.
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(led, LOW);
  delay(300);   
}

