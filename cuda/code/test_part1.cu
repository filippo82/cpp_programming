#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>

// CPU version - Serial - One thread
void add_cpu(int n, float *x, float *y)
{
   for (int i=0; i<n; i++)
   {
      y[i] = cos(x[i]) + sin(y[i]);
   }
}

// Kernel function to add the elements of two arrays
__global__
void add_gpu(int n, float *x, float *y, int a)
{
  // int index = threadIdx.x;
  // int stride = blockDim.x;
  // int check = 0;
  // int index = blockIdx.x * blockDim.x + threadIdx.x;
  // int stride = blockDim.x * gridDim.x;
  // if (check == 0) {
  //     printf("Stride for blockDim = %d is %d\n", a, stride);
  //     check = 1;
  // }
  for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < n; i += blockDim.x * gridDim.x)
  {
    // y[i] = x[i] + y[i];
    y[i] = a;
    // y[i] = cos(x[i]) + sin(y[i]);
  }
}

void checkCudaDevices()
{
  int nDevices;
  cudaGetDeviceCount(&nDevices);
  for (int i = 0; i < nDevices; i++) {
      cudaDeviceProp prop;
      cudaGetDeviceProperties(&prop, i);
      printf("Device Number: %d\n", i);
      printf("  Device name: %s\n", prop.name);
      printf("  Memory Clock Rate (KHz): %d\n", prop.memoryClockRate);
      printf("  Memory Bus Width (bits): %d\n", prop.memoryBusWidth);
      printf("  Peak Memory Bandwidth (GB/s): %f\n", 2.0*prop.memoryClockRate*(prop.memoryBusWidth/8)/1.0e6);
      printf("  Major: %d\n", prop.major);
      printf("  Minor: %d\n", prop.minor);
      printf("  Multiprocess count: %d\n", prop.multiProcessorCount);
      printf("  Max dimension size of a grid size (x,y,z): (%d, %d, %d)", prop.maxGridSize[0], prop.maxGridSize[1], prop.maxGridSize[2]);
      // printf("  Max grid size: %d\n", prop.maxGridSize[0]);
      printf("\n");
  }
}

int main(void)
{
  checkCudaDevices();
  int numSMs;
  int devId = 0;
  cudaDeviceGetAttribute(&numSMs, cudaDevAttrMultiProcessorCount, devId);
  // std::cout << "NumSMs: " << numSMs << std::endl;

  int n = 1 << 20; // Around 4GB
  float *x, *y;

  // Allocate Unified Memory – accessible from CPU or GPU
  cudaMallocManaged(&x, n*sizeof(float));
  cudaMallocManaged(&y, n*sizeof(float));

  // Initialize x and y arrays on the host
  for (int i = 0; i < n; i++)
  {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  double avg = 0;
  clock_t t;

  // Runs add 10 times on CPU
  // for(int i=0; i<10; i++)
  // {
  //   t = clock(); //start time
  //   add_cpu(n, x, y);
  //   t = clock() - t; //total time = end time - start time
  //   printf("CPU RUN-%d time = %f ms.\n",i,(((float)t)/CLOCKS_PER_SEC)*1000);
  //   avg += ((((float)t)/CLOCKS_PER_SEC)*1000);//time is calculated in terms of clockcycle. Converted in millisecond
  // }
  // std::cout << "The average time on CPU is: " << avg / 10.0 << " ms" << std::endl;

  // Run kernel on 20M elements on the GPU
  // add_gpu<<<1, 512>>>(N, x, y);

  // Wait for GPU to finish before accessing on host
  // cudaDeviceSynchronize();

  int data[10];

  // Runs add 10 times on GPU
  for(int i=32; i<=1024; i+=32)
  {
    avg = 0;
    for(int j=0; j<1; j++)
    {
      t = clock(); // Start time
      int blockSize = 1024 - i + 32; // Threads per block
      int numBlocks = (n + blockSize - 1) / blockSize;
      // add_gpu<<<dim3(i, 1, 1), dim3(16, 1, 1)>>>(n, x, y);
      add_gpu<<<numBlocks, blockSize>>>(n, x, y, blockSize);
      // add_gpu<<<256*numSMs, blockSize>>>(n, x, y);
      cudaDeviceSynchronize();
      t = clock() - t; // Total time = end time - start time
      printf("<<<%d, %d>>> - GPU RUN-%d time = %f ms.\n",numBlocks, blockSize, j,(((float)t)/CLOCKS_PER_SEC)*1000);
      avg += ((((float)t)/CLOCKS_PER_SEC)*1000);// Time is calculated in terms of clockcycle. Converted in millisecond
    }
    data[i] = avg / 10.0;
    // std::cout << "The average time on GPU is: " << data[i] << " ms" << std::endl;
    std::cout << y[100] << std::endl;
  }

  // std::cout << y[1] << std::endl;

  // Free memory
  cudaFree(x);
  cudaFree(y);
  return 0;
}
