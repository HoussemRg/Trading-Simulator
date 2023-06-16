#include "PrixJournalier.h"

PrixJournalier::PrixJournalier(string n,double p,Date d):nomAction(n),prix(p),date(d){
}

string PrixJournalier::getNomAction() const{
    return(this->nomAction);
}
double PrixJournalier::getPrix() const{
    return(this->prix);
}
Date PrixJournalier::getDate() const{
    return(this->date);
}


ostream& operator<<(ostream& flux,const PrixJournalier& p){
    flux<<"Nom Action : "<<p.nomAction<<endl;
    flux<<"Prix : "<<p.prix<<endl;
    flux<<"Date : "<<p.date;
    return flux;
}


istream& operator>>(istream& flux,PrixJournalier &p){
    char tab[100];
    flux>>p.date;
    flux.getline(tab,100,';');
    p.nomAction=tab;
    flux.getline(tab,100);
    p.prix=atof(tab);
    return flux;
}

bool operator==(const PrixJournalier& p1,const PrixJournalier& p2){
    return (p1.date==p2.date && p1.nomAction==p2.nomAction && p1.prix==p2.prix);
}

bool operator<(const PrixJournalier& p1,const PrixJournalier& p2){
    //return(p1.getDate()<p2.getDate() || p1.date==p2.date);

    if(p1.date<p2.date){
            return(p1.date<p2.date);
    }
    else if(p1.date==p2.date){
        if(p1.prix<p2.prix){
            return(p1.prix<p2.prix);
        }
        else if(p1.prix==p2.prix){
            return(p1.nomAction<p2.nomAction);
        }
    }
}
