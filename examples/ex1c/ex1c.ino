int led = D5; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);     
}
   
// the loop routine runs over and over again forever:
void loop() {
  blinkLeds();
}

void blinkLeds() {
  digitalWrite(LED_BUILTIN, HIGH);   // the built-in LED is unusual 
  digitalWrite(led, HIGH);            // (it turns on when it's low and off when it's high)
  delay(300); // The program stops for 0.3 seconds. The value inside the () is in milliseconds.
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(led, LOW);
  delay(300);   
}

