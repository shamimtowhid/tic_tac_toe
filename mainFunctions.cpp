#include<iostream>
#include<string>

int charCheck(char ch);
void getUser(std::string &user);
void printWelcomeMsg(std::string user1, std::string user2);
void getPosition(int &row,int &col);

void getPosition(int &row,int &col){
    std::cin>>row;
    std::cin>>col;
}

void getUser(std::string &user){
    //std::cout<<"Please enter the user name:";
    std::getline(std::cin,user);
}

int charCheck(char ch){
    if (ch == 'x' || ch == 'o'){
        return 1;
    }
    return 0;
}



void printWelcomeMsg(std::string user1, std::string user2){
    std::cout<<"Welcome "<<user1<<" and "<<user2<<" to this game!!";
}

