#include <iostream>
using namespace std;
// #define DEBUG

int arr[1005], n;

int findLast(int left, int right, int flag) {
    for (int i = left + 1; i <= right + 1; ++i) {
        if (i == right + 1 || (flag == 1 && arr[i] >= arr[left]) || (flag == 2 && arr[i] < arr[left]))
            return i - 1;
    }
}

//-1-都不是; 0-未定; 1-BST; 2-mBST
int judge(int left, int right) {
    int ans = 0;
    //只有一个元素，未定
    if (left >= right - 1)
        return ans;
    //当前可以判断出来的可能，以及左右子树的结果
    int lastPos, leftAns, rightAns;
    if (arr[left + 1] >= arr[left]) {
        lastPos = findLast(left, right, 2);
        //暂定为mBST
        ans = 2;
    } else {
        lastPos = findLast(left, right, 1);
        //暂定为BST
        ans = 1;
    }
    //只有一个分支，未定
    if (lastPos == right)
        ans = 0;
    else {
        for (int i = lastPos + 1; i <= right; ++i) {
            //后半段出现非法数据
            if ((arr[left + 1] >= arr[left] && arr[i] >= arr[left]) || (arr[left + 1] < arr[left] && arr[i] < arr[left]))
                ans = -1;
        }
    }
    //当前就能判断出，都不是
    if (ans == -1)
        return ans;
    leftAns = judge(left + 1, lastPos);
    rightAns = judge(lastPos + 1, right);
    if ((!(leftAns && ans) || leftAns == ans) && (!(rightAns && ans) || rightAns == ans)
        && (!(leftAns && rightAns) || leftAns == rightAns))
        return ans;
    return -1;
}

void postOrder(int left, int right, int flag) {
    if (left > right)
        return;
    int lastPos = findLast(left, right, flag);
    postOrder(left + 1, lastPos, flag);
    postOrder(lastPos + 1, right, flag);
    if (left)
        printf("%d ", arr[left]);
    else
        printf("%d\n", arr[left]);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int ans = judge(0, n - 1);
    if (ans == -1) {
        printf("NO\n");
        return 0;
    } else
        printf("YES\n");
    if (ans == 0) {
        for (int i = n - 1; i >= 0; --i) {
            if (i)
                printf("%d ", arr[i]);
            else
                printf("%d\n", arr[i]);
        }
    } else
        postOrder(0, n - 1, ans);
    return 0;
}