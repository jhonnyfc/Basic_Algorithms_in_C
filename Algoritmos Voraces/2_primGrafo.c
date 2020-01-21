#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Col 3 //columnas de la matriz

void prim(int matAristas[][Col], int nfilasMatAri, int matSol[][Col], int numfilSol);
int esPrometedor(int conjunto[], int origen, int destino);
int calcula(int origen, int numfilSol);
int buscarMenor(int matAristas[][Col], int iniOrigX,int nfilasMatAri, int origen);
int peso(int matSol[][Col], int numfilSol);
void mostrar(int matDatos[][Col],int fil, int col);
void mostrarSol(int matSol[][Col],int numfilSol);
void incluir(int matSol[][Col], int matAristas[][Col], int a, int b);
void intro();
void systemJ(char *);

int main(){
	intro();
    printf("El prgoram utiliza el algritmo de Prim, para\n");
    printf("obtener el arbol recubridor de coste minimo,\n");
	printf("la numeracion de los vertices empieza en 0\n\n");

	printf("Introduce el numero de vertices: ");
	int numVer;
	scanf("%d",&numVer);

	// Nuemro de aristas para el caso de que tengamos un grafo completo
	// en este problema se pide trabajar con este tipo de tabla
	// ademas de ser el nuemro de fias de la matriz de datos
	int numAris =  numVer*(numVer - 1)/2;

	int matAristas[numAris][Col];
	int indxFil = 0;

	printf("Introduce para cada arista su peso (1000 si no existe): \n");
	for (int i = 0; i < numVer; i++)
		for (int j = i+1; j < numVer; j++){
			printf("Arista %d - %d: ",i,j);
			matAristas[indxFil][0] = i;
			matAristas[indxFil][1] = j;
			scanf("%d",&matAristas[indxFil][2]); //Matriz con datos de las aristas
			indxFil++;
		}
    printf("\n");

	int solucion[numVer-1][Col];///aquí se almacena la solucion

	prim(matAristas,numAris-1,solucion,numVer-1);

    printf("Las aritas seleccionadas son: \n\n");
    mostrarSol(solucion,numVer-1);
    printf("\n");

    printf("El peso total es: %d",peso(solucion,numVer-1));
    printf("__________________________________________________________\n\n");
	systemJ("pause");
}

void prim(int matAristas[][Col], int nfilasMatAri, int matSol[][Col], int numfilSol){
	int conjunto[numfilSol+1];
	for (int i = 0; i <= numfilSol; i++)//inicializacion del conjunto de vertices
		conjunto[i] = i;

	int numArisEnSol = 0;// = auxiliar para filas  == numfilSol

	while (numArisEnSol < numfilSol){
		int indxMenor;
		if (numArisEnSol == 0){
			indxMenor = buscarMenor(matAristas,0,nfilasMatAri,0);

		}else{
			int indxFilAux = 0;
			int candidatas[numArisEnSol+1][2];//guardara indxFilMin , pesoMin -> Candidatos

			// Buscamos las posibles aritas menores para cada vertice origen disponible
			for (int i = 0; i <= numfilSol; i++)
				if (conjunto[i] == 0){
					int iniOrigX = calcula(i,numfilSol);
					candidatas[indxFilAux][0] = buscarMenor(matAristas,iniOrigX,nfilasMatAri,i);
					candidatas[indxFilAux][1] = matAristas[ candidatas[indxFilAux][0] ][2];
					indxFilAux++;
				}

			int min  = candidatas[0][1];
			indxMenor = candidatas[0][0];

			// Elejimos la arista con menor peso que sea valida
			for (int i = 0; i <= numArisEnSol; i++)     //             origen                            destino
				if (min > candidatas[i][1] && (esPrometedor(conjunto,matAristas[candidatas[i][0]][0], matAristas[candidatas[i][0]][1])) ){
					min  = candidatas[i][1];
					indxMenor = candidatas[i][0];
				}
		}
		incluir(matSol,matAristas,indxMenor,numArisEnSol);
		matAristas[indxMenor][2] = 1000;//actualizar datos para eliminar arista
		conjunto[matAristas[indxMenor][1]] = 0;
		numArisEnSol++;
	}
}

int esPrometedor(int conjunto[], int origen, int destino){
	//Sea el vector de conjuntos comprobamos si en el vetor los dos
	//vertices no forman ciclo, es decir no tienen el mismo identificador
	return conjunto[origen] != conjunto[destino];
}

int calcula(int origen, int numfilSol){//Recivimos la filas mat sol, dado que #Vertices == Filas +1
	//Calcula la fila donde empieza el origenX
	int iniOrigX = 0;
	int numVer = numfilSol + 1;
	for (int i = 1; i < origen + 1; i++)
		iniOrigX = iniOrigX + numVer - i;

	return iniOrigX;
}

int buscarMenor(int matAristas[][Col], int iniOrigX,int nfilasMatAri,int origen){
	//Devuelve la posicion de la Arista con menor peso para todas
	//las aristas que empiecen en el vertice: origen
	int     min = matAristas[iniOrigX][2];
	int indxMin = iniOrigX;
	int       i = iniOrigX;

	while ((matAristas[i][0] == origen) && (i <= nfilasMatAri)){
		if (min > matAristas[i][2]){
			min = matAristas[i][2];
			indxMin = i;
		}
		i++;
	}
	return indxMin;
}

int peso(int matSol[][Col], int numfilSol){
	if (numfilSol == 0)
		return matSol[numfilSol][Col-1];
	else
		return matSol[numfilSol][Col-1] + peso(matSol,numfilSol-1);
}

void mostrar(int matDatos[][Col],int fil, int col){
	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++)
			printf("%d\t",matDatos[i][j]); //Matriz con datos de las aristas
		printf("\n");
	}
}

void mostrarSol(int matSol[][Col],int numfilSol){
	for (int i = 0; i < numfilSol; i++)
		printf("Arista: %d - %d  de peso:   %d\n",matSol[i][0],matSol[i][1],matSol[i][2]);
}

void incluir(int matSol[][Col], int matAristas[][Col], int a, int b){
	matSol[b][0] = matAristas[a][0];
	matSol[b][1] = matAristas[a][1];
	matSol[b][2] = matAristas[a][2];
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
