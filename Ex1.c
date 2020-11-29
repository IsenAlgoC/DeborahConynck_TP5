#include <stdlib.h>
#include <stdio.h>

#define TAB2SIZE 100
#define TAILLEAJOUT 50


int initTab1(int* tab, int size) {
	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;

		}
	}return size;
}

int afficheTab(int* tab, int size, int nbElts) { // Permet d'arffiche les premiers nbELts du tableau
	if (tab == NULL || size < 0 || nbElts>size) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", tab[i]);
			
		printf("\n");
		}
		return 0;
	}
}
int remplirtableau(int* tab, int size, int* nbElts, int nombre) {
	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < nombre; i++) {
			*(tab + i) = i + 1;
			*nbElts += 1;
		}
	}
}


int* ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element) {

	if (tab == NULL || *size < 0 || *nbElts < 0) { return NULL; } //S'il y a un problème 

	if (*size > * nbElts) { // Si la taille est suffisante pour element 
		*(tab + *nbElts) = element;
		*nbElts += 1;
	}
	else {  //Si la taille n'est pas suffissante 
		*size += TAILLEAJOUT; //La taille est incrémentée de TAILLEAJOUT
		int* tabSave = tab;
		tab = (int*)realloc(tab, *size * sizeof(int)); //On réalloue de la mémoire au tableau
		if (tab == NULL) { tab = tabSave; return NULL; }// Si l'allocation ne fonctionne pas
		*(tab + *nbElts) = element;//On ajoute l'élément dans le tableau à la place souhaitée
		*nbElts += 1; // nombre d'élement total du tableau augmente
	}
	return tab;
}

int main() {
	int tab[4] = { 1,3,4,3 };
	printf("%d", initTab1(tab, 4));
	printf("\nLe tableau initialise est :\n");
	for (int i = 0; i < 4; i++) {
		printf("%d", tab[i]);
	}
	printf("\n");
	afficheTab(tab, 4, 2);//pas obligatoire
//tests obligatoire 
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	printf("\n");
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab1(myTab2, tabSize); }
	else { printf("mémoire insuffisante\n"); return(-1); }
	printf("%d", initTab1(myTab2, 100));
	printf("Le tableau initialise est :\n");
	for (int i = 0; i < TAB2SIZE; i++) {
		printf("%d", myTab2[i]);
	printf("\n");
	}
	remplirtableau(myTab2, tabSize, &nbElts, tabSize);
	for (int j = 0; j < 100; j++) {//Remplissage du tableau jusqu'à 100
		printf("%d ", *(myTab2 + j));
	}
	printf("\n");
	afficheTab(myTab2, TAB2SIZE, 20);//affiche les 20 éléments
	if (myTab2 != NULL) {
		//initTab1(tab3, 100);
		printf("\n");
		ajouteElementDansTableau(myTab2, &tabSize, &nbElts, 101); //on teste l'ajout et l'aggrandissement du tableau
		for (int i = 0; i < 101; i++) {
			printf("%d ", *(myTab2 + i));
		printf("\n");
		}
	}
	else { printf("mémoire insuffisante"); }
	free(myTab2);

}
