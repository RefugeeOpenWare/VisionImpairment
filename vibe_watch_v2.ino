#include <NewPing.h>
#include <RunningMedian.h>

//Define the pins for the ultrasonic sensor's echo and trigger pins 
#define DISTANCE_ECHO 3
#define DISTANCE_TRIGGER 2
#define MAX_ULTRASONIC_DISTANCE 500
#define M1 6

NewPing sonar(DISTANCE_TRIGGER, DISTANCE_ECHO, MAX_ULTRASONIC_DISTANCE);

int getDistanceFromUltrasonicSensor(){
  //Create an instance of the RunningMedian class with the number of samples to use
  RunningMedian samples = RunningMedian(7);
  
  //Get the 7 samples
  for(int i= 0; i<5; i++){
      delay(50);
      int pingVal = sonar.ping();
      
      int distance = pingVal / US_ROUNDTRIP_CM;
      if(distance == 0){
        distance = 3000;
      }
     samples.add(distance);
   }   
   //Return the median value
   return samples.getMedian();  
}


void setup()
{
    //Initialize serial communication to send the distance value  to the serial monitor
    Serial.begin(9600);
        pinMode(6, OUTPUT);

}

void loop()
{
  int distance_cm;
  distance_cm = getDistanceFromUltrasonicSensor();
  
  Serial.print(distance_cm);
  Serial.print("cm");
  Serial.println();
  
   if (distance_cm < 40) 
       {
          lt_100();
       } 
       
       else if(distance_cm < 100) 
       {
          lt_200(); 
       } 

       else; // if there's nothing in front of us
       {
          nothing();      
       }
}



void lt_100() {
  digitalWrite(M1,HIGH);
  delay(70);
  digitalWrite(M1,LOW);
  delay(35);
}

void lt_200() {
  digitalWrite(M1,HIGH);
  delay(70);
  digitalWrite(M1,LOW);
  delay(180);
}

void nothing() {
  digitalWrite(M1,LOW);
  delay(100);
}
