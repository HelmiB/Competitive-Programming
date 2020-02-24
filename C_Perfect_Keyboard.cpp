#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        set < int > g[27];
        int in[27] = {0};
        for(int i = 0 ; i < (int)s.length() - 1 ; ++i){
            g[s[i] - 'a'].insert(s[i + 1] - 'a');
            g[s[i + 1] - 'a'].insert(s[i] - 'a');
        }
        for(int i = 0 ; i < 26 ; ++i) in[i] = (int)g[i].size();
        bool no = false;
        for(int i = 0 ; i < 26 ; ++i)
            if(in[i] > 2)
                no = true;
        if(no){
            cout << "NO\n";
            continue;
        }
        string res = "";
        set < pair < int, int > > st;
        for(int i = 0 ; i < 26 ; ++i) st.insert({in[i], i});
        while(!st.empty()){
            auto u = *st.begin();
            st.erase(u);
            while(true){
                bool ok = false;
                res += (char)(u.second + 'a');
                for(auto v : g[u.second])
                    if(st.find({in[v], v}) != st.end()){
                        ok = true;
                        u = {in[v], v};
                        st.erase(u);
                        break;
                    }
                if(!ok) break;
                }
        }
        for(int i = 0 ; i < (int)s.length() - 1 ; ++i){
            no = true;
            for(int j = 0 ; j < 25 ; ++j)
                if((res[j] == s[i] && res[j + 1] == s[i + 1]) || (res[j] == s[i + 1] && res[j + 1] == s[i]))
                    no = false;
            if(no) break;
        }
        if(no){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << res << '\n';
    }

    return 0;
}
