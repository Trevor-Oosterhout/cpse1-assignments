#include "hwlib.hpp"

extern "C" void print_asciz( const char * s );
extern "C" void uart_put_char( char c );
extern "C" void application();
extern "C" char uppercase_lowercase(char c);

void uart_put_char( char c ){
   hwlib::cout << c;
}

char uppercase_lowercase(char c){
    if((c < 91 ) && (c > 64 )){
        c = c + 32;
        return c;
    }
    else if((c < 123 ) && (c > 96 )){
        c = c - 32;
        return c;
    }
    else{
        return c;
    }
}

int main( void ){

   namespace target = hwlib::target;

   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}
