 int redpin = 0; 
 int bluepin = 1; 
 int greenpin = 2 ; 
 int val;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 19;  // the number of the pushbutton pin
   // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
     for (val = 255; val> 0; val --){
        analogWrite (0, val);
        analogWrite (1, 255-val);
        analogWrite (2, 128-val);
        delay (10);
}
  for (val = 0; val <255; val ++){
        analogWrite (0, val);
        analogWrite (1, 255-val);
        analogWrite (2, 128-val);
        delay (10);
}
  

  Serial.println (val, DEC);
}
}
