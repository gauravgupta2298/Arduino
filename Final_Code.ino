#include <IRremote.h>

#define trigPin 13
#define echoPin 12
#define motor 7
#define buzzer 6
#define RECV_PIN 5
int x=0;

long l;
IRrecv irrecv(RECV_PIN);
decode_results results;

long base = 0x800;// base value for a another TV Remote

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  //Water Sensor code
  int sensor=analogRead(A0);
  if (sensor>325)
  {
    digitalWrite(motor, HIGH);
  }
  else
  {
    digitalWrite(motor, LOW);
  }


  //Ultrasonic Sensor code
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  if(distance>=90)
  {
    for(x=100-distance;x>=0;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(110);
    }
  }else if(distance<90 & distance>=80)
  {
     for(x=100-distance;x>=10;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(90);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
  }else if(distance<80 & distance>=70)
  {
    for(x=100-distance;x>=20;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(80);
      digitalWrite(buzzer, LOW);
      delay(90);
    }
  }else if(distance<70 & distance>=60)
  {
    for(x=100-distance;x>=30;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(70);
      digitalWrite(buzzer, LOW);
      delay(80);
    }
  }else if(distance<60 & distance>=50)
  {
    for(x=100-distance;x>=40;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(60);
      digitalWrite(buzzer, LOW);
      delay(70);
    }
  }else if(distance<50 & distance>=40)
  {
    for(x=100-distance;x>=50;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(60);
    }
  }else if(distance<40 & distance>=30)
  {
    for(x=100-distance;x>=60;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(40);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
  }else if(distance<30 & distance>=20)
  {
    for(x=100-distance;x>=70;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(30);
      digitalWrite(buzzer, LOW);
      delay(40);
    }
  }else if(distance<20 & distance>=10)
  {
    for(x=100-distance;x>=80;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(20);
      digitalWrite(buzzer, LOW);
      delay(30);
    }
  }else if(distance<10)
  {
    for(x=100-distance;x>=90;x--)
    {
      digitalWrite(buzzer, HIGH);
      delay(10);
      digitalWrite(buzzer, LOW);
      delay(20);
    }
  }
  delay(5);


  //IR sensor code  
  flag=irrecv.decode(&results);
  if (flag) 
  {
    l = results.value;
    if (l==12) 
    {
      digitalWrite(buzzer, HIGH);// reduce the code to base zero.
      delay(50);
    }

    delay(100);
    irrecv.resume(); // Receive the next value
  }
}
