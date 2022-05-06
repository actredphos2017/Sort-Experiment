#include <iostream>

using namespace std;

class Data{
    public:
        int key;
};

class SqList{
    public:
        Data* r;
        int length;
    public:
        SqList(){
            this->r = new Data[10];
            int temp[] = {59, 32, 51, 53, 32, 41, 71, 31, 10, 5};
            for(int i = 0; i < 10; i ++)
                this->r[i].key = temp[i];
            this->length = 10;
        }
        void output(){
            for(int i = 0; i < length; i ++)
                cout << r[i].key << " ";
            cout << endl;
        }
};

template<class T>
bool LT(T a, T b){
    return a < b;
}

void ShellInsert(SqList &L, int dk){
    int i, j;
    for(i = dk + 1; i <= L.length; ++ i)
        if(LT(L.r[i].key, L.r[i - dk].key)){
            L.r[0] = L.r[i];
            for(j = i-dk; i > 0 && LT(L.r[0].key, L.r[j].key); j-=dk)
                L.r[j+dk] = L.r[j];
            L.r[j+dk] = L.r[0];
        }
}

void ShellSort(SqList &L, int dlta[], int t){
    for(int k = 0; k < t; ++k){
        ShellInsert(L,dlta[k]);
        L.output();
    }
}

int main(){
    int dlta[] = {9,7,5,3,1};
    SqList sl;
    sl.output();
    ShellSort(sl, dlta, 5);
    return 0;
}