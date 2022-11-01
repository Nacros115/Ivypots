# Ivypots
Ivypots is a solution for peoples who want to grow indoors vegetables, without worrying about How Often & How Much Watering Houseplants 
 . We use the Peltier Effect to generate water from the humidity to finally be able to use it for watering your plants. 
 Then we use our library to analyze the plants to determine how much and how often the plants need to be watered to give you the best possible.
 
 Ivypots is an autonomous pole garden ,it is made for all people that want to grow some plants without paying for an expensives tools.
 

 

 ![image](https://user-images.githubusercontent.com/78697892/199302853-c1866604-8642-41c2-a169-269769fa6435.png)



PROJECT DESCRIPTION
 

                                                           //Project under developpement.//


 
Introduction

Ivypots is a solution for people who want to grow indoors vegetables, without worrying about How Often & How Much Watering the Houseplants are.


 

Ivypots uses the Peltier Effect to generate water from the humidity to finally be able to water the plants. Thanks to the SD Card we can use the results to create a graph in Excel to analyze the plants to determine how much and how often the plants need to be watered to give the best possible experience.

To be able to produce water, you must already understand what a Peltier module is. The module Peltier is a component that can perform heat exchange without any moving parts. It is a semiconductor cooler which consists of a collection of legs composed of P or N-type semiconductor material.

peltier-cooling (1)
Module Peltier (effect Seebeck)
 A leg is constructed by creating several layers of substrate material, built up in order to have some height. 

Thermoelectric coolers operate according to the Peltier effect. The effect creates a temperature difference by transferring heat between two electrical junctions. 


Working principle of the Module Peltier
When the current flows through the junctions of the two conductors, heat is removed at one junction and cooling occurs. 

Depending on the direction of the current, when current is applied one side gets hot and the other gets cold. Thanks to this physical effect would be able in theory to produce water thanks to the condensation.

Note that, this is the same process as the so-called Dehumidifier.

Diy 120w Tec Peltier Semiconductor Refrigerator Water-cooling Air Condition  Movement For Refrigeration And Fan - Air Conditioner Parts - AliExpress
Dehumidifier using Peltier module

This has been proven, YouTubers have been able to use this effect to design a system called the atmospheric water generator. The system is composed of three parts: the Peltier module, a passive cooler, and a fan, so it can produce water. 

  For the device to be most effective a heat sink has to be mounted on the hot side for heat transfer, otherwise, the cooling effect will be minimized and it will not give proper results. 

Peltier Effect Cooling Experiments – Peltier Devices
Example of High temperature
Peltier died. Burn out? Condensation leakage? What could cause this? -  Electrical Engineering Stack Exchange
Burned Peltier module

Now let's see how the light detection works :
for the light detection, we will the KY-018 Photoresistor LDR module ideally it will be better to use a phototransistor because of its high accuracy but it will be more expensive than the project should be.

So how does it work? 
The KY-018 Photoresistor LDR module consists of a photoresistor (or Light Dependent Resistor - LDR) and a 10kΩ resistor. These two resistors create a voltage divider, as shown on the following image: 


Schematics of the KY-018 Photoresistor (Voltage divider)
The resistance of a photoresistor decreases in the presence of light and increase in the absence of it. The output is an analog voltage that is in the opposite relation to the intensity of light. 

A photoresistor is a resistor that can vary depending on the state of the light, it will change the value of the voltage applied to it. 

To understand a little better how it works, here is an example:

How Light Sensor Works
Operation of a photoresistor
We can see when there is light the value of the voltage is 5V but when there is no light the voltage is 0V.  

Now that we know this, we could use this mechanism to deploy LEDs to give light to plants.

 How can we reproduce the sunlight?
You may know that plants need light to be able to photosynthesize, but how can we do this?

First of all, plants need a certain spectrum of light especially ultraviolet radiation (260–380 nm) and the visible portion of the spectrum (380–740 nm) which includes PAR (400–700 nm), and far-red radiation (700–850 nm).

Grow Light Spectrum Explained: Ideal LED Spectrum for Plants
Spectrum of light
So knowing this we can use a certain type of led like the WL-SMDC Horticulture LEDs from Würth Elektronik :


WL-SMDC SMT Mono-color Ceramic LED Water clear
there are perfect because of their spectrum light.

 
/////////////////////////////Hardware//////////////////////////// 
 
WizFi360-EVB-Pico is based on Raspberry Pi RP2040 and adds Wi-Fi connectivity using WizFi360. It is pin compatible with the Raspberry Pi Pico board and can be used for IoT Solution development. Features, hardware specifications and documents  can be find here: https://docs.wiznet.io/Product/Open-Source-Hardware/wizfi360-evb-pico 
Getting Started with WizFi360-EVB-Pico – RP2040 and Wi-Fi Development Board  from WIZnet - CIRCUITSTATE Electronics
WizFi360-EVB-Pico
Here are the pinouts of the WizFi360-EVB-Pico :

WizFi360-EVB-Pico | WIZnet Document System
Pinouts  WizFi360-EVB-Pico 
 

 
 
 
 

/////////////////////////////Preparation:////////////////////////////
To use the WizFi360 Arduino library, the development environment must be configured to use the Arduino platform.

Please note that in this guide examples were configured and tested using Arduino IDE in a Windows environment.

Before starting, download and install the Arduino IDE from the link below.

Arduino IDE
Additionally, if you are using WizFi360-EVB-Pico, minor settings are required in the Arduino IDE.

WizFi360-EVB-Pico is a development board based on RP2040, and you need to add a package to use the development board based on RP2040.

① Run the Arduino IDE

② Open Preferences

You can open it through 'File → Preferences' in the menu bar of Arduino IDE.

③ Add next link to Additional Boards Manager URL

https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json

 

Add Boards Manager URLs 

/////////////////////////////Code :////////////////////////////

③ Then Navigate to My Github: https://github.com/Nacros115/Ivypots

④ Click "Code"

 


 
⑤ Click "Download ZIP"

 


⑥  Once that is done, open the zip files, search for Ivypots.ino and open it.

 


 

⑦  Connect your device and select the correct port or press the BOOTSELL Button while plugging your cable.


 
 

 

 

 

⑧ Finally, transfer the program to the Wizfi360-EVB-Pico.

 

⑨ If the program works you should see this  : 


Temperature/Humidity sensor

 Soil moisture sensor
 


The Circuit
 Here is an example of what you can do with this device :


Data logger Aht10 (Temperature/Humidity)
 
