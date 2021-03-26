#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define DEBUG

bool isValid(char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    map<string, int> count;
    string line, word;
    getline(cin, line);
    int start, end = 0;
    for (;;) {
        start = end;
        while (start < line.size() && !isValid(line[start]))
            ++start;
        if (start >= line.size())
            break;
        end = start;
        while (end < line.size() && isValid(line[end]))
            ++end;
        word = line.substr(start, end - start);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (count.count(word))
            ++count[word];
        else
            count[word] = 1;
    }
    string maxString;
    int maxCount = 0;
    for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
        // map是有序的，所以第二个判断可以省略
        if (it->second > maxCount || (it->second == maxCount && it->first < maxString)) {
            maxCount = it->second;
            maxString = it->first;
        }
    }
    cout << maxString << " " << maxCount;
    return 0;
}