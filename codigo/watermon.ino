#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

//Trabalho para feira de ciencias - Escola Maria Leticia
//Aluno : Gabriel Andrade
//Tema : Controle de cisterna de agua


//SENSOR NIVEL MAX - FIO VERDE
//SENSOR NIVEL MED - FIO MARROM
//SENSOR NIVEL MIN - FIO AZUL

#define sensor_max 9// input nivel max
#define sensor_med 10// input nivel med
#define sensor_min 13// input nivel min

#define led_max 6 // out nivel max
#define led_med 7 // out nivel med
#define led_min 8 // out nivel min
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int vs_max = 0, vs_med = 0, vs_min = 0;
 
void setup() {
  pinMode(led_max, OUTPUT);
  pinMode(led_med, OUTPUT);
  pinMode(led_min, OUTPUT);

  pinMode(sensor_max, INPUT);
  pinMode(sensor_med, INPUT);
  pinMode(sensor_min, INPUT);
  lcd.begin(16, 2);
  
  Serial.begin(9600);
}

void loop() {
   
  int vs_max = digitalRead(sensor_max);
  int vs_med = digitalRead(sensor_med);
  int vs_min = digitalRead(sensor_min);

  Serial.print("Valor Sensores >> s max : ");
  Serial.print(vs_max);
  Serial.print(" s med : ");
  Serial.print(vs_med); 
  Serial.print(" s min : ");
  Serial.print(vs_min);
  Serial.println("");

  if ((vs_max == 0) && (vs_med == 0) && (vs_min == 0))
  {
     digitalWrite(led_min,HIGH);
     delay (100);
      digitalWrite(led_min,LOW);
      delay (100);
     digitalWrite(led_med,LOW);
     digitalWrite(led_max,LOW);
      lcd.clear();
  lcd.setCursor(3, 0); 
  lcd.print("nivel");
  lcd.setCursor(3, 1);
  lcd.print("critico");
 
  }
  
  if ((vs_max == 0) && (vs_med == 0) && (vs_min == 1))
  {
    digitalWrite(led_min,HIGH);
     digitalWrite(led_med,LOW);
     digitalWrite(led_max,LOW);
     lcd.clear();
  lcd.setCursor(3, 0); 
  lcd.print("nivel");
  lcd.setCursor(3, 1);
  lcd.print("baixo");
      
  }
  
  if ((vs_max == 0) && (vs_med == 1) && (vs_min == 1))
  {
     digitalWrite(led_min,LOW);
     digitalWrite(led_med,HIGH);
     digitalWrite(led_max,LOW);
    lcd.clear();
  lcd.setCursor(3, 0); 
  lcd.print("nivel");
  lcd.setCursor(3, 1);
  lcd.print("mediano");
  }

   if ((vs_max == 1) && (vs_med == 1) && (vs_min == 1))
  {
     digitalWrite(led_min,LOW);
     digitalWrite(led_med,LOW);
     digitalWrite(led_max,HIGH);
      lcd.clear();
  lcd.setCursor(3, 0); 
  lcd.print("nivel");
  lcd.setCursor(3, 1);
  lcd.print("maximo");
  }

}
 
