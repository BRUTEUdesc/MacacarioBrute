// usa miller_rabin.cpp!! olhar em matemática/primos
// usa pollar_rho.cpp!! olhar em matemática/fatoração

vector<long long> factorize(long long n) {
	if (n == 1) return {};
	if (miller_rabin(n)) return {n};
	long long x = pollard_rho(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
