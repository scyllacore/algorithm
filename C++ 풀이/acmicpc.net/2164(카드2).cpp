#include <iostream>
#include <deque>

using namespace std;

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n,i;
	cin >> n;
	deque<int> card;
	
	for (i = n; i >= 1; i--) {
		card.push_back(i);
	}

	while (card.size() > 1) {
		card.pop_back();
		card.push_front(card.back());
		card.pop_back();
	}

	cout << card.back();
	return 0;


}

