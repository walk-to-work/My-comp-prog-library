
typedef struct _ufTree{ 
	typedef long idx_type;
	
	vector<idx_type> par;
	vector<idx_type> rank;

	//n要素で初期化
	void init(idx_type n){
		par.assign(n,0);
		rank.assign(n,0);	
		for(idx_type i=0;i<n;i++) par[i]=i;
	}
	
	//木の根を求める
	idx_type root(idx_type x){
		if(par[x]==x) return x;
		else return par[x]=root(par[x]);
	}
	
	//xとyが同じ集合に属するかを調べる
	bool same(idx_type x,idx_type y){
		return root(x)==root(y);
	}
	
	//xとyの属する集合を併合
	void unite(idx_type x,idx_type y){
		x=root(x);
		y=root(y);
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
}ufTree;

