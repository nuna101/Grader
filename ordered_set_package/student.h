#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    v = A;
    set<T> s(v.begin(), v.end());
    for(auto b : B) {
        auto found = s.find(b);
        if(found == s.end()) v.push_back(b);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s(B.begin(), B.end());
    for(auto a : A) {
        auto found = s.find(a);
        if(found != s.end()) v.push_back(a); 
    }
    return v;
}
