#include <string>
using namespace std;

int main()
{
	int T, H, W, N;
	int Y, X;
	
	cin >> T;
	
	for(int i=0; i<T; i++)
	{
		cin >> H >> W >> N;
		
		X = ((N-1)/H)+1;
		Y = N%H;
		if(Y==0)
			Y = H;
      
		cout << Y*100 + X << "\n";
	}
	return 0;
}
