#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMSIZ 100 // maximum length of name field
#define buffer_size 1024
struct header
{
    char name[NAMSIZ];
    char size[12];
};

void generateResultTar(char **files, int num_files)
{
    // once arguments file1,file2 is executed on cli, then this funct should generate a results.tar to begin writing.
    FILE *results_tar = fopen("Results.tar", "wb"); // wb means write mode

    for (int i = 0; i < num_files; i++)
    {
        FILE *fp;
        int file_size;
        // file pointer
        fp = fopen(files[i], "rb"); // rb means read mode

        // check the file size.
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp); // gets the size of the file
        rewind(fp);            // resets the file pointer to start

        // assign values to the structure header
        struct header file_header;
        memset(&file_header, 0, sizeof(struct header)); // clear memory
        strncpy(file_header.name, files[i], NAMSIZ);
        sprintf(file_header.size, "%011lo\n", file_size);
        // fwrite header to tar file
        fwrite(&file_header, sizeof(struct header), 1, results_tar); // write file_header into results.tar file.

        // write file content to Results.tar
        char buffer[buffer_size];
        size_t bytes_read;
        char newline = '\n';
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0)
        {
            fwrite(buffer, 1, bytes_read, results_tar);
            fwrite(&newline, sizeof(char), 1, results_tar);
        }

        // close the file after loop
        fclose(fp);
    }
    // good practice to close file.
    fclose(results_tar);
}

// take in the arguments in cli
int main(int argc, char **argv)
{
    generateResultTar(argv + 1, argc - 1);
    return 0;
}
