#include <stdlib.h> 
#include <stdio.h> 


int defineHeight(int M){
    
    if(M < 1 || M > 16){
        return -1; 
    } 

    return M; 
} 

int defineWidth(int N){
    if(N < 1 || N > 16){
        return -1;
    }
    return N; 
} 

int maxDomino(int domTam, int M, int N){
    int multiple = M*N;
    return multiple/domTam;
}

int defineDomTam(){
    return 2; 
}

int main( ){
    int M, N,TAM, result; 
    TAM = defineDomTam();

    scanf("%d %d", &M, &N);
    
    M = defineHeight(M);

    if(M == -1){
        printf("invalido");
        return 0;
    }

    N = defineWidth(N);
     if(N == -1){
        printf("invalido");
        return 0;
    }
    
    result =  maxDomino(TAM, M, N);

    printf("%d",result);
}