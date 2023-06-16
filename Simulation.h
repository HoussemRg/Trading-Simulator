#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include<chrono>
#include<map>
#include "Date.h"
#include "Bourse.h"
#include "Portefeuille.h"
#include "Trader.h"
#include "TraderAléatoire.h"
#include "Transaction.h"

class Simulation{
public:
    static map<string,double> executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin,double solde);
};


#endif // SIMULATION_H_INCLUDED
