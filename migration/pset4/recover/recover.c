#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Return the right way to use the program
    if (argc != 2)
    {
        printf("Usage: ./recover imagen\n");
        return 1;
    }
    
    // Define the type of BYTE
    typedef uint8_t BYTE;
    
    // Get the position of the input
    // Open it and read what has inside
    char *in_file = argv[1];
    FILE *file = fopen(in_file, "r");
    
    // If has nothing in file, return an error
    if (file == NULL)
    {
        printf("Can't open the file\n");
        return 2;
    }
    
    // Declare the size of BYTE
    BYTE buffer[512];
    
    // Count increase one when found a new jpeg
    int count = 0;
    // Create an array to store the new jpeg
    char names[8];
    // Print inside of name an jpeg called 00(count)
    sprintf(names, "%03i.jpg", count);
    
    // Write in NEWFILE the new jpeg recovered
    FILE *newfile = fopen(names, "w");
    
    if (newfile == NULL)
    {
        printf("Could not open the file");
        
        return 3;
    }
    
    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        // See if it`s an valid jpeg 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // See if it`s the first jpeg
            if (count == 0)
            {
                fwrite(buffer, sizeof(BYTE), 512, newfile);
                count++;
            }
            // If it`s not the first
            else 
            {
                fclose(newfile);
                
                sprintf(names, "%03i.jpg", count);
                newfile = fopen(names, "w");
                
                if (newfile == NULL)
                {
                    printf("Can't open the file\n");
                    return 4;
                }
                fwrite(buffer, sizeof(BYTE), 512, newfile);
                count++;
            }
        }
        else if (count)
        {

            fwrite(buffer, sizeof(BYTE), 512, newfile);
        }
    }
    // Close the file
    fclose(file);

}