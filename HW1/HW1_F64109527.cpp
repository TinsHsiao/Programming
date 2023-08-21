# include <iostream>
# include <vector>
# include <fstream>
# include <string>
# include <stdlib.h>

using namespace std ;

void a_question( int n, int m ) {
	cout << "A. ans: " ;
	for ( int i = 0; i < n; i++ ) 
		cout << "+" ;
	
	for ( int i = 0; i < m; i++ ) 
		cout << "-" ;
		
	cout << endl ;
}

void b_question( int n, int m ) {
	cout << "B. ans: " ;
	int tmp1, tmp2 ;
	if ( n <= m ) {
		tmp1 = n ;
		tmp2 = m ;
	}
	
	else {
		tmp1 = m ;
		tmp2 = n ;
	}
	
	while( tmp1 <= tmp2 ) {
		cout << tmp1 << " " ;
		tmp1 ++ ;
	}
	
	cout << endl ;
}

void c_question( int n ) {
	cout << "C. ans: " ;
	char tmp = 'A' ;
	int i = 0 ;
	while( i < n ) {
		cout << (char)(tmp+i) << " " ;
		i ++ ;
	}
	
	cout << endl ;
}

void d_question( int m ) {
	cout << "D. ans: " ;
	char tmp = 'z' ;
	int i = 0 ;
	while( i < m ) {
		cout << (char)(tmp-i) << " " ;
		i ++ ;
	}
	
	cout << endl ;
}

void e_question( int n, int m ) {
	cout << "E. ans: " ;
	int total = 0 ;
	while( n <= m ) {
		total = total + n ;
		n ++ ;
	}
	
	cout << total << endl ;
}

void f_question( int n, int m ) {
	cout << "F. ans: " ;
	int total = 0 ;
	while( n <= m ) {
		if ( n % 2 == 0 ) 
			total = total + n ;	
		n ++ ;
	}
	
	cout << total << endl ;
}

void g_question( int n, int m ) {
	cout << "G. ans: " ;
	int n_total = 0 ;
	int m_total = 0 ;
	for ( int i = 1; i <=n; i ++ ) 
		n_total = n_total + i ;
	for ( int j = 1; j <=m; j ++ ) 
		m_total = m_total + j ;
	n_total = n_total - m_total ;
	cout << n_total << endl ;
}

void h_question( int m ) {
	cout << "H. ans: " ;
	int total = 0 ;
	int walk = 0 ;
	while ( walk <= m ) {
		if ( walk % 2 == 0 ) 
			total = total + walk ;
		else total = total - walk ;
		walk ++ ;
	}
	
	cout << total << endl ;
}

void i_question( int n, int m ) {
	cout << "I. ans: " ;
	int walk = 1 ;
	int tmp1, tmp2 ;
	if ( n <= m ) {
		tmp1 = n ;
		tmp2 = m ;
	}
	
	else {
		tmp1 = m ;
		tmp2 = n ;
	}
	
	while ( walk <= tmp2 ) {
		if ( tmp1 % walk == 0 && tmp2 % walk == 0 ) {
			cout << walk << " " ;
		}
		
		walk ++ ;
	}
	
	cout << endl ;
}

void j_question( int n, int m ) {
	cout << "J. ans: " ;
	int walk = 1 ;
	int tmp1, tmp2 ;
	if ( n <= m ) {
		tmp1 = n ;
		tmp2 = m ;
	}
	
	else {
		tmp1 = m ;
		tmp2 = n ;
	}
	
	while ( walk <= 100 ) {
		if ( walk % tmp1 == 0 && walk % tmp2 == 0 ) {
			cout << walk << " " ;
		}
		
		walk ++ ;
	}
	
	cout << endl ;
}


int main () {
	
	do {
	 	int n = 0 ;
		int m = 0 ;
	 	while ( n < 1 || n > 26 ) {
	 		cout << "請輸入第一個數字(1-26):" ;  
			cin >> n ;
		}
		
		while ( m < 1 || m > 26 ) {
	 		cout << "請輸入第二個數字(1-26):" ;  
			cin >> m ;
		}
		
		a_question( n, m ) ;
		b_question( n, m ) ;
		c_question( n ) ;
		d_question( m ) ;
		e_question( n, m ) ;
		f_question( n, m ) ;
		g_question( n, m ) ;
		h_question( m ) ;
		i_question( n, m ) ;
		j_question( n, m ) ;
		cout << endl ;
		
 	} while(true) ;
 	
}
