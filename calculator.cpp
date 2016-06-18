#include "calculator.h"
#include "stack.h"

bool Calculator::check_correctness() {
    int i = 0, operators = 0, operands = 0, length = operation.size();

    while( operation[i] ) {
        //Jesli mamy spacje, to idziemy dalej.
        if ( operation[i] == ' ' )
        	i++;
        else if ( operation[i] == '+' || operation[i] == '-' || operation[i] == '*') {
            //Sprawdzam czy operatory (operandy) sa rozdzielone spacja ( wyjatek dla operatora konczacego dzialanie )

            if ( operation[ i+1 ] == ' ' || i == length-1 ) {
                operators++;
                i++;
            }
            else
            	return false;
        }
        else {


            //Jesli napotkamy znak o nieodpowiednim kodzie ASCII, to zwracamy false.
            while ( operation[i] != ' ' ) {
                if( operation[i] >= '0' && operation[i] <= '9' )
                	i++;
                else
                	return false;
            }
            operands++;
        }


        if ( operators >= operands )
        	return false;
    }

    // Sprawdzam czy ilosciowo liczba operandow i operatorow jest poprawna

    if ( operators == (operands - 1) )
    	return true;
    else
    	return false;
}

int Calculator::result() {
    int i = 0;

    while( operation[i] ) {
        std::string element;
        if ( operation[i] == ' ' )
        	i++;
        else {
            //Sprawdzam czy nalezy wykonac dzialanie
            if ( operation[i] == '+' ) {
                add();
                i++;
            }
            else if ( operation[i] == '-' ) {
                subtract();
                i++;
            }
            else if ( operation[i] == '*' ) {
                multiply();
                i++;
            }
            else {
                //Blok do zamiany stringa na liczbe. Zmienna pomocnicza "element" - typu string
                //Zapisuje kolejne cyfry stringu "dzialania" do stringu "element" - warunek stopu to spacja
                while ( operation[i] != ' ' )  {
                    element += operation[i];
                    i++;
                }
                //Zamiana stringu na inta przy pomocy strumieni napisowych ( biblioteka <sstream> )
                int number;
                std::istringstream iss( element );
                iss >> number;
                stack.push(number);
            }
        }
    }

    return stack.top();  // wynik
}


void Calculator::add() {
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push( x + y );
}

void Calculator::subtract() {
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push( x - y );
}

void Calculator::multiply() {
	int x = stack.top();
	stack.pop();
	int y = stack.top();
	stack.pop();
	stack.push( x * y );
}



