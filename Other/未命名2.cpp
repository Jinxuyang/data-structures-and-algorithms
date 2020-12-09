
#include <cstdio>
#include <cstring>
const char * NOT_EXIST = "This puzzle has no final configuration.";
char a[5][10];
void swap(int i1, int j1, int i2, int j2) {
    char temp = a[i1][j1];
    a[i1][j1] = a[i2][j2];
    a[i2][j2] = temp;
}

int main() {
    int line = 1;
    while (true) {
        bool flag = true;
        int b_i = -1, b_j = -1;

        char ch = getchar();
        while (ch == '\n') {
            ch = getchar();
        }

        if (ch == 'Z') {
            return 0;
        }

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                while (ch == '\n' && j != 4) {
                    ch = getchar();
                }

                if (ch == '\n') {
                    a[i][j] = ' ';
                } else {
                    a[i][j] = ch;
                }
                if (a[i][j] == ' ') {
                    b_i = i;
                    b_j = j;
                }
                ch = getchar();
            }
        }

        while (true) {
            while (ch == '\n') {
                ch = getchar();
            }

            if (ch == '0') {
                break;
            }

            if (ch == 'A') {
                if (b_i - 1 < 0) {
                    flag = false;
                    break;
                }
                swap(b_i, b_j, b_i - 1, b_j);
                b_i = b_i - 1;
            } else if (ch == 'B') {
                if (b_i + 1 > 4) {
                    flag = false;
                    break;
                }
                swap(b_i, b_j, b_i + 1, b_j);
                b_i = b_i + 1;
            } else if (ch == 'L') {
                if (b_j - 1 < 0) {
                    flag = false;
                    break;
                }
                swap(b_i, b_j, b_i, b_j - 1);
                b_j = b_j - 1;
            } else if (ch == 'R') {
                if (b_j + 1 > 4) {
                    flag = false;
                    break;
                }
                swap(b_i, b_j, b_i, b_j + 1);
                b_j = b_j + 1;
            }
//            else {
//                flag = false;
//            }
            ch = getchar();
        }

        while (ch != '0') {
            ch = getchar();
        }

        if (line != 1) {
            printf("\n");
        }

        printf("Puzzle #%d:\n", line++);
        if (flag == false) {
            printf("%s\n", NOT_EXIST);
        } else {
            for (int i = 0; i < 5; ++i) {
                printf("%c", a[i][0]);
                for (int j = 1; j < 5; ++j) {
                    printf(" %c", a[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
201827010427 ? 8 months ago
谢谢大佬，Z之前一点不能有‘\n’

1847497680 ? 6 months ago
感谢老哥

hhx20120607 ? 6 months ago
#include <stdio.h>
#include <string.h>

char s[5][7];

char d;

int p,q;

int main()
{
    //freopen("data.in","r",stdin);
    int k=0;
    while(fgets(s[0],7,stdin)&&strcmp(s[0],"Z\n"))
    {
        k++;
        int r=0;
        for(int c=0; c<5; c++)
        {
            if(s[r][c]==' ')
            {
                p=r;
                q=c;
                break;
            }
        }
        for(int i=1; i<5; i++)
        {
            fgets(s[i],7,stdin);
            r++;
            for(int c=0; c<5; c++)
            {
                if(s[r][c]==' ')
                {
                    p=r;
                    q=c;
                    break;
                }
            }
        }
        bool tag=true;
        while((d=fgetc(stdin))!=EOF&&d!='0')
        {
            if(d=='\n')
                continue;
            int m=p,n=q;
            switch(d)
            {
            case 'A':
                m--;
                break;
            case 'B':
                m++;
                break;
            case 'L':
                n--;
                break;
            case 'R':
                n++;
                break;
            default:
                break;
            }
            if(m>=0&&m<5&&n>=0&&n<5)
            {
                s[p][q]=s[m][n];
                s[m][n]=' ';
                p=m;
                q=n;
            }
            else
                tag=false;
        }
        fgetc(stdin);
        if(k!=1)
            printf("\n");
        if(tag)
        {
            printf("Puzzle #%d:\n",k);
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<5; j++)
                {
                    if(j!=0)
                        printf(" ");
                    printf("%c",s[i][j]);
                }
                printf("\n");
            }
        }
        else
            printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",k);

    }
    return 0;
}
Shawn_XIAOGNAH ? 8 months ago Reply ? Edit ? Delete
幸好看了一下评论，搞清了输出格式。不然的话，这道题得做一年……
有些不足的地方，代码中有大量重复的地方可以封装为函数。

#include <iostream>
#include <string>
#define ROW 5
#define COL 5
using namespace std;

int main()
{    
    int kase = 1;
    while( true )
    {
        char puzzle[ROW][COL];
        string str, moves;
        int isBreak = 0, isFail = 0, blank_row = 0, blank_col = 0;
        // 读取迷宫
        for(int i = 0; i < ROW; i++)
        {                    
            getline(cin, str);
            if(str[0] == 'Z')
            {
                isBreak = 1;
                break;
            }

            for(int j = 0; j < COL; j++)
            {
                puzzle[i][j] = str[j];
                if(str[j] == ' ')
                {           // 记录空格位置
                    blank_row = i;
                    blank_col = j;
                } 
            }       
        }
        if(isBreak) break;

         // 读取移动操作
        do
        {       // 考虑到 moves 可能分为多行的情况              
            string subMoves;
            getline(cin, subMoves);
            moves += subMoves;
        } while(moves[moves.length()-1] != '0');

        for(int i = 0; i < moves.length(); i++)
        {
            if(moves[i] == 'A')
            {
                if(blank_row - 1 < 0)
                {
                    isFail = 1;
                    break;
                }
                else
                {
                    char tmp = puzzle[blank_row-1][blank_col];
                    puzzle[blank_row-1][blank_col] = puzzle[blank_row][blank_col];
                    puzzle[blank_row][blank_col] = tmp;
                    blank_row--;    // 更新空白区域的位置 
                }
            }
            if(moves[i] == 'B')
            {
                if(blank_row + 1 > 4)
                {
                    isFail = 1;
                    break;
                }
                else
                {
                    char tmp = puzzle[blank_row+1][blank_col];
                    puzzle[blank_row+1][blank_col] = puzzle[blank_row][blank_col];
                    puzzle[blank_row][blank_col] = tmp;
                    blank_row++; 
                }
            }
            if(moves[i] == 'L')
            {
                if(blank_col - 1 < 0)
                {
                    isFail = 1;
                    break;
                }
                else
                {
                    char tmp = puzzle[blank_row][blank_col-1];
                    puzzle[blank_row][blank_col-1] = puzzle[blank_row][blank_col];
                    puzzle[blank_row][blank_col] = tmp;
                    blank_col--; 
                }
            }
            if(moves[i] == 'R')
            {
                if(blank_col + 1 > 4)
                {
                    isFail = 1;
                    break;
                }
                else
                {
                    char tmp = puzzle[blank_row][blank_col+1];
                    puzzle[blank_row][blank_col+1] = puzzle[blank_row][blank_col];
                    puzzle[blank_row][blank_col] = tmp;
                    blank_col++; 
                }
            }
            if(moves[i] == '0') break; 
        }

        if(kase >= 2)   cout << endl;
        cout << "Puzzle #" << kase++ << ":\n";
        if(isFail)  cout << "This puzzle has no final configuration.\n";
        else
        {
            for(int i = 0; i < ROW; i++)
            {
                for(int j = 0; j < COL-1; j++)
                    cout << puzzle[i][j] << ' ';
                cout << puzzle[i][COL-1] << endl;
            }
        }
    }
    return 0;
}
zhangboer ? 8 months ago
注意空格在第一个位置的情况即可。

zhangAo ? 9 months ago
好烦啊，不想做了，已经能达到他表述的要求了，凭什么要因为他没说清楚的换行什么的算我错。。

#include<iostream>
using namespace std;
struct point{
    int x,y;
    point(int x,int y):x(x),y(y){
    }
    point(){} 
};
int main(){
    std::ios::sync_with_stdio(false);
    string s,heng[5],shu[5];
    point kong;
    int count=1;
    char t;
    bool f1=false;
    while(true){
        for(int i=0;i<5;++i){
            getline(cin,heng[i]);
            if(heng[i]=="Z")return 0;
        }
        cout<<"Puzzle #"<<(count++)<<":\n";
        for(int i=0;i<5;++i){
            shu[i]="";
            for(int j=0;j<5;++j){
                shu[i]+=heng[j][i];
                if(heng[j][i]==' '){
                    kong=point(i,j);
                }
            }
        }
        getline(cin,s);
        int l=s.size();
        if(s[l-1]=='Z'){
            f1=true;
            l--;
        }
        bool f=false;
        for(int i=0;i<l;++i){
            switch(s[i]){
                case 'A':
                    if(kong.y-1<0){
                        f=true;
                        break;
                    }
                    t=shu[kong.x][kong.y];
                    shu[kong.x][kong.y]=shu[kong.x][kong.y-1];
                    shu[kong.x][kong.y-1]=t;
                    for(int i=0;i<5;++i){
                        heng[kong.y][i]=shu[i][kong.y];
                        heng[kong.y-1][i]=shu[i][kong.y-1];
                    }
                    kong=point(kong.x,kong.y-1);
                    break;
                case 'B':
                    if(kong.y+1>4){
                        f=true;
                        break;
                    }
                    t=shu[kong.x][kong.y];
                    shu[kong.x][kong.y]=shu[kong.x][kong.y+1];
                    shu[kong.x][kong.y+1]=t;
                    for(int i=0;i<5;++i){
                        heng[kong.y][i]=shu[i][kong.y];
                        heng[kong.y+1][i]=shu[i][kong.y+1];
                    }
                    kong=point(kong.x,kong.y+1);
                    break;
                case 'R':
                    if(kong.x+1>4){
                        f=true;
                        break;
                    }
                    t=heng[kong.y][kong.x];
                    heng[kong.y][kong.x]=heng[kong.y][kong.x+1];
                    heng[kong.y][kong.x+1]=t;
                    for(int i=0;i<5;++i){
                        shu[kong.x][i]=heng[i][kong.x];
                        shu[kong.x+1][i]=heng[i][kong.x+1];
                    }
                    kong=point(kong.x+1,kong.y);
                    break;
                case 'L':
                    if(kong.x-1<0){
                        f=true;
                        break;
                    }
                    t=heng[kong.y][kong.x];
                    heng[kong.y][kong.x]=heng[kong.y][kong.x-1];
                    heng[kong.y][kong.x-1]=t;
                    for(int i=0;i<5;++i){
                        shu[kong.x][i]=heng[i][kong.x];
                        shu[kong.x-1][i]=heng[i][kong.x-1];
                    }
                    kong=point(kong.x-1,kong.y);
                    break;
            }
            if(f){
                cout<<"This puzzle has no final configuration.\n";
                break;
            }
        }
        if(!f){
            for(int i=0;i<5;++i){
                for(int j=0;j<4;++j){
                    cout<<heng[i][j]<<" ";
                }
                cout<<heng[i][4]<<endl;
            }
        }
        if(f1){
            return 0;
        }
        cout<<"\n";
    }
    return 0;
}

/*
  x
 --------------
y|
 |
 |
 |
 |

A:上面的下移->kong.y-1,shu[kong.x]变,heng[kong.y]、heng[kong.y-1]变 
B:下面的上移->kong.y+1
L:左面的右移->kong.x-1
R:右面的左移->kong.x+1

TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS 
TUVWX
AAA
ABCDE
FGHIJ
KLMNO
PQRS 
TUVWX
AAAAABBRRRLL0
Z

*/
Piller4F ? 12 months ago
//超超超笨的AC码
#define _CRT_SECURE_NO_WARNINGS
#include
#include
using namespace std;

void swap(char &a, char &b)
{
char t = a;
a = b;
b = t;
}

int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

char a[5][5] = { 0 };
int cnt = 1;
a[0][0] = getchar();
int black = 1;
while (a[0][0] != 'Z')
{
    int x, y;
    if (a[0][0] == ' ')
        x = 0, y = 0;
    for (int j = 1; j < 5; ++j)   //录入未录入完的数据
    {
        a[0][j] = getchar();
        if (a[0][j] == ' ' || j == 4 && a[0][j] == '\n')
        {
            a[0][j] = ' ';
            x = 0, y = j;
        }
    }
    char t;
    while ((t = getchar()) != '\n');
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            a[i][j] = getchar();
            if (j == 4 && a[i][j] == '\n')
            {
                a[i][j] = ' ';
                x = i, y = j;
            }
            else
            {
                if (a[i][j] == '\n')
                    j--;
                else
                {
                    if (a[i][j] == ' ')
                        x = i, y = j;
                }
            }
        }
        while ((t = getchar()) != '\n');
    }
    char ch;
    while ((ch = getchar()) == '\n'); 
    int flag = 0;
    while (ch != '0')
    {
        if (ch != '\n')
        {
            if (ch != 'A'&&ch != 'B'&&ch != 'L'&&ch != 'R')
                flag = 1;
            else
            {
                switch (ch)
                {
                case 'A':
                    if (x - 1 < 0)
                        flag = 1;
                    else
                    {
                        swap(a[x - 1][y], a[x][y]);
                        x = x - 1;
                    }
                    break;
                case 'B':
                    if (x + 1 > 4)
                        flag = 1;
                    else
                    {
                        swap(a[x + 1][y], a[x][y]);
                        x = x + 1;
                    }
                    break;
                case 'L':
                    if (y - 1 < 0)
                        flag = 1;
                    else
                    {
                        swap(a[x][y - 1], a[x][y]);
                        y = y - 1;
                    }
                    break;
                case 'R':
                    if (y + 1 > 4)
                        flag = 1;
                    else
                    {
                        swap(a[x][y + 1], a[x][y]);
                        y = y + 1;
                    }
                    break;
                }
            }
        }
        cin >> ch;
    }
    if (black)
        black = 0;
    else
        printf("\n");
    cout << "Puzzle #" << cnt++ << ":" << endl;
    if (flag)
        cout << "This puzzle has no final configuration.";
    else
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 4; ++j)
                cout << a[i][j] << " ";
            if (i < 4)
                cout << a[i][4] << endl;
            else
                cout << a[i][4];
        }
    }
    printf("\n");
    memset(a, 0, sizeof(a));
    while ((t = getchar()) != '\n');
    a[0][0] = getchar();
}

