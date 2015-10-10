#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RND_LIMIT 10

void RandomFillArray(int array[], int n, int limit);                            //riempien con numeri casuali un array;
void AscSortArray(int array[], int n);                                          //ordina in ordine crescente un array;
float AWT(int array[], int n);                                                  //calcolo tempo medio di attesa;

int main(int argc, char** argv) {
    int *array = NULL;                                                          //verrà utilizzato per memorizzare la durata dei processi;
    int nTask;                                                                  //numero di processi da inserire;
    float avg;                                                                  //tempo medio di attesa;
    
    printf("Inserisci il numero di processi in arrivo: ");
    scanf("%d", &nTask);
    
    if(!(array = (int*)malloc(nTask*sizeof(int))))                              //allocazione con controllo errore;
        exit(1);                                                                //ERROR N°1 || fallita allocazione array;
    
    RandomFillArray(array, nTask, RND_LIMIT);
    
    AscSortArray(array, nTask);
    
    avg = AWT(array, nTask);
    
    printf("\nIl tempo medio d'attesa e' uguale a: %f", avg);                   //stampa risultato;

    return (EXIT_SUCCESS);
}

void RandomFillArray(int array[], int n, int limit){                            //limit indica il massimo valore che può essere generato;
    int i;
    
    srand(time(NULL));                                                          //inizializzazione seme;
    for(i=0;i<n;i++){
        array[i]=(rand()%limit)+1;                                              //assegnazione su array;
        printf("Il %d° elemento e': %d\n", i+1, array[i]);                      //stampa valore;
    }
    
    return;
}

void AscSortArray(int array[], int n){                                          //bubble sort;
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
    int prv, i;                                                                 //prv conterrà il tempo di attesa precedente;
    float avg;
    
    prv=array[0];                                                               //inizializzazione (primo valore);
    avg = prv;                                                                  //inizializzazione avg;
    for(i=1; i < n-1; i++){                                                     //ciclo crescente (si ferma al penultimo elemento);
        avg += prv + array[i];
        prv += array[i];
    }
    avg = avg/n;
    
    return avg;
}