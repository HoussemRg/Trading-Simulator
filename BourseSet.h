#ifndef BOURSESET_H_INCLUDED
#define BOURSESET_H_INCLUDED
#include "Bourse.h"
#include "PrixJournalier.h"
#include "Date.h"

using namespace std;
class BourseSet:public Bourse{
private:
    set<PrixJournalier> historique;
    Date dateAujourdhui;
public:
    BourseSet(set<PrixJournalier> h,Date d);
    Date getDateAujourdhui()const;
    set<PrixJournalier> getHistorique() const;
    void setDateAujourdhui(Date d);
    double getPrixParNomAction(vector<PrixJournalier> v,string n)const;
    vector<PrixJournalier> getPrixJournalierParDateEtPrix(double solde)const;
    vector<double> getPrixParDateEtNomAction(string n)const;
    ~BourseSet(){cout<<"Bourse vecteur Detruite"<<endl;}
};
#endif // BOURSESET_H_INCLUDED
