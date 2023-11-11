#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int GetMedian(int *array) {
    int x = rand();
    return array[x++];
}

int exotericSelect(int *array, int k, int arrayFinish, int *L, int *R){

    int PossibleMedian = GetMedian(array); //GET POSSIBLE MEDIAN OF ARRAY
    //falta a implmentação do GetMedian

    //separate array
    int Rsize = 0;
    int Lsize = 0;
    for(int i = 0; i < arrayFinish; i++){
        
        if(array[i] < PossibleMedian){
            L[Lsize] = array[i];
            if(Lsize != 0) swap(L, Lsize, Lsize-1);
            Lsize++;

        }else if(array[i] == PossibleMedian){
            L[Lsize] = array[i];
            Lsize++;

        } else if (array[i] > PossibleMedian){
            R[Rsize] = array[i];
            Rsize++;
        }

    }
    //

    printf("\n\n");
    printf("---%d---\n", PossibleMedian);
    printf("L:");
    for(int i = 0; i < Lsize; i++){
        printf(" %d,", L[i]);
    }
    printf("\nR:");
    for(int i = 0; i < Rsize; i++){
        printf(" %d,", R[i]);
    }
    printf("\n\n");


    if(Lsize == k-1) return PossibleMedian;
    else if(Lsize > k-1){ 
        return exotericSelect(L, k, Lsize, L, R);
    }
    else{
        return exotericSelect(R, k-Lsize-1, Rsize, L, R);
    }

}

void escope(){
    int initValue[ARRAY_SIZE] = {66, 39, 98, 93, 62, 73, 95, 31, 45, 82};

    int k = ARRAY_SIZE/2; //MEDIAN NUMBER
    printf("K = %d\n", k);
    int *array = malloc(sizeof(int) * ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++){
        array[i] = initValue[i];
        printf(" %d ", array[i] );
    }
    int arrayFinish = ARRAY_SIZE;
    int *R = malloc(sizeof(int) * ARRAY_SIZE);
    int *L = malloc(sizeof(int) * ARRAY_SIZE);
    int x = exotericSelect(array, k, arrayFinish, L, R);
    printf("%d", x);
}



int main(){
    escope();
    return 0;
}