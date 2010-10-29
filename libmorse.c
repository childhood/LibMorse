
/* 0 means short and 1 means long */
/* a == 01      => 101 = 0x05
   b == 1000
   c == 1010
   d == 100
   e == 0
   f == 0010
   g == 110
   h == 0000
   i == 00
   j == 0111
   k == 101
   l == 0100
   m == 11
   n == 10
   o == 111
   p == 0110
   q == 1101
   r == 010
   s == 000
   t == 1
   u == 001
   v == 0001
   w == 011
   x == 1001
   y == 1011
   z == 1100

   0 == 11111
   1 == 01111
   2 == 00111
   3 == 00011
   4 == 00001
   5 == 00000
   6 == 10000
   7 == 11000
   8 == 11100
   9 == 11110

   to encode them we can use "1"+"CODE" so that we use up to 6 bit to encode a sign
   and no "0" at the first position get lost.
*/
/** this function sends and returns the code above */
int sign2code(char c) {
  switch (c) {
    case 'a': return 0x05; //101;
    case 'b': return 0x18; //11000;
    case 'c': return 0x1a; //11010;
    case 'd': return 0x0c; //1100;
    case 'e': return 0x02; //10;
    case 'f': return 0x12; //10010;
    case 'g': return 0x0e; //1110;
    case 'h': return 0x10; //10000;
    case 'i': return 0x04; //100;
    case 'j': return 0x17; //10111;
    case 'k': return 0x0d; //1101;
    case 'l': return 0x14; //10100;
    case 'm': return 0x07; //111;
    case 'n': return 0x06; //110;
    case 'o': return 0x0f; //1111;
    case 'p': return 0x16; //10110;
    case 'q': return 0x1d; //11101;
    case 'r': return 0x0a; //1010;
    case 's': return 0x08; //1000;
    case 't': return 0x03; //11;
    case 'u': return 0x09; //1001;
    case 'v': return 0x11; //10001;
    case 'w': return 0x0b; //1011;
    case 'x': return 0x19; //11001;
    case 'y': return 0x1b; //11011;
    case 'z': return 0x1c; //11100;

    case '0': return 0x3f; //111111;
    case '1': return 0x2f; //101111;
    case '2': return 0x27; //100111;
    case '3': return 0x23; //100011;
    case '4': return 0x21; //100001;
    case '5': return 0x20; //100000;
    case '6': return 0x30; //110000;
    case '7': return 0x38; //111000;
    case '8': return 0x3c; //111100;
    case '9': return 0x3e; //111110;

    default: return 0; // unknown
  }
}

void show_sign(char s) {
  if (s==0) {
    //unknown sign
  }else{
    int i=7;
    while ( (s & (1 << i)) == 0 )
      i--;

    i--; //scipp the "1" to identify the beginning
    for (;i>=0; i-- ) {
      if ( (s & (1 << i)) == 0 ) { //kurz
        on();
        wait();
        off();
        wait();
      }else { //lang
        on();
        wait();
        wait();
        off();
        wait();
      }
    }
    wait();//to terminate the sign
  }
}


