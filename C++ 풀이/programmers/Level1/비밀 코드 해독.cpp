#include <string>
#include <vector>

using namespace std;

int n_;

void cal_combi(int depth,int start ,vector<vector<int>& combi_list,vector<int> combi){
	if(depth >= 5){
		combi_list.push_back(combi);
		return;
	}

	for(int i=start; i<=n_; i++){
		combi[depth] = i;
		cal_combi(depth+1, start+1, combi_list, combi);
	}
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {

	n_ = n;

	vector<int> combi(5,0);
	vector<vector<int> combi_list;

	int answer = 0;
	for(const vector<int>& com : combi_list){
		bool flag = true;

		int com_cnt[31] = {0,};

		for(int com_val : com){
			com_cnt[com_val]++;
		}		

		int q_cnt[31] = {0,};


		for(int i=0; i<q.size(); i++ ){
			for(int q_val : q[i]){
				q_cnt[q_val]++;
			}

			int equal_cnt = 0;

			for(int i=1; i<=n_; i++){
				if(com_cnt[i] && q_cnt[i]){
					equal_cnt++;
				}
			}

			if(equal_cnt != ans[i]){
				flag = false;
				break;
			}
		}


		if(flag == true){
			answer++;
		}
	}

	return answer;
}
