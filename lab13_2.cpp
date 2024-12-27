#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double arr[], int N, double result[]) {
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    result[0] = sum / N;

    double sum_sq_diff = 0.0;
    for (int i = 0; i < N; i++) {
        sum_sq_diff += pow(arr[i] - result[0], 2);
    }
    result[1] = sqrt(sum_sq_diff / N);

    double product = 1.0;
    for (int i = 0; i < N; i++) {
        product *= arr[i];
    }
    result[2] = pow(product, 1.0 / N);

    double sum_reciprocal = 0.0;
    for (int i = 0; i < N; i++) {
        sum_reciprocal += 1.0 / arr[i];
    }
    result[3] = N / sum_reciprocal;

    result[4] = arr[0];
    result[5] = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > result[4]) {
            result[4] = arr[i];
        }
        if (arr[i] < result[5]) {
            result[5] = arr[i];
        }
    }
}
