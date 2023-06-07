# Ivypots
Ivypots is a solution for peoples who want to grow indoors vegetables, without worrying about How Often & How Much Watering Houseplants. 
We use the Peltier Effect to generate water from the humidity to finally be able to use it for watering your plants. 
 Then we use our library to analyze the plants to determine how much and how often the plants need to be watered to give you the best possible.
 
 Ivypots is an autonomous pole garden ,it is made for all people that want to grow some plants without paying for an expensives tools.
 

 

   ![image](https://user-images.githubusercontent.com/78697892/199302853-c1866604-8642-41c2-a169-269769fa6435.png)



PROJECT DESCRIPTION
 

                                                           //Project under developpement.//


 
Introduction

Ivypots is a solution for people who want to grow indoors vegetables, without worrying about How Often & How Much Watering the Houseplants are.
 

Ivypots uses the Peltier Effect to generate water from the humidity to finally be able to water the plants. Thanks to the SD Card we can use the results to 
create a graph in Excel to analyze the plants to determine how much and how often the plants need to be watered to give the best possible experience.
 

 

/////////////////////////////Preparation:////////////////////////////

All the schematics can be found on my GitHub page
Please note that in this guide examples were configured and tested using Arduino IDE in a Windows environment.
Before starting, download and install the Arduino IDE from the link below.

    Arduino IDE

Or if you want to use the Cloud :

    Arduino Cloud
    Blynk cloud  (if you want to use your phone)

Additionally, if you are using the Firebeetle esp32-E, minor settings are required in the Arduino IDE.
The new ESP32-E  FireBeetle supports WiFi and Bluetooth dual-mode communication, has  ultra low power consumption and even includes an on-board charging  circuit so you can power it with a lipo battery (and charge it over  USB-C).

① Run the Arduino IDE

② Open Preferences

You can open it through 'File → Preferences' in the menu bar of Arduino IDE.

③ Add next link to Additional Boards Manager URL
 
 https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json


Add Boards Manager URLs 

/////////////////////////////Code :////////////////////////////

③ Then Navigate to My Github: https://github.com/Nacros115/Ivypots
                     ![image](https://user-images.githubusercontent.com/78697892/199303451-9f493409-f632-4aeb-8a3f-eae19551ba68.png)
                     

④ Click "Code"
                     ![image](https://user-images.githubusercontent.com/78697892/199303423-8d83b9c4-da9d-4f0b-8a22-686a840e555a.png)
 


 
⑤ Click "Download ZIP"
                     

  ![image](https://user-images.githubusercontent.com/78697892/199303405-223761f4-68a4-4235-8ed5-4ad64ba51177.png)



⑥  Once that is done, open the zip files, search for Ivypots.ino and open it.

   ![image](https://user-images.githubusercontent.com/78697892/199303381-c169a192-5064-4937-92df-b2894bfc0f36.png)


 
⑦ Finally, transfer the program to the Fire beetle ESP32-E.

 

 
