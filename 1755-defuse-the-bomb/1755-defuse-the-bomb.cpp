using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define pq priority_queue
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = sz(code);
        int sum = 0;
        vi result(n, 0);
        if(k == 0) return result;
        if(k > 0){
            rep(i , 0, k){
                sum +=code[(i+1)%n];
            }
            rep(i, n, 2*n){
                cout<<code[(i+1)%n]<<" "<<code[(i+k+1)%n]<<endl;
                result[i%n] = sum;
                sum = sum - code[(i + 1) % n] + code[(i + k + 1) % n];
            }
        }else{
            k = -k;
            rep(i, 1, k+1){
                sum += code[(n - i) % n];
            }

            rep(i, 0, n){
                result[i] = sum;
                sum = sum - code[(n + i - k) % n] + code[(n + i) % n];
            }
        }
        return result;
    }
};