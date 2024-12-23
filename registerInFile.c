#include <gtk/gtk.h>
#include <unistd.h>
#include "header.h"
FILE* enregistrementFichier(char *nomFichier);
void on_submit4(GtkWidget *button, gpointer user_data) {
        structSearch *donnes =(structSearch *)user_data;
       GtkWidget* window =donnes->window;
        GtkWidget* entry =donnes->entry ;
     const gchar* nomFile = gtk_editable_get_text(GTK_EDITABLE(entry));
     char *nomFichier=g_strdup(nomFile); 
 FILE*   fp= enregistrementFichier(nomFichier);
 if (fp!=NULL)
{
    GtkWidget *grid = gtk_grid_new();
                GtkWidget *labelConfirmation;
                    labelConfirmation = gtk_label_new("enregistrement reussi");
                    gtk_grid_attach(GTK_GRID(grid), labelConfirmation  , 0, 0, 1, 1);
                    gtk_window_set_child (GTK_WINDOW (window), grid);

}
fclose(fp);
free(donnes);
free(nomFichier);
}
void MainButton6clicked (GtkButton *button6, gpointer user_data) {
    GtkWidget *window7 = gtk_window_new();
        GtkWidget *grid7 = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid7), 5); // Space between rows
        gtk_grid_set_column_spacing(GTK_GRID(grid7), 5);

                GtkWidget *labelNomFile;

                    labelNomFile = gtk_label_new("the file name ");
                     GtkWidget *entryNomfile=gtk_entry_new();
                    gtk_entry_set_placeholder_text(GTK_ENTRY(entryNomfile),NULL);


                    gtk_grid_attach(GTK_GRID(grid7), labelNomFile, 0, 0, 1, 1);
                    gtk_grid_attach(GTK_GRID(grid7), entryNomfile, 1, 0, 1, 1);

                     GtkWidget *button = gtk_button_new_with_label("register in file  ");
                    gtk_grid_attach(GTK_GRID(grid7), button, 0, 4, 2, 1);

                    structSearch * entries =(structSearch*)malloc(sizeof(structSearch));
                    entries->entry =entryNomfile;
                    entries->window=window7;
                     g_signal_connect(button, "clicked", G_CALLBACK(on_submit4), entries);
                  //  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

    gtk_window_set_child (GTK_WINDOW (window7), grid7);
    gtk_window_set_title(GTK_WINDOW(window7), "register in file  ");
    gtk_window_set_default_size(GTK_WINDOW(window7), 700, 700);
    gtk_window_present (GTK_WINDOW (window7));

}
