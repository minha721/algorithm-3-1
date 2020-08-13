//MST

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int vertexNum, edgeNum;
int visit[10001];
int sumOfWeight;

vector<pair<int, int>> graph[10001];

void input() {
	cin >> vertexNum >> edgeNum;

	for (int i = 0; i < edgeNum; i++) {
		int from, to, val;
		cin >> from >> to >> val;

		graph[from].push_back(make_pair(to, val));
		graph[to].push_back(make_pair(from, val));
	}
}

void makeMST(int startV) {
	visit[startV] = 1;
	priority_queue <
		pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>
	> pq;

	for (int i = 0; i < graph[startV].size(); i++) {
		int nextV = graph[startV][i].first;
		int nextCost = graph[startV][i].second;

		pq.push(make_pair(nextCost, nextV));
	}

	while (!pq.empty()) {
		int curr = pq.top().second;
		int currCost = pq.top().first;

		pq.pop();

		if (visit[curr] == 1) {
			continue;
		}

		visit[curr] = 1;

		sumOfWeight += currCost;

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int nextCost = graph[curr][i].second;

			pq.push(make_pair(nextCost, next));
		}
	}
	cout << sumOfWeight << "\n";
}

int main() {
	input();
	makeMST(1);

	return 0;
}