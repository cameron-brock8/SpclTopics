#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
KNOWN ISSUES:
 -a -u is achieved with -o command
*/

void displayUTF()
{
    int reading;
    do
    {
        uint8_t c;
        reading = read(0, &c, 1);

        if (reading == 1)
        {
            write(1, &c, 1);
        }
    } while (reading != 0);
}

void displayASCII()
{
    int reading;
    do
    {
        uint8_t c;
        reading = read(0, &c, 1);

        if (c < 127)
        {
            write(1, &c, 1);
        }
    } while (reading != 0);
}

void displayProblem()
{
    uint8_t firstByte;
    int reading, currentPos = -1;
    char buffer[250] = {'\0'};

    do
    {
        currentPos++;
        reading = read(0, &firstByte, 1);
        // 1
        if (firstByte >= 0x00 && firstByte <= 0x7f)
        {
            // Correctly formed
            // printf("Correctly formed\n");
        }
        // 2
        else if (firstByte >= 0xc2 && firstByte <= 0xdf)
        {
            uint8_t b2;
            read(0, &b2, 1);
            if (b2 < 0x80 || b2 > 0xbf)
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 3
        else if (firstByte == 0xe0)
        {
            uint8_t b2, b3;
            read(0, &b2, 1);
            read(0, &b3, 1);
            if ((b2 < 0xa0 || b2 > 0xbf) || (b3 < 0x80 || b3 > 0xbf))
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 4
        else if (firstByte >= 0xe1 && firstByte <= 0xec)
        {
            uint8_t b2, b3;
            read(0, &b2, 1);
            read(0, &b3, 1);
            if ((b2 < 0x80 || b2 > 0xbf) || (b3 < 0x80 || b3 > 0xbf))
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));

                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 5
        else if (firstByte == 0xed)
        {
            uint8_t b2, b3;
            read(0, &b2, 1);
            read(0, &b3, 1);
            if ((b2 < 0x80 || b2 > 0x9f) || (b3 < 0x80 || b3 > 0xbf))
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 6
        else if (firstByte >= 0xee && firstByte <= 0xef)
        {
            uint8_t b2, b3;
            read(0, &b2, 1);
            read(0, &b3, 1);
            if ((b2 < 0x80 || b2 > 0xbf) || (b3 < 0x80 || b3 > 0xbf))
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));

                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 7
        else if (firstByte == 0xf0)
        {
            uint8_t b2, b3, b4;
            read(0, &b2, 1);
            read(0, &b3, 1);
            read(0, &b4, 1);
            if ((b2 < 0x90 || b2 > 0xbf) || (b3 < 0x80 || b3 > 0xbf) || (b4 < 0x80 || b4 > 0xbf))
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));

                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b4);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 8
        else if (firstByte >= 0xf1 && firstByte <= 0xf3)
        {
            uint8_t b2, b3, b4;
            read(0, &b2, 1);
            read(0, &b3, 1);
            read(0, &b4, 1);
            if ((b2 < 0x80 || b2 > 0xbf) || (b3 < 0x80 || b3 > 0xbf) || (b4 < 0x80 || b4 > 0xbf))
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));

                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b4);
                write(1, buffer, strlen(buffer));
            }
            // printf("%s", buffer);
        }
        // 9
        else if (firstByte == 0xf4)
        {
            uint8_t b2, b3, b4;
            read(0, &b2, 1);
            read(0, &b3, 1);
            read(0, &b4, 1);
            if ((b2 < 0x80 || b2 > 0x8f) || (b3 < 0x80 || b3 > 0xbf) || b4 < 0x80 || b4 > 0xbf)
            {
                char *mesg = "There is/are ill-formed byte starting at offset ";
                write(1, mesg, strlen(mesg));
                sprintf(buffer, "%u: ", currentPos);
                write(1, buffer, strlen(buffer));

                sprintf(buffer, "%x ", firstByte);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b2);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b3);
                write(1, buffer, strlen(buffer));
                sprintf(buffer, "%x ", b4);
                write(1, buffer, strlen(buffer));
            }
        }
        // printf("%s", buffer);

    } while (reading != 0);
}

void displayOriginal()
{
    int reading;
    do
    {
        uint8_t c;
        reading = read(0, &c, 1);
        printf("%c", c);
    } while (reading != 0);
}

void displayVerbose()
{
    //
}

int main(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, "aupo")) != -1)
    {
        switch (opt)
        {
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
        case 'v':
            displayVerbose();
            break;
        default:
            break;
        }
    }
}
