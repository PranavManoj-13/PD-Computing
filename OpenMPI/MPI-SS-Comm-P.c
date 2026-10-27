// MPI Single-Sided Communication Program for Put

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int data = 0;
    MPI_Win win;
    MPI_Win_create(&data, sizeof(int), sizeof(int), MPI_INFO_NULL, MPI_COMM_WORLD, &win);
    MPI_Win_fence(0, win);

    if (rank == 0) {
        int value = 73;
        printf("Process %d: Putting value %d into window.\n", rank, value);
        MPI_Put(&value, 1, MPI_INT, 1, 0, 1, MPI_INT, win);
    }

    MPI_Win_fence(0, win);

    if (rank == 1) {
        printf("Process %d: Value in window is %d.\n", rank, data);
    }

    MPI_Win_free(&win);
    MPI_Finalize();
    return 0;
}