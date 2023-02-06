#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

void displayUTF() {
    int reading, count = 0;
    bool ascii = true;

    do{
        int8_t c;
        reading = read(0, &c, 1);

        if(c < 0)
        {
            printf("%c", c);
        }
    } while(reading != 0);
}

void displayASCII() {
    int reading, count = 0;
    bool ascii = true;

    do{
        uint8_t c;
        reading = read(0, &c, 1);

        if(c < 127)
        {
            printf("%c", c);
        }
    } while(reading != 0);
}

void displayProblem() {

}

void displayOriginal() {
    int reading;
    do{
        uint8_t c;
        reading = read(0, &c, 1);
        printf("%c", c);
    } while(reading != 0);
}


int main(int argc, char **argv){
    int opt;

    while ((opt = getopt(argc, argv, "aupo")) != -1) {
        switch(opt) {
            case 'a':
                displayASCII();
                break;
            case 'u':
                displayUTF();
                break;
            case 'p':
                displayProblem(); 
                break;
            case 'o':
                displayOriginal();
                break;
            default:
                break;
        }
    }
}

