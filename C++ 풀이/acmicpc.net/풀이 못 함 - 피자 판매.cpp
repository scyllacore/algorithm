1.

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	cin >> size;

	int a, b;
	cin >> a >> b;

	vector<int> pizzaA(a), pizzaB(b);

	for (int i = 0; i < a; i++) {
		cin >> pizzaA[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> pizzaB[i];
	}

	unordered_set<int> aSet, bSet;
	vector<int> dpA(pizzaA), dpB(pizzaB);

	cout << '\n';

	dpA[0] = pizzaA[0];
	aSet.insert(pizzaA[0]);
	cout << pizzaA[0] << '\n';


	dpB[0] = pizzaB[0];
	bSet.insert(pizzaB[0]);

	for (int i = 1; i < a; i++) {
		dpA[i] += dpA[i - 1];
		aSet.insert(dpA[i]);
		cout << dpA[i] << ' ';

		for (int j = 0; j < i; j++) {
			aSet.insert(dpA[i] - dpA[j]);
			cout << dpA[i] - dpA[j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i < b; i++) {
		dpB[i] += dpB[i - 1];
		aSet.insert(dpB[i]);

		for (int j = 0; j < i; j++) {
			aSet.insert(dpB[i] - dpB[j]);
		}
	}

}

2.

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	cin >> size;

	int a, b;
	cin >> a >> b;

	vector<int> pizzaA(a), pizzaB(b);

	for (int i = 0; i < a; i++) {
		cin >> pizzaA[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> pizzaB[i];
	}

	unordered_set<int> aSet, bSet;
	unordered_map<int, int> aMap, bMap;

	vector<int> dpA(pizzaA), dpB(pizzaB);

	dpA[0] = pizzaA[0];
	aSet.insert(pizzaA[0]);
	aMap[pizzaA[0]]++;


	dpB[0] = pizzaB[0];
	bSet.insert(pizzaB[0]);
	bMap[pizzaB[0]]++;


	for (int i = 1; i < a; i++) {
		dpA[i] += dpA[i - 1];
		aSet.insert(dpA[i]);
		aMap[dpA[i]]++;
		cout << dpA[i] << ' ';

		for (int j = 0; j < i; j++) {
			aSet.insert(dpA[i] - dpA[j]);
			aSet.insert(dpA[i] - dpA[i - 1 - j]);
			aMap[dpA[i] - dpA[j]]++;
			aMap[dpA[i] - dpA[i - 1 - j]]++;
			cout << dpA[i] - dpA[j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i < b; i++) {
		dpB[i] += dpB[i - 1];
		bSet.insert(dpB[i]);
		bMap[dpB[i]]++;

		for (int j = 0; j < i; j++) {
			bSet.insert(dpB[i] - dpB[j]);
			bSet.insert(dpB[i] - dpB[i - 1 - j]);
			bMap[dpB[i] - dpB[j]]++;
			aMap[dpB[i] - dpB[i - 1 - j]]++;
		}
	}

	int ans = 0;

	for (auto val : aSet) {
		if (val == size) {
			ans += aMap[val];
		}
		cout << val << ' ' << aMap[val] << '\n';
	}

	for (auto val : bSet) {
		if (val == size) {
			ans += bMap[val];
		}
	}

	for (auto val : aSet) {
		if (bSet.find(size - val) != bSet.end()) {
			ans += aMap[val] * bMap[size - val];
		}
	}

	cout << ans;

	return 0;
}

//https://velog.io/@khc41/%EB%B0%B1%EC%A4%80-2632%EB%B2%88-%ED%94%BC%EC%9E%90%ED%8C%90%EB%A7%A4-C

//7
//8 1
//10 3 2
//12 5 4 2
//14 7 6 4 2
//
//6
//9 3
//17 11 8
