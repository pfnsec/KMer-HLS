all:
	vivado_hls script.tcl


sim:
	g++ Test.cpp Fasta.cpp KMerCount.cpp -o kmer

clean:
	rm -rf kmer_hls
