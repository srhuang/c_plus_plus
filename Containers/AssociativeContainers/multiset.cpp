/*****************************************************************
Name    :multiset
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191118 Initial Version
*****************************************************************/
/*****************************************************************
Outline
    1. Initialization
    2. Capacity
    3. Element Access
    4. Modifiers
    5. Others
*****************************************************************/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*==============================================================*/

void printAll(multiset<int> &myset)
{
    multiset<int>::iterator it;
    for(it=myset.begin(); it!=myset.end(); it++)
    {
        cout << *it << " ";
    }
}

bool fncomp (int lhs, int rhs) {return lhs>rhs;}

class classcomp {
public:
    bool operator() (const int& lhs, const int& rhs) const
    {
        return lhs<rhs;
    }
};

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    multiset<int> myset;
    myset.insert(10);
    myset.insert(20);
    myset.insert(30);
    cout << "myset :";
    printAll(myset);
    cout << endl;

    //Using Initializer list constructor
    multiset<int> myset1({9,5,2,7,9,1,4,6,9});

    cout << "myset1 :";
    printAll(myset1);
    cout << endl;

    //Using range constructor
    vector<int> vec{9,5,2,7};
    multiset<int> myset2(vec.begin(), vec.end());

    cout << "myset2 :";
    printAll(myset2);
    cout << endl;

    //Using copy constructor
    multiset<int> myset3(myset);

    cout << "myset3 :";
    printAll(myset3);
    cout << endl;

    //custom comparator function
    multiset<int, bool(*)(int, int)> myset4(vec.begin(), vec.end(), fncomp);

    cout << "myset4 :";
    multiset<int, bool(*)(int, int)>::iterator it;
    for(it=myset4.begin(); it!=myset4.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //custom comparator class
    multiset<int, classcomp> myset5(vec.begin(), vec.end());

    cout << "myset5 :";
    //set<int, bool(*)(int, int)>::iterator it;
    for(it=myset5.begin(); it!=myset5.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << myset.size() << endl;
    cout << "empty:" << myset.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //insert()
    multiset<int>::iterator ret;
    ret = myset.insert(20);
    //[C++11] The function optimizes its insertion time 
    //if position points to the element 
    //that will follow the inserted element (or to the end, if it would be the last).
    myset.insert(ret, 10); //efficiency inserting
    myset.insert(ret, 30); //no efficiency inserting
    cout << "insert myset :";
    printAll(myset);
    cout << endl;

    //erase()
    myset.erase(20);
    cout << "erase myset :";
    printAll(myset);
    cout << endl;

    it = myset.find(30);
    myset.erase(it);
    cout << "erase myset :";
    printAll(myset);
    cout << endl;

    it = myset.find(25);
    myset.erase(it, myset.end());
    cout << "erase myset :";
    printAll(myset);
    cout << endl;

    //clear()
    myset.clear();
    cout << "clear myset :";
    printAll(myset);
    cout << endl;

    //swap()
    cout << "swap myset2 :";
    printAll(myset2);
    cout << endl;

    multiset<int>().swap(myset2);

    cout << "swap myset2 :";
    printAll(myset2);
    cout << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;

    //find()
    it = myset3.find(20);
    if(it!=myset3.end()){
        cout << "myset3 find :" << *it << endl;
    }

    //count()
    if(myset3.count(25)!=0){
        cout << "element is in the set." << endl;
    }else{
        cout << "element is NOT in the set." << endl;
    }

    return 0;
}
/*==============================================================*/