#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class T1
{
public:
    class _MyIn
    {
    public:
        using _I=int32_t;
        static constexpr bool sign=1;
        #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,BZ,stdin),p1==p2)?EOF:*p1++)
        #ifdef getchar
        static constexpr int BZ=1<<20;
        char buf[BZ],*p1=buf,*p2=buf;
        #endif
        _I operator()()
        {
            _I n=0;
            bool b=0;
            char c=getchar();
            while(c<48||c>57)((sign&&c=='-')?b=1:0),c=getchar();
            while(c>=48&&c<=57)
                n=(n<<1)+(n<<3)+(c^48),c=getchar();
            return b?-n:n;
        }
        _MyIn& operator>>(_I &n){return n=operator()(),(*this);}
        #undef getchar
    }read;
    int n,x,y=0;
    T1()
    {
        read>>n;
        while(n--)read>>x,y+=x;
    }
    ~T1()
    {
        cout<<y;
    }
}obj;
int main()
{
    return 0;
}
