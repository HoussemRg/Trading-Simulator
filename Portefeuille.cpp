#include "Portefeuille.h"


Portefeuille::Portefeuille(double s,vector<Titre> t):solde(s),titre(t){}


double Portefeuille::getSolde() const{
    return this->solde;
}
vector<Titre> Portefeuille::getTitre()const{
    return this->titre;
}

double Portefeuille::getQuantiteParNomAction(string n)const{
    for(auto t:this->getTitre()){
        if(t.getNomAction()==n){
            return t.getQte();
        }
    }
    return 0;
}

ostream& operator<<(ostream& flux,const Portefeuille& p){
    flux<<"Solde : "<<p.solde<<endl;
    for(auto t : p.titre){
        cout<<t<<endl;
    }
    return flux;
}

void Portefeuille::deposerMontant(double Montant){
    if(Montant>=0){
        this->solde+=Montant;
    }
}

void Portefeuille::retirerMonatant(double Montant){
    if(Montant>=0 && this->solde>=Montant){
        this->solde-=Montant;
    }
}

bool Portefeuille::ajouterTitre(Titre t){
    if(t.getQte()>0){
       for(auto it=this->titre.begin();it!=this->titre.end();++it) {
            if (t.getNomAction()== it->getNomAction()) {
                it->ajouterQte(t.getQte());
                return true;
            }
       }
       this->titre.push_back(t);
       return true;
    }
    else{
       return false;
    }
}
bool Portefeuille::retirerTitre(Titre t){
    for (auto it = this->titre.begin(); it != this->titre.end(); ++it){
        if(it->getNomAction()==t.getNomAction()){
                if(it->getQte()>=t.getQte()){
                        it->retirerQte(t.getQte());
                        if(it->getQte()==0){
                            this->titre.erase(it);
                            return true;
                        }
                        return true;
                }

        }
    return false;
    }
}



