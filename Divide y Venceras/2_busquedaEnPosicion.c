#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int busquedaEnPos(int v[],int ini, int fin);
void intro();
void systemJ(char *);

int main(){
	intro();
    printf("El program ejectua el Algoritmo de Busqueda de tal\n");
    printf("forma que el elemento coincida con su posicion\n");
	printf("Introduce el numero de elementos: ");
	int n;
	scanf("%d",&n);

	int *v1 = (int*)malloc(n*sizeof(int));
	printf("Introduce los elementos de menor a mayor: ");
	for(int i = 0; i < n; i++)
		scanf("%d",&v1[i]);
    printf("\n");

    int indx = busquedaEnPos(v1,0,n-1);
    if (indx == -1)//Tratar el valor devuelto
		printf("No se ha encontrado ningun valor que cumpla\n");
	else
		printf("El elemto esta en la posicion %d\n",indx);
    printf("________________________________________________________\n\n");
	systemJ("pause");
}

int busquedaEnPos(int v[], int ini, int fin){
	if (ini <= fin){			//este programa esta considerando que el vector
		int centro = (fin-ini)/2+ini;    	//se numera desde el 0 1 2 ...
		if (v[centro] == centro)		//au que e vector pordria enumerarse 1 2 3...
			return centro;			//pero seria otro codigo
		else if (v[centro] > centro)
			busquedaEnPos(v,ini,centro-1);
		else
			busquedaEnPos(v,centro+1,fin);
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
