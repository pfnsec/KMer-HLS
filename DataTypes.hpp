#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP


#include <stdint.h>

#ifdef _XILINX

#include "ap_int.h"

#define MER_WIDTH 6
#define FIFO_LEN 32

typedef ap_int<MER_WIDTH> mer_t;

#else

#define MER_WIDTH 8
#define FIFO_LEN 32

typedef uint8_t mer_t;


#endif 


#endif
