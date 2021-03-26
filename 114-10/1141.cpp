#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 100005;
struct Institution {
    string code;
    double score;
    int number;
    Institution() {}
    Institution(string _code, double _score)
        : code(_code)
        , score(_score) {
        number = 1;
    }
};
vector<Institution> institutionArr;
map<string, int> codeToIdx;

bool cmp(Institution a, Institution b) {
    if ((int)a.score != (int)b.score)
        return (int)a.score > (int)b.score;
    if (a.number != b.number)
        return a.number < b.number;
    return a.code < b.code;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, score;
    double realScore;
    string id, code;
    cin >> n;
    while (n--) {
        cin >> id >> score >> code;
        transform(code.begin(), code.end(), code.begin(), ::tolower);
        if (id[0] == 'T')
            realScore = (double)score * 1.5;
        else if (id[0] == 'A')
            realScore = (double)score;
        else
            realScore = (double)score / 1.5;
        if (codeToIdx.count(code)) {
            Institution& ins = institutionArr[codeToIdx[code]];
            ++ins.number;
            ins.score += realScore;
        } else {
            codeToIdx[code] = institutionArr.size();
            Institution ins(code, realScore);
            institutionArr.push_back(ins);
        }
    }
    sort(institutionArr.begin(), institutionArr.end(), cmp);
    cout << institutionArr.size() << endl;
    int r;
    for (int i = 0; i < institutionArr.size(); ++i) {
        Institution ins = institutionArr[i];
        if (i == 0 || (int)ins.score != (int)institutionArr[i - 1].score)
            r = i + 1;
        cout << r << " " << ins.code << " " << (int)ins.score << " " << ins.number << endl;
    }
    return 0;
}