#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 10

int main()
{
    char S[MAXN], t;
    int K;
    string str, ans = "0";
    queue<string> q;

    scanf(" %s %d", S, &K);
    str = S;
    
    q.push(str);
    
    for(int i=0; i<K; i++)
    {
        set<string> s;
        int qSize = q.size();
        
        for(int j=0; j<qSize; j++)
        {
            str = q.front();
            q.pop();
            
            if(s.count(str)==1) continue;
            s.insert(str);
            
            for(int k=0; k<str.size()-1; k++)
            {
                for(int l=k+1; l<str.size(); l++)
                {
                    if(k==0 && str[l]=='0') continue;

                    t = str[k];
                    str[k] = str[l];
                    str[l] = t;
                    
                    q.push(str);

                    t = str[k];
                    str[k] = str[l];
                    str[l] = t;
                }
            }
        }
    }
    
    while(!q.empty())
    {
        ans = max(ans, q.front());
        q.pop();
    }
    
    if(ans[0]=='0') printf("-1");
    else printf("%s", ans.c_str());    

    return 0;
}