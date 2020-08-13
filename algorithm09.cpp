//task scheduling(1 machine)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int begin;
	int end;
};

bool cmp(Time f, Time s) {
	if (f.end == s.end)
		return f.begin < s.begin;
	else
		return f.end < s.end;
}

int main() {
	int N;
	cin >> N;
	vector<Time> t(N);
	
	for (int i = 0; i < N; i++) {
		cin >> t[i].begin >> t[i].end;
	}
	
	sort(t.begin(), t.end(), cmp);

	int cnt = 0;
	int n = 0;

	for (int i = 0; i < t.size(); i++) {
		if (n <= t[i].begin) {
			n = t[i].end;
			cnt++;
		}
	}
	
	cout << cnt << endl;
}