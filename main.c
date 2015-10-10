#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RND_LIMIT 10

void RandomFillArray(int array[], int n, int limit);
void AscSortArray(int array[], int n);
float AWT(int array[], int n);

int main(int argc, char** argv) {
    int *array = NULL;
    int nTask;
    float avg;
    
    printf("Inserisci il numero di processi in arrivo: ");
    scanf("%d", &nTask);
    
    if(!(array = (int*)malloc(nTask*sizeof(int))))
        exit(1);
    
    RandomFillArray(array, nTask, RND_LIMIT);
    
    AscSortArray(array, nTask);
    
    avg = AWT(array, nTask);
    
    printf("\nIl tempo medio d'attesa e' uguale a: %f", avg);

    return (EXIT_SUCCESS);
}

void RandomFillArray(int array[], int n, int limit){
    int i;
    
    srand(time(NULL));
    for(i=0;i<n;i++){
        array[i]=(rand()%limit)+1;
        printf("Il %d° elemento e': %d\n", i+1, array[i]);
    }
    
    return;
}

void AscSortArray(int array[], int n){
    int i,j,scambio;
    
    for(i=0; i<n-1; i++){
        for(j=1; j<n-i; j++){
            if(array[j-1]>array[j]){
                scambio = array[j];
                array[j] = array[j-1];
                array[j-1] = scambio;
            }
        }
    }
    
    return;
}

float AWT(int array[], int n){
    int prv, i;
    float avg;
    
    prv=array[0];                                                               //inizializzazione (primo valore);
    avg = prv;                                                                  //inizializzazione avg;
    for(i=1; i < n-1; i++){                                                //ciclo crescente (si ferma al penultimo elemento);
        avg += prv + array[i];
        prv += array[i];
    }
    avg = avg/n;
    
    return avg;
}