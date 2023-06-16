#include "Titre.h"


Titre::Titre(string n,double q):nomAction(n),qte(q){}

string Titre::getNomAction() const{
    return this->nomAction;
}
double Titre::getQte() const{
    return this->qte;
}
void Titre::ajouterQte(double q){
    if(q>=0){
        (this->qte)+=q;
    }



}
void Titre::retirerQte(double q){
    if(this->qte>=q){
        this->qte-=q;
    }
}

ostream& operator<<(ostream& flux,const Titre& t){
    flux<<"Nom Action : "<<t.nomAction<<endl;
    flux<<"quantitée : "<<t.qte<<endl;
    return flux;
}

bool operator==(const Titre& t1,const Titre& t2){
    return (t1.nomAction==t2.nomAction && t1.qte==t2.qte);
}


