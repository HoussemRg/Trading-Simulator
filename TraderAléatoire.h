#ifndef TRADERALÈATOIRE_H_INCLUDED
#define TRADERALÈATOIRE_H_INCLUDED

#include "Trader.h"

class TraderAleatoire:public Trader{
public:
    Transaction choisirTransaction(const Bourse& bourse,const Portefeuille &portefeuille);
    ~TraderAleatoire(){cout<<"Trader aleatoire Detruit"<<endl;}
};

#endif // TRADERALÈATOIRE_H_INCLUDED
