#include <iostream>
#include <ctime>

class Clock {
private:
    int seconds; // variable for the seconds
    int hours; // variable for hours
    int minutes; // variable for the minutes
    bool is12HourClock; // variable for 12 hour clock format
    bool isPM; // variable to check if time is AM or PM on 12 hour clock format
    bool is24HourFormat; // variable for 24 hour clock format
    int timeZone; // variable to input time zone
public:
    Clock() {
        time_t currentTime = time(0); // the current time
        tm *localTime = localtime(&currentTime); // allows time to convert to local 
        seconds = localTime->tm_sec; // set seconds
        hours = localTime->tm_hour; // set hours
        minutes = localTime->tm_min; // set minutes
        is12HourClock = true; // set clock to 12 hour clock format
        isPM = true; // set time to PM
        is24HourFormat = true; // set clock to 24 hour clock format
        timeZone = 4; // set time zone ahead 4 hours (PST)
    }

     void addSecond() {
        seconds = (seconds + 1) % 60; // increase seconds. Range of 0-59
        if (seconds == 60) {
            addMinute(); // increase minute if seconds is 60
        }
    }

    void addHour() {
        hours = (hours + 1) % 24; // increase hours. Keep hours between range of 0-23
        if(hours == 60)
        {
            if(isPM)
            {
                isPM = false; // if hour is 0 and time is PM, set it to AM
            }
            else
            {
                isPM = true; // if hour is 0 and time is AM, set it to PM
            }
        }
    }

    void addMinute() {
        minutes = (minutes + 1) % 60; // increase minutes. Range of 0-59
        if (minutes == 60) {
            addHour(); // increase hour if minutes is 60
        }
    }

    void time_t12HourClockFormat() {
        is12HourClock = !is12HourClock; // clock format between 12 hour and 24 hour
    }

    void time_t24HourClockFormat() {
        is24HourFormat = !is24HourFormat; // clock format between 24 hour and 12 hour
    }

    void setTimeZone(int timeZone) {
        this->timeZone = timeZone; // set time zone of choice
    }

    void displayClock() {
        if (is24HourFormat) {
            std::cout << hours << ":" << minutes << ":" << seconds;
        } else {
            int hour = (hours % 12 == 0) ? 12 : hours % 12; // convert hour to 12 hour clock format
            std::cout << hour << ":" << minutes << ":" << seconds;
            if(isPM)
            {
                std::cout << " PM";
            }
                        else
            {
                std::cout << " AM";
            }
        }
        if (timeZone != 0) {
            std::cout << " (PST " << ((timeZone > 0) ? "+" : "") << timeZone << ")";
        }
    }
};

int main() {
    Clock clock;

    while (true) {
        std::cout << "Clock: ";
        clock.displayClock();

        std::cout << "\n\nMenu: \n1. Add Second \n2. Add Minute \n3. Add Hour \n4. time_t12HourClockFormat \n5. time_t24HourClockFormat \n6. Set Time Zone \n7. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                clock.addHour();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addSecond();
                break;
            case 4:
                clock.time_t12HourClockFormat();
                break;
            case 5:
                clock.time_t24HourClockFormat();
                break;
            case 6:
                int timeZone;
                std::cout << "Enter time zone: ";
                std::cin >> timeZone;
                clock.setTimeZone(timeZone);
                break;
            case 7:
                return 0;
            default:
                break;
        }
    }
    return 0;
}