#include "Time.hpp"

void Time::setPeriodSecond(unsigned long second) {
  this->period = second;    
}

void Time::setPeriodMinute(unsigned long minute) {
  if (minute < MAX_PERIOD_SECONDS/60) {
    this->period = minute * 60;    
  } else {
    this->period = MAX_PERIOD_SECONDS;
  }
}

void Time::setPeriodHour(unsigned long hour) {
  if (hour < MAX_PERIOD_SECONDS/3600) {
    this->period = hour * 3600;    
  } else {
    this->period = MAX_PERIOD_SECONDS;
  }
}

void Time::setPeriodDay(unsigned long day) {
  if (day <= MAX_PERIOD_DAYS) {
    this->period = this->DAY_SECONDS * day;
  } else {
    this->period = MAX_PERIOD_DAYS; 
  }
}

void Time::setPeriodYear(unsigned long year) {
  if (year <= MAX_PERIOD_YEARS) {
    this->period = this->YEAR_SECONDS * year;
  } else {
    this->period = MAX_PERIOD_YEARS; 
  }
}

Time::Time(){
}

Time::Time(unsigned long period_in_second){
  this->setPeriodSecond(period_in_second);
}