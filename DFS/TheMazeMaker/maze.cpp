// TODO
//
// 1) need to accelerate solving rates.
// 2) need to modify multiple path cases (cause now I just found 
//    a case that has multiple paths between start and end points of the maze,
//    but, in this problem, I need to find the case that all the pairs of coordinations has multiple paths!)

#include <iostream>
#include <vector>
#include <map>

#define LEFT	1
#define RIGHT	2
#define UP		3
#define DOWN	4

using namespace std;

int h, w, sp;
vector<pair<int, int> > outedge;
vector<vector<char> > mazes;
vector<vector<int> > is_visited;
vector<vector<int> > is_discovered;
vector<vector<pair<int, int> > > solved_v;
map<int, pair<int, int> > move_v;

string hexTobin(char c)
{
	switch(c)
	{
		case 'A':
			return "1010";
		case 'B':
			return "1011";
		case 'C':
			return "1100";
		case 'D':
			return "1101";
		case 'E':
			return "1110";
		case 'F':
			return "1111";
		case '0':
			return "0000";
		case '1':
			return "0001";
		case '2':
			return "0010";
		case '3':
			return "0011";
		case '4':
			return "0100";
		case '5':
			return "0101";
		case '6':
			return "0110";
		case '7':
			return "0111";
		case '8': 
			return "1000";
		case '9':
			return "1001";
		default:
			return "fail";
	}
}

int calc_out(int x, int y, int val)
{
	string bin = hexTobin(val);
	if (bin == "fail") return -1;
	if (x == h-1 && y == w-1) { // n, n
		if (bin[1] == '0' || bin[2] == '0') return 1;
	}  else if (0 < x && x < h-1 && y == w-1) { // n-x, n
		if (bin[1] == '0') return 1;
	} else if (x == h-1 && 0 < y && y < w-1) { // n, n-x
		if (bin[2] == '0') return 1;
	} else if (x == 0 && y == 0) { // 0, 0
		// 0 x x 0
		if (bin[0] == '0' || bin[3] == '0') return 1;
	} else if (x == 0 && y == w-1) { // 0, n
		if (bin[0] == '0' || bin[1] == '0') return 1;
	} else if (x == h-1 && y == 0) { // n, 0
		if (bin[2] == '0' || bin[3] == '0') return 1;
	} else if (0 < x && x < h-1 && y == 0) { // n-x, 0
		if (bin[3] == '0') return 1;
	} else if (x == 0 && 0 < y && y < w-1) { // 0, n-y
		if (bin[0] == '0') return 1;
	}	

	return 0;
}

bool is_dest(int x, int y) {
	if (x == outedge[1].first && y == outedge[1].second) return true;
	else return false;
}

bool is_unique(vector<pair<int, int> > traking)
{
	for (int i = 0; i < sp; i++)
	{
		if (traking == solved_v[i]) return false;
	}

	return true;
}

vector<pair<int, int> > fill_poss_mov(int _val, vector<pair<int, int> > _poss_mov)
{
	string bin = hexTobin(_val);
	if (bin[0] == '0') _poss_mov.push_back(move_v[UP]);
	if (bin[1] == '0') _poss_mov.push_back(move_v[RIGHT]);
	if (bin[2] == '0') _poss_mov.push_back(move_v[DOWN]);
	if (bin[3] == '0') _poss_mov.push_back(move_v[LEFT]);

	return _poss_mov;
}

void try_walking(int x, int y, int t, vector<pair<int,int> > traking)
{
	vector<pair<int, int> > poss_mov;
	//for (int i = 0; i < t; i++)
	//	cout << " ";
    //cout << x << ", " << y << endl;
	if (is_dest(x, y) && is_unique(traking)) { 
		solved_v.push_back(traking);

//		for (int i = 0; i < solved_v.size(); i++) {
//			for (int j = 0; j < solved_v[i].size(); j++)
//			{
//				cout << solved_v[i][j].first << "," << solved_v[i][j].second << " ";
//			}
			//cout << endl;
//		}
		sp++;
	}

	int val = mazes[x][y];
	poss_mov = fill_poss_mov(val, poss_mov);
	
	// need to modify as while+queue, not recursive..
	for (int i = 0; i < poss_mov.size(); i++)
	{
		int m_x = poss_mov[i].first+x;
		int m_y = poss_mov[i].second+y;
//		for (int j = 0; j < t; j++)
//			cout << " ";
//		cout << "moved to " << m_x << ", " << m_y << endl;
		if (m_x < 0 || m_x >= h ||
				m_y < 0 || m_y >= w) continue;
		if (is_visited[m_x][m_y] == 0) {
			is_visited[m_x][m_y] = 1;
			is_discovered[m_x][m_y] = 1;
			traking.push_back(make_pair(m_x, m_y));
			try_walking(m_x, m_y, t+1, traking);
			traking.pop_back();
			is_visited[m_x][m_y] = 0;
		}
	}
//	for (int j = 0; j < t; j++)
//			cout << " ";

//	cout << x << ", " << y << " finished" << endl;

	return ;
}


int main(void)
{

	move_v.insert(make_pair(RIGHT, make_pair(0, 1)));
	move_v.insert(make_pair(LEFT, make_pair(0, -1)));
	move_v.insert(make_pair(UP, make_pair(-1, 0)));
	move_v.insert(make_pair(DOWN, make_pair(1, 0)));

	while (true) {
		//cout << "================ CASE ==============" << endl;
		cin >> h >> w;
		if (h == 0 && w == 0)	return 0;
//		mazes = vector<vector <char> >(h, vector<char>(w, 0));
//		is_visited = vector<vector <int> >(h, vector<int>(w, 0));
//		is_discovered = vector<vector <int> >(h, vector<int>(w, 0));
//		solved_v = vector<vector <pair<int, int> > >(w*h, vector<pair<int, int> >());

		mazes = vector<vector <char> >(h, vector<char>(w, 0));
		is_visited = vector<vector <int> >(h, vector<int>(w, 0));
		is_discovered = vector<vector <int> >(h, vector<int>(w, 0));
		solved_v = vector<vector <pair<int, int> > >(w*h, vector<pair<int, int> >());

		outedge.resize(0);
		sp = 0;

		int is_reachable = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				std::cin >> std::hex >> mazes[i][j]; 
				if (calc_out(i, j, mazes[i][j])) {
					outedge.push_back(make_pair(i, j));
				}
			}
		}

//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++)
//				cout << mazes[i][j] << " ";
//			cout << endl;
//		}
		
		
		is_visited[outedge[0].first][outedge[0].second] = 1;
		is_discovered[outedge[0].first][outedge[0].second] = 1;
		vector<pair<int, int> > traking;
		traking.push_back(outedge[0]);
		try_walking(outedge[0].first, outedge[0].second, 0, traking);

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (is_discovered[i][j] == 0) { 
					is_reachable = 0;
//					cout << i << "," << j << endl;
				}
		//cout << solved_v.size() << endl;
		if (sp == 0) cout << "NO_SOLUTION" << endl;
		else if (is_reachable == 0) cout << "UNREACHABLE CELL" << endl;
		else if (sp > 1) cout << "MULTIPLE PATHS" << endl;
		else if (sp == 1) cout << "MAZE OK" << endl;

		//cout << "================ FINISH ==============" << endl;
	}
	return 0;
}

