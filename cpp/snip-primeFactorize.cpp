//input:数 output:<素因数,乗数>のvector
vector<pair<long long, long long> > primeFactrize(long long n) {
		vector<pair<long long, long long> > res;
		for (long long p = 2; p * p <= n; ++p) {
				if (n % p != 0) continue;
				int num = 0;
				while (n % p == 0) { ++num; n /= p; }
				res.push_back(make_pair(p, num));
		}
		if (n != 1) res.push_back(make_pair(n, 1));
		return res;
}
