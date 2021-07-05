//编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v1(10, 1);
    fill_n(v1.begin(), v1.size(), 0);
    for (const auto i : v1)
        cout << i << " ";
    cout << endl;

    vector<int> v2;
    // fill_n(v2.end(), 10, 0);
    //首先end()返回的迭代器是不支持解引用的，要想修改最后一个元素使用v.end()-1，强行对end()解引用会报异常。

    // 然后 *(v.end() - 1) = 10;
    // 是修改最后一个元素内容，而 *(std::back_inserter(v2)) = 10;
    // 是在末尾新增一个元素。

    // 标准库算法不会改变他们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效

    // 标准库算法根本不知道有“容器”这个东西。它们只接受迭代器参数，运行于这些迭代器之上，通过这些迭代器来访问元素。 back_inserter 的迭代器能调用对应的插入算法

    fill_n(back_inserter(v2), 10, 0);
    for (const auto i : v2)
        cout << i << " ";
    cout << endl;

    return 0;
}
