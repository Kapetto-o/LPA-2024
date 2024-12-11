#pragma once
#include "FST.h"

struct GRAPH
{
	char lex;
	FST::FST graph;		// ������������������� �������� �������
};

// ���� ������

#define GRAPH_SHORT \
	4, \
	FST::NODE(1, FST::RELATION('i', 1)), \
	FST::NODE(1, FST::RELATION('n', 2)), \
	FST::NODE(1, FST::RELATION('t', 3)), \
	FST::NODE()

#define GRAPH_CHAR \
	5, \
	FST::NODE(1, FST::RELATION('c', 1)), \
	FST::NODE(1, FST::RELATION('h', 2)), \
	FST::NODE(1, FST::RELATION('a', 3)), \
	FST::NODE(1, FST::RELATION('r', 4)), \
	FST::NODE()

#define GRAPH_STR \
	4, \
	FST::NODE(1, FST::RELATION('s', 1)), \
	FST::NODE(1, FST::RELATION('t', 2)), \
	FST::NODE(1, FST::RELATION('r', 3)), \
	FST::NODE()

#define GRAPH_BOOL \
	5, \
	FST::NODE(1, FST::RELATION('b', 1)), \
	FST::NODE(1, FST::RELATION('o', 2)), \
	FST::NODE(1, FST::RELATION('o', 3)), \
	FST::NODE(1, FST::RELATION('l', 4)), \
	FST::NODE()

// ��������������

#define GRAPH_IDENTIFIERS \
    3, \
	FST::NODE(52, \
        FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), \
        FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1), \
        FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), \
		FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
		FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), \
		FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), \
		FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), \
		FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
		FST::RELATION('y', 1), FST::RELATION('z', 1), \
		FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), \
		FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2), \
		FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), \
		FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
		FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), \
		FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2), \
		FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), \
		FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
		FST::RELATION('y', 2), FST::RELATION('z', 2)), \
    FST::NODE(72, \
        FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), \
        FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1), \
        FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), \
		FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
		FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), \
		FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), \
		FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), \
		FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
		FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('0', 1), \
		FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
		FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), \
		FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), \
		\
		FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), \
        FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2), \
        FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), \
		FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
		FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), \
		FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2), \
		FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), \
		FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
		FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('0', 2), \
		FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
		FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
		FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2)), \
    FST::NODE()

// ��������

#define GRAPH_BOOL_TRUE \
	5, \
	FST::NODE(1, FST::RELATION('t', 1)), \
	FST::NODE(1, FST::RELATION('r', 2)), \
	FST::NODE(1, FST::RELATION('u', 3)), \
	FST::NODE(1, FST::RELATION('e', 4)), \
	FST::NODE()
#define GRAPH_BOOL_FALSE \
	6, \
	FST::NODE(1, FST::RELATION('f', 1)), \
	FST::NODE(1, FST::RELATION('a', 2)), \
	FST::NODE(1, FST::RELATION('l', 3)), \
	FST::NODE(1, FST::RELATION('s', 4)), \
	FST::NODE(1, FST::RELATION('e', 5)), \
	FST::NODE()

#define GRAPH_SHORT_LITERAL_8 \
    5, \
    FST::NODE(3, \
        FST::RELATION('-', 1), FST::RELATION('0', 2), FST::RELATION('0', 4)), \
    FST::NODE(1, FST::RELATION('0', 2)), \
	FST::NODE(14, \
        FST::RELATION('1', 3), FST::RELATION('2', 3), FST::RELATION('3', 3), \
        FST::RELATION('4', 3), FST::RELATION('5', 3), FST::RELATION('6', 3), \
        FST::RELATION('7', 3), \
		FST::RELATION('1', 4), FST::RELATION('2', 4), FST::RELATION('3', 4), \
		FST::RELATION('4', 4), FST::RELATION('5', 4), FST::RELATION('6', 4), \
		FST::RELATION('7', 4)), \
    FST::NODE(16, \
        FST::RELATION('0', 3), FST::RELATION('1', 3), FST::RELATION('2', 3), \
        FST::RELATION('3', 3), FST::RELATION('4', 3), FST::RELATION('5', 3), \
        FST::RELATION('6', 3), FST::RELATION('7', 3), \
		FST::RELATION('0', 4), FST::RELATION('1', 4), FST::RELATION('2', 4), \
		FST::RELATION('3', 4), FST::RELATION('4', 4), FST::RELATION('5', 4), \
		FST::RELATION('6', 4), FST::RELATION('7', 4)), \
    FST::NODE()

#define GRAPH_SHORT_LITERAL_10  \
    4, \
    FST::NODE(11, \
        FST::RELATION('-', 1), FST::RELATION('0', 3), \
		FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
		FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
		FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2)), \
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
        FST::RELATION('9', 2), \
		FST::RELATION('0', 3), FST::RELATION('1', 3), FST::RELATION('2', 3), \
		FST::RELATION('3', 3), FST::RELATION('4', 3), FST::RELATION('5', 3), \
		FST::RELATION('6', 3), FST::RELATION('7', 3), FST::RELATION('8', 3), \
		FST::RELATION('9', 3)), \
    FST::NODE()

