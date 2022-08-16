#include "connect4.hpp"
std::vector<std::vector<std::string>> GetEmptyBoard(int width, int height) {
    for (int x = 1; x <= width; x++) { //Starting Line Where Board is Created
            std::cout<<x<< "   ";
        }
        std::vector<std::vector<std::string>>board;
        std::vector<std::string>one_d_board;
        std::cout<<"\n";
        for (int c = 0; c < width; c++) {
            one_d_board.push_back("[ ]");
            
        }
        for (int r = 0; r < height; r++) {
            board.push_back(one_d_board);
            
        }
        for (std::vector<std::string> one_d_board : board) { //Empty board gets displayed here 
            for (std::string s: one_d_board) {
                std::cout<<s<<" ";
            }
            std::cout<<"\n";
        }
        return board;
}
void UpdateBoard(std::vector<std::vector<std::string>>& board, std::string player, std::vector<int>& heights, int slot) {
    if (player == "X") { //Used to update board as well as height for given col 
        board.at(heights.at(slot-1)).at(slot - 1) = "[X]";
        heights.at(slot-1) -= 1;
    }
    else {
        board.at(heights.at(slot-1)).at(slot - 1) = "[O]";
        heights.at(slot-1) -= 1;
    }
    std::cout<<"\n";
    std::cout<<" ";
    for (int x = 1; x <= heights.size(); x++) { //prints board positions
        std::cout<<x<< "   ";
    }
    std::cout<<"\n";
    for (std::vector<std::string> one_d_board : board) { //prints the actual contents of the board
        for (std::string s: one_d_board) {
            std::cout<<s<<" ";
        }
        std::cout<<"\n";
    }
}
void UpdatePlayer(std::string& player) {
    if (player == "X") {
        player = "O";
    }
    else {
        player = "X";
    }
}
char CheckHoz(std::vector<std::vector<std::string>>& board) {
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board.at(0).size(); c++) {
            if (c + 3 <  board.at(0).size()) {
                if ((board.at(r).at(c) == "[X]") && (board.at(r).at(c + 1) == "[X]") 
                    && (board.at(r).at(c + 2) == "[X]") && (board.at(r).at(c + 3) == "[X]")) {
                    return 'X';
                }
                if ((board.at(r).at(c) == "[O]") && (board.at(r).at(c + 1) == "[O]") 
                    && (board.at(r).at(c + 2) == "[O]") && (board.at(r).at(c + 3) == "[O]")) {
                    return 'O';
                }
            }
            
        }
    }
    return ' ';
}
char CheckVert(std::vector<std::vector<std::string>>& board) {
    for (int c = 0; c < board.at(0).size(); c++) {
        for (int r = 0; r < board.size(); r++) {
            if (r + 3 <  board.size()) {
                if ((board.at(r).at(c) == "[X]") && (board.at(r + 1).at(c) == "[X]") 
                    && (board.at(r + 2).at(c) == "[X]") && (board.at(r + 3).at(c) == "[X]")) {
                    return 'X';
                }
                if ((board.at(r).at(c) == "[O]") && (board.at(r + 1).at(c) == "[O]") 
                    && (board.at(r + 2).at(c) == "[O]") && (board.at(r + 3).at(c) == "[O]")) {
                    return 'O';
                }
            }
            
        }
    }
    return ' ';

}
char CheckRightDiag(std::vector<std::vector<std::string>>& board) {
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board.at(0).size(); c++) {
            if (c + 3 <  board.at(0).size() && r + 3 < board.size()) {
                if ((board.at(r).at(c) == "[X]") && (board.at(r + 1).at(c + 1) == "[X]") 
                    && (board.at(r + 2).at(c + 2) == "[X]") && (board.at(r + 3).at(c + 3) == "[X]")) {
                    return 'X';
                }
                if ((board.at(r).at(c) == "[O]") && (board.at(r + 1).at(c + 1) == "[O]") 
                    && (board.at(r + 2).at(c + 2) == "[O]") && (board.at(r + 3).at(c + 3) == "[O]")) {
                    return 'O';
                }
            }
        }
    }
    return ' ';
}
char CheckLeftDiag(std::vector<std::vector<std::string>>& board) {
    for (int r = 0; r < board.size(); r++) {
        for (int c = board.at(0).size() - 1; c >= 0; c--) {
            if (c - 3 >=  0 && r + 3 < board.size()) {
                if ((board.at(r).at(c) == "[X]") && (board.at(r + 1).at(c - 1) == "[X]") 
                    && (board.at(r + 2).at(c - 2) == "[X]") && (board.at(r + 3).at(c - 3) == "[X]")) {
                    return 'X';
                }
                if ((board.at(r).at(c) == "[O]") && (board.at(r + 1).at(c - 1) == "[O]") 
                    && (board.at(r + 2).at(c - 2) == "[O]") && (board.at(r + 3).at(c - 3) == "[O]")) {
                    return 'O';
                }
            }
        }
    }
    return ' ';
}

