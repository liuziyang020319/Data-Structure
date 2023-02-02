#pragma comment(lib, ".\\x64\\EasyXa.lib")
#pragma comment(lib, ".\\x64\\EasyXw.lib")

#pragma comment(lib, "kernel32")
#pragma comment(lib, "user32")
#pragma comment(lib, "gdi32")
#pragma comment(lib, "winspool")
#pragma comment(lib, "comdlg32")
#pragma comment(lib, "advapi32")
#pragma comment(lib, "shell32")
#pragma comment(lib, "ole32")
#pragma comment(lib, "oleaut32")
#pragma comment(lib, "uuid")
#pragma comment(lib, "odbc32")
#pragma comment(lib, "odbccp32")

#include "graphics.h"
#include <conio.h>
#include <atlstr.h> 

#include <stdio.h>
#include <string.h>
#include <string.h>

int Board[8][8];
const int HTry1[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int HTry2[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct STACK {int x,y,counted,count[8];} stack[66];
int head;

void print_board(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%2d ",Board[i][j]);
        }
        printf("\n");
    }
}

void judge_priority(){
    for(int n=0;n<=7;n++){
        int i=stack[head].x, j=stack[head].y;
        if(0<=i+HTry1[n]&&i+HTry1[n]<=7
            &&0<=j+HTry2[n]&&j+HTry2[n]<=7
            &&!Board[i=i+HTry1[n]][j=j+HTry2[n]]
        ){
            if(head==62){
                stack[head].count[n]=1;
            }else{
                for(int m=0;m<=7;m++){
                    if(0<=i+HTry1[m]&&i+HTry1[m]<=7
                        &&0<=j+HTry2[m]&&j+HTry2[m]<=7
                        &&!Board[i+HTry1[m]][j+HTry2[m]]
                    ){
                        stack[head].count[n]++;
                    }
                }
            }
        }
    }
    stack[head].counted=1;
}

int check(int i0,int j0,int next){
    static int i,j;
    
    printf("Finding the");
    if(next) printf(" next");
    else printf(" first");
    printf(" solution on %d %d ... \t",i0,j0);

    if(!next){
        i=i0;
        j=j0;

        //Initialize board and stack
        memset(Board,0,sizeof(Board));
        head=0;

        //Store the initial point
        memset(stack+head,0,sizeof(STACK));
        stack[head].x=i;
        stack[head].y=j;
        Board[i][j]=head+1;
    }

    //Find solution
    int cycles=0; //cycles counter
    while(head<63||next--){

        //Count the number of choices after taking a possible step
        if(!stack[head].counted) judge_priority();

        //Find the priority: the one with least choices count
        int count_min=9;    //1~8
        int next_try=8;     //0~7
        for(int n=0;n<=7;n++){
            if(stack[head].count[n]&&stack[head].count[n]<=count_min){
                next_try=n;
                count_min=stack[head].count[n];
            }
        }

        if(next_try!=8){
            //Still worth trying
            stack[head].count[next_try]=0;
            i+=HTry1[next_try];
            j+=HTry2[next_try];
            head++;
            memset(stack+head,0,sizeof(STACK));
            stack[head].x=i;
            stack[head].y=j;
            Board[i][j]=head+1;
        }else{
            //All path dead
            Board[i][j]=0;
            head--;
            if(head==-1) break;
            i=stack[head].x;
            j=stack[head].y;
        }
        cycles++;
    }

    printf("Cycles count:%d\n",cycles);

    //If solution exists, head > 0
    return head;
}

int main(){
    //Input the initial point
    int i,j;
    printf("Please input two numbers bewteen 0 and 7 as the cooridinate of initial point\n");
    printf("Or input -1 -1 to check if solution exists under all initial circumstances\n");
    scanf("%d%d",&i,&j);

    if(i==-1&&j==-1){
        int failed=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(!check(i,j,0)){
                    printf("No path exists on %d %d\n",i,j);
                    failed=1;
                }
            }
        }
        if(!failed) printf("Solution exists under all initial circumstances!");
	    _getch();
    }else{
        int is_gui=0;
        printf("Use GUI? 1 for yes, 0 for no\n");
        scanf("%d",&is_gui);

        int next=0;
        do{
            if(check(i,j,next)){
                //Print the solution on CMD
                printf("Path exists!\n");
                print_board();
                if(is_gui){
                    //Draw the solution on GUI
                    int size=640;
                    float radius=0.8;
                    initgraph(size, size);
                    setfillcolor(WHITE);
                    for(int i=0;i<=7;i++){
                        for(int j=i%2;j<=7;j+=2){
                            solidrectangle(i*size/8,j*size/8,(i+1)*size/8,(j+1)*size/8);
                        }
                    }
                    setbkmode(TRANSPARENT);
                    IMAGE img;
                    loadimage(&img,_T(".\\horse.jpg"),size/8,size/8);
                    for(int step=0;step<=head;step++){
                        // //circle
                        // setfillcolor(RED);
                        // solidcircle((1+2*stack[step].x)*size/16,(1+2*stack[step].y)*size/16,(int)(radius*size/16));

                        putimage(stack[step].x*size/8, stack[step].y*size/8, &img, SRCINVERT);
                        Sleep(400);

                        setfillcolor((stack[step].x+stack[step].y)%2==0?WHITE:BLACK);
                        solidrectangle(stack[step].x*size/8,stack[step].y*size/8,(stack[step].x+1)*size/8,(stack[step].y+1)*size/8);

                        settextcolor((stack[step].x+stack[step].y)%2==0?BLACK:WHITE);
                        RECT r = {stack[step].x*size/8, stack[step].y*size/8, (1+stack[step].x)*size/8, (1+stack[step].y)*size/8};
                        //https://blog.csdn.net/Stephen___Qin/article/details/120466491
                        CString str;
                        str.Format(_T("%d"), step+1);
                        drawtext(LPCTSTR(str), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    }
                    _getch();
                    closegraph();
                }
            }else{
                printf("Path not exists!\n");
            }
            printf("Continue to search the next solution? 1 for yes, 0 for no\n");
            scanf("%d",&next);
        }while(next);
    }
}