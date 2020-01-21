#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void merge(int ini, int centro, int fin, int t[]);
void mergeSort(int ini, int fin, int t[]);
void intro();
void systemJ(char *);

int main(){
	intro();
	printf("Introduce el numero de elementos: ");
	int N;
	scanf("%d",&N);
	printf("\n");

	int *vector = (int*)malloc(N*sizeof(int));

	printf("Introduce los elemtos: ");
	for (int i=0; i<N; i++)
		scanf("%d",&vector[i]);
	printf("\n");

	mergeSort(0,N-1,vector);

	printf("El vecotr orenado es: ");
	for (int i=0; i<N; i++)
		printf("%d ",vector[i]);
	printf("\n");
	printf("_________________________________________________________\n\n");
	systemJ("pause");
}

void mergeSort(int ini, int fin, int t[]){
	int centro;
	if(ini < fin){//El minimo vector tiene dos elementos
		centro = (fin+ini)/2;
		mergeSort(ini,centro,t);
		mergeSort(centro+1,fin,t);
		merge(ini,centro,fin,t);//enviamos el vetor con las dos mitades para ordenar
	}
}

void merge(int ini, int centro, int fin, int t[]){
	int taux[fin-ini+1];

	int izda   = ini;//inicio parte izquierda
	int dcha   = centro+1;//inicio parte derecha
	int idxV = 0;//inicio vector auxiliar
	//En el primer acceso llegra un vector con dos elementos
	while(izda <= centro && dcha <= fin){//mientras ninguno de los dos ontadores finere el limite
		if(t[izda] > t[dcha]){//si los elemtos derechos son menores que los elemntos izquierdos
			taux[idxV]=t[dcha];//se copian en el vtror auxiliar
			dcha++;
		}
		else{//si el elemoto izquierdo es menor o igual que el elemto derecho
			taux[idxV]=t[izda];//se copia en el el vector auxliar
			izda++;
		}//obtendremos idxV elemnots de menor a mayor
		idxV++;
	}

	int i;
	for(i = izda; i <= centro; i++){//Copiamos los restantes de la parte izquierda
		taux[idxV]=t[i];
		idxV++;
	}
	for(i = dcha; i <= fin; i++){//Copiamos los restantes de la parte derecha
		taux[idxV]=t[i];
		idxV++;
	}
	for(i = ini; i <= fin; i++){//copiamos el vector auxiliar en el vector origen
		t[i]=taux[i-ini];
	}
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
