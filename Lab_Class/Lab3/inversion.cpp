#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(int a[], int l, int r, int m) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    ll ans = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] > y[j]) {
            ans += x.size() - i;
            a[l++] = y[j++];
        } else {
            a[l++] = x[i++];
        }
    }
    while (i < x.size()) {
        a[l++] = x[i++];
    }
    while (j < y.size()) {
        a[l++] = y[j++];
    }
    return ans;
}

ll mergesort(int a[], int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    ll ans = 0;
    ans += mergesort(a, l, m);
    ans += mergesort(a, m + 1, r);
    ans += merge(a, l, r, m);
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cout << mergesort(a, 0, n - 1);
    return 0;
}