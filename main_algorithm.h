#ifndef MAIN_ALGORITHM_H
#define MAIN_ALGORITHM_H

#include<mainwindow.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>

struct mat
{
    long long m[6][6];
    int mod=4;
    mat operator *(const mat temp)const
    {
        mat res;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                res.m[i][j]=0;
            }
        }
        res.mod=mod;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                for(int k=1;k<=5;k++)
                {
                    res.m[i][j]=(res.m[i][j]+m[i][k]*temp.m[k][j])%mod;
                }
            }
        }
        return res;
    }
    mat operator %(const int mod)const
    {
        mat res=*this;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                res.m[i][j]%=mod;
            }
        }
        return res;
    }

    mat operator ^(const long long tmp)const
    {
        mat res=*this;
        if(tmp==1)return res;
        if(tmp&1)return (res*(res^(tmp-1)))%mod;
        res=(res^(tmp>>1))%mod;
        return (res*res)%mod;

    }
    void print()
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                std::cout<<m[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
    }
};



//--------------------------------------------------------------------------
struct CPY
{
    long long P;
    mat Ps,Qs,Fir,ans;
    int key[11][11];
    void Step_1(int seed)
    {
        Ps.mod=4;
        Qs.mod=4;
        Fir.mod=4;
        ans.mod=4;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=10;j++)
            {
                key[i][j]=0;
            }
        }
        srand(seed);
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                Fir.m[i][j]=rand()%Fir.mod;
            }
        }
        return;
    }
    void Step_2(long long p)
    {
        P=p;
        Ps=Fir^P;
        return;
    }
    void Step_3()
    {
        ans=Qs^P;
        return;
    }
    void Step_4()
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                if(ans.m[i][j]==0)key[i][j]=1;
                if(ans.m[i][j]==1)key[j][11-i]=1;
                if(ans.m[i][j]==2)key[11-i][11-j]=1;
                if(ans.m[i][j]==3)key[11-j][i]=1;
            }
        }
        return;
    }
};




#endif // MAIN_ALGORITHM_H