return 0;
}

Willii ? 1 years ago
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

//#define LOCAL

#define PUZZLE_SCALE        (5)
#define MAX_MOVE_SIZE        (100)
#define MAX_BUFFER_SIZE        (100)

#pragma pack(1)
typedef struct
{
    int x;
    int y;
}stPosition;

typedef struct
{
    char puzzle[PUZZLE_SCALE][PUZZLE_SCALE + 1];
    char move[MAX_MOVE_SIZE];
    stPosition blankPosition;
}stPuzzle;
#pragma pack()

static stPuzzle puzzles;
static char buffer[MAX_BUFFER_SIZE];

int idx = 0;

int main(void)
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i = 0, j = 0, k = 0;

    for (;;)
    {
        bool bFlag = true;    // used to print '\n' before "Puzzle #n:"

        i = 0;        
        memset(&puzzles, 0, sizeof(puzzles));

        // read 5 lines input
        while(i < PUZZLE_SCALE)
        {
            scanf("%[^\n]", buffer);    // stop on '\n'
            getchar();                  // read '\n'

            if ( buffer[0] == 'Z')
                return 0;

            if (idx != 0 && bFlag)
            {
                bFlag = false;
                printf("\n"); 
            }                

            char *ret = (char *)memchr(buffer, ' ', PUZZLE_SCALE);  // find space
            if (ret != NULL)
            {
                puzzles.blankPosition.x = i;
                puzzles.blankPosition.y = ret - buffer;
            }
            // else if (strlen(buffer) == PUZZLE_SCALE - 1)
            // {
                // puzzles.blankPosition.x = i;
                // puzzles.blankPosition.y = PUZZLE_SCALE - 1;  // if there are only 4 characters in a line, then the 5 character is space by default

                // buffer[PUZZLE_SCALE - 1] = ' ';
            // }

            memcpy(&puzzles.puzzle[i++][0], buffer, PUZZLE_SCALE);
        }

        // read moves
        scanf("%[^0]", puzzles.move);                       // stop on '0'
        puzzles.move[strlen(puzzles.move)] = getchar();     // read '0'
        getchar();                                          // read '\n'

        idx++;                  // record how many puzzles are processed 


        // process input

        bool bRet = true;       // has final configuration or not
        int preX = puzzles.blankPosition.x;                 // x position of the blank before processing
        int preY = puzzles.blankPosition.y;                 // y position of the blank before processing

        j = 0;
        while(puzzles.move[j] != '0')
        {
            int newX = preX;
            int newY = preY;

            // printf("##A: preX: %d, preY: %d, newX: %d, newY: %d\n", preX, preY, newX, newY);

            switch (puzzles.move[j])
            {
                case 'A':   newX -= 1;      break;
                case 'B':   newX += 1;      break;
                case 'L':   newY -= 1;      break;
                case 'R':   newY += 1;      break;
                case '\n':                  break;          // '\n' could be contained in the move sequence
                default:    bRet = false;   break;
            }

            if (newX < 0 || newX > PUZZLE_SCALE - 1 ||  \
                newY < 0 || newY > PUZZLE_SCALE - 1 ||  \
                bRet == false)
            {
                bRet = false;
                break;                                      // this puzzle doesn't have final configuration
            }

            swap(puzzles.puzzle[preX][preY], puzzles.puzzle[newX][newY]);

            preX = newX;
            preY = newY;

            j++;
        }

        // print result
        printf("Puzzle #%d:\n", idx);

        if (bRet)
        {
            j = 0, k = 0;

            for (j = 0; j < PUZZLE_SCALE; j++)
            {
                for (k = 0; k < PUZZLE_SCALE; k++)
                {
                    printf("%c", puzzles.puzzle[j][k]);

                    (k < PUZZLE_SCALE - 1) ? printf(" ") : printf("\n");
                }

            }
        }
        else
        {
            printf("This puzzle has no final configuration.\n");
        }

        // continue to get the next puzzle input
    }
}
Frankyao ? 1 years ago
好绝望啊java一直超时

