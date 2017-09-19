# iot-workshop
## Walkthrough for the IoT Prototyping 101 Workshop

When using a new computer, there's a few things to prepare beforehand. Please go through these instructions and in case something doesn't work out, reach out to us beforehand

There's 4 things you'll need to do:
* Install the driver to connect to the Wemos
* Install & configure the Arduino app
* Sign-up for the Blynk mobile app
* Test it (*we'll provide the hardware for this*)!


## Step 1 — Install the USB-to-serial driver to connect to the Wemos

Head on [here](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) and download the driver for your operating system. Go through the installation process (**you'll need root rights for this**).

## Step 2 — Install & Configure the Arduino app

1. Go to [Arduino](http://arduino.cc/en/Main/Software) and download the Arduino IDE for your OS.

2. Run the installer & start the app

3. Go to *File* (or on Mac *Arduino*)* -> Preferences -> Additional Boards Manager* and paste the link below into it:

    `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
![Board manager link](https://cdn.sparkfun.com/assets/learn_tutorials/3/6/5/arduino-board-manager-link.png)
4. Go to *Tools -> Board: "Arduino..." -> Board Managers* and Install *esp8266 by ESP8266 Community*

    ![Board manager link](https://cdn.sparkfun.com/assets/learn_tutorials/3/6/5/arduino-board-install.png)
    
#### Required Libraries

    
5. Download the [Blynk Arduino Library](https://github.com/blynkkk/blynk-library/archive/master.zip).

5. For the  DHT11 + DHT22 sensor: download the [Adafruit unified sensor](https://github.com/adafruit/Adafruit_Sensor/archive/master.zip) library. 

6. Download the [SimpleTimer library](https://github.com/jfturcot/SimpleTimer/archive/master.zip)

6. In the Arduino App, go to Sketch > Include Library > Add .ZIP Library ![screenshot](img/ziplib.png)

7. Navigate to your Downloads folder and choose one of the .zip files you've downloaded.

8. Repeat the last two steps for the other libraries.

    **Testing**: 

5. From *Tools -> Board: "Arduino..." ->* select the *WeMos D1 R2 & Mini*

6. Connect the WeMos to your PC and under *Tools -> Port* select *dev/cu.SLAB_USBtoUART*

7. Go to Examples > ESP8266 > Blink.

8. Click the Upload button and wait for it. If all goes well, you should have a blinking blue LED on your Wemos.


## Step 3 - Download the Blynk App & Sign Up

1. Go to your phone's App Store and download the Blynk App _or click one of the links — [iOS](https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8) / [Android](https://play.google.com/store/apps/details?id=cc.blynk)._

2. Sign up for an account.

## That's it! Awesome! You're done. Have fun hacking.

