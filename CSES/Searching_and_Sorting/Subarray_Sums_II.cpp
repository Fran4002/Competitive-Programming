#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long int ll;
typedef vector<long long int> vi;

int main() {
    cin.tie(0) -> ios_base::sync_with_stdio(0);
    ll n, x, subs = 0, objt, up, low, pos;

    cin >> n >> x;

    vi presum(n, 0);

    unordered_map<ll, ll> counter;

    cin >> presum[0];
    for (ll i = 1; i < n; i++) {
        cin >> presum[i];
        presum[i] += presum[i - 1];
    }

    counter[0] = 1;


    for (ll i = 0; i < n; i++) {
        //cout << "Iteration: " << i << '\n';
        objt = presum[i] - x;

        if(counter.count(objt))
            subs += counter[objt];

        counter[presum[i]]++;
    }
    //cout << '\n';
    cout << subs << '\n';
}
