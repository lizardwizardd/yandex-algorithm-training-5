#include <iostream>
#include <vector>
#include <string>

enum DayOfWeek
{
    Saturday,
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Invalid
};

int getDayOfWeek(int year, int month, int day)
{
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    
    // 0 = Saturday, 6 = Friday
    int dayOfWeek = (q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;

    return dayOfWeek;
}

inline bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

DayOfWeek stringToDayOfWeek(const std::string& day)
{
    if (day == "Monday")
        return Monday;
    else if (day == "Tuesday")
        return Tuesday;
    else if (day == "Wednesday")
        return Wednesday;
    else if (day == "Thursday")
        return Thursday;
    else if (day == "Friday")
        return Friday;
    else if (day == "Saturday")
        return Saturday;
    else if (day == "Sunday")
        return Sunday;
    else
        return Invalid;
}

std::string dayOfWeekToString(DayOfWeek day)
{
    switch (day) {
        case DayOfWeek::Monday:
            return "Monday";
        case DayOfWeek::Tuesday:
            return "Tuesday";
        case DayOfWeek::Wednesday:
            return "Wednesday";
        case DayOfWeek::Thursday:
            return "Thursday";
        case DayOfWeek::Friday:
            return "Friday";
        case DayOfWeek::Saturday:
            return "Saturday";
        case DayOfWeek::Sunday:
            return "Sunday";
        default:
            return "Invalid day";
    }
}

int stringToMonthNumber(const std::string& month)
{
    if (month == "January")
        return 1;
    else if (month == "February")
        return 2;
    else if (month == "March")
        return 3;
    else if (month == "April")
        return 4;
    else if (month == "May")
        return 5;
    else if (month == "June")
        return 6;
    else if (month == "July")
        return 7;
    else if (month == "August")
        return 8;
    else if (month == "September")
        return 9;
    else if (month == "October")
        return 10;
    else if (month == "November")
        return 11;
    else if (month == "December")
        return 12;
    else
        return -1;
}

int main()
{
    int freeDaysCount;
    int year;
    std::cin >> freeDaysCount >> year;

    std::vector<int> workDaysPerDayOfWeek(7, 52);
    while (freeDaysCount--)
    {
        int day;
        std::string month;
        std::cin >> day >> month;

        int dayOfWeek = getDayOfWeek(year, stringToMonthNumber(month), day);
        workDaysPerDayOfWeek[dayOfWeek] -= 1;
    }

    std::string firstDayOfWeekInYear; 
    std::cin >> firstDayOfWeekInYear;
    DayOfWeek firstDayInYear = stringToDayOfWeek(firstDayOfWeekInYear);
    
    workDaysPerDayOfWeek[(int)firstDayInYear % 7] += 1;
    if (isLeapYear(year))
        workDaysPerDayOfWeek[((int)firstDayInYear + 1) % 7] += 1;

    // for (int i = 0; i < 7; i++)
    // {
    //     std::cout << dayOfWeekToString((DayOfWeek)i) << ": "
    //               << workDaysPerDayOfWeek[i] << '\n';
    // }

    int mostWorkdays = -1;
    int mostWorkdaysDay = -1;
    int leastWorkdays = 367;
    int leasWorkdaysDay = -1;
    for (int i = 0 ; i < 7; i++)
    {
        if (workDaysPerDayOfWeek[i] > mostWorkdays)
        {
            mostWorkdays = workDaysPerDayOfWeek[i];
            mostWorkdaysDay = i;
        }
        if (workDaysPerDayOfWeek[i] < leastWorkdays)
        {
            leastWorkdays = workDaysPerDayOfWeek[i];
            leasWorkdaysDay = i;
        }
    }

    // The best free day is the one with most work days per year
    std::cout << dayOfWeekToString((DayOfWeek)mostWorkdaysDay) << ' ';
    // The worst free day is the one with least work days per year
    std::cout << dayOfWeekToString((DayOfWeek)leasWorkdaysDay) << '\n';

    return 0;
}