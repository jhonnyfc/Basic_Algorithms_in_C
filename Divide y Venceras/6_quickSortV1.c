#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void intro();
void quickSort(int v[],int ini, int fin);
void swap(int *, int *);
void systemJ(char *);

int main(){
	intro();
    printf("El program ejectua el algoritmo de ordenacion quickSort\n");
	printf("donde el pivote siempre es el primer numero del vector\n");
	printf("Introduce el numero de elementos: ");
	int n;
	scanf("%d",&n);

	int *v1 = (int*)malloc(n*sizeof(int));
	printf("Introduce los elementos: ");
	for(int i = 0; i < n; i++)
		scanf("%d",&v1[i]);
    printf("\n");

    quickSort(v1,0,n-1);

    printf("Los elementos ordenados son: ");
	for(int i = 0; i < n; i++)
		printf("%d ",v1[i]);
	printf("\n");
    printf("________________________________________________________\n\n");
	systemJ("pause");
}

void quickSort(int v[],int ini, int fin){
    if (ini < fin){
		int pivote = v[ini];//Elejimos como pivote siempre el primero de la tabla -> se podria mejorar Ex 2018
		int left = ini+1; 	//apuntador izquierdo
		int right = fin;   	//apuntador derecho
		while (left <= right) {
			if (pivote < v[left]){//si el izquierdo es mayor que el pivote
				if (pivote > v[right]){
					swap(&v[left],&v[right]);
					left++;
					right--;
				}else
					right--;
			}else
				left++;
		}

		swap(&v[right],&v[ini]);//Cambiamos el pivote por el apuntador derecho
		quickSort(v,ini,right-1);///izda
		quickSort(v,right+1,fin);///dcha
	}
}

void swap(int *x, int *y){
    int a;
    a=*x;
    *x=*y;
    *y=a;
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
