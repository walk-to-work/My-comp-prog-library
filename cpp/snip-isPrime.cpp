template<class X> bool is_prime( X n ){
	if(n <= 0 )
		return false;
	else if( n == 1 )
		return false;
	else if( n == 2 )
		return true;
	else{
		X limit = sqrt(n)+1;
		if( n % 2 == 0 )
			return false;
		for(X i = 3 ; i <= limit ; i += 2 ){
			if( n % i == 0 )
				return false;
		}
	}
	return true;
}

