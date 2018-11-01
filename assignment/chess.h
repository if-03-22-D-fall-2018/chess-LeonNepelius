/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			Leon Nepelius
 * Due Date:		November 2, 2018
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdbool.h>
#ifndef ___CHESS_H
#define ___CHESS_H
enum Color {White,Black};
enum PieceType
{
  Pawn,Knight,Rook,Bishop,Queen,King,NoPiece
};
struct ChessPiece
{
  enum Color color;
  enum PieceType type;
};
enum PawnMove
{
	NormalMove,CaptureMove
};
struct ChessSquare
{
  bool is_occupied;
  struct ChessPiece piece;
};



typedef int Rank;
typedef char File;
typedef struct ChessSquare ChessBoard[8][8];


struct ChessPiece get_piece(ChessBoard chess_board, File file , int rank)
{
	ChessSquare type = chess_board[file-'0'][rank];
	return type.piece;
}

bool is_piece(struct ChessPiece piece,enum Color color,enum PieceType type)
{
	return piece.type == type && piece.color == color;
}

void init_chess_board(ChessBoard chess_board)
{
	for(int i=0;i<8;i++)
	{
		for(int j= 0;j<8;j++)
		{
			chess_board[i][j].is_occupied = false;
		}
	}
}
void setup_chess_board(ChessBoard chess_board);

bool is_square_occupied(ChessBoard chess_board,File file,Rank rank);
struct ChessSquare* get_square(ChessBoard chess_board,File file, Rank rank);
bool add_piece(ChessBoard chess_board, File file ,Rank rank,struct ChessPiece piece);
struct ChessPiece get_piece(ChessBoard chess_board, File file ,File rank);
bool remove_piece(ChessBoard chess_board, File file ,Rank rank);

bool squares_share_rank(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_file(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_diagonal(File file1, Rank rank1, File file2, Rank rank2);

bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_kings_move(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_pawns_move(enum Color color,enum PawnMove move, File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_queens_move(File file1, Rank rank1, File file2, Rank rank2);
#endif