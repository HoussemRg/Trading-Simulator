#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<chrono>
#include<map>
#include "Date.h"
#include "PrixJournalier.h"
#include "PersistancePrixJournaliers.h"
#include "Bourse.h"
#include "BourseVector.h"
#include "Titre.h"
#include "Portefeuille.h"
#include "Transaction.h"
#include "Trader.h"
#include "TraderAléatoire.h"
#include "Simulation.h"
#include <iomanip>
#include "BourseMmap.h"
#include "TraderAlgorithmique.h"
#include "BourseSet.h"


using namespace std;


int main()
{
    srand(time(NULL));
    PersistancePrixJournaliers p;
    vector<PrixJournalier> historique=p.lirePrixJournaliersDUnFichier("prices_simple.csv");

    Date dateDebut(4,1,2010);
    Date dateFin(4,1,2015);
    Bourse* B=new BourseVector(historique,dateDebut);
    Trader* Tr=new TraderAleatoire;

    //Simulation S;
    //S.executer(*B,*Tr,dateDebut,dateFin,10000);
    //delete B;
    //delete Tr;
    cout<<"Statistiques De BourseVector : "<<endl;
    auto stats = Simulation::executer(*B,*Tr,dateDebut,dateFin,1000);
    for(auto it:stats){
        cout<<it.first<<"\t"<<it.second<<endl;
    }


    /*multimap<Date,PrixJournalier> his;
    for(auto it:historique){
        his.insert(make_pair(it.getDate(),it));
    }
    Date dateDebut(4,1,2010);
    Date dateFin(6,5,2010);
    Bourse* B=new BourseMmap(his,dateDebut);
    Trader* Tr=new TraderAleatoire;
    //Simulation S;
    //S.executer(*B,*Tr,dateDebut,dateFin,1000);
    //delete B;
    //delete Tr;
    cout<<"Statistiques De BourseMultimap : "<<endl;
    auto stats = Simulation::executer(*B,*Tr,dateDebut,dateFin,1000);
    for(auto it:stats){
        cout<<it.first<<"\t"<<it.second<<endl;
    }*/



    /*Date dateDebut(4,1,2010);
    Date dateFin(11,5,2011);
    Bourse* B=new BourseVector(historique,dateDebut);
    Trader* Tr=new TraderAlgorithmique;

    //Simulation S;
    //S.executer(*B,*Tr,dateDebut,dateFin,1000);
    //delete B;
    //delete Tr;

    auto stats = Simulation::executer(*B,*Tr,dateDebut,dateFin,1000);
    for(auto it:stats){
        cout<<it.first<<"\t"<<it.second<<endl;
    }*/


    /*multimap<Date,PrixJournalier> his;
    for(auto it:historique){
        his.insert(make_pair(it.getDate(),it));
    }
    Date dateDebut(4,1,2010);
    Date dateFin(11,5,2011);
    Bourse* B=new BourseMmap(his,dateDebut);
    Trader* Tr=new TraderAlgorithmique;
    //Simulation S;
    //S.executer(*B,*Tr,dateDebut,dateFin,1000);
    //delete B;
    //delete Tr;
    cout<<"Statistiques De BourseMultimap Algorithmique : "<<endl;
    auto stats = Simulation::executer(*B,*Tr,dateDebut,dateFin,1000);
    for(auto it:stats){
        cout<<it.first<<"\t"<<it.second<<endl;
    }*/


    /*set<PrixJournalier> his;
    for(auto it:historique){
        his.insert(it);
    }
    Date dateDebut(4,1,2010);
    Date dateFin(6,5,2010);
    Bourse* B=new BourseSet(his,dateDebut);
    Trader* Tr=new TraderAleatoire;
    //Simulation S;
    //S.executer(*B,*Tr,dateDebut,dateFin,1000);
    //delete B;
    //delete Tr;
    cout<<"Statistiques De BourseSet : "<<endl;
    auto stats = Simulation::executer(*B,*Tr,dateDebut,dateFin,1000);
    for(auto it:stats){
        cout<<it.first<<"\t"<<it.second<<endl;
    }*/

    /*set<PrixJournalier> his;
    for(auto it:historique){
        his.insert(it);
    }
    Date dateDebut(4,1,2010);
    Date dateFin(11,5,2011);
    Bourse* B=new BourseSet(his,dateDebut);
    Trader* Tr=new TraderAlgorithmique;
    //Simulation S;
    //S.executer(*B,*Tr,dateDebut,dateFin,1000);
    //delete B;
    //delete Tr;
    cout<<"Statistiques De BourseSet Algorithmique : "<<endl;
    auto stats = Simulation::executer(*B,*Tr,dateDebut,dateFin,1000);
    for(auto it:stats){
        cout<<it.first<<"\t"<<it.second<<endl;
    }*/

    return 0;
}
