#include <gtk/gtk.h>


void
on_treeviewGD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_GDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDTraiteStatusAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDCoursStatusAjout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDnonUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDouiUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDouiUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDnonUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDTraiteStatusModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDCoursStatusModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDModifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsearchModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data);
