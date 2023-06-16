#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <iostream>
#include <string>
#include "Titre.h"

using namespace std;

enum TypeTx{Rien,Achat,Vente};

class Transaction{
private:
    Titre titre;
    TypeTx type;
public:
    Transaction(Titre t=Titre(),TypeTx T=Rien);
    Titre getTitre() const;
    TypeTx getType() const;
    friend ostream& operator<<(ostream& flux,const Transaction& t);
    ~Transaction(){}

};

#endif // TRANSACTION_H_INCLUDED
