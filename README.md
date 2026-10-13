# Parallel and Distributed Computing

A collection of C programs exploring **parallel programming, concurrency, synchronization, workload scheduling, and performance scalability** using OpenMP and OpenMPI.

This repository contains implementations and experiments developed as part of learning Parallel and Distributed Computing, with a focus on understanding how parallel execution affects performance and how different parallel programming constructs work in practice.

## Technologies

- **C** — Core programming language
- **OpenMP** — Shared-memory parallel programming
- **OpenMPI** — Distributed-memory parallel programming

## Compilation and Execution

### OpenMP Programs

Compile an OpenMP program using `gcc-16` with the `-fopenmp` flag:

```bash
gcc-16 -fopenmp <programname>.c
./a.out
```

For example:

```bash
gcc-16 -fopenmp OMP-Barriers.c
./a.out
```

### OpenMPI Programs

Compile an MPI program using `mpicc` and execute it using `mpirun` with four processes:

```bash
mpicc <programname>.c
mpirun -np 4 ./a.out
```

For example:

```bash
mpicc OpenMPI/MPI-Block-P2P.c
mpirun -np 4 ./a.out
```

**Note:** Ensure that `gcc-16` and OpenMPI are installed and available in your system's PATH. Adjust the number of MPI processes (`-np 4`) as required by the program.

## Repository Structure

### OpenMP Programs

The current collection covers OpenMP directives, data-sharing attributes, synchronization mechanisms, parallel workloads, and scalability experiments.

| Program | Description |
|---|---|
| [`OMP-AVSensorScalability.c`](OMP-AVSensorScalability.c) | Exploring scalability using autonomous-vehicle sensor data |
| [`OMP-Barriers.c`](OMP-Barriers.c) | Synchronizing threads using barriers |
| [`OMP-Critical.c`](OMP-Critical.c) | Protecting shared resources using critical regions |
| [`OMP-FirstPrivate.c`](OMP-FirstPrivate.c) | Initializing private variables using their original values |
| [`OMP-GPU-Sim.c`](OMP-GPU-Sim.c) | Simulating GPU-like parallel execution using OpenMP threads |
| [`OMP-ImageBrightness.c`](OMP-ImageBrightness.c) | Parallel image brightness adjustment |
| [`OMP-LastPrivate.c`](OMP-LastPrivate.c) | Propagating the value from the logically last iteration or section |
| [`OMP-MatMulScalability.c`](OMP-MatMulScalability.c) | Investigating scalability in matrix multiplication |
| [`OMP-Ordered-Pvt.c`](OMP-Ordered-Pvt.c) | Exploring ordered execution and private data |
| [`OMP-ParallelSensorFusion.c`](OMP-ParallelSensorFusion.c) | Parallel processing for sensor fusion |
| [`OMP-Private.c`](OMP-Private.c) | Demonstrating thread-private variable scopes (`private` clause) |
| [`OMP-Race.c`](OMP-Race.c) | Demonstrating data race conditions and unsynchronized shared access |
| [`OMP-Reduction.c`](OMP-Reduction.c) | Combining thread-local results using reduction operations |
| [`OMP-Sections.c`](OMP-Sections.c) | Executing independent code sections in parallel |
| [`OMP-StaticSchedule.c`](OMP-StaticSchedule.c) | Exploring static loop work distribution and chunk size allocation |
| [`OMP-Tasks.c`](OMP-Tasks.c) | Implementing explicit dynamic task parallelism (`#pragma omp task`) |
| [`OMP-ThreadPrivate.c`](OMP-ThreadPrivate.c) | Maintaining thread-persistent copies of variables |

### OpenMPI Programs

Implementations focusing on message-passing concurrency and distributed-memory parallel patterns.

| Program | Description |
|---|---|
| [`MPI-Block-P2P.c`](OpenMPI/MPI-Block-P2P.c) | Blocking point-to-point communication (`MPI_Send` and `MPI_Recv`) |
| [`MPI-NB-P2P.c`](OpenMPI/MPI-NB-P2P.c) | Non-blocking point-to-point communication (`MPI_Isend` and `MPI_Irecv`) |
| [`MPI-P2P-Multiple.c`](OpenMPI/MPI-P2P-Multiple.c) | Point-to-point communication across multiple processes and messages |

## Learning Objectives

- Understand shared-memory and distributed-memory parallel programming.
- Explore synchronization, data sharing, and race conditions.
- Compare workload scheduling strategies and parallel execution patterns.
- Implement inter-process communication using MPI.
- Investigate performance scalability in computational workloads.