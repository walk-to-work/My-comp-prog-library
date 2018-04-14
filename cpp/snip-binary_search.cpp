//vector内にtargetがあればtrue,なければfalseを返す
bool binary_search( vector<int> &v , long target){
	long l = 0;
	long r = v.size();
	while( r - l > 0){
		long mid = (l + r ) / 2;
		if( v[mid] == x )
			return true;
		else if( x < v[mid] )
			r = mid;
		else
			l = mid + 1;
	}
}
