#include <iostream>
#include <cstdbool>

using namespace std;

int deque[20001];
int back = 10000, front = 10000;

void push_front(int X)
{
	deque[front++] = X;
}

void push_back(int X)
{
	deque[--back] = X;
}

int pop_front() {
	return front - back != 0 ? deque[--front] : -1;
}

int pop_back() {
	return front - back != 0 ? deque[back++] : -1;
}

bool empty()
{
	return front - back == 0 ? 1 : 0;
}

int print_front() {
	return front - back != 0 ? deque[front - 1] : -1;
}

int print_back() {
	return front - back != 0 ? deque[back] : -1;
}




int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, X, i;
	string cmd;


	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> cmd;

		if (cmd[1] == 'u') {
			cin >> X;
			if (cmd[5] == 'f') {
				push_front(X);
			}
			else {
				push_back(X);

			}

		}
		else if (cmd[1] == 'o') {
			if (cmd[4] == 'f') {
				cout << pop_front() << '\n';
			}
			else {
				cout << pop_back() << '\n';
			}
		}
		else if (cmd[1] == 'i') {
			cout << front - back << '\n';
		}
		else if (cmd[1] == 'm') {
			cout << empty() << '\n';
		}
		else if (cmd[1] == 'r') {
			cout << print_front() << '\n';
		}
		else if (cmd[1] == 'a') {
			cout << print_back() << '\n';
		}
	}

	return 0;

}