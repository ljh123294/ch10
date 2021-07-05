#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int main()
{
    vector<string> vs = {"d", "c", "b", "a", "a", "c", "e", "bb", "aa", "aaa", "aaaaa"};

    auto iter = partition(vs.begin(), vs.end(), bind(check_size, placeholders::_1, 5));
    for (const auto s : vs)
        cout << s << " ";
    cout << endl;

    vs.erase(iter, vs.end());
    for (const auto s : vs)
        cout << s << " ";
    cout << endl;

    return 0;
}
