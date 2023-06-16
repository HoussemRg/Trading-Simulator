#ifndef BOURSEMMAP_H_INCLUDED
#define BOURSEMMAP_H_INCLUDED
#include "Bourse.h"
#include "PrixJournalier.h"
#include "Date.h"

using namespace std;
class BourseMmap:public Bourse{
private:
    multimap<Date,PrixJournalier> historique;
    Date dateAujourdhui;
public:
    BourseMmap(multimap<Date,PrixJournalier> h,Date d);
    Date getDateAujourdhui()const;
    multimap<Date,PrixJournalier> getHistorique() const;
    void setDateAujourdhui(Date d);
    double getPrixParNomAction(vector<PrixJournalier> v,string n)const;
    vector<PrixJournalier> getPrixJournalierParDateEtPrix(double solde)const;
    vector<double> getPrixParDateEtNomAction(string n)const;
    ~BourseMmap(){cout<<"Bourse vecteur Detruite"<<endl;}
};


#endif // BOURSEMMAP_H_INCLUDED
