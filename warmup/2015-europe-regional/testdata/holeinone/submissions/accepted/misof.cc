#include <bits/stdc++.h>
using namespace std;

typedef long double COORD_TYPE;
typedef complex<COORD_TYPE> point;
typedef vector<point> poly;

#define EPSILON (1e-9) // epsilon used for computations involving doubles ; lower to 1e-9 for %Lf 

bool is_negative(COORD_TYPE x) { return x < -EPSILON; } 
bool is_zero(COORD_TYPE x) { return abs(x) <= EPSILON; }
bool is_positive(COORD_TYPE x) { return x > EPSILON; }
COORD_TYPE size(const point &A) { return sqrt(real(A) * real(A) + imag(A) * imag(A)); }
void normalize(point &A) { COORD_TYPE Asize = size(A); A *= (1/Asize); }
COORD_TYPE square_size  (const point &A)                 { return real(A) * real(A) + imag(A) * imag(A); }
COORD_TYPE dot_product  (const point &A, const point &B) { return real(A) * real(B) + imag(A) * imag(B); }
COORD_TYPE cross_product(const point &A, const point &B) { return real(A) * imag(B) - real(B) * imag(A); }
bool colinear(const point &A, const point &B, const point &C) { return is_zero( cross_product( B-A, C-A )); }
bool colinear(const point &B, const point &C) { return is_zero( cross_product( B,   C ));   }
bool are_equal(const point &A, const point &B) { return is_zero(real(B)-real(A)) && is_zero(imag(B)-imag(A)); }

int N;
vector<point> P,Q;
point T;

bool is_on_segment(const point &A, const point &B, const point &C) { 
    if (!colinear(A,B,C)) return false; else return ! is_positive( dot_product(A-C,B-C) ); 
}

poly intersect_segment_segment(const point &A, const point &B, const point &C, const point &D) {
    point U = B-A, V = D-C, W = C-A, X = D-A;
    if (colinear(U,V)) { // parallel
        // check for degenerate cases
        if (are_equal(A,B)) { if (is_on_segment(C,D,A)) return {A}; }
        if (are_equal(C,D)) { if (is_on_segment(A,B,C)) return {C}; }
        // two parallel segments
        if (!colinear(U,W)) return {}; // not on the same line

        // A, B, C, D all lie on the same non-degenerate line; if A=0 and B=1, what are C and D?
        COORD_TYPE a = 0, b = 1;
        COORD_TYPE c = dot_product(U,W) / square_size(U);
        COORD_TYPE d = dot_product(U,X) / square_size(U);
        COORD_TYPE lo = max(a,min(c,d)), hi = min(b,max(c,d));

        if (is_negative(hi-lo)) return {}; // no intersection
        if (is_zero(hi-lo)) return { A+U*lo }; // one point
        return { A+U*lo, A+U*hi };
    }
    // not parallel, at most one intersection point
    COORD_TYPE k = ( cross_product(C,V) - cross_product(A,V) ) / cross_product(U,V);
    point cand = A + k*U;
    if (is_on_segment(A,B,cand) && is_on_segment(C,D,cand)) return {cand}; else return {};
}

// mirror point A according to line BC
point mirror(const point &A, const point &B, const point &C) {
    point N ( -imag(B-C), real(B-C) );
    normalize(N);
    COORD_TYPE tmp = dot_product(N,B-A);
    return A + 2*tmp*N;
}

bool simulate(point direction, const vector<int> &poradie) {
    vector<bool> alive( P.size(), true );
    point where(0,0);
    normalize(direction);
    for (int expected : poradie) {
        auto exp_is = intersect_segment_segment( where, where+(long double)3000.*direction, P[expected], Q[expected] );
        if (exp_is.size() != 1u) return false;
        point exp_pt = exp_is[0];
        for (int n=0; n<N; ++n) {
            if (n == expected) continue;
            if (!alive[n]) continue;
            auto this_is = intersect_segment_segment( where, where+(long double)3000.*direction, P[n], Q[n] );
            assert( this_is.size() <= 1u );
            if (this_is.size() == 0u) continue;
            point this_pt = this_is[0];
            if (is_negative( size(this_pt-where) - size(exp_pt-where) )) return false;
        }
        alive[ expected ] = false;
        where = exp_pt;
        point where_plus_d = where + direction;
        point mirrored = mirror( where_plus_d, P[expected], Q[expected] );
        direction = mirrored - where;
    }
    for (int n=0; n<N; ++n) {
        if (!alive[n]) continue;
        auto this_is = intersect_segment_segment( where, where+(long double)3000.*direction, P[n], Q[n] );
        if (!this_is.empty()) return false;
    }
    return is_on_segment( where, where+(long double)3000.*direction, T );
}

bool works(const vector<int> &poradie) {
    vector<point> NP = P, NQ = Q;
    point NT = T;
    for (int x : poradie) {
        vector<point> NNP, NNQ;
        for (unsigned i=0; i<NP.size(); ++i) {
            NNP.push_back( mirror( NP[i], NP[x], NQ[x] ) );
            NNQ.push_back( mirror( NQ[i], NP[x], NQ[x] ) );
        }
        NT = mirror( NT, NP[x], NQ[x] );
        NP = NNP;
        NQ = NNQ;
    }
    return simulate( NT, poradie );
}

int main() {
    cin >> N;
    
    double xtarget, ytarget; cin >> xtarget >> ytarget;
    T = point(xtarget,ytarget);
    
    for (int n=0; n<N; ++n) {
        double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        P.push_back( point(x1,y1) );
        Q.push_back( point(x2,y2) );
    }
    
    int answer = -1;
    for (int subset=0; subset<(1<<N); ++subset) {
        vector<int> poradie;
        for (int n=0; n<N; ++n) if (subset & 1<<n) poradie.push_back(n);
        do {
            if (works(poradie)) answer = max( answer, int(poradie.size()) );
        } while (next_permutation(poradie.begin(),poradie.end()));
    }
    if (answer == -1) cout << "impossible" << endl; else cout << answer << endl;
}
