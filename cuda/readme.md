
## Resources

* [An Even Easier Introduction to CUDA](https://devblogs.nvidia.com/even-easier-introduction-cuda/)
* [CUDA Pro Tip: Write Flexible Kernels with Grid-Stride Loops](https://devblogs.nvidia.com/cuda-pro-tip-write-flexible-kernels-grid-stride-loops/)
* [CUDA Grid-Stride Loops: What if you Have More Data Than Threads?](https://alexminnaar.com/2019/08/02/grid-stride-loops.html)

```shell
$ nnvcc --version
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2018 NVIDIA Corporation
Built on Sat_Aug_25_21:08:01_CDT_2018
Cuda compilation tools, release 10.0, V10.0.130
```

[Pascal microarchitecture](https://en.wikipedia.org/wiki/Pascal_(microarchitecture))

GP104 chip

20 Streaming Multiprocessors (SMs) with 128 CUDA cores each

Equipped with 2560 CUDA cores and 16GB of GDDR5X GPU memory

Compute Capability 6.1


kernelName<<<GridSize, BlockSize, SMEMSize, Stream>>>(arguments, ...);


[cudaDeviceProp Struct Reference](https://docs.nvidia.com/cuda/cuda-runtime-api/structcudaDeviceProp.html#structcudaDeviceProp)