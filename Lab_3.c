//
// Created by Great_Society on 15.11.2020.
//
//Даны натуральное число n, действительное число x, действительная
//матрица размера n*2n. Получить последовательность b1,...,bn из нулей и
//единиц, где bi=1, если элементы i-ой строки матрицы не превосходят x, и bi=0 в
//противном случае.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define TRUE 1
#define FALSE 0

int main (){
    int rows, colm;
    double x;

    // Ввод N
    do {
        printf("Please, specify the dimension of the matrix:");
        scanf("\n%d",&rows);
        fflush(stdin);

    }while(rows == 0);

    colm = rows*2;

    // Ввод X
        printf("\nPlease, specify a real number for comparison:");
        scanf("\n%lf", &x);

    time_t timeSeed;
    srand(time(&timeSeed));

    double matrix[rows][colm];
    int boolMatrix[rows];

    // Заполняем массив рандомом
    puts("\nMatrix for search:");
    for( int i = 0; i <rows; i++, putchar('\n')){
        for (int j = 0; j < colm; j++){
            matrix[i][j] = (rand()%((rows*3) - (-rows*3)) + (-rows*3))/(x*2)+1.0;
            printf("% 2.1lf ", matrix[i][j]);
        }
    }

    // Поиск в двумерном массиве и установлние последовательности 0 и 1
    puts("\n0 - if we have one element in string more than X, else - 1:");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colm; j++){
            if (matrix[i][j] >= x){
                boolMatrix[i] = FALSE;
                break;
            }
            boolMatrix [i] = TRUE;
        }
        printf(" %d ",boolMatrix[i]);
    }

   return 0;
}