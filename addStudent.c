#include <gtk/gtk.h>
#include <unistd.h>
#include "header.h"
void insertElement(apprenant *app);

void on_submit(GtkWidget *button, gpointer user_data) {
        GtkWidget **entries=(GtkWidget **)user_data;

    // Check for NULL entries
    for (int i = 0; i < 4; i++) {
        if (entries[i] == NULL) {
            g_print("Entry %d is NULL\n", i);
            return;  // Exit if any entry is NULL
        }
    }

    // Get text from entries
    const gchar *nomChar = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    const gchar *ageChar = gtk_editable_get_text(GTK_EDITABLE(entries[1]));
    const gchar *noteNumerique1Char = gtk_editable_get_text(GTK_EDITABLE(entries[2]));
    const gchar *noteNumerique2Char = gtk_editable_get_text(GTK_EDITABLE(entries[3]));

    // Print the retrieved values for verification
    g_print("Nom: %s\n", nomChar);
    g_print("Age: %s\n", ageChar);
    g_print("Note 1: %s\n", noteNumerique1Char);
    g_print("Note 2: %s\n", noteNumerique2Char);

    // Create the apprenant structure and fill it with the values
    apprenant *app1 = (apprenant *)malloc(sizeof(apprenant));
    app1->nomPrenon=(char*)malloc(sizeof(char)*50);
    app1->nomPrenon = strdup(nomChar);  // Copy the name into the structure
    app1->age = atoi(ageChar);          // Convert age from string to integer
    app1->noteNumerique1 = atof(noteNumerique1Char); // Convert note 1 from string to float
    app1->noteNumerique2 = atof(noteNumerique2Char); // Convert note 2 from string to float
    g_print("mriguel");
    // Insert the apprenant into the table
    insertElement(app1);
    usleep(10);
    // Free the memory for the apprenant structure

    // No need to free nomChar, ageChar, etc., since they point to the GtkEntry's internal memory
    free(app1->nomPrenon);
    free(app1);
}

void MainButton1clicked (GtkButton *button1, gpointer user_data) {
    GtkWidget *window1 = gtk_window_new();
        GtkWidget *grid = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid), 50); // Space between rows
        gtk_grid_set_column_spacing(GTK_GRID(grid), 50);


        GtkWidget *label1 = gtk_label_new("username ");
        gtk_widget_set_halign(label1, GTK_ALIGN_END);
       GtkWidget *entry1=gtk_entry_new();
       gtk_widget_set_margin_top(label1, 10);
    gtk_widget_set_margin_bottom(label1, 10);
       gtk_entry_set_placeholder_text(GTK_ENTRY(entry1),NULL);
        gtk_grid_attach(GTK_GRID(grid), label1, 0, 0, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), entry1, 1, 0, 2, 1);



        GtkWidget *label2 = gtk_label_new("age ");
        gtk_widget_set_halign(label2, GTK_ALIGN_END);
        GtkWidget *entry2=gtk_entry_new();
        gtk_widget_set_margin_top(label2, 10);
    gtk_widget_set_margin_bottom(label2, 10);
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry2),NULL);
         gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), entry2, 1, 1, 2, 1);


        GtkWidget *label3 = gtk_label_new("NoteNumerique1 ");
        gtk_widget_set_halign(label3, GTK_ALIGN_END);
        gtk_widget_set_margin_top(label3, 10);
    gtk_widget_set_margin_bottom(label3, 10);
        GtkWidget *entry3=gtk_entry_new();
       gtk_entry_set_placeholder_text(GTK_ENTRY(entry3),NULL);
         gtk_grid_attach(GTK_GRID(grid), label3, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry3, 1, 2, 2, 1);


        GtkWidget *label4 = gtk_label_new("NoteNumerique2 ");
        gtk_widget_set_halign(label4, GTK_ALIGN_END);
        GtkWidget *entry4=gtk_entry_new();
        gtk_widget_set_margin_top(label4, 10);
    gtk_widget_set_margin_bottom(label4, 10);
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry4),NULL);
        gtk_grid_attach(GTK_GRID(grid), label4, 0, 3, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), entry4, 1, 3, 2, 1);

 // Create the button
    GtkWidget *button = gtk_button_new_with_label("Submit");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);
     gtk_widget_set_margin_top(button, 10);
    gtk_widget_set_margin_bottom(button, 10);
    gtk_widget_set_margin_start(button, 30);
     GtkWidget **entries=(GtkWidget**)malloc(sizeof(GtkWidget*)*4);

    entries[0] = entry1;
    entries[1] = entry2;
    entries[2] = entry3;
    entries[3] = entry4;
    g_signal_connect(button, "clicked", G_CALLBACK(on_submit), entries);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window1);
    gtk_window_set_child (GTK_WINDOW (window1), grid);
    gtk_window_set_title(GTK_WINDOW(window1), "AddStudent ");
    gtk_window_set_default_size(GTK_WINDOW(window1), 500, 500);
    gtk_window_present (GTK_WINDOW (window1));
}
