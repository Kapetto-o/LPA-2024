#pragma once
#include "stdafx.h"

struct GRAPH
{
	char lex;
	FST::FST graph;		// Недетерминированный конечный автомат
};

// Идентификаторы

#define GRAPH_IDENTIFIERS \
    3, \
	FST::NODE(25, \
        FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), \
        FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1), \
        FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), \
		FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
		FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), \
		FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), \
		FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), \
		FST::RELATION('v', 1), FST::RELATION('x', 1), FST::RELATION('y', 1), \
		FST::RELATION('z', 1), FST::RELATION('a', 3), FST::RELATION('b', 3), \
		FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3), \
		FST::RELATION('f', 3), FST::RELATION('g', 3), FST::RELATION('h', 3), \
		FST::RELATION('i', 3), FST::RELATION('j', 3), FST::RELATION('k', 3), \
		FST::RELATION('l', 3), FST::RELATION('m', 3), FST::RELATION('n', 3), \
		FST::RELATION('o', 3), FST::RELATION('p', 3), FST::RELATION('q', 3), \
		FST::RELATION('b', 3),), \
    FST::NODE(70, \
        FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), \
        FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1), \
        FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), \
		FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
		FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), \
		FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), \
		FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), \
		FST::RELATION('v', 1), FST::RELATION('x', 1), FST::RELATION('y', 1), \
		FST::RELATION('z', 1), FST::RELATION('0', 1), FST::RELATION('1', 1), \
		FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), \
		FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
		FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('a', 2), \
		FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
		FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), \
		FST::RELATION('h', 2), FST::RELATION('i', 2), FST::RELATION('j', 2), \
		FST::RELATION('k', 2), FST::RELATION('l', 2), FST::RELATION('m', 2), \
		FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
		FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), \
		FST::RELATION('t', 2), FST::RELATION('u', 2), FST::RELATION('v', 2), \
		FST::RELATION('x', 2), FST::RELATION('y', 2), FST::RELATION('z', 2), \
		FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), \
		FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
		FST::RELATION('9', 2),), \
    FST::NODE()

// Литералы

#define GRAPH_INT_LITERAL_8 \
    4, \
    FST::NODE(3, \
        FST::RELATION('-', 1), FST::RELATION('0', 2), FST::RELATION('0', 4)), \
    FST::NODE(1, FST::RELATION('0', 2)), \
	FST::NODE(14, \
        FST::RELATION('1', 3), FST::RELATION('2', 3), FST::RELATION('3', 3), \
        FST::RELATION('4', 3), FST::RELATION('5', 3), FST::RELATION('6', 3), \
        FST::RELATION('7', 3), FST::RELATION('1', 4), FST::RELATION('2', 4), \
		FST::RELATION('3', 4), FST::RELATION('4', 4), FST::RELATION('5', 4), \
		FST::RELATION('6', 4), FST::RELATION('7', 4)), \
    FST::NODE(8, \
        FST::RELATION('0', 3), FST::RELATION('1', 3), FST::RELATION('2', 3), \
        FST::RELATION('3', 3), FST::RELATION('4', 3), FST::RELATION('5', 3), \
        FST::RELATION('6', 3), FST::RELATION('7', 3), FST::RELATION('0', 4), \
		FST::RELATION('1', 4), FST::RELATION('2', 4), FST::RELATION('3', 4), \
        FST::RELATION('4', 4), FST::RELATION('5', 4), FST::RELATION('6', 4), \
		FST::RELATION('7', 4)), \
    FST::NODE()

#define GRAPH_INT_LITERAL_10  \
    4, \
    FST::NODE(11, \
        FST::RELATION('-', 1), FST::RELATION('1', 2), FST::RELATION('2', 2), \
        FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), \
        FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
        FST::RELATION('9', 2), FST::RELATION('0', 3)), \
    FST::NODE(18, \
        FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
        FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
        FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), \
        FST::RELATION('1', 3), FST::RELATION('2', 3), FST::RELATION('3', 3), \
        FST::RELATION('4', 3), FST::RELATION('5', 3), FST::RELATION('6', 3), \
        FST::RELATION('7', 3), FST::RELATION('8', 3), FST::RELATION('9', 3)), \
    FST::NODE(20, \
        FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), \
        FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), \
        FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
        FST::RELATION('9', 2), FST::RELATION('0', 3), FST::RELATION('1', 3), \
		FST::RELATION('2', 3), FST::RELATION('3', 3), FST::RELATION('4', 3), \
        FST::RELATION('5', 3), FST::RELATION('6', 3), FST::RELATION('7', 3), \
        FST::RELATION('8', 3), FST::RELATION('9', 3)), \
    FST::NODE()

