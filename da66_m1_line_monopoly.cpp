#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool arr[20000000];
    int n, c, ans = 0;
    long long f, l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> f >> l;
            while (f <= l)
            {
                if (arr[f - 1] == 0 && arr[f] == 0 && arr[f + 1] == 0)
                    ans++;
                if (arr[f - 1] == 1 && arr[f] == 0 && arr[f + 1] == 1)
                    ans--;
                arr[f] = 1;
                ++f;
            }
        }
        else
            cout << ans << "\n";
    }
}
