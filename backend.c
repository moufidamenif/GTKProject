#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void  createDynamicArray(int capacity) {
    tab->casesRemplis=0;
    tab->capacite = capacity;
tab->tabNomPrenom  = (char**)malloc(capacity*sizeof(char*));
     tab->tabAge = (int*)malloc(capacity*sizeof(int));
      tab->tabNote2 = (float*)malloc(capacity*sizeof(float));
      tab->tabNote1 = (float*)malloc(capacity*sizeof(float));
  /*  for (int i = 0; i < capacity ; i++) {
        tab->tabNomPrenom[i] = (char *)malloc(50 * sizeof(char));}*/
}

void  resizeArray(int newCapacity) {
    int c =newCapacity+tab->capacite;
    char** newArrayNomPrenom  = (char**)malloc(c * sizeof(char*));
    /*for (int i = 0; i <c; i++) {
        newArrayNomPrenom[i] = (char *)malloc(50 * sizeof(char));}*/
    int* newArrayAge  = (int *)malloc(tab->capacite+newCapacity * sizeof(int));
    float* newArrayNote1  = (float*)malloc(tab->capacite+newCapacity * sizeof(float));
    float* newArrayNote2  = (float*)malloc(tab->capacite+newCapacity * sizeof(float));
    for (int i = 0; i < tab->casesRemplis; i++) {
        strcpy(newArrayNomPrenom[i], tab->tabNomPrenom[i]);
        newArrayAge[i]=tab->tabAge[i];
        newArrayNote1[i]=tab->tabNote1[i];
        newArrayNote2[i]=tab->tabNote2[i];
    }
    for (int i = 0; i < tab->casesRemplis; i++) {
    free(tab->tabNomPrenom[i]);  // Free each string
}
free(tab->tabNomPrenom);
tab->tabNomPrenom = NULL;
    free(tab->tabAge);
    tab->tabAge = NULL;
    free(tab->tabNote1);
    tab->tabNote1 = NULL;
    free(tab->tabNote2);
    tab->tabNote2 = NULL;
   tab->tabNomPrenom = newArrayNomPrenom;
    tab->tabAge = newArrayAge;
    tab->tabNote1 = newArrayNote1;
    tab->tabNote2 = newArrayNote2;
     tab->capacite= c;
}
void insertElement(apprenant *app) {
    int newcapacity =5;
    if (tab->casesRemplis ==tab->capacite){
    resizeArray(newcapacity);
    }
    tab->tabNomPrenom[tab->casesRemplis]=(char*)malloc(sizeof(char)*50);
    strcpy(tab->tabNomPrenom[tab->casesRemplis],app->nomPrenon);
    tab->tabAge[tab->casesRemplis]=app->age ;
    tab->tabNote1[tab->casesRemplis]=app->noteNumerique1;
    tab->tabNote2[tab->casesRemplis]=app->noteNumerique2;
    tab->casesRemplis++;
}
int rechercheApprenant ( char* aChercher ){

    int j =-1;
    for (int i=0 ; i<tab->casesRemplis;i++){
        if (strcmp(tab->tabNomPrenom[i],aChercher)==0){
            j=i;
        }
    }
    return j ;
}
void suppresionApprenant (int position ){
        if (position ==1&&tab->casesRemplis==1){
            tab->tabNomPrenom[0]=NULL;
            tab->tabAge[0] = 0;
        tab->tabNote1[0] = 0.0;
        tab->tabNote2[0] = 0.0;
        }
        else {
        for (int i=position-1 ;i<tab->casesRemplis; i++){
            strcpy(tab->tabNomPrenom[i],tab->tabNomPrenom[i+1]);
            tab->tabAge[i]=tab->tabAge[i+1];
            tab->tabNote1[i]=tab->tabNote1[i+1];
            tab->tabNote2[i]=tab->tabNote2[i+1];
        }}
         tab->casesRemplis--;
}
FILE* enregistrementFichier(char *nomFichier) {
    FILE *fp = fopen(nomFichier, "w");
    if (fp != NULL) {
        for (int i = 0; i < tab->casesRemplis; i++) {
            tab->tabNomPrenom[i][strcspn(tab->tabNomPrenom[i], "\n")] = '\0';
            if (fprintf(fp, "%d\t%s\t%f\t%f\n",
                        tab->tabAge[i],
                        tab->tabNomPrenom[i],
                        tab->tabNote1[i],
                        tab->tabNote2[i]) < 0) {
                g_print("Erreur lors de l'�criture dans le fichier.\n");
                fclose(fp);
                return NULL;
            }
        }
        fclose(fp);
        g_print("Enregistrement r�ussi.\n");
}
return fp;}
FILE*  chargementFichier(char *nomFichier){
    apprenant* app1=(apprenant*)malloc(sizeof(apprenant));

    char ligne[250];
    int age ;
    int nblignes=0 ;
    float note1;
    float note2;
FILE *fp = fopen(nomFichier, "r");
    if (fp != NULL) {
             app1->nomPrenon=(char*)malloc(50 * sizeof(char));
    char nomPrenom[50];
           while (fgets(ligne, sizeof(ligne), fp) != NULL){
                printf("Debug: Ligne brute -> %s\n", ligne);
           //Debug: Ligne brute -> 24        omar    0.000000        2.000000
                nblignes ++;
         if (sscanf(ligne, "%d %49s %f %f", &age, nomPrenom, &note1, &note2) == 4){
                strcpy(app1->nomPrenon, nomPrenom);
            app1->nomPrenon[sizeof(app1->nomPrenon) - 1] = '\0';
            app1->noteNumerique1 = note1;
            app1->noteNumerique2 = note2;
            app1->age=age;
        insertElement(app1);
    }
    else {
            g_print("ligne mal formee");

        }
    };
        fclose(fp);
        g_print("chargement reussi ");
    }
    /*else {
         printf("Erreur d'ouverture du fichier.\n");
    }
    fclose(fp);*/
}

