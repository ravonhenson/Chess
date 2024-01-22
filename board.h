//
// Created by Ravon Henson on 1/15/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#import <iostream>
#import <vector>

#define ROWS 8
#define COLUMNS 8

std::vector<std::string> splitString(const std::string& str, char delimiter);

class Board {

public:
    std::string defaultFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

private:
    char m_board[ROWS][COLUMNS];

public:
    Board() {
        loadFEN(defaultFEN);
    }

    Board(std::string FEN) {
        loadFEN(FEN);
    }

    // can optimize this code heavily but works for now
    void loadFEN(std::string FEN) {
       std::vector<std::string> rows = splitString(FEN, '/');
       for (int row = 0; row < rows.size(); row++) {
           std::string string_row = rows.at(row);
           int col = 0;
           for (const auto& piece : string_row) {
               int num = piece - 48;
               if (num >= 1 && num <= 8) {
                   int final = col + num;
                   while (col < final) {
                     m_board[row][col] = '_';
                     col++;
                   }
               }
               else {
                   m_board[row][col] = piece;
                   col++;
               }
               std::cout << std::endl;
           }

       }

    }

    void displayBoard() {
        for (int row = 0; row < ROWS; row++) {
            for (int column = 0; column < COLUMNS; column++) {
                std::cout << m_board[row][column] << " ";
            }
            std::cout << std::endl;
        }
    }

};

// board utility functions
inline std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> split;
    std::size_t start = 0, end;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        split.push_back(str.substr(start, end-start));
        start = end + 1;
    }
    split.push_back(str.substr(start));

    return split;
}

inline void displayStringVector(const std::vector<std::string>& stringVector) {
    for (const std::string& element : stringVector) {
        std::cout << element << std::endl;
    }
}

#endif //CHESS_BOARD_H
