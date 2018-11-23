#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "KMer.hpp"
#include "KMerCount.hpp"
#include "Fasta.hpp"

using namespace std;
 
int main( int argc, char **argv ){

    //Vivado HLS executes our testbench within a subdirectory...
#ifdef _XILINX
    char *filename = "../../../../test.fasta";
#else 
    char *filename = "test.fasta";
#endif

    Fasta *fst = ReadFasta(filename);

    //Length of k-mer
    int k = 2;

    

    std::string s = fst->content;

    int inSize = s.size();

    mer_t *inArray = (mer_t *) malloc(inSize);


    int outSize = kmerBufferSize(k);

    uint16_t *outArray = (uint16_t *) malloc(outSize);


    int offset = 0;
    for (std::string::iterator it = s.begin(), end = s.end(); it != end; ++it) {
        std::cout << *it << ": " << (int)CharMer(s[offset]) << "\n";


        inArray[offset] = CharMer(*it);

        offset++;
    }


    KMerCount((uint8_t *)inArray, outArray, k, inSize);

    mer_t addr[k] = {
            CharMer('E'),
            CharMer('E'),
           // CharMer('S')
    };

    cout << outArray[kmerAddr(k, addr)]
         << endl;


    return 0;
}
