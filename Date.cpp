#include "Date.h"




Date::Date(int d,int m,int y):day(d),month(m),year(y){
    if(d>0 && d<32){
        this->day=d;
    }
    if(m>0 && m<13){
        this->month=m;
    }
    if(y>0){
        this->year=y;
    }
}
int Date::getDay() const {

       return day;
}


int Date::getMonth() const {

       return month;
}


int Date::getYear() const {

       return year;
}
ostream& operator<<(ostream& flux,const Date& d){
    flux<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    return flux;
}
bool estBissextile(Date d){
    if(d.year%4==0){
        if(d.year%100==0){
            if(d.year%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}
void Date::incrementerDate(){
    switch(this->month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        {
            if(this->day==31 && this->month!=12){
               this->day=1;
               this->month++;
            }
            else if(this->day==31 && this->month==12){
               this->day=1;
               this->month=1;
               this->year++;
            }
            else{
               this->day++;
            }
            break;

        }
    case 4:
    case 6:
    case 9:
    case 11:
        {
            if(this->day==30 && this->month!=12){
               this->day=1;
               this->month++;
            }
            else if(this->day==30 && this->month==12){
               this->day=1;
               this->month=1;
               this->year++;
            }
            else{
               this->day++;
            }
            break;

        }
    case 2:
        {
           if((estBissextile(*this) && this->day==29)||(estBissextile(*this)==false && this->day==28)){
              this->day=1;
              this->month++;
           }
           else{
              this->day++;
           }
           break;
        }
    default:
        {
            exit(0);
        }
    }
}

istream& operator>>(istream& flux,Date &d){
    char tab[100];
    flux.getline(tab,100,'/');
    d.day=atoi(tab);
    flux.getline(tab,100,'/');
    d.month=atoi(tab);
    flux.getline(tab,100,';');
    d.year=atoi(tab);



    return flux;
}


bool operator==(const Date& d1,const Date& d2){
    return(d1.day==d2.day && d1.month==d2.month && d1.year==d2.year);
}

bool operator<=(const Date& d1, const Date& d2){
    if (d1.year < d2.year) {
        return true;
    }
    else if (d1.year > d2.year) {
        return false;
    }
    else {
        if (d1.month < d2.month) {
            return true;
        }
        else if (d1.month > d2.month) {
            return false;
        }
        else {
            return d1.day <= d2.day;
        }
    }
}

bool operator<(const Date& d1, const Date& d2){
    if (d1.year < d2.year) {
        return true;
    }
    else if (d1.year > d2.year) {
        return false;
    }
    else {
        if (d1.month < d2.month) {
            return true;
        }
        else if (d1.month > d2.month) {
            return false;
        }
        else {
            return d1.day < d2.day;
        }
    }
}



