#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int acid()
{
    int n;
    cin >> n;
    if (n == 1)
        return 0;
    vector<int> a(n);
    vector<int> b;
    unordered_set<int> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(s.insert(a[i]).second)
        {
            b.push_back(a[i]);
            if (b.size() > 1 && (b.at(b.size() - 1) < b.at(b.size() - 2)))
                return -1;

        }

    }
    if (s.size() == 1)
        return 0;

    else
        return b.at(b.size() - 1) - b.at(0);
    return -1;
}
using namespace std;
int main()
{

    cout << acid();
    return 0;

}
