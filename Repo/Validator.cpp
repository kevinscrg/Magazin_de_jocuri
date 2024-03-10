//
// Created by Kevin on 5/20/2023.
//

#include "Validator.h"

void Validator::valid_joc(std::string n, int pr,int c) {
    if(n.size() <3)
        throw Exception("numele trebuie sa aiba cel putin 3 caractere.\n");
    else if(pr<=0)
        throw Exception("pretul trebuie sa fie un numar pozitiv\n");
    else if(c<0)
        throw Exception("codul trebuie sa fie un numar natural.\n");
}