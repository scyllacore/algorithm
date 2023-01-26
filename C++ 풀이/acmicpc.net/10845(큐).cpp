#include <iostream>

using namespace std;

int front = 0, back = 0;
int queue[10001] = { 0 };


void push(int X)
{
	queue[back++] = X;
}

int pop()
{
	return back - front != 0 ? queue[front++] : -1;
}

int ckech_front()
{
	return back - front != 0 ? queue[front] : -1;

}

int ckech_back()
{
	return back - front != 0 ? queue[back - 1] : -1;

}

int empty()
{
	return back - front == 0 ? 1 : 0;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, X;
	string cmd;

	cin >> n;

	for (i = 0; i < n; i++) {

		cin >> cmd;

		if (cmd[0] == 'p') {
			if (cmd[1] == 'u') {
				cin >> X;
				push(X);
			}
			else {
				cout << pop() << '\n';
			}
		}
		else if (cmd[0] == 's') {
			cout << back - front << '\n';
		}
		else if (cmd[0] == 'e') {
			cout << empty() << '\n';
		}
		else if (cmd[0] == 'f') {
			cout << ckech_front() << '\n';
		}
		else if (cmd[0] == 'b') {
			cout << ckech_back() << '\n';

		}

	}

	return 0;

}