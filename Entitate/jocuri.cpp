//
// Created by Kevin on 5/2/2023.
//


#include "Joc.h"
Validator v;

Joc::Joc() {
    cod = 0;
    nume = "";
    pret =0;
}

Joc::Joc(int c, string& n, int p) {
    v.valid_joc(n,p,c);
    cod = c;
    nume = n;
    pret = p;
}

Joc::Joc(const Joc &j) {
    this->cod = j.cod;
    this->nume = j.nume;
    this->pret = j.pret;
}

Joc::~Joc()=default;

int Joc::get_cod() const {
    return cod;
}

int Joc::get_pret() const {
    return pret;
}

string Joc::get_nume() const {
    return nume;
}

void Joc::set_cod(int c) {
    cod = c;
}

void Joc::set_pret(int p) {
    pret = p;
}

void Joc::set_nume(string& n) {
    nume=n;
}

string Joc::to_string() const {
    ostringstream st;
    st<<"{-----\ncodul: "<<cod <<"\nnumele este: "<< nume<<"\nsi are un pret de: "<< pret<<"\n-----}\n";
    return st.str();
}

Joc &Joc::operator=(const Joc &j) = default; /*{
    this->cod = j.cod;
    nume = j.nume;
    this->pret = j.pret;
    return *this;
}*/

bool Joc::operator==(const Joc &j) {
    return this->nume==j.nume && this->pret == j.pret && this->cod == j.cod;
}