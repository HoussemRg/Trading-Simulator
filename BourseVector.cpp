#include "BourseVector.h"

BourseVector::BourseVector(vector<PrixJournalier> h,Date d):historique(h),dateAujourdhui(d){}

vector<PrixJournalier>BourseVector::getHistorique() const{
    return(this->historique);
}

Date BourseVector::getDateAujourdhui()const{
    return this->dateAujourdhui;
}
void BourseVector::setDateAujourdhui(Date d){
    this->dateAujourdhui=d;
}

double BourseVector::getPrixParNomAction(vector<PrixJournalier> v,string n)const{
    for(auto it:v){
        if(it.getNomAction()==n){
            return(it.getPrix());
        }
    }
    return(0);
}


vector<PrixJournalier> BourseVector::getPrixJournalierParDateEtPrix(double solde)const{
    vector<PrixJournalier> v1={};



    for(auto it:this->historique){
            if(this->dateAujourdhui <= it.getDate()){
                if(this->dateAujourdhui==it.getDate() && it.getPrix()<=solde){
                    v1.push_back(it);
                }

            }

    }
    return v1;
}
vector<double> BourseVector::getPrixParDateEtNomAction(string n)const{
    vector<double> v={};
    for (auto pj : this->historique){
        if (pj.getDate() <= (this->dateAujourdhui) && pj.getNomAction()==n){
            v.push_back(pj.getPrix());
        }
    }
    return v;
}


