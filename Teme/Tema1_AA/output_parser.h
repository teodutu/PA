#ifndef PRIME_NUMBERS_OUTPUT_PARSER_H
#define PRIME_NUMBERS_OUTPUT_PARSER_H

#include <cstdio>

#define OUTPUT_BUFF_SIZE (1 << 20)

/**
 * Pentru ca testerul si generatorul sa ruleze mai repede, outputul se va parsa.
 */
class OutputWriter {
private:
    static char num[10];
    static char buff[OUTPUT_BUFF_SIZE];
    int pos;
    FILE *p_out_file;

public:

    /**
     * Se deschide fisierul in care se va scrie.
     *
     * @param file_name numele fisierului in care se va scrie
     */
    explicit OutputWriter(char* file_name);

    ~OutputWriter();

    /**
     * Se adauga un nou caracter in buffer.
     *
     * @param c caracterul nou adaugat
     */
    void write_char(char c);

    /**
     * Se scrie un numar intreg in buffer, caracter cu caracter, folosind metoda write_char
     *
     * @param x intregul scris
     */
    void write_int(int x);
};

#endif //PRIME_NUMBERS_OUTPUT_PARSER_H
