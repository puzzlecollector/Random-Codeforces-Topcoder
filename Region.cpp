#include <stdio.h>
#include "Region.h"

int Region::notation = Region::POINT_POINT;

Region::Region(void)
{
    SetRect(0,0,0,0);  // 영역을 0으로 초기화
}

Region::Region(int l, int t, int r, int b)
{
    SetRect(l,t,r,b); // 영역을 주어진 값으로 초기화
}

void Region::SetRect(int l, int t, int r, int b)
{
    left = l; // start x
    top = t; // start y
    right = r; // end x
    bottom = b; // end y
}

int Region::GetWidth() const
{
    return right - left;
}

int Region::GetHeight() const
{
    return bottom - top;
}

void Region::GetStartPoint(int &x, int &y) const
{
    x = left;
    y = top;
}

void Region::GetEndPoint(int &x, int &y) const
{
    x = right;
    y = bottom;
}

void Region::GetCenterPoint(int &x, int &y) const
{
    x = (left+right)/2; // 중심의 x좌표
    y = (top+bottom)/2; // 중심의 y좌표
}

bool Region::IsPointInRegion(int x, int y) const
{
    return (x >= left && x <= right && y >= top && y <= bottom);
}

void Region::Move(int x, int y)
{
    left += x;
    right += x;
    top += y;
    bottom += y;
}

void Region::Resize(int width, int height)
{
    int x,y;
    GetCenterPoint(x,y); // 중심점 좌표
    left = x - width/2; // 중심으로부터 가로길이의 절반만큼 이동
    top = y - height/2; // 중심으로부터 세로길이의 절반만큼 이동
    right = left + width; // 가로길이가 width가 되도록 조절
    bottom = top + height; // 세로길이가 height가 되도록 조절
}

/*
UnionRegion 함수는 인자로 주어진 두 영역의 교집합, 즉 두 영역에 동시에 포함되는 사각형 영역을 지정하는 함수입니다.
교집합을 구하려면 시작점은 두 영역의 시작점 중 큰 값, 끝점은 두 영역의 끝점 중 작은 값을 취하면 됩니다. 만약 두 영역의
겹치는 부분이 없어 교집합이 존재하지 않는 경우에는 계산 결과의 시작점이 끝점보다 작아지는데 이럴때는 영역의 좌표를 0으로
초기화시킵니다.
*/

void Region::UnionRegion(const Region &r1, const Region &r2)
{
    left = r1.left > r2.left ? r1.left : r2.left;
    right = r1.right < r2.right ? r1.right : r2.right;
    top = r1.top > r2.top ? r1.top : r2.top;
    bottom = r1.bottom < r2.bottom ? r1.bottom : r2.bottom;
    if (left >= right || top >= bottom)
    {
        left = top = right = bottom = 0;
    }
}

/*
IntersectRegion 함수는 인자로 주어진 두 영역의 합집합, 즉 두 영역을 모두 포함하는 사각형
영역을 지정하는 함수입니다. 합집하을 구할때는 교집합을 구할 때와 달리, 시작점은 두 영역의 시작점 중
작은 값을 취하고 끝점은 두 영역의 큰 값을 취합니다.
*/
void Region::IntersectRegion(const Region &r1, const Region &r2)
{
    left = r1.left < r2.left ? r1.left : r2.left;
    right = r1.right > r2.right ? r1.right : r2.right;
    top = r1.top < r2.top ? r1.top : r2.top;
    bottom = r1.bottom < r2.bottom ? r1.bottom : r2.bottom;
}

// SetNotation 함수는 인자로 주어진 값을 static 멤버변수에 저장합니다.
void Region::SetNotation(int n)
{
    notation = n;
}

void Region::Show(void)
{
    if (notation == POINT_POINT)
    {
        printf("(%d,%d), (%d,%d)\n", left, top, right, bottom);
    }
    else
    {
        printf("(%d, %d), [%d x %d]\n", left, top, GetWidth(), GetHeight());
    }
}

int main(void)
{
    Region::SetNotation(Region::POINT_POINT);

    Region r1(10,10,100,100);
    Region r2(50,50,120,120);
    Region r3;

    r3.IntersectRegion(r1,r2);
    r3.Show();

    r3.UnionRegion(r1,r2);
    r3.Show();

    r3.Move(100,100);
    r3.Show();

    r3.Resize(200,200);
    r3.Show();

    Region::SetNotation(Region::POINT_SIZE);
    r1.Show();
    r2.Show();
    r3.Show();

    return 0;
}
