/*
 Fundacion Kinal
 Electronica
Grado: Quito perito
seccion: A
curso: taller de electronica
Nombre: Diego Alejandro Culajay Gonzalez
carnet: 2019485
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger A3
#define echo A2
int d;
int distancia;
//Constructor
LiquidCrystal_I2C LCD_DIEGO(direccion_lcd, columnas, filas);

//caracteres
byte bloque[] = {
  B11111,
  B11111,
  B11011,
  B11011,
  B11011,
  B11011,
  B11111,
  B11111
};
void setup()
{
  Serial.begin(9600);
  for(int i=2; i<=11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  LCD_DIEGO.init();
  LCD_DIEGO.backlight();
  LCD_DIEGO.createChar(1, bloque);
}


void loop()
{
  Serial.println(d);
  medicion();
   distancia = d;
  alerta();
}
int medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(50);
  return d;
}
void alerta(){
   if( distancia == 50){
    LCD_DIEGO.clear();
    LCD_DIEGO.setCursor(0,0);
    LCD_DIEGO.print("                ");
    LCD_DIEGO.setCursor(0,0);
    LCD_DIEGO.write(1);
    LCD_DIEGO.write(1);
    LCD_DIEGO.write(1);
    LCD_DIEGO.setCursor(7,0);
    LCD_DIEGO.print("50");
    LCD_DIEGO.setCursor(13,0);
    LCD_DIEGO.write(1);
    LCD_DIEGO.write(1);
    LCD_DIEGO.write(1);
    LCD_DIEGO.setCursor(5,1);
    LCD_DIEGO.print("LIBRE");
  }
  if( distancia == 30){
     LCD_DIEGO.clear();
     LCD_DIEGO.setCursor(0,0);
     LCD_DIEGO.print("                ");
     LCD_DIEGO.setCursor(0,0);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.setCursor(7,0);
     LCD_DIEGO.print("30");
     LCD_DIEGO.setCursor(11,0);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.setCursor(4,1);
     LCD_DIEGO.print("CUIDADO");
  }
  if( distancia == 10){
     LCD_DIEGO.clear();
     LCD_DIEGO.setCursor(0,0);
     LCD_DIEGO.print("                ");
     LCD_DIEGO.setCursor(0,0);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.setCursor(7,0);
     LCD_DIEGO.print("10");
     LCD_DIEGO.setCursor(9,0);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.write(1);
     LCD_DIEGO.setCursor(6,1);
     LCD_DIEGO.print("ALTO");
  }
  }
