#include "TraderAléatoire.h"
#include<cmath>


Transaction TraderAleatoire::choisirTransaction(const Bourse& bourse,const Portefeuille &portefeuille){
        if(portefeuille.getTitre().size()==0){
            TypeTx type= Achat;
            vector<PrixJournalier> v=bourse.getPrixJournalierParDateEtPrix(portefeuille.getSolde());
            if(v.size()!=0){
               int index=rand()%v.size();
               string nt=v[index].getNomAction();
               double pr=v[index].getPrix();
               double qte_transaction=(rand()%((int)(floor(portefeuille.getSolde()/pr)))+1);
               Titre t(nt,qte_transaction);
               Transaction T(t,type);
               return T;
            }
            else{
              Transaction T;
              return T;
            }

        }
        else{
            TypeTx type = static_cast<TypeTx>(rand()%3);
            if(type==Achat){
                vector<PrixJournalier> v=bourse.getPrixJournalierParDateEtPrix(portefeuille.getSolde());
                if(portefeuille.getTitre().size()==0){
                    int index=rand()%v.size();
                    string nt=v[index].getNomAction();
                    double pr=v[index].getPrix();
                    double qte_transaction=(rand()%((int)(floor(portefeuille.getSolde()/pr)))+1);
                    Titre t(nt,qte_transaction);
                    Transaction T(t,type);
                    return T;
                }
                else{
                    Transaction T;
                    return T;
                }
            }
            else if(type==Vente){
                string nt=portefeuille.getTitre()[rand()%portefeuille.getTitre().size()].getNomAction();
                double qte_transaction=(rand()%((int)(floor(portefeuille.getQuantiteParNomAction(nt)))+1));
                Titre t(nt,qte_transaction);
                Transaction T(t,type);
                return T;
            }
            else{
                Transaction T;
                return T;
                cout<<T<<endl;
            }
        }
    }




