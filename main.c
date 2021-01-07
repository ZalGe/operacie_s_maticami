#include <stdio.h>

#define N 20

void LoadMatrix (int AMatrix [N][N], int BMatrix [N][N], int A_r, int A_c, int B_r, int B_c);
void SumMatrix (int AMatrix [N][N], int BMatrix [N][N], int SumMatrix [N][N], int A_r, int A_c, int B_r, int B_c);
void ProductMatrix (int AMatrix [N][N], int BMatrix [N][N], int ProductMatrix [N][N], int A_r, int A_c, int B_r, int B_c);
void PrintMatrix (int matrix [N][N], int r, int c);


int main() {
    int A [N][N], B [N][N], C [N][N], D [N][N], A_r, A_c, B_r, B_c;

    printf("Enter number of rows and columns of matrix A.\n");
    scanf("%d %d", &A_r, &A_c);
    printf("Enter number of rows and columns of matrix B.\n");
    scanf("%d %d", &B_r, &B_c);

    LoadMatrix(A, B, A_r, A_c, B_r, B_c);
    SumMatrix(A, B, C, A_r, A_c, B_r, B_c);
    ProductMatrix(A, B, D, A_r, A_c, B_r, B_c);

    return 0;
}

void LoadMatrix(int (*AMatrix)[20], int (*BMatrix)[20], int A_r, int A_c, int B_r, int B_c) {
    printf("Enter matrix A: \n");

    for (int i = 0; i < A_r; ++i) {
        for (int j = 0; j < A_c; ++j) {
            scanf("%d", &AMatrix[i][j]);
        }
    }

    printf("Enter matrix B: \n");

    for (int i = 0; i < B_r; ++i) {
        for (int j = 0; j < B_c; ++j) {
            scanf("%d", &BMatrix[i][j]);
        }
    }
}

void SumMatrix(int AMatrix [N][N], int BMatrix [N][N], int SumMatrix [N][N], int A_r, int A_c, int B_r, int B_c) {
    if (A_r == B_r && A_c == B_c){
        for (int i = 0; i < A_r; ++i) {
            for (int j = 0; j < A_c; ++j) {
                SumMatrix [i][j] = AMatrix[i][j] + BMatrix [i][j];
            }
        }
        printf("Sum of this two matrices is: \n");
        PrintMatrix(SumMatrix, A_r, A_c);
    } else
        printf("Cannot sum up this two matrices!");

}

void ProductMatrix(int AMatrix [N][N], int BMatrix [N][N], int ProductMatrix [N][N], int A_r, int A_c, int B_r, int B_c) {
    int sum = 0;

    if (A_c == B_r) {
        for (int i = 0; i < A_r; ++i) {
            for (int j = 0; j < B_c; ++j) {
                for (int k = 0; k < A_c; ++k) {
                    sum = sum + AMatrix[i][k] * BMatrix[k][j];
                }

                ProductMatrix[i][j] = sum;
                sum = 0;
            }
        }
        printf("Product of this two matrices is: \n");
        PrintMatrix(ProductMatrix, A_r, B_c);
    } else
        printf("Cannot make a product of these two matrices!");

}

void PrintMatrix(int (*matrix)[20], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
