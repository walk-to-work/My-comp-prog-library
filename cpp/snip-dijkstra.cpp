typedef struct edge_{
	int to,cost;
}edge;

class graph{ 
	typedef long cost_type;
	typedef int edge_type;
	typedef pair<cost_type,edge_type> P; 	//first:最短経路コスト second:頂点番号
	
	private:
		vector<vector<edge> > gra; 	//グラフ本体
		priority_queue<P,vector<P>,greater<P> > que; 	//最短経路の値の小さいものから取り出せる
		edge_type V; 	//頂点の個数
	  vector<cost_type> dp; 	//開始地点からの最小コストを格納する配列
	
	public:
		void init(int num){
			V = num;
			dp.assign(V,0x7FFFFFFF);
			gra.assign(V,vector<edge>());
		}

		void setCost(edge_type from , edge_type to , edge_type cost){
			edge e = {to , cost};
			edge e2 = {from , cost};
			gra[from].push_back( e );
			gra[to].push_back(e2);
		}	
		
		void setDirectCost(edge_type from , edge_type to , edge_type cost){
			edge e = {to , cost};
			gra[from].push_back( e );
		}	

		void dijkstra(edge_type s){
			dp[s] = 0;
			que.push(pair<cost_type,edge_type>(0,s)); 

			while(!que.empty()){
				P p = que.top();
				que.pop();
				edge_type v = p.second;
				if( dp[v] > p.first ) continue;
				for(edge_type i = 0 ; i < gra[v].size() ; i++ ){
					edge e = gra[v][i];
					if( dp[e.to] > dp[v] + e.cost ){
						dp[e.to] = dp[v] + e.cost;
						que.push(pair<cost_type,edge_type>(dp[e.to],e.to));
					}
				}
			}
		}

		cost_type getCost(edge_type to){
			return dp[to];
		} 

};
