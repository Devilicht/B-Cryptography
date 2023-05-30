# B-cryptography
é um programa em C++ que implementa uma funcionalidade básica de criptografia de arquivos e diretórios. Ele utiliza as bibliotecas <iostream>, <fstream>, <dirent.h>, <sys/stat.h> e <cstring> para manipulação de arquivos, diretórios e strings.

## Features

- main: é apresentado um exemplo de uso das funções encryptDirectory e encryptFile. O programa criptografa o conteúdo de um diretório especificado e também de um arquivo específico, chamando as funções com os caminhos adequados.

- encryptFile: ecebe o caminho de um arquivo como parâmetro e realiza a criptografia do conteúdo do arquivo. Para isso, o programa abre o arquivo original em modo de leitura e cria um arquivo temporário em modo de escrita. Em seguida, ele lê cada byte do arquivo original, incrementa o valor desse byte em 1 e escreve o byte criptografado no arquivo temporário. Ao final do processo, o arquivo original é fechado e o arquivo temporário é renomeado para substituir o arquivo original.

- encryptDirectory: recebe o caminho de um diretório como parâmetro e realiza a criptografia de todos os arquivos encontrados nesse diretório e em seus subdiretórios. Para isso, o programa utiliza as funções opendir e readdir para percorrer as entradas (arquivos e subdiretórios) no diretório especificado. Em cada iteração, o programa verifica se a entrada é um diretório ou um arquivo. Se for um diretório, a função encryptDirectory é chamada recursivamente para criptografar os arquivos dentro desse diretório. Se for um arquivo, a função encryptFile é chamada para criptografar o arquivo.

## How to use
Para usar basta simplesmente adicionar o caminho como parametro ao chamar a função na main, depois compilar e rodar.
