#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
struct Person
{
    string name;
    string last_name;
    string father_name;
    int _day;
    int _month;
    int year;

    void fillSet()
    {
        for (auto x: name)
        {
            name_symbols.insert(x);
        }
        for (auto x: last_name)
        {
            name_symbols.insert(x);
        }
        for (auto x: father_name)
        {
            name_symbols.insert(x);
        }
        different_symbols = name_symbols.size();
    };
    string getCyfr()
    {
        int fio_symbols_count = different_symbols;
        vector<int> day;
        vector<int> month;

        if (_day > 9)
        {
            day.push_back(_day / 10);
            day.push_back(_day % 10);
        }
        else
            day.push_back(_day);

        if (_month > 9)
        {
            day.push_back(_month / 10);
            day.push_back(_month % 10);
        }
        else
            day.push_back(_month);

        int counter_day = 0;
        for (auto x: day)
            counter_day += x;
        for (auto x: month)
            counter_day += x;

        int day_month_cyfr = counter_day * 64;
        int alphabet_pos;
        if (last_name[0] < 97)
            alphabet_pos = last_name[0] - 64;
        else
            alphabet_pos = last_name[0] - 144;
        int total = fio_symbols_count + day_month_cyfr + alphabet_pos * 256;

        stringstream ss;
        ss << hex  << uppercase << total;
        string result(ss.str());
        string buff;
        int counter = 0;
        for (auto i = result.rbegin(); i != result.rend(); ++i)
        {
            if (counter == 3)
                break;
            buff += *i;
            ++counter;
        }
        string rev;
        for (int i = buff.size() - 1; i >= 0; i--)
        {
            rev = rev.append(1, buff[i]);
        }

        while (rev.size() < 3)
        {
            rev += '0';
        }
        return rev;

    };
    set<char> name_symbols;
    int different_symbols;
    string cyfr;
};

string readIntoBuffer(const int& i, int& j, const vector<string>& data)
{
    string buffer;
    while (data[i][j] != ',')
    {
        buffer += data[i][j];
        ++j;
    }
    ++j;
    return buffer;
}
void readIntoPerson(const vector<string>& data, vector<Person>& users)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        int j = 0;
        string buffer;

        users[i].last_name = readIntoBuffer(i, j, data);
        users[i].name = readIntoBuffer(i, j, data);
        users[i].father_name = readIntoBuffer(i, j, data);
        users[i]._day = stoi(readIntoBuffer(i, j, data));
        users[i]._month = stoi(readIntoBuffer(i, j, data));

        int limit = j+4;
        for (;j < limit; ++j)
        {
            buffer += data[i][j];
        }

        users[i].year = stoi(buffer);
         ++j; buffer.clear();
    }
}
int main()
{
    int N;
    cin >> N;
    vector<string> data;
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        data.push_back(temp);
    }
    vector<Person> users(data.size());
    readIntoPerson(data, users);

    for (auto& x: users)
        x.fillSet();
    for (auto& x: users)
        cout << x.getCyfr() << '\n';

    return 0;
}
