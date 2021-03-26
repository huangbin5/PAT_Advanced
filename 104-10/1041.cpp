#include <iostream>
#include<map>
using namespace std;
// #define DEBUG

int num[100005];
map<int,int> count;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&num[i]);
        ++count[num[i]];
    }
    for(int i=0;i<N;++i){
        if(count[num[i]]==1){
            printf("%d",num[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}