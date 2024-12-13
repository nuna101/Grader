#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
    vector<int> copy(v);
    copy.erase(copy.begin(), copy.begin()+position);
    v.erase(v.begin()+position, v.end());
    for(int i = position; i < position+count; ++i) {
        v.push_back(value);
    }
    for(auto c : copy) {
        v.push_back(c);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,value,position,count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    multiple_add(v,value,position,count);
    cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}