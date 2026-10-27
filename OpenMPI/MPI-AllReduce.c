#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int localVal, globalSum;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    localVal = rank + 1;

    MPI_Allreduce(&localVal, &globalSum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Process %d: Global Sum = %d\n", rank, globalSum);

    MPI_Finalize();
    return 0;
}