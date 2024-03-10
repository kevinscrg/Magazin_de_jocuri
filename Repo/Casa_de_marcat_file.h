//
// Created by Kevin on 5/13/2023.
//

#ifndef PROB_LAB_9_10_CASA_DE_MARCAT_FILE_H
#define PROB_LAB_9_10_CASA_DE_MARCAT_FILE_H
#include "Collection.h"
#include <iostream>
using namespace std;
#include "fstream"
#include "Casa_de_marcat.h"


class Casa_de_marcat_file : public Casa_de_marcat {
private:
    std::string filename;
public:
    Casa_de_marcat_file(): Casa_de_marcat(), filename(""){}
    explicit Casa_de_marcat_file(std::string f);
    ~Casa_de_marcat_file()=default;
    void citire();
    void scriere();
    Coll<int> rest(int s);
    void scad(Coll<int> vec);

};


#endif //PROB_LAB_9_10_CASA_DE_MARCAT_FILE_H
