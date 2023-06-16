#include "BourseMmap.h"

BourseMmap::BourseMmap(multimap<Date,PrixJournalier> h,Date d):historique(h),dateAujourdhui(d){}


multimap<Date,PrixJournalier>BourseMmap::getHistorique() const{
    return(this->historique);
}

Date BourseMmap::getDateAujourdhui()const{
    return this->dateAujourdhui;
}

void BourseMmap::setDateAujourdhui(Date d){
    this->dateAujourdhui=d;
}


double BourseMmap::getPrixParNomAction(vector<PrixJournalier> v,string n)const{
    for(auto it:v){
        if(it.getNomAction()==n){
            return(it.getPrix());
        }
    }
    return(0);
}


vector<PrixJournalier> BourseMmap::getPrixJournalierParDateEtPrix(double solde)const{
    vector<PrixJournalier> v1={};
    for(auto it:this->historique){
            if(this->dateAujourdhui <= it.first){
                if(this->dateAujourdhui==it.first && it.second.getPrix()<=solde){
                    v1.push_back(it.second);
                }

            }

    }
    return v1;
}
vector<double> BourseMmap::getPrixParDateEtNomAction(string n)const{
    vector<double> v={};
    for (auto d : this->historique){
        if (d.first <= (this->dateAujourdhui) && d.second.getNomAction()==n){
            v.push_back(d.second.getPrix());
        }
    }
    return v;
}
