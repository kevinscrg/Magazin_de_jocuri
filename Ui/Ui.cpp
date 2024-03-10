//
// Created by Kevin on 5/5/2023.
//

#include "Ui.h"

Ui::Ui(const Service& s) {
    ser = s;
}

void Ui::vinde() {
    try{
        int s,b,c;
        string nume;
        cout << "dati numele jocului pe care doriti sa-l cumparati.\n";
        getline(cin>>ws,nume);
        Joc j = ser.search(nume);
        cout << "vor fi " << j.get_pret()<< " lei.\nva rugam sa introduceti suma de bani: \n";
        cin >> s;
        b=j.get_pret();
        while(s<b){
            cout << "suma nu este destul de mare pentru achizitionarea jocului.\n mai este nevoie de " << b-s<< " lei.\n";
            cin >>c;
            s= s+c;
        }
        if(s>b){
            cout << "aici aveti restul:\n\n" << afis_ban(ser.rest(s-b))<<'\n';
        }
        ser.vinde_joc(j);
    }catch (Exception& exc) {
        cout << exc.get_eroare();
    }
}

void Ui::vinde_masiv() {
    int n;
    cout << "cate jocuri doriti sa cumparati?\n";
    cin >>n;
    while(n>0)
        vinde(),n--;
}


void Ui::adauga() {
    try{
        string nume;
        int pr, co;
        cout << "dati codul jocului.\n";
        cin>>co;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw Exception("input invalid.\n");
        }
        cout << "dati numele jocului\n";
        getline(cin>>ws,nume);
        cout << "spuneti pretul jocului.\n";
        cin >> pr;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw Exception("input invalid.\n");
        }
        Joc j = Joc(co,nume,pr);
        ser.addel(j);
    }catch (Exception& exc) {
        cout << exc.get_eroare();
    }
}

void Ui::sterge() {
    try{
        int i;
        cout << "dati pozitia unde doriti sa stergeti: ";
        cin >> i;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw Exception("input invalid.\n");
        }
        ser.sterg(i - 1);
    }catch (Exception& exc){
        cout << exc.get_eroare();
    }
}

void Ui::update() {
    try{
        int co, pr;
        string nume;
        cout << "dati codul jocului pe care doriti sa-l modificati:";
        cin >> co;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw Exception("input invalid.\n");
        }
        cout << "dati noul nume: ";
        getline(cin >> ws, nume);
        cout << "dati si noul pret: ";
        cin >> pr;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw Exception("input invalid.\n");
        }
        Joc j = Joc(co, nume, pr);
        ser.update(co, j);
    }catch (Exception& exc){
        cout << exc.get_eroare();
    }

}
Coll<Joc> Ui::filtru_pret() {
    try{
        int a;
        string b;
        cout << "dati care este opertaorul (<,>,=)";
        getline(cin>>ws,b);
        cout << "dati pretul dupa care sa se filtreze";
        cin >>a;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw Exception("input invalid.\n");
        }
        cout << "\n\n";
        return ser.filtru_bani(b,a);
    }catch(Exception& ex){
        Coll<Joc> r;
        return r ;
    }
}


void Ui::afis(Coll<Joc> vec) {
    if(vec.empty())
        cout << "lista este goala.\n";
    else
        for (int i = 0; i < vec.size(); i++)
            cout << i + 1 << ":\n" << vec[i].to_string() << vec.nroccurrences(vec[i]) << "\n";

}

string Ui::afis_ban(Coll<int> vec) {
    ostringstream st;
    if(vec.empty()) {
        st << "lista este goala.\n";
    }
    else

        for(int i =0;i<vec.size();i++) {
            if(vec.nroccurrences(vec[i])==1 && vec[i] == 1)
                st << vec.nroccurrences(vec[i]) << " bancnota de: " << vec[i] << " leu\n";
            else if(vec.nroccurrences(vec[i])==1)
                st << vec.nroccurrences(vec[i]) << " bancnota de: " << vec[i] << " le1\n";
            else if(vec[i]==1)
                st << vec.nroccurrences(vec[i]) << " bancnote de: " << vec[i] << " leu\n";
            else
            st << vec.nroccurrences(vec[i]) << " bancnote de: " << vec[i] << " lei\n";
        }
    return st.str();
}




void Ui::printMeniu() {
    cout <<"\n--------------------------------------------\n";
    cout <<"1. cumpara un joc din magazinul nostru.\n";
    cout <<"2. cumpara mai multe jocuri\n";
    cout <<"3. filtru in functie de pret.\n";
    cout <<"j adauga jocuri in magazin\n";
    cout <<"u. actiualizeaza datele despre un joc in functie de cod.\n";
    cout <<"s. sterge un joc de pe o pozitie.\n";
    cout <<"b. afiseaza banii din magazin.\n";
    cout <<"a. afiseaza lista de jocuri.\n";
    cout <<"x. iesire din aplicatie.\n";
    cout <<"--------------------------------------------\n";
}

void Ui::Meniu() {
    string c;
    while(true){
        printMeniu();
        cout << "dati optiunea:\n";
        getline(cin>>ws,c);
        if(c=="j")
            adauga();
        else if(c=="1")
            vinde();
        else if(c=="2")
            vinde_masiv();
        else if(c=="u")
            update();
        else if(c=="3")
            afis(filtru_pret());
        else if(c=="s")
            sterge();
        else if(c=="b")
           cout << afis_ban(ser.get_banc());
        else if(c=="a")
            afis(ser.getAll());
        else if(c =="x")
            break;
        else
            cout<<"optiune gresita.\n";
    }
}
