#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include "Bourse.h"
#include "PrixJournalier.h"
#include "Date.h"
using namespace std;
class BourseVector:public Bourse{
private:
    vector<PrixJournalier> historique;
    Date dateAujourdhui;
public:
    BourseVector(vector<PrixJournalier> h,Date d);
    Date getDateAujourdhui()const;
    void setDateAujourdhui(Date d);
    double getPrixParNomAction(vector<PrixJournalier> v,string n)const;
    vector<PrixJournalier> getHistorique() const;
    vector<PrixJournalier> getPrixJournalierParDateEtPrix(double solde)const;
    vector<double> getPrixParDateEtNomAction(string n)const;
    ~BourseVector(){cout<<"Bourse vecteur Detruite"<<endl;}
};

#endif // BOURSEVECTOR_H_INCLUDED
