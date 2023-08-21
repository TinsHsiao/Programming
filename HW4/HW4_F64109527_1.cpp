# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <stdio.h>
# include <windows.h>
using namespace std ;

char game[3][3] ;

void perface() {
	cout << "<<<<<<<<<<<<<<<遊戲說明>>>>>>>>>>>>>>>" << endl ;
	cout << "此遊戲為井字遊戲，俗稱圈圈叉叉" << endl ;
	cout << "玩家A 對應>>>>>符號O" << endl ;
	cout << "玩家B 對應>>>>>符號X" << endl ;
	cout << "請輸入欲填入座標" << endl ;
	cout << "您所輸入第一個數字為 >> 列 << " << endl ; 
	cout << "您所輸入第二個數字為 >> 行 << " << endl ; 
	cout << "範例 : " << endl ;
	cout << "使用者輸入座標 : 1 3 " << endl ;
	cout << " _ _ @ " << endl ;
	cout << " _ _ _ " << endl ;
	cout << " _ _ _ " << endl ;
	cout << endl << " @ 為目標所在" << endl ;
	
	cout << endl << "規則 : " << endl ; 
	cout << "當一符號以斜、橫、直的方式連成一直線，即為一方獲勝" << endl ;
	cout << "範例一   範例二  範例三" << endl ; 
	cout << " _ _ O   O O O   O _ _ " << endl ;
	cout << " _ O _   _ _ _   O _ _ " << endl ;
	cout <<  " O _ _   _ _ _   O _ _ " << endl ;
	cout << endl << "此三種範例皆為玩家A獲勝" << endl ; 
	 
	cout << endl << endl ;
	 
}

void setgame() {
	for ( int i = 0; i < 3; i ++ ) {
		for ( int j = 0; j < 3; j++ ) {
			game[i][j] = '_' ;
		}
	}
} 

bool isTie() {
	for ( int j = 0; j < 3; j ++ ) {
		for ( int i = 0; i < 3; i++ ) {
			if ( game[j][i] == '_' ) {
				return false ;
			}
			
		}
	}
	
	return true ;
}

bool gameover( char & win ) {
	
	for ( int i = 0; i < 3; i++ ) {
		if ( game[i][0] == 'O' && game[i][1] == 'O' && game[i][2] == 'O' ) {
			win = 'O' ;
			return true ;
		}
		
		if ( game[i][0] == 'X' && game[i][1] == 'X' && game[i][2] == 'X' ) {
			win = 'X' ;
			return true ;
		}
	} 
	
	for ( int i = 0; i < 3; i++ ) {
		if ( game[0][i] == 'O' && game[1][i] == 'O' && game[2][i] == 'O' ) {
			win = 'O' ;
			return true ;
		}
		
		if ( game[0][i] == 'X' && game[1][i] == 'X' && game[2][i] == 'X' ) {
			win = 'X' ;
			return true ;
		}
	} 
	
	if ( game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O' ) {
		win = 'O' ;
		return true ;
	}
	
	if ( game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X' ) {
		win = 'X' ;
		return true ;
	}
	
	if ( game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O' ) {
		win = 'O' ;
		return true ;
	}
	
	if ( game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X' ) {
		win = 'X' ;
		return true ;
	}
	
	if ( isTie() ) {
		win = 't' ;
		return true ;
	}
	
	return false ;
}

bool canUse( int j, int i ) {
	if ( i < 1 || i > 3 || j < 1 || j > 3 ) {
		cout << "請輸入座標於1-3間" << endl ; 
		return false ;
	}
	
	else if ( game[j-1][i-1] == '_' ) return true ;
	
	else {
		cout << "此座標已被使用" << endl ;
		return false ;
	}
}

void print() {
	cout << endl << "---遊戲戰況---" << endl ;
	for ( int i = 0; i < 3; i ++ ) {
		for ( int j = 0; j < 3; j++ ) {
			cout << game[i][j] ;
		}
		
		cout << endl ;
	}
	
	cout << endl ;
}

int main() {
	
	char win, again_point ;
	int i, j ;
	bool again = true ;
	perface() ;
	
	do {
		setgame() ;
		cout << "<<<<<<<<<<<<<<<遊戲開始>>>>>>>>>>>>>>>" << endl ;
		while ( !gameover( win ) ) {
			
			if ( !gameover( win ) ) {
				cout << "請使用者A輸入座標" ;
				cin >> j >> i ;
	
				while ( ! canUse( j, i ) ) {
					cout << "請再次輸入 : " ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'O' ;
				print() ;
			}
			
			if ( !gameover( win ) ) {
				cout << "請使用者B輸入座標" ;
				cin >> j >> i ;
				while ( ! canUse( j, i ) ) {
					cout << "請再次輸入 : " ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'X' ;
				print() ;
			}		
			
		}
		
		if ( win == 'O' ) cout << "恭喜玩家A勝利:)" << endl ;
		else if ( win == 'X' ) cout << "恭喜玩家B勝利:)" << endl ;
		else if ( win == 't' ) cout << "平手" << endl ; 
		cout << "想再玩一次請輸入鍵盤p鍵，若欲退出遊戲請輸入任意鍵" << endl ;
		cin >> again_point ;
		if ( again_point == 'p' || again_point == 'P' ) again = true ;
		else again = false ;
	} while ( again ) ;
	
	cout << "Byebye~~~~~~~~~" << endl ;
	system( "pause" ) ;
	
		
}
