#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
// #define DEBUG

string low[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string high[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> mp;

void initMap() {
    mp["tret"] = 0;
    mp["jan"] = 1;
    mp["feb"] = 2;
    mp["mar"] = 3;
    mp["apr"] = 4;
    mp["may"] = 5;
    mp["jun"] = 6;
    mp["jly"] = 7;
    mp["aug"] = 8;
    mp["sep"] = 9;
    mp["oct"] = 10;
    mp["nov"] = 11;
    mp["dec"] = 12;
    mp["tam"] = 13;
    mp["hel"] = 13 * 2;
    mp["maa"] = 13 * 3;
    mp["huh"] = 13 * 4;
    mp["tou"] = 13 * 5;
    mp["kes"] = 13 * 6;
    mp["hei"] = 13 * 7;
    mp["elo"] = 13 * 8;
    mp["syy"] = 13 * 9;
    mp["lok"] = 13 * 10;
    mp["mer"] = 13 * 11;
    mp["jou"] = 13 * 12;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    initMap();
    int n, a;
    cin >> n;
    getchar();
    string s, t;
    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        if (s[0] >= '0' && s[0] <= '9') {
            ss >> a;
            bool zero = true;
            if (a > 12) {
                zero = false;
                cout << high[a / 13];
                a %= 13;
            }
            if (zero)
                cout << low[a];
            else if (a)
                cout << " " << low[a];
            cout << endl;
        } else {
            a = 0;
            while (ss >> t) {
                a += mp[t];
            }
            cout << a << endl;
        }
    }
    return 0;
}