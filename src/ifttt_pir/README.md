# ESP8266 To IFTTT Using Arduino IDE

The following instructions demostrates how to send the Notification to slack channel if the humidity is too high.  
Wemos creates a WiFi client and sends a URL request to IFTTT server to enable slack channel notification service.  

##IFTT Maker channel configuration

1. Create an IFTTT account.  
<img src=./../../img/create_ifttt_account.png width=600 />  
2. Enable Maker channel.  
 Now we are using this Maker channel which we can our own DIY project by simplying receiving or sending a web request.  
 <img src=./../../img/search_maker.png width=600 />  
 <img src=./../../img/maker_channel.png width=600 />  

3. Create our own IFTTT service.  
Go to My Applets -> New Applet.  
<img src=./../../img/new_applet.png width=500 />  
4. IF something happens  
<img src=./../../img/if_this.png width=500 />  
5. Then that...  
<img src=./../../img/then_that.png width=500 />  
<img src=./../../img/services.png/>  

##Send an url request from Wemos

1. Using the example code. And don't forget to change the WIFI credential part.  
```
const char *ssid     = "XXXX";
const char *password = "XXXX";
```
2. Change your own private key and customized triggered event name.  
```
const char *privateKey = "mGHBR8ACguChSfwY38WHLBj46ercITqKMlFhacszvOx";
```  
<img src=./../../img/private_key.png width=600 />  

```
send_event("wemos_demo");
```  
<img src=./../../img/triggered_event.png width=400 />

##PIR schematic  
```
Vdd = POWER SOURCE.
Vss = GROUND.
Vdl = GROUND.
VserialIn = Output SIGNAL.
```
<img src=./../../img/pir_schematic.png width=400 />
