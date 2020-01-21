#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int busquedaBinaria(int v[],int ini, int fin, int dat);
void intro();
void systemJ(char *);

int main(){
	intro();
    printf("El program ejectua el Algoritmo de Busqueda binaria\n");
	printf("Introduce el numero de elementos: ");
	int n;
	scanf("%d",&n);

	int *v1 = (int*)malloc(n*sizeof(int));
	printf("Introduce los elementos: ");
	for(int i = 0; i < n; i++)
		scanf("%d",&v1[i]);
    printf("\n");

    printf("Introduzca el elemento a buscar\n");
	int ele;
    scanf("%d",&ele);
    printf("\n");

    int indx = busquedaBinaria(v1,0,n-1,ele);
    if (indx == -1)//Tratar el valor devuelto
		printf("No se ha encontrdo el valor\n");
	else
		printf("El elemto esta en la posicion %d\n",indx+1);
    printf("________________________________________________________\n\n");
	systemJ("pause");
}

int busquedaBinaria(int v[], int ini, int fin, int dat){
	if (ini <= fin){
		int centro = (fin-ini)/2+ini;
		if (v[centro] == dat)
			return centro; //si el elemto esta devuelve la posicion del elemento
		else if (v[centro] > dat)
			busquedaBinaria(v,ini,centro - 1,dat);
		else
			busquedaBinaria(v,centro+1,fin,dat);
	}
	else
		return -1;
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
