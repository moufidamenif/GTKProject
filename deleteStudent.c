#include <gtk/gtk.h>
#include <unistd.h>
#include "header.h"
void suppresionApprenant (int position );
void on_submit3(GtkWidget *button, gpointer user_data) {
        structSearch *donnes =(structSearch *)user_data;
       GtkWidget* window =donnes->window;
        GtkWidget* entry =donnes->entry ;
     const gchar* position  = gtk_editable_get_text(GTK_EDITABLE(entry));

int pos = atoi(position);
if (pos> tab->casesRemplis|| tab->casesRemplis==0 ){
GtkWidget *grid6 = gtk_grid_new();
                GtkWidget *labelSuppresion ;

                    labelSuppresion = gtk_label_new("nb nn valide ");
                    gtk_grid_attach(GTK_GRID(grid6), labelSuppresion  , 0, 0, 1, 1);

                     GtkWidget *button = gtk_button_new_with_label("quit ");
                    gtk_grid_attach(GTK_GRID(grid6), button, 0, 1, 2, 1);
                    gtk_window_set_child (GTK_WINDOW (window), grid6);
                    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);
}
else if (pos<= tab->casesRemplis) {
        suppresionApprenant(pos);
        g_print("termin�");
        GtkWidget *grid6 = gtk_grid_new();
                GtkWidget *labelSuppresion ;

                    labelSuppresion = gtk_label_new("suppression reussie ");
                    gtk_grid_attach(GTK_GRID(grid6), labelSuppresion  , 0, 0, 1, 1);

                     GtkWidget *button = gtk_button_new_with_label("quit ");
                    gtk_grid_attach(GTK_GRID(grid6), button, 0, 1, 2, 1);
                    gtk_window_set_child (GTK_WINDOW (window), grid6);
                    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);


}
free(donnes);
}
void MainButton5clicked (GtkButton *button5, gpointer user_data) {
    GtkWidget *window5 = gtk_window_new();
        GtkWidget *grid5 = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid5), 5); // Space between rows
        gtk_grid_set_column_spacing(GTK_GRID(grid5), 5);




       GtkWidget *label1 = gtk_label_new("Position");
        gtk_widget_set_halign(label1, GTK_ALIGN_END);
       GtkWidget *entry1=gtk_entry_new();
       gtk_entry_set_placeholder_text(GTK_ENTRY(entry1),NULL);
        gtk_grid_attach(GTK_GRID(grid5), label1, 0, 0, 1, 1);
        gtk_grid_attach(GTK_GRID(grid5), entry1, 1, 0, 1, 1);




 // Create the button
    GtkWidget *button = gtk_button_new_with_label("Submit");
    gtk_grid_attach(GTK_GRID(grid5), button, 0, 1, 2, 1);
     structSearch* donnees =(structSearch *)malloc(sizeof(structSearch));
     donnees->entry= entry1;
     donnees->window =window5;

    g_signal_connect(button, "clicked", G_CALLBACK(on_submit3), donnees);
    //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window4);
    gtk_window_set_child (GTK_WINDOW (window5), grid5);
    gtk_window_set_title(GTK_WINDOW(window5), "searchStudent ");
    gtk_window_set_default_size(GTK_WINDOW(window5), 700, 700);
    gtk_window_present (GTK_WINDOW (window5));

}
