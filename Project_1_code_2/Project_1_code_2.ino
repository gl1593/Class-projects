// speed controlled Servo Sweep
// see: http://arduino.cc/forum/index.php/topic,61586.0.html
//
// Michael Margolis 4 August 2011

#include <VarSpeedServo.h>

const int NBR_SERVOS = 3;       // the number of servos

VarSpeedServo Servos[NBR_SERVOS];        // servo objects


int servoPins[NBR_SERVOS]        = {3,6,9}; // servo pins
int servoSpeeds[NBR_SERVOS]      = {65,20,10}; // sweep speed, 1 is slowest, 255 fastest)
int servoMinPosition[NBR_SERVOS] = {0,0,20}; // the minumum servo angle
int servoMaxPosition[NBR_SERVOS] = {100,60,130}; // the maximum servo angle

void setup()
{
   for(int i=0; i < NBR_SERVOS; i++)  
   {
     Servos[i].attach(servoPins[i]);       
     Servos[i].slowmove(servoMinPosition[i],servoSpeeds[i]) ; // start sweeping from min position
   }
}

void loop()
{
  // sweep the servos
  for(int i=0; i < NBR_SERVOS; i++)
  {    
     if( Servos[i].read() == servoMinPosition[i])
       Servos[i].slowmove(servoMaxPosition[i],servoSpeeds[i]) ;         
     else if( Servos[i].read() == servoMaxPosition[i])
       Servos[i].slowmove(servoMinPosition[i],servoSpeeds[i]) ;           
  }  
}
