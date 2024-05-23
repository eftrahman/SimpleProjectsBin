#include <stdio.h>
#include <stdlib.h>
char arr[]={'0',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int Move[5];
int moves[9];
int won=1;
int noBlock=0;
void display(){
    system("cls");
    system("color E0");
    printf("\t\tYou: X,  Computer: O>--------------<< OR >>-------------<");
    printf("Player 1: X, Player 2: O\n\n");
    printf("\t\t\tBLOCK NOs:");
    printf("\t\t  1 | 2 | 3\n");
    printf("\t\t\t\t\t\t ---+---+---\n");
    printf("\t\t\t\t\t\t  4 | 5 | 6\n");
    printf("\t\t\t\t\t\t ---+---+---\n");
    printf("\t\t\t\t\t\t  7 | 8 | 9\n");

    printf("\n\t\t>---------------------------------<< PLAY >>----------------------------------<\n\n");

    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t    %c    |    %c    |    %c    \n", arr[1], arr[2], arr[3]);
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t_________|_________|_________\n");
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t    %c    |    %c    |    %c   \n", arr[4], arr[5], arr[6]);
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t_________|_________|_________\n");
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t    %c    |    %c    |    %c   \n", arr[7], arr[8], arr[9]);
    printf("\t\t\t\t\t         |         |         \n");
    printf("\t\t\t\t\t         |         |         \n");

    printf("\n\t\t>---------------------------------<<<<<>>>>>---------------------------------<\n");

    printf("\n\t\tEnter a cell >>\t\t\t\t\t\t\t     < 0 >Menu\n\t\t");

}
int main(){
    system("color E0");
    printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
    design02();
    printf("\n\n\n\t\t\t\t     >>----<+>----<< HOW TO PLAY >>----<+>----<<\n\n");
    printf("\t  THERE ARE NINE BLOCKS IN A 'TIC TAC TOE' GAME. YOU CAN PICK A BLOCK SIMPLY BY CHOOSING A NUMBER\n\t  FROM ONE TO NINE. ");
    printf(" >>BLOCK NOs :\n");
    printf("\t\t\t\t\t\t      1 | 2 | 3\n");
    printf("\t\t\t\t\t\t     ---+---+---\n");
    printf("\t\t\t\t\t\t      4 | 5 | 6\n");
    printf("\t\t\t\t\t\t     ---+---+---\n");
    printf("\t\t\t\t\t\t      7 | 8 | 9\n");
    printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
    getch();
    Home();
    return 0;
}
void Home(){
    system("cls");
    int chs;
    design01();
    scanf("%d",&chs);
    if(chs==2){
        display();
        HvH();
    }
    else if(chs==1){
        HvC();
    }
    else if(chs==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
}
void Menu1(){
    system("cls");
    system("color B0");
    int b;
    printf("\n\t   >-----------------------------------------<< MENU >>------------------------------------------<\n\n\n\n");
    design02();
    printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
    printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
    printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
    printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
    scanf("%d",&b);
    if(b==1){
        for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Hard();
    }
    else if(b==2){
        for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
    }
    else if(b==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
}
void Menu2(){
    system("cls");
    system("color B0");
    int b;
    printf("\n\t   >-----------------------------------------<< MENU >>------------------------------------------<\n\n\n\n");
    design02();
    printf("\n\n\n\n\t   >>----< 1 >----<< CONTINUE >>--<\n");
    printf("\n\t   >>----< 2 >----<< RESTART >>---<\n");
    printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
    printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
    printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
    scanf("%d",&b);
    if(b==1){
        Easy();
    }
    else if(b==2){
        for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Easy();
    }
    else if(b==3){
        for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
    }
    else if(b==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
}
void Menu3(){
    system("cls");
    system("color B0");
    int b;
    printf("\n\t   >-----------------------------------------<< MENU >>------------------------------------------<\n\n\n\n");
    design02();
    printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
    printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
    printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
    printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
    scanf("%d",&b);
    if(b==1){
        for(int i=1;i<10;i++){
                arr[i]=' ';
            }
                won=1;
                HvH();
    }
    else if(b==2){
        for(int i=1;i<10;i++){
            arr[i]=' ';
        }
            won=1;
            Home();
    }
    else if(b==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
}
void HvH(){
    int g;
    int a=0;
    display();
    scanf("%d",&moves[0]);
    if(moves[0]==0){
        Menu3();
    }
    else{
        arr[moves[0]]='X';
        display();
    }
    scanf("%d",&moves[1]);
    if(moves[1]==0){
        Menu3();
    }
    else{
        arr[moves[1]]='O';
        display();
    }
    scanf("%d",&moves[2]);
    if(moves[2]==0){
        Menu3();
    }
    else{
        arr[moves[2]]='X';
        display();
    }
    scanf("%d",&moves[3]);
    if(moves[3]==0){
        Menu3();
    }
    else{
        arr[moves[3]]='O';
    display();
    }
    scanf("%d",&moves[4]);
    if(moves[4]==0){
        Menu3();
    }
    else{
        arr[moves[4]]='X';
        display();
        winChk(a);
    }
    if(a==0){
        scanf("%d",&moves[5]);
        if(moves[5]==0){
        Menu3();
        }
        else{

        }
        arr[moves[5]]='O';
        display();
        winChk(a);
        if(a==0){
            scanf("%d",&moves[6]);
            if(moves[6]==0){
                Menu3();
            }
            else{
                arr[moves[6]]='X';
            display();
            winChk(a);
            if(a==0){
                scanf("%d",&moves[7]);
                if(moves[7]==0){
                    Menu3();
                }
                else{
                    arr[moves[7]]='O';
                display();
                winChk(a);
                if(a==0){
                    scanf("%d",&moves[8]);
                    if(moves[8]==0){
                        Menu3();
                    }
                    else{
                        arr[moves[8]]='X';
                    display();
                    winChk(a);
                    if(a==0){
                        system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   DRAWN\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                HvH();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
                    }
                    }
                }
                }
            }
            }
        }
    }

    }
void HvC(){
    system("cls");
    system("color E0");
    int chs;
    printf("\n\t   >----------------------------------------<< OPTIONS >>-----------------------------------------<\n\n\n\n");
    design02();
    printf("\n\n\n\n\t   >>----< 1 >----<< EASY >>---<\n");
    printf("\n\t   >>----< 2 >----<< HARD >>---<\n");
    printf("\n\t   >>----< 3 >----<< HOME >>---<\n");
    printf("\n\t   >>----< 0 >----<< EXIT >>---<\n");
    printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
    scanf("%d",&chs);
    if(chs==2){
        display();
        Hard();
    }
    else if(chs==1){
        Easy();
    }
    else if(chs==3){
        Home();
    }
    else if(chs==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
}
void Easy(){
    int g;
    display();
    int a=0;
    scanf("%d",&moves[0]);
    if(moves[0]==0){
        Menu2();
    }
    else{
        arr[moves[0]]='X';
        display();

        CellFill();
    }

    scanf("%d",&moves[2]);
    if(moves[2]==0){
        Menu2();
    }
    else{
        arr[moves[2]]='X';
        display();

        CellFill();
    }

    scanf("%d",&moves[4]);
    if(moves[4]==0){
        Menu2();
    }
    else{
        arr[moves[4]]='X';
        display();

        winChk02(a);
    }
    if(a==0){
        CellFill();

        winChk02(a);
        if(a==0){
            scanf("%d",&moves[6]);
            if(moves[6]==0){
                Menu2();
            }
            else{
                arr[moves[6]]='X';
                display();

                winChk02(a);
                if(a==0){
                    CellFill();

                    winChk02(a);
                    if(a==0){
                        scanf("%d",&moves[8]);
                        if(moves[8]==0){
                            Menu2();
                        }
                        else{
                            arr[moves[8]]='X';
                            display();
                            winChk02(a);
                            if(a==0){
                            system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   DRAWN\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Easy();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
                        }
                        }

                }
            }
            }
        }
    }
}
void Hard(){
    int g;
    int x=0;
    int y=0;
    display();
//**MOVE 1 FOR PLAYER ->> (out of 5)
    compMove01();
//**MOVE 2 FOR PLAYER ->>
    compMove02();
//**MOVE 3 FOR PLAYER ->>
    compMove03(x);
//**MOVE 4 FOR PLAYER ->>
    if(x==0){
        compMove04(y);
    }
    //winCheck();
    if(y==0){
        humanMove05();
        system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   DRAWN\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                noBlock=0;
                Hard();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                noBlock=0;
                Home();
            }else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
    }
//**MOVE 5 FOR PLAYER ->>

}
void compMove01(){
    scanf("%d",&Move[0]);
    if(Move[0]==0){
        Menu1();
    }
    else{
        arr[Move[0]]='X';
        display();

//**MOVE 1 FOR COMPUTER ->> (out of 4)
        if(Move[0]==5){
        arr[9]='O';
        display();
        }
        else {
        arr[5]='O';
        display();
        }
    }

}
void compMove02(){
    scanf("%d",&Move[1]);
    if(Move[1]==0){
        Menu1();
    }
    else{
        arr[Move[1]]='X';
        display();

//**MOVE 2 FOR COMPUTER ->>
        if(arr[5]=='X'&&arr[1]=='X'){
            arr[3]='O';
            display();
        }
        else if(arr[1]=='X'&&arr[9]=='X'){
            arr[6]='O';
            display();
        }
        else if(arr[1]=='X'&&arr[8]=='X'){
            arr[7]='O';
            display();
        }
        else if(arr[1]=='X'&&arr[6]=='X'){
            arr[3]='O';
            display();
        }
        else if(arr[3]=='X'&&arr[7]=='X'){
            arr[4]='O';
            display();
        }
        else if(arr[3]=='X'&&arr[8]=='X'){
            arr[9]='O';
            display();
        }
        else if(arr[3]=='X'&&arr[4]=='X'){
            arr[1]='O';
            display();
        }
        else if(arr[7]=='X'&&arr[2]=='X'){
            arr[1]='O';
            display();
        }
        else if(arr[7]=='X'&&arr[6]=='X'){
            arr[9]='O';
            display();
        }
        else if(arr[9]=='X'&&arr[4]=='X'){
            arr[7]='O';
            display();
        }
        else if(arr[9]=='X'&&arr[2]=='X'){
            arr[3]='O';
            display();
        }
        else if(arr[2]=='X'&&arr[4]=='X'){
            arr[7]='O';
            display();
        }
        else if(arr[2]=='X'&&arr[6]=='X'){
            arr[1]='O';
            display();
        }
        else if(arr[4]=='X'&&arr[8]=='X'){
            arr[9]='O';
            display();
        }
        else if(arr[6]=='X'&&arr[8]=='X'){
            arr[3]='O';
            display();
        }
        else if (arr[5]=='X'){
            blockMove();

        }
        else{
            blockMove();
        }
    }
}
void compMove03(int X){
    int g;
    scanf("%d",&Move[2]);
    if(Move[2]==0){
        Menu1();
    }
    else{
    arr[Move[2]]='X';
    display();

//**MOVE 3 FOR COMPUTER ->>
    winMove();
        if (won==1){
            system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   COMPUTER WON\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Hard();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
            X=X+1;
        }
        else if(arr[1]=='X'&&arr[8]=='X'&&arr[3]=='X'&&arr[2]==' '){
            arr[2]='O';
            display();
        }
        else if(arr[1]=='X'&&arr[6]=='X'&&arr[7]=='X'&&arr[4]==' '){
            arr[4]='O';
            display();
        }
        else if(arr[3]=='X'&&arr[4]=='X'&&arr[9]=='X'&&arr[6]==' '){
            arr[6]='O';
            display();
        }
        else if(arr[3]=='X'&&arr[8]=='X'&&arr[1]=='X'&&arr[2]==' '){
            arr[2]='O';
            display();
        }
        else if(arr[7]=='X'&&arr[6]=='X'&&arr[1]=='X'&&arr[4]==' '){
            arr[4]='O';
            display();
        }
        else if(arr[7]=='X'&&arr[2]=='X'&&arr[9]=='X'&&arr[8]==' '){
            arr[8]='O';
            display();
        }
        else if(arr[9]=='X'&&arr[4]=='X'&&arr[3]=='X'&&arr[6]==' '){
            arr[6]='O';
            display();
        }
        else if(arr[9]=='X'&&arr[2]=='X'&&arr[7]=='X'&&arr[8]==' '){
            arr[8]='O';
            display();
        }
        else if(arr[1]=='X'&&arr[3]=='X'&&arr[8]=='X'&&arr[4]==' '){
            arr[4]='O';
            display();
        }
        else if(arr[1]=='X'&&arr[7]=='X'&&arr[6]=='X'&&arr[8]==' '){
            arr[8]='O';
            display();
        }
        else if(arr[7]=='X'&&arr[9]=='X'&&arr[2]=='X'&&arr[6]==' '){
            arr[6]='O';
            display();
        }
        else if(arr[9]=='X'&&arr[3]=='X'&&arr[4]=='X'&&arr[2]==' '){
            arr[2]='O';
            display();
        }
        else if(won==0){
            blockMove();
        }

    }
}
void compMove04(int X){
    int g;
    int a=0;
    int f=0;
    scanf("%d",&Move[3]);
    if(Move[3]==0){
        Menu1();
    }
    else{
        arr[Move[3]]='X';
    display();

//**MOVE 4 FOR COMPUTER ->>
    winMove();
    if(won==0){
        X=X+1;
        system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   COMPUTER WON\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Hard();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
    }
    else if(won<0){
        blockMove(a);
        if(noBlock==1){
            CellFill();
            display();
        }
    }

    }

}
void humanMove05(){
    scanf("%d",&Move[5]);
    if(Move[5]==0){
        Menu1();
    }
    else{
        arr[Move[5]]='X';
        display();
    }

}
void blockMove(){
//**First Case>>
    if (arr[1]=='X'&&arr[2]=='X'&&arr[3]==' '){
        arr[3]='O';
        display();
    }
    else if (arr[4]=='X'&&arr[5]=='X'&&arr[6]==' '){
        arr[6]='O';
        display();
    }
    else if (arr[7]=='X'&&arr[8]=='X'&&arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[1]=='X'&&arr[4]=='X'&&arr[7]==' '){
        arr[7]='O';
        display();
    }
    else if (arr[2]=='X'&&arr[5]=='X'&&arr[8]==' '){
        arr[8]='O';
        display();
    }
    else if (arr[3]=='X'&&arr[6]=='X'&&arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[1]=='X'&&arr[5]=='X'&&arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[3]=='X'&&arr[5]=='X'&&arr[7]==' '){
        arr[7]='O';
        display();
    }

//**Second Case>>
    else if (arr[1]=='X'&&arr[2]==' '&&arr[3]=='X'){
        arr[2]='O';
        display();
    }
    else if (arr[4]=='X'&&arr[5]==' '&&arr[6]=='X'){
        arr[5]='O';
        display();
    }
    else if (arr[7]=='X'&&arr[8]==' '&&arr[9]=='X'){
        arr[8]='O';
        display();
    }
    else if (arr[1]=='X'&&arr[4]==' '&&arr[7]=='X'){
        arr[4]='O';
        display();
    }
    else if (arr[2]=='X'&&arr[5]==' '&&arr[8]=='X'){
        arr[5]='O';
        display();
    }
    else if (arr[3]=='X'&&arr[6]==' '&&arr[9]=='X'){
        arr[6]='O';
        display();
    }
    else if (arr[1]=='X'&&arr[5]==' '&&arr[9]=='X'){
        arr[5]='O';
        display();
    }
    else if (arr[3]=='X'&&arr[5]==' '&&arr[7]=='X'){
        arr[5]='O';
        display();
    }

//Third Case>>
    else if (arr[3]=='X'&&arr[2]=='X'&&arr[1]==' '){
        arr[1]='O';
        display();
    }
    else if (arr[6]=='X'&&arr[5]=='X'&&arr[4]==' '){
        arr[4]='O';
        display();
    }
    else if (arr[9]=='X'&&arr[8]=='X'&&arr[7]==' '){
        arr[7]='O';
        display();
    }
    else if (arr[7]=='X'&&arr[4]=='X'&&arr[1]==' '){
        arr[1]='O';
        display();
    }
    else if (arr[8]=='X'&&arr[5]=='X'&&arr[2]==' '){
        arr[2]='O';
        display();
    }
    else if (arr[9]=='X'&&arr[6]=='X'&&arr[3]==' '){
        arr[3]='O';
        display();
    }
    else if (arr[9]=='X'&&arr[5]=='X'&&arr[1]==' '){
        arr[1]='O';
        display();
    }
    else if (arr[7]=='X'&&arr[5]=='X'&&arr[3]==' '){
        arr[3]='O';
        display();
    }
    else {
        noBlock=1;
    }

}
void winMove(){
//**First Case>>
    if (arr[1]=='O'&&arr[2]=='O'&&arr[3]==' '){
        arr[3]='O';
        display();
    }
    else if (arr[4]=='O'&&arr[5]=='O'&&arr[6]==' '){
        arr[6]='O';
        display();
    }
    else if (arr[7]=='O'&&arr[8]=='O'&&arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[1]=='O'&&arr[4]=='O'&&arr[7]==' '){
        arr[7]='O';
        display();
    }
    else if (arr[2]=='O'&&arr[5]=='O'&&arr[8]==' '){
        arr[8]='O';
        display();
    }
    else if (arr[3]=='O'&&arr[6]=='O'&&arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[1]=='O'&&arr[5]=='O'&&arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[3]=='O'&&arr[5]=='O'&&arr[7]==' '){
        arr[7]='O';
        display();
    }

//**Second Case>>
    else if (arr[1]=='O'&&arr[2]==' '&&arr[3]=='O'){
        arr[2]='O';
        display();
    }
    else if (arr[4]=='O'&&arr[5]==' '&&arr[6]=='O'){
        arr[5]='O';
        display();
    }
    else if (arr[7]=='O'&&arr[8]==' '&&arr[9]=='O'){
        arr[8]='O';
        display();
    }
    else if (arr[1]=='O'&&arr[4]==' '&&arr[7]=='O'){
        arr[4]='O';
        display();
    }
    else if (arr[2]=='O'&&arr[5]==' '&&arr[8]=='O'){
        arr[5]='O';
        display();
    }
    else if (arr[3]=='O'&&arr[6]==' '&&arr[9]=='O'){
        arr[6]='O';
        display();
    }
    else if (arr[1]=='O'&&arr[5]==' '&&arr[9]=='O'){
        arr[5]='O';
        display();
    }
    else if (arr[3]=='O'&&arr[5]==' '&&arr[7]=='O'){
        arr[5]='O';
        display();
    }

//Third Case>>
    else if (arr[3]=='O'&&arr[2]=='O'&&arr[1]==' '){
        arr[1]='O';
        display();
    }
    else if (arr[6]=='O'&&arr[5]=='O'&&arr[4]==' '){
        arr[4]='O';
        display();
    }
    else if (arr[9]=='O'&&arr[8]=='O'&&arr[7]==' '){
        arr[7]='O';
        display();
    }
    else if (arr[7]=='O'&&arr[4]=='O'&&arr[1]==' '){
        arr[1]='O';
        display();
    }
    else if (arr[8]=='O'&&arr[5]=='O'&&arr[2]==' '){
        arr[2]='O';
        display();
    }
    else if (arr[9]=='O'&&arr[6]=='O'&&arr[3]==' '){
        arr[3]='O';
        display();
    }
    else if (arr[9]=='O'&&arr[5]=='O'&&arr[1]==' '){
        arr[1]='O';
        display();
    }
    else if (arr[7]=='O'&&arr[5]=='O'&&arr[3]==' '){
        arr[3]='O';
        display();
    }
    else{
        won=won-1;
    }
}
void winChk(int A){
    int g;
    if(arr[1]=='X'&&arr[2]=='X'&&arr[3]=='X'||
       arr[4]=='X'&&arr[5]=='X'&&arr[6]=='X'||
       arr[7]=='X'&&arr[8]=='X'&&arr[9]=='X'||
       arr[1]=='X'&&arr[4]=='X'&&arr[7]=='X'||
       arr[2]=='X'&&arr[5]=='X'&&arr[8]=='X'||
       arr[3]=='X'&&arr[6]=='X'&&arr[9]=='X'||
       arr[1]=='X'&&arr[5]=='X'&&arr[9]=='X'||
       arr[3]=='X'&&arr[5]=='X'&&arr[7]=='X'){
            system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   PLAYER 01 WON\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                HvH();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
            A=A+1;
       }
    else if(arr[1]=='O'&&arr[2]=='O'&&arr[3]=='O'||
       arr[4]=='O'&&arr[5]=='O'&&arr[6]=='O'||
       arr[7]=='O'&&arr[8]=='O'&&arr[9]=='O'||
       arr[1]=='O'&&arr[4]=='O'&&arr[7]=='O'||
       arr[2]=='O'&&arr[5]=='O'&&arr[8]=='O'||
       arr[3]=='O'&&arr[6]=='O'&&arr[9]=='O'||
       arr[1]=='O'&&arr[5]=='O'&&arr[9]=='O'||
       arr[3]=='O'&&arr[5]=='O'&&arr[7]=='O'){
            system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   PLAYER 02 WON\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                HvH();
            }
            else if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
            A=A+1;
       }
}
void winChk02(int A){
    int g;
    if(arr[1]=='X'&&arr[2]=='X'&&arr[3]=='X'||
       arr[4]=='X'&&arr[5]=='X'&&arr[6]=='X'||
       arr[7]=='X'&&arr[8]=='X'&&arr[9]=='X'||
       arr[1]=='X'&&arr[4]=='X'&&arr[7]=='X'||
       arr[2]=='X'&&arr[5]=='X'&&arr[8]=='X'||
       arr[3]=='X'&&arr[6]=='X'&&arr[9]=='X'||
       arr[1]=='X'&&arr[5]=='X'&&arr[9]=='X'||
       arr[3]=='X'&&arr[5]=='X'&&arr[7]=='X'){
            system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   YOU WON\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Easy();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
            A=A+1;
       }
    else if(arr[1]=='O'&&arr[2]=='O'&&arr[3]=='O'||
       arr[4]=='O'&&arr[5]=='O'&&arr[6]=='O'||
       arr[7]=='O'&&arr[8]=='O'&&arr[9]=='O'||
       arr[1]=='O'&&arr[4]=='O'&&arr[7]=='O'||
       arr[2]=='O'&&arr[5]=='O'&&arr[8]=='O'||
       arr[3]=='O'&&arr[6]=='O'&&arr[9]=='O'||
       arr[1]=='O'&&arr[5]=='O'&&arr[9]=='O'||
       arr[3]=='O'&&arr[5]=='O'&&arr[7]=='O'){
            system("cls");
            printf("\n\t   >-----------------------------------------<< RESULT >>------------------------------------------<\n\n");
            printf("\n\n\t   COMPUTER WON\n");
            printf("\n\n\t\t\t    %c | %c | %c\n", arr[1], arr[2], arr[3]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[4], arr[5], arr[6]);
            printf("\t\t\t   ---+---+---\n");
            printf("\t\t\t    %c | %c | %c\n", arr[7], arr[8], arr[9]);
            printf("\n\n\n\n\t   >>----< 1 >----<< RESTART >>--<\n");
            printf("\n\t   >>----< 2 >----<< HOME >>-----<\n");
            printf("\n\t   >>----< 0 >----<< EXIT >>-----<\n");
            printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
            scanf("%d",&g);
            if (g==1){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Easy();
            }
            else if (g==2){
                for(int i=1;i<10;i++){
                    arr[i]=' ';
                }
                won=1;
                Home();
            }
            else if(g==0){
                system("cls");
                system("color B0");
                printf("\n\t   >----------------------------------<< A SIMPLE PAPER GAME >>----------------------------------<\n\n\n");
                design02();
                printf("\n\n\t   THANKS FOR PLAYING.");
                printf("\n\n\t   >-----------------------------------------<<<<<+>>>>>------------------------------------------<\n\n");
                exit(1);
            }
            A=A+1;
       }
}
void CellFill(){
    if (arr[5]==' '){
        arr[5]='O';
        display();
    }
    else if (arr[3]==' '){
        arr[3]='O';
        display();
    }
    else if (arr[8]==' '){
        arr[8]='O';
        display();
    }
    else if (arr[9]==' '){
        arr[9]='O';
        display();
    }
    else if (arr[2]==' '){
        arr[2]='O';
        display();
    }
    else if (arr[6]==' '){
        arr[6]='O';
        display();
    }
    else if (arr[4]==' '){
        arr[4]='O';
        display();
    }
    else if (arr[7]==' '){
        arr[7]='O';
        display();
    }
    else if (arr[1]==' '){
        arr[1]='O';
        display();
    }
}
void design01(){
    system("color E0");
    printf("\n\t   >-----------------------------------------<< HOME >>------------------------------------------<\n\n");
    printf("\t                           ______               \t\n");
    printf("\t   _________        .------------------.        \n");
    printf("\t  :______.-':      :  .--------------.  :       \t\t            ////^\\\\\\\\\n");
    printf("\t  | ______  |      | :                : |       \t\t            | ^   ^ |\n");
    printf("\t  |:______B:|      | |  Little Error: | |       \t\t           @ (o) (o) @\n");
    printf("\t  |:______B:|      | |                | |       \t\t            |   <   |\n");
    printf("\t  |:______B:|      | |  Power not     | |       \t\t            |  ___  |\n");
    printf("\t  |         |      | |  found.        | |       \t\t             \\_____\/\n");
    printf("\t  |:_____:  |      | |                | |       \t\t           ____|  |____\n");
    printf("\t  |    ==   |      | :                : |       \t\t          /    \\__/    \\\n");
    printf("\t  |       O |       ' '--------------' '        \t\t         /              \\\n");
    printf("\t  |       O |        ''--------------''         \t\t        /\\_/|        |\\_/\\\n");
    printf("\t  |       o |-._.-____/'            '\\._        \t\t       / /  |REFAYTH!|  \\ \\\n");
    printf("\t  |'-.____o_|   '-.   '-...______...-'  `-.     \t\t      ( <   |        |   > )\ \n");
    printf("\t  :_________:      `.____________________   `-.___.-.\t\t       \\ \\  |        |  / /\ \n");
    printf("\t                   .'.eeeeeeeeeeeeeeeeee.'.      :___:\t\t        \\ \\ |________| / / \n");
    printf("\t      fsc        .'.eeeeeeeeeeeeeeeeeeeeee.'. \t\t\t\t \\ \\| \n");
    printf("\t                :____________________________:\n");
    printf("\n");
    printf("\n\n\t   >--< 1 >--<< PLAY AGAINST COMPUTER >>---------<+>----------");
    printf("<< PLAY WITH A FRIEND >>--< 2 >--<\n\n");
    printf("\n\t   >-----------------------------------------<<<<<+>>>>>---------------------------------------<\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t      < 0 > EXIT\n");
}
void design02(){
    printf("\t\t\t\t\t\t      T | I | C\n");
    printf("\t\t\t\t\t\t     ---+---+---\n");
    printf("\t\t\t\t\t\t      T | A | C\n");
    printf("\t\t\t\t\t\t     ---+---+---\n");
    printf("\t\t\t\t\t\t      T | O | E\n");
}
