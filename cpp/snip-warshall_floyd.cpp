const int MAX_V = ???;
vector<vector<ll>> dp(MAX_V,vector<ll>(MAX_V,INF));
//d[[i][j]:i,j間の最短経路
int E,V; //頂点数

void wf(){
	rep(k,0,V)
		rep(i,0,V)
			rep(j,0,V)
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] );
}

//入力
void make(){
	rep(i,0,V)
		dp[i][i] = 0;
	
	rep(i,0,E){
		int u,v,c;
		cin>>u>>v>>c;
		u--; v--;
		dp[u][v] = c;
		dp[v][u] = c;
	}
}

