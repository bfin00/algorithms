#include <iostream>
#include <vector>

using namespace std;

enum Seats {A = 0, B, C, D = 4, E, F};
const char* rank_txt[] = {"A", "B", "C", "_", "D", "E", "F"};

struct Passenger
{
    int num;
    string side;
    string location;
};

bool checkSits(int x, int y, const string& data)
{
    for (; x <=y; ++x)
    {
        if (data[x] == '#')
            return false;
    }
    return true;
}
int main()
{
    int n;
    vector<string> data;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i)
    {
        string row;
        getline(cin, row);
        data.push_back(row);
    }

    int m;
    vector<Passenger> passengers;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        Passenger p;
        cin >> p.num >> p.side >> p.location;
        passengers.push_back(p);
    }

    for (size_t i = 0; i < passengers.size(); ++i)
    {
        bool flag = false;
        int nums = passengers.at(i).num;
        string side = passengers.at(i).side;
        string location = passengers.at(i).location;

        for (size_t j = 0; j < data.size(); ++j)
        {
            int x, y;
            if (side == "left" && location == "window")
            {
                x = 0;
                y =nums - 1;
            }
            else if (side == "left" && location == "aisle")
            {
                y = 2;
                x = 2 - nums + 1;
            }
            else if (side == "right" && location == "aisle")
            {
                y = nums + 3;
                x = 4;
            }
            else if (side == "right" && location == "window")
            {
                y = 6;
                x = 6 - nums + 1;
            }
            else
                throw std::invalid_argument("wrong value");
            if (checkSits(x, y, data[j]))
            {
                vector<string> pr = data;
                flag = true;
                cout << "Passengers can take seats: ";
                for (; x <= y; ++x)
                {
                    pr[j][x] = 'X';
                    data[j][x] = '#';
                    if (x == y)
                    {
                        cout << j + 1 << rank_txt[x];
                        break;
                    }
                    cout << j + 1 << rank_txt[x] << ' ';
                }
                cout << '\n';

                for (auto x: pr)
                    cout << x << '\n';
                break;
            }
        }
        if (!flag)
            cout << "Cannot fulfill passengers requirements" << '\n';
    }

    return 0;
}
