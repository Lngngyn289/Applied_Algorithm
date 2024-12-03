#include<bits/stdc++.h>
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

bool check(int a[], int n, int c, int dis) {
    int cnt = 1;
    int last_pos = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last_pos >= dis) {
            cnt++;
            last_pos = a[i];
            if (cnt == c) return true;
        }
    }
    return false;
}

int findmaximaldistance(int a[], int n, int c) {
    sort(a, a + n);
    int l = 0, r = a[n - 1] - a[0];
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(a, n, c, m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

int main() {
    faster();
    int t;
    scanf("%d",&t);
    while (t--) {
        int n, c;
        scanf("%d%d",&n,&c);
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d",&a[i]);
        printf("%d\n",findmaximaldistance(a, n, c));
    }
    return 0;
}