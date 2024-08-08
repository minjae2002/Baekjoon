#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> Vec(100001);
vector<int> Depth_Vec(100001, 0);
vector<vector<int>> Parents(100001, vector<int>(17, 0)); //3의 0제곱~16제곱(65536) 총 17칸
 
void Find_Depth(int _Num)
{
    for (auto i : Vec[_Num])
    {
        if (Depth_Vec[i]==0)
        {
            Depth_Vec[i] = Depth_Vec[_Num]+1;
            Parents[i][0] = _Num;
 
            for (int j = 0; j < 16; j++)
            {
                // 2^(j+1) = 2^j + 2^j = Parents[i][j]에 j만큼 올린거 = 네칸업 + 네칸 업 된거에서 네칸 더 = 8칸 = 2^2 + 2^2 = 2^3.
                Parents[i][j + 1] = Parents[Parents[i][j]][j];
 
                if (Parents[i][j + 1] == 0) //한도 넘어감 or 없음
                    break;
            }
            Find_Depth(i);
        }
    }
}
 
int Find_LCA(int _Num1, int _Num2)
{
    // a 와 b 를 같은 높이로 맞춰주기
    if (Depth_Vec[_Num1] < Depth_Vec[_Num2]) 
        swap(_Num1, _Num2);
    int diff = Depth_Vec[_Num1] - Depth_Vec[_Num2], j = 0;
    while (diff) 
    {
        if (diff % 2) 
            _Num1 = Parents[_Num1][j];
        j++;
        diff /= 2;
    }
 
    //올라감. 최종적으 ab는 공통 부모의 바로 아레 좌우에 위치함.
    if (_Num1 != _Num2) 
    {
        for (int j = 16; j >= 0; j--) 
        {
            if (Parents[_Num1][j] != Parents[_Num2][j]) 
            {
                _Num1 = Parents[_Num1][j];
                _Num2 = Parents[_Num2][j];
            }
        }
        _Num1 = Parents[_Num1][0];
    }
 
    return _Num1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Parents[1][0] = 1;
    Depth_Vec[0] = 0;
    Depth_Vec[1] = 1;
 
    int Num, Find_Num;
    cin >> Num;
    for (int i = 0; i < Num - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        Vec[a].emplace_back(b);
        Vec[b].emplace_back(a);
    }
    Find_Depth(1);
 
    cin >> Find_Num;
    for (int i = 0; i < Find_Num; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << Find_LCA(a, b) << '\n';
    }
}
