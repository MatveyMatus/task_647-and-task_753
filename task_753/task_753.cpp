#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string sub(int s, string sr) {
	string substr;
	int len_S = s;
	for (int i = 0; i <= len_S; ++i) {
		substr += sr[i];
	}
	return substr;
}

int main()
{
	string str;
	int coun = 0;
	bool bFlag = true;
	ifstream input("input.txt");
	ofstream output("output.txt");
	ofstream substr("substring.txt");
	getline(input, str);
	for (int i = 0; i < str.length(); ++i) {
		for (int j = 0; j < str.length(); ++j) {
			if (str[j] != str[i]){
				bFlag = false;
				break;
			}
		}
	}
	for (int i = 0; i < str.length(); ++i) {
		if (bFlag == false) {
			coun++;
			sub(i, str);
			if (i == str.length() - 1) {
				substr << str << endl;
				str.erase(0, 1);
				i = -1;
			}
		}
		else {
			sub(i, str);
			if (i == str.length() - 1) {
				substr << str << endl;
				str.erase(0, 1);
				coun++;
				i = -1;
			}
		}
	}
	output << coun;
	input.close();
	output.close();
	substr.close();
	cout << "Everything went well";
}