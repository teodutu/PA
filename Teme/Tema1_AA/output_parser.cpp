#include "output_parser.h"

char OutputWriter::buff[OUTPUT_BUFF_SIZE];
char OutputWriter::num[10];

OutputWriter::OutputWriter(char *file_name) {
    pos = 0;
    p_out_file = fopen(file_name, "w");
}

OutputWriter::~OutputWriter() {
    // se scriu in fisier ultimele caractere ramase in buffer
    if (pos) {
        fwrite(buff, sizeof(char), pos, p_out_file);
    }

    fclose(p_out_file);
}

void OutputWriter::write_char(char c) {
    // se adauga caracterul in buffer
    buff[pos++] = c;

    // cand s-a umplut buffer-ul, acesta se scrie in fisier
    if (pos == OUTPUT_BUFF_SIZE) {
        fwrite(buff, sizeof(char), OUTPUT_BUFF_SIZE, p_out_file);
        pos = 0;
    }
}

void OutputWriter::write_int(int x) {
    int i = 0;

    // se extrag cifrele numarului x
    do {
        num[i++] = x % 10 + '0';
    } while (x /= 10);

    // fiecare cifrea se scrie in fisier
    while (i--) {
        write_char(num[i]);
    }
}