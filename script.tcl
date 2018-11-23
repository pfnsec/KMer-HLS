open_project kmer_hls
set_top KMerCount

set tb_flags "-Wno-unknown-pragmas -D_XILINX"


add_files KMerCount.cpp 
add_files KMer.hpp 


add_files -tb KMer.hpp      -cflags $tb_flags
add_files -tb KMerCount.hpp -cflags $tb_flags
add_files -tb Fasta.cpp     -cflags $tb_flags
add_files -tb Test.cpp      -cflags $tb_flags

open_solution "kmer"

set_part {xczu3eg-sbva484-1-e} -tool vivado
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
export_design -format ip_catalog

