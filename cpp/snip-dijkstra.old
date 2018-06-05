const int MAX_V = ???;
typedef struct edge_{int to,cost;}edge;
typedef pair<int,int> P; 	//firstは最短経路,secondは頂点番号
int V; 										//頂点数
vector<vector<edge>> G(MAX_V);
int dp[MAX_V];
void dijkstra( int s ){
	//最短経路の値の小さいものから取り出せる
	priority_queue<P,vector<P>,greater<P>> que;
	for(int i = 0 ; i < V ; i++ ) dp[i] = INF;
	dp[s] = 0;
	que.push(pair<int,int>(0,s));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if( dp[v] > p.first ) continue;
		for(int i = 0 ; i < G[v].size() ; i++ ){
			edge e = G[v][i];
			if( dp[e.to] > dp[v] + e.cost ){
				dp[e.to] = dp[v] + e.cost;
				que.push(pair<int,int>(dp[e.to],e.to));
			}
		}
	}
	return;
}
//input:G[from].push_back( edge { to , cost } );
//output:dp[to] = sum of journey cost

