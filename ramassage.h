#ifndef RAMASSAGE_H
#define RAMASSAGE_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
class Ramassage
{
    QString ID_Chauffeur;
    QString ID_Ramassage;
    QString Matricule;
    QString Nom_cartier;
    QTime H_depart;
    QTime Duree;
    QDate Date;
    QString Nb_Poubelle;
    QString Id_empl1;
    QString Id_empl2;


public:
    Ramassage();
    //Ajouter un constructeur avec paramètres

QString getIdchauffeur()
{return ID_Chauffeur; }
QString getId_empl1()
{return Id_empl1; }
QString getId_empl2()
{return Id_empl2; }
QString getId_Ramassage()
{return ID_Ramassage; }
QString getMatricule()
{return Matricule; }
QString getNom_cartier()
{return Nom_cartier; }
QTime getHdepart()
{return H_depart;}
QTime getDuree()
{return Duree;}
QDate getDate()
{return Date;}
QString getNbPoubelle()
{return Nb_Poubelle;}
void setIdChauffeur(QString ch)
{ID_Chauffeur=ch;}
void setId_empl1(QString ch1)
{Id_empl1=ch1;}
void setId_empl2(QString ch2)
{Id_empl2=ch2;}
void setMatricule(QString m)
{Matricule=m;}
void setNom_cartier(QString ad)
{Nom_cartier=ad;}
void setHdepart(QTime h)
{H_depart=h; }
void setDuree(QTime d)
{Duree=d; }
void setDate(QDate d)
{Date=d;}
void setId_Ramassage(QString r)
{ID_Ramassage=r; }
void setNb_Poubelle(QString nb)
{Nb_Poubelle=nb;}


bool ajouter();
QSqlQueryModel* afficher();
void Remplissage(QString*,QString*,QString*,QString*,QString*,QString*,QString*,QString*,QString*,QString*);
bool Supprimer(QString ID);
bool Modifier(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
bool Recherche(QString*,QString*,QString*,QString*,QString*,QString*,QString*,QString*,QString*,QString*);
};

#endif // RAMASSAGE_H
