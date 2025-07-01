#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <U8g2lib.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";
const char* serverUrl = "SERVER_ADDRESS";

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 22, 21);
const int buttonPin = 18;
const int laserPin = 23;  

void reconnectWiFi() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Próba ponownego połączenia z Wi-Fi...");
    WiFi.disconnect();
    WiFi.begin(ssid, password);
    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
      delay(500);
      Serial.print(".");
    }
    Serial.println();

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Połączono ponownie z Wi-Fi!");
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
    } else {
      Serial.println("Nie udało się ponownie połączyć z Wi-Fi");
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.sendBuffer();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW);  

  WiFi.begin(ssid, password);
  Serial.print("Łączenie z Wi-Fi");
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Połączono z Wi-Fi!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Nie udało się połączyć z Wi-Fi");
  }
}

void loop() {
  reconnectWiFi();

  bool buttonPressed = (digitalRead(buttonPin) == LOW);

  if (buttonPressed) {
    digitalWrite(laserPin, HIGH); 

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverUrl);
      int httpCode = http.GET();
      if (httpCode == 200) {
        String response = http.getString();
        Serial.println("Dystans: " + response);
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_ncenB14_tr);
        u8g2.setCursor(0, 40);
        u8g2.print(response);
        u8g2.print(" m");
        u8g2.sendBuffer();
      } else {
        Serial.println("Błąd HTTP: " + String(httpCode));
      }
      http.end();
    } else {
      Serial.println("Brak połączenia Wi-Fi");
    }
  } else {
    digitalWrite(laserPin, LOW); 

    
    u8g2.clearBuffer();
    int centerX = 64; 
    int centerY = 32; 
    u8g2.drawDisc(centerX, centerY, 2, U8G2_DRAW_ALL);  
    u8g2.sendBuffer();
  }

  delay(1000);  
}
