#include <stdio.h>
int caste(char* cc);
void ouverture(FILE **nom_fichier, char **chaine);
int compteur(FILE* nom_fichier, char *chaine);
void default_tail(FILE* fichier, int i, char *argv[],char *chaine );
void fonction_tail(FILE* nom_fichier, char *chaine,char* argv[],int n, int contarg);
