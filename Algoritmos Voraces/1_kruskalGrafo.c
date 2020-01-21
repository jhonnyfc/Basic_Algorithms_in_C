#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Col 3 //numero de columnas de la matriz

void kruskal(int **matAristas, int nfilasMatAri, int sol[][Col], int numfilSol);
int esPrometedor(int conjunto[], int origen, int destino, int numVer);
int peso(int matSol[][Col],int numfilSol);
void mostrar(int **matDatos,int fil,int );
void mostrarSol(int matSol[][Col],int numfilSol);
void quickSort(int **v, int ini, int fin);
void incluir(int matSol[][Col], int **matAristas, int a, int b);
void swap(int **,int , int );
void intro();
void systemJ(char *);

int main(){
	intro();
    printf("El prgoram utiliza el algritmo de kruskal para\n");
    printf("obtener el arbol recubridor de coste minimo\n");
    printf("\n");

	printf("Introduce el numero de vertices: ");
	int numVer;
	scanf("%d",&numVer);

	printf("Introduce el numero de aristas: ");
	int numAris;
	scanf("%d",&numAris);

	int **matAristas = (int**)malloc(numAris*sizeof(int*));
	for (int i=0; i  < numAris; i++)
		matAristas[i] = (int*)malloc(Col*sizeof(int));

	printf("Introduce para cada arista el origen, destino y peso (grafo no Dirigido): \n");
	for (int i=0; i <numAris; i++)
		for (int j=0; j < Col; j++)
			scanf("%d",&matAristas[i][j]); //Matriz con datos de las aristas
	printf("\n");

	quickSort(matAristas,0,numAris-1);

	int solucion[numVer-1][Col];///aqui se almacena la solucion

    kruskal(matAristas,numAris,solucion,numVer-1);

    printf("Las aritas seleccionadas son: \n\n");
    mostrarSol(solucion,numVer-1);
    printf("\n");

    printf("El peso total es %d\n",peso(solucion,numVer-2));
    printf("____________________________________________________________\n\n");
	systemJ("pause");
}

void kruskal(int **matAristas, int nfilasMatAri, int sol[][Col], int numfilSol){
	int conjunto[numfilSol+1];

	for (int i = 0; i <= numfilSol; i++)//inicia el conjunto de vertices
		conjunto[i] = i;				//con un valor distinto para cada vertice

	int numArisEnSol = 0;
	int indxFil = 0;//fila de la arista

	while ((numArisEnSol < numfilSol) && (indxFil < nfilasMatAri)) {
		if (esPrometedor(conjunto,matAristas[indxFil][0],matAristas[indxFil][1],numfilSol+1)){//mira si hay ciclo o no
			incluir(sol,matAristas,indxFil,numArisEnSol);//si no hay ciclo se incluye como solucion
			numArisEnSol++;//aumentmos la cantidad de aristas introducidas
		}
		indxFil++;
	}
}

int esPrometedor(int conjunto[], int origen, int destino, int numVer){
	//Sea el vector de conjuntos comprobamos si en el vetor los dos
	//vertices no forman ciclo, es decir no tienen el mismo identificador
	if (conjunto[origen] != conjunto[destino]){
		//Creamos esta variable con el identificador del destino
		int idSubConjunto = conjunto[destino];

		// Actualizacion de Subconjuntos
		for (int j = 0; j < numVer; j++){
			if (idSubConjunto == conjunto[j])		// Si el identificador es igual al de destino
				conjunto[j] = conjunto[origen];	 	// le asignamos el identificador del origen
		}
		return 1;
	} else
		return 0;
}

int peso(int matSol[][Col], int numfilSol){
	if (numfilSol == 0)
		return matSol[numfilSol][Col-1];
	else
		return matSol[numfilSol][Col-1] + peso(matSol,numfilSol-1);
}

void mostrar(int** matDatos,int fil, int col){
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

void quickSort(int** v,int ini, int fin){
    if (ini < fin){
		int pivote = ini;
		int left = ini + 1;
		int right = fin;
		while (left <= right) {
			if (v[pivote][Col-1] > v[right][Col-1]){
				if (v[pivote][Col-1] < v[left][Col-1]){
					swap(v,left,right);
					left++;
					right--;
				}
				else{
					left++;
				}
			}
			else
				right--;
		}

		swap(v,pivote,right);
		quickSort(v,ini,right-1);
		quickSort(v,right+1,fin);
	}
}

void incluir(int matSol[][Col], int **matAristas, int a, int b){
	matSol[b][0] = matAristas[a][0];
	matSol[b][1] = matAristas[a][1];
	matSol[b][2] = matAristas[a][2];
}

void swap(int** matriz,int i, int j){
	int aux1 = matriz[i][0];
	int aux2 = matriz[i][1];
	int aux3 = matriz[i][2];
	matriz[i][0] = matriz[j][0];
	matriz[i][1] = matriz[j][1];
	matriz[i][2] = matriz[j][2];
	matriz[j][0] = aux1;
	matriz[j][1] = aux2;
	matriz[j][2] = aux3;
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
