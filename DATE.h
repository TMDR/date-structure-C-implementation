#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
char days[7][10] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char* dayOfMonthf(int year,int month,int day){
  int m=month-2;
  if(m<1)
    m+=12;
  int d = year%10+((year/10)%10)*10;
  int c = (year/100)%10+(year/1000)*10;
  int f =day+(int)((13*m-1)/5)+d+(int)(d/4)+(int)(c/4)-2*c;
  return days[f%7-1];
}
struct DATE{
  int year;
  int month;
  int dayOfMonth;
  char* dayOfWeek;
};
DATE DATESet(int year, int month, int day){
  DATE DATE;
  DATE.year = year;
  DATE.month = month;
  DATE.dayOfMonth = day;
  DATE.dayOfWeek = dayOfMonthf(year, month, day);
  return DATE;
}
int DateDay(DATE DATE){
  return DATE.dayOfMonth;
}
int DateMonth(DATE DATE){
  return DATE.month;
}
int DateYear(DATE DATE){
  return DATE.year;
}
char* DateDayWeek(DATE DATE){
  return DATE.dayOfWeek;
}
void DATEPrint(DATE DATE){
  std::cout << "DATE : " << DateDayWeek(DATE) << " " << DateDay(DATE) << "\/" << DateMonth(DATE) << "\/" << DateYear(DATE) << '\n';
}
DATE DateNow ( ) {
DATE d = { 1, 1, 1970};
time_t t = time(0L);
tm *tp;
if (t == (time_t)(-1))
return d;
tp = localtime(&t);
d.dayOfMonth = tp->tm_mday;
d.month = tp->tm_mon + 1;
d.year = tp->tm_year + 1900;
d.dayOfWeek = dayOfMonthf(d.year, d.month, d.dayOfMonth);
return d;
}

#endif
