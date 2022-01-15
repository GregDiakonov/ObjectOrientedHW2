#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "container.h"

using std::string;
using std::ifstream;
using std::ofstream;

void CommandLineArgsErrorMessage();
bool CheckCommandLineArgs(int argc, char* argv[]);

// Сюда записываются аргументы командной строки
string input_file;
string output_file;
bool isFromFile=true;
int data_size;

/*
 * Алгоритм работы программы.
 * 1. Запуск таймера для подсчётов времени.
 * 2. Идёт проверка и запись аргументов командной строки.
 * 3. Контейнер заполняется согласно одному из режимов заполнения.
 * 4. Считается общая функция для каждого из элементов контейнера.
 * 5. Отсортированное по возрастанию времени прибытия, содержимое контейнера выписывается в файл.
 */
int main(int argc, char** argv) {
    clock_t start = clock();
    if(!CheckCommandLineArgs(argc, argv)) {
        CommandLineArgsErrorMessage();
        return 1;
    }
    container cont = container::Initialize(data_size);
    if(isFromFile) {
        cont.Input(input_file);
    } else {
        cont.InputRandom();
        cont.RawOutput(input_file);
    }
    cont.CountCommonFunction();
    cont.SortFunction(output_file);
    std::cout << "Done! Check the output file!\n";
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Program work time: " << seconds << "seconds.\n";
    return 0;
}

bool CheckCommandLineArgs(int argc, char** argv) {
    if(argc!=5) {
        return false;
    }
    input_file = *(argv+1);
    output_file = *(argv+2);
    string file_mode = *(argv+3);
    ifstream file;
    file.open(input_file);
    if(!file) {
        std::cout << "Wrong input file! ";
        return false;
    }
    file.close();
    file.open(output_file);
    if(!file){
        std::cout << "Wrong output file! ";
        return false;
    }
    file.close();
    if(file_mode=="-f") {
        isFromFile=true;
    } else if(file_mode=="-r") {
        isFromFile=false;
    } else {
        std::cout << "Wrong input identifier! ";
        return false;
    }
    data_size = atoi(*(argv+4));
    if(data_size<=0 || data_size > MAX_LENGTH) {
        std::cout << "Wrong lines number! ";
        return false;
    }
    return true;
}

// Сообщение, которое появляется при неправильных аргументах командной строки.
void CommandLineArgsErrorMessage() {
    printf("Sorry, your command line arguments are unsuitable.\n");
    printf("Press ENTER to close the program...\n");
    while( getchar() != '\n' );
}