long powMod( long a , long p ){
	if( p == 0 ) return 1;
	else if( p == 1 ) return a % mod;
	else if( p % 2 == 0 ){
		long tmp = powMod( a , p/2 );
		return (tmp * tmp) % mod;
	}
	else{
		long tmp = powMod( a , p/2 );
		return ((tmp%mod * tmp%mod) * a ) % mod;
	}
}
struct combLarge{
	typedef long int_type;
	vector<int_type> fact;
	vector<int_type> revFact;
	//input:nCrのn
	void init(int_type N){
		N++;
		fact.assign(N,0);
		revFact.assign(N,0);
		fact[0] = 1;
		for( int i = 1 ; i < N ; i++ ){
			fact[i] = fact[i-1] * i;
			fact[i] %= mod;
		}
		revFact[N-1] = powMod(fact[N-1] , mod - 2);
		for(int i = N-2 ; i >= 0 ; i-- ){
			revFact[i] = revFact[i+1] * (i+1);
			revFact[i] %= mod;
		}
	}
	//input:nCrのnとr output:nCr
	int_type getC(int_type a , int_type b){
		return (((fact[a] * revFact[b]) % mod) * revFact[a-b] ) % mod;
	}
};
