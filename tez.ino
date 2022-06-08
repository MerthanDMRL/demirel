#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display;  
#include <DHT.h>
#define DHTPIN 3
#define Ldr A3
DHT dht(DHTPIN, DHT11);

int soilMoistureValue;
int Value;


void setup() {   
  Serial.begin(9600);
  delay(10);
  dht.begin();
  pinMode(7,OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();

pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}
void loop() {  
 
  soilMoistureValue = analogRead(A0);
  Value = map(soilMoistureValue, 610, 310, 0, 100);
  
      float h = dht.readHumidity();     
      float t = dht.readTemperature();
      int Ldr_deger = analogRead(Ldr);
             
                                         
                             Serial.print("Işık = "); 
                             Serial.println(Ldr_deger);                
                             Serial.print("Temperature: "); 
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.print("%. ");
                             Serial.print("Moisture: ");
                             Serial.print(Value);
                             Serial.println("%. ");
 
                            delay(1000);
 if (Value >30){
 digitalWrite(7,HIGH); 
 }
 else {digitalWrite(7,LOW); 
 }
 if (t < 26
 ){
 digitalWrite(12,HIGH);
 }
 else {digitalWrite(12,LOW);
 }
 if (Ldr_deger>330){
  digitalWrite(13,HIGH);
 }
 else {digitalWrite(13,LOW);
 }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Sicaklik:");
  display.setCursor(68,0);
  display.print(t);
  display.setCursor(102,0);
  display.print("C");
  display.setCursor(0,11);
  display.print("Hava nem:");
  display.setCursor(68,11);
  display.print(h);
  display.setCursor(102,11);
  display.print("%");
  display.setCursor(0,22);
  display.print("Toprak nem:");
  display.setCursor(68,22);
  display.print(Value);
  display.setCursor(102,22);
  display.print("%");
  
  display.display();
}
