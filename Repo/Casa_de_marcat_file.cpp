//
// Created by Kevin on 5/13/2023.
//

#include "Casa_de_marcat_file.h"

#include <utility>
#include "Exception.h"

Casa_de_marcat_file::Casa_de_marcat_file(std::string f) {
    bancnote = Coll<int>();
    filename = std::move(f);
    citire();
}

void Casa_de_marcat_file::citire() {
    ifstream in(filename);
    int b,a;
    while(in >>b>>a)
    {
        bancnote.push_back(b);
        bancnote.setnrocc(b,a);
    }
    scriere();
    in.close();
}

void Casa_de_marcat_file::scriere() {
    ofstream of(filename);
    for(int i=0;i<bancnote.size();i++){
        of << bancnote[i] << " " << bancnote.nroccurrences(bancnote[i]) << "\n";
    }
    of.close();
}

Coll<int> Casa_de_marcat_file::rest(int s) {
    Coll<int> rez;
    int nr;
    int r = s;
    for(int i= bancnote.size()-1;i>=0;i--){
        int b = bancnote[i];
        nr = r/b;
        if(nr>0) {
            r -= nr * bancnote[i];
            rez.push_back(bancnote[i]);
            rez.setnrocc(bancnote[i], nr);
        }
    }
    if(r==0) {
        scad(rez);
        return rez;
    }
    else
        throw Exception("nu dispunem de restul necesar, va rugam sa dati o suma fixa.\n");
}


void Casa_de_marcat_file::scad(Coll<int> vec) {
    for(int i=0;i<vec.size();i++)
        for(int j=0;j < this->bancnote.size();j++)
            if(vec[i] == this->bancnote[j])
                bancnote.setnrocc(vec[i],bancnote.nroccurrences(vec[i])-vec.nroccurrences(vec[i]));
    scriere();
}
