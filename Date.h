#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int d=0,int m=0,int y=0);
    int getDay() const ;
    int getMonth() const ;
    int getYear() const ;
    Date(const Date& d){
        this->day=d.day;
        this->month=d.month;
        this->year=d.year;
    }
    void incrementerDate();
    friend bool estBissextile(Date);
    friend ostream& operator<<(ostream& flux,const Date& d);
    friend istream& operator>>(istream& flux,Date &d);
    friend bool operator==(const Date& d1,const Date& d2);
    friend bool operator<=(const Date& d1,const Date& d2);
    friend bool operator<(const Date& d1,const Date& d2);
    ~Date(){}
};


#endif // DATE_H_INCLUDED
