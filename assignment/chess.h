/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			P. Bauer
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdbool.h>
enum Color {White,Black};
enum PieceType
{
  Pawn,Knight,Rook,Bishop,Queen,King
};

struct ChessPiece
{
  enum Color color;
  enum PieceType type;
};

struct ChessSquare
{
  bool is_occupied;
  struct ChessPiece piece;
};



typedef int Rank;
typedef char File;
typedef ChessSquare ChessBoard[8][8];
typedef ChessSquare Chessboard[8][8];
typedef ChessSquare NormalMove;
typedef ChessSquare NoPiece;

struct ChessPiece get_piece(ChessBoard chess_board, File file , int rank)
{
	ChessSquare type = chess_board[file-'0'][rank];
	return type.piece;
}

bool is_piece(struct ChessPiece board,enum Color color,enum PieceType piece)
{
	return board.type == piece && board.color == color;
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
void setup_chess_board(Chessboard chess_board);

struct ChessSquare* get_square(ChessBoard chess_board,int file,int rank);
bool is_square_occupied(ChessBoard chess_board,char file,int rank);
bool add_piece(ChessBoard chess_board, char file ,int rank,struct ChessPiece piece);
bool remove_piece(ChessBoard chess_board, char Xpos ,int Ypos);
bool is_piece(struct ChessPiece piece, enum Color color ,enum PieceType type);
bool squares_share_rank(char file1,  int rank1, int file2,  char rank2);
bool squares_share_file(char file1,  int rank1, char file2,  int rank2);
bool squares_share_diagonal(char file1,  int rank1, char file2,  int rank2);

bool squares_share_knights_move(char file1, int rank1, char file2,  int rank2);
bool squares_share_kings_move(char file1,  int rank1, char file2,  int rank2);
bool squares_share_pawns_move(enum Color color, NormalMove, char file1,  int rank1, char file2,  int rank2);
bool squares_share_queens_move(char file1,  int rank1, char file2,  int rank2);