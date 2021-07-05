#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool greater_than_5(const string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> vs = {"d", "c", "b", "a", "a", "c", "e", "bb", "aa", "aaa", "aaaaa"};

    auto iter = partition(vs.begin(), vs.end(), greater_than_5);
    for (const auto s : vs)
        cout << s << " ";
    cout << endl;

    vs.erase(iter, vs.end());
    for (const auto s : vs)
        cout << s << " ";
    cout << endl;

    return 0;
}
