#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 1005;
struct Student {
    string id;
    int site, time;
    int score;
    Student(string _id, int _site, int _time, int _score)
        : id(_id)
        , site(_site)
        , time(_time)
        , score(_score) {}
};
struct Site {
    int id, cnt;
    Site(int _id, int _cnt)
        : id(_id)
        , cnt(_cnt) {}
};
map<int, int> idToIdx;
vector<Student> stu;
vector<Site> site;
int n, m;

bool cmpStu(Student a, Student b) {
    if (a.score != b.score)
        return a.score > b.score;
    return a.id < b.id;
}

void handleLevel(char query) {
    bool NA = true;
    for (int i = 0; i < stu.size(); ++i) {
        if (stu[i].id[0] == query) {
            printf("%s %d\n", stu[i].id.c_str(), stu[i].score);
            NA = false;
        }
    }
    if (NA)
        printf("NA\n");
}

void handleSite(int query) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < stu.size(); ++i) {
        if (stu[i].site == query) {
            ++cnt;
            sum += stu[i].score;
        }
    }
    if (cnt)
        printf("%d %d\n", cnt, sum);
    else
        printf("NA\n");
}

bool cmpSite(Site a, Site b) {
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.id < b.id;
}

void handleTime(int query) {
    idToIdx.clear();
    site.clear();
    for (int i = 0; i < stu.size(); ++i) {
        if (stu[i].time == query) {
            int siteId = stu[i].site;
            if (idToIdx.count(siteId))
                ++site[idToIdx[siteId]].cnt;
            else {
                idToIdx[siteId] = site.size();
                site.push_back(Site(siteId, 1));
            }
        }
    }
    if (site.empty())
        printf("NA\n");
    else {
        sort(site.begin(), site.end(), cmpSite);
        for (int i = 0; i < site.size(); ++i) {
            printf("%03d %d\n", site[i].id, site[i].cnt);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    char tmp[20];
    int score;
    string id;
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", tmp, &score);
        id = string(tmp);
        stu.push_back(Student(id, stoi(id.substr(1, 3)), stoi(id.substr(4, 6)), score));
    }
    sort(stu.begin(), stu.end(), cmpStu);
    for (int i = 1; i <= m; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char query;
            scanf(" %c", &query);
            printf("Case %d: %d %c\n", i, type, query);
            handleLevel(query);
        } else {
            int query;
            scanf("%d", &query);
            if (type == 2) {
                printf("Case %d: %d %03d\n", i, type, query);
                handleSite(query);
            } else {
                printf("Case %d: %d %06d\n", i, type, query);
                handleTime(query);
            }
        }
    }
    return 0;
}