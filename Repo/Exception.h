//
// Created by Kevin on 5/20/2023.
//

#ifndef PROB_LAB_9_10_EXCEPTION_H
#define PROB_LAB_9_10_EXCEPTION_H
#include <iostream>
#include <string>
#include <utility>
using std::string;
class Exception : std::exception {
private:
    string mesaj;
public:
explicit Exception(string mes): mesaj(std::move(mes)){}
[[nodiscard]] string get_eroare() const;
};


#endif //PROB_LAB_9_10_EXCEPTION_H
