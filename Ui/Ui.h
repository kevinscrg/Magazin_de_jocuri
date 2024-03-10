//
// Created by Kevin on 5/5/2023.
//

#ifndef PROB_LAB_9_10_UI_H
#define PROB_LAB_9_10_UI_H


#include "../Service/Service.h"

class Ui {
private:
    Service ser;
public:
    Ui():ser(Service()){}
    explicit Ui(const Service& s);
    ~Ui() =default;

    void adauga();
    void update();
    void sterge();
    static void afis(Coll<Joc> vec);
    static string afis_ban(Coll<int> vec);
    static void printMeniu();
    void Meniu();
    Coll<Joc> filtru_pret();

    void vinde();
    void vinde_masiv();

};



#endif //PROB_LAB_9_10_UI_H
