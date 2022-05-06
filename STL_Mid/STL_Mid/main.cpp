#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

template <typename inputIt, typename outputIt, typename condition>
void xcopy_if(inputIt first, inputIt last, outputIt d_first, condition pred)
{
    while (first != last) {
        if (pred(*first))
        {
            *d_first = *first;
            d_first++;
        }
        first++;
    }
}

struct People
{
    string name;
    int age;

    People(string n, int a) :name(n), age(a) {}
    void Dump() const { cout << name << "(" << age << ")" << endl; }
};

bool compare_name(shared_ptr<People> a, shared_ptr<People> b) {
    return a->age < b->age;
}

bool compare_age(shared_ptr<People> a, shared_ptr<People> b) {
        return a->name < b->name;
}

int main(int argc, char* argv[])
{
    /* 巩力 1 */
    /*
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int y[10] = { 0 };
 
    xcopy_if(x, x + 10, y, [](int a){ return a % 2 == 0; });

    for (auto n : y)
    {
        cout << n << endl;
    }

    */

  
    /* 巩力 2 */
    /*
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int y[10] = { 0 };

    //copy_if(x, x + 10, y, [](int a) { return a % 2 == 0; });
    copy_if(x, x + 10, rbegin(y), [](int a) { return a % 2 == 0; });

    for (auto n : y)
    {
        cout << n << endl;
    }
    */


    /* 巩力 3 */
    /*
    vector <shared_ptr<People>> v;
    v.push_back(make_shared<People>("kim", 10));
    v.push_back(make_shared<People>("lee", 15));
    v.push_back(make_shared<People>("park", 5));
    v.push_back(make_shared<People>("jung", 20));
    v.push_back(make_shared<People>("choi", 12));

    sort(v.begin(), v.end(), compare_age);

    for (auto n : v)
    {
        n->Dump();
    }

    sort(v.begin(), v.end(), compare_name);

    for (auto n : v)
    {
        n->Dump();
    }
    */


    /* 巩力 4 */
    unordered_map<string, string> u;
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    string s;
    while (getline(in, s))
    {
        stringstream iss(s);
        string n1, n2, n3;
        iss >> n1 >> n2 >> n3;
        if (n1 == "define") {
            u[n2] = n3;
        }
        else if( !n2.empty() && !n3.empty()) {
            out << n1 << " = " << u[n3] << endl;
        }
    }

    /* 巩力 5 */
    /*
    vector<int> v2 = { 1,2,3,1,2,3,1,2,3,1 };
    auto p = remove(begin(v2), end(v2), 3);
    cout << v2.size() << ", " << v2.capacity() << ", ";
    v2.erase(p, end(v2));
    cout << v2.size() << ", " << v2.capacity() << ", ";
    */

	return 0;
}
