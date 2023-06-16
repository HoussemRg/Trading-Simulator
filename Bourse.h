#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include "Date.h"
#include "PrixJournalier.h"
#include<vector>
#include<set>
#include <map>
#include <algorithm>
using namespace std;
class Bourse{

public:
    virtual Date getDateAujourdhui()const=0;
    virtual void setDateAujourdhui(Date d)=0;
    virtual double getPrixParNomAction(vector<PrixJournalier> v,string n)const=0;
    virtual vector<PrixJournalier> getPrixJournalierParDateEtPrix(double solde)const=0;
    virtual vector<double> getPrixParDateEtNomAction(string n)const =0;
    virtual ~Bourse(){cout<<"Bourse Detruite"<<endl;}
};


#endif // BOURSE_H_INCLUDED
