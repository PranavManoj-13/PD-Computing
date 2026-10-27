// MPI Single-Sided Communication Program for Get

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int data = 1000 + rank;
    MPI_Win win;
    MPI_Win_create(&data, sizeof(int), sizeof(int), MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    int recvValue = -1;

    MPI_Win_fence(0, win);

    if (rank == 0) {
        printf("Process %d: Fetching value from window.\n", rank);
        MPI_Get(&recvValue, 1, MPI_INT, 1, 0, 1, MPI_INT, win);
    }

    MPI_Win_fence(0, win);

    if (rank == 0) {
        printf("Process %d: Successfully fetched value %d from window.\n", rank, recvValue);
    }

    if (rank == 1) {
        printf("Process %d: Providing value %d to window.\n", rank, data);
    }

    MPI_Win_free(&win);
    MPI_Finalize();
    return 0;
}