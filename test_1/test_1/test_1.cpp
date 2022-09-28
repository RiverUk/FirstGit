#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
     int size[20][20] = { 0, };               // 최대 칸수
     char move[10];                           // 이동경로 저장하는 문자열 배열 (ex. U5, R3)
     const char* route[20][20] = {0};      // 이동경로를 화면에 보여주는 2차원 배열 , 초기화값이 NULL값으로 나옴
    
    int choice = 0;
    
    
    int reset = -1;                         // 처음시작시 size배열이 0부터 시작하기때문에 처음에만 -1을 해주고 시작
    int x = 0, y = 0;                       // 이동시 위치 저장 시켜주는 변수
    int num = 0;                            // 얼만큼 이동하는지 scanf에서 받는 변수

    printf("최대 칸수(MAX=20): ");
    
    scanf_s("%d", &choice);

    choice -= 1;
    
    while (1)
    {
        printf("\n");

        if (x<0||x>choice+1)                          // x가 배열의 범위를 넘어가면 while문 종료
        {
            break;
        }
        else if (y < 0 || y>choice+1)                 // y가 배열의 범위를 넘어가면 while문 종료
        {
            break;
        }
        
        num = 0;
        printf("이동경로는 ?");
        scanf_s("%s", move, 10);                   // move에 문자열 받기

        if (move[0] == 'u')                         // move의 첫번째 배열에 u가 들어가면
        {
            
            num = move[1]-48+reset;               // scanf에서 입력받은 이동칸수를 num에 저장
           

            for (int i=x;i>=x-num;i--)              // for문을 사용해서 지나간 길 찍기
            {
                if (i < 0)                          // 범위를 초과 하면 빠져나오기
                {
                    break;
                    
                }                
                else if (size[i][y] != 0)           // 옆에 지나가다가 부딪히면 goto문으로 종료
                {
                    goto finish;
                }
                size[i][y] = { 8 };                 // 위로 올라가는 표시인 숫자 8
                route[i][y] = "↑";
                
            }
            x -= (num+1);                               // x값에 현재 위치 저장 (-인 이유는 올라가면 x의 배열이 줄어들기때문에)
        }

        else if (move[0] == 'd')                    
        {
            
            num = move[1]-48+reset;
           
           
            for (int i = x; i <= x + num; i++)          // for문을 사용해서 자나간 길 찍기
            {                       
                if (i > choice)
                {
                    break;
                  
                }
                else if (size[i][y] != 0)
                {
                    goto finish;
                }
                size[i][y] ={2};
                route[i][y] = "↓";
               
            }

            x += (num+1);
        }

        else if (move[0] == 'r')
        {
           
            num = move[1]-48+reset;
           
            
            for (int i=y;i<=y+num;i++)
            {               
                if (i > choice)
                {
                    break;
                    
                }
                else if (size[x][i] != 0)
                {
                    goto finish;
                }
                size[x][i] = { 6 };
                route[x][i] = "→";
            }
            y += (num+1);
            
        }

        else if (move[0] == 'l')
        {
            
            num = move[1]-48+reset;
            
           
            for (int i = y; i >= y - num; i--)
            {                
                if (i < 0)
                {
                    break;
                }
                else if (size[x][i] != 0)
                {

                    goto finish;
                }
                size[x][i] = { 4 };
                route[x][i] = "←";
            }
            y -= (num+1);
        }
        for (int i = 0; i < choice+1; i++)    // 2차원 배열의 세로 크기만큼 반복
        {
            for (int j = 0; j < choice+1; j++)    // 2차원 배열의 가로 크기만큼 반복
            {
                printf("%s\t", route[i][j]); // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
            }
            printf("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
        }
        
        
    }
finish:
    printf("\n벽에 부딪히거나 지나간 길입니다.!");



    return 0;

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
