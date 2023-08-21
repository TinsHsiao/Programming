# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <stdio.h>
# include <windows.h>
using namespace std ;

char game[15][15] ;

void perface() {
	cout << "<<<<<<<<<<<<<<<�C������>>>>>>>>>>>>>>>" << endl ;
	cout << "���C�������l�ѹC��" << endl ;
	cout << "���aA ����>>>>>�Ÿ�O" << endl ;
	cout << "���aB ����>>>>>�Ÿ�X" << endl ;
	cout << "�п�J����J�y�СA�d��1-15" << endl ;
	cout << "�z�ҿ�J�Ĥ@�ӼƦr�� >> �C << " << endl ; 
	cout << "�z�ҿ�J�ĤG�ӼƦr�� >> �� << " << endl ; 
	cout << "�ѽL�˦��H.�Ÿ���ܬ��ťճB �i���l" << endl ;
	cout << "�d�� : " << endl ;
	cout << "�Ъ��a��J�y�� : 2 3" << endl ;
	cout << "..............." << endl ;
	cout << "..O............" << endl ;
	for ( int i = 2; i < 15; i ++ ) 
		cout << "..............." << endl ;
	
	cout << endl << "�W�h : " << endl ; 
	cout << "�סB��B�����覡�s�򤭭ӬۦP���l�s���A�Y���@�����" << endl ;
	cout << "�d��" << endl ; 
	cout << ".....O..X......" << endl ;
	cout << "......OXX......" << endl ;
	cout << ".......OX......" << endl ;
	cout << "........O......" << endl ;
	cout << ".........O....." << endl ;
	for ( int i = 5; i < 15; i ++ ) 
		cout << "..............." << endl ;
		
	cout << endl << "���ؽd�Ҭ����aA���" << endl ; 
	 
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
	while ( game[y][x] == c && in_range( x, y ) ) { // ���U�� 
		if ( game[y][x] == c ) {
			connect ++ ;
		}
		
		x -- ;
		y ++ ;
	}
	
	x = i + 1 ;
	y = j - 1 ;
	while ( game[y][x] == c && in_range( x, y ) ) { // �k�W�� 
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
		cout << "�п�J�y�Щ�1-15��" << endl ; 
		return false ;
	}
	
	else if ( game[j-1][i-1] == '.' ) return true ;
	
	else {
		cout << "���y�Фw�Q�ϥ�" << endl ;
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
		cout << "<<<<<<<<<<<<<<<�C���}�l>>>>>>>>>>>>>>>" << endl ;
		while ( !gameover( win, i, j ) ) {
			
			if ( !gameover( win, i, j ) ) {
				cout << "�Ъ��aA��J�y�� :" ;
				cin >> j >> i ;
	
				while ( ! canUse( i, j ) ) {
					cout << "�ЦA����J : " << endl ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'O' ;
				win = 'O' ;
				print() ;
			}
			
			if ( !gameover( win, i, j ) ) {
				cout << "�Ъ��aB��J�y�� :" ;
				cin >> j >> i ;
				while ( ! canUse( i, j ) ) {
					cout << "�ЦA����J : " ;  
					cin >> j >> i ;
				}
				
				game[j-1][i-1] = 'X' ;
				win = 'X' ;
				print() ;
			}		
			
		}
		
		if ( win == 'O' ) cout << "���� ���aA�ӧQ" << endl ;
		else if ( win == 'X' ) cout << "���� ���aB�ӧQ" << endl ;
		else if ( win == 't' ) cout << "����" << endl ; 
		cout << endl << "�Q�A���@���п�J��Lp��A�Y���h�X�C���п�J���N��" << endl ;
		cin >> again_point ;
		if ( again_point == 'p' || again_point == 'P' ) again = true ;
		else again = false ;
		
	} while( again ) ; 
	
	cout << "Byebye~~~~~~~~~" << endl ;
	system( "pause" ) ;
	
}
