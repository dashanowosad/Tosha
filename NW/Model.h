//
// Created by dasha on 20.05.2020.
//

#ifndef NW_MODEL_H
#define NW_MODEL_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Model {
private: vector <vector <int> > A;
private: int n; //столбцы
private: int m; //строки

public: Model(){
        this->ReadFromFile();
        this->WriteMatrix();
        int res = this->Summ();
        if (res != 0) this->Fiktiv(res);


        //this->WriteMatrix();

    }
~Model() = default;

private: int ReadFromFile();
private: void WriteMatrix();
private: int Summ();
private: void Fiktiv(int res);

public: vector<vector<int>> getA(){
    return this->A;
}

public: int getN(){
    return this->n;
}
public: int getM(){
    return m;
}

};


#endif //NW_MODEL_H
