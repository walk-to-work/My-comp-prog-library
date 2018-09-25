template<typename T>
vector<vector<T>>(T N){
	vector<vector<T>> C(N , vector<T> (N));
	for(int i = 0 ; i < N ; i++ ){
		C[i][0] = 1;
		for(int j = 0 ; j <= i ; j++ ){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if( C[i][j] >= mod ) C[i][j] -= mod;
		}
	}
}
