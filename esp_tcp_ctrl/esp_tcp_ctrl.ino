
#include "esp_wifi_update.h"

void setup()
{
  setup_init();
  read_eeprom();
  wifi_start();
}
char ch_data;
void loop() {
  if ((WiFi.status() == WL_CONNECTED))
  {
    WiFiClient client = check_wifi_server_available();
  
    if (client) 
    {
      if (client.connected())
      {
        Serial.println("Client connected");
      }
      else
      {
        Serial.println("Client NOT connected");
      }
    }
    else
    {
      client.stop();
      Serial.println("Client disconnected");
    }
  
    while(client.connected())
    {
      while(client.available()>0)
      {
        //read data from the connected client
        ch_data = client.read();

        if(ch_data == '-')
        {
          Serial.write(client_data.c_str());
          Serial.println("");
          if (strncmp(client_data.c_str(), led_ac, strlen(led_ac)) == 0)
          {
            Serial.println("CMD: AC");
            digitalWrite(LED_BUILTIN, LOW);
          }
          else if (strncmp(client_data.c_str(), led_kapa, strlen(led_kapa)) == 0)
          {
            Serial.println("CMD: KAPAT");
            digitalWrite(LED_BUILTIN, HIGH);
          }
          else
          {
            Serial.println("CMD: UNKNOWN");
          }
          client_data = "";
        }
        else if ((ch_data != '\r') && (ch_data != '\n'))
        {
          client_data += ch_data;
        }
      }
      //Send data to connected client
      while(Serial.available()>0)
      {
        client.write(Serial.read());
      }
    }
    delay(1000);
  }
  else
  {
    Serial.println("Wifi NOT connected");
    delay(1000);
  }

}
