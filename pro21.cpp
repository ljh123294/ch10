#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i = 6;

    auto reduce_i = [&]() -> bool
    {
        if (i <= 0)
            return false;
        else
        {
            --i;
            return true;
        }
    };
    while (reduce_i())
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
