#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void mergeSort(int v[],int ini, int fin);
void swap(int *, int *);
void merge(int v[], int left[], int right[], int leftFin, int rightFin, int fin, int ini);
void intro();
void systemJ(char *);

int main(){
	intro();
    printf("El program ejectua Mergesort para la ordenacion\n");
	printf("Introduce el numero de elementos: ");
	int n;
	scanf("%d",&n);

	int *v1=(int*)malloc(n*sizeof(int));
	printf("Introduce los elementos: ");
	for(int i=0; i < n; i++)
		scanf("%d",&v1[i]);
    printf("\n");

    mergeSort(v1,0,n-1);

    printf("Los elementos ordenados son: ");
	for(int i=0; i < n; i++)
		printf("%d ",v1[i]);

	printf("\n");
    printf("_________________________________________________________\n\n");
	systemJ("pause");
}
/***************Funciones********************/
void mergeSort(int v[],int ini, int fin){
    if (fin - ini == 1){
		if (v[ini] > v[fin])
			swap(&v[ini],&v[fin]);
	}else if (ini < fin){
		int centro = (fin + ini)/2;
		int left[fin - centro];
		int right[fin - (centro + 1) + 1 ];
		int indxLeft = 0;
		int indxRight = 0;

		for (int i = ini; i <= fin; i++){
			if (indxLeft <= centro){
				left[indxLeft]=v[i];
				indxLeft++;
			}else{
				right[indxRight]=v[i];
				indxRight++;
			}
		}
		indxLeft--;
		indxRight--;
		///izda
		mergeSort(left,0,indxLeft);
		///dcha
		mergeSort(right,0,indxRight);

		merge(v,left,right,indxLeft,indxRight,fin,ini);
	}
}

void merge(int v[], int left[], int right[], int leftFin, int rightFin, int fin, int ini){
	int indxLeft = 0;
	int indxRight = 0;

	for (int i = ini; i <= fin; i++){
		if (((left[indxLeft] < right[indxRight]) && (indxLeft <= leftFin)) || (indxRight > rightFin)){
			v[i] = left[indxLeft];
			indxLeft++;
		}else if ( ((left[indxLeft] >= right[indxRight]) && (indxRight <= rightFin)) || (indxLeft > leftFin)){
			v[i] = right[indxRight];
			indxRight++;
		}
	}
}

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void intro(){
	char *v1={"/***********************************************/\n/*****@Chicaiza Palomo, Jhonny Fabricio*********/\n/***********************************************/\n\n"};

	for (int j=0; j<strlen(v1); j++){
		printf("%c",v1[j]);
		usleep(8900);
		fflush(stdout);
	}
}

void systemJ(char *msg){
	printf("Presione cualquier tecla para continuar...\n");
	getchar();
	getchar();
}
