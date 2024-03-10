//
// Created by Kevin on 5/2/2023.
//

#ifndef PROB_LAB_9_10_REPOJOC_H
#define PROB_LAB_9_10_REPOJOC_H
# include "Collection.h"
#include "Exception.h"
#include "../Entitate/Joc.h"

class RepoJoc {
protected:
    Coll<Joc> Jocuri;

public:

    RepoJoc();
    /*RepoJoc(const RepoJoc& r);*/
    ~RepoJoc() = default;

    Coll<Joc> getAll();
    Joc& getAt(int i);

    virtual void addJoc(const Joc& j);
    virtual void stergjoc(int i);
    virtual void update(int i, Joc& j);
    unsigned int get_Size();


};


#endif //PROB_LAB_9_10_REPOJOC_H
