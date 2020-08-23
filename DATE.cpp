#include "DATE.h"
main(){
  int year,month,day;
  std::cout << "give the year : ";
  std::cin >> year;
  do {
    std::cout << "give the month : ";
    std::cin >> month;
  } while(month<1||month>12);
  if (year%4 == 0) {
    NumberOfDays[1] = 29;
  }
  do {
    std::cout << "give the day : ";
    std::cin >> day;
  } while(day<1||day>NumberOfDays[month-1]);
  DATE date = DATESet(year, month, day);
  DATEPrint(date);
  std::cout << '\n' << "Now : "; DATEPrint(DateNow());
}
