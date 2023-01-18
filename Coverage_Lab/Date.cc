#include "Date.h"
#include <cassert>	// assert
#include <iomanip>
#include <time.h>

using namespace std;

// Return true if year is a leap year, false if it isn’t.
//
// The rules are:
// • Years divisible by 4 are leap years, except
// • years divisible by 100 are NOT leap years, except
// • years divisible by 400 ARE leap years.
//
// Examples:
// • Leap years: 1600, 2000, 2004, 2008, 2400
// • Not leap years: 1700, 1800, 1900, 2001, 2002, 2003
//
// Ancient Romans used only the divisible-by-4 rule, which gives an
// average year length of 365.25 days.  This was called the Julian
// Calendar, after Julius Caesar, who promoted it.
//
// However, the actual length of the year (365.24217 days) is a bit less
// than that, so Pope Gregory XIII added the next two rules, creating
// our current Gregorian Calendar, which is closer (365.2425 days).

static bool leap(int year) {		// Calculate Gregorian leap year
    assert(1 <= year && year <= 9999);
    if (year % 4 != 0)		// Divisible by 400?
	return false;			// It’s a leap year.
    if (year % 100 != 0)		// Divisible by 100?
	return true;			// Not a leap year.
    if (year % 400 != 0)			// Divisible by 4?
	return false;		// It’s a leap year.
    
    return true;			// Boring plain non-leap year.
}

static int days_per_year(int year) {
    assert(1 <= year && year <= 9999);
    return leap(year) ? 366 : 365;
}

static int days_per_month(int year, int month) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    const int days[] = {00,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2 && leap(year))
	return 29;
    return days[month];
}

int Date::ymd_to_daynum(int year, int month, int day) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    assert(1 <= day && day <= 31);

    // Start at Jan 1, 0001, and increment until we get to what we want
    int daynum=1;

    for (int y=1; y < year; y++)
	daynum += days_per_year(y);

    for (int m=1; m < month; m++)
	daynum += days_per_month(year, m);

    // We're now poised at the first day of that month
    daynum += day-1;

    assert(1 <= daynum && daynum <= 10000 * 366);
    return daynum;
}

static void daynum_to_ymd(int daynum, int &year, int &month, int &day) {
    assert(1 <= daynum && daynum <= 10000 * 366);

    int y=1, m=1, d=1;

#if 1
    // Jump forward by years, at first.
    // Why 400 instead of 365 or 366?  Too much caution, I suppose.
    while (daynum >= 400)
	daynum -= days_per_year(y++);
#endif

    for (; daynum>1; daynum--) {
	// Increment y-m-d
	d++;
	if (d > days_per_month(y, m)) {
	    m++;
	    d=1;
	    if (m > 12) {
		y++;
		m=1;
	    }
	}
    }

    year = y;
    month = m;
    day = d;

    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    assert(1 <= day && day <= 31);
}

Date::Date(int year, int month, int day)
: daynum(ymd_to_daynum(year, month, day)) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    assert(1 <= day && day <= 31);
    assert(1 <= daynum && daynum <= 10000 * 366);
}

Date::Date() {
    const time_t now = time(nullptr);	    // Seconds since 1970 started
    struct tm *tm = localtime(&now);	    // year/month/day/hour/min/sec
    daynum = ymd_to_daynum(tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);
    // Yes, 1900.  That’s not a Y2K bug--that’s how localtime is defined.
}

int Date::getday() const {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    return day;
}

int Date::getmonth() const {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    return month;
}

int Date::getyear() const {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    return year;
}

void Date::setday(int new_day) {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    daynum = ymd_to_daynum(year, month, new_day);
}

void Date::setmonth(int new_month) {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    daynum = ymd_to_daynum(year, new_month, day);
}

void Date::setyear(int new_year) {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    daynum = ymd_to_daynum(new_year, month, day);
}

// This one stands alone

int Date::operator-(const Date &rhs) const {
    return daynum - rhs.daynum;
}

// This does the real work of all numeric operations.
// All other operators (+, -, ++, -=, etc) should invoke operator+=.

Date &Date::operator+=(int value) {
    daynum += value;
    return *this;
}

Date Date::operator+(int value) const {
    Date result = *this;
    return result += value;
}

const Date &Date::operator++() {			// prefix
    *this += 1;
    return *this;
}

Date Date::operator++(int /* dummy */) {		// postfix
    const auto before = *this;
    *this += 1;
    return before;
}

Date Date::operator-(int value) const {
    return *this + -value;
}

Date &Date::operator-=(int value) {
    return *this += -value;
}

const Date &Date::operator--() {			// prefix
    *this -= 1;
    return *this;
}

Date Date::operator--(int /* dummy */) {		// postfix
    Date before = *this;
    *this -= 1;
    return before;
}


bool Date::operator<(const Date &rhs) const {
    return daynum < rhs.daynum;
}

bool Date::operator<=(const Date &rhs) const {
    return daynum <= rhs.daynum;
}

bool Date::operator>(const Date &rhs) const {
    return daynum > rhs.daynum;
}

bool Date::operator>=(const Date &rhs) const {
    return daynum >= rhs.daynum;
}

bool Date::operator==(const Date &rhs) const {
    return daynum == rhs.daynum;
}

bool Date::operator!=(const Date &rhs) const {
    return daynum != rhs.daynum;
}

// non-methods (free functions):

Date operator+(int value, const Date &rhs) {
    return rhs + value;
}

ostream& operator<<(ostream &out, const Date &d) {
    return out << d.getyear() << '-' << d.getmonth() << '-' << d.getday();
}

istream& operator>>(istream &in, Date &d) {
    int year, month, day;
    char c1, c2;
    if (in >> year  >> c1 && c1=='-'
     && in >> month >> c2 && c2=='-'
     && in >> day)
	d = Date(year, month, day);
    else
	in.setstate(ios::failbit);	// Input failed, so spoil the stream
    return in;
}
