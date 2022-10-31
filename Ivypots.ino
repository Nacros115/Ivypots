/*
          _____                    _____                _____                    _____                   _______               _____                    _____
         /\    \                  /\    \              |\    \                  /\    \                 /::\    \             /\    \                  /\    \
        /::\    \                /::\____\             |:\____\                /::\    \               /::::\    \           /::\    \                /::\    \
        \:::\    \              /:::/    /             |::|   |               /::::\    \             /::::::\    \          \:::\    \              /::::\    \
         \:::\    \            /:::/    /              |::|   |              /::::::\    \           /::::::::\    \          \:::\    \            /::::::\    \
          \:::\    \          /:::/    /               |::|   |             /:::/\:::\    \         /:::/~~\:::\    \          \:::\    \          /:::/\:::\    \
           \:::\    \        /:::/____/                |::|   |            /:::/__\:::\    \       /:::/    \:::\    \          \:::\    \        /:::/__\:::\    \
           /::::\    \       |::|    |                 |::|   |           /::::\   \:::\    \     /:::/    / \:::\    \         /::::\    \       \:::\   \:::\    \
  ____    /::::::\    \      |::|    |     _____       |::|___|______    /::::::\   \:::\    \   /:::/____/   \:::\____\       /::::::\    \    ___\:::\   \:::\    \
 /\   \  /:::/\:::\    \     |::|    |    /\    \      /::::::::\    \  /:::/\:::\   \:::\____\ |:::|    |     |:::|    |     /:::/\:::\    \  /\   \:::\   \:::\    \
/::\   \/:::/  \:::\____\    |::|    |   /::\____\    /::::::::::\____\/:::/  \:::\   \:::|    ||:::|____|     |:::|    |    /:::/  \:::\____\/::\   \:::\   \:::\____\
\:::\  /:::/    \::/    /    |::|    |  /:::/    /   /:::/~~~~/~~      \::/    \:::\  /:::|____| \:::\    \   /:::/    /    /:::/    \::/    /\:::\   \:::\   \::/    /
 \:::\/:::/    / \/____/     |::|    | /:::/    /   /:::/    /          \/_____/\:::\/:::/    /   \:::\    \ /:::/    /    /:::/    / \/____/  \:::\   \:::\   \/____/
  \::::::/    /              |::|____|/:::/    /   /:::/    /                    \::::::/    /     \:::\    /:::/    /    /:::/    /            \:::\   \:::\    \
   \::::/____/               |:::::::::::/    /   /:::/    /                      \::::/    /       \:::\__/:::/    /    /:::/    /              \:::\   \:::\____\
    \:::\    \               \::::::::::/____/    \::/    /                        \::/____/         \::::::::/    /     \::/    /                \:::\  /:::/    /
     \:::\    \               ~~~~~~~~~~           \/____/                          ~~                \::::::/    /       \/____/                  \:::\/:::/    /
      \:::\    \                                                                                       \::::/    /                                  \::::::/    /
       \:::\____\                                                                                       \::/____/                                    \::::/    /
        \::/    /                                                                                        ~~                                           \::/    /
         \/____/                                                                                                                                       \/____/


  Fichier :       Ivypots.ino
  
  Description :   This program allows you to control your plants and create water from a Peltier module 
  but also to measure temperature and hygrometry with a DHT11, 
  and to store these informations on an SD card, in a file in CVS. format (importable in Excel)
  
 Please note that some elements are missing like the NFC for the app, and the link between the app and the pots it's because this project is still under development.
 
  Auteur :        Nayel Khouatra
  Créé le :       28.10.2022

*/


////Led RGB BOOT////
int redpin = 2; 
int bluepin = 0; 
int greenpin = 1 ; 
int val;
int delayPeriod = 500; 

/*////Dht sensor/////
#include "DHT.h"
#define DHTPIN 28
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);*/


////AHT10///
#include <AHT10.h>
#include <Wire.h>
uint8_t readStatus = 0;
AHT10 myAHT10(AHT10_ADDRESS_0X38);




////Photo resistor////
int valeur = analogRead(A2);
int Luminar = 5;
// Analog input pin for the LDR
int pinLDR = 28;
// Variable where the LDR value is stored
int LDRvalue = 0;  


////Moisture sensor/////
#define Dry 600 
#define Wet 550 // CHANGE YOUR THRESHOLD HERE
 

/////Relay/////
#define RELAY_PIN 4
 


void setup() {
  Serial.begin(115200);
  ////Relay//// 
  pinMode(RELAY_PIN, OUTPUT);  

  ////PHOTO RESISTOR////
  pinMode(Luminar, OUTPUT);

  ////RGB LED////
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
 
  ////RGB LED////
  for (int i = 0; i < 3; i++){
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
    } 
  
 ////AHT 10////
 
  Serial.println();
  
  while (myAHT10.begin() != true)
  {
    Serial.println(F("AHT10 not connected or fail to load calibration coefficient")); //(F()) save string to flash & keeps dynamic memory free
    delay(5000);
  }
  Serial.println(F("AHT10 OK"));

 
 
}


// =================
// Main loop
// ================= 
void loop() {

  ////PHOTO RESISTOR//// 
  digitalWrite (Luminar, LOW);
   
  LDRvalue = analogRead (pinLDR);
  while(LDRvalue< 256){
   
    digitalWrite (Luminar, HIGH);
    Serial.println ("La lampe sera allumé");
    delay(5000);
    Serial.println (LDRvalue);
  
  }
  while(LDRvalue< 768){
  
    digitalWrite (Luminar, LOW);
    Serial.println ("La lampe sera éteinte");
    delay(5000);
    Serial.println (LDRvalue);
  }
  // Wait a few milliseconds before updating
  
  
////Moisture sensor////
  int value = analogRead( A0); // read the analog value from sensor

  if (value > Dry) {
    Serial.print("The soil is DRY => turn pump ON");
    digitalWrite(RELAY_PIN, HIGH);
    Serial.print(" (");
    Serial.print(value);
    Serial.println(")");
    delay(3000);
  } else if (value < Wet){
    Serial.print("The soil is WET => turn pump OFF");
    digitalWrite(RELAY_PIN, LOW);
    Serial.print(" (");
    Serial.print(value);
    Serial.println(")");
    delay(3000);
  }

   ////AHT10////
 
  Serial.print(F("Temperature: ")); 
  Serial.print(myAHT10.readTemperature(AHT10_FORCE_READ_DATA)); 
  Serial.println(F(" +-0.3C"));
  Serial.print(F("Humidity...: ")); 
  Serial.print(myAHT10.readHumidity(AHT10_USE_READ_DATA));      
  Serial.println(F(" +-2%"));

 

  readStatus = myAHT10.readRawData(); //read 6 bytes from AHT10 over I2C   
 
  delay(1000);
 
   
}

 
 
