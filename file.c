#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Tete=-1;
    ptrF->Queue=-1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if (fileVide==0)
    {
        affecterElt(ptrE,ptrF->Elts[ptrF->Tete]);
        ptrF->Tete=(ptrF->Tete+1)%10;
        return 1;
    }
    
return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (filePleine==0)
    {
        affecterElt(ptrF->Elts[ptrF->Queue],ptrE);
        ptrF->Queue=(ptrF->Queue+1)%10;
        return 1;
    }
    
return 0;
} 

int fileVide(const  T_File *prtF) // qd Tete == 0 
{
    if ((prtF->Queue-prtF->Tete)==0 || prtF->Queue==-1 || prtF->Tete==-1)
    {
        return 1;
    }
    
return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if ((ptrF->Queue+1)%10==ptrF->Tete)
    {
        return 1;
    }
    
return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    if (fileVide ==0)
    {
        for (int i = ptrF->Tete; i < (ptrF->Queue-ptrF->Tete)%10; i++)
        {
            afficherElt(ptrF->Elts[i%10]);
        }
    }
}

int menuFile()
{

int choix;
printf("\n\n\n 1 : filePleine");
printf("\n 2 : fileVide");
printf("\n 3 : ajouter");
printf("\n 4 : supprimeter");
printf("\n 5 : premier");
printf("\n 6 : afficherFile");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}


void testFile(T_File *F) {
    initFile(F);
    int chx;
    T_Elt test;
    // int taille;
    //char chaine[20];
    
    do
    {
    chx=menuFile();
    switch (chx)
        {
        case 1 :  
            if(filePleine(F)) {
                printf("La file est pleine\n");
            } else {
                printf("La file n'est pas pleine\n");
            }
            break;
        case 2 : 
            if(fileVide(F)) {
                printf("La file est vide\n");
            } else {
                printf("La file n'est pas vide\n");
            }
            break; 
        case 3 : 
            printf("Quelle element voulez-vous ajouter ?\n");
            saisirElt(test);
            if(ajouter(F,test)) {
                printf("Ajout réussie !\n");
            } else {
                printf("Ajout Impossible !\n");
            }
            break;
        case 4 : 
            if(retirer(F, test)) {
                printf("Suppression Réussie !\n");
            } else {
                printf("Suppression Impossible !\n");
            }
            break;
        case 5 :
            if(!fileVide(F)) {
                printf("Le premier element est : \n");
                premier(F);
            } else {
                printf("la file est vide\n");
            }
            break;
        case 6 :
            printf("La file est : ");
            afficherPile(F);
            break;
        }
    }while(chx!=0);
    
    printf("\nFin test File\n");
    return;
    }






