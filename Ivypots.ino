
////Dht sensor/////
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

////Photo resistor/////
int Ledb = 8;

////Moisture sensor/////
const int AirValue = 100;   //you need to replace this value with Value_1
const int WaterValue = 618;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
 


// Fonction setup(), appelée au démarrage de la carte Arduino
void setup() {
  dht.begin();
  pinMode(Ledb, OUTPUT);
  Serial.begin(9600);
}

// Fonction loop(), appelée continuellement en boucle tant que la carte Arduino est alimentée
void loop() {
   
////Photo resistor////
  int valeur = analogRead(A0);
  
/////Dht sensor /////
  Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
  Serial.println("Humidite = " + String(dht.readHumidity())+" %");
  
  if (valeur<140){
  Serial.println("Sombre");
  digitalWrite(Ledb, HIGH);

  }
  if (valeur>300){
  Serial.println("éclairer");
  digitalWrite(Ledb, LOW);

  }

  
////Moisture sensor////
soilMoistureValue = analogRead(A1);  
 
Serial.println(soilMoistureValue);

soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

if(soilmoisturepercent >= 100)

{

  Serial.println("100 %");

}

else if(soilmoisturepercent <=0)

{

  Serial.println("0 %");

}

else if(soilmoisturepercent >0 && soilmoisturepercent < 100)

{

  Serial.print(soilmoisturepercent);

  Serial.println("%");
  
}
 
   
   
  
  delay(10000);
}
 
 
