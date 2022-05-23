#include <iostream>

using namespace std;

typedef char ElemType;

struct SqList{
    int key;
};

void QuickSort(SqList* list, int begin_loc, int end_loc){
    if(begin_loc == end_loc) return;

    cout << begin_loc << " " << end_loc << " :   ";
    for(int i = 0; i < 10; i ++)
        cout << " " << list[i].key;
    cout << endl;
    cin.get();
    
    int p[2] = {begin_loc + 1, end_loc},
        empty_loc = begin_loc;
    SqList temp = list[empty_loc];
    int i = 1;
    while(p[0] < p[1]){
        while((i ? list[p[i]].key > temp.key : list[p[i]].key < temp.key) && p[0] != p[1])
            p[i] -= i*2-1;
        list[empty_loc] = list[p[i]];
        empty_loc = p[i];
        i = (++i)%2;
    }
    list[p[0]] = temp;
    QuickSort(list, begin_loc, p[0]-1);
    QuickSort(list, p[0]+1, end_loc);
}

int main(){
    int keys[] = {59, 88, 17, 82, 3, 56, 57, 69, 55, 61};
    SqList l[10];
    for(int i = 0; i < 10; i ++)
        l[i].key = keys[i];
    cout << "hw" << endl;
    QuickSort(l, 0, 9);
    cout << "hw" << endl;
    for(SqList i : l)
        cout << i.key << " ";
    return 0;
}