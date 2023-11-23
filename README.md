## Tar File Generator

This C program creates a TAR archive (`Results.tar`) by combining multiple files into a single archive. It generates a TAR file containing the headers and contents of the specified input files.

### Program Overview:

#### Structures:
- `struct header`: Represents the header structure for each file in the TAR archive.
  - `name`: Stores the name of the file.
  - `size`: Stores the size of the file.

#### Functionality:

1. **Input**:
   - The program takes file names as command-line arguments.

2. **TAR File Creation**:
   - Opens `Results.tar` in write mode (`"wb"`) to begin writing the TAR file.
   - For each input file:
       - Reads the file's size and creates a header (`struct header`) containing file details.
       - Writes the header into the TAR file.
       - Writes the content of the file into the TAR file.

### Code Details:

- **File Processing**:
    - Opens each specified file in read mode (`"rb"`).
    - Reads the file size and assigns it to the TAR header.
    - Writes the header and file content into `Results.tar`.

- **Command-Line Usage**:
    - The program takes file names as arguments when executed in the command line.

### Running the Program:

1. Compile the program: `gcc minitar.c -o minitar`.
2. Run the executable: `./minitar File1.txt File2.txt`.
3. Replace `file1.txt`, `file2.txt`, etc., with the names of the files you want to include in the TAR archive.

### Example Output:

```
$ ./tar_generator file1.txt file2.txt
[Generates Results.tar containing file1.txt and file2.txt]
```

### Note:

- Ensure the specified files exist in the current directory or provide the correct paths.
- The program creates a TAR archive (`Results.tar`) containing the specified files.
