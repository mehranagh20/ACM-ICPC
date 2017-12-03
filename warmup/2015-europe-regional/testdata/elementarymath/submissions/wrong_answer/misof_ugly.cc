#include <bits/stdc++.h>
using namespace std;

const long long TIMELIMIT_MICROSECONDS = 5000000;

int N;
vector< vector<long long> > G;
map<long long, vector<int> > Gtrans;

map<long long,long long>
experiment() {
    map<long long, set<long long> > G1;
    map<long long, set<long long> > G2;

    map<long long, long long> answer;

    for (int n=0; n<N; ++n) G1[n].insert( G[n].begin(), G[n].end() );
    for (const auto &rec : Gtrans) G2[rec.first].insert( rec.second.begin(), rec.second.end() );

    while (true) {
        if (G1.empty()) return answer;
        bool zmena = false;

        for (const auto &rec : G1) if (rec.second.empty()) return {};

        {
            set<long long> zmaz1;
            set<long long> zmaz2;
            for (const auto &rec : G1) if (rec.second.size()==1u) { answer[rec.first] = *rec.second.begin(); zmaz1.insert(rec.first); zmaz2.insert(*rec.second.begin()); }
            if (zmaz1.size() != zmaz2.size()) return {};
            for (auto y : zmaz2) for (auto x : G2[y]) G1[x].erase(y);
            for (auto x : zmaz1) G1.erase(x);
            for (auto y : zmaz2) G2.erase(y);
            zmena |= !zmaz1.empty();
        }

        {
            set<long long> zmaz1;
            set<long long> zmaz2;
            for (const auto &rec : G2) if (rec.second.size()==1u) { 
                long long x = *rec.second.begin(), y = rec.first;
                if (zmaz1.count(x)) { zmaz2.insert(y); continue; }
                answer[x] = y;
                zmaz1.insert(x);
                zmaz2.insert(y);
            }
            for (auto x : zmaz1) for (auto y : G1[x]) G2[y].erase(x);
            for (auto x : zmaz1) G1.erase(x);
            for (auto y : zmaz2) G2.erase(y);
            zmena |= !zmaz1.empty();
        }
        
        if (!zmena) {
            auto x = G1.begin()->first;
            vector<long long> tmp ( G1.begin()->second.begin(), G1.begin()->second.end() );
            unsigned u = tmp.size();
            auto y = tmp[ rand()%u ];
            answer[x] = y;
            for (auto yy : tmp) G2[yy].erase(x);
            for (auto xx : G2[y]) G1[xx].erase(y);
            G1.erase(x);
            G2.erase(y);
        }
    }
}

// GETTIMER machinery {{{"
#include <sys/time.h>
struct timeval __timer1, __timer2;
bool __timerInitialized = false;
#define STARTTIMER { gettimeofday(&__timer1,NULL); __timerInitialized = true; }
#define GETTIMER ({ assert(__timerInitialized); gettimeofday(&__timer2,NULL); long long __runtime = 1000000LL*(__timer2.tv_sec-__timer1.tv_sec) + 1LL*(__timer2.tv_usec-__timer1.tv_usec); __runtime; })
// }}}

int main() {
    STARTTIMER;
    cin >> N;
    G.resize(N);
    vector<long long> A, B;
    for (int n=0; n<N; ++n) {
        long long a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        long long c=a+b, d=a-b, e=a*b;
        G[n].push_back(c);
        if (d!=c) G[n].push_back(d);
        if (e!=d && e!=c) G[n].push_back(e);
        for (long long x : G[n]) Gtrans[x].push_back(n);
    }
    while (true) {
        auto answer = experiment();
        if (answer.empty()) {
            if (GETTIMER > 0.9 * TIMELIMIT_MICROSECONDS) { cout << "impossible" << endl; break; }
            continue;
        }
        for (int n=0; n<N; ++n) {
            int a = A[n], b = B[n];
            long long c=a+b, d=a-b, e=a*b;
            if (c == answer[n]) { cout << a << "+" << b << "=" << answer[n] << endl; continue; }
            if (d == answer[n]) { cout << a << "-" << b << "=" << answer[n] << endl; continue; }
            if (e == answer[n]) { cout << a << "*" << b << "=" << answer[n] << endl; continue; }
        }
        break;
    }
}
