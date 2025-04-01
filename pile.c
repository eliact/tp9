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
    affecterElt(pelt, &(P->Elts[P->nbElts]));
    P->nbElts--;
    afficherElt(pelt);
    return 1;
}


//apeller si pile non vide
T_Elt sommet(const  T_Pile *P) { 
    return P->Elts[P->nbElts];
}



int hauteur(const  T_Pile *P) {
    return P->nbElts;
}


void afficherPile(  T_Pile *P) {
    int nbElem = P->nbElts, i;
    for(i = 0; i < nbElem; i++) {
        afficherElt(P->Elts[i]);
    }
    return;
}








