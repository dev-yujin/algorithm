//2016125086 김유진
//g++ 컴파일러 사용
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Rectangle{
    int xLow, yLow, width, height;

    public:
        Rectangle(int x, int y, int h, int w){
            xLow=x;
            yLow=y;
            width=w;
            height=h;
        }

        //this와 R의 면적의 교집합의 면적을 구하는 함수
        int joint(Rectangle &r){
            int s = 0; //면적
            int valY, valX;

            vector <int> v;
            //높이
            int y1,y2,ya,yb;
            y1 = yLow + height;
            y2 = yLow;
            ya = (r.yLow) + (r.height);
            yb = (r.yLow);
            v.push_back(y1);
            v.push_back(y2);
            v.push_back(ya);
            v.push_back(yb);

            //둘이 안겹치는 경우
            if( (y2>ya) || (yb>y1) ){
                return 0;
            }

            sort(v.begin(), v.end());
            valY = v[2] - v[1];

            //너비
            int x1,x2,xa,xb;
            x1 = xLow;
            x2 = xLow + width;
            xa = (r.xLow);
            xb = (r.xLow) + (r.width);

            vector <int> c;
            c.push_back(x1);
            c.push_back(x2);
            c.push_back(xa);
            c.push_back(xb);

            //둘이 안겹치는 경우 
            if( (x2<xa) || (xb<x1) ){
                return 0;
            }
            
            sort(c.begin(), c.end());
            valX = c[2] - c[1];

            s = valX * valY;
            
            return s;
        }
};

int main(){

    int a,b,c,d,e,f,g,h;
    cin >> a >> b >> c >> d ;
    cin >> e >> f >> g >> h ;

    Rectangle r1(a,b,c,d);
    Rectangle r2(e,f,g,h);

    cout<< r1.joint(r2) <<endl;

    return 0;
}