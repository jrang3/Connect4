#include "connect4.hpp"
int main() {
    std::string input;
    std::cout<<"Hello There. Do you want to play connect4? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n") {
        std::cout<<"Invalid Answer! Enter y for yes or n for no ";
        std::cin>>input;
    }
    while (input == "y") {
        int width;
        std::cout<<"What board width do you want to use? Enter a number greater than or eqaul to 4. ";
        std::cin>>width;
        while(width < 4) {
            std::cout<<"Error! Enter a number greater than or equal to 4! ";
            std::cin>>width;
        }
        int height;
        std::cout<<"What board height do you want to use? Enter a number greater than or eqaul to 4. ";
        std::cin>>height;
        while(height < 4) {
            std::cout<<"Error! Enter a number greater than or equal to 4! ";
            std::cin>>height;
        }
        std::cout<<" ";
        std::vector<std::vector<std::string>> board = GetEmptyBoard(width, height);
        int count = 0;
        std::string player = "X";
        std::vector<int>heights;
            for (int x = 0; x < width; x++) {
                heights.push_back(height - 1);
        }
        bool game = false;
        while(count < width * height) {
            int slot;
            std::cout<<"It's "<<player<<"'s turn. Choose a slot from 1 through "<<width<<" ";
            std::cin>>slot;
            while((slot < 1 || slot > width || heights.at(slot - 1) < 0)) { //Make sure that the user enters a slot within the boundaries as well as in a col where not all rows are full
                if (slot < 1 || slot > width) {
                    std::cout<<"Invalid Slot! Choose a slot from 1 through "<<width<<" ";
                    std::cin>>slot;
                }
                else if (heights.at(slot - 1) < 0) {
                    std::cout<<"All the rows in that slot have been filled up! Choose a different slot ";
                    std::cin>>slot;
                }
                else {
                    count = width * height;
                }
            }
            UpdateBoard(board, player, heights, slot);
            UpdatePlayer(player);
            if (CheckHoz(board) == 'X' || CheckVert(board) == 'X' || CheckRightDiag(board) == 'X' || CheckLeftDiag(board) == 'X') { //left diag is causing an error 
                std::cout<<"Game Over! The winner of this game is player X "<<std::endl;
                count = width * height;
                game = true;
            }
            else if (CheckHoz(board) == 'O' || CheckVert(board) == 'O' || CheckRightDiag(board) == 'O' || CheckLeftDiag(board) == 'X') {
                std::cout<<"Game Over! The winner of this game is player O " <<std::endl;
                count = width * height;
                game = true;
            }
            count++;
        }
        if (!game)  { //game only changes to true if a player won, so if nobody wins then then game remains false
            std::cout<<"Game Over! There's a tie! "<<std::endl;
        }
        std::cout<<"Do you want to play again? (y/n) ";
        std::cin>>input;
        while(input != "y" && input != "n") {
            std::cout<<"Invalid Answer! Enter y for yes or n for no ";
            std::cin>>input;
        }
    }
    std::cout<<"Goodbye!"<<std::endl;
    


    

}