// Функции
#define GRAPH_MAIN \
	5, \
	FST::NODE(1,FST::RELATION('m', 1)), \
	FST::NODE(1,FST::RELATION('a', 2)), \
	FST::NODE(1,FST::RELATION('i', 3)), \
	FST::NODE(1,FST::RELATION('n', 4)), \
	FST::NODE()
#define GRAPH_RETURN \
	7, \
	FST::NODE(1,FST::RELATION('r', 1)), \
	FST::NODE(1,FST::RELATION('e', 2)), \
	FST::NODE(1,FST::RELATION('t', 3)), \
	FST::NODE(1,FST::RELATION('u', 4)), \
	FST::NODE(1,FST::RELATION('r', 5)), \
	FST::NODE(1,FST::RELATION('n', 6)), \
	FST::NODE()
#define GRAPH_STRDUPLICATE \
	13, \
	FST::NODE(1,FST::RELATION('s', 1)), \
	FST::NODE(1,FST::RELATION('t', 2)), \
	FST::NODE(1,FST::RELATION('r', 3)), \
	FST::NODE(1,FST::RELATION('d', 4)), \
	FST::NODE(1,FST::RELATION('u', 5)), \
	FST::NODE(1,FST::RELATION('p', 6)), \
	FST::NODE(1,FST::RELATION('l', 7)), \
	FST::NODE(1,FST::RELATION('i', 8)), \
	FST::NODE(1,FST::RELATION('c', 9)), \
	FST::NODE(1,FST::RELATION('a', 10)), \
	FST::NODE(1,FST::RELATION('t', 11)), \
	FST::NODE(1,FST::RELATION('e', 12)), \
	FST::NODE()
#define GRAPH_STRLENGTH \
	10, \
	FST::NODE(1,FST::RELATION('s', 1)), \
	FST::NODE(1,FST::RELATION('t', 2)), \
	FST::NODE(1,FST::RELATION('r', 3)), \
	FST::NODE(1,FST::RELATION('l', 4)), \
	FST::NODE(1,FST::RELATION('e', 5)), \
	FST::NODE(1,FST::RELATION('n', 6)), \
	FST::NODE(1,FST::RELATION('g', 7)), \
	FST::NODE(1,FST::RELATION('t', 8)), \
	FST::NODE(1,FST::RELATION('h', 9)), \
	FST::NODE()
#define GRAPH_STRTRANSINT \
	12, \
	FST::NODE(1,FST::RELATION('s', 1)), \
	FST::NODE(1,FST::RELATION('t', 2)), \
	FST::NODE(1,FST::RELATION('r', 3)), \
	FST::NODE(1,FST::RELATION('t', 4)), \
	FST::NODE(1,FST::RELATION('r', 5)), \
	FST::NODE(1,FST::RELATION('a', 6)), \
	FST::NODE(1,FST::RELATION('n', 7)), \
	FST::NODE(1,FST::RELATION('s', 8)), \
	FST::NODE(1,FST::RELATION('i', 9)), \
	FST::NODE(1,FST::RELATION('n', 10)), \
	FST::NODE(1,FST::RELATION('t', 11)), \
	FST::NODE()

// Операторы вывода и цикл

#define GRAPH_WRITELINE \
	10, \
	FST::NODE(1,FST::RELATION('w', 1)), \
	FST::NODE(1,FST::RELATION('r', 2)), \
	FST::NODE(1,FST::RELATION('i', 3)), \
	FST::NODE(1,FST::RELATION('t', 4)), \
	FST::NODE(1,FST::RELATION('e', 5)), \
	FST::NODE(1,FST::RELATION('l', 6)), \
	FST::NODE(1,FST::RELATION('i', 7)), \
	FST::NODE(1,FST::RELATION('n', 8)), \
	FST::NODE(1,FST::RELATION('e', 9)), \
	FST::NODE()
