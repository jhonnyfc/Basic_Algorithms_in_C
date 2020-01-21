/************************************************************************/
/****************Chicaiza Palomo, Jhonny Fabricio************************/
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//Constantes
#define N 5 //ce = columnas de la matriz
//Funciones
int suma2(int v[][N], int x, int y, int fila);
/*********************************/
void maxBenficio(int m[][N], int sol[][N]);
/******************************************/
int anterior(int v[][N],int dat,int x, int col);
/*********************************************/
void imprime(int v[][N], int dim);
/*************************************/
void intro();
//Mainprogram
int main(){
	//Variables
	int	v[N][N];
	int sol[N][N];
	//Body
	intro();
    printf("El prgoram Calcula el benifcio para una catidad de 5000 $\n");
    printf("en 5 vancos fierentes cuyos benficio son diferentes\n");
    printf("\n");

	printf("Introduce para cada arista el origen, destino y peso: \n");
	int i,j;
	for (i=0; i < N; i++){
		printf("Introduce los bencficon para el banco %d: \n",i+1);
		for (j=0; j < N; j++)
			scanf("%d",&v[i][j]); //Matriz con los benificion dse los bancos
	}
	maxBenficio(v,sol);
	imprime(sol,N);
    printf("____________________________________________________________\n");
}
/*********************Funciones***************************/
void maxBenficio(int m[][N], int sol[][N]){
	//Variables
	int max,auxm;
	//Body
	int i,j,x;
	for (i=0; i<N; i++){//Cada for represte un banco en la tabal  es decir, avance por filas
		if (i == 0)//La primera fila se instacia como caso base
			for (j=0; j<N; j++)
				sol[i][j]=m[i][j];
		else//Apaertir de la sengunda fila
			for (j=0; j<N; j++){//Esto reliza el avance por columas de 1000 a 5000
				max=sol[i-1][j];
				for (x=j-1; x>=j/2; x--){//estudiamos todods la posibles combinaciones
					auxm=suma2(sol,x,j-x-1,i);//los datos que mandamos son las posibles
								//combinaciones de las columas para sumar la cantidad estudiada
					if (max < auxm)
						max=auxm;
				}
				if (max < m[i][j])
					sol[i][j]=m[i][j];
				else
					sol[i][j]=max;
			}
	}
}
/******************************************************/
int suma2(int v[][N], int x, int y, int fila){//la 'x' e 'y' son las columas a estudiar
	int aux,aux2;					//v -> es la matriz de las soluciones
	if (x == y){
		aux=anterior(v,v[fila][x],fila,y);
		return v[fila][x]+aux;
	}
	else{
		aux=anterior(v,v[fila][y],fila,y)+v[fila][x];
		aux2=anterior(v,v[fila][x],fila,x)+v[fila][y];
		if (aux > aux2){
			return aux;
		}else{
			return aux2;
		}
	}

}
/*****************************************************************/
int anterior(int v[][N],int dat,int x, int col){//Recibe el maximo de la colmuna y busca el antecesor
	int i=x-1;								 //x ->  es la fila en la que estamos
	while ((dat <= v[i][col]) && (i > 0))
		i--;
	return v[i][col];
}
/***************************************************************/
void imprime(int v[][N], int dim){
	printf("\n");
	printf("Los maximos beneficios para cada posible subproblema son: \n");
	int i,j;
	for (i=0; i<dim; i++){
		for (j=0; j<dim; j++)
			printf("%d  ",v[i][j]);
		printf("\n");
	}
}
void intro(){
	char *v1={"/***********************************************/\n/*****@Chicaiza Palomo, Jhonny Fabricio*********/\n/***********************************************/\n"};

	for (int j=0; j<strlen(v1); j++){
		printf("%c",v1[j]);
		usleep(8900);
		fflush(stdout);
	}
	printf("\n");
}
