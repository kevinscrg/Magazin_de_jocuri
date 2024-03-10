//
// Created by Kevin on 5/9/2023.
//

#include "fileRepo.h"


fileRepo::fileRepo(const string &nume) {
    filename = nume;
    citire_f();
}

void fileRepo::citire_f() {
    ifstream in(filename);
    int co,pr,oc;
    string nume;
    while(in >>co>>nume>>pr>>oc){
        Joc j =Joc(co,nume,pr);
        addJoc(j);
        if(oc!=0)
        Jocuri.setnrocc(j,oc);
    }
    scrie_f();
    in.close();
}

void fileRepo::scrie_f() {
    ofstream ot(filename);
    for(int i =0;i<Jocuri.size();i++)
        ot <<Jocuri[i].get_cod() << " "<< Jocuri[i].get_nume() << " "<< Jocuri[i].get_pret()<< " "<<Jocuri.nroccurrences(Jocuri[i])<< "\n";
    ot.close();
}

void fileRepo::addJoc(const Joc &j) {
    for(int i =0;i<Jocuri.size();i++)
        if(j.get_cod() == Jocuri[i].get_cod() && j!= Jocuri[i])
            throw Exception("exista deja un joc cu acel cod");
    Jocuri.push_back(j);
    scrie_f();
}

void fileRepo::stergjoc(int i) {
    if(i<0 or i>=Jocuri.size())
        throw Exception("pozitia este una incorecta");
    Jocuri.remove(Jocuri[i]);
    scrie_f();
}
void fileRepo::update(int i, Joc &j) {
    if(i<0 or i>=Jocuri.size())
        throw Exception("pozitia este una incorecta");
    Jocuri[i] =j;
    scrie_f();
}