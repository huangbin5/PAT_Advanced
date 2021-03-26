#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 10005;
struct Node {
    string id;
    int online, middle, final, g;
    Node(string _id)
        : id(_id) {
        online = middle = final = g = -1;
    }
};
vector<Node> stu;
map<string, int> mp;
int p, m, n;

bool cmp(Node a, Node b) {
    if (a.g != b.g)
        return a.g > b.g;
    return a.id < b.id;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &p, &m, &n);
    char s[25];
    int score;
    while (p--) {
        scanf("%s%d", s, &score);
        string id(s);
        mp[id] = stu.size();
        Node node(id);
        node.online = score;
        stu.push_back(node);
    }
    while (m--) {
        scanf("%s%d", s, &score);
        string id(s);
        if (mp.count(id)) {
            stu[mp[id]].middle = score;
        } else {
            mp[id] = stu.size();
            Node node(id);
            node.middle = score;
            stu.push_back(node);
        }
    }
    while (n--) {
        scanf("%s%d", s, &score);
        string id(s);
        if (mp.count(id)) {
            stu[mp[id]].final = score;
        } else {
            mp[id] = stu.size();
            Node node(id);
            node.final = score;
            stu.push_back(node);
        }
    }
    for (int i = 0; i < stu.size(); ++i) {
        Node& node = stu[i];
        if (node.online < 200)
            continue;
        if (node.middle <= node.final)
            node.g = node.final;
        else
            node.g = round(0.4 * node.middle + 0.6 * node.final);
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < stu.size() && stu[i].g >= 60; ++i) {
        Node& node = stu[i];
        printf("%s %d %d %d %d\n", node.id.c_str(), node.online, node.middle, node.final, node.g);
    }
    return 0;
}