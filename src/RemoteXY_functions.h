
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>



String mainURL ="http://192.168.8.148";
JsonDocument doc;


long get_data_timer = 0;
long get_data_interval = 250; // ms

long send_data_timer = 0;
long send_data_interval = 500; // ms


// convert float to char array
String floatToCharArray(float val, int decimal_places=3) {
  char temp[32];
  dtostrf(val, 0, decimal_places, temp);
  return String(temp);
}



void set_value(String key, String value) {
  WiFiClient client;
  HTTPClient http;

  // Serial.print("[HTTP] begin...");

  if (http.begin(client, mainURL + "/set_value/" + key + "/" + value)) {  // HTTP
    // Serial.print("[HTTP] GET...");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      // Serial.printf("[HTTP] GET code: %d", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        // deserializeJson(doc, payload);
        // Serial.println(payload);
      }
    } else {
      // Serial.printf("[HTTP] GET failed, error: %s", http.errorToString(httpCode).c_str());
    }

    http.end();
  } else {
    // Serial.printf("[HTTP} Unable to connect");
  }
}


void get_all_data() {
  if ((currenttime - get_data_timer) < get_data_interval) {
    return;
  }
  get_data_timer = currenttime;

  WiFiClient client;
  HTTPClient http;

  // Serial.print("[HTTP] begin...");

  if (http.begin(client, mainURL + "/get_all")) {  // HTTP
    // Serial.print("[HTTP] GET...");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET code: %d", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        deserializeJson(doc, payload);

        booster_state = doc["booster_power"];
        starlink_state = doc["starlink_power"];

        if (booster_state == 1) {
          digitalWrite(booster_pin, HIGH);
        } else {
          digitalWrite(booster_pin, LOW);
        }

        if (starlink_state == 1) {
          digitalWrite(starlink_pin, HIGH);
        } else {
          digitalWrite(starlink_pin, LOW);
        }

      }
    } else {
      Serial.printf("[HTTP] GET failed, error: %s", http.errorToString(httpCode).c_str());
    }

    http.end();
  } else {
    Serial.printf("[HTTP} Unable to connect");
  }
}


void send_feedback() {
  if ((currenttime - send_data_timer) < send_data_interval) {
    return;
  }
  send_data_timer = currenttime;

  set_value("booster_power_feedback", digitalRead(booster_pin) ? "1" : "0");
  set_value("starlink_power_feedback", digitalRead(starlink_pin) ? "1" : "0");
}




