#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include "Bourse.h"
#include "Transaction.h"
#include "Portefeuille.h"

class Trader{
public:
    string nomTrader;
    virtual Transaction choisirTransaction(const Bourse& bourse,const Portefeuille &portefeuille)=0;
    virtual ~Trader(){cout<<"Trader detruit"<<endl;}
};


#endif // TRADER_H_INCLUDED
