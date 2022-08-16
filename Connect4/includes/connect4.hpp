#ifndef CONNECT_4_HPP
#define CONNECT_4_HPP
#include <iostream>
#include <string>
#include <vector>
std::vector<std::vector<std::string>> GetEmptyBoard(int width, int height); //Creates empty board prints the contents and returns it in a 2d vector 
void UpdateBoard(std::vector<std::vector<std::string>>& board, std::string player, std::vector<int>&heights, int slot);
void UpdatePlayer(std::string& player);
char CheckHoz(std::vector<std::vector<std::string>>& board);
char CheckVert(std::vector<std::vector<std::string>>& board);
char CheckRightDiag(std::vector<std::vector<std::string>>& board);
char CheckLeftDiag(std::vector<std::vector<std::string>>& board);

#endif