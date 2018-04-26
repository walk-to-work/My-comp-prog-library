const int MAX_V = 100;
typedef struct edge_{int to,cost;}edge;
typedef pair<int,int> P; 	//firstは最短距離，secondは頂点の番号
int V; 										//頂点数
vector<edge> G[MAX_V];
int dp[MAX_V]; 						//頂点Sからの最小距離
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	//firstの値が最小のものがtopとなる
	memset(d,d+v,inf);
	d[s] = 0;
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if( dp[v] < p.first ) 	continue;
		for( int i = 0 ; i < G[v].size() ; i++ ){
			edge e = G[v][i];
			if( dp[e.to] = d[v] + e.cost){
				dp[e.to] = dp[v] + e.cost;
				que.push(P(dp[e.to],e.to));
			}
		}
	}
	return;
}

