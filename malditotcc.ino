#include <LiquidCrystal.h>
#define LED_R 3
#define BUZZER 4
#define cOptica 5
#define LM35 A0
#define sLuz A1
#define limiteTemp 10
#define limiteLuz 800
#define CONTRASTE 9

LiquidCrystal lcd(12, 11, 10, 13, 8, 7);

void setup(){
  Serial.begin(9600);

  lcd.begin(16, 2);
  
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(CONTRASTE, OUTPUT);
  
  digitalWrite(LED_R, LOW);
  digitalWrite(BUZZER,LOW);
  lcd.clear();
}

int valorTemp = 0;
int valorFumaca = 0;
int valorLuz = 0;
float temperatura = 0;

void loop(){
  
  valorFumaca = digitalRead(cOptica);
  valorLuz = analogRead(sLuz);
  valorTemp = analogRead(LM35);
  
  temperatura = (valorTemp * 0.00488);
  temperatura = temperatura * 100;


if (temperatura >= limiteTemp){        
    acionado();  
   } else {
    desacionado();
   }
     
if (valorLuz >= limiteLuz){
      acionado();
   } else {
     desacionado();
   }

if (valorFumaca == 1){
    acionado();  
   } else {
    desacionado();
   } 

  Serial.print(temperatura);
  Serial.print("\t");
  Serial.print(valorFumaca);
  Serial.print("\t");
  Serial.println(valorLuz);

  analogWrite(CONTRASTE,100);
  lcd.setCursor(1, 0);
  lcd.print("Temp=");
  lcd.print(temperatura); 
  lcd.setCursor(1, 1);
  lcd.print("Luz=");
  lcd.print(valorLuz);
  lcd.setCursor(10, 1);
  lcd.print("CO=");
  lcd.print(valorFumaca);
  delay(80);
}


void acionado(){
  digitalWrite(LED_R, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay (150);
}


void desacionado(){
  digitalWrite(LED_R, LOW);
  digitalWrite(BUZZER, LOW);
}



