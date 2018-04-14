

long med3( long x , long y , long z){
	if( x < y ){
		if( y < z )
			ret y;
		else
			ret z;
	}
	else{
		if( x < z )
			ret x;
		else
			ret z;
	}
}

//pairの第1引数でソートする
void quick_sort( vector<pair<long,int>> &array , int left , int right ){
	if( left < right ){
		int i = left;
		int j = right;
		long pivot = (array[i].first+array[j].first)/2;
		while(1){
			while(array[i].first < pivot)
				i++;
			while(pivot < array[j].first)
				j--;
			if( i >= j )
				break;
			iter_swap( array.begin()+i , array.begin()+j );
		}
		quick_sort( array , left , i-1 );
		quick_sort( array , j+1 , right);
	}
}


