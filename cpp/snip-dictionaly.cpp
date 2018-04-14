string dictionaly(string s){
	vector<char> v;
	for(int i = 0 ; i < s.size() , i++ )
		v.push_back(s[i]);
	
	sort(v.begin() , v.end() );
	
	for(int i = 0 ; i < s.size() ; i++ )
		s[i] = v[i];
	
	return s;
}
