/*---------------------KRENOVATOR---------------------
  LED & BLYNKK & Google Assistant

  Demonstrates to aware of the distance using the
  ultrasonic sensor which can measure a distance 
  in centimeter where the LED is responded when
  the threshold is reached

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

void setup(){
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
}
