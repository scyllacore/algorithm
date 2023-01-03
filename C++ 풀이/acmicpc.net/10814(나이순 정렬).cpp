#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct people {
	int age;
	string name;
	int order;
}People;


bool cmp(const People& p1, const People& p2)
{
	if (p1.age == p2.age)
	{
		return p1.order < p2.order;
	}
	else
	{
		return p1.age < p2.age;
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, cnt = 1;
	cin >> n;

	vector<People> member(n);


	for (i = 0; i < n; i++)
	{
		cin >> member[i].age >> member[i].name;
		member[i].order = cnt++;
	}

	sort(member.begin(), member.end(), cmp);


	for (i = 0; i < n; i++)
	{
		cout << member[i].age << ' ' << member[i].name << '\n';
	}




}