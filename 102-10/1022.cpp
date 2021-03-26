#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;
// #define DEBUG

map<string, set<int>> m1;
map<string, set<int>> m2;
map<string, set<int>> m3;
map<string, set<int>> m4;
map<string, set<int>> m5;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, id;
    string title, author, keyWords, key, publisher, year;
    scanf("%d", &n);
    while (n--) {
        cin >> id;
        cin.ignore();
        getline(cin, title);
        m1[title].insert(id);
        getline(cin, author);
        m2[author].insert(id);
        getline(cin, keyWords);
        stringstream ss(keyWords);
        while (ss >> key) {
            m3[key].insert(id);
        }
        getline(cin, publisher);
        m4[publisher].insert(id);
        cin >> year;
        m5[year].insert(id);
    }
    int m, type;
    string line, query;
    map<string, set<int>>* mp;
    cin >> m;
    cin.ignore();
    while (m--) {
        getline(cin, line);
        type = line[0] - '0';
        query = line.substr(3);
        cout << line << endl;
        if (type == 1)
            mp = &m1;
        else if (type == 2)
            mp = &m2;
        else if (type == 3)
            mp = &m3;
        else if (type == 4)
            mp = &m4;
        else
            mp = &m5;
        if (mp->count(query)) {
            for (set<int>::iterator it = (*mp)[query].begin(); it != (*mp)[query].end(); ++it) {
                printf("%07d\n", *it);
            }
        } else
            cout << "Not Found" << endl;
    }
    return 0;
}