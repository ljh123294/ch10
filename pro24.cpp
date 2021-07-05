#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool check_size(const string &s, const int n)
{
    return n > s.size();
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    string s("asdf");
    auto iter = find_if(v.begin(), v.end(), bind(check_size, s, placeholders::_1));
    cout << *iter << endl;
}