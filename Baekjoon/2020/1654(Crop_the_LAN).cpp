#include <iostream>
using namespace std;

#define LAN_max_len 10000

int LAN[LAN_max_len];
int K, N;

int find_lan_length(int cut_len, int min_len, int max_len)
{
    int ret, count = N;
    
    if((max_len - min_len) <= 1)
    {
        for(int i = 0; i < K; i++)
            count -= (LAN[i] / max_len);
        if(count <= 0)
            return max_len;
        return min_len;
    }
    
    for(int i = 0; i < K; i++)
        count -= (LAN[i] / cut_len);
    
    if(count > 0)
        ret = find_lan_length((cut_len+(long long)min_len)/2, min_len, cut_len - 1);    
    else
        ret = find_lan_length((cut_len+(long long)max_len)/2, cut_len, max_len);
    
    return ret;
}

int main()
{
    int max_len = 0;
    cin >> K >> N;
    for(int i = 0; i < K; i++)
    {
        cin >> LAN[i];
        if(max_len < LAN[i])
            max_len = LAN[i];
    }

    cout << find_lan_length(max_len/2, 0, max_len) << '\n';
    return 0;
}
