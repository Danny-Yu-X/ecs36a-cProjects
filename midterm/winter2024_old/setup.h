#ifndef SETUP_H
    #define SETUP_H
    #include <stdbool.h>
    void setup_game(int dimensions, char blank_space);
    char** make_grid(int dimensions, char blank_space);
    char* pick_player_pieces(char blank_space);
    char pick_piece(char blank_space, char* player_pieces, int num_player_pieces);
    bool is_valid_piece(int num_args_read, char player_piece, char blank_space, char* player_pieces, int num_player_pieces);
    bool is_in(char letter, const char* str, int len);
    int pick_starting_player()

#endif