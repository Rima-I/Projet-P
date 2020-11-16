#include "ramassage.h"
#include"connection.h"

#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QModelIndex>
Ramassage::Ramassage()
{}


bool Ramassage::ajouter()
{



      QSqlQuery query;


      query.prepare("insert into RAMASSAGE (ID_RAMASSAGE,MATRICULE_CAMION,ID_CHAUFFEUR,ID_EMPLOYER1,ID_EMPLOYER2,DATE_RAMASSAGE,"
                          "NOMBRE_POUBELLE,DUREE,NOM_CARTIER,HEURE_DEBUT) values(:id,:Matricule,:ID_chauffeur,:ID_empl1,:ID_empl2,:date,:nb_p,:duree,:cartier,:heure)");
query.bindValue(":id",getId_Ramassage());
query.bindValue(":Matricule",getMatricule());
query.bindValue(":ID_chauffeur",getIdchauffeur());
query.bindValue(":ID_empl1",getId_empl1());
query.bindValue(":ID_empl2",getId_empl2());
query.bindValue(":date",getDate().toString());
query.bindValue(":nb_p",getNbPoubelle());
query.bindValue(":duree",getDuree().toString());
query.bindValue(":cartier",getNom_cartier());
query.bindValue(":heure", getHdepart().toString());

return query.exec();

}


QSqlQueryModel * Ramassage ::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT ID_RAMASSAGE FROM RAMASSAGE ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));


return model;
}


void Ramassage::Remplissage(QString* ID,QString*Matricule,QString*Id_chauffeur,QString* id_empl1,QString* id_empl2,QString*Date,QString*Nb_poubelle,QString*Nom_Cartier,QString*Duree,QString*Heure)
{

    QSqlQuery q;

   q.prepare("select * from RAMASSAGE where ID_RAMASSAGE='"+*ID+"'");

    if(q.exec())
    {
        while(q.next())
        {
*ID= q.value(0).toString();
*Matricule=q.value(1).toString();
*Id_chauffeur=q.value(2).toString();
*id_empl1=q.value(3).toString();
*id_empl2=q.value(4).toString();
*Date   =q.value(5).toString();
*Nb_poubelle  =q.value(6).toString();
*Duree  =q.value(7).toString();
*Nom_Cartier  =q.value(8).toString();
*Heure=q.value(9).toString();

}
    }



}

bool Ramassage::Supprimer(QString ID)
{

    QSqlQuery query;
    query.prepare("Delete from RAMASSAGE where ID_RAMASSAGE = :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}


bool Ramassage::Modifier(QString ID, QString Matricule, QString Id_chauffeur, QString id_empl1, QString id_empl2, QString Date, QString Nb_poubelle, QString Nom_cartier, QString Duree, QString Heure)
{
    QSqlQuery query;



query.prepare("update RAMASSAGE set MATRICULE_CAMION= :Matricule,ID_CHAUFFEUR= :ID_chauffeur,ID_EMPLOYER1= :id_empl1,ID_EMPLOYER2= :id_empl2"
          ",DATE_RAMASSAGE= :date,NOMBRE_POUBELLE= :nb_p,DUREE= :duree,NOM_CARTIER= :cartier,HEURE_DEBUT= :heure where ID_RAMASSAGE= :ID");

query.bindValue(":ID",ID);
query.bindValue(":Matricule",Matricule);
query.bindValue(":ID_chauffeur",Id_chauffeur);
query.bindValue(":id_empl1",id_empl1);
query.bindValue(":id_empl2",id_empl2);
query.bindValue(":date",Date);
query.bindValue(":nb_p",Nb_poubelle);
query.bindValue(":duree",Duree);
query.bindValue(":cartier",Nom_cartier);
query.bindValue(":heure", Heure);

query.exec();
       return   query.exec();

}
bool Ramassage::Recherche(QString* ID,QString*Matricule,QString*Id_chauffeur,QString* id_empl1,QString* id_empl2,QString*Date,QString*Nb_poubelle,QString*Nom_Cartier,QString*Duree,QString*Heure)
{
QSqlQuery q;

   q.prepare("select * from RAMASSAGE where ID_RAMASSAGE= :identifiant");
q.bindValue(":identifiant",*ID);

    if(q.exec())
    {
        while(q.next())
        {
            *ID= q.value(0).toString();
            *Matricule=q.value(1).toString();
            *Id_chauffeur=q.value(2).toString();
            *id_empl1=q.value(3).toString();
            *id_empl2=q.value(4).toString();
            *Date   =q.value(5).toString();
            *Nb_poubelle  =q.value(6).toString();
            *Duree  =q.value(7).toString();
            *Nom_Cartier  =q.value(8).toString();
            *Heure=q.value(9).toString();

}

}

return q.exec();
}
