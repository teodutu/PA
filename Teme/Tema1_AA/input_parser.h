#ifndef PRIME_NUMBERS_INPUT_PARSER_H
#define PRIME_NUMBERS_INPUT_PARSER_H

#include "cstdio"

#define INPUT_BUFF_SIZE (1 << 20)

/**
 * Pentru ca testerul sa ruleze mai repede, inputul se va parsa.
 */
class InputReader {
private:
    static char buff[INPUT_BUFF_SIZE];
    int pos;
    FILE *p_in_file;

public:

    /**
     * Se deschide fisierul din care se va citi.
     *
     * @param file_name numele fiseirului din care se citeste
     */
    explicit InputReader(char* file_name);

    ~InputReader();

    /**
     * Citeste si returneaza un nou caracter din buffer.
     *
     * @return caracterul citit
     */
    char read_char();

    /**
     * Folosind metoda read_char, se formeaza un numar intreg pe 32 de biti din buffer.
     *
     * @return numarul intreg citit
     */
    int read_int();
};

#endif //PRIME_NUMBERS_INPUT_PARSER_H
