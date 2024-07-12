#include <stdio.h>
#include "tail.h"
int main(int argc, char* argv[])
{
    FILE* fichier;
    char chaine[1000];
    int cont;
    int n;
    fonction_tail(fichier,chaine ,argv,n ,argc );
    return (0);
}
