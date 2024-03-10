//
// Created by Kevin on 5/9/2023.
//

#ifndef PROB_LAB_9_10_FILEREPO_H
#define PROB_LAB_9_10_FILEREPO_H
#include "RepoJoc.h"
#include "fstream"

class fileRepo : public RepoJoc {
private:
    string filename;
public:
    fileRepo():RepoJoc(){}
    explicit fileRepo(const string& nume);
    ~fileRepo() = default;

    void citire_f();
    void scrie_f();
    void addJoc(const Joc& j) override;
    void stergjoc(int i) override;
    void update(int i, Joc& j) override;
};


#endif //PROB_LAB_9_10_FILEREPO_H
