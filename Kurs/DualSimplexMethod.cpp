//
// Created by asakujaku on 08.05.2020.
//

#include "DualSimplexMethod.h"


int DualSimplexMethod::ReaddFromFile() {
    int k, sch;


    ifstream file("../res/test0");
    if(!file){
        cout<<"Error of open file"<<endl;
        return 0;
    }

    file >> this->m;
    file >> this->n;

    vector <int> Sign(this->m);
    for(auto &h: Sign)
        h = 0;

    for(k = 0; k < this->m; ++k) {
        sch = 0;
        vector <Frac> tmp(this->n);
        for (auto &i: tmp) {
            file >> i;
            if(!file) break;

            if(sch >= (this->n - this->m) && sch < this->n - 1  && i == -1) {
                Sign[k] = 1;
                this->Base.push_back(sch + 1);
            }
            ++sch;
        }
        this->A.push_back(tmp);
    }

    string str;
    file >> str;
    if(str == "min")
        this->M = 0;
    else
        this->M = 1;


    file.close();

    this->CO.resize(this->n);
    for(auto &i: this->CO)
        i = 0;

    this->Z = this->A[this->m - 1];

<<<<<<< HEAD

=======
<<<<<<< HEAD
   // for(auto &i: Base)
     //   cout<<i<<" ";
=======
>>>>>>> 3a733d53f2e1bd806e09bd35f73f533f8440c6e6
>>>>>>> 2f0bd274b94c0eb5e9f14ee6d53de1f4bee47a64
    this->Write();
    this->UnitMatrix(Sign);

}

void DualSimplexMethod::Write() {
    int j,i;
    for (i = 0; i < this->m; ++i) {
        vector <Frac> line = this->A[i];
        for (auto &j: line)
            cout << setw(5) << j<< " ";
        cout << endl;
    }

    cout << endl << endl;
}

void DualSimplexMethod::PrintTable() {
    int i,j;
    for(i = 0; i < this->m; ++i){
        if(i < this->Base.size())
            cout<<setw(5)<<"x"<<this->Base[i]<<" ";
        else
            cout<<setw(5)<<"Z"<<"  ";
        vector <Frac> line = A[i];
        for(auto &j: line)
            cout<<setw(5)<<j<<" ";
        cout<<endl;
    }
    cout<<setw(5)<<"C"<<"O"<<" ";
    for(auto &j: this->CO)
        cout<<setw(5)<<j<<" ";

    cout<<endl<<endl;

}

void DualSimplexMethod::Recalculation() {
    int i, j;

    while(Check()) {

        int line, col = 1;
        Frac Min = (Frac)1000;

        line = this->FindMin();


        for (i = 1; i < this->CO.size(); ++i)
            if (Min > this->CO[i] && this->CO[i] > 0) {
                Min = this->CO[i];
                col = i;
            }

        this->Base[line] = col;

        Frac v = this->A[line][col];
        for (i = 0; i < this->m; ++i)
            for (j = 0; j < this->n; ++j)
                if (i != line && j != col)
                    this->A[i][j] = this->A[i][j] - ((this->A[line][j] * this->A[i][col]) / v);


        for (i = 0; i < this->n; ++i)
            this->A[line][i] /= v;

        for (i = 0; i < this->m; ++i)
            if (i != line) this->A[i][col] = 0;

        this->PrintTable();
    }
    this->PrintTable();
    this->FindZ();
}

void DualSimplexMethod::FindZ(){
    int i;

    Frac res = (Frac)0;

    this->Base.resize(this->m - 1);
    for(i = 0; i < this->m - 1; ++i){
        res += this->A[i][0] * this->Z[this->Base[i] - 1];

    }

    cout<<"Z";
    if(!this->M)
        cout<<"min = "<<res;
    else
        cout<<"max = "<<res;
}

bool DualSimplexMethod::Check() {
    int i;
    bool flag = false;


    for(i = 1; i < this->n; ++i){
        if((!this->M && this->A[this->m - 1][i] < 0) || (this->M && this->A[this->m - 1][i] > 0)) {
            flag = true;
        }
    }

    for(i = 0; i < this->m - 1; ++i){
        if(this->A[i][0] < 0)
            flag = true;
    }
    return flag;
}

int DualSimplexMethod::FindMin() {
    int i;
    Frac Min = this->A[0][0];
    int line = 0;

    for(i = 0; i < this->m - 1; ++i)
        if(Min > this->A[i][0]) {
            Min = this->A[i][0];
            line = i;
        }

    for(i = 0; i < this->CO.size(); ++i){
        if (this->A[line][i] != 0)
            this->CO[i] = this->A[this->m - 1][i] / this->A[line][i];
        else
            this->CO[i] = (Frac)0;
        if(this->CO[i] < 0)
            this->CO[i] *= -1;
    }
    return line;
}

void DualSimplexMethod::UnitMatrix(vector <int> Sign) {
    int i, j;

    for(i = 0; i < this->m - 1; ++i){
        if(Sign[i] == 1){
            for(j = 0; j < this->n; ++j)
                this->A[i][j] *= -1;
        }
    }
    this->EndToFirst();
}

void DualSimplexMethod::EndToFirst() {
    int i;

    for(i = 0; i < this-> m; ++i){
        auto iter = this->A[i].cbegin();
        this->A[i].emplace(iter,this->A[i][this->n - 1]);
        this->A[i].resize(this->n);
    }

    if(this->M){ // если Z->max - инвертируем
        for(auto &i: this->A[this->m - 1])
            i *= -1;
    }
}