124132423 ? 1 years ago
这题目有问题，我一个错代码，连样例都通过不了，也能ac
#include
void swap1(char &a,char &b)
{
char c;
c=a;a=b;b=c;
}

int main()
{
int kase=0,c;
char s[5][5];
for(;;)
{
int sp1,sp2,flag=0;
for(int i=0;i<5;i++) { for(int j=0;j<5;j++) { if(s[0][0]=='Z') return 0; scanf("%c",&s[i][j]); if(s[i][j]==' ') { sp1=i;sp2=j; } } getchar(); } while((c=getchar())!='0') { if(c=='A'&&sp1-1>=0)
{
swap1(s[sp1][sp2],s[sp1-1][sp2]);
sp1-=1;
}
else if(c=='B'&&sp1+1<=4) { swap1(s[sp1][sp2],s[sp1+1][sp2]); sp1+=1; } else if(c=='L'&&sp2-1>=0)
{
swap1(s[sp1][sp2],s[sp1][sp2-1]);
sp2-=1;
}
else if(c=='R'&&sp2+1<=4)
{
swap1(s[sp1][sp2],s[sp1][sp2+1]);
sp2+=1;
}
else if(c!='\n')
{
flag=1;
}
}
getchar();
if(kase)
printf("\n");
printf("Puzzle #%d:\n",++kase);
if(!flag)
{
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
if(!j)
printf("%c",s[i][j]);
else
printf(" %c",s[i][j]);
}
printf("\n");
}
}
else
printf("This puzzle has no final configuration.\n");

}
return 0;
}

