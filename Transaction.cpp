#include "Transaction.h"

Transaction::Transaction(Titre t,TypeTx T):titre(t),type(T){}


Titre Transaction::getTitre() const{
    return this->titre;
}

TypeTx Transaction::getType() const{
    return this->type;
}


ostream& operator<<(ostream& flux,const Transaction& t){
    cout<<"Type De Transaction : "<<t.type<<endl;
    cout<<"Titre de Transaction : "<<endl<<t.titre<<endl;

    return flux;
}
