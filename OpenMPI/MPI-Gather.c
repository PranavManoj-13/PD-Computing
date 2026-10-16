#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int sendVal, recvVal[8];

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    sendVal = rank + 10;
    MPI_Gather(&sendVal, 1, MPI_INT, recvVal, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Root collected: ");
        for(int i=0; i < size; i++)
            printf("%d ", recvVal[i]);
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}