Fireflies2000 ? 1 years ago
样例的每行最后一个‘ ’是复制不上的

124132423 ? 1 years ago
谢谢提醒。。

Lily0630 ? 1 years ago
#include
#include
int panduan(int han,int li)
{
if(han>4||han<0||li<0||li>4)
return -1;
else
return 1;
}
int main()
{

char a[6][6]={0},b,q[100];
int i,j,hang,lie,ji,ji1=0,flag,i1,i2,j1;
while(1)
{  ji1++; ji=0;
    memset(a,0,sizeof(a));
        for(i=0;i<5;i++)
        {
           gets(a[i]);
            if(a[0][0]=='Z')
          return 0;
         // puts(a[i]);
           int len=strlen(a[i]);
                {
                    if(len==4)
                    { a[i][4]=' ';}
                }

        }
       while(1)
       {
            b=getchar();
           if(b=='0')
           {
                getchar();
                break;
           }
           else
           {
                for(i1=0;i1<5;i1++)
                for(j1=0;j1<5;j1++)
                {
                    if(a[i1][j1]==' ')
                    {
                        hang=i1;lie=j1;
                    }
                }
                flag=1;
                if(b=='A') ji=panduan(hang-1,lie); else
                if(b=='B') ji=panduan(hang+1,lie); else
                if(b=='L') ji=panduan(hang,lie-1); else
                if(b=='R') ji=panduan(hang,lie+1);
                if(ji==1)
                {
                if(b=='A') {a[hang][lie]=a[hang-1][lie];a[hang-1][lie]=' ';}else
                if(b=='B') {a[hang][lie]=a[hang+1][lie];a[hang+1][lie]=' ';}else
                if(b=='L') {a[hang][lie]=a[hang][lie-1];a[hang][lie-1]=' ';}else
                if(b=='R') {a[hang][lie]=a[hang][lie+1];a[hang][lie+1]=' ';}else
                flag=0;

                }
                else
                {flag=0; gets(q);break;}
           }
       }
        if(ji1!=1)
        printf("\n");
        printf("Puzzle #%d:\n",ji1);
        if(flag==1)
        {
                for(i=0;i<5;i++)
                {
                    for(j=0;j<5;j++)
                    {if(j==0)
                        printf("%c",a[i][j]);
                        else
                            printf(" %c",a[i][j]);

                    }printf("\n");
                }
        }
        else
        {
            printf("This puzzle has no final configuration.\n");
        }
}
return 0;
}

