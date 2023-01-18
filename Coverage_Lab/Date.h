#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>	    // istream, ostream

class Date {
  public:
    Date();
    // Default copy ctor is fine
    // Default assignment operator is fine
    Date(int year, int month, int day);

    int getday() const;
    int getmonth() const;
    int getyear() const;

    void setday(int);
    void setmonth(int);
    void setyear(int);

    Date& operator+=(int);
    int operator-(const Date &) const;

    Date operator+(int) const;
    const Date& operator++();	// prefix
    Date operator++(int);	// postfix

    Date operator-(int) const;
    Date& operator-=(int);
    const Date& operator--();	// prefix
    Date operator--(int);	// postfix

    bool operator<(const Date &) const;
    bool operator<=(const Date &) const;
    bool operator>(const Date &) const;
    bool operator>=(const Date &) const;
    bool operator==(const Date &) const;
    bool operator!=(const Date &) const;

  protected:
    static int ymd_to_daynum(int year, int month, int day);
    int daynum;				// 1 = January 1, year 1
};

// non-methods (free functions):

Date operator+(int, const Date &);
std::ostream& operator<<(std::ostream &out, const Date &);	// YYYY-MM-DD
std::istream& operator>>(std::istream &in, Date &);		// YYYY-MM-DD

#endif /* DATE_H_INCLUDED */
