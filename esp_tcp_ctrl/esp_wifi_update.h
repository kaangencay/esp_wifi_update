#ifndef MY_LIB_H
#define MY_LIB_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <string.h>

#define WIFI_SERVER_PORT 8888
#define WEB_SERVER_PORT 80

void setup_init(void);
void read_eeprom(void);
void wifi_start(void);

//Function Decalration
bool testWifi(void);
void launchWeb(void);
void setupAP(void);
void createWebServer(void);
WiFiClient check_wifi_server_available(void);

//Variables
extern int i;
extern int statusCode;
extern String esid;
extern String epass;
extern String st;
extern String content;
extern String client_data;
extern const char *led_ac;
extern const char *led_kapa;

#endif //MY_LIB_H