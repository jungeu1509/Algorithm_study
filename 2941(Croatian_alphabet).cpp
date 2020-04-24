#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	int size, ret;
	
	cin >> input;
	
	size = input.size();
	ret = size;
	
	for(int i = 0 ; i < size ; i++)	
	{
		switch(input[i])
		{
			case 'd':
				if(input[i+1] == 'z' && input[i+2] == '=')
				{
					input[i+1] = 'a';
					ret -= 2;
				}
				else if(input[i+1] == '-')
					ret--;
				break;
			case 'c':
				if(input[i+1] == '=' || input[i+1] == '-')
					ret--;
				break;
			case 'l':
				if(input[i+1] == 'j')
					ret--;
				break;
			case 'n':
				if(input[i+1] == 'j')
					ret--;
				break;
			case 's':
			case 'z':
				if(input[i+1] == '=')
					ret--;
				break;
		}
	}
	
	cout << ret;
	
	return 0;
}
