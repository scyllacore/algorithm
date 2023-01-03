#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;


    if (n == 4 || n == 7) {
        cout << -1;
    }
    else if (n % 5 == 0) {
        cout << n / 5;
    }
    else if (n % 5 == 1 || n % 5 == 3) {
        cout << (n / 5) + 1;
    }
    else if (n % 5 == 2 || n % 5 == 4) {
        cout <<  (n / 5) + 2;
    }

    return 0;

}


// greedy와 dp 방식은 나중에 개념 다시익히고 이해할 것
// https://st-lab.tistory.com/72
