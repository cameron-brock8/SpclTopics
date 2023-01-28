#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

int main(){

    int reading, count = 0;
    bool ascii = true;

    do{
        count++;
        uint8_t c;
        reading = read(0, &c, 1);

        //unsigned int ascii = c;
        //uint8_t ascii = c;

        if(c > 127)
        {
            ascii = false;
            printf("Not an ascii file, found a %u integer at byte %d", c, count);
            printf(": %c \n", c);
        }

    } while(reading != 0);

    if (ascii == true)
    {
        printf("ASCII data\n");   
    }

}