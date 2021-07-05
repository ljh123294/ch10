#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <../ch7/Sales_item.h>

using namespace std;

class PS
{
public:
    Sales_item operator()(const Sales_item &t1, const Sales_item &t2)
    {
        return t1 + t2;
    }
};

int main()
{
    istream_iterator<Sales_item> is_cin(cin), eof;
    vector<Sales_item> v(is_cin, eof);
    sort(v.begin(), v.end(), compareIsbn);
    cout << endl;
    for (auto beg = v.cbegin(), end = beg; beg != v.end(); beg = end)
    {
        end = find_if(beg, v.cend(), [beg](const Sales_item &item)
                      { return beg->isbn != item.isbn; });
        // cout << accumulate(beg, end, Sales_item(beg->isbn), PS());
        cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
    }
}