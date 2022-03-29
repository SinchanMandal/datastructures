template <typename T>
struct bit
{
	vector<T> values;
	int N;
	void init(int n)
	{
		N = n;
		values.resize(N + 1);
 
		for (int i = 1; i <= N; ++i)
		{
			values[i] = 0;
		}
	}
	void upd(int x, T y)
	{
		while (x <= N)
		{
			values[x] += y;
			x += (x & (-x));
		}
	}
	void range_upd(int l, int r, T val)
	{
		this->upd(l, val);
		this->upd(r + 1, -val);
	}
	T sum(int x)
	{
		T ans = 0;
		while (x > 0)
		{
			ans += values[x];
			x -= (x & (-x));
		}
		return ans;
	}
};
