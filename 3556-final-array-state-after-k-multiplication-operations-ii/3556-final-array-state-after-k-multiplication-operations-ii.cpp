typedef pair<long, int> pi;
typedef long long ll;  // Use long long to avoid overflow
int mod = 1e9 + 7;

class Solution {
    ll mod_val(ll a, ll n) {
        ll res = 1;
        while (n) {
            if (n % 2) {
                res = (res * a) % mod;
                n--;
            } else {
                a = (a * a) % mod;
                n /= 2;
            }
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        if (m == 1)
            return nums;

        set<pi> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            st.insert({nums[i], i});

        while (k) {
            auto firstit = st.begin();
            auto lastit = --st.end();  // Corrected to point to the last element

            if ((*firstit).first * m > (*lastit).first)
                break;
            else {
                int ind = (*firstit).second;
                ll val = ((*firstit).first * 1LL * m) % mod;  // Cast to long long to avoid overflow
                st.erase(firstit);
                st.insert({val, ind});
            }
            k--;
        }

        vector<pi> v;
        for (auto it : st)
            v.push_back(it);

        ll value = mod_val(m, k / n) % mod;  // Use k / n before modifying k

        for (int i = 0; i < n; i++) {
            v[i].first = (v[i].first * value) % mod;
        }

        int extra = k % n;
        for (int i = 0; i < extra; i++) {
            v[i].first = (v[i].first * m) % mod;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[v[i].second] = v[i].first;
        }
        return ans;
    }
};
