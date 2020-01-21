#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void intro();
int mediana(int v1[],int in1, int fin1, int v2[], int in2, int fin2);
void systemJ(char *);

int main(){
	intro();
	printf("El program calcula la Mediana de dos vecotres del mismo tamaño\n");
	printf("Introduce el numero de elementos: ");
	int n;
	scanf("%d",&n);

    printf("Introduce lo elementos ordenados\n");
	int *v1=(int*)malloc(n*sizeof(int));
	printf("Introduce los elementos del primer vector: ");
	for(int i=0; i < n; i++)
		scanf("%d",&v1[i]);

	int *v2=(int*)malloc(n*sizeof(int));
    printf("Introduce los elementos del segundo vector: ");
	for(int i=0; i < n; i++)
		scanf("%d",&v2[i]);

	printf("La medianaes es %d \n",mediana(v1,0,n-1,v2,0,n-1));
	printf("________________________________________________________\n\n");
	systemJ("pause");
}
int mediana(int v1[],int in1, int fin1, int v2[], int in2, int fin2){
	if ((fin1 == in1) && (in2 == fin2)){
		if (v1[fin1] < v2[fin2])
			return v1[fin1];
		else
			return v2[fin2];
	}
	else{
		int cen1 = (fin1 - in1)/2 + in1; //Posicino media de los dos arrays
		int cen2 = (fin2 - in2)/2 + in2;//Para comparar los elemtos centrales de los vectores

		if  (v1[cen1] ==  v2[cen2])
			return v1[cen1];// caso: -> el valor v1-i y v2-j son siguales
		else if (((in1 - fin1 + 1) % 2 != 0) && ((in2 - fin2 + 1) % 2 != 0)){//Si la cantidad de elemtos de los vectores es impar
				if (v1[cen1] > v2[cen2])
						return mediana(v1,in1,cen1,v2,cen2,fin2);
				else if (v1[cen1] < v2[cen2])
						return mediana(v1,cen1,fin1,v2,in2,cen2);
			}else
				if (v1[cen1] > v2[cen2])
						return mediana(v1,in1,cen1,v2,cen2+1,fin2);
				else if (v1[cen1] < v2[cen2])
						return mediana(v1,cen1+1,fin1,v2,in2,cen2);
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
