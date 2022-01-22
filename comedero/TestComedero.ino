#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int A = 9;
int B = 10;
int C = 11;
int D = 12;
long del = 3500;

void setup () 
{
  Serial.begin(9600);
  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
  
    // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
     rtc.adjust(DateTime(2022, 1, 20, 20, 29, 0));
     showTime();
  }
  pinMode(A, OUTPUT);     
  pinMode(B, OUTPUT);     
  pinMode(C, OUTPUT);     
  pinMode(D, OUTPUT); 
}

void loop () 
{
    DateTime now = rtc.now();
    
    //Serial.println("Seconds: " + now.second());
    Serial.println(now.second(), DEC);

    if(now.hour() == 22  && now.minute() >= 29 && now.minute() <= 30){
      run_engine();
    }else{
      stop_engine();
    }
    showTime();
    
//    Serial.println("Unix Time: ");
//    Serial.print("elapsed ");
//    Serial.print(now.unixtime());
//    Serial.print(" seconds/");
//    Serial.print(now.unixtime() / 86400L);
//    Serial.println(" days since 1/1/1970");
    
    // calculate a date which is 7 days & 30 seconds into the future
//    DateTime future (now + TimeSpan(7,0,0,30));
//    
//    Serial.println("Future Date & Time (Now + 7days & 30s): ");
//    Serial.print(future.year(), DEC);
//    Serial.print('/');
//    Serial.print(future.month(), DEC);
//    Serial.print('/');
//    Serial.print(future.day(), DEC);
//    Serial.print(' ');
//    Serial.print(future.hour(), DEC);
//    Serial.print(':');
//    Serial.print(future.minute(), DEC);
//    Serial.print(':');
//    Serial.print(future.second(), DEC);
//    Serial.println();

    //Serial.println();
    //delay();
}




void stop_engine(){
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);   
  digitalWrite(C, LOW);   
  digitalWrite(D, LOW);
}

void showTime(){
    DateTime now = rtc.now();
    Serial.println("Current Date & Time: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}
void run_engine()
{
    for (int i=0; i<=10; i++){
      een(); 
      twee();
      drie();
      vier();
    }
}


void een(){
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);   
  digitalWrite(C, HIGH);   
  digitalWrite(D, LOW);   
  delayMicroseconds(del);
}
void twee(){
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);   
  digitalWrite(C, LOW);   
  digitalWrite(D, HIGH);   
  delayMicroseconds(del);
}
void drie(){
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);   
  digitalWrite(C, LOW);   
  digitalWrite(D, HIGH);   
  delayMicroseconds(del);
}
void vier(){
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);   
  digitalWrite(C, HIGH);   
  digitalWrite(D, LOW);   
  delayMicroseconds(del);
}
