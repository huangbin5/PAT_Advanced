#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

struct vNode {
    string name;
    int happiness;
    vNode() {}
    vNode(string _name, int _happiness)
        : name(_name)
        , happiness(_happiness) {}
};

const int maxn = 210;
const int maxInt = 0x3fffffff;
int n, k;
string start;
int sId = 0, romId;
map<string, int> nameToId;
vector<vNode> idToNode;
int edge[maxn][maxn];
bool visited[maxn] = { false };

int pre[maxn];
//最小花费
int cost[maxn];
//幸福指数
int happy[maxn] = { 0 };
//沿途城市数目
int cNum[maxn] = { 0 };
//路径条数
int num[maxn] = { 0 };

void init() {
    fill(edge[0], edge[0] + maxn * maxn, maxInt);
    fill(cost, cost + maxn, maxInt);
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
    }
}

void getBest() {
    romId = nameToId["ROM"];
    cost[sId] = 0;
    happy[sId] = 0;
    cNum[sId] = 0;
    num[sId] = 1;
    for (;;) {
        //选择最小花费
        int u, minCost = maxInt;
        for (int i = 0; i < n; ++i) {
            //这个minCost很容易误写成maxInt
            if (!visited[i] && cost[i] < minCost) {
                u = i;
                minCost = cost[i];
            }
        }
        visited[u] = true;
        if (u == romId)
            break;
        //更新最小花费
        for (int v = 0; v < n; ++v) {
            if (edge[u][v] != maxInt && !visited[v]) {
                vNode node = idToNode[v];
                if (cost[u] + edge[u][v] < cost[v]) {
                    cost[v] = cost[u] + edge[u][v];
                    happy[v] = happy[u] + node.happiness;
                    cNum[v] = cNum[u] + 1;
                    num[v] = num[u];
                    pre[v] = u;
                } else if (cost[u] + edge[u][v] == cost[v]) {
                    num[v] += num[u];
                    if (happy[u] + node.happiness > happy[v]) {
                        happy[v] = happy[u] + node.happiness;
                        cNum[v] = cNum[u] + 1;
                        pre[v] = u;
                    } else if (happy[u] + node.happiness == happy[v] && cNum[u] + 1 < cNum[v]) {
                        cNum[v] = cNum[u] + 1;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void printPath(int v) {
    if (pre[v] != v) {
        printPath(pre[v]);
        cout << "->";
    }
    cout << idToNode[v].name;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    cin >> n >> k >> start;
    idToNode.push_back(vNode(start, 0));
    nameToId[start] = 0;
    string city;
    int happiness;
    for (int i = 1; i < n; ++i) {
        cin >> city >> happiness;
        idToNode.push_back(vNode(city, happiness));
        nameToId[city] = i;
    }
    string city1, city2;
    int e, v1, v2;
    while (k--) {
        cin >> city1 >> city2 >> e;
        v1 = nameToId[city1];
        v2 = nameToId[city2];
        edge[v1][v2] = e;
        edge[v2][v1] = e;
    }
    getBest();
    cout << num[romId] << " " << cost[romId] << " " << happy[romId] << " " << (int)(happy[romId] / cNum[romId]) << endl;
    printPath(romId);
    return 0;
}