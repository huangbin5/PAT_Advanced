#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 1005;
int price[24];
set<string> cus;
struct Bill {
    int mon, day, hour, minu, stat;
    Bill(int _mon, int _day, int _hour, int _minu, int _stat)
        : mon(_mon)
        , day(_day)
        , hour(_hour)
        , minu(_minu)
        , stat(_stat) {}
};
map<string, vector<Bill>> bill;
int n;

bool cmp(Bill a, Bill b) {
    if (a.day != b.day)
        return a.day < b.day;
    if (a.hour != b.hour)
        return a.hour < b.hour;
    return a.minu < b.minu;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    int a, b, c, d;
    string name;
    char s[10];
    for (int i = 0; i < 24; ++i)
        cin >> price[i];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        scanf("%d:%d:%d:%d %s", &a, &b, &c, &d, s);
        if (cus.count(name)) {
            bill[name].push_back(Bill(a, b, c, d, s[1] == 'n' ? 0 : 1));
        } else {
            cus.insert(name);
            vector<Bill> v;
            v.push_back(Bill(a, b, c, d, s[1] == 'n' ? 0 : 1));
            bill[name] = v;
        }
    }
    for (set<string>::iterator it = cus.begin(); it != cus.end(); ++it) {
        vector<Bill> v = bill[*it];
        sort(v.begin(), v.end(), cmp);
        vector<Bill> nv;
        int step = 0, idx = 0, pre;
        for (; idx < v.size(); ++idx) {
            Bill bi = v[idx];
            if (bi.stat == 0) {
                pre = idx;
                step = 1;
            } else if (step == 1) {
                nv.push_back(v[pre]);
                nv.push_back(v[idx]);
                step = 0;
            }
        }
        int toTime, toPrice, ansPrice = 0;
        if (!nv.empty()) {
            printf("%s %02d\n", it->c_str(), v[0].mon);
            for (int i = 0; i < nv.size(); i += 2) {
                printf("%02d:%02d:%02d %02d:%02d:%02d ", nv[i].day, nv[i].hour, nv[i].minu, nv[i + 1].day, nv[i + 1].hour,
                    nv[i + 1].minu);
                toTime = 0;
                toPrice = 0;
                while (nv[i].day != nv[i + 1].day || nv[i].hour != nv[i + 1].hour || nv[i].minu != nv[i + 1].minu) {
                    ++toTime;
                    toPrice += price[nv[i].hour];
                    ++nv[i].minu;
                    if (nv[i].minu == 60) {
                        nv[i].minu = 0;
                        ++nv[i].hour;
                        if (nv[i].hour == 24) {
                            nv[i].hour = 0;
                            ++nv[i].day;
                        }
                    }
                }
                ansPrice += toPrice;
                printf("%d $%.2f\n", toTime, (double)toPrice / 100);
            }
            printf("Total amount: $%.2f\n", (double)ansPrice / 100);
        }
    }
    return 0;
}