麻烦各位大佬帮忙看看，任意 能想起来的测试样例 都对，提交后就是wrong answer

请各位大佬帮忙看看，感激不尽啊！！！！

wqy123 ? 1 years ago
#include
#include
int main()
{
int x,y,len,i,sum=1,sum1=0,k;
char ch[6][6]={0},gh,t;
while(gets(ch[0])&&ch[0][0]!='Z')
{
sum1=0;
len=strlen(ch[0]);
if(len==4)
{
x=0;y=4;
}
else
{
for(k=0;k<=4;k++) { if(ch[0][k]==' ') { x=0;y=k; } } } for(i=1;i<=4;i++) { gets(ch[i]); len=strlen(ch[i]); if(len==4) { x=i;y=4; } else { for(k=0;k<=4;k++) { if(ch[i][k]==' ') { x=i;y=k; } } } } while((gh=getchar())&&gh!='0') { if(gh=='\n') continue; if(gh=='A'&&x>0)
{
ch[x][y]=ch[x-1][y];
ch[x-1][y]='\0';
x=x-1;
}
else if(gh=='B'&&x<4) { ch[x][y]=ch[x+1][y]; ch[x+1][y]='\0'; x=x+1; } else if(gh=='L'&&y>0)
{
ch[x][y]=ch[x][y-1];
ch[x][y-1]='\0';
y=y-1;
}
else if(gh=='R'&&y<4)
{
ch[x][y]=ch[x][y+1];
ch[x][y+1]='\0';
y=y+1;
}
else
sum1++;
}
if(sum!=1)
printf("\n");
printf("Puzzle #%d:\n",sum);
if(sum1==0){
for(i=0;i<=4;i++)
{
for(k=0;k<=4;k++)
{
if(k==0)
printf("%c",ch[i][k]);
else
printf(" %c",ch[i][k]);
}
printf("\n");
}}
else
printf("This puzzle has no final configuration.\n");
memset(ch,0,sizeof(ch));
getchar();sum++;
}
return 0;
}
一直报错，测试数据都对，求教

