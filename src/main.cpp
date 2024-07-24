

long currenttime = 0;

int booster_pin = 4;
int starlink_pin = 0; 

int booster_state = 0;
int starlink_state = 0;

#include <jled.h>
// breathe LED for 5 times, LED is connected to pin 9 (PWM capable) gpio
auto led_on = JLed(LED_BUILTIN).Breathe(3000).Forever();
auto led_off = JLed(LED_BUILTIN).LowActive().Off();

#include <ESP8266WiFi.h>
#include "network.h"
#include "RemoteXY_functions.h"
#include "RemoteXY_callbacks.h"
#include <Arduino.h>
#include <ArduinoOTA.h>
#include "OTA.h"




void setup()
{
  // Debug console
  Serial.begin(115200);
  led_off.Update();

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(booster_pin, OUTPUT);
  pinMode(starlink_pin, OUTPUT);
  digitalWrite(booster_pin, LOW);
  digitalWrite(starlink_pin, LOW);

  ConnectWifi();

  OTA_Functions();

}



void loop()
{;
  manageBlynkConnection2();
  led_on.Update();
  ArduinoOTA.handle();
  currenttime = millis();

  // get all data from api at regular interval
  // assign to pertinent variables
  // update pins with variable values
  get_all_data();

  // send feedback states to api at regular interval
  send_feedback();
}


