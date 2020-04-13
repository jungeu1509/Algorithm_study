#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int space=0, len;
	string str = "";
	getline(cin, str);
	len = str.size();

	for(int i = 0; i<len ; i++)
	{
		if(str[i] == ' ')
			space++;
	}

	if(str[0] == ' ')
		space--;
	if(str[len-1] == ' ')
		space--;

	if(len == space)
	{
		cout << 0;
		return 0;
	}
		
	cout << (space+1);
	return 0;
}
