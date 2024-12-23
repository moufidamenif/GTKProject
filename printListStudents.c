#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void MainButton2clicked (GtkButton *button2, gpointer user_data) {

        GtkWidget *window2 = gtk_window_new();
        GtkWidget *grid2 = gtk_grid_new();

        gtk_grid_set_row_spacing(GTK_GRID(grid2), 5); // Space between rows
        gtk_grid_set_column_spacing(GTK_GRID(grid2),5);




         GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "frame { "
        "  border: 2px solid black; "
        "  border-radius: 5px; "
        "  padding: 5px; "
        "}", -1);


                GtkWidget *nomPrenomColLabel;
                GtkWidget *ageColLab;
                GtkWidget *note1ColLabel;
                GtkWidget *note2ColLab;

                GtkWidget *framenomPrenomCol = gtk_frame_new(NULL);
                GtkWidget *frameageCol = gtk_frame_new(NULL);
                GtkWidget *framenote1Col = gtk_frame_new(NULL);
                GtkWidget *framenote2Col = gtk_frame_new(NULL);
                gtk_widget_set_size_request(framenomPrenomCol, 100, 100);
                  // Set the size of each cell
                gtk_widget_set_size_request(frameageCol, 100, 100);
                gtk_widget_set_size_request(framenote1Col, 100, 100);
                gtk_widget_set_size_request(framenote2Col, 100, 100);

            // Apply CSS styling to the frame
            GtkStyleContext *contextNom = gtk_widget_get_style_context(framenomPrenomCol);
            GtkStyleContext *contextAge = gtk_widget_get_style_context(frameageCol);
            GtkStyleContext *contextNote1 = gtk_widget_get_style_context(framenote1Col);
            GtkStyleContext *contextNote2 = gtk_widget_get_style_context(framenote2Col);

            gtk_style_context_add_provider(contextNom, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_style_context_add_provider(contextAge, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_style_context_add_provider(contextNote1, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_style_context_add_provider(contextNote2, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);


                    GtkWidget* labelNomPrenomcol = gtk_label_new("NomPrenom");

                    gtk_frame_set_child(GTK_FRAME(framenomPrenomCol), labelNomPrenomcol);
                    gtk_grid_attach(GTK_GRID(grid2), framenomPrenomCol  , 0, 0, 1, 1);
                    GtkWidget* labelAgecol = gtk_label_new("Age");
                    gtk_frame_set_child(GTK_FRAME(frameageCol), labelAgecol);
                    gtk_grid_attach(GTK_GRID(grid2), frameageCol  , 1, 0, 1, 1);


                    GtkWidget* labelNote1Col  = gtk_label_new("Note1");
                    gtk_frame_set_child(GTK_FRAME(framenote1Col), labelNote1Col);
                    gtk_grid_attach(GTK_GRID(grid2), framenote1Col  , 2, 0, 1, 1);



                    GtkWidget* labelNote2Col = gtk_label_new("Note2 ");
                    gtk_frame_set_child(GTK_FRAME(framenote2Col), labelNote2Col);
                    gtk_grid_attach(GTK_GRID(grid2), framenote2Col  , 3, 0, 1, 1);



        for (int i=0;i<tab->casesRemplis; i++){


                GtkWidget *labelNomPrenom;
                GtkWidget *labelAge;
                GtkWidget *labelNote1;
                GtkWidget *labelNote2;

                GtkWidget *frameNomPrenom = gtk_frame_new(NULL);
                GtkWidget *frameAge = gtk_frame_new(NULL);
                GtkWidget *frameNote1 = gtk_frame_new(NULL);
                GtkWidget *frameNote2 = gtk_frame_new(NULL);
                gtk_widget_set_size_request(frameNomPrenom, 100, 100);
                  // Set the size of each cell
                gtk_widget_set_size_request(frameAge, 100, 100);
                gtk_widget_set_size_request(frameNote1, 100, 100);
                gtk_widget_set_size_request(frameNote2, 100, 100);

            // Apply CSS styling to the frame
            GtkStyleContext *context1 = gtk_widget_get_style_context(frameNomPrenom);
            GtkStyleContext *context2 = gtk_widget_get_style_context(frameAge);
            GtkStyleContext *context3 = gtk_widget_get_style_context(frameNote1);
            GtkStyleContext *context4 = gtk_widget_get_style_context(frameNote2);

            gtk_style_context_add_provider(context1, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_style_context_add_provider(context2, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_style_context_add_provider(context3, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_style_context_add_provider(context4, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);


                    labelNomPrenom = gtk_label_new(tab->tabNomPrenom[i]);

                    gtk_frame_set_child(GTK_FRAME(frameNomPrenom), labelNomPrenom);
                    gtk_grid_attach(GTK_GRID(grid2), frameNomPrenom  , 0, i+1, 1, 1);
                    char * ageStr = g_strdup_printf("%d", tab->tabAge[i]);
                        labelAge = gtk_label_new(ageStr);
                            g_free(ageStr);
                    gtk_frame_set_child(GTK_FRAME(frameAge), labelAge);
                    gtk_grid_attach(GTK_GRID(grid2), frameAge  , 1, i+1, 1, 1);

                    char *NoteStr1 = g_strdup_printf("%.2f", tab->tabNote1[i]);
                    labelNote1 = gtk_label_new(NoteStr1);
                    gtk_frame_set_child(GTK_FRAME(frameNote1), labelNote1);
                    gtk_grid_attach(GTK_GRID(grid2), frameNote1  , 2, i+1, 1, 1);
                    g_free(NoteStr1);

                    char * NoteStr2 = g_strdup_printf("%.2f", tab->tabNote2[i]);
                    labelNote2 = gtk_label_new(NoteStr2);
                    g_free(NoteStr2);
                    gtk_frame_set_child(GTK_FRAME(frameNote2), labelNote2);
                    gtk_grid_attach(GTK_GRID(grid2), frameNote2  , 3, i+1, 1, 1);}



 // Create the button
    GtkWidget *button = gtk_button_new_with_label("quit ");
    gtk_grid_attach(GTK_GRID(grid2), button, 0, 4, 2, 1);
g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window2);
    gtk_window_set_child (GTK_WINDOW (window2), grid2);

    gtk_window_set_title(GTK_WINDOW(window2), "PrintListStudents ");
    gtk_window_set_default_size(GTK_WINDOW(window2), 700, 700);
    gtk_window_present (GTK_WINDOW (window2));

}

