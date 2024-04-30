#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("There can be only one command-line argument.\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }
    a program that iterates over a copy of my memory card, looking for JPEGs’ signatures.
    Each time you find a signature, you can open a new file for writing
     and start filling that file with bytes from my memory card,
     closing that file only once you encounter another signature. Moreover,
     rather than read my memory card’s bytes one at a time,
     you can read 512 of them at a time into a buffer for efficiency’s sake.
     Thanks to FAT, you can trust that JPEGs’ signatures will be “block-aligned.”
     That is, you need only look for those signatures in a block’s first four bytes.
      I’ve only imaged the first few megabytes of the memory card. But you should ultimately find that the image contains 50 JPEGs.
    // Open memory card
    // Repeat until the end of card:
        // Read 512 bytes into a buffer
        // If start of new JPEG
            // If first JPEG
                // ...
            // Else
                // ...
        // Else
            // If already found JPEG
                // ...


}
