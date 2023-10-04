class Solution {
public:
    void update(vector<int> &bit, int idx){
        while(idx < bit.size()){
            bit[idx]++;
            idx += (idx & (-idx));
        }
        return ;
    }
    int query(vector<int> &bit, int idx){
        int res = 0;
        while(idx > 0){
            res += bit[idx];
            idx -= (idx & (-idx));
        }
        return res;
    }
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
       vector<int> bit(n+1, 0);
        set<long long> st(arr.begin(), arr.end());
        int c = 1;
        map<long long,int> mp;
        for(auto &v : st){
            mp[v] = c;
            c++;
        }
        update(bit, mp[arr[0]]);
        int ans = 0;
        for(int i=1; i<n; i++){
            long long val = 1ll*2 * arr[i];
            auto it = st.lower_bound(val);
            if(it != st.end()){
                int res;
                if(*it == 1ll*2*arr[i]) res = query(bit, mp[*it]);
                else res = query(bit, mp[*it] - 1);
                ans += (i - res);
            }
            update(bit, mp[arr[i]]);
        }
        return ans;
        
    }
};
