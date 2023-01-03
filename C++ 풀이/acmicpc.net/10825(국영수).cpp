#include <iostream>
#include <algorithm>

using namespace std;


struct student{
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(const student& s1, const student& s2) {
	if (s1.korean != s2.korean) {
		return s1.korean > s2.korean;
	}
	else if (s1.english != s2.english) {
		return s1.english < s2.english;
	}
	else if(s1.math != s2.math) {
		return s1.math > s2.math;
	}
	else {
		return s1.name.compare(s2.name) < 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	student* stu = new student[n];

	int i;
	for (i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].korean >> stu[i].english >> stu[i].math;
	}

	sort(stu, stu + n, cmp);

	for (i = 0; i < n; i++) {
		cout << stu[i].name << '\n';
	}

	return 0;
}