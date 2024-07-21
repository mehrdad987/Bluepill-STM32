#include <Wire.h>
#include "RTClib.h"
 
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 
void setup() 
{
 
  Serial.begin(115200);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
    }
  rtc.adjust(DateTime(__DATE__, __TIME__));
}
 
void loop()
{
  DateTime now = rtc.now();
  delay(1000);
  

  Serial.println(now.second(), DEC);
  Serial.println(now.minute(), DEC);
  Serial.println(now.hour(), DEC);
  Serial.println(now.day(), DEC);
  Serial.println(now.month(), DEC);
  Serial.println(now.year(), DEC);
}
