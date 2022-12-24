#include <bits/stdc++.h>
using namespace std;
vector<long long> solve(vector<long long> v){
    for (long long i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            v.push_back(v[i] / 2);
            v.push_back(v[i] / 2);
        }
        else
        {
            return v;
        }
    }
    return v;
} 
int main()
{
    long long n,q;
    cin>>n>>q;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long ans;
        cin>>ans;
        v.push_back(ans);
    }
    long long sum=0;

    for (long long i = 0; i < v.size(); i++)
    {
        sum+=v[i];
    }
    cout<<sum<<endl;
    return 0;
}