#include <stdio.h>
#include <stdbool.h>

int main()
{
    // print
    printf("Hello World!\n");

    /*
    Multi-comment.
    Another comment
    */
    printf("\"I like Pizza\" - Abraham Lincoln probably\n");

    // Variable
    // is a space in memory to store a value.

    int x; // declaration
    x = 123; // initialization

    int y = 321; // declaration + initialization
    int age = 35; // integer value
    float gpa = 2.05; // floating point number
    char grade = 'C'; // single character
    char name[] = "Alex";
    printf("Hello %s!\n", name);
    printf("You are %i years old.\n", age);
    printf("Your average grade is %c.\n", grade);
    printf("Your gpa is %f.\n", gpa);

    // Data Types
    char a = 'C'; // single character %c
    char b[] = "Bro"; // array of characters %s

    float c = 3.141592653589793; // 4 bytes (32 bits of precision) 6 - 7 digits %f
    double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15 - 16 digits %lf

    printf("%0.15f\n", c);
    printf("%0.15lf\n", d); // see output, double is more precise

    bool e = true; // 1 byte( true or false) %d
    printf("e: %i\n", e);

    char f = 120; // 1 byte (-128 to 127) %d or %c
    unsigned char g = 255; // 1 byte (0 + 255) %d or %c
    printf("f: %c\n", f);
    printf("g: %i\n", g);

    short int h = 32767; // 2 bytes (-32,768 to 32,767) %d
    unsigned short int i = 65535; // 2 bytes (0 to 65,535) %d

    int j = 2147483647; // 4 bytes (-2,147,483,648 to 2,147,483,647) %d
    unsigned int k = 4294967295; // 4 bytes (0 to 4,294,967,295) %u
    printf("j: %i\n", j); 
    printf("k: %u\n", k);

    long long int l = 9223372036854775807; // 8 bytes ( -9 quintillion to 9 quintillion) %lld
    unsigned long long int m = 18446744073709551615; // 8 bytes (0 to 18 quintillion) %llu
    printf("l: %lld\n", l);
    printf("m: %llu\n", m);

    return 0;
}