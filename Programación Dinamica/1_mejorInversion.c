#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 5 // Numero de Bancos en los que se puede invertir

void maxBenficio(int m[][N], int benefiMaximos[][N]);
int maxCombi2Col(int benefiMaximos[][N], int colX, int colY, int fila);
int maxAnteriorCol(int benefiMaximos[][N],int maxNowCol,int fila, int col);
void imprime(int matriz[][N], int nFil, int nCol);
void intro();
void systemJ(char *);

int main(){
	intro();
    printf("El prgoram Calcula el benefcio para una catidad de 5000 $\n");
    printf("en 5 bancos diferentes cuyos beneficios son diferentes\n\n");

	int benefiXBanco[N][N];
	printf("Introduzca los beneficios por Banco: \n");
	for (int i = 0; i < N; i++){
		printf("Beneficios para el banco %d: \n",i+1);
		for (int j = 0; j < N; j++)
			scanf("%d",&benefiXBanco[i][j]); //Matriz con los benificion dse los bancos
	}


	int benefiMaximos[N][N];
	maxBenficio(benefiXBanco,benefiMaximos);

	imprime(benefiMaximos,N,N);
    printf("____________________________________________________________\n\n");
	systemJ("pause");
}

void maxBenficio(int benefiXBanco[][N], int benefiMaximos[][N]){
	//Cada iteracion represta un banco en la tabal  es decir, avance por filas
	for (int fila = 0; fila < N; fila++){
		//La primera fila se instacia como caso base
		if (fila == 0)
			for (int col = 0; col < N; col++)
				benefiMaximos[fila][col] = benefiXBanco[fila][col];

		else//El resto de filas
			//Iteramos para completar las los beneficios maximos de la filaX
			for (int col = 0; col < N; col++){
				int maxBenf = benefiMaximos[fila-1][col];

				//Estudiamos las posibles combinaciones de invertir la cantidad de la columna (col)
				//es decir obtenemos las distintas combinaciones de columnas
				//y buscamos el maximo beneficion para ese caso (fila,col)
				for (int j = col -1; j >= col /2; j--){
					int auxMax = maxCombi2Col(benefiMaximos,j,col -j -1,fila);//los datos que mandamos son las posibles
								//combinaciones de las columnas para sumar la cantidad estudiada
					if (maxBenf < auxMax)
						maxBenf = auxMax;
				}

				if (maxBenf < benefiXBanco[fila][col])
					benefiMaximos[fila][col] = benefiXBanco[fila][col];
				else
					benefiMaximos[fila][col] = maxBenf;
			}
	}
}

int maxCombi2Col(int benefiMaximos[][N], int colX, int colY, int fila){
	//la 'x' e 'y' son las Columnas a estudiar de la matriz benefiMaximos (sol)
	if (colX == colY){
		return benefiMaximos[fila][colX] + maxAnteriorCol(benefiMaximos,benefiMaximos[fila][colX],fila,colY);
	}
	else{
		int maxX_Yant = benefiMaximos[fila][colX] + maxAnteriorCol(benefiMaximos,benefiMaximos[fila][colY],fila,colY);
		int maxY_Xant = benefiMaximos[fila][colY] + maxAnteriorCol(benefiMaximos,benefiMaximos[fila][colX],fila,colX);
		if (maxX_Yant > maxY_Xant){
			return maxX_Yant;
		}else{
			return maxY_Xant;
		}
	}

}

int maxAnteriorCol(int benefiMaximos[][N],int maxNowCol,int fila, int col){
	//Recibe el maximo de la columna y busca el antecesor
	//fila ->  es la fila en la que estamos
	//i -> La ulizamos para recorrer la columna
	int j = fila - 1;
	while ((benefiMaximos[j][col] >= maxNowCol) && (j > 0))
		j--;
	return benefiMaximos[j][col];
}

void imprime(int matriz[][N], int nFil, int nCol){
	printf("\nLos maximos beneficios para cada posible subproblema son: \n");
	for (int i = 0; i < nFil; i++){
		for (int j = 0; j < nCol; j++)
			printf("%d  ",matriz[i][j]);
		printf("\n");
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
