// 1st_calculation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	
	int plus = 0;
	int count = 0;

	int x = 0;
	int y = 0;
	int k = 0;
	int sum = 0;

	int z[200] = { 0, };
	char c[200] = { 0, };
	int a[200] = { 0, };
	char b[200] = { 0, };									// 계산값 받는 거
	int n[200] = { 0, };

	printf("연산을 입력하세요: ");
	scanf_s("%s", b, 200);


	for (int i = 0; i < 200; i++)
	{
		if ((b[i] == '+') || (b[i] == '-') || (b[i] == '*') || (b[i] == '/'))
		{
			c[x] = b[i];
			x++;
			y++;
			k = 0;
		}

		else if (b[i] >= '0' && b[i] <= '9')
		{

			k = (k * 10) + (b[i] - 48);
			z[y] = k;



		}
		else if (b[i] == '=')
		{
			break;
		}
	}

	for (int i = 0; i < 200; i++)
	{	
		if (c[i] == '*')
		{
			z[i + 1] = z[i] * z[i + 1];
			z[i] = 0;
			sum = z[i + 1];
			
		}
		else if (c[i] == '/')
		{
			z[i + 1] = z[i] / z[i + 1];
			z[i] = 0;
			sum = z[i + 1];
			
		}
		
	
	}
	for (int i = 0; i < 200; i++)
	{
		if (z[i] != NULL)
		{
			n[plus] = z[i];
			plus++;
		}
		
	}
	
	

	for (int i = 0; i < 200; i++)
	{
		if (c[i] == '+')
		{
			n[count+1] = n[count] + n[count + 1];
			sum = n[count + 1];
			count++;
		}
		else if (c[i] == '-')
		{
			n[count + 1] = n[count] - n[count + 1];
			sum = n[count + 1];
			count++;
		}
		else if (c[i] == '=')
		{
			break;
		}
		
	}

	
	printf("결과는 :%d", sum);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
