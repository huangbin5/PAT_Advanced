#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 1005;
struct Man {
    string head;
    int time;
    Man() {}
    Man(string _head, int _time)
        : head(_head)
        , time(_time) {}
};
struct Gang {
    string head;
    int time, num;
    Gang() {}
    Gang(string _head, int _time, int _num)
        : head(_head)
        , time(_time)
        , num(_num) {}
};
map<string, Man> man;
map<string, Gang> gang;
vector<Gang> gs;
int n, k;

void addMan(string a, int t) {
    if (man.count(a))
        man[a].time += t;
    else
        man[a] = Man(a, t);
}

string findHead(string a) {
    if (man[a].head == a)
        return a;
    string ans = findHead(man[a].head);
    man[a].head = ans;
    return ans;
}

bool cmp(Gang& a, Gang& b) { return a.head < b.head; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    cin >> n >> k;
    string a, b;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> t;
        addMan(a, t);
        addMan(b, t);
        man[findHead(a)].head = findHead(b);
    }
    for (map<string, Man>::iterator it = man.begin(); it != man.end(); ++it) {
        a = it->first;
        Man se = it->second;
        string head = findHead(a);
        if (gang.count(head)) {
            if (se.time > man[gang[head].head].time) {
                gang[head].head = a;
            }
            gang[head].time += se.time;
            ++gang[head].num;
        } else {
            gang[head] = Gang(a, se.time, 1);
        }
    }
    for (map<string, Gang>::iterator it = gang.begin(); it != gang.end(); ++it) {
        Gang se = it->second;
        if (se.num > 2 && se.time > 2 * k) {
            gs.push_back(se);
        }
    }
    cout << gs.size() << endl;
    sort(gs.begin(), gs.end(), cmp);
    for (int i = 0; i < gs.size(); ++i) {
        cout << gs[i].head << " " << gs[i].num << endl;
    }
    return 0;
}
