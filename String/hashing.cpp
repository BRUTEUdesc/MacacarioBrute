#include <bits/stdc++.h>
using namespace std;

struct hash{
    static const long long LIM = 1000006;
    long long p, m, pw[LIM], hsh[LIM];
    hashing(long long p, long long m) : p(p), m(m) {
        pw[0] = 1;
        for(int i = 1; i < LIM; i++) pw[i] = (pw[i-1] * p) % m;
    }
    void set_string(string& s) {
        hsh[0] = s[0];
        for (int i = 1; i < s.size(); i++) hsh[i] = (hsh[i-1] * p + s[i]) % m;
    }
    long long range(int esq, int dir) {
        long long ans = hsh[dir];
        if(esq > 0) ans = (ans - (hsh[esq-1] * pw[dir-esq+1] % m) + m) % m;
        return ans;
    }
};