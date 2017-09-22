#define DEBUG

// Functions prototypes
String getUptime();

// Setup TypeDefs
typedef struct { // Sensor Data
    uint16_t      temperature;
    uint16_t      windspeed_mps;
    uint16_t      windspeed_kph;
    uint8_t       winddirection;
    unsigned long looptime;
    uint32_t      ChipId;
    uint32_t      FlashChipId;
} SENSORDATA;
SENSORDATA sensorData;

char* windDirectionArray[17] = {"x", "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

#include <ArduinoJson.h>
#include "spiffs.h"
#include "esp_wifi.h"
#include "esp_timefunctions.h"
#include "esp_chipid.h"
#include "esp_systemdiag.h"

ADC_MODE(ADC_VCC);

//--------------------------------------------------------------------------------------------
// Convert MAC address to String
//--------------------------------------------------------------------------------------------
String macToStr(const uint8_t* mac) {
  
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}

String displayIP(IPAddress address) {
 return String(address[0]) + "." + 
        String(address[1]) + "." + 
        String(address[2]) + "." + 
        String(address[3]);
}
