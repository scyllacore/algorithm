#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
	char name[20];
	int score;

	bool operator<(const Student& s2)const //  operator> 는 안됨
	{
		if (score != s2.score) {
			return score > s2.score;
		}
		else {
			return strcmp(name, s2.name)<0 ;
		}
	}

};


int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int n, i;
	cin >> n;

	Student* students = new Student[n];

	for (i = 0; i < n; i++)
	{
		cin >> students[i].name >> students[i].score;
	}

	

	sort(students, students + n);


	for (i = 0; i < n; i++)
	{
		cout << students[i].name << ' ' << students[i].score << '\n';
	}



}