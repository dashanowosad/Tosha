//
// Created by dasha on 20.05.2020.
//

#ifndef NW_NW_H
#define NW_NW_H
#include "Model.h"

using namespace std;

class NW {

private: vector <vector <int> > A;
private: vector <vector <int>> Cost;
private: int n; //столбцы
private: int m; //строки

    public: NW(){
        Model model;
        this->A = model.getA();
        this->n = model.getN();
        this->m = model.getM();


        this->FillTable();
        this->WriteTable();

        this->FindCost();
    }

private: void WriteMatrix();
private: void FillTable();
private: void Transponir();

private:void WriteTable();
private: void FindCost();
};


#endif //NW_NW_H
