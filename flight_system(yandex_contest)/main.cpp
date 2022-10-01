#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <tuple>
using namespace std;
struct Date
{
    int day; //day
    int hour; //hour
    int minute; //minute
    bool operator<(const Date& rhs) const
    {
        return tie(day, hour, minute) < tie(rhs.day, rhs.hour, rhs.minute);
    }
    int operator-(const Date& rhs)
    {
        return (day*1440 + hour*60 + minute) - (rhs.day*1440 + rhs.hour*60 + rhs.minute);
    }
};
struct Rocket
{
    int _id;
    set<Date> A;
    set<Date> CS;
    set<Date> B;
    void addInfo(int day, int hour, int minute, char status, int id)
    {
        _id = id;
        if (status == 'A')
            A.insert({day, hour, minute});
        else if (status == 'C' || status == 'S')
            CS.insert({day, hour, minute});
        else
            B.insert({day, hour, minute});
    }
    int getOverallTime()
    {
        int result_minutes = 0;
        if (A.size() == CS.size())
        {
            vector<Date> a;
            copy(A.begin(), A.end(), back_inserter(a));
            vector<Date> cs;
            copy(CS.begin(), CS.end(), back_inserter(cs));
            for (size_t i = 0; i < a.size(); ++i)
            {
                result_minutes += cs[i] - a[i];
            }
        }
        return result_minutes;
    };
};
void getInfo(map<int,Rocket>& info)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int day, hour, minute, id;
        char status;
        cin >> day >> hour >> minute >> id >> status;
        info[id].addInfo(day, hour, minute, status, id);
    }
}
int main()
{
    map<int, Rocket> data;
    getInfo(data);
    for (auto& x: data)
        cout << x.second.getOverallTime() << " ";
    return 0;
}
