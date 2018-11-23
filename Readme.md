KMer-HLS: Fast K-mer counting in an FPGA

This project is intended to be a building block for a future FPGA Genomics project.

The current implementation is extremely memory-intensive. Since the k-mer indices are not hashed,
the output buffer is extremely sparse. 
