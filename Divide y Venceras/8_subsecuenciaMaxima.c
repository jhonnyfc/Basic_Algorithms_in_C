#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int subsecuenciaMaxima(int ve[], int ini, int fin);
int mayorD3(int ,int , int );
void intro();
void systemJ(char *);

int main(){
	intro();
	printf("El program calcula el segmetno maximo\n");
	printf("Introduce el numero de elementos: ");
	int n;
	scanf("%d",&n);

	int *vector = (int*)malloc(n*sizeof(int));
	printf("Introduce los elementos: ");
	for(int i = 0; i < n; i++)
		scanf("%d",&vector[i]);

	printf("la subsecuencia maxima es %d \n",subsecuenciaMaxima(vector,0,n-1));
	printf("____________________________________________________________\n\n");
	systemJ("pause");
}

int subsecuenciaMaxima(int ve[], int ini, int fin){
	if (ini == fin){//Caso base cuando solo llega un valor se devuelve ese como solucion
		return ve[ini];
	}
	else{
		int si = subsecuenciaMaxima(ve,ini,(ini+fin)/2);//Lamamos la funcion de subsecunecia con la mitad izquierda
		int sd = subsecuenciaMaxima(ve,(ini+fin)/2+1,fin);//Llamoas la funcion subsecuncia con la mitad derecha
		//
			//Calculamos la suma central la cual la haceo en dos mitades izquirda y derecha
		int sci = 0;//Instaciamos el primer valor para la suma izquirda maxima
		int sciaux = 0;//Instaciamos la variable que ira sumando todos los valores
		for (int i = (ini+fin)/2; i >= ini; i--){
            sciaux = sciaux+ve[i];//Sumamos en la variable auxiliar de suma
			if (sciaux > sci)//Comparamos la variable auxiliar con la variable de salida final
               sci = sciaux;
		}

		int scd = 0;//Instaciamos el primer valor para la suma derecha maxima
		int scdaux = 0;//Instaciamos la variable que ira sumando todos los valores
		for (int i = (ini+fin)/2+1; i <= fin; i++){
            scdaux = scdaux+ve[i];//Sumamos en la variable auxiliar de suma
			if (scdaux > scd)//Comparamos la variable auxiliar con la variable de salida final
               scd=scdaux;
		}
		int sc = sci+scd;//Sumamos los valores obtenidos en sentido derecho e iquierdo desde el centro
				//Para tener la suma central total

        return mayorD3(si,sd,sc);//Calculamos el mayo de los anteriore obtenidos
	}
}

int mayorD3(int a,int b, int c){
	return a < b ? (b < c ? c : b) : (a < c ? c : a);
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
