# Telegram Bot with ESP32 + W5500

## Hardware
ESP32-WROOM-32

// mettere immagine

W5500 shield

// mettere immagine

5V 4-Channel Relay Module

// mettere immagine

Switching Power Supply 12V // scrivere valore ampere

// mettere immagine

External power supply 5.0V-0.7A

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
To use relays I used specific pins because some of them are HIGH at boot ***

Be sure that when the upload finishes you see this 

// mettere immagine

## References
- https://github.com/cotestatnt/AsyncTelegram2 *
- https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/ **
- https://randomnerdtutorials.com/esp32-pinout-reference-gpios/ ***
