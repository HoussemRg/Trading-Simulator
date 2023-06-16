#include "TraderAlgorithmique.h"
#include<cmath>


Transaction TraderAlgorithmique::choisirTransaction(const Bourse& bourse,const Portefeuille &portefeuille){
        Date d=bourse.getDateAujourdhui();
        if(d.getDay()%5!=0){
            TypeTx type=Achat;
            vector<PrixJournalier> v=bourse.getPrixJournalierParDateEtPrix(portefeuille.getSolde());
            if(v.size()!=0){
                string nt=v[v.size()-1].getNomAction();
                double pr=v[v.size()-1].getPrix();
                double qte_transaction=(int)(floor((portefeuille.getSolde()/pr)));
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
            if(portefeuille.getTitre().size()!=0){
                TypeTx type=Vente;
                string nt=portefeuille.getTitre()[0].getNomAction();
                double qte_transaction=(portefeuille.getTitre()[0].getQte());
                Titre t(nt,qte_transaction);
                Transaction T(t,type);
                return T;
            }
            else{
                Transaction T;
                return T;
            }
        }
}

