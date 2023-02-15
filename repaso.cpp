#include <iostream>
#include <omp.h>
#include <cmath>

using namespace std;

struct arreglo{
    int arr[4];
};

struct arreglo n_perfect_serial(int num){
    struct arreglo arr;
    int count = 0;
    for (int i = 2; i <= num; i++) {
        int suma = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                suma += j;
            }
        }
        if (suma == i){
            arr.arr[count] = i;
            count++;
        }
    }
    return arr;
}

struct arreglo n_perfect_paralelo(int num){

    int numero_hilos = 0;

    #pragma omp parallel
    {
        #pragma omp master
        numero_hilos = omp_get_num_threads();
    };

    std::printf("Thread count: %d\n", numero_hilos);

    struct arreglo arr;
    int count = 0;
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 2; i <= num; i++) {
            int suma = 0;
            for (int j = 1; j <= i / 2; j++) {
                if (i % j == 0) {
                    suma += j;
                }
            }
            if (suma == i){
                arr.arr[count] = i;
                count++;
            }
        }
    };

    return arr;
}

int main(int argc, char** argv){
    struct arreglo result = n_perfect_paralelo(10000);
    int lenght = sizeof(result.arr) / sizeof(result.arr[0]);
    for (int i = 0; i < lenght; i++) {
        std::printf("Numero Perfecto[%d]: %d\n",i, result.arr[i]);
    }
    return 0;
}