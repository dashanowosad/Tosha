//
// Created by dasha on 20.05.2020.
//


#include "Model.h"

int Model::ReadFromFile() {
    int k;
    ifstream file("../res/test1");
    if(!file){
        cout<<"Error of open file"<<endl;
        return 0;
    }

    file >> this->m;
    file >> this->n;
    for(k = 0; k < this->m; ++k) {
        vector <int> tmp(this->n); //line input
        for (auto &i: tmp) {
            file >> i;
            if(!file) break;
        }
        this->A.push_back(tmp);
    }
    file.close();
}

void Model::WriteMatrix() {
    int j,i;
    for (i = 0; i < this->m; ++i) {
        for (j = 0; j < this->n; ++j) {
            //if (i == this->A.size() - 1 && j == this->n - 1);
            //else
                cout << setw(5) << this->A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

int Model::Summ() {
    int a = 0, b = 0,i;
    for(i = 0; i < this->m - 1; ++i)
        a += this->A[i][this->n - 1];

    for(i = 0;i < this->n - 1; ++i)
        b += this->A[this->m - 1][i];

    return a-b;
}

void Model::Fiktiv(int res) {
    int i,j;
    vector <vector <int> > B;

    if(res > 0)
        cout<<"Sum ai > Sum bj"<<endl;
    else
        cout<<"Sum ai < Sum bj"<<endl;

    cout<<endl;

    if (res < 0) {
        B = this->A;
        vector <int> tmp(this->n - 1);
        B.resize(this->A.size() - 1);

        for(auto &i: tmp)
            i = 0;
        tmp.push_back(abs(res));
        B.push_back(tmp);
        tmp = this->A[this->m - 1];

        B.push_back(tmp);
        this->A = B;
        this->m++;

    }
    else{
        for(i = 0; i < this->m; ++i) {
            vector<int> tmp = this->A[i];
            tmp.resize(this->n - 1);
            tmp.push_back(0);
            tmp.push_back(this->A[i][this->n - 1]);

            B.push_back(tmp);
        }
        this->A = B;
        this->n++;

        this->A[this->m - 1][this->n - 2] = res;
    }

    this->WriteMatrix();

    /*for(i = 0; i < B.size(); ++i){
        for(j = 0; j < B[0].size(); ++j)
            cout<<B[i][j]<<" ";
        cout<<endl;
    }*/

}