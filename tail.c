#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000
#include <unistd.h>

//Fonction qui caste
int caste(char* cc)
{
    int n;
    n = atoi(cc);
    return n;
}

void ouverture(FILE **nom_fichier, char **chaine)
{
    *nom_fichier = fopen(*chaine,"r" );
    if(*nom_fichier == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}
int compteur(FILE* nom_fichier, char *chaine)
{
    int cont = 1;
    while(feof(nom_fichier) != 1)
    {
        fgets(chaine,100,nom_fichier);
        cont++;
    }
    fclose(nom_fichier);
    return (cont);
}
//Fonction default_tail
void default_tail(FILE* fichier, int i, char *argv[],char *chaine )
{
    int cont = 1;
    int cont1;
    ouverture(&fichier, &argv[i]);
    cont1 = compteur (fichier, chaine);
    ouverture(&fichier,&argv[i]);
    while(feof(fichier) != 1)
    {
        fgets(chaine,100,fichier);
        cont++;
        if (cont > cont1-10)
        {
            printf("%s", chaine);
        }
    }
    fclose(fichier);
}
//Fonction qui fait le tail
void fonction_tail(FILE* nom_fichier, char *chaine,char* argv[],int n, int contarg)
{
    int i;
    int cont1;
    int cont = 1;
    int j = 1;
    int k = 1;
    char buffer[BUFFER_SIZE];
    if(argv[1] == NULL)
    {
        printf("Utilisation : ./Application <option> <nom_fichier>");
    }
    if(strcmp(argv[1], "-n") == 0){
        i = 2;
        n = caste(argv[i]);
        i = 3;
        ouverture(&nom_fichier, &argv[i]);
        cont1 = compteur (nom_fichier, chaine);
        cont1 = cont1 - n;
        i = 3;
        ouverture(&nom_fichier, &argv[i]);
        while(feof(nom_fichier) != 1)
        {
            fgets(chaine,100,nom_fichier);
            cont++;
            if (cont > cont1)
            {
                printf("%s", chaine);
            }
        }
        fclose(nom_fichier);
    }
    else if(strcmp(argv[1], "-v") == 0)
    {
        i = 2;
        printf("==> %s <==\n", argv[i]);
        n = 10;
        default_tail(nom_fichier, i, argv, chaine);
        ouverture(&nom_fichier, &argv[i]);
        cont1 = compteur (nom_fichier, chaine);
        cont1 = cont1 - n;
        i = 2;
        ouverture(&nom_fichier, &argv[i]);
        while(feof(nom_fichier) != 1)
        {
            fgets(chaine,100,nom_fichier);
            cont++;
            if (cont > cont1)
            {
                printf("%s", chaine);
            }
        }
     fclose(nom_fichier);
    }
    else
    {
        default_tail(nom_fichier, 1, argv, chaine);
    }
}

