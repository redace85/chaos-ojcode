#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int area=(C-A)*(D-B)+(G-E)*(H-F);
	// no overlap
	if (A>=G||E>=C||B>=H||D<=F)
	{
		return area;
	}

	int x1= A>E?A:E;
	int x2= C<G?C:G;

	int y1= B>F?B:F;
	int y2= D<H?D:H;

	return area-(x2-x1)*(y2-y1);
}

int main(){
	int area = computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1);
	printf("area:%d\n",area);

	int r=11/4;
	printf("r:%d\n",r);
	puts("end of app");
}

