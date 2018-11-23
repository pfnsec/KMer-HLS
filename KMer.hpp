#ifndef KMER_HPP
#define KMER_HPP

#include "DataTypes.hpp"
#include <iostream>


/*
 *  A ALA alanine                         P PRO proline
 *  B ASX aspartate or asparagine         Q GLN glutamine
 *  C CYS cystine                         R ARG arginine
 *  D ASP aspartate                       S SER serine
 *  E GLU glutamate                       T THR threonine
 *  F PHE phenylalanine                   U     selenocysteine
 *  G GLY glycine                         V VAL valine
 *  H HIS histidine                       W TRP tryptophan
 *  I ILE isoleucine                      Y TYR tyrosine
 *  K LYS lysine                          Z GLX glutamate or glutamine
 *  L LEU leucine                         X     any
 *  M MET methionine                      *     translation stop
 *  N ASN asparagine                      -     gap of indeterminate length 
 */

//Convert a character to its low-level representation
inline mer_t CharMer(char c) {
    switch(c) {
    case('A'):
        return (mer_t) 0;
    case('B'):
        return (mer_t) 1;
    case('C'):
        return (mer_t) 2;
    case('D'):
        return (mer_t) 3;
    case('E'):
        return (mer_t) 4;
    case('F'):
        return (mer_t) 5;
    case('G'):
        return (mer_t) 6;
    case('H'):
        return (mer_t) 7;
    case('I'):
        return (mer_t) 8;
    case('K'):
        return (mer_t) 9;
    case('L'):
        return (mer_t) 10;
    case('M'):
        return (mer_t) 11;
    case('N'):
        return (mer_t) 12;
    case('P'):
        return (mer_t) 13;
    case('Q'):
        return (mer_t) 14;
    case('R'):
        return (mer_t) 15;
    case('S'):
        return (mer_t) 16;
    case('T'):
        return (mer_t) 17;
    case('U'):
        return (mer_t) 18;
    case('V'):
        return (mer_t) 19;
    case('W'):
        return (mer_t) 20;
    case('Y'):
        return (mer_t) 21;
    case('Z'):
        return (mer_t) 22;
    case('X'):
        return (mer_t) 23;
    case('*'):
        return (mer_t) 24;
    case('-'):
        return (mer_t) 25;
    default: 
        std::cerr << "Unknown Character " << c << std::endl;
        return -1;
    }
}


//Convert the low-level representation into a character
inline char MerCar(mer_t m) {
    const char mers[] = {
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'K',
        'L',
        'M',
        'N',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'Y',
        'Z',
        'X',
        '*',
        '-'
    };

    return mers[m];

}


//Output size for a given kmer operation
//(This gets real big as k increases)
inline uint32_t kmerBufferSize(int k) {
    return (1ULL << (MER_WIDTH * k)) * 4;
}


inline uint32_t kmerAddr(int k, mer_t subseq[FIFO_LEN]) {

    uint32_t addr = 0;

    for(int i = 0; i < k; i++) {
        addr |= ( subseq[i] << (i * MER_WIDTH) );
    }

    addr << 2;

    return addr;
}



#endif
