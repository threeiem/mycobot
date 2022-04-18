#ifndef TIME_HPP
#define TIME_HPP
#include <string.h>

class Time {

  public:
    // Constructor
    Time();
    Time(unsigned long period_in_seconds);

    unsigned long period = 0; // Period in seconds

    void setPeriodSecond(unsigned long second);
    void setPeriodMinute(unsigned long minute);
    void setPeriodHour(unsigned long hour);
    void setPeriodDay(unsigned long day);
    void setPeriodYear(unsigned long year);

  private:
    // Constants
    const unsigned long MAX_PERIOD_SECONDS = 4294967295; // Maximum seconds allowed for a period of time
    const unsigned long MAX_PERIOD_DAYS    = 49710;      // Maximum days allowed for a period of time
    const unsigned long MAX_PERIOD_YEARS   = 136;        // Maximum years allowed for a period of time
    const unsigned long DAY_SECONDS        = 86400;      // Seconds in a day
    const unsigned long YEAR_SECONDS       = 31556952;   // Seconds in a year
};

#endif