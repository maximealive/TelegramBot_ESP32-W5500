# Telegram Bot with ESP32 + W5500

## Hardware

ESP32-WROOM-32             |  W5500 shield             |5V 4-Channel Relay Module  |  Switching Power Supply 12V          |
:-------------------------:|:-------------------------:|:-------------------------:|:-------------------------:|
<img src="https://user-images.githubusercontent.com/12975980/149148822-50f93fa7-2737-4645-b8b0-bc0e2947304d.jpg" width="100" height="100" />  |  <img src="https://user-images.githubusercontent.com/12975980/149148979-3c30bb2f-e8ec-4d13-b4b2-b634d4bb84a3.jpg" width="100" height="100" />  |<img src="https://user-images.githubusercontent.com/12975980/149150298-bc503122-0125-4117-a21d-d7fe446f0cd4.jpg" width="100" height="100" />  | <img src="https://user-images.githubusercontent.com/12975980/149152089-c6aa75c3-c5a1-4eca-baa4-db32fc0b3315.jpg" width="100" height="100" />  |




## Connection

// mettere schema + foto originale

## Software
Windows 10
Arduino IDE 1.18.19

## Install library
<pre>
- AsyncTelegram2  v.2.0.4  (by Tolentino Cotesta) *
- ArduinoJson     v.6.15.2 (by Benoit Blanchon)
- SSLClient       v.1.6.11 (by OPenS Lab)
- Ethernet        v.2.0.0  (by Arduino)

// controllare le altre librerie
</pre>
## Install ESP32 Add-on in Arduino IDE **
To install the ESP32 board in your Arduino IDE, follow these next instructions:
- From Arduino IDE: __*File*__ -> __*Preferences*__
- In the Additional Boards Manager URLs add this link (if you have more than one link, separate them with a comma):
  https://dl.espressif.com/dl/package_esp32_index.json
- __*Tools*__ -> __*Board*__ -> __*Boards Manager…*__
- Search for ESP32 and press install button for the "ESP32 by Espressif Systems"

## Upload sketch
- Select your board from: __*Tools*__ ->__*Board:"xxxxx"*__ (I selected "ESP Dev Module")
- Check the upload speed from: __*Tools*__ -> __*Upload Speed*__, should be 921600
- Upload

## Notes

External power supply 5.0V-0.7A

To use relays I used specific pins because some of them are HIGH at boot ***

Be sure that when the upload finishes you can see something like this 

<img src="https://user-images.githubusercontent.com/12975980/149152743-3a9c4def-885b-451e-ae64-4ccf05d88690.png" width="200" height="150" />

## References
- https://github.com/cotestatnt/AsyncTelegram2 *
- https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/ **
- https://randomnerdtutorials.com/esp32-pinout-reference-gpios/ ***
