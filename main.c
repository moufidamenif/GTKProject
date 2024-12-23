#include<gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"

tableaux * tab ;
void  createDynamicArray(int capacity);
void MainButton1clicked (GtkWidget *button1, gpointer user_data);
void MainButton2clicked (GtkWidget *button2, gpointer user_data);
void MainButton3clicked (GtkWidget *button3, gpointer user_data);
void MainButton4clicked (GtkButton *button4, gpointer user_data);
void MainButton5clicked (GtkButton *button5, gpointer user_data);
void MainButton6clicked (GtkButton *button6, gpointer user_data);
void MainButton7clicked (GtkButton *button7, gpointer user_data);
static void activate (GtkApplication *app,gpointer user_data){
  int capacity;
    capacity=5;
    tab=(tableaux*)malloc(capacity*sizeof(tableaux));
    createDynamicArray(capacity);
  GtkWidget *window;
  GtkWidget *button1 ;
  GtkWidget *button2 ;
  GtkWidget *button3 ;
  GtkWidget *button4 ;
  GtkWidget *button5 ;
  GtkWidget *button6 ;
  GtkWidget *button7 ;
  GtkWidget *button8 ;
  GtkWidget *box;


  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Students Management ");
  gtk_window_set_default_size (GTK_WINDOW (window), 1000, 1000);

  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 20);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

    button1 = gtk_button_new_with_label ("creez un nouveau dossier");
    button2 = gtk_button_new_with_label ("afficher la liste des etudiants");
    button3 = gtk_button_new_with_label ("afficher la moyenne des notes des etudiants");
    button4 = gtk_button_new_with_label ("Rechercher un dossier");
    button5 = gtk_button_new_with_label ("supprimer un dossier");
    button6 = gtk_button_new_with_label ("enregistrer les apprenants dans un fichier");
    button7 = gtk_button_new_with_label ("charger un fichier");
    button8=gtk_button_new_with_label ("quittez le programme");


    g_signal_connect (button1, "clicked", G_CALLBACK (MainButton1clicked ), NULL);
    g_signal_connect (button2, "clicked", G_CALLBACK (MainButton2clicked ), NULL);
    g_signal_connect (button3, "clicked", G_CALLBACK (MainButton3clicked ), NULL);
    g_signal_connect (button4, "clicked", G_CALLBACK (MainButton4clicked ), NULL);
    g_signal_connect (button5, "clicked", G_CALLBACK (MainButton5clicked ), NULL);
    g_signal_connect (button6, "clicked", G_CALLBACK (MainButton6clicked ), NULL);
    g_signal_connect (button7, "clicked", G_CALLBACK (MainButton7clicked ), NULL);

    g_signal_connect_swapped (button8, "clicked", G_CALLBACK (gtk_window_destroy), window);

    gtk_box_append (GTK_BOX (box), button1);
    gtk_box_append (GTK_BOX (box), button2);
    gtk_box_append (GTK_BOX (box), button3);
    gtk_box_append (GTK_BOX (box), button4);
    gtk_box_append (GTK_BOX (box), button5);
    gtk_box_append (GTK_BOX (box), button6);
    gtk_box_append (GTK_BOX (box), button7);
    gtk_box_append (GTK_BOX (box), button8);

     GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "window { "
        "  background-image: linear-gradient(to bottom, #1e5799 0%,#2989d8 50%,#7db9e8 100%); "
        "}", -1);
        GtkStyleContext *contextWindow = gtk_widget_get_style_context(window);


        gtk_style_context_add_provider(contextWindow, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);


    gtk_window_present (GTK_WINDOW (window));
}

int main (int argc,char **argv)
{  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
 free(tab->tabAge);
    for (int i=0; i<tab->capacite;i++){
         free(tab->tabNomPrenom[i]);
    }
    free(tab->tabNomPrenom);
    free(tab->tabNote1);
    free(tab->tabNote2);
    free(tab);
  return status;
}

