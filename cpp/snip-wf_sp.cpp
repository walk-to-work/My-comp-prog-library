const int MAX_V = ???;
vector<vector<ll>> d(MAX_V,vector<ll>(MAX_V,INF));
//d[[i][j]:i,j間の最短経路
int E,V; //辺の数，頂点数
int nxt[MAX_V][MAX_V];
void wf(){
	rep(k,0,V){
		rep(i,0,V){
			rep(j,0,V){
				if( d[i][j] > d[i][k] + d[k][j] ){
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
}

//入力
void make(){
	rep(i,0,E){
		int u,v,c;
		cin>>u>>v>>c;
		u--; v--;
		d[u][v] = c;
		d[v][u] = c;
	}
}

//初期化
void init(){
	rep(i,0,V){
		rep(j,0,V){
			if( i == j ) d[i][j] = 0;
			else d[i][j] = INF;
			nxt[i][j] = i;
		}
	}
}

//経路復元
void printPath( int start , int goal ){
	for(int cur = start ; cur != goal ; cur = next[cur][goal] )
		cout << cur << " ";
	cout << goal << endl;
}
