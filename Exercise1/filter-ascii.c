#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

int main(){

    int reading, count = 0;

    do{
        count++;
        char c;
        reading = read(0, &c, 1);

        unsigned int ascii = c;

        if(ascii > 127)
        {
            printf("Not an ascii file, found a %u integer at byte %d", ascii, count);
            printf(": %c \n", c);
        }

    } while(reading != 0);


}