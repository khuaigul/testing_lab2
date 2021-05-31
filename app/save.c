#include <stdio.h>
#include "common.h"
#include "text.h"
#include <assert.h>

void save_line (int index, char *line, int cursor, void *f);

/**
 * Загружает содержимое указанного файла
 */
void save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "w")) == 0) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    process_forward(txt, save_line, f);

    fclose(f);
}

void save_line (int index, char *line, int cursor, void *f)
{
    /*Проверка на пустую строку*/
    assert(line != 0);

    /*Неиспользуемые переменные*/
    UNUSED(index);
    UNUSED(cursor);

    /*Вывод строки в файл*/
    fprintf((FILE *)f, "%s\n", line);
}
