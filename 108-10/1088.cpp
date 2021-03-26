#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
// #define DEBUG

struct fraction {
    ll son, mother;
} a, b;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

fraction simplify(fraction f) {
    if (f.mother < 0) {
        f.son *= -1;
        f.mother *= -1;
    } else if (f.son == 0) {
        f.mother = 1;
    } else {
        ll g = gcd(abs(f.mother), abs(f.son));
        f.son /= g;
        f.mother /= g;
    }
    return f;
}

fraction add(fraction a, fraction b) {
    fraction ans;
    ans.son = a.son * b.mother + a.mother * b.son;
    ans.mother = a.mother * b.mother;
    return simplify(ans);
}

fraction sub(fraction a, fraction b) {
    fraction ans;
    ans.son = a.son * b.mother - a.mother * b.son;
    ans.mother = a.mother * b.mother;
    return simplify(ans);
}

fraction mul(fraction a, fraction b) {
    fraction ans;
    ans.son = a.son * b.son;
    ans.mother = a.mother * b.mother;
    return simplify(ans);
}

fraction div(fraction a, fraction b) {
    fraction ans;
    ans.son = a.son * b.mother;
    ans.mother = a.mother * b.son;
    return simplify(ans);
}

void print(fraction a) {
    a = simplify(a);
    if (a.son < 0)
        printf("(");
    if (a.mother == 1) {
        printf("%lld", a.son);
    } else if (abs(a.son) > a.mother) {
        printf("%lld %lld/%lld", a.son / a.mother, abs(a.son) % a.mother, a.mother);
    } else {
        printf("%lld/%lld", a.son, a.mother);
    }
    if (a.son < 0)
        printf(")");
}

char op[4] = { '+', '-', '*', '/' };
fraction (*cacul[4])(fraction, fraction) = { add, sub, mul, div };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%lld/%lld %lld/%lld", &a.son, &a.mother, &b.son, &b.mother);
    for (int i = 0; i < 4; ++i) {
        print(a);
        printf(" %c ", op[i]);
        print(b);
        printf(" = ");
        if (i == 3 && b.son == 0)
            printf("Inf");
        else
            print(cacul[i](a, b));
        printf("\n");
    }
    return 0;
}