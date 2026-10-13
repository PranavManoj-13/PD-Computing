#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int rank, size;
    int data;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size < 4) {
        if (rank == 0)
            printf("Please run with at least 4 processes.\n");

        MPI_Finalize();
        return 0;
    }

    if (rank == 0 || rank == 1) {
        int dest = rank + 2;

        for (int i = 1; i <= 5; i++) {
            data = rank * 100 + i;

            printf("Process %d sending message %d with data = %d to process %d.\n",
                   rank, i, data, dest);

            MPI_Send(&data, 1, MPI_INT, dest, i, MPI_COMM_WORLD);
        }
    }

    else if (rank == 2 || rank == 3) {
        int source = rank - 2;

        for (int i = 1; i <= 5; i++) {
            MPI_Recv(&data, 1, MPI_INT, source, i,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            printf("Process %d received message %d with data = %d from process %d.\n",
                   rank, i, data, source);
        }
    }

    MPI_Finalize();
    return 0;
}