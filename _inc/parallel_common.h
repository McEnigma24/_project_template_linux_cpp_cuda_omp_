#pragma once

#ifdef CPU
#include <omp.h>
#endif

#ifdef GPU
#include "cuda_runtime.h"
#include "curand_kernel.h"
#include "device_launch_parameters.h"
#endif
