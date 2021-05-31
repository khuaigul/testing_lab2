/**
 * remove_all.c -- реализует функцию очистки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == 0) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    
    
    /* Если список изначально пуст, делать ничего не надо */
    if (txt->length == 0) {
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != 0 && txt->end != 0);
    
    /* Стартуем с первого элемента списка */
    node *current = txt->begin;

    do {
        /* Запоминаем адрес следующего элемента */
        node *next = current->next;
        /* Освобождаем память, выделенную под текущий элемент */
        free(current);
        /* Продвигаемся к следующему элементу */
        current = next;
    } while (current);

    /* Реинициализируем текст */
    txt->length = 0;
    txt->begin = 0;
    txt->end = 0;
    txt->cursor->line = 0;
    txt->cursor->position = 0;
}
