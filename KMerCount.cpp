
#include "KMer.hpp"

uint64_t KMerCount(uint8_t  *srcBase, 
                   uint16_t *destBase,
                   uint8_t   k,  
                   uint32_t  size) {

#pragma HLS INTERFACE m_axi depth=4096 port=srcBase  offset=slave 
#pragma HLS INTERFACE m_axi depth=32768 port=destBase offset=slave 

#pragma HLS INTERFACE s_axilite port=k
#pragma HLS INTERFACE s_axilite port=size
#pragma HLS INTERFACE s_axilite port=return

    //Current subsequence,
    //a window of k characters along the input string
    mer_t subseq[FIFO_LEN];

    for(int j = 0; j < k; j++) {
        subseq[j] = (mer_t) 0;
    }

    uint32_t addr;

    for(int i = 0; i < size; i++) {

        //Advance the window for all but the first entry
        for(int j = 0; j < k - 1; j++) {
            subseq[j] = subseq[j + 1];
        }

        //...First entry feeds from the source data
        subseq[k - 1] = (mer_t) srcBase[i];


        if(i >= k - 1) {

            addr = kmerAddr(k, subseq);

            /*
            addr = ( subseq[k - 3] )
                 | ( subseq[k - 2] << MER_WIDTH )
                 | ( subseq[k - 1] << (2 * MER_WIDTH));


            //Ensure that the address is aligned
            addr << 2;
            */

            destBase[addr]++;
        }

    }

    return 0;

}
