#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

// Function to compute the hash code of pattern p
int hashcodep(const string &p) {
    int c = 0;
    for (char ch : p) {
        c = (c * 256 + ch) % mod;
    }
    return c;
}

// Function to compute the hash code of substring s[start...end]
int hashcodes(const string &s, int start, int end) {
    int c = 0;
    for (int i = start; i <= end; ++i) {
        c = (c * 256 + s[i]) % mod;
    }
    return c;
}

// Function to compute (x^y) % mod using modular exponentiation
ll pinpow(int x, int y) {
    if (y == 0) return 1;
    ll tmp = pinpow(x, y / 2);
    if (y % 2 == 0) {
        return (tmp * tmp) % mod;
    } else {
        return ((tmp * tmp) % mod * x) % mod;
    }
}

// Rabin-Karp algorithm to count occurrences of P in T
int Rabin_Karp(string P, string T) {
    int cnt = 0, N = T.length(), M = P.length();
    int codeP = hashcodep(P);
    int codeT = hashcodes(T, 0, M - 1);
    ll e = pinpow(256, M - 1);

    for (int s = 0; s <= N - M; ++s) {
        if (codeT == codeP) {
            bool ok = true;
            for (int j = 0; j < M; ++j) {
                if (P[j] != T[s + j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt++;
        }
        if (s < N - M) {
            codeT = (codeT - T[s] * e % mod) % mod; 
            codeT = (codeT * 256 + T[s + M]) % mod;
        }
    }
    return cnt;
}

int main() {
    string P, T;
    getline(cin, P);
    cin.ignore();
    getline(cin, T);
    cout << Rabin_Karp(P, T) << endl;
    return 0;
}