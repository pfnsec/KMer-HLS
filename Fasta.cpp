#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Fasta.hpp"


Fasta *ReadFasta(char *filename) {

    Fasta *fst = (Fasta *) malloc(sizeof(Fasta));
 
    std::ifstream input(filename);
    if(!input.good()){
        std::cerr << "Error opening '" << filename << "'. Bailing out." << std::endl;
        free(fst);
        return 0;
    }
 
    std::string line, name, content;
    while( std::getline( input, line ).good() ){
        if( line.empty() || line[0] == '>' ){ // Identifier marker
            if( !name.empty() ){ // Print out what we read from the last entry
                std::cout << name << " : " << content << std::endl;
                name.clear();
            }
            if( !line.empty() ){
                name = line.substr(1);
            }
            content.clear();
        } else if( !name.empty() ){
            if( line.find(' ') != std::string::npos ){ // Invalid sequence--no spaces allowed
                name.clear();
                content.clear();
            } else {
                content += line;
            }
        }
    }
    if( !name.empty() ){ // Print out what we read from the last entry
        std::cout << name << " : " << content << std::endl;
    }

    fst->name    = name;
    fst->content = content;

    return fst;
}
