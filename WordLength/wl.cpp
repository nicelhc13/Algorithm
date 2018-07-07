#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
#define C_MAX 81
#define GET_MODE 1
#define WAIT_MODE 2

char input[C_MAX];
int mode = GET_MODE;

int main(void)
{
	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		getchar();
		string str;
		int cnt = 0;
		int wrd_num = 0;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		cout << str << endl;
		if (mode == GET_MODE && 'a' <= str[0] && str[0] <= 'z') { 
			wrd_num++;
			cout << "word is increased " << str[0] << ", " << i << endl;
		} else {
			mode = WAIT_MODE;
		}
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ' || str[j] == '-') {
					if (mode == GET_MODE) {
						mode = WAIT_MODE;
					}
			}
			if (str[j] >= 'a' && str[j] <= 'z') {
					cnt++;
					if (mode == WAIT_MODE) {
						mode = GET_MODE;
						if (j != 0) {
							wrd_num++;
							cout << "word is increased '" << str[j] << "'" <<  endl;
						}
					}
			}
		}

		int ss = str.size();
		if (str[ss-1] == '-' && str[ss-2] >= 'a' && str[ss-2] <= 'z') {
			mode = WAIT_MODE;
			//wrd_num--;
			cout << "word is decreased" << endl;
		}
		else mode = GET_MODE;
	}

		/*
		if (is_concat && !('a'<=str[0] && str[0]<='b')) wrd_num--;
		if (!is_concat && 'a' <= str[0] && str[0] <= 'b') wrd_num++;
		for (int j = 0; j < str.size(); j++)
		{
			if ((str[j] == ' ' || str[j] == '-') &&
					(before != ' ' && before != '-')) {
				wrd_num++;
			}
			if (str[j] != '-' && str[j] != ' ') cnt++;
			before = str[j]; 
		}
	
		if (str[str.size()-1]=='-' && 
			str[str.size()-2] >= 'a'&& str[str.size()-2] <= 'z') 
		{ 
			is_concat = true;
			wrd_num--;
		}
		else {
			is_concat = false;
		}
	}
	*/
	cout << cnt << " , " << wrd_num << endl;
	cout << fixed;
	cout.precision(3);
	if (wrd_num>0)
		cout << ((double)cnt/wrd_num) << endl;
	else cout << "0.000" << endl;
}
return 0;
}
