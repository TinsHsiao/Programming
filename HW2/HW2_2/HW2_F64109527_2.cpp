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
	
	for ( int i = 0; i < 4; i ++ ) { // 將輸入進來資料轉陣列形式儲存 以及資料初始化 
		test[i][0] = n % 10 ;
		test[i][1] = 0 ;
		guess[i][1] = 0;
		n = n / 10 ;
	}
	
	for ( int i = 0; i < 4; i ++ ) { // 找a的次數 
		if ( test[i][0] == guess[i][0] ) {
			test[i][1] = 1 ;
			guess[i][1] = 1 ;
			a ++ ; 
		}
	}
	
	for ( int i = 0; i < 4; i ++ ) { // 找b的次數 
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
		cout << "4A0B，答案正確" << endl ; 
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
	cout << "請輸入數字N:" ;
	cin >> n ;
	det = find_answer( n ) ;
	while ( ! det ) {
		cout << endl << "請輸入數字N:" ;
		cin >> n ;
		det = find_answer( n ) ;
	}
	
	cout << "#######>> Have a nice day ! <<#######" << endl ;
	system( "pause" ) ;
}
