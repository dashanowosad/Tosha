//
// Created by dasha on 20.05.2020.
//


#include "NW.h"
void NW::WriteMatrix() {
    int j,i;
    for (i = 0; i < this->m; ++i) {
        for (j = 0; j < this->n; ++j) {
            if (i == this->A.size() - 1 && j == this->n - 1);
            else
                cout << setw(5) << this->A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

void NW::WriteTable() {
    int j,i;
    for (i = 0; i < this->m - 1; ++i) {
        for (j = 0; j < this->n - 1; ++j) {

            cout << setw(5) << this->A[i][j];
            cout<<setw(2)<<"[";
            cout<<setw(2)<<this->Cost[i][j];
            cout<<setw(2)<<"] ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

void NW::FillTable() {
    int i, j;
    int Min = 0;


    for(i = 0; i < this-> n - 1; ++i){
        vector <int> tmp;
        for(j = 0; j < this->m - 1; ++j){
            //cout<<this->A[j][i]<<" ";
            if(this->A[j][this->n - 1] == 0 || this->A[this->m - 1][i] == 0) {
                tmp.push_back(0);

            }
            else {
                cout<<"x"<<i+1<<j+1<<"=min( "<<this->A[j][this->n - 1]<<", "<<this->A[this->m - 1][i]<<")";
                if(this->A[j][this->n - 1] == this->A[this->m - 1][i])
                    cout<<" - a degenerate basic plan";
                cout<<endl;
                Min = min(this->A[j][this->n - 1], this->A[this->m - 1][i]);
                tmp.push_back(Min);
                this->A[j][this->n - 1] -= abs(Min);
                this->A[this->m - 1][i] -= abs(Min);

                //cout<<this->A[j][this->n - 1]<<" "<<this->A[this->m - 1][i]<<" ";
            }
            //cout<<tmp[j]<<" ";
        }
        //cout<<endl;
        this->Cost.push_back(tmp);
    }
    cout<<endl;

    this->Transponir();

    /*for(i = 0; i < this->Cost.size(); ++i) {
        for (j = 0; j < this->Cost[0].size(); ++j)
            cout<<this->Cost[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/

}

void NW::FindCost() {
    int Z = 0,i,j;

    for(i = 0; i < this->m - 1; ++i){
        for(j = 0; j < this->n - 1; ++j)
            Z += this->A[i][j] * this->Cost[i][j];
    }

    cout<<"Cost of transportation:"<<endl;
    cout<<"Z = "<<Z<<endl;
}

void NW::Transponir() {
    vector<vector<int>> newMatrix(this->Cost.size());
    for (int i = 0; i < this->Cost[0].size(); i++)
    {
        for (int j = 0; j < this->Cost.size(); j++)
        {
            newMatrix[i].push_back(this->Cost[j][i]);
        }
    }
    this->Cost = newMatrix;

}

