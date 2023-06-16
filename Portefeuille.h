#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include "Titre.h"

class Portefeuille{
private:
    double solde;
    vector<Titre> titre;
public:
    Portefeuille(double s=0,vector<Titre> t={});
    double getSolde() const;
    vector<Titre> getTitre()const;
    void deposerMontant(double Montant);
    void retirerMonatant(double Montant);
    double getQuantiteParNomAction(string n)const;
    friend ostream& operator<<(ostream& flux,const Portefeuille& p);
    bool ajouterTitre(Titre t);
    bool retirerTitre(Titre t);
    ~Portefeuille(){}
};



#endif // PORTEFEUILLE_H_INCLUDED
