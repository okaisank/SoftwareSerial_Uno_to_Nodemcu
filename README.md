## ติดตั้งไดร์เวอร์ CP210x 
https://drive.google.com/file/d/1gpVwB4QQ8wsG-S7WcqFHgHZgZnBadNv9/view

# Code for Arduino:
#include "DHT.h"
#include (SoftwareSerial.h) //instead of parenthesis () put angle bracket as YouTube description does not allow angle bracket 
#define DHTPIN 2

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11 // DHT 11
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

SoftwareSerial espSerial(5, 6);
DHT dht(DHTPIN, DHTTYPE);
String str;

void setup(){
Serial.begin(115200);
espSerial.begin(115200);
dht.begin();
delay(2000);
}
void loop()
{
float h = dht.readHumidity();
// Read temperature as Celsius (the default)
float t = dht.readTemperature();
Serial.print("H: ");
Serial.print(h); 
Serial.print("% ");
Serial.print(" T: ");
Serial.print(t); 
Serial.println("C");
str =String("coming from arduino: ")+String("H= ")+String(h)+String("T= ")+String(t);
espSerial.println(str);
delay(1000);
}


# Code for ESP8266:
void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
}

void loop() { // run over and over
if (Serial.available()) {
Serial.write(Serial.read());
}
}
