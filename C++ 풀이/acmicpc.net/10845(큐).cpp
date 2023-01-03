#include <iostream>

using namespace std;

int front = 0, rear = 0;
int queue[10001] = { 0 };


void push(int X)
{
	queue[front++] = X;
}

int pop()
{
	return front - rear != 0 ? queue[rear++] : -1;
}

int frontCkech()
{
	return front - rear != 0 ? queue[rear] : -1;

}

int backCkech()
{
	return front - rear != 0 ? queue[front-1] : -1;

}

int empty()
{
	return front - rear == 0 ? 1 : 0;
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
			cout << front - rear << '\n';
		}
		else if (cmd[0] == 'e') {
			cout << empty() << '\n';
		}
		else if (cmd[0] == 'f') {
			cout << frontCkech() << '\n';
		}
		else if (cmd[0] == 'b') {
			cout << backCkech() << '\n';

		}

	}

	return 0;

}