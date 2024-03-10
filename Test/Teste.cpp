//
// Created by Kevin on 5/2/2023.
//
#include "..\Service\Service.h"
#include <cassert>
using std::string;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wambiguous-reversed-operator"
void test_entit(){
    Joc j1;
    assert(j1.get_pret()==0);
    assert(j1.get_cod()==0);
    string num = "mario";
    j1 = Joc(1,num,50);
    assert(j1.get_pret()==50);
    assert(j1.get_cod()==1);
    assert(j1.get_nume() == "mario");


    j1.set_pret(25);
    assert(j1.get_pret()!=50);
    assert(j1.get_pret()==25);

    j1.set_cod(3);
    assert(j1.get_cod()!=1);
    assert(j1.get_cod()==3);
    num = "Zelda";
    j1.set_nume(num);
    assert(j1.get_nume()!="mario");
    assert(j1.get_nume()=="Zelda");
    assert(j1.to_string() == "{-----\ncodul: 3\nnumele este: Zelda\nsi are un pret de: 25\n-----}\n");
}

void test_repo(){
    RepoJoc r;
    Joc j1,j2;
    string num = "mario";
    j1 = Joc(1,num,50);
    num ="COD";
    j2 = Joc(2,num,85);
    assert(r.get_Size()==0);
    r.addJoc(j1),r.addJoc(j2);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] == j1);
    assert(r.getAll()[1]==j2);
    num ="minecraft";
    Joc j3 = Joc(3,num,44);
    r.update(0,j3);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] != j1);
    assert(r.getAll()[0] == j3);
    assert(r.getAll()[1]==j2);

    r.addJoc(j1);
    assert(r.get_Size()==3);
    r.stergjoc(0);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] != j1);
    assert(r.getAll()[0] != j3);
    assert(r.getAll()[0]==j2);
    assert(r.getAll()[1]==j1);
    try{
        r.update(3,j3), assert(false);
    }catch (Exception& exc){
        assert(true);
    }
}


void test_file(){
    fileRepo r = fileRepo(R"(..\Test\fileTest.txt)");
    assert(r.get_Size()==1);
    r.stergjoc(0);

    Joc j1,j2;
    string num = "mario";
    j1 = Joc(1,num,50);
    r.addJoc(j1);
    num ="COD";
    j2 = Joc(2,num,85);
    r.addJoc(j2);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] == j1);
    assert(r.getAll()[1]==j2);
    num ="minecraft";
    Joc j3 = Joc(3,num,44);
    r.update(0,j3);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] != j1);
    assert(r.getAll()[0] == j3);
    assert(r.getAll()[1]==j2);

    r.addJoc(j1);
    assert(r.get_Size()==3);
    r.stergjoc(0);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] != j1);
    assert(r.getAll()[0] != j3);
    assert(r.getAll()[0]==j2);
    assert(r.getAll()[1]==j1);
    try{
        r.update(3,j3), assert(false);
    }catch (Exception& exc){
        assert(true);
    }
    r.stergjoc(0);
    r.stergjoc(0);
    r.addJoc(j3);


}

void test_serv(){
    Service r;
    Joc j1,j2;
    string num = "mario";
    j1 = Joc(1,num,50);
    num ="COD";
    j2 = Joc(2,num,85);
    assert(r.get_Size()==0);
    r.addel(j1),r.addel(j2);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] == j1);
    assert(r.getAll()[1]==j2);
    num ="minecraft";
    Joc j3 = Joc(3,num,44);
    r.update(1,j3);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] != j1);
    assert(r.getAll()[0] == j3);
    assert(r.getAll()[1]==j2);

    r.addel(j1);
    assert(r.get_Size()==3);
    r.sterg(0);
    assert(r.get_Size()==2);
    assert(r.getAll()[0] != j1);
    assert(r.getAll()[0] != j3);
    assert(r.getAll()[0]==j2);
    assert(r.getAll()[1]==j1);
    Coll<Joc> rez;
    string b = ">";
    int a = 60;
    rez = r.filtru_bani(b,a);
    assert(rez.size() == 1);
    assert(rez[0] == j2);

    r.vinde_joc(j2);
    assert(r.get_Size() ==1);
    assert(r.getAll()[0]==j1);

    assert(r.get_banc().size() ==0);
    try{
    r.rest(100);
    assert(false);}
    catch(Exception& ex){
        assert(true);
    }

}


void test_All(){
    std::cout << "incep testele...\n";
    test_file();
    test_entit();
    test_repo();
    test_serv();
    std::cout<< "au trecut toate testele.\n\n";
}
#pragma clang diagnostic pop