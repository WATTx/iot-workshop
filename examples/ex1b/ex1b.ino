int led = D5; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); //     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // the built-in LED is unusual (it turns on when it's low and off when it's high)
  digitalWrite(led, HIGH); // The LED you set-up turns on when it's high as expected            
  delay(300); // The program stops for 0.3 seconds. The value inside the () is in milliseconds.
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(led, LOW);
  delay(300);   
}



