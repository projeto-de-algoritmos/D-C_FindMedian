#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int * separateArray(int *array, int PossibleMediuan){
    int R = ARRAY_SIZE - 1;
    int L = 0;
    int *subArray = malloc(sizeof(int) * ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(array[i] <= PossibleMediuan){
            if (array[i] == PossibleMediuan){
                subArray[L] = array[i];
                L++;
            } else{
                subArray[L] = array[i];
                if(L != 0) swap(subArray, L, L-1);
                L++;
            }

        } else if (array[i] > PossibleMediuan){
            subArray[R] = array[i];
            R--;
        }
    }
    return subArray;
}

void exotericSelect(){
    int array[ARRAY_SIZE] = {66, 39, 98, 93, 62, 73, 95, 31, 45, 82};
    
    int medianNumber = ARRAY_SIZE/2; //MEDIAN NUMBER

    int PossibleMediuan = GetMedian(array, 100); //GET POSSIBLE MEDIAN OF ARRAY

    int *subArray = separateArray(array, PossibleMediuan);
    
    
    printf("---%d---\n", PossibleMediuan);
    for(int i = 0 ; i < ARRAY_SIZE; i++){
        printf(" %d,", subArray[i]);
    }
}

int main(){
    exotericSelect();
    return 0;
}