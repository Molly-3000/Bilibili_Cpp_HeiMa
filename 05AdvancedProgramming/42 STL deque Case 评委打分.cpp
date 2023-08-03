#include"head.h"
/*
* STL Case for deque
* 
* CD：5名选手ABCDE，由10个评委，对其分别打分，
*		每个选手得分去掉一个最高分，去掉一个最低分，取平均分
* 
*/
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

class Player {
public:
	Player(string name) :m_name(name), m_score(0) {}
	Player(string name, int score) :m_name(name), m_score(score) {}
	string m_name;
	double m_score;
	deque<int> socres;
};

static void init_players(vector<Player>& vp) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "Player ";
		name += nameSeed[i];
		vp.push_back(Player(name));
	}
}

static void judge_players(vector<Player>& vp, int n_judge) {
	for (int i = 0; i < vp.size(); i++) {
		// judges
		cout << "Please input the scores of " << vp[i].m_name << endl;
		int score;
		for (int j = 0; j < n_judge; j++) {
			//cout << "judge" << j << ": ";
			//cin >> score;
			//vp[i].socres.push_back(score);

			// 随机打分
			score = rand() % 41 + 60; // 60~100
			vp[i].socres.push_back(score);
		}
		system("cls");
	}
}

static void print_deque(const deque<int>& dq) {
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

static void print_players(vector<Player>& vp) {
	for (int i = 0; i < vp.size(); i++) {
		cout << vp[i].m_name << endl;
		cout << "socres: ";
		print_deque(vp[i].socres);
		cout << "final score: " << vp[i].m_score << endl;
	}
}

static void test() {

	vector<Player> vp;

	int n_judge = 10;

	init_players(vp);

	judge_players(vp,n_judge);

	for (int i = 0; i < vp.size(); i++) {
		// sort
		sort(vp[i].socres.begin(), vp[i].socres.end());

		// mean
		int sum = 0;
		deque<int>::iterator start = vp[i].socres.begin() + 1;
		deque<int>::iterator end = vp[i].socres.end() - 1;
		for (deque<int>::iterator it = start; it != end;it++) {
			sum += *it;
		}
		vp[i].m_score = sum / (vp[i].socres.size()-2);

	}

	print_players(vp);

}

int main42() {
	srand((unsigned int)time(NULL));
	test();
	return 0;
}