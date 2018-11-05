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

 bool is_piece(struct ChessPiece pc, enum Color color, enum PieceType type)
 {
   return pc.color == color && pc.type == type;
 }
 void init_chess_board(ChessBoard chess_board)
 {
   for (int i = 0; i < 8; i++) {
     for (int j = 0; j < 8; j++) {
       chess_board[i][j].is_occupied = false;
       chess_board[i][j].piece.type = NoPiece;
     }
   }
 }
 struct ChessSquare* get_square (ChessBoard chess_board, File file, Rank rank)
 {
   if((file > 'h' || file < 'a') || (rank > 8 || rank < 1))
   {
     return 0;
   }
   return &chess_board[rank-1][file-97];
 }
 bool is_square_occupied(ChessBoard chess_board, File file, Rank rank)
 {
   int int_file = file - 97;
   return chess_board[rank-1][int_file].is_occupied;
 }
 bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
 {
   int int_file = file - 97;
   if((file > 'h' || file < 'a') || (rank > 8 || rank < 1) || chess_board[rank-1][int_file].is_occupied)
   {
     return false;
   }
   chess_board[rank-1][int_file].is_occupied = true;
   chess_board[rank-1][int_file].piece = piece;
   return true;
 }
 struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank)
 {
   int int_file = file - 97;
   if(((file > 'h' || file < 'a') || (rank > 8 || rank < 1)) || chess_board[rank-1][int_file].is_occupied == false)
   {
     chess_board[rank-1][int_file].piece.type = NoPiece;
     return chess_board[rank-1][int_file].piece;
   }
   return chess_board[rank-1][file-97].piece;
 }
 void setup_chess_board(ChessBoard chess_board)
 {
   File file;
   init_chess_board(chess_board);
   for (file = 'a'; file <= 'h'; file++) {
 		add_piece(chess_board, file, 2, {White,Pawn});
 		add_piece(chess_board, file, 7, {Black, Pawn});
 	}
   add_piece(chess_board, 'a', 1, {White, Rook});
   add_piece(chess_board, 'h', 1, {White, Rook});
   add_piece(chess_board, 'b', 1, {White, Knight});
   add_piece(chess_board, 'g', 1, {White, Knight});
   add_piece(chess_board, 'c', 1, {White, Bishop});
 	 add_piece(chess_board, 'f', 1, {White, Bishop});
 	 add_piece(chess_board, 'd', 1, {White, Queen});
 	 add_piece(chess_board, 'e', 1, {White, King});
 	 add_piece(chess_board, 'a', 8, {Black, Rook});
 	 add_piece(chess_board, 'h', 8, {Black, Rook});
 	 add_piece(chess_board, 'b', 8, {Black, Knight});
   add_piece(chess_board, 'g', 8, {Black, Knight});
   add_piece(chess_board, 'c', 8, {Black, Bishop});
 	 add_piece(chess_board, 'f', 8, {Black, Bishop});
 	 add_piece(chess_board, 'd', 8, {Black, Queen});
 	 add_piece(chess_board, 'e', 8, {Black, King});
 }
 bool remove_piece(ChessBoard chess_board, File file, Rank rank)
 {
   int int_file = file - 97;
   if(((file > 'h' || file < 'a') || (rank > 8 || rank < 1)) || chess_board[rank-1][int_file].is_occupied == false)
   {
     return false;
   }
   chess_board[rank-1][int_file].is_occupied = false;
   chess_board[rank-1][int_file].piece.type = NoPiece;
   return true;
 }
 bool squares_share_file(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   if((s1_f > 'h' || s1_f < 'a') || (s2_f > 'h' || s2_f < 'a') || (s1_r > 8 || s1_r < 1) || (s2_r > 8 || s2_r < 1))
   {
     return false;
   }
   return (s1_f == s2_f);
 }
 bool squares_share_rank(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   if((s1_f > 'h' || s1_f < 'a') || (s2_f > 'h' || s2_f < 'a') || (s1_r > 8 || s1_r < 1) || (s2_r > 8 || s2_r < 1))
   {
     return false;
   }
   return (s1_r == s2_r);
 }
 bool squares_share_diagonal(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   if((s1_f > 'h' || s1_f < 'a') || (s2_f > 'h' || s2_f < 'a') || (s1_r > 8 || s1_r < 1) || (s2_r > 8 || s2_r < 1))
   {
     return false;
   }
   return (s1_f - s2_f == s1_r - s2_r || s2_f - s1_f == s2_r - s1_r || s2_f - s1_f == s1_r - s2_r);
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
