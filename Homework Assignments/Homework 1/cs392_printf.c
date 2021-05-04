/*Mehta Nimtrakul */
/*I pledge my honor that I have abided by the Stevens Honor System. */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cs392_printf.h>


char *convert(unsigned int num, int base)
{
    static char vals[]= "0123456789ABCDEF";

    static char temp[30];

    char *ptr;

    ptr = &temp[29];
    *ptr = '\0';

    do
    {
        *--ptr = vals[num%base];
        num /= base;
    } while(num != 0);
    return(ptr);
}

void print_str(char * s){
    while (*s != '\0')
        putchar(*s++);
}
int cs392_printf(const char * format, ...){

    va_list args;
    int a;
    char c;
    char *s;


    va_start(args, format);

//iterative over “format” and find specifiers
    while (*format !='\0') {

    // get the first argument with va_arg
    // the following is an example of handling integer format “%d”


            if(*format == '%'){
                format++;


                if(*format == 0)
                    break;

                if(*format == 'd'){
                    print_str(convert(va_arg(args, int), 10));

                }
                if(*format == 'x'){
                    print_str(convert(va_arg(args, int), 16));
                }
                if(*format == 's'){
                    s = va_arg(args, char*);
                    print_str(s);
                }

                if(*format == 'c'){
                    putchar(va_arg(args, int));

                }

            }
                else{
                    putchar(*format);
                }
        *format++;
// you check for other formats
    }
    va_end(args);
}




int main() {


    return 0;
}