#define GRAPH_WRITE \
	6, \
	FST::NODE(1,FST::RELATION('w', 1)), \
	FST::NODE(1,FST::RELATION('r', 2)), \
	FST::NODE(1,FST::RELATION('i', 3)), \
	FST::NODE(1,FST::RELATION('t', 4)), \
	FST::NODE(1,FST::RELATION('e', 5)), \
	FST::NODE()
#define GRAPH_CYCLE \
	6, \
	FST::NODE(1,FST::RELATION('c', 1)), \
	FST::NODE(1,FST::RELATION('y', 2)), \
	FST::NODE(1,FST::RELATION('c', 3)), \
	FST::NODE(1,FST::RELATION('l', 4)), \
	FST::NODE(1,FST::RELATION('e', 5)), \
	FST::NODE()

// Скобки

#define GRAPH_LEFTBRACE_OPEN \
	2, \
	FST::NODE(1,FST::RELATION('{', 1)), \
	FST::NODE()
#define GRAPH_RIGHTBRACE_CLOSE \
	2, \
	FST::NODE(1,FST::RELATION('}', 1)), \
	FST::NODE()
#define GRAPH_LEFTHESIS_OPEN \
	2, \
	FST::NODE(1,FST::RELATION('(', 1)), \
	FST::NODE()
#define GRAPH_RIGHTHESIS_CLOSE \
	2, \
	FST::NODE(1,FST::RELATION(')', 1)), \
	FST::NODE()

// Арифметические операторы

#define GRAPH_ADDITION \
	2, \
	FST::NODE(1,FST::RELATION('+', 1)), \
	FST::NODE()
#define GRAPH_SUBSTRACTION \
	2, \
	FST::NODE(1,FST::RELATION('-', 1)), \
	FST::NODE()
#define GRAPH_MULTIPLICATION \
	2, \
	FST::NODE(1,FST::RELATION('*', 1)), \
	FST::NODE()
#define GRAPH_DIVISION \
	2, \
	FST::NODE(1,FST::RELATION('/', 1)), \
	FST::NODE()
#define GRAPH_REMAINDERDIVISION \
	2, \
	FST::NODE(1,FST::RELATION('%', 1)), \
	FST::NODE()
#define GRAPH_EQUALS \
	2, \
	FST::NODE(1,FST::RELATION('=', 1)), \
	FST::NODE()

// Операторы сравнения

#define GRAPH_MORE \
	2, \
	FST::NODE(1,FST::RELATION('>', 1)), \
	FST::NODE()
#define GRAPH_LESS \
	2, \
	FST::NODE(1,FST::RELATION('<', 1)), \
	FST::NODE()
#define GRAPH_MOREEQUAL \
	3, \
	FST::NODE(1,FST::RELATION('>', 1)), \
	FST::NODE(1,FST::RELATION('=', 2)), \
	FST::NODE()
#define GRAPH_LESSEQUAL \
	3, \
	FST::NODE(1,FST::RELATION('<', 1)), \
	FST::NODE(1,FST::RELATION('=', 2)), \
	FST::NODE()
#define GRAPH_INEQUALITY \
	3, \
	FST::NODE(1,FST::RELATION('=', 1)), \
	FST::NODE(1,FST::RELATION('=', 2)), \
	FST::NODE()
#define GRAPH_NOTEQUALS \
	3, \
	FST::NODE(1,FST::RELATION('!', 1)), \
	FST::NODE(1,FST::RELATION('=', 2)), \
	FST::NODE()

// Разное

#define GRAPH_COMMA \
	2, \
	FST::NODE(1,FST::RELATION(',', 1)), \
	FST::NODE()

#define GRAPH_SEMICOLON \
	2, \
	FST::NODE(1,FST::RELATION(';', 1)), \
	FST::NODE()