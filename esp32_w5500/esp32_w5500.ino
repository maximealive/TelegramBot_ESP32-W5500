#include <SPI.h>
#include <Ethernet.h>
#include <SSLClient.h>

#include <AsyncTelegram2.h>
#include <tg_certificate.h>

// write your bot token
const char* token =  "xxxxxxxxxxxx:xxxxxxxxxxxxxxxxxxxxxxx";

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 1, 1);

EthernetClient base_client;
SSLClient client(base_client, TAs, (size_t)TAs_NUM, A0, 1, SSLClient::SSL_ERROR );

AsyncTelegram2 myBot(client);
ReplyKeyboard myReplyKbd;   // reply keyboard object helper

#define RELAY_1   17
#define RELAY_2   16
#define RELAY_3   33
#define RELAY_4   25

// add or delete 'CHAT_ID_x' to give or restrict bot usage
// find chat id and replace the xxxxxxx; for example you can use @myidbot to find it/them
#define CHAT_ID_0   xxxxxxx
#define CHAT_ID_1   xxxxxxx
#define CHAT_ID_2   xxxxxxx

// variable to store
uint32_t chat_id;

void setup() {
  SPI.begin();
  // You can use Ethernet.init(pin) to configure the CS pin
  Ethernet.init(5);

  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);

  // Set the Telegram bot properies
  myBot.setUpdateTime(3000);
  myBot.setTelegramToken(token);

  // Check if all things are ok
  Serial.print("\nTest Telegram connection... ");
  myBot.begin() ? Serial.println("OK") : Serial.println("NOK");

  myReplyKbd.addButton("/relay1");
  myReplyKbd.addButton("/relay2");
  myReplyKbd.addRow();
  myReplyKbd.addButton("/relay3");
  myReplyKbd.addButton("/relay4");

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, LOW);
  digitalWrite(RELAY_3, LOW);
  digitalWrite(RELAY_4, LOW);
}

void loop() {
  // a variable to store telegram message data
  TBMessage msg;

  // if there is an incoming message...
  if (myBot.getNewMessage(msg)) {
    String msgText = msg.text;
    // store the id sender
    chat_id = msg.sender.id;

    if (chat_id == CHAT_ID_1 || chat_id == CHAT_ID_1 || chat_id == CHAT_ID_2) {
      if (msgText.equals("/relay1")) {
        digitalWrite(RELAY_1, HIGH);
        delay(500);
        digitalWrite(RELAY_1, LOW);
        myBot.sendMessage(msg, "Relay1");
      }
      else if (msgText.equals("/relay2")) {
        digitalWrite(RELAY_2, HIGH);
        delay(500);
        digitalWrite(RELAY_2, LOW);
        myBot.sendMessage(msg, "Relay2");
      }
      else if (msgText.equals("/relay3")) {
        digitalWrite(RELAY_3, HIGH);
        delay(500);
        digitalWrite(RELAY_3, LOW);
        delay(500);
        myBot.sendMessage(msg, "Relay3");
      }
      else if (msgText.equals("/relay4")) {
        digitalWrite(RELAY_4, HIGH);
        delay(500);
        digitalWrite(RELAY_4, LOW);
        myBot.sendMessage(msg, "Relay4");
      }
      else if (msgText.equals("/keyboard")) {
        myBot.sendMessage(msg, "Button keyboard activated", myReplyKbd);
      }
      else {
        // generate the message for the sender
        String reply;
        reply = "Welcome ";
        reply += msg.sender.username;
        reply += ".\nTry /relay1, /relay2,/relay3 or /relay4";
        reply += ".\nOppure /keyboard to activate the button keybord";
        myBot.sendMessage(msg, reply);
      }
    }
    else {
      myBot.sendMessage(msg, "Unauthorized access");
    }
  }
}
