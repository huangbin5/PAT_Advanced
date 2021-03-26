#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int unsorted[105], sorted[105], n;

//如果前面一部分是有序的，并且后面一部分顺序和原序列一致，则为插入排序
// 0-堆排序，非0-插入排序第一个无序元素
int judge() {
    int next = 1;
    //找到第一个无序部分的元素
    while (next < n && sorted[next] >= sorted[next - 1])
        ++next;
    for (int i = next; i < n; ++i) {
        if (sorted[i] != unsorted[i])
            return 0;
    }
    return next;
}

void handelInsertion(int next) {
    int tmp = sorted[next];
    while (next > 0 && tmp < sorted[next - 1]) {
        sorted[next] = sorted[next - 1];
        --next;
    }
    sorted[next] = tmp;
}

void handelHeap() {
    int next = 1;
    while (sorted[next] < sorted[0])
        ++next;
    --next;
    swap(sorted[0], sorted[next]);
    int i = 0;
    //下滤
    while (2 * i + 1 < next) {
        int maxIdx = 2 * i + 1;
        if (2 * i + 2 < next && sorted[2 * i + 2] > sorted[2 * i + 1])
            maxIdx = 2 * i + 2;
        if (sorted[maxIdx] < sorted[i])
            break;
        swap(sorted[maxIdx], sorted[i]);
        i = maxIdx;
    }
}

void print() {
    for (int i = 0; i < n; ++i) {
        if (i == n - 1)
            printf("%d\n", sorted[i]);
        else
            printf("%d ", sorted[i]);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &unsorted[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &sorted[i]);
    int next = judge();
    if (next) {
        printf("Insertion Sort\n");
        handelInsertion(next);
    } else {
        printf("Heap Sort\n");
        handelHeap();
    }
    print();
    return 0;
}