chenghan ? 1 years ago
#include
#include
#include
int main()
{
char a[6][6];
int q=0,k=0;
memset(a,0,sizeof(a));
while(gets(a[1])&&a[1][0]!='Z')
{
if(k++)
printf("\n");
int d=1;
int m,n,i,j;
for(i=2;i<6;i++) {gets(a[i]);} for(i=1;i<6;i++) for(j=0;j<5;j++) if(a[i][j]==' ') {m=i;n=j;} char b[1000]; gets(b); int t=0; printf("Puzzle #%d:\n",++q); while(b[t]!='0') { if(b[t]=='R'&&(n+1<5)) {a[m][n]=a[m][n+1];a[m][n+1]=' ';n++;} else if(b[t]=='L'&&(n-1>=0))
{a[m][n]=a[m][n-1];a[m][n-1]=' ';n--;}
else if(b[t]=='A'&&(m-1>=1))
{a[m][n]=a[m-1][n];a[m-1][n]=' ';m--;}
else if(b[t]=='B'&&(m+1<6))
{a[m][n]=a[m+1][n];a[m+1][n]=' ';m++;}
else
{
d=!d;
printf("This puzzle has no final configuration.\n");
break;
}t++;}
if(d)
{for(i=1;i<6;i++)
for(j=0;j<6;j++)
printf(j==5?"%c\n":"%c ",a[i][j]);}
memset(a,0,sizeof(a));
}
return 0;
}
本地凑了无数个数据都是对的，就是一直WA，求大神解释一下

