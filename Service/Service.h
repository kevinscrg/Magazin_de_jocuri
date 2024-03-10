//
// Created by Kevin on 5/5/2023.
//

#ifndef PROB_LAB_9_10_SERVICE_H
#define PROB_LAB_9_10_SERVICE_H


#include "../Repo/fileRepo.h"
#include "../Repo/Casa_de_marcat_file.h"

class Service {
private:
     fileRepo rep;
     Casa_de_marcat mar;
public:
    Service():rep(fileRepo()),mar(Casa_de_marcat()){}
    explicit Service(const fileRepo& f, const Casa_de_marcat& c);
    ~Service() =default;

    void addel(Joc& j);
    Coll<Joc> getAll();
    Joc& getAt(int i);
    Coll<int> get_banc();
    Coll<int> rest(int s);
    unsigned int get_Size();
    void update(int i, Joc& j);
    void sterg(int i);
    void vinde_joc(Joc& j);
    Joc& search(const string& n);
    Coll<Joc> filtru_bani(const string& b, int a);

};



#endif //PROB_LAB_9_10_SERVICE_H
