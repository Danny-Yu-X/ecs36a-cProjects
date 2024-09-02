#include <stdio.h>
#include <stdbool.h>
#include "setup.h"
#include "input_validation.h"


char** make_grid(int dimensions, char blank_space){
    /*
    Make a N X N empty tic tac toe board
    */
    char** board = (char**)malloc(dimensions * sizeof(char*));
    for(int i = 0; i < dimensions; ++i){
        board[i] = (char*) malloc(dimensions * sizeof(char));
        for(int j = 0; j < dimensions; ++j){
            board[i][j] = blank_space;
        }
    }
    return board;
}

char* pick_player_pieces(char blank_space){
    const int num_players = 2;
    char* player_pieces = (char*)malloc(num_players * sizeof(char));
    for(int i = 0; i < num_players; ++i){
        player_pieces[i] = pick_piece(blank_space, player_pieces, i);
    }
    return player_pieces;
}

char pick_piece(char blank_space, char* player_pieces, int num_player_pieces){
    char player_piece;
    int nar;
    do{
        printf("Player %d please choose your piece: ", num_player_pieces + 1);
        nar = scanf(" %c", &player_piece);
    }while(!is_valid_piece(nar, player_piece, blank_space, player_pieces, num_player_pieces));
    return player_piece;
}


bool is_valid_piece(int num_args_read, char player_piece, char blank_space, char* player_pieces, int num_player_pieces){
    return isValidFormat(num_args_read, 1) && 
            player_piece != blank_space && 
            !is_in(player_piece, player_pieces, num_player_pieces);
}

bool is_in(char letter, const char* str, int len){
    for(int i = 0; i < len; ++i){
        if(str[i] == letter){
            return true;
        }
    }
    return false;
}

void setup_game(int dimensions, char blank_space, char** *out_board, char* *out_player_pieces, int* *out_starting_player){
    srand(3);
    *out_board = make_grid(dimensions, blank_space);
    char* player_pieces = pick_player_pieces(blank_space);
    int starting_player = pick_starting_player();


}

int pick_starting_player(){
    /*
    0 means player 1,
    1 means player 2
    */
    return rand() % 2;
}

