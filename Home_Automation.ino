#include <ESP8266WiFi.h>
#include <ThingESP.h>?

ThingESP8266 thing("", "", "");  //Enter Username, Project Name, Project's device credentials

int LIGHT = D0;
int FAN = D1;
int LSWITCH = D2;
int FSWITCH = D3;
String result;
bool l = 1;
bool f = 1;

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(LSWITCH, INPUT);
  pinMode(FSWITCH, INPUT);
  thing.SetWiFi("", "");  //Enter Wifi Username,Password
  thing.initDevice();
}

//code for msgs from whatsapp
String HandleResponse(String Input) {
  int delimiterIndex = Input.indexOf(",");
  String code = Input.substring(0, delimiterIndex);
  String query = Input.substring(delimiterIndex + 1);
  if (code == "homaut") {     //modify the passcode if necessary
    if (query == "light on") {
      digitalWrite(LIGHT, 0);
      return "Done: Light Turned ON";
    }
    else if (query == "light off") {
      digitalWrite(LIGHT, 1);
      return "Done: Light Turned OFF";
    }

    else if (query == "fan on") {
      digitalWrite(FAN, 0);
      return "Done: Fan Turned ON";
    }

    else if (query == "fan off") {
      digitalWrite(FAN, 1);
      return "Done: Fan Turned OFF";
    }

    else if (query == "status") {
      result = digitalRead(LIGHT) ? "LIGHT is OFF" : "LIGHT is ON";
      result += digitalRead(FAN) ? "\nFAN is OFF" : "\nFAN is ON";
      return result;
    } else
      return "Invalid query";
  } else 
    return "Invalid passcode";
}

//code for controlling with switch
bool lswt(bool x) {
  if (x == 1) {
    digitalWrite(LIGHT, 0); //Switch on, so light on
  } else if (x == 0) {
    digitalWrite(LIGHT, 1); // Switch off, so light off
  }
  Serial.println("Made changes in light");
  return 1;
}

bool fswt(bool y) {
  if (y == 1) {
    digitalWrite(FAN, 0);  //Switch on, so fan on
  } 
  else if (y == 0) {
    digitalWrite(FAN, 1);  // Switch off, so fan off
  }
  Serial.println("Made changes in fan");
  return 1;
}

void loop() {
  thing.Handle();
  bool lstate = digitalRead(LSWITCH);
  bool fstate = digitalRead(FSWITCH);
  Serial.println("Light");
  Serial.println(lstate);
  Serial.println("Fan");
  Serial.println(fstate);
  Serial.println();

  while (lstate != l) //when light switch is not equal to previous state
  {
    lswt(lstate);
    l = lstate;
    Serial.println(l);
  }
  while (fstate != f) //when fan switch is not equal to previous state
  {
    fswt(fstate);
    f = fstate;
    Serial.println(f);
  }
  delay(5000);
}