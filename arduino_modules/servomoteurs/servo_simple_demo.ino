//****************************************************************
//  kayfiyat al-täuaköm bi-al 'Servomoteur' biàistiemâl al-Arduino
//  barnâmaj àistoxdima fîh Arduino IDE 1.5.2
//  wiki.ieagles.net 2013
//****************************************************************
#include <Servo.h>

Servo servoDyali; // al-taerîf bi-al-mo7arïk

void setup(){
  // Attacher la pin 9 à l'objet servo.
  //   ATTN: le code initialise l'angle à 90 degrés par défaut. 
  // rabp al-mouarïk bi-al-pin "PWM 9"
  // einda al-àiçeâl takôno jamîeo al-maxarij "PWM" mohayäàa bi 90°
  servoDyali.attach(9); 
}

void loop(){
  
  servoDyali.write(0);
  delay(1000);
  
  // yatauaräko al-"Servo" bayn 0 
  for( int zawiya=0; zawiya<= 180; zawiya+=2 )
  { 
    servoDyali.write(zawiya);
    delay( 50 );
  }
  
  delay(1000);
}
