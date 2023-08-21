# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# define ANS 8462

using namespace std ;

void find_a_b( int n, int & a, int & b ) {
	int guess[4][2], test[4][2] ;
	int walk = 0 ; 
	guess[0][0]= 2 ;
	guess[1][0] = 6 ;
	guess[2][0] = 4 ;
	guess[3][0] = 8 ;
	
	for ( int i = 0; i < 4; i ++ ) { // �N��J�i�Ӹ����}�C�Φ��x�s �H�θ�ƪ�l�� 
		test[i][0] = n % 10 ;
		test[i][1] = 0 ;
		guess[i][1] = 0;
		n = n / 10 ;
	}
	
	for ( int i = 0; i < 4; i ++ ) { // ��a������ 
		if ( test[i][0] == guess[i][0] ) {
			test[i][1] = 1 ;
			guess[i][1] = 1 ;
			a ++ ; 
		}
	}
	
	for ( int i = 0; i < 4; i ++ ) { // ��b������ 
		walk = 0 ;
		while( ( walk < 4 ) && ( test[i][0] != guess[walk][0] ) ) walk ++ ;
		
		if ( walk < 4 && test[i][0] == guess[walk][0] && guess[walk][1] != 1 && test[i][1] != 1) {
			guess[walk][1] = 1 ;
			test[i][1] = 1 ;
			b ++ ;
		}	
	}
	
	
	
}

bool find_answer( int n ) {
	
	if ( n > 9999 || n < 0000 ) return false ;
	
	else if ( n == ANS ) {
		cout << "4A0B�A���ץ��T" << endl ; 
		return true ;
	} 
	
	else {
		int a = 0, b = 0 ;
		find_a_b( n, a, b ) ;
		cout << "Hint :" << a << "A" << b << "B" << endl ;
		return false ;
	}
}

int main() {
	cout << "############>> WELCOME <<#############" << endl ;
	bool det = false ;
	int n = 0 ;
	cout << "�п�J�ƦrN:" ;
	cin >> n ;
	det = find_answer( n ) ;
	while ( ! det ) {
		cout << endl << "�п�J�ƦrN:" ;
		cin >> n ;
		det = find_answer( n ) ;
	}
	
	cout << "#######>> Have a nice day ! <<#######" << endl ;
	system( "pause" ) ;
}
