#include "gestionDemande.h"
#include <stdio.h>
#include<string.h>
#include <stdlib.h>

enum{EID,
     EETAB,
     EDATEJJ,
     EDATEMM,
     EDATEYY,
     EQUANTITE,
     ETYPESANG,
     EURGENCE,
     ESTATUS,
     COLUMNS
      };





void afficherDemande(GtkWidget *liste, char *filename){

     GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Demande d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQUANTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPESANG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cas urgence", renderer, "text", EURGENCE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ESTATUS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {

         sprintf(jj,"%d",d.date.jj);
         sprintf(mm,"%d",d.date.mm);
         sprintf(yy,"%d",d.date.yy);
          sprintf(quantite,"%d",d.quantite);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, d.id,  EETAB, d.etab, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EQUANTITE,quantite,ETYPESANG,d.typeSang,EURGENCE,d.urgence,ESTATUS,d.status,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }

}
void viderDemande(GtkWidget *liste){

     GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste


    store = NULL;
  
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQUANTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPESANG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cas urgence", renderer, "text", EURGENCE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ESTATUS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,COLUMNS);



}

void rechercherDemande(GtkWidget *liste, char *filename,char *id[50]){




   GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Demande d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQUANTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPESANG, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cas urgence", renderer, "text", EURGENCE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ESTATUS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
             if(strcmp(d.id,id)==0){
         sprintf(jj,"%d",d.date.jj);
         sprintf(mm,"%d",d.date.mm);
         sprintf(yy,"%d",d.date.yy);
          sprintf(quantite,"%d",d.quantite);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, d.id,  EETAB, d.etab, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EQUANTITE,quantite,ETYPESANG,d.typeSang,EURGENCE,d.urgence,ESTATUS,d.status,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }










}





















int ajouterDemande(char *filename,Demande d){

     FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.status);

        fclose(f);
        return 1;
    }
    else return 0;

}

int modifierDemande(char *filename,char *id,Demande nouv){


 int tr=0;
    Demande d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            if(strcmp(d.id,id)== 0)
            {
                fprintf(f2,"%s %s %s %s %d %d %d %d %s \n",nouv.id,nouv.etab,nouv.typeSang,nouv.urgence,nouv.quantite,nouv.date.jj,nouv.date.mm,nouv.date.yy,nouv.status);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.status);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerDemande(char *filename,char *id){

int tr=0;
    Demande d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            if(strcmp(d.id,id)== 0)
            {

                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.status);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}


Demande chercherDemande(char *filename, char *id){
 Demande d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            if(strcmp(d.id,id)== 0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
      strcpy(d.id,"-1");
    return d;







}


float afficherPourcentageDemandes(char *filename, char *etab){

float poucentageDemande = 0;
 Demande d;
    int nombreDemande=0;
    int nombreEtabil=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {
            nombreDemande++;

            if (strcmp(d.etab,etab)== 0)
            {
                nombreEtabil++;
            }




        }

    }
    fclose(f);

    if (nombreDemande > 0)
    {
        poucentageDemande = (float)nombreEtabil / (float)nombreDemande * 100;

    return poucentageDemande;
    }

    return poucentageDemande;

}


int quantiteDemandeType(char *filename,char *typeSang){


   Demande d;
   int quantiteTotale=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %d %d %d %d %s \n",d.id,d.etab,d.typeSang,d.urgence,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.status)!=EOF)
        {


            if (strcmp(d.typeSang, typeSang) == 0)
            {
               quantiteTotale+=d.quantite;
            }




        }

    }
    fclose(f);

     return quantiteTotale;
}


char* afficherTypeSangPlusDemande(char *filename ){
       char typesSangConnus[][5] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    int maxQuantite = 0;
    char sangPlusDemande[5] = "";
 Demande d;
         for(int i =0; i<8;i++){

            int quantite = quantiteDemandeType(filename,typesSangConnus[i]);
             if (quantite > maxQuantite) {
            maxQuantite = quantite;
            strcpy(sangPlusDemande, typesSangConnus[i]);
            }








}
  char *resultat = (char *)malloc((strlen(sangPlusDemande) + 1) * sizeof(char));

   strcpy(resultat,sangPlusDemande);
return resultat;

}
