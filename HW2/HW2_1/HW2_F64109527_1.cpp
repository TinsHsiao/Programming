# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# define ANS 66
using namespace std ;

bool find_answer( int n ) {
	if ( n == ANS ) {
		cout << "���ץ��T" << endl ; 
		return true ;
	} 
	
	else {
		if ( n > ANS ) cout << "Hint : �񵪮פj" << endl ;
		else cout << "Hint : �񵪮פp" << endl ;
		return false ; 
	}
}

int main() {
	bool det = false ;
	int n = 0 ;
	cout << "############>> WELCOME <<#############" << endl ;
	while ( ! det ) {
		cout << endl << "�п�J�ƦrN:" ;
		cin >> n ;
		det = find_answer( n ) ;
	}
	
	cout << "#######>> Have a nice day ! <<#######" << endl ;
	system( "pause" ) ;
	 
}
