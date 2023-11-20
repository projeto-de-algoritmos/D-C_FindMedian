#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 11

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void ordenaArr(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void ordena(int **arr, int start, int finish, int linha) {
    int i, j;
    for (i = start; i <= finish; i++) {
        for (j = start; j <= finish - i - 1; j++) {
            if (arr[linha][j] > arr[linha][j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[linha][j];
                arr[linha][j] = arr[linha][j + 1];
                arr[linha][j + 1] = temp;
            }
        }
    }
}

int GetMedian(int *array, int size) {
    if(size <= 5){
        ordenaArr(array, size);
        switch (size){
        case 1:

        case 2:
            return array[0];
            break;
        case 3:

        case 4:
            return array[1];
            break;
        case 5:
            return array[2];
            break;
        default:
            break;
        }
    }
    int qut_linhas = size/5;
    int resto = size % 5;
    int x = 0;
    if(resto == 0){
        //alocando matriz
        int **m = calloc(sizeof(int*), qut_linhas);
        for(int i = 0; i < qut_linhas; i++)
            m[i] = calloc(sizeof(int), 5);
        //

        //passando valores do array pra matriz e ordenando linha
        for(int i = 0; i < qut_linhas; i++){
            for(int j = 0; j < 5; j++, x++){
                m[i][j] = array[x];
                ;
            }
            
            ordena(m, 0, 4, i);
        }
        //

        //print array
        printf("\n");
        for (int i = 0; i < size; i++){
            printf("array[%d]: %d\n", i,array[i]);
        }
        printf("\n");

        // Print the matrix m
        for (int i = 0; i < qut_linhas; i++) {
            for (int j = 0; j < 5; j++) {
                printf("m[%d][%d]: %d\n", i, j, m[i][j]);
            }
        }

        // pegando a mediana da mediana
        int *mediana_das_medianas = malloc(sizeof(int) * qut_linhas);
        x = 0;
        for(int i = 0; i < qut_linhas; i++, x++){
            mediana_das_medianas[x] = m[i][2];
        }
        //

        return GetMedian(mediana_das_medianas, qut_linhas);

    } else{
        qut_linhas++;

        //alocando matriz
        int **m = calloc(sizeof(int*), qut_linhas);
        for(int i = 0; i < qut_linhas; i++)
            m[i] = calloc(sizeof(int), 5);
        //

        //passando valores do array pra matriz e ordenando linha
        int x = 0;
        int i = 0;
        int j = 0;
        for(; i < qut_linhas - 1; i++){
            for (; j < 5; j++, x++)
                m[i][j] = array[x];
            ordena(m, 0, 4, i);
        }


        switch (resto){
        case 1:
            m[i][2] = array[x];
            break;
        
        case 2:
            m[i][2] = array[x++];
            m[i][3] = array[x];
            if(m[i][2] > m[i][3]){
                int h = m[i][3];
                m[i][3] = m[i][2];
                m[i][2] = h;
            }
            break;

        case 3:
            m[i][1] = array[x++];
            m[i][2] = array[x++];
            m[i][3] = array[x];
            ordena(m, 1, 3, i);
            break;

        case 4:
            m[i][1] = array[x++];
            m[i][2] = array[x++];
            m[i][3] = array[x++];
            m[i][4] = array[x];
            ordena(m, 1, 4, i);
            break;
        default:
            break;
        } //end switch

        // pegando a mediana da mediana
        int *mediana_das_medianas = malloc(sizeof(int) * qut_linhas);
        x = 0;
        for(int i = 0; i < qut_linhas; i++){
            mediana_das_medianas[x++] = m[i][2];
        }
        //

        return GetMedian(mediana_das_medianas, qut_linhas);

    } //end else
        
} //end function


int exotericSelect(int *array, int k, int arraySize, int *L, int *R, int *I){
    
    printf("na função:");
    for(int i = 0; i < arraySize; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    int PossibleMedian = GetMedian(array, arraySize); //GET POSSIBLE MEDIAN OF ARRAY

    //separate array
    int Isize = 0;
    int Rsize = 0;
    int Lsize = 0;
    for(int i = 0; i < arraySize; i++){
        
        if(array[i] < PossibleMedian){
            L[Lsize] = array[i];
            Lsize++;

        }else if(array[i] == PossibleMedian){
            I[i] = array[i];
            Isize++;

        } else if (array[i] > PossibleMedian){
            R[Rsize] = array[i];
            Rsize++;
        }
    }

    for(int i = 0; i < Isize - 1; i++){
        L[Lsize] = I[i];
        Lsize++;
    }

    //

    printf("\n\n");
    printf("PossibleMedian: %d\n", PossibleMedian);
    printf("Lsize: %d\n", Lsize);
    printf("L:");
    for(int i = 0; i < Lsize; i++){
        printf(" %d,", L[i]);
    }
    printf("\n");
    printf("Rsize: %d\n", Rsize);
    printf("\nR:");
    for(int i = 0; i < Rsize; i++){
        printf(" %d,", R[i]);
    }
    printf("\n\n");


    if(Lsize - 1 == k-1) return PossibleMedian;
    else if(Lsize - 1 > k-1){ 
        return exotericSelect(L, k, Lsize, L, R, I);
    }
    else{
        return exotericSelect(R, k-Lsize-1, Rsize, L, R, I);
    }

}

void escope(){
    int initValue[ARRAY_SIZE] = {16, 27, 80, 79, 40, 3, 2, 58, 65, 48, 5};

    int k;
    if(ARRAY_SIZE % 2 == 0)
        k = ARRAY_SIZE/2 - 1; //MEDIAN NUMBER
    else
        k = ARRAY_SIZE/2;

    printf("k(indice da mediana) = %d\n", k);

    int *array = malloc(sizeof(int) * ARRAY_SIZE);
    if(array == NULL){
        perror("malloc");
        return; 
    }

    printf("inicial:");
    for(int i = 0; i < ARRAY_SIZE; i++){
        array[i] = initValue[i];
        printf("%d ", array[i] );
    }
    printf("\n");

    int *I = malloc(sizeof(int) * ARRAY_SIZE);
    int *R = malloc(sizeof(int) * ARRAY_SIZE);
    int *L = malloc(sizeof(int) * ARRAY_SIZE);

    int p = exotericSelect(array, k, ARRAY_SIZE, L, R, I);

    printf("-----MEDIANA FINAL: %d -------", p);
}



int main(){
    escope();
    return 0;
}