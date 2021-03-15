#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::snowman(11114411) << endl;
/* Should print:
_===_
(.,.)
( : )
( : )
	*/

	cout << ariel::snowman(33232124) << endl;   
/* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/

    cout << ariel::snowman(12121212) << endl;
/* Should print:
 _===_
 (..o)/
<( : )
 (" ")
	*/

    cout << ariel::snowman(12341234) << endl;
/* Should print:
 _===_
 (o.-)/
<(> <)
 (   )
	*/
 
    cout << ariel::snowman(41414141) << endl;
/* Should print:
  ___ 
 (_*_)
 (-,.)
 (   )>
 ( : )
	*/

	try{
		cout << ariel::snowman(15151215) << endl;
	}
	catch (exception& ex){
		cout << "caught exception: " << ex.what() << endl ;
	}

	try{
		cout << ariel::snowman(-11111111) << endl;
	}
	catch (exception& ex){
		cout << "caught exception: " << ex.what() << endl ;
	}

		try{
		cout << ariel::snowman(111111111) << endl;
	}
	catch (exception& ex){
		cout << "caught exception: " << ex.what() << endl ;
	}

	try {
		cout << ariel::snowman(5) << endl;
	} catch (exception& ex){
		cout << "caught exception: " << ex.what() << endl ;
	}
}
