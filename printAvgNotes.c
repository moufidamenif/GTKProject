#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void MainButton3clicked (GtkButton *button3, gpointer user_data) {

        GtkWidget *window3 = gtk_window_new();
        GtkWidget *grid3 = gtk_grid_new();

        gtk_grid_set_row_spacing(GTK_GRID(grid3), 5); // Space between rows
        gtk_grid_set_column_spacing(GTK_GRID(grid3),5);


   GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "frame { "
        "  border: 2px solid black; "
        "  border-radius: 5px; "
        "  padding: 5px; "
        "}", -1);
        GtkWidget *nomPrenomColLabel;
        GtkWidget *avgColLab;
        GtkWidget *framenomPrenomCol = gtk_frame_new(NULL);
        GtkWidget *frameAvgcol  = gtk_frame_new(NULL);
        gtk_widget_set_size_request(framenomPrenomCol, 100, 100);
        gtk_widget_set_size_request(frameAvgcol, 100, 100);
        GtkStyleContext *contextNom = gtk_widget_get_style_context(framenomPrenomCol);
        GtkStyleContext *contextAvg = gtk_widget_get_style_context(frameAvgcol);
        gtk_style_context_add_provider(contextNom, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
        gtk_style_context_add_provider(contextAvg, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
        GtkWidget* labelNomPrenomcol = gtk_label_new("NomPrenom");
                    gtk_frame_set_child(GTK_FRAME(framenomPrenomCol), labelNomPrenomcol);
                    gtk_grid_attach(GTK_GRID(grid3), framenomPrenomCol  , 0, 0, 1, 1);
                    GtkWidget* labelAvg = gtk_label_new("Moyenne ");
                    gtk_frame_set_child(GTK_FRAME(frameAvgcol), labelAvg);
                    gtk_grid_attach(GTK_GRID(grid3), frameAvgcol , 1, 0, 1, 1);







        for (int i=0;i<tab->casesRemplis; i++){

        GtkWidget *nomPrenomLabel;
        GtkWidget *avgLab;
        GtkWidget *framenomPrenom = gtk_frame_new(NULL);
        GtkWidget *frameAvg  = gtk_frame_new(NULL);
        gtk_widget_set_size_request(framenomPrenom, 100, 100);
        gtk_widget_set_size_request(frameAvg, 100, 100);
        GtkStyleContext *context1 = gtk_widget_get_style_context(framenomPrenom);
        GtkStyleContext *context2 = gtk_widget_get_style_context(frameAvg);
        gtk_style_context_add_provider(context1, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
        gtk_style_context_add_provider(context2, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
                    nomPrenomLabel = gtk_label_new(tab->tabNomPrenom[i]);
                    gtk_frame_set_child(GTK_FRAME(framenomPrenom), nomPrenomLabel);
                    gtk_grid_attach(GTK_GRID(grid3), framenomPrenom  , 0, i+1, 1, 1);

                    char * avg =g_strdup_printf("%.2f", (tab->tabNote1[i]*40+tab->tabNote2[i]*60)/100);
                    labelAvg =gtk_label_new(avg);
                        g_free(avg);
                     gtk_frame_set_child(GTK_FRAME(frameAvg), labelAvg);
                    gtk_grid_attach(GTK_GRID(grid3), frameAvg  ,1 , i+1, 1, 1);}



 // Create the button
    GtkWidget *button = gtk_button_new_with_label("quit ");
    gtk_grid_attach(GTK_GRID(grid3), button, 0, 4, 2, 1);
g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window3);
    gtk_window_set_child (GTK_WINDOW (window3), grid3);
    gtk_window_set_title(GTK_WINDOW(window3), "printAvgNotes ");
    gtk_window_set_default_size(GTK_WINDOW(window3), 700, 700);
    gtk_window_present (GTK_WINDOW (window3));

}

