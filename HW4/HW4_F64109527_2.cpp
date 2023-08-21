# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <stdio.h>
# include <windows.h>
using namespace std ;

char game[15][15] ;

void perface() {
	cout << "<<<<<<<<<<<<<<<遊戲說明>>>>>>>>>>>>>>>" << endl ;
	cout << "此遊戲為五子棋遊戲" << endl ;
	cout << "玩家A 對應>>>>>符號O" << endl ;
	cout << "玩家B 對應>>>>>符號X" << endl ;
	cout << "請輸入欲填入座標，範圍為1-15" << endl ;
	cout << "您所輸入第一個數字為 >> 列 << " << endl ; 
	cout << "您所輸入第二個數字為 >> 行 << " << endl ; 
	cout << "棋盤樣式以.符號表示為空白處 可落子" << endl ;
	cout << "範例 : " << endl ;
	cout << "請玩家輸入座標 : 2 3" << endl ;
	cout << "..............." << endl ;
	cout << "..O............" << endl ;
	for ( int i = 2; i < 15; i ++ ) 
		cout << "..............." << endl ;
	
	cout << endl << "規則 : " << endl ; 
	cout << "斜、橫、直的方式連續五個相同的子連接，即為一方獲勝" << endl ;
	cout << "範例" << endl ; 
	cout << ".....O..X......" << endl ;
	cout << "......OXX......" << endl ;
	cout << ".......OX......" << endl ;
	cout << "........O......" << endl ;
	cout << ".........O....." << endl ;
	for ( int i = 5; i < 15; i ++ ) 
		cout << "..............." << endl ;
		
	cout << endl << "此種範例為玩家A獲勝" << endl ; 
	 
	cout << endl << endl ;
	 
}

void setgame() {
	for ( int i = 0; i < 15; i ++ ) {
		for ( int j = 0; j < 15; j++ ) {
			game[i][j] = '.' ;
		}
	}
} 

bool in_range( int i, int j ) {
	if ( ( i >= 0 && i <= 14 ) && ( j >= 0 && j <= 14 ) ) return true ;
	else return false ;
}

bool isTie() {
	for ( int i = 0; i < 15; i ++ ) {
		for ( int j = 0; j < 15; j++ ) {
			if ( game[i][j] == '.' ) {
				return false ;
			}
			
		}
	}
	
	return true ;
}

bool hori_line( char c, int i, int j ) {
	int connect = 0;
	int x = i, y = j ;
	while ( game[y][x] == c && in_range( x, y ) ) {

		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x ++ ;
	}
	
	x = i - 1 ;
	y = j ;
	while ( game[y][x] == c && in_range( x, y ) ) {
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x -- ;
	}
	
	// cout << connect ;
	if ( connect >= 5 ) return true ;
	else return false ;
	
}

bool verti_line( char c, int i, int j ) {
	int connect = 0;
	int x = i, y = j ;

	while ( game[y][x] == c && in_range( x, y ) ) {
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		y ++ ;
	}
	
	x = i ;
	y = j - 1 ;
	while ( game[y][x] == c && in_range( x, y ) ) {
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		y -- ;
	}
	// cout << connect ;
	if ( connect >= 5 ) return true ;
	else return false ;
	
}

bool obi_left_up_line( char c, int i, int j ) {
	int connect = 0;
	int x = i, y = j ;
	while ( game[y][x] == c && in_range( x, y ) ) {
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x ++ ;
		y ++ ;
	}
	
	x = i - 1 ;
	y = j - 1 ;
	while ( game[y][x] == c && in_range( x, y ) ) {
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x -- ;
		y -- ;
	}
	// cout << connect ;
	if ( connect >= 5 ) return true ;
	else return false ;
	
}

bool obi_right_up_line( char c, int i, int j ) {
	int connect = 0;
	int x = i, y = j ;
	while ( game[y][x] == c && in_range( x, y ) ) { // 左下方 
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x -- ;
		y ++ ;
	}
	
	x = i + 1 ;
	y = j - 1 ;
	while ( game[y][x] == c && in_range( x, y ) ) { // 右上方 
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x ++ ;
		y -- ;
	}
	// cout << connect ;
	if ( connect >= 5 ) return true ;
	else return false ;
	
}

bool gameover( char & c, int i, int j ) {

	if ( hori_line( c, i-1, j-1 ) || verti_line( c, i-1, j-1 ) || 
		obi_left_up_line( c, i-1, j-1 ) || obi_right_up_line( c, i-1, j-1 ) ) 
		return true ;
	else if ( isTie() ) {
		c = 't' ;
		return true ;
	}
	
	else return false ;
}


bool canUse( int i, int j ) {
	if ( i < 1 || i > 15 || j < 1 || j > 15 ) {
		cout << "請輸入座標於1-15間" << endl ; 
		return false ;
	}
	
	else if ( game[j-1][i-1] == '.' ) return true ;
	
	else {
		cout << "此座標已被使用" << endl ;
		return false ;
	}
}

void print() {

	for ( int i = 0; i < 15; i ++ ) {
		for ( int j = 0; j < 15; j++ ) {
			cout << game[i][j] ;
		}
		
		cout << endl ;
	}
	
	cout << endl ;
}

int main() {
	char win, again_point ;
	bool again = true ;
	int i, j ;
	perface() ;
	do {
		setgame() ;
		cout << "<<<<<<<<<<<<<<<遊戲開始>>>>>>>>>>>>>>>" << endl ;
		while ( !gameover( win, i, j ) ) {
			
			if ( !gameover( win, i, j ) ) {
				cout << "請玩家A輸入座標 :" ;
				cin >> j >> i ;
	
				while ( ! canUse( i, j ) ) {
					cout << "請再次輸入 : " << endl ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'O' ;
				win = 'O' ;
				print() ;
			}
			
			if ( !gameover( win, i, j ) ) {
				cout << "請玩家B輸入座標 :" ;
				cin >> j >> i ;
				while ( ! canUse( i, j ) ) {
					cout << "請再次輸入 : " ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'X' ;
				win = 'X' ;
				print() ;
			}		
			
		}
		
		if ( win == 'O' ) cout << "恭喜 玩家A勝利" << endl ;
		else if ( win == 'X' ) cout << "恭喜 玩家B勝利" << endl ;
		else if ( win == 't' ) cout << "平手" << endl ; 
		cout << endl << "想再玩一次請輸入鍵盤p鍵，若欲退出遊戲請輸入任意鍵" << endl ;
		cin >> again_point ;
		if ( again_point == 'p' || again_point == 'P' ) again = true ;
		else again = false ;
		
	} while( again ) ; 
	
	cout << "Byebye~~~~~~~~~" << endl ;
	system( "pause" ) ;
	
}
