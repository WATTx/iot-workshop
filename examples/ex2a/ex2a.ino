int led = D5;
int motionSensorPin = D1;
int motionState;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT); 
  Serial.begin(9600); // We'll use Serial to talk with the computer
      
}
   
// the loop routine runs over and over again forever:
void loop() {

  motionState = digitalRead(motionSensorPin); // Reading the state of the sensor

  if (motionState == LOW) // if value is LOW, then no motion has been detected
  {
    Serial.println("No motion detected");   
  }
  else  // if value is something other than LOW then it must be HIGH meaning motion has been detected
  {
    Serial.println("Motion detected!! Someone is here!");
    blinkLeds();
    digitalWrite(LED_BUILTIN, HIGH); // Turn off the built-in LED
  }
  delay(500);
  
}

void blinkLeds() {
  digitalWrite(LED_BUILTIN, HIGH);   // the built-in LED is unusual 
  digitalWrite(led, HIGH);            // (it turns on when it's low and off when it's high)
  delay(300); // The program stops for 0.3 seconds. The value inside the () is in milliseconds.
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(led, LOW);
  delay(300);   
}

