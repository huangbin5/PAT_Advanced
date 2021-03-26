#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 2005;
//顶点
struct Node {
    string name;
    int time = 0;
    bool visited = false;
} node[maxn];
//根据name找id
map<string, int> mp;
//边
int edge[maxn][maxn] = { 0 };
//顶点数，边数，门限
int vNum = 0, eNum, threthold;
//要输出的内容
struct Ans {
    string headName;
    int headTime;
    int totalTime;
    int count;
} ans;
vector<Ans> answer;

void dfs(int v) {
    node[v].visited = true;
    ans.totalTime += node[v].time;
    ++ans.count;
    if (node[v].time > ans.headTime) {
        ans.headTime = node[v].time;
        ans.headName = node[v].name;
    }
    for (int i = 0; i < vNum; ++i) {
        if (edge[v][i] && !node[i].visited)
            dfs(i);
    }
}

bool cmp(Ans a, Ans b) { return a.headName < b.headName; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    cin >> eNum >> threthold;
    string name1, name2;
    int time, id1, id2;
    while (eNum--) {
        cin >> name1 >> name2 >> time;
        //分配编号
        if (!mp.count(name1))
            mp[name1] = vNum++;
        if (!mp.count(name2))
            mp[name2] = vNum++;
        id1 = mp[name1], id2 = mp[name2];
        //关联边
        edge[id1][id2] = edge[id2][id1] = 1;
        //更新顶点
        node[id1].name = name1;
        node[id1].time += time;
        node[id2].name = name2;
        node[id2].time += time;
    }
    for (int i = 0; i < vNum; ++i) {
        if (!node[i].visited) {
            ans.headTime = 0;
            ans.count = 0;
            ans.totalTime = 0;
            dfs(i);
            //时间是以节点相加的，每条边加了两次
            ans.totalTime >>= 1;
            if (ans.count > 2 && ans.totalTime > threthold)
                answer.push_back(ans);
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i].headName << " " << answer[i].count << endl;
    }
    return 0;
}