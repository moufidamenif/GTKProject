#include<gtk/gtk.h>
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
    char* nomPrenon;
    int age ;
    float noteNumerique1;
    float noteNumerique2;
}apprenant ;
typedef struct {
    char** tabNomPrenom ;
    int* tabAge ;
    float* tabNote1;
    float* tabNote2 ;
    int capacite ;
    int casesRemplis;
}tableaux;
typedef struct {
GtkWidget * window ;
 GtkWidget *entry;
}structSearch ;
extern tableaux *tab;
void MainButton7clicked (GtkButton *button7, gpointer user_data);

#endif // HEADER_H_INCLUDED
