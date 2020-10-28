#include<bits.stdc++.h>

class cpoint
{
    public:
        int x,y,z;

        cpoint(int tx,int ty,int tz=0)
        {
            x=tx,y=ty,z=tz;
        }
};

int dot(cpoint A,cpoint B)
{
    return A.x*B.x+A.y*B.y+A.z*B.z;
}

double ang(cpoint A,cpoint B)
{
    double Thetha=acos(dot(A,B)/(sqrt(dot(A,A)*dot(B,B))));
    return Thetha;
}
