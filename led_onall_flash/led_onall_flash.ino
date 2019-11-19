/*---------------------KRENOVATOR---------------------
  LED & BLYNKK & Google Assistant

  The codes is for Blynk apps on controls the LEDs.
  The user may control all of the LEDs at the same
  time. Either to turn it OFF at the same time or
  vice versa. Add on as a targetted LED to act as a
  blinking LED.

  Get the code at github
  https://github.com/MZulsyahmi/Smart-Voice-Assistant.git
  
  by M.Zulsyahmi @krenovator
  September 2018
 */


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your Auth Token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your SSID";
char pass[] = "SSID Password";

//initialize the pin to be used
int green = D6;
int yellow = D7;
int red = D8;

//the blynk virtual pin
//Turn ON/OFF all lights
BLYNK_WRITE(V1) {
  int pinV1 = param.asInt();
  if(param.asInt()){
    digitalWrite(green, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
  }
  else{
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
}

//Turn ON/OFF flash
BLYNK_WRITE(V2){
  int pinV2 = param.asInt();
  if(pinV2 == 1){
    on_flash();
    Blynk.syncVirtual(V2);
  }
}

//Turn ON/OFF 1 light for Virtual Pin 3
BLYNK_WRITE(V3){
  int pinV3 = param.asInt();
  if(pinV3 == 1){
    digitalWrite(red, HIGH);
  }
  else{
    digitalWrite(red, LOW);
  }
}

void on_flash(){
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
}

void setup(){
  // Debug console
  Serial.begin(9600);

  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
}
