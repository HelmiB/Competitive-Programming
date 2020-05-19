#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

struct edge {
	int to, flow, cap, cost, rev;
};

struct MinCostMaxFlow{
    const int INF = 1LL << 60;
	struct edge {
		int to;
		int cap;
		int cost;
		int rev;
		bool isrev;
 
		edge(int _to, int _cap, int _cost, int _rev, bool _isrev) :to(_to), cap(_cap), cost(_cost), rev(_rev), isrev(_isrev) {}
 
	};
	vector<vector<edge>> graph;
	vector<int> potential, min_cost;
	vector<int> prevv, preve;
	MinCostMaxFlow(int V) :graph(V) {}
 
	void add_edge(int from, int to, int cap, int cost) {
		graph[from].emplace_back(to, cap, cost, graph[to].size(), false);
		graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1, true);
	}
 
	int min_cost_flow(int s, int t, int f) {
		int V = graph.size();
		int res = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		potential.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);
 
		while (f > 0) {
			min_cost.assign(V, INF);
			pq.emplace(0, s);
			min_cost[s] = 0;
			while (!pq.empty()) {
				auto cur = pq.top();
				pq.pop();
				if (min_cost[cur.second] < cur.first) continue;
				for (int i = 0; i < graph[cur.second].size(); i++) {
					edge& e = graph[cur.second][i];
					int nextCost = min_cost[cur.second] + e.cost + potential[cur.second] - potential[e.to];
					if (e.cap > 0 and min_cost[e.to] > nextCost) {
						min_cost[e.to] = nextCost;
						prevv[e.to] = cur.second;
						preve[e.to] = i;
						pq.emplace(min_cost[e.to], e.to);
					}
 
				}
			}
			if (min_cost[t] == INF) return -1;
			for (int v = 0; v < V; v++) potential[v] += min_cost[v];
			int add_flow = f;
			for (int v = t; v != s; v = prevv[v]) {
				add_flow = min(add_flow, graph[prevv[v]][preve[v]].cap);
			}
			f -= add_flow;
			res += add_flow * potential[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge& e = graph[prevv[v]][preve[v]];
				e.cap -= add_flow;
				graph[v][e.rev].cap += add_flow;
			}
		}
		return res;
	}
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector < int > mini(n, 1), maxi(n, n);
    for(int i = 0 ; i < q ; ++i){
        int t, l, r, v;
        cin >> t >> l >> r >> v;
        for(int j = l - 1 ; j < r ; ++j)
            if(t == 1) mini[j] = max(mini[j], v);
            else maxi[j] = min(maxi[j], v);
    }
    MinCostMaxFlow mcmf(2 * n + 2);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 1 ; j <= n ; ++j)
            mcmf.add_edge(2 * n, i, 1, j * j - (j - 1) * (j - 1));
    for(int i = 0 ; i < n ; ++i)
        for(int j = mini[i] - 1; j < maxi[i]; ++j)
            mcmf.add_edge(j, i + n, 1, 0);
    for(int i = 0 ; i < n ; ++i)
        mcmf.add_edge(i + n, 2 * n + 1, 1, 0);
    cout << mcmf.min_cost_flow(2 * n, 2 * n + 1, n) << '\n';    
    return 0;
}