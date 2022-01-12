# Telegram Bot with ESP32 + W5500

## Hardware
ESP32

// mettere immagine

W5500 shield

// mettere immagine

## Install library
<pre>
- AsyncTelegram2 v.2.0.4 (cotestatn)
- ArduinoJson    v.6.15.2 (vedere nomi)
- SSLClient      v.1.6.11
__*Arduino IDE*__


// controllare le altre librerie
</pre>
## Install ESP32 Add-on in Arduino IDE
To install the ESP32 board in your Arduino IDE, follow these next instructions:
- From Arduino IDE: __*File*__ -> __*Preferences*__
- In the Additional Boards Manager URLs add this link (if you have more than one link, separate them with a comma):
  https://dl.espressif.com/dl/package_esp32_index.json
- __*Tools*__ -> __*Board*__ -> __*Boards Manager…*__
- Search for ESP32 and press install button for the "ESP32 by Espressif Systems"
- Select your board from: __*Tools*__ ->__*Board:"xxxxx"*__ (I selected "ESP Dev Module")
  
https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
