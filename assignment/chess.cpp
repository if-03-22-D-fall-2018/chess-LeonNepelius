/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
#include <stdlib.h>
#include "general.h"
#include "chess.h"

 int convert_file_to_int(File file)
 {
   char alphabet[8] = {'a','b','c','d','e','f','g','h'};
   for (int i = 0; i < 8; i++) {
     if (file == alphabet[i])
     {
         return i;
     }
   }
   return 0;
 }
 bool is_piece(struct ChessPiece pc, enum Color color, enum PieceType type)
 {
   return pc.color == color && pc.type == type;
 }
 void init_chess_board(ChessBoard chess_board)
 {
   for (int i = 0; i < 8; i++) {
     for (int j = 0; j < 8; j++) {
       chess_board[i][j].is_occupied = false;
       chess_board[i][j].piece = {White,NoPiece};
     }
   }
 }
 struct ChessSquare* get_square (ChessBoard chess_board, File file, Rank rank)
 {
   int int_file;
   int_file = convert_file_to_int(file);
   if((file > 'h' || file < 'a') || (rank > 8 || rank < 1))
   {
     return 0;
   }
   return &chess_board[int_file][rank];
 }
 bool is_square_occupied(ChessBoard chess_board, int file, Rank rank)
 {
   return chess_board[file][rank].is_occupied == true;
 }
 bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
 {
   int int_file;
   int_file = convert_file_to_int(file);
   if((file > 'h' || file < 'a') || (rank > 8 || rank < 1))
   {
     return false;
   }
   chess_board[int_file][rank].piece = piece;
   return true;
 }
 struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank)
 {
   int int_file;
   int_file = convert_file_to_int(file);
   if(((file > 'h' || file < 'a') || (rank > 8 || rank < 1)) || chess_board[rank][int_file].is_occupied == true)
   {
     chess_board[int_file][rank].piece.type = NoPiece;
     return chess_board[int_file][rank].piece;
   }
   return chess_board[int_file][rank].piece;
 }
 void setup_chess_board(ChessBoard chess_board)
 {
   init_chess_board(chess_board);
   //Continue with the beginning positions
 }
 bool remove_piece(ChessBoard chess_board, File file, Rank rank)
 {
   int int_file;
   int_file = convert_file_to_int(file);
   if(((file > 'h' || file < 'a') || (rank > 8 || rank < 1)) || chess_board[rank][int_file].is_occupied == false)
   {
     return false;
   }
   chess_board[int_file][rank].piece.type = NoPiece;
   return true;
 }
 bool squares_share_file(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool squares_share_rank(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool squares_share_diagonal(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool squares_share_knights_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool squares_share_pawns_move(enum Color color, enum Move move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool squares_share_queens_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool squares_share_kings_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
