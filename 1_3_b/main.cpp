/*#include <iostream>

using namespace std;

int main()
{
    float Array [4][4] = {1.7, 0.0003, 0.0004, 0.0005, 0.0, 0.8, 0.0001, 0.0002, -0.0003, -0.0002, -0.1, 0.0, -0.0005, -0.0004, -0.0003, -1.0};

    float Brray [4] = {0.681, 0.4803, -0.802, -1.0007};

    float Xrray [4][4] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    cout << Array[3][3] << endl << Brray[3] << endl << Xrray [3][3] << "123123123";

}
*/
//Очевидно, что написанный код - мой, никакого подвоха
//#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <math.h>


const int n = 4;

float A[n][n] = {1.7, 0.0003, 0.0004, 0.0005, 0.0, 0.8, 0.0001, 0.0002, -0.0003, -0.0002, -0.1, 0.0, -0.0005, -0.0004, -0.0003, -1.0};

float B[n] = {0.681, 0.4803, -0.802, -1.0007};

float X[30][n] = {0};
float TEST[n];
float summ;
float eps;
int k = 0;


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
    printf("Enter eps:");
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
    getch();
}
