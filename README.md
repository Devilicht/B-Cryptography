# B-cryptography
B-cryptography is a C++ program that implements basic file and directory encryption functionality. It uses the libraries <iostream>, <fstream>, <dirent.h>, <sys/stat.h>, and <cstring> for file, directory, and string manipulation.


## Features
- main: An example usage of the encryptDirectory and encryptFile functions is presented. The program encrypts the contents of a specified directory and a specific file by calling the functions with the appropriate paths.

- encryptFile: This function takes the path of a file as a parameter and encrypts the contents of the file. It opens the original file in read mode and creates a temporary file in write mode. Then, it reads each byte of the original file, increments the value of that byte by 1, and writes the encrypted byte to the temporary file. After the process is complete, the original file is closed, and the temporary file is renamed to replace the original file.

- encryptDirectory: This function takes the path of a directory as a parameter and encrypts all the files found in that directory and its subdirectories. It uses the opendir and readdir functions to iterate over the entries (files and subdirectories) in the specified directory. In each iteration, the program checks if the entry is a directory or a file. If it is a directory, the encryptDirectory function is called recursively to encrypt the files within that directory. If it is a file, the encryptFile function is called to encrypt the file.

## How to use
To use B-cryptography, simply add the path as a parameter when calling the function in the main function. Then, compile and run the program.
