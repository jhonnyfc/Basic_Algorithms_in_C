#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void quicksort(int v[],int ini, int fin);
void swap(int *, int *);
int numeroCentral(int v[], int ini, int centro, int fin);
void intro();
void systemJ(char *);

int main(){
    intro();
    printf("El program ejectua el algoritmo de ordenacion quickSort,\n");
    printf("donde elejimos como pivot el numero central de tres: el\n");
    printf("primero, el del medio y el ultimo del vector\n");
    printf("Introduce el numero de elmentos: ");
    int n;
    scanf("%d",&n);
    printf("\n");

    int *v = (int*)malloc(n*sizeof(int));
    printf("Introduce los elemntos del vector: ");
    for (int i = 0; i < n; i++)
        scanf("%d",&v[i]);
    printf("\n");

    quicksort(v,0,n-1);

    printf("Los elementos ordenados son: ");
    for (int i = 0; i < n; i++)
        printf("%d ",v[i]);
    printf("\n");
    printf("________________________________________________________\n\n");
    systemJ("pause");
}

void quicksort(int v[],int ini, int fin){
    if(ini < fin){
        int pivote; //pivote Xd
        int left;   //apuntador izquierdo
        int right;  //apuntador derecho

        //Eleccion del pivote
        if (fin - ini >= 2){
            pivote = numeroCentral(v,ini,(fin+ini)/2,fin);
            if(pivote == fin){
                left  = ini;
                right = fin-1;
            } else {
                left  = ini+1;
                right = fin;
            }
        } else {
            pivote = ini;
            left   = ini+1;
            right  = fin;
        }

        while(left <= right){
            if (v[pivote] < v[left]){
                if (v[pivote] > v[right]){
                    swap(&v[left],&v[right]);
                    left++;
                    right--;
                } else
                    right--;
            } else
                left++;
        }

        //Cambio del pivote
        if(pivote == fin || pivote > left){
            swap(&v[left],&v[pivote]);
            quicksort(v,ini,left - 1);
            quicksort(v,left + 1,fin);
        } else if (pivote == ini || pivote < right){
            swap(&v[right],&v[pivote]);
            quicksort(v,ini,right - 1);
            quicksort(v,right + 1,fin);
        } else {
            quicksort(v,ini,pivote - 1);
            quicksort(v,pivote + 1,fin);
        }
    }
}

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int numeroCentral(int v[], int ini, int centro, int fin){
    if (v[ini] < v[centro]){
        if (v[centro] < v[fin])
                return centro;
        else if (v[ini] < v[fin])
            return fin;
        else
            return ini;
    } else if (v[ini] < v[fin])
            return ini;
        else if (v[centro] < v[fin])
            return fin;
        else
            return centro;
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