#define GRAPH_STRING_LITERAL \
	4, \
	FST::NODE(2, FST::RELATION('\"', 1), FST::RELATION('\"', 2)), \
	FST::NODE(290, \
		FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), \
		FST::RELATION('D', 1), FST::RELATION('E', 1), FST::RELATION('F', 1), \
		FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), \
		FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1), \
		FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), \
		FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1), \
		FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), \
		FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), \
		FST::RELATION('Y', 1), FST::RELATION('Z', 1), \
		FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), \
		FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1), \
		FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), \
		FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
		FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), \
		FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1), \
		FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), \
		FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
		FST::RELATION('y', 1), FST::RELATION('z', 1), \
		\
		FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), \
		FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), \
		FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), \
		FST::RELATION('9', 1), \
		\
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		\
		FST::RELATION(' ', 1), FST::RELATION('.', 1), FST::RELATION(',', 1), \
		FST::RELATION('?', 1), FST::RELATION('!', 1), FST::RELATION(';', 1), \
		FST::RELATION(':', 1), FST::RELATION('-', 1), FST::RELATION(')', 1), \
		FST::RELATION('(', 1), FST::RELATION('<', 1), FST::RELATION('>', 1), \
		FST::RELATION('/', 1), FST::RELATION('%', 1), FST::RELATION('=', 1), \
		FST::RELATION('+', 1), FST::RELATION('*', 1), \
		\
		FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2), \
		FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2), \
		FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('I', 2), \
		FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2), \
		FST::RELATION('M', 2), FST::RELATION('N', 2), FST::RELATION('O', 2), \
		FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2), \
		FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), \
		FST::RELATION('V', 2), FST::RELATION('W', 2), FST::RELATION('X', 2), \
		FST::RELATION('Y', 2), FST::RELATION('Z', 2), \
		FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), \
		FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2), \
		FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), \
		FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
		FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), \
		FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2), \
		FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), \
		FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
		FST::RELATION('y', 2), FST::RELATION('z', 2), \
		\
		FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), \
		FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
		FST::RELATION('9', 2), \
		\
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		\
		FST::RELATION(' ', 2), FST::RELATION('.', 2), FST::RELATION(',', 2), \
		FST::RELATION('?', 2), FST::RELATION('!', 2), FST::RELATION(';', 2), \
		FST::RELATION(':', 2), FST::RELATION('-', 2), FST::RELATION(')', 2), \
		FST::RELATION('(', 2), FST::RELATION('<', 2), FST::RELATION('>', 2), \
		FST::RELATION('/', 2), FST::RELATION('%', 2), FST::RELATION('=', 2), \
		FST::RELATION('+', 2), FST::RELATION('*', 2)), \
	FST::NODE(1, FST::RELATION('\"', 3)), \
	FST::NODE()

#define GRAPH_CHAR_LITERAL \
	4, \
	FST::NODE(2, FST::RELATION('\'', 1), FST::RELATION('\'', 2)), \
	FST::NODE(145, \
		FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2), \
		FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2), \
		FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('I', 2), \
		FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2), \
		FST::RELATION('M', 2), FST::RELATION('N', 2), FST::RELATION('O', 2), \
		FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2), \
		FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), \
		FST::RELATION('V', 2), FST::RELATION('W', 2), FST::RELATION('X', 2), \
		FST::RELATION('Y', 2), FST::RELATION('Z', 2), \
		FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), \
		FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2), \
		FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), \
		FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
		FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), \
		FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2), \
		FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), \
		FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
		FST::RELATION('y', 2), FST::RELATION('z', 2), \
		\
		FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), \
		FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
		FST::RELATION('9', 2), \
		\
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		\
		FST::RELATION(' ', 2), FST::RELATION('.', 2), FST::RELATION(',', 2), \
		FST::RELATION('?', 2), FST::RELATION('!', 2), FST::RELATION(';', 2), \
		FST::RELATION(':', 2), FST::RELATION('-', 2), FST::RELATION(')', 2), \
		FST::RELATION('(', 2), FST::RELATION('<', 2), FST::RELATION('>', 2), \
		FST::RELATION('/', 2), FST::RELATION('%', 2), FST::RELATION('=', 2), \
		FST::RELATION('+', 2), FST::RELATION('*', 2)), \
	FST::NODE(1, FST::RELATION('\'', 3)), \
	FST::NODE()

// �������

#define GRAPH_MAIN \
	5, \
	FST::NODE(1,FST::RELATION('m', 1)), \
	FST::NODE(1,FST::RELATION('a', 2)), \
	FST::NODE(1,FST::RELATION('i', 3)), \
	FST::NODE(1,FST::RELATION('n', 4)), \
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

// �������� �����

#define GRAPH_RETURN \
	7, \
	FST::NODE(1,FST::RELATION('r', 1)), \
	FST::NODE(1,FST::RELATION('e', 2)), \
	FST::NODE(1,FST::RELATION('t', 3)), \
	FST::NODE(1,FST::RELATION('u', 4)), \
	FST::NODE(1,FST::RELATION('r', 5)), \
	FST::NODE(1,FST::RELATION('n', 6)), \
	FST::NODE()

#define GRAPH_NEW \
	4, \
	FST::NODE(1,FST::RELATION('n', 1)), \
	FST::NODE(1,FST::RELATION('e', 2)), \
	FST::NODE(1,FST::RELATION('w', 3)), \
	FST::NODE()

#define GRAPH_FUNCTION \
	9, \
	FST::NODE(1,FST::RELATION('f', 1)), \
	FST::NODE(1,FST::RELATION('u', 2)), \
	FST::NODE(1,FST::RELATION('n', 3)), \
	FST::NODE(1,FST::RELATION('c', 4)), \
	FST::NODE(1,FST::RELATION('t', 5)), \
	FST::NODE(1,FST::RELATION('i', 6)), \
	FST::NODE(1,FST::RELATION('o', 7)), \
	FST::NODE(1,FST::RELATION('n', 8)), \
	FST::NODE()

// ��������� ������ � �����

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

// ������

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

// �������������� ���������

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

// ��������� ���������

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

// ������

#define GRAPH_COMMA \
	2, \
	FST::NODE(1,FST::RELATION(',', 1)), \
	FST::NODE()

#define GRAPH_SEMICOLON \
	2, \
	FST::NODE(1,FST::RELATION(';', 1)), \
	FST::NODE()