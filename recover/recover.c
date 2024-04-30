#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 4;
const int BLOCK_SIZE = 512;
const int JPEG_NB = 50;


int main(int argc, char *argv[])
{
    char buffer[BLOCK_SIZE];
    int jpgcpt = 0;

    if (argc != 2)
    {
        printf("There can be only one command-line argument.\n");
        return 1;
    }

    // Open memory card
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Read 512 bytes into a buffer and repeat until the end of card:
    while (fread(*buffer, BLOCK_SIZE, 1, f))
    {
        // If start of new JPEG (each JPEG starts with a distinct header)
        if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff & (buffer[3] & 0xf0) == 0xe0)
        {
            // make a new file
            // filenames : ###.jpg starting from 000.jpg
            // If first JPEG
                // ...
            // Else // JPEGs are stored back-to-back in memory card
                // keep moving on, one block at a time, until you find one
        }
        // Else
            // If already found JPEG
                // ...
    }
    open a new jpeg file for writing
    start filling that file with bytes from my memory card
    closing that file only once you encounter another signature
}
