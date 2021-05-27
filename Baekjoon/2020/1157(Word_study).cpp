#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string input;
	int size;
	char ret;
	int max_val = 0;
	int count[26] = {0, };
	cin >> input;
	size = input.size();
	
	for(int i = 0; i < size ; i++)
	{
		count[(toupper(input[i])-'A')]++;
	}
	
	for(int i = 0; i < 26 ; i++)
	{
		if(max_val < count[i])
		{
			max_val = count[i];
			ret = i + 'A';
		}
		else if(max_val == count[i])
			ret = '?';
	}
	
	cout << ret;
	
	return 0;
}
