#include <string>


typedef struct Fasta {
    std::string name;
    std::string content;
} Fasta;

Fasta *ReadFasta(char *filename);
