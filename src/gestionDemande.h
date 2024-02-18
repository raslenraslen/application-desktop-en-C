#ifndef GESTIONDEMANDE_H_INCLUDED
#define GESTIONDEMANDE_H_INCLUDED
#include <gtk/gtk.h>
typedef struct {
 int jj;
 int mm;
 int yy;
}Date;
typedef struct {
 char id[50];
 char etab[50];

 char typeSang[50];
 char urgence[50];

 int quantite;
 Date date;
 char status[50];

}Demande;
void afficherDemande(GtkWidget *liste, char *filename);
void viderDemande(GtkWidget *liste);
int ajouterDemande(char *,Demande);
int modifierDemande(char *,char *,Demande);
int supprimerDemande(char *,char *);
Demande chercherDemande(char *, char *);
float afficherPourcentageDemandes(char *,char *);
int quantiteDemandeType(char *,char *);
char*  afficherTypeSangPlusDemande(char *);
void rechercherDemande(GtkWidget *liste, char *filename,char *id[50]);
#endif // GESTIONDEMANDE_H_INCLUDED
