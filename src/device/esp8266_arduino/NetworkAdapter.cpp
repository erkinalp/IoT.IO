#include "NetworkAdapter.h"
#include "SetupRunner.h"
#include "WiFiCore.h"
#include "Global.h"

void NETEvent(WiFiEvent_t event) 
{
  IPAddress myIP;
  switch(event) {
    case WIFI_EVENT_STAMODE_GOT_IP:
    
      /* Start WebSocket or MQTT comm in here !*/
      
      myIP = WiFi.localIP();
      Serial.printf("Trace   : WiFi connected. IP : %d.%d.%d.%d\n", myIP[0],myIP[1],myIP[2],myIP[3]);
      break;
    case WIFI_EVENT_STAMODE_DISCONNECTED:
      Serial.printf("Warning : WiFi lost connection!\n");
      break;
  }
}

void NETBegin()
{
  char ssidGathered[MAX_FILE_ATTR_LEN];
  char passGathered[MAX_FILE_ATTR_LEN];
  if(SETUPConfigCheck(ssidGathered, passGathered))
  {
    WiFiBegin(ssidGathered, passGathered, NETEvent);
  }
  else
  {
    SETUPConfigStart();
  }
}


