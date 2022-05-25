#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

typedef int CRecode;

typedef int DataType;

class SeqList;
class SeqNode;

class SeqNode{
    public:
        int key;
        int times;
        SeqList* father;
    public:
        SeqNode(int _key, SeqList* _father);
};

class SeqList{
    public:
        vector<SeqNode> nodes;
    public:
        void Output();
        void Create();
        void RandCreate(int n);
};

void SeqList::Output(){
    for(auto i : this->nodes){
        cout << i.key;
        for(int j = 0; j < i.times; j ++)
            cout << "*";
        cout << " ";
    }
}

void SeqList::Create(){
    unsigned int n;
    int key;
    cout << "Please enter the number of nodes: ";
    cin >> n;
    cout << "Please enter the keys: ";
    while(n --){
        cin >> key;
        nodes.push_back(SeqNode(key, this));
    }
}
 Ann
void SeqList::RandCreate(int n){
    while(n --)
        this->nodes.push_back(SeqNode(rand()%100, this));
}

SeqNode::SeqNode(int _key, SeqList* _father){
    this->key = _key;
    this->father = _father;
    this->times = -1;
    int t = -1;
    for(auto i : _father->nodes)
        if(_key == i.key && i.times != -1 && i.times > t)
            t = i.times;
    this->times = t + 1;
}

void DebugQuickSort_main(SeqList &list, int begin_loc, int end_loc, unsigned int &Compare_times, unsigned int &Recursion_times, unsigned int &Swap_times){
    if(begin_loc >= end_loc) return;
    Recursion_times ++;
    
    cout << endl << "From " << begin_loc << " to " << end_loc << " : ";
    list.Output();
    cout << endl;
    
    int p[2] = {begin_loc + 1, end_loc}, empty_loc = begin_loc, i = 1;
    SeqNode temp = list.nodes[empty_loc];
    while(p[0] < p[1]){
        while((i ? list.nodes[p[i]].key >= temp.key : list.nodes[p[i]].key <= temp.key) && p[0] < p[1]){
            i ? p[i] -- : p[i] ++;
            Compare_times ++;
        }
        Swap_times ++;
        list.nodes[empty_loc] = list.nodes[p[i]];
        empty_loc = p[i];
        i = 1 - i;
    }
    list.nodes[empty_loc] = temp;
    DebugQuickSort_main(list, begin_loc, empty_loc - 1, Compare_times, Recursion_times, Swap_times);
    DebugQuickSort_main(list, empty_loc + 1, end_loc, Compare_times, Recursion_times, Swap_times);
}

void DebugQuickSort(SeqList &list, int begin_loc, int end_loc){
    unsigned int SqNode_nums        = end_loc - begin_loc + 1,
                 Compare_times      = 0,
                 Recursion_times    = 0,
                 Swap_times         = 0;
    cout << "Before sort:       ";
    for(auto i : list.nodes)
        cout << i.key << " ";
    cout << endl;
    DebugQuickSort_main(list, begin_loc, end_loc, Compare_times, Recursion_times, Swap_times);
    cout << "Compare times:     " << Compare_times << endl;
    cout << "Recursion times:   " << Recursion_times << endl;
    cout << "Swap times:        " << Swap_times << endl;
    cout << "After sort:        ";
    list.Output();
    cout << endl;
}

int Patition(SeqList &list, int begin_loc, int end_loc){
	SeqNode temp = list.nodes[begin_loc];
	int pivotkey = temp.key;
	while (begin_loc < end_loc){
		while(begin_loc < end_loc && list.nodes[end_loc].key >= pivotkey)
            end_loc --;
		list.nodes[begin_loc] = list.nodes[end_loc];
		while(begin_loc < end_loc && list.nodes[begin_loc].key <= pivotkey)
            begin_loc ++; 
		list.nodes[end_loc] = list.nodes[begin_loc];
	}
	list.nodes[begin_loc] = temp;
	return begin_loc;
}

void QSort(SeqList &list, int begin_loc, int end_loc) { //对顺序表L中的子序列L.r[low...end_loc]做快速排序
	if(begin_loc < end_loc){
        int pivotloc = Patition(list, begin_loc, end_loc);
		QSort(list, begin_loc, pivotloc - 1);
		QSort(list, pivotloc + 1, end_loc);    
	}
}

void Unusual_QuickSort(vector<SeqNode> &sl){
    if(sl.size() > 1){
        vector<vector<SeqNode>> parts;
        parts.resize(3);
        parts[1].push_back(sl[0]);
        for(auto i = sl.begin() + 1; i != sl.end(); i ++)
            parts[2*(int)(i->key > parts[1][0].key)].push_back(*i);
        sl.clear();
        for(auto i : parts){
            Unusual_QuickSort(i);
            for(auto _i : i)
                sl.push_back(_i);
        }
    }
}

#if 0

int main(){
    srand(time(NULL));
    SeqList l;
    l.RandCreate(10);
    Unusual_QuickSort(l.nodes);
    l.Output();
    return 0;
}

#elif 0

int main(){
    srand(time(NULL));
    SeqList l;
    l.RandCreate(10);
    QSort(l, 0, 9);
    l.Output();
    return 0;
}

#elif 1
int main(){
    SeqList l;
    l.Create();
    DebugQuickSort(l, 0, l.nodes.size()-1);
    return 0;
}
#endif