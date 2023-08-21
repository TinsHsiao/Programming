# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <stdio.h>
# include <windows.h>
using namespace std ;

void SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  SetConsoleTextAttribute( hConsole, color );
}

string answer_a( string p ) {
	return p ;
}

string answer_b( string p ) {
	string num ;
	for ( int i = 0; i < p.length(); i++ ) {
		if ( p[i] <= '9' && p[i] >= '0' ) {
			num = num + p[i] ;
		}
	}
	
	return num ;
}

string answer_c( string p, string q ) {
	string s ;
	s = p + q ;
	return s ;
}

string answer_d( string p, string q ) {
	string s = p + q ;
	string answer ;
	for ( int i = s.length()-1; i >= 0; i-- ) {
		answer = answer + s[i] ;
	}  
	
	return answer ;
}

int answer_e( string p, string q ) {
	string s = p + q ;
	int total = 0 ;
	for ( int i = 0; i < s.length(); i++ ) {
		if ( s[i] <= '9' && s[i] >= '0' ) total ++ ;
	}
	
	return total ;
}

int answer_f( string p, string q ) {
	string s = p + q ;
	int total = 0 ;
	for ( int i = 0; i < s.length(); i++ ) {
		if ( s[i] <= '9' && s[i] >= '0' ) {
			total = total + int(s[i]-'0') ;
		}
	}
	
	return total ;
}

string answer_g( string p, string q ) {
	string s;
	bool det = false ;
	for ( int i = 0; i < p.length(); i++ ) {
		for ( int j = 0; j < q.length() && det == false; j++ ) {
			if ( p[i] == q[j] ) {
				s = s + q[j] ;
				q.erase( j, 1 ) ;
				det = true ;
			}
		}
			
		det = false ;
	}

	
	return s ;
}

string answer_h( string p, string q ) {
	string s ;
	bool det = false ;
	for ( int i = 0; i < p.length(); i ++ ) {
		for ( int j = 0; j < q.length() && det == false; j++ ) {
			if ( p[i] == q[j] ) {
				det = true ;
				q.erase( j, 1 ) ;
			}
		}
		
		if ( det == false ) s = s + p[i] ;
		det = false ;
	}
	
	return s ;
}

string answer_i( string p ) {
	string s ;
	for ( int i = 0; i < p.length(); i++ ) {
		if ( p[i] <= '8' && p[i] >= '0' ) {
			p[i] = char( p[i] + 1 ) ;
		}
		
		s = s + p[i] ;
	}
	
	return s ;
}

string answer_j( string q ) {
	string s ;
	for ( int i = 0; i < q.length(); i++ ) {
		if ( q[i] <= 'Z' && q[i] >= 'A' ) {
			q[i] = char( q[i] + 32 ) ;
		}
		
		else if ( q[i] <= 'z' && q[i] >= 'a' ) {
			q[i] = char( q[i] - 32 ) ;
		}
		
		s = s + q[i] ;
	}
	
	return s ;
}

void perface( string & p, string & q ) {
	SetColor( 236 ) ;
	cout << "�п�J��Ӧr��" << endl;
	cout << "P :" ;
	cin >> p ;
	cout << "Q :" ;
	cin >> q ;
}

int main() {
	string p, q ;
	perface( p, q ) ;
	SetColor( 233 ) ;
	cout << "A. P�r��	>>" << answer_a( p ) << endl ;
	cout << "B. P�r�ꤤ���Ʀr	>>" << answer_b( p ) << endl ;
	cout << "C. P�r��PQ�r�ꤧ�걵�r��	>>" << answer_c( p, q ) << endl ;
	cout << "D. P�BQ�걵�r�ꤧ����r��	>>" << answer_d( p, q ) << endl ;
	cout << "E. P�r��PQ�r��@���X�ӼƦr	>>" << answer_e( p, q ) << endl ;
	cout << "F. P�r��PQ�r�ꤤ�A�Ʀr���`�M	>>" << answer_f( p, q ) << endl ;
	cout << "G. P�r��PQ�r�ꤧ�@�P�l�r��	>>" << answer_g( p, q ) << endl ;
	cout << "H. P�BQ�r�ꤧ�t���r��(P����Q�S�����r��)	>>" << answer_h( p, q ) << endl ;
	cout << "I. P�r�ꤤ���Ʀr�r���U�[1	>>" << answer_i( p ) << endl ;
	cout << "J. Q�r�ꤧ�j�p�g�ഫ	>>" << answer_j( q ) << endl ;
	SetColor( 236 ) ;
	system("pause") ;
	return 0 ;
}
