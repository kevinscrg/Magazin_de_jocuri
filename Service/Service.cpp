//
// Created by Kevin on 5/5/2023.
//

#include "Service.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wambiguous-reversed-operator"
Service::Service(const fileRepo& f, const Casa_de_marcat& c) {
    rep = f;
    mar = c;
}
void Service::addel(Joc &j) {
    rep.addJoc(j);
}

Coll<Joc> Service::getAll() {
    return rep.getAll();
}

Joc& Service::getAt(int i){
    return rep.getAt(i);
}

Coll<int> Service::get_banc() {
    return mar.get_Bani();
}

Coll<int> Service::rest(int s) {
    try{
    return mar.rest(s);}
    catch(Exception& ex){
        throw Exception(ex.get_eroare());
    }
}

void Service::update(int i, Joc &j) {
    int pos;
    for(int k =0;k<get_Size();k++)
        if(getAll()[k].get_cod() == i)
            pos =k;
    rep.update(pos,j);
}

void Service::sterg(int i) {
    rep.stergjoc(i);
}

unsigned int Service::get_Size() {
    return rep.get_Size();
}

Coll<Joc> Service::filtru_bani(const string& b, int a) {
    Coll<Joc> rez;
    if(b == "<"){
        for(int i=0; i<get_Size();i++){
            if(getAll()[i].get_pret() <= a)
                rez.push_back(getAll()[i]);
        }
    }
    else if(b==">"){
        for(int i=0; i<get_Size();i++){
            if(getAll()[i].get_pret() >= a)
                rez.push_back(getAll()[i]);
        }
    }
    else if(b =="="){
        for(int i=0; i<get_Size();i++){
            if(getAll()[i].get_pret() == a)
                rez.push_back(getAll()[i]);
        }
    }
    if(rez.empty())
        throw Exception("nu exista nici un joc cu acele caracteristice.\n");
    else
        return rez;
}

Joc &Service::search(const std::string &n) {

    for (int i = 0; i < get_Size(); i++) {
        if (n == getAll()[i].get_nume())
            return getAt(i);
    }
    throw Exception("nu avem acel joc in magazin");
}

void Service::vinde_joc(Joc &j) {
    int pos=0;
    for(int i=0; i < get_Size();i++){
        if(getAll()[i] == j && getAll().nroccurrences(getAll()[i])>0)
            pos = i;
    }
    sterg(pos);
}
#pragma clang diagnostic pop
