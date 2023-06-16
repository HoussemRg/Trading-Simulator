#include "BourseSet.h"

BourseSet::BourseSet(set<PrixJournalier> h,Date d):historique(h),dateAujourdhui(d){}


set<PrixJournalier>BourseSet::getHistorique() const{
    return(this->historique);
}

Date BourseSet::getDateAujourdhui()const{
    return this->dateAujourdhui;
}

void BourseSet::setDateAujourdhui(Date d){
    this->dateAujourdhui=d;
}

double BourseSet::getPrixParNomAction(vector<PrixJournalier> v,string n)const{
    for(auto it:v){
        if(it.getNomAction()==n){
            return(it.getPrix());
        }
    }
    return(0);
}

vector<PrixJournalier> BourseSet::getPrixJournalierParDateEtPrix(double solde)const{
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
vector<double> BourseSet::getPrixParDateEtNomAction(string n)const{
    vector<double> v={};
    for (auto it : this->historique){
        if (it.getDate() <= (this->dateAujourdhui) && it.getNomAction()==n){
            v.push_back(it.getPrix());
        }
    }
    return v;
}
