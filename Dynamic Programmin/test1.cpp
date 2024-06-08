#include <bits/stdc++.h>
using namespace std;
int ans(int p, vector<int> vec)
{
    int cnt = 1;
    int a = 0;
    p--;
    if (vec[p] == 1)
        a++;
    while (1)
    {
        if (p - cnt >= 0 and p + cnt < vec.size() - 1 and vec[p + cnt] == vec[p - cnt] and vec[p + cnt] == 1)
        {
            a += 2;
            cnt++;
        }
        else if (p - cnt >= 0 and p + cnt < vec.size() - 1 and vec[p + cnt] == vec[p - cnt] and vec[p + cnt] == 0)
        {
            cnt++;
            continue;
        }
        else if (p - cnt >= 0 and p + cnt < vec.size() - 1 and vec[p + cnt] != vec[p - cnt])
        {
            cnt++;
            continue;
        }
        else
        {
            int temp = cnt;
            while (p - temp >= 0 and vec[p - temp] == 1)
            {
                a++;
                temp++;
            }
            while (p + cnt < vec.size() - 1 and vec[p + cnt] == 1)
            {
                a++;
                cnt++;
            }
            break;
        }
        cout << cnt << " " << a << endl;
    }
    return a;
}
int main()
{
    int p;
    cin >> p;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << ans(p, arr) << endl;
    return 0;
}