#include <iostream>
#include <omp.h>

int main() {
    /*
    #pragma omp parallel default(none)
    {
        int nthreads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();

        std::printf("Hello OpenMP\n");
        std::printf("I have %d thread(s) and my thread_is is %d\n", nthreads, thread_id);
    }*/

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
}
