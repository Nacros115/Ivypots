int redpin = 0; 
int bluepin = 1; 
int greenpin = 2 ; 
int val;
int buttonState = 0;   
const int buttonPin = 19;   
void setup () {
pinMode(buttonPin, INPUT);
pinMode (redpin, OUTPUT);
pinMode (bluepin, OUTPUT);
pinMode (greenpin, OUTPUT);
Serial.begin (9600);
}
void loop ()
{while( buttonState == HIGH){
   
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
}}
 
Serial.println (val, DEC);
}
