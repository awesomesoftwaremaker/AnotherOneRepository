#include <stdio.h>
#include <math.h>

int n = 4;

float A[n][n] = {1.7, 0.0003, 0.0004, 0.0005, 0.0, 0.8, 0.0001, 0.0002, -0.0003, -0.0002, -0.1, 0.0, -0.0005, -0.0004, -0.0003, -1.0};

float B[n] = {0.681, 0.4803, -0.802, -1.0007};
float X[30][n] = {0};
float TEST[n];
float summ;
float eps;
int k = 0;

//Условие окончания работы программы
bool ExitFunc(float eps)
{
    if(k == 0) return true;
    for(int i = 0; i < n; i++) {
        if( fabs(X[k][i] - X[k - 1][i]) > eps )
            return true;
    }
    return false;
}

int main()
{
    printf("Enter eps:");//Взятие погрешности
    scanf("%f", &eps);
    do {
        for(int i = 0; i < n; i++) {
            summ = 0;
            for(int j = 0; j < n; j++)
                if(i != j)
                    summ += A[i][j] * X[k][j];
            X[k + 1][i] = (1 / A[i][i]) * (B[i] - summ);
        }
        k++;
    } while(ExitFunc(eps));

//Проверка
    printf("\nResult:\n");
    for(int j = 0; j < n; j++)
        printf("%4.8f ", X[k][j]);

    printf("\nTest:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            TEST[i] += (A[i][j] * X[k][j]);
        printf("%4.8f ", TEST[i]);
    }

    printf("\nIterations:\n%i", k);
}
