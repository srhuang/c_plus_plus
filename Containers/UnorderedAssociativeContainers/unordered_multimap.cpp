/*****************************************************************
Name    :unordered_multimap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191120 Initial Version
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
#include <unordered_map>
#include <vector>
using namespace std;
/*==============================================================*/

void printAll(unordered_multimap<int, string> &mymap)
{
    unordered_multimap<int, string>::iterator it;
    for(it=mymap.begin(); it!=mymap.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    unordered_multimap<int, string> mymap;
    mymap.insert(pair<int, string>(20, "twenty"));
    mymap.insert(make_pair(10, "ten"));
    mymap.insert({30, "thirty"});
    cout << "mymap :";
    printAll(mymap);
    cout << endl;

    //Using Initializer list constructor
    unordered_multimap<int, string> mymap1({{9,"nine"},{5, "five"},{2, "two"},
        {7, "seven"},{9,"nine"},{1, "one"},{4, "four"},{6, "six"},{9,"nine"}});

    cout << "mymap1 :";
    printAll(mymap1);
    cout << endl;

    //Using range constructor
    vector<pair<int, string>> vec{{9,"nine"}, {5, "five"}, {2, "two"}, {7, "seven"}};
    unordered_multimap<int, string> mymap2(vec.begin(), vec.end());

    cout << "mymap2 :";
    printAll(mymap2);
    cout << endl;

    //Using copy constructor
    unordered_multimap<int, string> mymap3(mymap);

    cout << "mymap3 :";
    printAll(mymap3);
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << mymap.size() << endl;
    cout << "empty:" << mymap.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //insert()
    pair<int, string> input(10, "ten");
    mymap.insert(input); //copy insertion
    input.first = 15;
    input.second = "fifthteen";
    mymap.insert(pair<int, string>(40, "fourty")); //move insertion
    mymap.insert(mymap2.begin(), mymap2.end()); //range insertion
    mymap.insert({25, "twenty-five"}); //initializer list insertion
    cout << "insert mymap :";
    printAll(mymap);
    cout << endl;

    //erase() by key
    mymap.erase(20);
    cout << "erase mymap :";
    printAll(mymap);
    cout << endl;

    //erase() by position
    unordered_multimap<int, string>::iterator it;
    it = mymap.find(30);
    mymap.erase(it);
    cout << "erase mymap :";
    printAll(mymap);
    cout << endl;

    //erase() by range
    it = mymap.find(25);
    mymap.erase(it, mymap.end());
    cout << "erase mymap :";
    printAll(mymap);
    cout << endl;

    //clear()
    mymap.clear();
    cout << "clear mymap :";
    printAll(mymap);
    cout << endl;

    //swap()
    cout << "swap mymap2 :";
    printAll(mymap2);
    cout << endl;

    unordered_multimap<int, string>().swap(mymap2);

    cout << "swap mymap2 :";
    printAll(mymap2);
    cout << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;

    //find()
    it = mymap3.find(20);
    if(it!=mymap3.end()){
        cout << "mymap3 find :" << it->second << endl;
    }

    //count()
    if(mymap3.count(25)!=0){
        cout << "element is in the set." << endl;
    }else{
        cout << "element is NOT in the set." << endl;
    }

    return 0;
}
/*==============================================================*/