#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> &elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    return words;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
                      { return a.size() >= sz; });
    auto wc1 = stable_partition(words.begin(), words.end(), [sz](const string &a)
                                { return a.size() >= sz; });
    auto cnt = words.end() - wc;
    auto cnt1 = wc1 - words.begin();
    cout << cnt << endl;
    cout << cnt1 << endl;
    for_each(wc, words.end(), [](const string &a)
             { cout << a << " "; });
    for_each(words.begin(), wc1, [](const string &a)
             { cout << a << " "; });
    cout << endl;
}

int main()
{
    vector<string> vs = {"d", "c", "b", "a", "a", "c", "e", "bb", "aa", "aaa", "aaaaa"};

    biggies(vs, 5);

    return 0;
}
