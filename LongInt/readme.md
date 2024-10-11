# 关于无符号整形二进制加减乘除的运算技巧

运算的本质就是列竖式

## 加法

```cpp
ULong_Int<sz> operator+ (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        return (b?(a^b)+((a&b)<<(size_t)1):a);
    }
```

本质是列竖式 举例

11**Dec**=1011**Bin**

7**Dec**=111**Bin**

如果不进位加法 0+0=0 0+1=1 1+1=0

与xor运算相同 0xor0=0 0xor1=0 1xor1=0

而进位运算中，仅1+1=1，其余1+0与0+0都不需要进位

与and运算相同 1&1=1

因此得出该式

$$
a+b=a\oplus b+2(a\land b)
$$

此处 $\land$ 符号为与 不是幂运算

11+7 ->

|   | 1 | 0 | 1 | 1 |
| - | - | - | - | - |
| + |   | 1 | 1 | 1 |

另外 避免无限递归，在进位为0时停止递归，得出上述代码

## 减法

众所周知 减法是加法的一种

## 乘法

```cpp
ULong_Int<sz> operator* (ULong_Int <sz> a,ULong_Int <sz> b)
    {
        ULong_Int<sz> ans=0;
        size_t i=0;
        while (b)
        {
            b[0]?ans+=(a<<i):b;
            (b>>=1),++i;
        }
        return ans;
    }
```

## 除法/取模

```cpp
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
```
