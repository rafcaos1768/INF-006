#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#define TAM 100

// void quebrarString(char string []){
    
//     int i =0; 
//     while(string[i] != NULL){
        
//     }
    
// }
void insertionsort(int A[], int tam){
    for(int j = 1; j < tam; j = j +1){
        int key = A[j];
        int i = j-1;
        while(i >= 0 && A[i]>key){
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}

void printOrdenado(int valores[], int tam){
    int o =0; 
    while(o<tam){
        if(o == tam- 1){
            printf("%d",valores[o]);
        } else{
            printf("%d+",valores[o]);
        }
        
        o++; 
    }
    
}
int main()
{   
    char string[TAM]; 
    int valores[50];
    int i=0; 
    const char separador[] = "+" ; // guaradar a soma para utilizar como base 
    scanf("%s", string);
    
    char * pedaco; // o atual 
    pedaco = strtok(string, separador); 
    while( pedaco != NULL ){
        int valor = atoi(pedaco);
        pedaco = strtok(NULL, separador); // null é para indicar continue
        valores[i]= valor; 
        i++; 
    }
    
    insertionsort(valores, i); 
    printOrdenado(valores,i);
    
    return 0;
}
