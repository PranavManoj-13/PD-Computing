#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&rank, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int dataSend, dataRecv;
    MPI_Request request_send, request_recv;
    MPI_Status status;

    if (rank == 0) {
        dataSend = 123;
        printf("Process %d: Starting non-blocking send of data = %d\n",rank,dataSend);

        MPI_Isend(&dataSend, 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &request_send);

        printf("Process %d: Doing some other work while message is being sent.\n",rank);

        MPI_Wait(&request_send, &status);
        printf("Process %d: Send completed successfully.\n",rank);
    }

    else if (rank == 1) {
        MPI_Irecv(&dataRecv, 1, MPI_INT, 0, 99, MPI_COMM_WORLD, &request_recv);
        printf("Process %d: Posted non-blocking receive from Process 0 (tag 99)\n",rank);
        printf("Process %d: Doing other computation while waiting.\n",rank);

        MPI_Wait(&request_recv, &status);
        int count;
        MPI_Get_count(&status, MPI_INT, &count);

        printf("Process %d: Received data = %d from Process 0 (tag 99), count = %d\n",rank,dataRecv,count);
    }
    MPI_Finalize();
    return 0;
}