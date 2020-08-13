//set cover
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> setlist;

vector<int> inputNum() {
	string ch;
	vector<int> numList;

	getline(cin, ch);
	int leng = ch.length();
	string startCh = "";

	for (int i = 0; i <= leng; i++) {
		if (ch[i] == ' ' || ch[i] == '\n' || ch[i] == NULL) {
			if (startCh != "") {
				numList.push_back(stoi(startCh)); startCh = "";
			}
		}
		else {
			startCh += ch[i];
		}
	}
	return numList;
}

vector<int> deleteNum(vector<int> list, int listNum) {
	for (unsigned int i = 0; i < setlist[listNum].size(); i++) {
		vector<int>::iterator iter;
		iter = find(list.begin(), list.end(), setlist[listNum][i]);
		
		if (iter == list.end()) {
			continue;
		}
		list.erase(iter);
	}
	return list;
}

int longSet(vector<int> list, int N) {
	vector<int> count;
	
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (unsigned int j = 0; j < setlist[i].size(); j++) {
			if (find(list.begin(), list.end(), setlist[i][j]) != list.end())
				cnt++;
		}
		count.push_back(cnt);
	}

	int idx = 0;
	int maxNum = count[idx];
	
	for (int i = 1; i < N; i++) {
		if (maxNum < count[i]) {
			maxNum = count[i];
			idx = i;
		}
	}
	return idx;
}

int main() {
	int N;
	cin >> N;
	getchar();

	vector<int> list;

	for (int i = 0; i < N; i++)
		list.push_back(i + 1);

	for (int i = 0; i < N; i++) {
		vector<int> tempList = inputNum();
		if (tempList.empty()) {
			continue;
		}
		setlist.push_back(tempList);
	}
	vector<int> fin;

	while (list.size() > 0) {
		int listNum = longSet(list, N);
		list = deleteNum(list, listNum);
		fin.push_back(listNum);
		setlist[listNum].clear();
	}
	
	sort(fin.begin(), fin.end());

	for (unsigned int i = 0; i < fin.size(); i++) {
		cout << fin[i] + 1 << " ";
	}
	cout << endl;
}
