#include "input_parser.h"

char InputReader::buff[INPUT_BUFF_SIZE];

InputReader::InputReader(char* file_name) {
    pos = INPUT_BUFF_SIZE;
    p_in_file = fopen(file_name, "r");
}

InputReader::~InputReader() {
        fclose(p_in_file);
}

char InputReader::read_char() {
    // cand s-a parcurs tot buffer-ul, se citeste o noua serie de caractere in acesta
    if (pos == INPUT_BUFF_SIZE) {
        fread(buff, sizeof(char), INPUT_BUFF_SIZE, p_in_file);
        pos = 0;
    }

    // se citeste un nou caracter din buffer
    return buff[pos++];
}

int InputReader::read_int() {
    int integer = 0;
    char c;

    // se ignora caracterele ce nu sunt cifre
    do {
        c = read_char();
    } while (c < '0' || c > '9');

    // se creeaza urmatorul numar intreg din buffer
    do {
        integer = (integer << 1) + (integer << 3) + c - '0';
        c = read_char();
    } while (c >= '0' && c <= '9');

    return integer;
}