#include <iostream>
#include <string>
using namespace std;
// #define DEBUG

int n;

int findFirst(string& s) {
    int len = s.size(), i = 0;
    while (i < len && (s[i] == '0' || s[i] == '.'))
        ++i;
    return i;
}

string dealStr(string& s) {
    int len = s.size(), first = findFirst(s);
    int count = 0, cur = first;
    string ans = "0.";
    while (count < n) {
        if (cur >= len) {
            ans += '0';
            ++count;
        } else if (s[cur] != '.') {
            ans += s[cur];
            ++count;
        }
        ++cur;
    }
    ans += "*10^";
    int dot = s.find('.');
    if (dot == -1)
        dot = len;
    if (first == len)
        ans += '0';
    else if (first < dot)
        ans += to_string(dot - first);
    else {
        ans += '-';
        ans += to_string(first - dot - 1);
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> n >> s1 >> s2;
    string ans1 = dealStr(s1);
    string ans2 = dealStr(s2);
    if (ans1 == ans2)
        cout << "YES " << ans1 << endl;
    else
        cout << "NO " << ans1 << " " << ans2 << endl;
    return 0;
}