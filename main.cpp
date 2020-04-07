#include "mainClasses.cpp"
#include "mainFunctions.cpp"

int main(){
    Gameboard board;
    std::string user1,user2;
    getUser(user1);
    getUser(user2);
    printWelcomeMsg(user1,user2);
    int r,c;
    for(;;){
        //1st user move
        std::cout<<"Enter the position for "<<user1;
        getPosition(r,c);
        while(board.setChar(r,c,'x')!=1){
            std::cout<<"\nThat position is already taken out.Please enter a new position";
            getPosition(r,c);
            board.printBoard();
        }
        board.printBoard();
        if (board.rowCheck('x') == 1 || board.columnCheck('x') == 1 || board.diagonalCheck('x') == 1){
            std::cout<<user1<<" wins the game\n";
            break;
        }else if(board.drawCheck()==1){
            std::cout<<"Game is drawn!!Congratulations to both of you.";
            break;
        }
        
        
        // 2nd user move
        std::cout<<"Enter the position for "<<user2;
        getPosition(r,c);
        while(board.setChar(r,c,'o')!=1){
            std::cout<<"\nThat position is already taken out.Please enter a new position";
            getPosition(r,c);
            board.printBoard();
        }
        board.printBoard();
        if (board.rowCheck('o') == 1 || board.columnCheck('o') == 1 || board.diagonalCheck('o') == 1){
            std::cout<<user2<<" wins the game\n";
            break;
        }else if(board.drawCheck()==1){
            std::cout<<"Game is drawn!!Congratulations to both of you.";
            break;
        }
    }
    return 0;
}
