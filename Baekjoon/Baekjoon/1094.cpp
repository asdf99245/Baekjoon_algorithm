//막대기
//https://www.acmicpc.net/problem/1094

#include <cstdio>
#include <algorithm>
//#include <intrin.h> __popcnt() 이용 위한 라이브러리
using namespace std;

int bitCount(unsigned int x) { 
	if (x == 0) return 0;

	return (x % 2) + bitCount(x / 2); //이진수 변환하면서 1일시 카운트
}

int main() {
	unsigned int X;
	scanf("%d", &X);

	printf("%d", bitCount(X));
	
	/* 비주얼 스튜디오에 __popcnt() 함수로 하드웨어명령을 통해 빠르게 처리 가능하다
	gcc 에서는 __builtin_popcount() 이용 */
	//printf("%d", __popcnt(X));
	return 0;
}