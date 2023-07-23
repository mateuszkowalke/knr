#include <stdio.h>

char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isLeap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int day_of_year(int year, int month, int day) {
    if (month < 1 || month > 12) {
        printf("Incorrect month: %d\n", month);
        return -1;
    }

    int yearday = 0;
    int leap = isLeap(year);

    if (day < 1 || day > daytab[leap][month]) {
        printf("Incorrect day: %d\n", day);
        return -1;
    }

    for (int i = 1; i < month; i++) {
        yearday += daytab[leap][i];
    }

    return yearday + day;
}

void month_day(int year, int yearday, int *month, int *day) {
    int leap = isLeap(year);
    if ((leap && yearday > 366) || (!leap && yearday > 365) || yearday < 1) {
        printf("Incorrect yearday: %d\n", yearday);
    }

    for (*month = 1; yearday > daytab[leap][*month]; yearday -= daytab[leap][*month++]);
    *day = yearday;
}
