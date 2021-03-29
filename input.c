void main() {
    // line comment test

    /* block comment test
        testing
        cout <<  testing
        x = 'testing'
    */

    // cout test
    cout << 2;

    // assignment and identifier test
    int x = 9;
    cout << x;

    // plus test
    cout << x + 4;

    // minus test
    cout << x - 2;

    // times test
    cout << x * 3;

    // divide test
    cout << x / 3;


    // less test
    cout << x < 3; 
    cout << ( x < 29 );

    // greater test
    cout << x > 3; 
    cout << ( x > 29 );

    // less equal test
    cout << x <= 9;
    cout << x <= 2;

    // greater equal test
    cout << x >= 9;
    cout << ( x >= 38);

    // not equal test
    cout << x != 9;
    cout << ( x != 3 );

    int y = 21;
    int z = 6;
    // bitwise and test ( expected output = 4)
    cout << y & z;

    // bitwise or test ( expected output = 23 )
    cout << y | z;

    // && ( and ) test
    cout << ( x == 9 ) && ( y == 21);
    cout << ( x == 9 )  && ( y == 2);
    cout << ( x == 8 ) &&  ( y == 21);
    cout << ( x == 8 ) && ( y == 2);

    // | ( or ) test
    cout << ( x == 9 ) || ( y == 21);
    cout << ( x == 9 ) || ( y == 2);
    cout << ( x == 8 ) || ( y == 21);
    cout << ( x == 8 ) || ( y == 2);

    // equal test
    cout << x == 9;
    cout << x == 10;

    // if test
    // true true and 
    if (( x == 9 ) && ( y == 21 )) {
        cout << 24;
    }

    // false true and 
    if (( x != 9 ) && ( y == 21 )) {
        cout << 99;
    }

    // true false or
    if (( x == 9 ) || ( y == 16 )) {
        cout << 22;
    }

    // for loop test
    for ( int i = 1; i < 6; i=i+1 ) {
        cout << i;
    }

    // while loop test
    int j = 8;
    while ( j > 0 ) {
        cout << j;
        j=j-1;
    }

    // order of operations
    cout << 2 * 3 + 4;
    cout << 2 * ( 3 + 4 );
    cout << 9 / 3 - 1;


    cout << 1 && 1;

    int p = 0;
    int q = 0;
    if ( p + 99 || q ) {
        cout << 99;
    }
}