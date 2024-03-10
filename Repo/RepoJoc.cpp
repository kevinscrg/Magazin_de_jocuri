//
// Created by Kevin on 5/2/2023.
//

#include "RepoJoc.h"

RepoJoc::RepoJoc() {
    Jocuri =Coll<Joc>();
}

/*RepoJoc::RepoJoc(const RepoJoc &r) {
    this->Jocuri = r.Jocuri;
}*/

Coll<Joc> RepoJoc::getAll() {
    return this->Jocuri;
}

void RepoJoc::addJoc(const Joc& j) {
    for(int i =0;i<Jocuri.size();i++)
        if(j.get_cod() == Jocuri[i].get_cod() && j!= Jocuri[i])
            throw Exception("exista deja un joc cu acel cod");
    Jocuri.push_back(j);
}

unsigned int RepoJoc::get_Size() {
    return Jocuri.size();
}

void RepoJoc::stergjoc(int i) {
    if(i<0 or i>=Jocuri.size())
        throw Exception("pozitia este una incorecta");
    Joc pp;
    /*for(int j=i;j<Jocuri.size()-1;j++){
        pp = Jocuri[j];
        Jocuri[j] = Jocuri[j+1];
        Jocuri[j+1]= pp;
    }*/
    pp = Jocuri[i];
    Jocuri.remove(pp);
}

void RepoJoc::update(int i, Joc &j) {
    if(i<0 or i>=Jocuri.size())
        throw Exception("pozitia este una incorecta");
    Jocuri[i] =j;
}

Joc& RepoJoc::getAt(int i){
    return this->Jocuri[i];
}