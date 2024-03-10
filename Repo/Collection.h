//
// Created by Kevin on 5/10/2023.
//

#ifndef PROB_LAB_9_10_COLLECTION_H
#define PROB_LAB_9_10_COLLECTION_H
#include <vector>
template<class T>
class Coll{
private:
    std::vector<T> elements;
    std::vector<int> occurrences;
    int distinctelements;
public:
    Coll();
    void push_back(T elem);

    [[maybe_unused]] void pop_back();
    bool remove(T elem);
    [[nodiscard]] int size() const;
    int nroccurrences(T elem);
    void setnrocc(T elem,int s);
    [[nodiscard]] bool empty() const;
    ~Coll() =default;

    /**
     * this will be removed
     */
    T & getAt(int position);
    T& operator[](int i);
};


template<class T>
Coll<T>::Coll() {
    distinctelements =0;
    elements={};
    distinctelements={};
}

template<class T>
void Coll<T>::push_back(T elem) {
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++)
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }

    if (exist)
        occurrences[position] = occurrences[position] + 1;
    else {
        elements.push_back(elem);
        occurrences.push_back(0);
        distinctelements++;
    }
}

template<class T>
bool Coll<T>::remove(T elem) {
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++) {
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }
    }

    if (exist) {
        if (occurrences[position] >= 1) {
            occurrences[position]--;
        } else /*if(distinctelements !=1 )*/ {
            for (int i = position; i < distinctelements-1; i++) {
                elements[i] = elements[i + 1];
                occurrences[i] = occurrences[i + 1];
            }
            elements.pop_back();
            occurrences.pop_back();
            distinctelements--;
        }
        /*else{
            elements.pop_back();
            occurrences.pop_back();
            distinctelements--;
        }*/
        return true;
    }
    return false;
}

template<class T>
int Coll<T>::size() const {
    return distinctelements;
}

template<class T>
int Coll<T>::nroccurrences(T elem) {
    for (int i = 0; i<distinctelements; i++)
        if (elements[i] == elem)
            return occurrences[i];
    return -1;
}

template<class T>
T & Coll<T>::getAt(int position){
    return elements[position];
}

template<class T>
T &Coll<T>::operator[](int i){
    return getAt(i);
}

template<class T>
void Coll<T>::setnrocc(T elem, int s) {
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++)
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }

    if (exist)
        occurrences[position] = s;
}

template<class T>
[[maybe_unused]] void Coll<T>::pop_back() {
    elements.pop_back();
    occurrences.pop_back();
    distinctelements--;
}

template<class T>
bool Coll<T>::empty() const {
    return size() == 0;
}




#endif //PROB_LAB_9_10_COLLECTION_H
