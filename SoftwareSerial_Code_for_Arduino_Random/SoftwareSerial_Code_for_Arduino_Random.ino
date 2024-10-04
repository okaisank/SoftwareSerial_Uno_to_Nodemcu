//Code for Arduino:
#include "DHT.h"
#include <SoftwareSerial.h> //instead of parenthesis () put angle bracket as YouTube description does not allow angle bracket 
#define DHTPIN 2

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11 // DHT 11
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

SoftwareSerial espSerial(5, 6);//TX,RX 
DHT dht(DHTPIN, DHTTYPE);
String str;

int Temp;
int Humi; 

void setup(){
Serial.begin(115200);
espSerial.begin(115200);
dht.begin();
delay(2000);
}

void sendTemp(){
int Temp = random(0,100);
int Humi = random(0,100); 

delay(1000);
//  float h = dht.readHumidity();
//  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
//  if (isnan(h) || isnan(t)){ 
//  Serial.println("Read from DHT Sensor ");
//  return;
//  }
//  Serial.print("Temperature : "); 
//  Serial.println(Temp); 
//
//  Serial.print("Humidity : "); 
//  Serial.println(Humi); 
//  Serial.print("\n"); 
 
}
void loop()
{

int Temp = random(0,100);
int Humi = random(0,100);  
sendTemp();
  
//float h = dht.readHumidity();
// Read temperature as Celsius (the default)
//float t = dht.readTemperature();
//Serial.print("H: ");
//Serial.print(h); 
//Serial.print("% ");
//Serial.print(" T: ");
//Serial.print(t); 
//Serial.println("C");
//str =String("coming from arduino: ")+String("H= ")+String(h)+String("T= ")+String(t);
str =String("coming from arduino: ")+String("Humidity = ")+String(Humi)+String(" :  Temperature = ")+String(Temp);
espSerial.println(str);
delay(1000);
}
