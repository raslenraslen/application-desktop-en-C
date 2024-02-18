#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gestionDemande.h"
int urgence1 ;
int status1;
int urgence2;
int status2;
char filename2[50]="gestionDemande.txt";
void
on_treeviewGD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   
}


void
on_GDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
     
}


void
on_GDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDstatistique,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDstatistique = lookup_widget(button,"GDstatistique");
     GDstatistique = create_GDstatistique();
     gtk_widget_show(GDstatistique);

}


void
on_GDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDaffiche,*w1,*treeview;
      w1=lookup_widget(button,"GDaffiche");
      GDaffiche=create_GDaffiche();
       gtk_widget_show(GDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);

}


void
on_GDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDsupprime,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDsupprime = lookup_widget(button,"GDsupprime");
     GDsupprime = create_GDsupprime();
     gtk_widget_show(GDsupprime);
}


void
on_GDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *GDmodife,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDmodife = lookup_widget(button,"GDmodife");
     GDmodife = create_GDmodife();
     gtk_widget_show(GDmodife);
}


void
on_GDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDajoute,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDajoute = lookup_widget(button,"GDajoute");
     GDajoute = create_GDajoute();
     gtk_widget_show(GDajoute);
}


void
on_GDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *id ,*GDaffiche,*pInfo,*w1,*treeview;
    
           int b = 1;
         char id1[50];
         GDaffiche  = lookup_widget(button,"GDaffiche");
           GDaffiche = create_GDaffiche();
        id = lookup_widget(button,"GDsearchEntry"); 
        
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
            pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
             }else{
                w1=lookup_widget(button,"GDaffiche");
      GDaffiche=create_GDaffiche();
       gtk_widget_show(GDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       rechercherDemande(treeview,filename2,id1);

           }
}


void
on_GDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDsupprime,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
   char id1[50];
   GDsupprime = lookup_widget(button,"GDsupprime");
           GDsupprime = create_GDsupprime();
   id = lookup_widget(button,"GDidEntrySupprimer"); 
    label = lookup_widget(button,"GDcontroleSaisiSupprimer");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
        if(strcmp(id1,"")==0 ){
      
           b=0;
             }
                            if(b == 1){
       int t =  supprimerDemande(filename2,id1);
       if(t == 1){
      
          
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDsupprime);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);
          


        
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed Supprimer  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
   
}


void
on_GDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDsupprime,*GDaffiche;
     GDsupprime = lookup_widget(button,"GDsupprime");
   gtk_widget_destroy(GDsupprime);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *GDajoute,*GDaffiche;
     GDajoute = lookup_widget(button,"GDajoute");
   gtk_widget_destroy(GDajoute);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}

void
on_GDTraiteStatusAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status1=2;} 
}


void
on_GDCoursStatusAjout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(togglebutton))
 {status1=1;} 
}  


void
on_GDnonUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence1=2;} 
}


void
on_GDouiUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence1=1;} 
}


void
on_GDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDajoute,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
  Demande d;
   GDajoute = lookup_widget(button,"GDajoute");
           GDajoute = create_GDajoute();
   id = lookup_widget(button,"GDidEntryAjout"); 
 etab= lookup_widget(button,"GDetabComboAjout1");
 jj =  lookup_widget(button,"GDjjSpinAjout");
        mm =  lookup_widget(button,"GDmmSpinAjout");
        yy =   lookup_widget(button,"GDyySpinAjout");
        quantite = lookup_widget(button,"GDquantiteSpinAjout");
        sangType =  lookup_widget(button,"GDtypeSangComboAjout1");
        label = lookup_widget(button,"GDcontroleSaisiAjout");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
         d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sangType)));
         if(urgence1 == 1){
          strcpy(d.urgence,"oui");
         }else{
         strcpy(d.urgence,"non");
         }
          if(status1 == 1){
          strcpy(d.status,"encours");
         }else {
         strcpy(d.status,"traite");
         }
          if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
               if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

                         if(b == 1){
       int t =  ajouterDemande(filename2,d);
       if(t == 1){
        
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDajoute);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);
              


 
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


           
}



void
on_GDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDmodife,*GDaffiche;
     GDmodife = lookup_widget(button,"GDmodife");
   gtk_widget_destroy(GDmodife);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDouiUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence2=1;}
}


void
on_GDnonUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence2=2;}
}


void
on_GDTraiteStatusModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status2=2;}
}


void
on_GDCoursStatusModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status2=1;}
}


void
on_GDModifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDmodife,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
  Demande d;
   GDmodife = lookup_widget(button,"GDmodife");
           GDmodife = create_GDmodife();
   id = lookup_widget(button,"GDidEntryModifier"); 
 etab= lookup_widget(button,"GDetabComboModifier1");
 jj =  lookup_widget(button,"GDjjSpinModifier");
        mm =  lookup_widget(button,"GDmmSpinModifier");
        yy =   lookup_widget(button,"GDyySpinModifier");
        quantite = lookup_widget(button,"GDquantiteSpinModifier");
        sangType =  lookup_widget(button,"GDtypeSangComboModifier1");
        label = lookup_widget(button,"GDcontroleSaisiModifier");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
         d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sangType)));
         if(urgence2 == 1){
          strcpy(d.urgence,"oui");
         }else{
         strcpy(d.urgence,"non");
         }
          if(status2 == 1){
          strcpy(d.status,"encours");
         }else {
         strcpy(d.status,"traite");
         }
          if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
               if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

                         if(b == 1){
       int t =  modifierDemande(filename2,d.id,d);
       if(t == 1){
        
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDmodife);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,filename2);
              


       
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed Modification  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


}


void
on_GDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *label;
   label = lookup_widget(button,"GDtypePlusDemandeLabelStatistique");
    gtk_label_set_text(GTK_LABEL(label),afficherTypeSangPlusDemande(filename2));
}


void
on_GDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDstatistique,*GDaffiche;
     GDstatistique = lookup_widget(button,"GDstatistique");
   gtk_widget_destroy(GDstatistique);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDsearchModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_GDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget  *etab,*label1,*labelControlle,*GDstatistique;
      GDstatistique = lookup_widget(button,"GDstatistique");
           GDstatistique = create_GDstatistique();
    int b=1;
char etab1[50];
   etab = lookup_widget(button,"GDcomboEtabStatistique"); 
   label1 = lookup_widget(button,"GDpourcentageDemandeLabelStatistique");
    labelControlle = lookup_widget(button,"GDcontroleSaisiStatistique"); 
    strcpy(etab1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        if(strcmp(etab1,"")==0 ){
      
           b=0;
             }
         if (b == 1){
       float pourcentage = afficherPourcentageDemandes(filename2,etab1);
       char var[50];
    sprintf(var,"%.2f",pourcentage);

         gtk_label_set_text(GTK_LABEL(label1),var);


         }else{


           gtk_label_set_text(GTK_LABEL(labelControlle),"verifier vos donnée ❌️");

        }
     
}

