//
// Created by Kevin on 5/2/2023.
//

#ifndef PROB_LAB_9_10_JOC_H
#define PROB_LAB_9_10_JOC_H
#include <cstring>
#include <sstream>
#include <iostream>
#include "..\Repo\Validator.h"
using namespace std;

class Joc {
private:
    int cod;
    string nume;
    int pret;
public:
    Joc();
    Joc(int c, string& n, int p);
    Joc(const Joc& j);
    ~Joc();

    [[nodiscard]] int get_cod() const;
    [[nodiscard]] int get_pret() const;
    [[nodiscard]] string get_nume() const;

    void set_cod(int c);
    void set_pret(int p);
    void set_nume(string& n);
    [[nodiscard]] string to_string() const;

    Joc& operator =(const Joc& j);
    bool operator==(const Joc& j);

};


#endif //PROB_LAB_9_10_JOC_H
