#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 4;
const int BLOCK_SIZE = 512;
const int JPEG_NB = 50;


int main(int argc, char *argv[])
{
    uint8_t buffer[BLOCK_SIZE];
    int jpgcpt = 0;
    char filename[8];
    sprintf(filename, "%03i.jpg", jpgcpt); // filenames : ###.jpg starting from 000.jpg
    FILE *img = fopen(filename, "w");

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
    while (fread(buffer, BLOCK_SIZE, 1, f) == 512)
    {
        // If start of new JPEG (each JPEG starts with a distinct header)
        if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff & (buffer[3] & 0xf0) == 0xe0)
        {
            // If first JPEG
            if (jpgcpt == 0)
            {
                // Writing the 1rst block into the file
                fwrite(buffer, BLOCK_SIZE, 1, img);
                // Increasing the counter
                jpgcpt++;
            }
            else
            {
                // closing that file only once you encounter another signature
                fclose(img);
                // // Open a new jpeg file for writing
                // filenames : ###.jpg starting from 000.jpg
                sprintf(filename, "%03i.jpg", jpgcpt);
                FILE *img = fopen(filename, "w");
                // Writing the 1rst block into the file
                fwrite(buffer, BLOCK_SIZE, 1, img);
                // Increasing the counter
                jpgcpt++;
            }
        }
        // keep moving on, one block at a time, until you find one JPEGs are stored back-to-back in memory card
        else
        {
            // If a JPEG was already found, keep writing the block into the output file
            if (jpgcpt > 0)
            {
                // Writing the 1rst block into the file
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
        }
    }
    fclose(f);
    fclose(img);
}
