#include <iostream>
#include "stack.h"
#include "Calculator.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	try {

        char c = '1';
        Calculator calc;

        while ( c != 'q' ) {
            cout << "Enter operation:  " << endl;


            calc.enter_operation();
            if ( calc.check_correctness() )
            	cout << "Result = "<< calc.result() << endl;

            else
            	cout << "Niepoprawne dzialanie !" << endl;

            cout << "Press 'q' to exit, or different button to continue"<< std::endl;
            cin >> c;

            //Czyszcze ekran i bufor ( zalega w nim znak konca linii, a wiec getline() zakonczy prace od razu
            //i nie bedziemy mogli wprowadzic nowego dzialania.
            std::cin.ignore();
            //system("clear");
        }

	}

	catch( const char * blad ) {
		cout << endl << blad << endl;
		exit(EXIT_FAILURE);
	}


	catch(std::bad_alloc & blad){
		cout << blad.what() << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
