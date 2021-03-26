#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
// #define DEBUG

struct Family {
    //家庭最小的id
    int id;
    //家庭成员
    set<int> member;
    //房产数，房产总面积
    int sets, area;
    double avgSets, avgArea;
    Family() {}
    Family(int _id)
        : id(_id) {
        sets = 0;
        avgSets = 0;
        area = 0;
        avgArea = 0;
    }
};

const int maxn = 10000;
//并查集，记录家庭
int ufind[maxn];
//记录家庭到房产的映射关系，只有根节点才会有映射
map<int, Family> mp;
vector<Family*> estate;
int n;

void init() {
    for (int i = 0; i < maxn; ++i)
        ufind[i] = i;
}

int find(int x) {
    if (x == ufind[x])
        return x;
    int f = find(ufind[x]);
    ufind[x] = f;
    return f;
}

int merge(int a, int b) {
    // ra肯定有房产
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
        ufind[rb] = ra;
        if (mp.count(rb)) {
            mp[ra].id = min(mp[ra].id, mp[rb].id);
            for (set<int>::iterator it = mp[rb].member.begin(); it != mp[rb].member.end(); ++it) {
                mp[ra].member.insert(*it);
            }
            mp[ra].sets += mp[rb].sets;
            mp[ra].area += mp[rb].area;
            mp.erase(rb);
        } else {
            mp[ra].id = min(mp[ra].id, rb);
            mp[ra].member.insert(rb);
        }
    }
}

//如果当前节点已经存在，将它转移至根节点，否则新建节点
void handel(int x) {
    int r = find(x);
    if (mp.count(r)) {
        ufind[r] = x;
        ufind[x] = x;
        mp[x] = mp[r];
        mp.erase(r);
    } else {
        mp[x] = Family(x);
        mp[x].member.insert(x);
    }
}

bool cmp(Family* a, Family* b) {
    if (a->avgArea != b->avgArea)
        return a->avgArea > b->avgArea;
    return a->id < b->id;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d", &n);
    int id, father, mother, k, child, sets, area;
    while (n--) {
        scanf("%d%d%d%d", &id, &father, &mother, &k);
        handel(id);
        if (father != -1)
            merge(id, father);
        if (mother != -1)
            merge(id, mother);
        while (k--) {
            scanf("%d", &child);
            merge(id, child);
        }
        scanf("%d%d", &sets, &area);
        mp[id].sets += sets;
        mp[id].area += area;
    }
    for (map<int, Family>::iterator it = mp.begin(); it != mp.end(); ++it) {
        Family* tmp = &(it->second);
        estate.push_back(tmp);
        tmp->avgSets = (double)tmp->sets / tmp->member.size();
        tmp->avgArea = (double)tmp->area / tmp->member.size();
    }
    sort(estate.begin(), estate.end(), cmp);
    printf("%d\n", estate.size());
    for (vector<Family*>::iterator it = estate.begin(); it != estate.end(); ++it) {
        printf("%04d %d %.3f %.3f\n", (*it)->id, (*it)->member.size(), (*it)->avgSets, (*it)->avgArea);
    }
    return 0;
}