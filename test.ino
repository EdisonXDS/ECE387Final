
//
  
#include <Pixy2.h>
#include <Servo.h>
// This is the main Pixy object 
Pixy2 pixy;
Servo myservo; 
int pos = 90; 

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  myservo.attach(9);
  pixy.init();
}

void loop()
{ 
  int i; 
  pixy.ccc.getBlocks();
  
  // 
  if (pixy.ccc.numBlocks)
  {
 for (pos = 90; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  delay(10000);
  for (pos = 180; pos >= 90; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                      
  }
  }
}
   
