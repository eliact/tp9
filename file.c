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
        ptrF->Tete++;
        return 1;
    }
    
return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (filePleine==0)
    {
        ptrF->Queue++;
        affecterElt(ptrF->Elts[ptrF->Queue-1],ptrE);
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
    if (abs(ptrF->Queue-ptrF->Tete)==1)
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
        for (int i = 0; i < abs(ptrF->Queue-ptrF->Tete); i++)
        {
            afficherElt(ptrF->Elts[i]);
        }
    }
}

void testFile(T_File *ptrF){
    T_Elt test;
    initFile(ptrF);
    if(fileVide(ptrF)==1)
    saisirElt(test);
    ajouter(ptrF,test);
    afficherElt(ptrF->Elts[ptrF->Tete]);
    afficherFile(ptrF);


}






