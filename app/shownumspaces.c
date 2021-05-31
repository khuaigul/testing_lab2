#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"
#include <string.h>

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит количество пробелов в каждой строке на экран в порядке следования
 */
void shownumspaces(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, 0);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != 0);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /* Считаем количество пробелов */
    int numspaces = 0;
    for (int i = 0; i < (int)strlen(contents); i++)
        if (contents[i] == ' ')
            numspaces++;
    /* Вывод значения на экран*/
    printf("%d\n", numspaces);
}
