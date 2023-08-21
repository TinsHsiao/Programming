# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <stdio.h>
# include <windows.h>
using namespace std ;

char game[3][3] ;

void perface() {
	cout << "<<<<<<<<<<<<<<<�C������>>>>>>>>>>>>>>>" << endl ;
	cout << "���C�������r�C���A�U�ٰ��e�e" << endl ;
	cout << "���aA ����>>>>>�Ÿ�O" << endl ;
	cout << "���aB ����>>>>>�Ÿ�X" << endl ;
	cout << "�п�J����J�y��" << endl ;
	cout << "�z�ҿ�J�Ĥ@�ӼƦr�� >> �C << " << endl ; 
	cout << "�z�ҿ�J�ĤG�ӼƦr�� >> �� << " << endl ; 
	cout << "�d�� : " << endl ;
	cout << "�ϥΪ̿�J�y�� : 1 3 " << endl ;
	cout << " _ _ @ " << endl ;
	cout << " _ _ _ " << endl ;
	cout << " _ _ _ " << endl ;
	cout << endl << " @ ���ؼЩҦb" << endl ;
	
	cout << endl << "�W�h : " << endl ; 
	cout << "��@�Ÿ��H�סB��B�����覡�s���@���u�A�Y���@�����" << endl ;
	cout << "�d�Ҥ@   �d�ҤG  �d�ҤT" << endl ; 
	cout << " _ _ O   O O O   O _ _ " << endl ;
	cout << " _ O _   _ _ _   O _ _ " << endl ;
	cout <<  " O _ _   _ _ _   O _ _ " << endl ;
	cout << endl << "���T�ؽd�ҬҬ����aA���" << endl ; 
	 
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
		cout << "�п�J�y�Щ�1-3��" << endl ; 
		return false ;
	}
	
	else if ( game[j-1][i-1] == '_' ) return true ;
	
	else {
		cout << "���y�Фw�Q�ϥ�" << endl ;
		return false ;
	}
}

void print() {
	cout << endl << "---�C���Ԫp---" << endl ;
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
		cout << "<<<<<<<<<<<<<<<�C���}�l>>>>>>>>>>>>>>>" << endl ;
		while ( !gameover( win ) ) {
			
			if ( !gameover( win ) ) {
				cout << "�ШϥΪ�A��J�y��" ;
				cin >> j >> i ;
	
				while ( ! canUse( j, i ) ) {
					cout << "�ЦA����J : " ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'O' ;
				print() ;
			}
			
			if ( !gameover( win ) ) {
				cout << "�ШϥΪ�B��J�y��" ;
				cin >> j >> i ;
				while ( ! canUse( j, i ) ) {
					cout << "�ЦA����J : " ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'X' ;
				print() ;
			}		
			
		}
		
		if ( win == 'O' ) cout << "���ߪ��aA�ӧQ:)" << endl ;
		else if ( win == 'X' ) cout << "���ߪ��aB�ӧQ:)" << endl ;
		else if ( win == 't' ) cout << "����" << endl ; 
		cout << "�Q�A���@���п�J��Lp��A�Y���h�X�C���п�J���N��" << endl ;
		cin >> again_point ;
		if ( again_point == 'p' || again_point == 'P' ) again = true ;
		else again = false ;
	} while ( again ) ;
	
	cout << "Byebye~~~~~~~~~" << endl ;
	system( "pause" ) ;
	
		
}
