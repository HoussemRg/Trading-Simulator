#include "Simulation.h"


map<string,double> Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin,double solde){
    map<string, double> stats;
    stats["MON_COMPTEUR"]++;
    auto start = chrono::high_resolution_clock::now();
    Portefeuille portefeuille(solde);
    Date dateCourante=dateDebut;
    int nbAchat=0;
    int nbVente=0;
    while(dateCourante<=dateFin){
        bourse.setDateAujourdhui(dateCourante);
        int i=0;
        Transaction T;
        do{
            auto start1 = chrono::high_resolution_clock::now();
            T=trader.choisirTransaction(bourse,portefeuille);
            //cout<<T<<endl;
            auto stop1 = chrono::high_resolution_clock::now();
            auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
            stats["TEMPS_Choisir_Transaction_탎"]+=duration1.count();
            if(T.getType()==Achat){
                    auto start2 = chrono::high_resolution_clock::now();
                    vector<PrixJournalier> v=bourse.getPrixJournalierParDateEtPrix(portefeuille.getSolde());
                    auto stop2 = chrono::high_resolution_clock::now();
                    auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
                    stats["TEMPS_Get_PrixJournalier_Par_Date_Et_Prix_탎"]+=duration2.count();
                    Titre t=T.getTitre();
                    double pr=bourse.getPrixParNomAction(v,t.getNomAction());
                    bool b=portefeuille.ajouterTitre(t);
                    if(b){
                        portefeuille.retirerMonatant(t.getQte()*pr);
                        nbAchat++;
                    }
            }
            else if(T.getType()==Vente){
                    auto start3 = chrono::high_resolution_clock::now();
                    vector<double> v2=bourse.getPrixParDateEtNomAction(T.getTitre().getNomAction());
                    auto stop3 = chrono::high_resolution_clock::now();
                    auto duration3 = chrono::duration_cast<chrono::microseconds>(stop3 - start3);
                    stats["TEMPS_Get_Prix_Par_Nom_Action_탎"]+=duration3.count();
                    if(v2.size()!=0){
                        double pr=v2[v2.size()-1];
                        Titre t=T.getTitre();
                        bool b=portefeuille.retirerTitre(t);
                        if(b){
                           portefeuille.deposerMontant(t.getQte()*pr);
                           nbVente++;
                        }
                    }
                    else{
                    }
            }
            else{
            }
            i++;
        }while(i<100 && T.getType()!=Rien);
        cout<<dateCourante<<endl;
        dateCourante.incrementerDate();
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    stats["TEMPS_SIMULATION_탎"]+=duration.count();
    for(auto it:portefeuille.getTitre()){
            vector<double> v1=bourse.getPrixParDateEtNomAction(it.getNomAction());
            if(v1.size()!=0){
                portefeuille.deposerMontant((it.getQte())*v1[v1.size()-1]);
                portefeuille.retirerTitre(it);
            }
            else{
                portefeuille.retirerTitre(it);
            }
    }
    stats["Nbre_Transactions"]=nbAchat+nbVente;
    stats["Solde_Final"]=portefeuille.getSolde();
    stats["Nombre_d_Achats"]=nbAchat;
    stats["Nombre_de_Vente"]=nbVente;
    double gain=portefeuille.getSolde()-solde;
    double rendement=gain/solde;
    double TauxDeRendement=rendement*100;
    stats["Gain"]=gain;
    stats["Rendement"]=rendement;
    stats["Taux_de_Rendement_en_%"]=TauxDeRendement;
    return stats;
}
