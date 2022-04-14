#include "date.h"

Date::Date(int day, int month, int year) {
  _day = day;
  _month = month;
  _year = year;
}

int Date::getDay() const {
  return _day;
}
void Date::setDay(int day) {
  _day = day;
}

int Date::getMonth() const {
  return _month;
}

void Date::setMonth(int month) {
  _month = month;
}
int Date::getYear() const {
  return _year;
}

void Date::setYear(int year) {
  _year = year;
}

string Date::getDate() const {
  return to_string(_day) + " " + to_string(_month) + " " + to_string(_year);
}
