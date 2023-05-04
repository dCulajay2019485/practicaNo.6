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

#define bar1 2
#define bar2 3
#define bar3 4
#define bar4 5
#define bar5 6
#define bar6 7
#define bar7 8
#define bar8 9
#define bar9 10
#define bar10 11
#define Buzzer 12
#define trig A3
#define echo A2
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
int nota_mi = 329;

LiquidCrystal_I2C LCDDIEGO(0x27, 16, 2); //LCD con dirección 0x20 y tamaño 16x2

void setup() {
  pinMode(bar1, OUTPUT);
  pinMode(bar2, OUTPUT);
  pinMode(bar3, OUTPUT);
  pinMode(bar4, OUTPUT);
  pinMode(bar5, OUTPUT);
  pinMode(bar6, OUTPUT);
  pinMode(bar7, OUTPUT);
  pinMode(bar8, OUTPUT);
  pinMode(bar9, OUTPUT);
  pinMode(bar10, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  LCDDIEGO.init();
  LCDDIEGO.backlight();
}

void loop() {
  long duracion, distancia;
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 59;

  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia >= 45) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Fuera de Rango");
    turnOffAllBars();
  } else if (distancia > 40 && distancia <= 45) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Objeto detectado");
    turnOnBar(1);
  } else if (distancia > 35 && distancia <= 40) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Objeto detectado");
    turnOnBar(1);
    turnOnBar(2);
  } else if (distancia > 30 && distancia <= 35) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Objeto detectado");
    turnOnBar(1);
    turnOnBar(2);
    turnOnBar(3);
  } else if (distancia > 25 && distancia <= 30) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Cuidado");
    LCDDIEGO.setCursor(0, 1);
    LCDDIEGO.print("Espacio privado");
    turnOnBar(1);
    turnOnBar(2);
    turnOnBar(3);
    turnOnBar(4);
    playTone(nota_mi, 326);
  } else if (distancia > 20 && distancia <= 25) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Cuidado");
    LCDDIEGO.setCursor(0, 1);
    LCDDIEGO.print("
Espacio privado");
    turnOnBar(1);
    turnOnBar(2);
    turnOnBar(3);
    turnOnBar(4);
    turnOnBar(5);
    playTone(nota_mi, 326);
  } else if (distancia > 15 && distancia <= 20) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Cuidado");
    LCDDIEGO.setCursor(0, 1);
    LCDDIEGO.print("Espacio privado");
    turnOnBar(1);
    turnOnBar(2);
    turnOnBar(3);
    turnOnBar(4);
    turnOnBar(5);
    turnOnBar(6);
    playTone(nota_mi, 326);
  } else if (distancia > 10 && distancia <= 15) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Invadiendo");
    LCDDIEGO.setCursor(0, 1);
    LCDDIEGO.print("Espacio privado");
    turnOnBar(1);
    turnOnBar(2);
    turnOnBar(3);
    turnOnBar(4);
    turnOnBar(5);
    turnOnBar(6);
    turnOnBar(7);
    playTone(nota_mi, 326);
  } else if (distancia > 5 && distancia <= 10) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Invadiendo");
    LCDDIEGO.setCursor(0, 1);
    LCDDIEGO.print("Espacio privado");
    turnOnBar(1);
    turnOnBar(2);
    turnOnBar(3);
    turnOnBar(4);
    turnOnBar(5);
    turnOnBar(6);
    turnOnBar(7);
    turnOnBar(8);
    playTone(nota_mi, 326);
  } else if (distancia <= 5) {
    LCDDIEGO.clear();
    LCDDIEGO.setCursor(0, 0);
    LCDDIEGO.print("Invadiendo");
    LCDDIEGO.setCursor(0, 1);
    LCDDIEGO.print("Espacio privado");
    turnOnAllBars();
    playTone(nota_mi, 326);
  }
}

void turnOnBar(int barPin) {
  digitalWrite(barPin, HIGH);
}

void turnOffBar(int barPin) {
  digitalWrite(barPin, LOW);
}

void turnOffAllBars() {
  for (int i = bar1; i <= bar10; i++) {
    turnOffBar(i);
  }
}

void turnOnAllBars() {
  for (int i = bar1; i <= bar10; i++) {
    turnOnBar(i);
  }
}

void playTone(int frequency, int duration) {
  tone(Buzzer, frequency, duration);
}
