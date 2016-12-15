# Blynk with DHT sensor on Wemos

##Requirements

####The required libraries
* Blynk library: https://github.com/blynkkk/blynk-library

* DHT22 sensor: Adafruit unified sensor by Adafruit.  
(Install by ```Sketch->Include Library->Manage Libraries->adafruit unified sensor```)

* Simple Timer: https://github.com/schinken/SimpleTimer
##### Here's how to install them:

1. The In the Arduino app go to Sketch -> Include Library -> Library Manager and search for ‘dht’. Install the first one that shows up; by Adafruit.
2. The SimpleTimer - This time download https://github.com/jfturcot/SimpleTimer/archive/master.zip and then go to Sketch -> Include Library -> Add .ZIP Library and choose the file you’ve just downloaded.
3. Follow Step 1 again but this time search for ‘Adafruit Unified Sensor’. It should be the last one on the list. If you can’t find it, go to https://github.com/adafruit/Adafruit_Sensor/archive/master.zip and do the same thing you did in Step 2.


##Getting Started With The Blynk App

Please refer this: http://docs.blynk.cc/

##Schematic
<img src=./../../img/dht_wemos.png width=300 /> 

##DHT22 sensor:

Datasheet:
This is [datasheet](https://cdn-shop.adafruit.com/datasheets/DHT22.pdf "DHT22 Sensor").
