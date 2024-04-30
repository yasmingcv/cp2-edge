#include "LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);
int sensorPin = 1;

int sensorValue = 0; //inicia o valor do potenciometro
int analogPin = 2; // porta do potenciometro

 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop()
{
 
 int umidade = analogRead(analogPin); //le o valor do potenciometro
int readingTemperature = analogRead(sensorPin);
 // measure the 5v with a meter for an accurate value
 //In particular if your Arduino is USB powered
 float voltagem = readingTemperature * 4.68;
 voltagem /= 1024.0;
 
 // now print out the temperature

 float temperatura = (voltagem - 0.5) * 100;
  
  if(temperatura >= 10 && temperatura <= 15){
  lcd.setCursor(0,0);
    lcd.print("Temperatura OK");
  }
  else if (temperatura > 15){
    lcd.setCursor(0,0);
    lcd.print("Temp. ALTA");
  }
  else {
   lcd.setCursor(0,0);
   lcd.print("Temp. BAIXA"); 
  }
  
  lcd.setCursor(0,1);
  lcd.print("Temp. =");
  lcd.setCursor(9,1);
  lcd.print(temperatura);
  delay(1000);
  lcd.clear();
  
  //Luminosidade
  int LDR = analogRead(A0);
  
  if(LDR <= 300){
    lcd.setCursor(0,0);
    lcd.print("Luz Ambiente OK");
  } else if(LDR > 300 && LDR <= 500){
    lcd.setCursor(0,0);
    lcd.print("Ambiente a meia");
    lcd.setCursor(0,1);
    lcd.print("luz");
  } else{
    lcd.setCursor(0,0);
    lcd.print("Ambiente muito");
    lcd.setCursor(0,1);
    lcd.print("CLARO");
  }
  
  delay(1000);
  lcd.clear();
  //Sensor de Umidade
  //usa o valor do potenciometro e aplica a coondicao
  if(umidade <= 500){
    lcd.setCursor(0,0);
    lcd.print("Umidade BAIXA");
    lcd.setCursor(0,1);
    lcd.print("Umidade = ");
    lcd.setCursor(11, 1);
    lcd.print(umidade/10);
    lcd.setCursor(12, 1);
    lcd.print("%");
  }else if (umidade > 500 && umidade <= 700){
    lcd.setCursor(0,0);
    lcd.print("Umidade OK");
    lcd.setCursor(0,1);
    lcd.print("Umidade = ");
    lcd.setCursor(11, 1);
    lcd.print(umidade/10);
    lcd.setCursor(13, 1);
    lcd.print("%");
  }
  else {
   lcd.setCursor(0,0);
   lcd.print("Umidade ALTA");
    lcd.setCursor(0,1);
    lcd.print("Umidade = ");
    lcd.setCursor(11, 1);
    lcd.print(umidade/10);
    lcd.setCursor(13, 1);
    lcd.print("%");
  }
  
  delay(2000);
  lcd.clear();
  
}
