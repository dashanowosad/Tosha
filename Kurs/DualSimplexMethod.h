//
// Created by asakujaku on 08.05.2020.
//

#ifndef CURSWORK_H
#define CURSWORK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Frac.h"

using namespace std;

class DualSimplexMethod {
    private: vector<vector<Frac>> A;
    private: int n;
    private: int m;
    private: int M;
    private: vector <int> Base;
    private: vector <Frac> CO;
    private: vector <Frac> Z;

    public: DualSimplexMethod(){
        this->ReaddFromFile();
        this->FindMin();
        this->PrintTable();
        this->Recalculation();
    }

    private: int ReaddFromFile();
    private: void Write();

    private: void UnitMatrix(vector <int> Sign);
    private: void EndToFirst();

    private: void PrintTable();
    private: int FindMin();
    private: void Recalculation();

    private: bool Check();

    private: void FindZ();

};


#endif
