//
// Created by Kevin on 10/03/2024.
//

#ifndef PROB_LAB_9_10_CASA_DE_MARCAT_H
#define PROB_LAB_9_10_CASA_DE_MARCAT_H


#include "Collection.h"

class Casa_de_marcat {
protected:
    Coll<int> bancnote;

public:
    Casa_de_marcat():bancnote(Coll<int>()){}
    ~Casa_de_marcat()=default;
    virtual Coll<int> rest(int s);
    Coll<int> get_Bani();
    virtual void scad(Coll<int> vec);


};


#endif //PROB_LAB_9_10_CASA_DE_MARCAT_H
