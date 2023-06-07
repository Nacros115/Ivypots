#define BLYNK_TEMPLATE_ID "TMPLx_bWw8Rh"
#define BLYNK_TEMPLATE_NAME "Ivypots"
#define BLYNK_AUTH_TOKEN "kPV_t8FGysQvF8stVPMp0UQpFDyGGX9h"
#define BLYNK_PRINT Serial

#include "DFRobot_EnvironmentalSensor.h"
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
#include <SoftwareSerial.h>
#endif
#define MODESWITCH        /*UART:*/0 /*I2C: 1*/
#if MODESWITCH
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
  SoftwareSerial mySerial(/*rx =*/4, /*tx =*/5);
  DFRobot_EnvironmentalSensor environment(/*addr =*/SEN050X_DEFAULT_DEVICE_ADDRESS, /*s =*/&mySerial);//Create an object for broadcast address, which can configure all devices on the bus in batches  
#else
  DFRobot_EnvironmentalSensor environment(/*addr =*/SEN050X_DEFAULT_DEVICE_ADDRESS, /*s =*/&Serial1); //Create an object for broadcast address, which can configure all devices on the bus in batches
#endif
#else
DFRobot_EnvironmentalSensor environment(/*addr = */SEN050X_DEFAULT_DEVICE_ADDRESS, /*pWire = */&Wire);
#endif

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SFR_1B80";
char pass[] = "dciz2qxg94rzgp5vbc85";

const int RelayPin = 2;


// Declaring a global variable for sensor data
int sensorData; 
int sensorData2; 
int sensorData3; 

// This function creates the timer object. It's part of Blynk library 
BlynkTimer timer; 

void myTimer() 
{
    
   Blynk.virtualWrite(V5, sensorData);
    
   Blynk.virtualWrite(V6, sensorData2);
    
   Blynk.virtualWrite(V7, sensorData3);

   Blynk.virtualWrite(V1, environment.getUltravioletIntensity());
    
   Blynk.virtualWrite(V2, environment.getTemperature(TEMP_C));
    
   Blynk.virtualWrite(V3, environment.getHumidity());

   Blynk.virtualWrite(V4, environment.getLuminousIntensity());
    
   Blynk.virtualWrite(V8, environment.getElevation());
    
    
   
}

void setup()
{
  //Connecting to Blynk Cloud.
  
  Blynk.begin(auth, ssid, pass); 
  
  // Setting interval to send data to Blynk Cloud to 1000ms. 
  // It means that data will be sent every second.
  
  timer.setInterval(1000L, myTimer); 
  
  Serial.begin(115200);
  
  Blynk.begin(auth, ssid, pass);
  
  pinMode(RelayPin, OUTPUT);  
  
  
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
  mySerial.begin(9600);
#elif defined(ESP32)
  Serial1.begin(9600, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
#else
  Serial1.begin(9600);
#endif
 
}
void loop() {
  Blynk.run();
  
  timer.run(); 
  
  sensorData2 = analogRead(A1); // this is an example of reading sensor data.
  
  sensorData3 = analogRead(A2); // this is an example of reading sensor data.

  sensorData = analogRead(A0); // this is an example of reading sensor data.

   

     /*if (currentLine.endsWith("/GET")) {
             //Read environmental data and print them on the web 
             client.print("Temp: "); client.print(environment.getTemperature(TEMP_C));client.println(" ℃");
             client.print("Humidity: "); client.print(environment.getHumidity());client.println(" %");
             client.print("Ultraviolet intensity: "); client.print(environment.getUltravioletIntensity());client.println(" mw/cm2");
             client.print("LuminousIntensity: "); client.print(environment.getLuminousIntensity());client.println(" lx");
             client.print("Atmospheric pressure: "); client.print(environment.getAtmospherePressure(HPA));client.println(" hpa");
             client.print("Elevation: "); client.print(environment.getElevation());client.println(" m");*/
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);  // will cause BLYNK_WRITE(V0) to be executed
}  

 BLYNK_WRITE(V0) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(RelayPin,HIGH);  // Set digital RelayPin to HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(RelayPin,LOW);  // Set digital RelayPin to LOW    
  }
}

 



 













 
