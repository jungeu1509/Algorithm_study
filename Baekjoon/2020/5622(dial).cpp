#include <iostream>
#include <string>
using namespace std;

int main()
{
	char string[15];
	int ret=0, i=0;

	cin >> string;

	for(i=0;i<15;i++)
	{
		if(string[i] == 'A' || string[i] == 'B' || string[i] == 'C')
			ret += 3;
		else if(string[i] == 'D' || string[i] == 'E' || string[i] == 'F')
			ret += 4;
		else if(string[i] == 'G' || string[i] == 'H' || string[i] == 'I')
			ret += 5;
		else if(string[i] == 'J' || string[i] == 'K' || string[i] == 'L')
			ret += 6;
		else if(string[i] == 'M' || string[i] == 'N' || string[i] == 'O')
			ret += 7;
		else if(string[i] == 'P' || string[i] == 'Q' || string[i] == 'R' || string[i] == 'S')
			ret += 8;
		else if(string[i] == 'T' || string[i] == 'U' || string[i] == 'V')
			ret += 9;
		else if(string[i] == 'W' || string[i] == 'X' || string[i] == 'Y' || string[i] == 'Z')
			ret += 10;
		else
		{
			break;
		}
	}

	cout << ret;
	return 0;
}
