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
