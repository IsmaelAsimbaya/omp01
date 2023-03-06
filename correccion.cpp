#include <iostream>
#include <omp.h>
#include <cstdio>
#include <cmath>

using namespace std;

float distancia(int a[], int b[]){
    return sqrt(pow((b[0]-a[0]),2)+pow((b[1]-a[1]),2)+pow((b[2]-a[2]),2));
}

int menor(float d[]){
    int index = 0;
    float aux = d[0];
    for(int i=0;i<3;i++){
        if(d[i]<aux){
            index = i;
            aux = d[i];
        }
    }
    return index;
}

void print_vector(int a[], int index){
    std::printf("\n (%d, %d, %d) i:%d",a[0],a[1],a[2],index);
}

void print_vector(float a[]){
    std::printf("\n (%f, %f, %f) ",a[0],a[1],a[2]);
}

void distancia_centros(int n, int a[n][3], int c[3][3]){
    int numero_hilos = 0;

    #pragma omp parallel
    {
        #pragma omp master
        numero_hilos = omp_get_num_threads();
    };

    std::printf("Thread count: %d\n", numero_hilos);

    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i<n; i++){
            float dist[] = {(distancia(a[i],c[0])),
                            (distancia(a[i],c[1])),
                            (distancia(a[i],c[2]))};
            //print_vector(dist);
            int index = menor(dist);
            print_vector(a[i],index);
        }
    };
}

int main(int argc, char** argv){

    int n = 30;
    int C[3][3];
    int A[n][3];

    std::srand(std::time(nullptr));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < 3; j++){
            A[i][j] = std::rand() % 10 + 1;
        }
    }

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            C[i][j] = std::rand() % 10 + 1;
        }
    }

    std::printf("\n Centros: \n");
    for (int i = 0; i < 3; i++) {
        for(int j = 0;j<3;j++){
            std::printf("%d, ", C[i][j]);
        }
        std::printf("\n");
    }

    distancia_centros(n,A,C);

    return 0;
}