CoAAColA ? 2 years ago
大家审题一定要仔细啊，我一个冒号没有输出，OJ给我报WA，硬生生让我过几个月才找出毛病来

1297909082 ? 2 years ago
心态爆炸

CoAAColA ? 2 years ago
这题慢慢来吧hh

wqy123 ? 1 years ago
我是个大一的小白，是要学好c++，才能做这种题吗，现在做感觉好吃力

CoAAColA ? 1 years ago
基础语法熟练之后再做这种题目会更顺畅，但是也可以通过做题来提高编程水平

CRUEL_KING ? 1 years ago
100行代码被我改成60行才过的……
注意最后一个结果之后无空行，注意空行在输入之后输出，以下是菜鸡PE两天才AC的代码，欢迎大佬批评指正。https://www.cnblogs.com/bianjunting/p/9848909.html

827852427 ? 1 years ago
注意最后一个结果之后没有空行！！！
菜鸡写的题解uav 227
autologic ? 2 years ago
这题格式太难受了

Yichuan_Sun ? 2 years ago
这题太能卡人了，都是输入输出卡的。
1.输入的5X5矩阵中，有时一行最后有多个空格和回车
2.输出格式中，每两个输出结果之间间隔一个空行，但是最后一个结果之后没有空行。
3.有时到第四位元素，直接不按空格，直接换行了。

（星号星号都用不了，这莫非是个假markdown？）

这个辣鸡写的题解见uva 227

Starpast ? 2 years ago
Be careful that when you input the letter Z, actually the program gets that Z instead of a newline character in front of it.

Trust_04zh ? 2 years ago
AC
#include
#include
#define hide 1
#ifdef hide
char block[5][5];
int x,y;
int input();
int move();
void output(int);
#endif
int main(void){
for(;;){
int flag1=input();
if(flag1) break;
int flag2=move();
output(flag2);
}
return 0;
}
int input(){
for(int i=0;i<5;i++){
for(int j=0;j<5;j++){
reput:scanf("%c",&block[i][j]);
if(i==0&j==0&block[0][0]=='Z') return 1;
if(block[i][j]==13||block[i][j]==10) goto reput;
if(block[i][j]==32) {x=i;y=j;}
}}return 0;}
int move(){
char ch;
int flag=1;
while((ch=getchar())!='0'){
switch(ch){
case '\n':continue;
case 'A':if(x!=0){block[x][y]=block[x-1][y];block[x-1][y]=' ';x--;}else{flag=0;}break;
case 'B':if(x!=4){block[x][y]=block[x+1][y];block[x+1][y]=' ';x++;}else{flag=0;}break;
case 'L':if(y!=0){block[x][y]=block[x][y-1];block[x][y-1]=' ';y--;}else{flag=0;}break;
case 'R':if(y!=4){block[x][y]=block[x][y+1];block[x][y+1]=' ';y++;}else{flag=0;}break;
}
}
return flag;
}
void output(int flag){
static int count=0;count++;
if(count!=1){printf("\n");}
printf("Puzzle #%d:\n",count);
if(flag){
for(int i=0;i<5;i++){
for(int j=0;j<4;j++){
printf("%c ",block[i][j]);
}
printf("%c\n",block[i][4]);
}}
else printf("This puzzle has no final configuration.\n");
}

     
