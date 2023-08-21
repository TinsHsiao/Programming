# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# define ANS 66
using namespace std ;

bool find_answer( int n ) {
	if ( n == ANS ) {
		cout << "答案正確" << endl ; 
		return true ;
	} 
	
	else {
		if ( n > ANS ) cout << "Hint : 比答案大" << endl ;
		else cout << "Hint : 比答案小" << endl ;
		return false ; 
	}
}

int main() {
	bool det = false ;
	int n = 0 ;
	cout << "############>> WELCOME <<#############" << endl ;
	while ( ! det ) {
		cout << endl << "請輸入數字N:" ;
		cin >> n ;
		det = find_answer( n ) ;
	}
	
	cout << "#######>> Have a nice day ! <<#######" << endl ;
	system( "pause" ) ;
	 
}
