#ifndef TRADERALGORITHMIQUE_H_INCLUDED
#define TRADERALGORITHMIQUE_H_INCLUDED

#include "Trader.h"

class TraderAlgorithmique:public Trader{
public:
    Transaction choisirTransaction(const Bourse& bourse,const Portefeuille &portefeuille);
    ~TraderAlgorithmique(){cout<<"Trader Algorithmique Detruit"<<endl;}
};

#endif // TRADERALGORITHMIQUE_H_INCLUDED
