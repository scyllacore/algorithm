#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long getFac(int n) {
    long long sum = 1;

    for (int i = n; i >= 2; i--) {
        sum *= i;
    }

    return sum;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    k -= 1;

    for (; k != 0;) { // n!=0도 가능하다
        n -= 1; // (n-1)!
        long long boundary = getFac(n);
        int idx = k / boundary;
        k = k % boundary; // 선택한 그룹의 나머지 숫자들

        answer.push_back(permutation[idx]);
        permutation.erase(permutation.begin() + idx);
    }

    for (auto pVal : permutation) {
        answer.push_back(pVal);
    }

    return answer;
}

//https://kangworld.tistory.com/258

/*
vector<int> solution(int n, long long k) {
    vector<int> answer(n);

    for(int i=0; i<answer.size(); i++){
        answer[i] = i+1;
    }

    int order=1;

    do{
        if(order==k){return answer;}
        order++;
    }while(next_permutation(answer.begin(),answer.end()));
}
*/


/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool getNextPermutation(vector<int>& arr){
    int size = arr.size();

    int i,j;
    i = j = size-1;

    for(;i >=1 && arr[i-1] >= arr[i]; i--){}
    if(i<1){return 0;}

    for(;arr[i-1] >= arr[j]; j--){}

    swap(arr[i-1], arr[j]);

    j = size-1;

    for(;i<j;){
        swap(arr[i],arr[j]);
        i++,j--;
    }

    return 1;
}

vector<int> solution(int n, long long k) {
    vector<int> answer(n);

    for(int i=0; i<n; i++){
        answer[i] = i+1;
    }

    int order = 1;

    for(;;){
        if(order == k){
            break;
        }

        order++;

        if(!getNextPermutation(answer)){
            break;
        }
    }

    return answer;
}
*/