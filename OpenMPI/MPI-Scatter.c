#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int sendData[8], recvData;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for(int i=0;i<8;i++)
            sendData[i] = i + 1;
    }

    MPI_Scatter(&sendData[0], 1, MPI_INT, &recvData, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // MPI_Scatter(const void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, 
                // int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);

    printf("Process %d received %d\n",rank,recvData);
    MPI_Finalize();
    return 0;
}