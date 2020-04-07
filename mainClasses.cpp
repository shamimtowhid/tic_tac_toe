#include<iostream>

class Gameboard{
    char gameSpace[4][4];
    
    public:
        Gameboard();
        void printBoard();
        int setChar(int row, int column, char ch);
        int rowCheck(char to_check);
        int columnCheck(char to_check);
        int diagonalCheck(char to_check);
        int drawCheck();
};

Gameboard::Gameboard(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            gameSpace[i][j]='-';
        }
    }
}

int Gameboard::drawCheck(){
    int count =0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (gameSpace[i][j]=='x' || gameSpace[i][j]=='o'){
                count++;
            }
        }
    }
    if (count == 16){
        return 1;
    }
    return 0;
}

int Gameboard::diagonalCheck(char to_check){
    int count=0,col=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j==i && gameSpace[i][j]==to_check){
                count++;
            }
        }
    }
    if (count==4){
        return 1;
    }
    // 2nd diagonal check
    count = 0;
    for(int i=3;i>=0;i--){
        for(int j=0;j<4;j++){
            if (j==col && gameSpace[i][j]==to_check){
                count++;
            }
        }
        col++;
    }
    if (count==4){
        return 1;
    }
    return 0;
}

int Gameboard::columnCheck(char to_check){
    int count;
    for(int i=0;i<4;i++){
        count=0;
        for(int j=0;j<4;j++){
            if (gameSpace[j][i]==to_check){
                count++;
            }
        }
        if (count == 4){
            return 1;
        }
    }
    return 0;
}

int Gameboard::rowCheck(char to_check){
    int count;
    for(int i=0;i<4;i++){
        count=0;
        for(int j=0;j<4;j++){
            if (gameSpace[i][j]==to_check){
                count++;
            }
        }
        if (count == 4){
            return 1;
        }
    }
    return 0;
}

int Gameboard::setChar(int row, int column, char ch){
    int flag;
    if (gameSpace[row][column]=='-'){
        gameSpace[row][column]=ch;
        flag = 1;
    }
    else{
        flag = 0;
    }
    return flag;
}

void Gameboard::printBoard(){
    std::cout<<"\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<gameSpace[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}
