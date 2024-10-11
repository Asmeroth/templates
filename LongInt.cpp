/*************************
        O.o
*************************/
#include<iostream>
#include<cstdio>
#include<bitset>
//using namespace std;
namespace LongInt
{
    template<size_t sz>
    class ULong_Int
    {
        //private:
        public:
        std::bitset<sz> cs;
        public:
        //friend ULong_Int<sz> operator= (Ulong_Int<sz>& num,char[] s);
        operator bool()
        {
            return (cs.any());
        }
        operator unsigned int()
        {
            /*std::bitset<sz> tmp=(unsigned int)-1;
            return (cs&tmp).to_ulong();*/
            std::bitset<32> num;
            for(int i=0;i<32;++i)num[i]=cs[i];
            return num.to_ulong();
        }
        operator unsigned long long()
        {
            /*std::bitset<sz> tmp=(unsigned long long)-1;
            return (cs&tmp).to_ullong();*/
            std::bitset<64> num;
            for(int i=0;i<64;++i)num[i]=cs[i];
            return num.to_ulong();
        }
        ULong_Int(){cs=0;}
        ULong_Int(unsigned int n){cs=n;}
        ULong_Int(unsigned long long n){cs=n;}
        ULong_Int(int n){(*this)=((n>=0)?(ULong_Int)((unsigned int)(n)):-(ULong_Int)((unsigned int)(-n)));}
        ULong_Int(long long n){cs=((n>=0)?n:-(ULong_Int)((unsigned long long)(-n)));}
        ULong_Int(std::bitset<sz> n){cs=n;}
        /*ULong_Int<sz> operator= (char* s)
        {
            char c=s[0];
            unsigned int i=0;
            bool b=0;
            (*this)=0;
            while(c<'0'||c>'9')
            {
                (c=='-')?b=1:b;
                c=s[++i];
            }
            while(c>='0'&&c<='9')
            {
                (*this)=((*this)<<1)+((*this)<<3)+(ULong_Int<sz>)(c^48);
                c=s[++i];
            }
            return (*this)=(b?(~(*this)+(ULong_Int<sz>)1):(*this));
        }*/
        bool operator[](size_t n)
        {
            return cs[n];
        }
        template<size_t> friend ULong_Int<sz> operator& (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator| (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator^ (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator+ (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator- (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator* (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator/ (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator% (ULong_Int <sz>,ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator- (ULong_Int <sz>);
        template<size_t> friend ULong_Int<sz> operator~ (ULong_Int <sz>);
    };
    template<size_t sz>
    ULong_Int<sz> operator& (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return a.cs&b.cs;
    }
    template<size_t sz>
    ULong_Int<sz> operator| (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return a.cs|b.cs;
    }
    template<size_t sz>
    ULong_Int<sz> operator^ (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return a.cs^b.cs;
    }
    template<size_t sz>
    ULong_Int<sz> operator~ (ULong_Int <sz> a)
    {
        return ~a.cs;
    }
    template<size_t sz>
    ULong_Int<sz> operator<< (ULong_Int <sz> a,size_t n)
    {
        a.cs<<=n;
        return a;
    }
    template<size_t sz>
    ULong_Int<sz> operator>> (ULong_Int <sz> a,size_t n)
    {
        a.cs>>=n;
        return a;
    }
    template<size_t sz>
    ULong_Int<sz> operator+ (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return (b?(a^b)+((a&b)<<(size_t)1):a);
    }
    template<size_t sz>
    ULong_Int<sz> operator- (ULong_Int <sz> a)
    {
        return (~a)+(ULong_Int<sz>)1;
    }
    template<size_t sz>
    ULong_Int<sz> operator- (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return a+(-b);
    }
    template<size_t sz>
    ULong_Int<sz>& operator+= (ULong_Int <sz> &a,ULong_Int <sz> b)
    {
        a=a+b;
        return a;
    }
    template<size_t sz>
    ULong_Int<sz>& operator-= (ULong_Int <sz> &a,ULong_Int <sz> b)
    {
        a=a-b;
        return a;
    }
    template<size_t sz>
    ULong_Int<sz>& operator<<= (ULong_Int <sz> &a,size_t n)
    {
        a=a<<n;
        return a;
    }
    template<size_t sz>
    ULong_Int<sz>& operator>>= (ULong_Int <sz> &a,size_t n)
    {
        a=a>>n;
        return a;
    }
    template<size_t sz>
    bool operator> (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        for(size_t i=sz-1;(i>=0)&&(i<=sz);--i)
        {
            if (a.cs[i]>b.cs[i])
            {
                return 1;
            }else if (a.cs[i]<b.cs[i])
            {
                return 0;
            }
        }
        return 0;
    }
    template<size_t sz>
    bool operator< (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return (b>a);
    }
    template<size_t sz>
    bool operator>= (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return !(a<b);
    }
    template<size_t sz>
    bool operator<= (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return !(a>b);
    }
    template<size_t sz>
    bool operator== (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return (a.cs==b.cs);
    }
    template<size_t sz>
    bool operator!= (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return !(a==b);
    }
    template<size_t sz>
    ULong_Int<sz> operator* (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        ULong_Int<sz> ans=0;
        size_t i=0;
        while (b)
        {
        /*std::cout<<b.cs.to_string()<<'\n';
            std::cout<<'d'<<b[i]<<"i="<<i<<" b[i]="<<b[i]<<'\n';*/
            b[0]?ans+=(a<<i):b;
            (b>>=1),++i;
        }
        return ans;
    }
    template<size_t sz>
    ULong_Int<sz> operator/ (ULong_Int <sz> a,ULong_Int <sz> b)
    {

        if(b.cs.none())return ~b;
        size_t i=sz-1;
        ULong_Int<sz> Quo=0;
        for(;(i>=0)&&(i<=sz);--i)
        {
            if(b[i]==1)break;
        }
        //std::cout<<"i="<<i<<'\n';
        i=sz-1-i;
        //b<<=i;
        while(a>=b)
        {
            //std::cout<<"i="<<i<<'\n';
            if(a>=(b<<i))Quo.cs[i]=1,a-=(b<<i);
            --i;
        }
        return Quo;
    }
    template<size_t sz>
    ULong_Int<sz> operator% (ULong_Int <sz> a,ULong_Int <sz> b)
    {

        if(b.cs.none())return ~b;
        size_t i=sz-1;
        ULong_Int<sz> Quo=0;
        for(;(i>=0)&&(i<=sz);--i)
        {
            if(b[i]==1)break;
        }
        //std::cout<<"i="<<i<<'\n';
        i=sz-1-i;
        //b<<=i;
        while(a>=b)
        {
            //std::cout<<"i="<<i<<'\n';
            if(a>=(b<<i))Quo.cs[i]=1,a-=(b<<i);
            --i;
        }
        return a;
    }
    template<size_t sz>
    std::ostream& operator<< (std::ostream& out,ULong_Int<sz> num)
    {
        if (num>(ULong_Int<sz>)9)
        {
            out<<num/(ULong_Int<sz>)10;
        }
        out<<(unsigned)((num%(ULong_Int<sz>)10));
        return out;
    }/*
    template<size_t sz>
    std::ostream& operator<< (std::ostream& out,ULong_Int<sz> num)
    {
        if (num>(ULong_Int<sz>)999999999)
        {
            out<<num/(ULong_Int<sz>)1000000000;
        }
        out<<(unsigned)((num%(ULong_Int<sz>)1000000000));
        return out;
    }*/
    template<size_t sz>
    std::istream& operator>> (std::istream& in,ULong_Int<sz> &num)
    {
        num=0;
        char c=in.get();
        while(c<'0'||c>'9')c=in.get();
        while(c>='0'&&c<='9')
        {
            num=(num<<1)+(num<<3)+(ULong_Int<sz>)(c^48);
            c=in.get();
            //putchar('p');
        }
        return in;
    }
    /*template<size_t sz>
    ULong_Int<sz>& operator= (Ulong_Int<sz>& num,char[] s)
    {
        char c=s[0];
        unsigned int i=0;
        bool b=0;
        num=0;
        while(c<'0'||c>'9')
        {
            (c=='-')?b=1:b;
            c=s[++i];
        }
        while(c>='0'&&c<='9')
        {
            num=(num<<1)+(num<<3)+(c^48);
            c=s[++i];
        }
        return num=(b?(~num+1):num);
    }*/
    template<size_t sz>
    class Long_Int
    {
        ULong_Int<sz> num;

    };
} // namespace LongInt
/**/
using namespace std;
/* */
int main()
{
    /*cout<<1/2<<endl;
    LongInt::ULong_Int<128> m,n,q,w,e,r,t;
    unsigned  b,c,d,p,o;
    while(1)
    {
        cin>>b>>c;
        m=b,n=c;
        q=m+n,w=m-n,e=m*n,r=m/n,t=m%n;
        b=q,c=w,d=e,p=r,o=t;
        //cout<<b<<' '<<c<<' '<<d<<' '<<p<<' '<<o<<endl;
        cout<<q<<' '<<w<<' '<<e<<' '<<r<<' '<<t<<endl;
    }*/
    LongInt::ULong_Int<1024> a,b,c;
   //while(1)
   {
        cin>>a>>b;
        //cout<<a+b<<endl<<a-b<<endl<<a*b<<endl<<a/b<<endl<<a%b<<endl;
        c=a+b;
        //c=a+b^a-b^a*b^a/b^a%b;
        putchar('f');
        cout<<c<<endl;
   }
    return 0;
}
