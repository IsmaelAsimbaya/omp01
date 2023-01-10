#include <iostream>
#include <omp.h>
#include <chrono>

namespace ch = std::chrono;
#define NUMERO_ITERACIONES 1000000000
/*int main() {

    #pragma omp parallel default(none)
    {
        int nthreads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();

        std::printf("Hello OpenMP\n");
        std::printf("I have %d thread(s) and my thread_is is %d\n", nthreads, thread_id);
    }

    #pragma omp parallel default(none)
    {
        if (omp_get_thread_num()==0){
            std::printf("I have %d proc(s)\n", omp_get_num_procs());
            std::printf("I have %d thread(s)\n", omp_get_num_threads());
        }

        int thread_id = omp_get_thread_num();

        std::printf("My thread_id is %d\n", thread_id);

    }

    return 0;
}*/

double pi_serial(){
    double respuesta = 0.0;
    bool esIndicePar = true;
    for (long indice =0; indice <= NUMERO_ITERACIONES;indice++){
        if (esIndicePar == true){
            respuesta += 4.0/(2.0*indice+1.0);
        }else{
            respuesta -= 4.0/(2.0*indice+1.0);
        }
        esIndicePar = !esIndicePar;
    }
    return respuesta;
}

double pi_omp1(){

    //omp_set_num_threads(16);
    int numero_hilos = 0;

    #pragma omp parallel
    {
        #pragma omp master
        numero_hilos = omp_get_num_threads();
    };

    std::printf("Thread count: %d\n", numero_hilos);

    double sumas_paricales[numero_hilos];

    #pragma omp parallel shared(sumas_paricales)
    {
        int thread_id = omp_get_thread_num();

        for (long indice =thread_id; indice <= NUMERO_ITERACIONES;indice+=numero_hilos){
            if (thread_id%2==0){
                sumas_paricales[thread_id] += 4.0/(2.0*indice+1.0);
            }else{
                sumas_paricales[thread_id] -= 4.0/(2.0*indice+1.0);
            }
        }
    };

    double respuesta = 0;
    for (int i = 0; i < numero_hilos; i++) {
        respuesta = respuesta + sumas_paricales[i];
    }
    return respuesta;
}

int main(){
    double pi1;
    auto start = ch::high_resolution_clock::now();
    {
        pi1 = pi_omp1();
    }
    auto end = ch::high_resolution_clock::now();
    ch::duration<double,std::milli> duracion = end-start;

    std::printf("Tiempo serial: %lf, pi=%.10lf\n", duracion.count(), pi1);

    return 0;
}
