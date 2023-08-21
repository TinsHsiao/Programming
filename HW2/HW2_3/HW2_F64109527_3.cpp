# include <iostream>
# include <vector>
# include <fstream>
# include <string>
#include <stdio.h>
#include <stdlib.h>
# define ANS 8462

using namespace std ;

int rand_process() {
	int a = rand() % 10 ;
	int b = rand() % 10 ;
	int c = rand() % 10 ;
	cout << a << " + " << b << " + " << c << " ==> " ;
	int total = 0 ;
	if ( a == 0 || a == 6 || a == 9 || a == 4 ) total ++ ;
	else if ( a == 8 ) total = total + 2 ;
	if ( b == 0 || b == 6 || b == 9 || b == 4 ) total ++ ;
	else if ( b == 8 ) total = total + 2 ;
	if ( c == 0 || c == 6 || c == 9 || c == 4 ) total ++ ;
	else if ( c == 8 ) total = total + 2 ;
	
	return total ;
}

void find_answer() {
	int n ;
	cout << "ex " ; 
	cout << rand_process() << endl ;
	cout << "Please input a number :	" << endl;
	int answer = rand_process() ;
	cin >> n ;
	while ( n > 9 || n < 0 ) {
		cout << "Please input a number" << endl ;
		cin >> n ;
	}
	
	while ( n != answer ) {
		cout << "Please try again !" << endl << "Ans :";
		cin >> n ;
	}
}

int main() {
	cout << "############>> WELCOME <<#############" << endl ;
	find_answer() ;
	cout << "Great!" << endl ;
	cout << "#######>> Have a nice day ! <<#######" << endl ;
	system( "pause" ) ;
	 
}
