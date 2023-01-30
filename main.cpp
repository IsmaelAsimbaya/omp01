#include <iostream>
#include <omp.h>
#include <chrono>
#include <benchmark/benchmark.h>

namespace ch = std::chrono;
#define NUMERO_ITERACIONES 1000000000

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

double pi_omp1_parallelFor(){

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

        #pragma omp for
        for (long i =0; i <= NUMERO_ITERACIONES;i++){
            if (i%2==0){
                sumas_paricales[thread_id] += 4.0/(2.0*i+1.0);
            }else{
                sumas_paricales[thread_id] -= 4.0/(2.0*i+1.0);
            }
        }
    };

    double respuesta = 0;
    for (int i = 0; i < numero_hilos; i++) {
        respuesta = respuesta + sumas_paricales[i];
    }
    return respuesta;
}

static void BM_piSerial(benchmark::State& state){
    double value;
    for (auto _ : state) {
        value = pi_serial();
    }
    std::printf("El valor de pi serial es %f\n", value);
}

static void BM_piOmp1(benchmark::State& state) {
    double value;
    for (auto _ : state) {
        value = pi_omp1();
    }
    std::printf("El valor de pi paralelo es %f\n", value);
}

static void BM_piOmp2(benchmark::State& state) {
    double value;
    for (auto _ : state) {
        value = pi_omp1_parallelFor();
    }
    std::printf("El valor de pi for paralelo es %f\n", value);
}

BENCHMARK(BM_piSerial)
        ->Unit(benchmark::kMillisecond)
        ->Iterations(1)
        ->Repetitions(5);

BENCHMARK(BM_piOmp1)
        ->Unit(benchmark::kMillisecond)
        ->Iterations(1)
        ->Repetitions(5);

BENCHMARK(BM_piOmp2)
        ->Unit(benchmark::kMillisecond)
        ->Iterations(1)
        ->Repetitions(5);

int main(int argc, char** argv){
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::Shutdown();
    return 0;
}
