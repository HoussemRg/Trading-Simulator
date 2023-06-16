#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include <iostream>
#include <string>
#include <cstring>
#include "Date.h"
using namespace std;

class PrixJournalier{
private:
    string nomAction;
    double prix;
    Date date;
public:
    PrixJournalier(string n=" ",double p=0,Date d=Date());
    string getNomAction() const;
    double getPrix() const;
    Date getDate() const;
    friend ostream& operator<<(ostream& flux,const PrixJournalier& p);
    friend istream& operator>>(istream& flux,PrixJournalier &p);
    friend bool operator==(const PrixJournalier& p1,const PrixJournalier& p2);
    friend bool operator<(const PrixJournalier& p1,const PrixJournalier& p2);
    ~PrixJournalier(){}
};
#endif // PRIXJOURNALIER_H_INCLUDED
