#include <gtk/gtk.h>
#include <unistd.h>
#include "header.h"
int rechercheApprenant (char* aChercher );

void on_submit2(GtkWidget *button, gpointer user_data) {
        structSearch *donnes =(structSearch *)user_data;
       GtkWidget* window =donnes->window;
        GtkWidget* entry =donnes->entry ;
    const gchar* nomChar = gtk_editable_get_text(GTK_EDITABLE(entry));
     char *  nomChar2 =(char*)nomChar;
g_print("Nom: %s\n", nomChar);

int j=rechercheApprenant(nomChar2);
if (j==-1){
         gtk_window_destroy(GTK_WINDOW(window));
}
else {
        GtkWidget *grid5 = gtk_grid_new();
                GtkWidget *labelNomPrenom;
                GtkWidget *labelAge;
                GtkWidget *labelNote1;
                GtkWidget *labelNote2;
                    labelNomPrenom = gtk_label_new(tab->tabNomPrenom[j]);
                    gtk_grid_attach(GTK_GRID(grid5), labelNomPrenom  , 0, 0, 1, 1);


                    char * ageStr = g_strdup_printf("%d", tab->tabAge[j]);
                        labelAge = gtk_label_new(ageStr);
                            g_free(ageStr);
                    gtk_grid_attach(GTK_GRID(grid5), labelAge  , 1, 0, 1, 1);

                    char *NoteStr1 = g_strdup_printf("%.2f", tab->tabNote1[j]);
                    labelNote1 = gtk_label_new(NoteStr1);
                    g_free(NoteStr1);
                    gtk_grid_attach(GTK_GRID(grid5), labelNote1 , 2, 0, 1, 1);
                    char * NoteStr2 = g_strdup_printf("%.2f", tab->tabNote2[j]);
                    labelNote2 = gtk_label_new(NoteStr2);
                    g_free(NoteStr2);
                    gtk_grid_attach(GTK_GRID(grid5), labelNote2 , 3, 0, 1, 1);
                     GtkWidget *button = gtk_button_new_with_label("quit ");
                    gtk_grid_attach(GTK_GRID(grid5), button, 0, 4, 2, 1);
                    gtk_window_set_child (GTK_WINDOW (window), grid5);
                    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);


}
free(donnes);
}
void MainButton4clicked (GtkButton *button4, gpointer user_data) {
    GtkWidget *window4 = gtk_window_new();
        GtkWidget *grid4 = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid4), 5); // Space between rows
        gtk_grid_set_column_spacing(GTK_GRID(grid4), 5);




       GtkWidget *label1 = gtk_label_new("NomPrenom");
        gtk_widget_set_halign(label1, GTK_ALIGN_END);
       GtkWidget *entry1=gtk_entry_new();
       gtk_entry_set_placeholder_text(GTK_ENTRY(entry1),NULL);
        gtk_grid_attach(GTK_GRID(grid4), label1, 0, 0, 1, 1);
        gtk_grid_attach(GTK_GRID(grid4), entry1, 1, 0, 1, 1);




 // Create the button
    GtkWidget *button = gtk_button_new_with_label("Submit");
    gtk_grid_attach(GTK_GRID(grid4), button, 0, 1, 2, 1);
     structSearch* donnees =(structSearch *)malloc(sizeof(structSearch));
     donnees->entry= entry1;
     donnees->window =window4;

    g_signal_connect(button, "clicked", G_CALLBACK(on_submit2), donnees);
    //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window4);
    gtk_window_set_child (GTK_WINDOW (window4), grid4);
    gtk_window_set_title(GTK_WINDOW(window4), "searchStudent ");
    gtk_window_set_default_size(GTK_WINDOW(window4), 700, 700);
    gtk_window_present (GTK_WINDOW (window4));

}
