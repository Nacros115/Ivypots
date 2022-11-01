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


  File :       Ivypots.ino
  
  Description :   This program allows you to control your plants and create water from a Peltier module 
  but also to measure temperature and hygrometry with a DHT11, 
  and to store these informations on an SD card, in a file in CVS. format (importable in Excel)
  
 Please note that some elements are missing like the NFC for the app, and the link between the app and the pots it's because this project is still under development.
 
  Author : Nayel Khouatra
  Created on : 28.10.2022

*/

#include <SD.h>
 

// Variables used for the SD card
// The SD card reader will be connected to pin 10 for the CS (chip select), 11/12/13 for the MOSI/MISO/SCK of the SPI bus
const char* nomDuFichier = "donnees.csv";     // Format 8.3 (i.e. 8 letters maximum for the name, and optionally 3 for the extension)
File monFichier;

 
 

// Other variables
const long delaiIntervalleDeMesures = 2000;             // Measurement/recording interval (expressed in milliseconds)
                                                        // Note: do not go below 2 seconds, because the DHT22 cannot go that fast

 

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
int RELAY_PIN = 4;
 
// ========================
// Initialisation programme
// ========================


void setup() {
  Serial.begin(115200);
  while(not Serial) delay(10);
  SPI1.setRX(12);
  SPI1.setCS(13);
  SPI1.setSCK(10);
  SPI1.setTX(11);
  Serial.println(F("DATALOGGER program (t°/hygro recording from an AHT10 and a moist and luminosity sensor, and storage of data on SD card"));
  Serial.println(F("==================================================================================================="));
  Serial.println();

  // ----------------------------------------------------------------------------
  // Check: is the SD card accessible from the arduino?
  // ----------------------------------------------------------------------------
  Serial.print(F("Initialisation de la carte SD..."));
  if (!SD.begin(13, SPI1)) {
    Serial.println();
    Serial.println();
    Serial.println(F("SD card reader initialization failed. Check:"));
    Serial.println(F("1. that the SD card is properly inserted"));
    Serial.println(F("2. that your wiring is good"));
    Serial.println(F("3. that the variable 'SD.begin ' corresponds to the pin CS of your SD card on the Arduino"));
    Serial.println(F("And press the RESET button on your Arduino once the problem is solved, to restart the program!"));
    while (true);
  }
  Serial.println(F(" successful!"));
  Serial.println();

  // ----------------------------------------------------------------------------
  // Initialisation du DHT22
  // ----------------------------------------------------------------------------
  
}
   
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
    Serial.println(F("AHT10 not connected")); //(F()) save string to flash & keeps dynamic memory free
      
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
    Serial.println ("The lamp will be turned on");
     
    Serial.println (LDRvalue);
  
  }
  while(LDRvalue< 768){
  
    digitalWrite (Luminar, LOW);
    Serial.println ("The lamp will be turned off");
     
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
     
  } else if (value < Wet){
    Serial.print("The soil is WET => turn pump OFF");
    digitalWrite(RELAY_PIN, LOW);
    Serial.print(" (");
    Serial.print(value);
    Serial.println(")");
     
  }



 
  // Vérification si données bien reçues
 
 

  readStatus = myAHT10.readRawData(); //read 6 bytes from AHT10 over I2C   

 
  int tauxHumidite = myAHT10.readHumidity(AHT10_USE_READ_DATA);        // Reading of the moisture content, expressed in %.
  int temperature = myAHT10.readTemperature(AHT10_FORCE_READ_DATA);   // Reading of the room temperature, expressed in degrees Celsius
  if (isnan(tauxHumidite) || isnan(temperature)) {
    Serial.println(F("No value returned by the AHT10. Is it properly connected?"));
     
    return;         // If no value has been received by the Arduino, we wait 2 seconds, then we restart the loop() function
  }

  // Formatting of this data (one digit after the decimal point)
  
  String tauxHumiditeArrondi = String(tauxHumidite,1);     
  String temperatureArrondie = String(temperature,1);      
  tauxHumiditeArrondi.replace(".", ",");                   
  temperatureArrondie.replace(".", ",");             
        
  // Display values on the Arduino IDE serial monitor
  
  Serial.print("Humidité =  +-2%"); Serial.print(tauxHumiditeArrondi); Serial.print(" % - ");
  Serial.print("Température = +-0.3"); Serial.print(temperatureArrondie); Serial.println(" °C");

  // Enregistrement de ces données sur la carte SD
  monFichier = SD.open(nomDuFichier, FILE_WRITE);
  if (monFichier) {    
    monFichier.print(tauxHumiditeArrondi);
    monFichier.print(";");                   
    monFichier.println(temperatureArrondie);  
    monFichier.print(";"); 
    monFichier.println(value);                    
    monFichier.print(";"); 
    monFichier.println(LDRvalue);  
    monFichier.close();                     
    Serial.println(F("Successful recording to SD card"));
  }
  else {
    Serial.println(F("Error when trying to open the file in writing, on the SD card"));
  }

  // X seconds delay (2 sec min, so that the sensors have time to make their measurements)
  Serial.println();
  delay(delaiIntervalleDeMesures);
}
