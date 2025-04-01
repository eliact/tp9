#include "pile.h"



void initPile( T_Pile * P) {
    P->nbElts = 0;
    return;
}


int pilepleine(const  T_Pile *P) {
    if(P->nbElts == MAX) return 1;
    return 0;
}



int pilevide(const  T_Pile *P) {
    if(P->nbElts == 0) return 1;
    return 0;
}



int empiler( T_Pile *P, T_Elt *e) { //renvoie 0 si pile pleine, sinon 1
    if(pilepleine(P)) return 0;
    // P->Elts[P->nbElts] = e;
    affecterElt(&(P->Elts[P->nbElts]), e);
    P->nbElts++;
    return 1;
}



int depiler( T_Pile *P, T_Elt *pelt) {  //renvoie 0 si pile vide, sinon 1
    if(pilevide(P)) return 0;
    // printf("Affectation\n");
    affecterElt(pelt, &(P->Elts[P->nbElts - 1]));
    // printf("Réduction taille\n");
    P->nbElts--;
    // printf("affchage\n");
    afficherElt(pelt);
    return 1;
}


//apeller si pile non vide
T_Elt sommet(const  T_Pile *P) { 
    return P->Elts[P->nbElts-1];
}



int hauteur(const  T_Pile *P) {
    return P->nbElts;
}


void afficherPile(  T_Pile *P) {
    int nbElem = P->nbElts, i;
    for(i = nbElem; i > 0; i--) {
        afficherElt(&(P->Elts[i-1]));
    }
    return;
}


int menuPile()
{

int choix;
printf("\n\n\n 1 : pilePleine");
printf("\n 2 : pileVide");
printf("\n 3 : empiler");
printf("\n 4 : depiler");
printf("\n 5 : sommet");
printf("\n 6 : hauteur");
printf("\n 7 : afficherPile");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}


void testPile(T_Pile *P) {
initPile(P);
int chx;
T_Elt elem;
// int taille;
//char chaine[20];

do
{
chx=menuPile();
switch (chx)
	{
	case 1 :  
		if(pilepleine(P)) {
			printf("La pile est pleine\n");
		} else {
			printf("La pile n'est pas pleine\n");
		}
		break;
	case 2 : 
		if(pilevide(P)) {
			printf("La pile est vide\n");
		} else {
			printf("La pile n'est pas vide\n");
		}
		break; 
	case 3 : 
		printf("Quelle element voulez-vous ajouter ?\n");
		saisirElt(&elem);
		if(empiler(P,&elem)) {
			printf("Empilement réussie !\n");
		} else {
			printf("Empilement Impossible !\n");
		}
		break;
	case 4 : 
		if(depiler(P, &elem)) {
			printf("\nDepilement Réussie !\n");
		} else {
			printf("Depilement Impossible !\n");
		}
		break;
	case 5 :
		if(!pilevide(P)) {
			printf("Le sommet est : ");
			T_Elt som = sommet(P);
			afficherElt(&som);
			printf("\n");
		} else {
			printf("la pile est vide\n");
		}
		break;
	case 6 :
		printf("La pile a une hauteure de: %d", hauteur(P));
		break;
	case 7:
		printf("La pile est : \n");
		afficherPile(P);
		break;
	}
}while(chx!=0);

printf("\nFin test Pile\n");
return;
}






