// Now is 12:30 pm, my timer is 1h40m, when did I start the timer?
// Use C++ ctime library to output the start time in hh:mm am format.

#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

int main() {
    tm endTimeSpec;
    endTimeSpec.tm_year = 2020 - 1900; // year since 1900
    endTimeSpec.tm_mon = 5; // months since Jan [0, 11]
    endTimeSpec.tm_mday = 8; // day of the month [1, 31]
    endTimeSpec.tm_hour = 12; // hours since midnight [0, 23]
    endTimeSpec.tm_min = 30; // minutes after the hour [0, 59]
    endTimeSpec.tm_sec = 0; // seconds after the minute [0, 60]
    mktime(&endTimeSpec);
    cout << "end time: \t" << put_time(&endTimeSpec , "%I:%M %p") << endl;
}
