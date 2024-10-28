#include "stdafx.h"

namespace Error
{ //	0   -  9   -  системные
	//	10  -  49  -  входных параметров
	//	50  -  89  -  открытия и чтения файлов
	//	90  -  99  -  ошибки лексического анализа
	//  100 -  299  - ошибки синтаксического анализа
	//  300  - 399  - ошибки семантического анализа
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[SYSTEM] Недопустимый код ошибки"), // код ошибки вне диапазона 0 - ERROR_MAX_ENTRY
		ERROR_ENTRY(1, "[SYSTEM] Системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY(10, "[PARM] Параметр -in должен быть задан"),
		ERROR_ENTRY(11, "[PARM] Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(12), ERROR_ENTRY_NODEF(13), ERROR_ENTRY_NODEF(14), ERROR_ENTRY_NODEF(15),
		ERROR_ENTRY_NODEF(16), ERROR_ENTRY_NODEF(17), ERROR_ENTRY_NODEF(18), ERROR_ENTRY_NODEF(19),
		ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY(50, "[FILE] Ошибка при открытии файла с исходным кодом(-in)"),
		ERROR_ENTRY(51, "[FILE] Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(52, "[FILE] Ошибка при создании файла протокола(-log)"),
		ERROR_ENTRY(53, "[PARM] Отсутствие закрывающей кавычки в строковом литерале"),
		ERROR_ENTRY_NODEF(54),
		ERROR_ENTRY_NODEF(55), 
		ERROR_ENTRY_NODEF(56), 	ERROR_ENTRY_NODEF(57), ERROR_ENTRY_NODEF(58), ERROR_ENTRY_NODEF(59),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), 
		ERROR_ENTRY(90, "[LEX] Превышен размер таблицы идентификаторов"),
		ERROR_ENTRY(91, "[LEX] Превышен размер таблицы лексем"),
		ERROR_ENTRY(92, "[LEX] Cлово не разобрано"),
		ERROR_ENTRY(93, "[LEX] Неправильное использование знаков арифметических операций или операции присваивания"), //на этапе лекс
		ERROR_ENTRY(94, "[LEX] В символьной переменной не может быть больше одного символа"), 
		ERROR_ENTRY_NODEF(95), ERROR_ENTRY_NODEF(96),
		ERROR_ENTRY_NODEF(97), ERROR_ENTRY_NODEF(98), ERROR_ENTRY_NODEF(99),
		ERROR_ENTRY(100, "[SYN] Неверная структура программы"),
		ERROR_ENTRY(101, "[SYN] Ошибка в параметрах функции"),
		ERROR_ENTRY(102, "[SYN] Ошибочная конструкция"),
		ERROR_ENTRY(103, "[SYN] Ошибка в выражении"),
		ERROR_ENTRY(104, "[SYN] Ошибка в параметрах вызываемой функции"),
		ERROR_ENTRY(105, "[SYN] Ошибка в построении арифметического выражения"),
		ERROR_ENTRY(106, "[SYN] Ошибка в построении логического выражения"), 
		ERROR_ENTRY(107, "[SYN] Ошибка в теле цикла"),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109), ERROR_ENTRY_NODEF10(110),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170),
		ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF10(200),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250),  ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280),
		ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "[SEM] Превышено максимальное количество параметров при вызове функции"),
		ERROR_ENTRY(301, "[SEM] Попытка переопределения идентификатора"),
		ERROR_ENTRY(302, "[SEM] Отсутствует объявление идентификатора"),
		ERROR_ENTRY(303, "[SEM] Отсутствует точка входа main"),
		ERROR_ENTRY(304, "[SEM] Точка входа main должна быть единственной"),
		ERROR_ENTRY(305, "[SEM] Несоответствие типов"),
		ERROR_ENTRY(306, "[SEM] Запрещено присваивать значение функции"),
		ERROR_ENTRY(307, "[SEM] Запрещено делить на ноль"),
		ERROR_ENTRY(308, "[SEM] Использование стандартных функций без подключения стандартной библиотеки"),
		ERROR_ENTRY(309, "[SEM] Попытка подключить стандартную библиотеку более одного раза"),
		ERROR_ENTRY(310, "[SEM] Попытка проведения операций со строковым типом данных"),
		ERROR_ENTRY(311, "[SEM] Тип возвращаемого значения и тип функции не совпадают"),
		ERROR_ENTRY(312, "[SEM] Неправильное количество параметров при вызове функции"),
		ERROR_ENTRY(313, "[SEM] Неправильный тип параметров при вызове функции"),
		ERROR_ENTRY(314, "[SEM] Превышено допустимое количество параметров функции"),
		ERROR_ENTRY(315, "[SEM] Неправильный вызов функции"),
		ERROR_ENTRY_NODEF(316), ERROR_ENTRY_NODEF(317), ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319)
	};


	ERROR GetError(int id)
	{
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		else
			return errors[id];
	}

	ERROR GetError(int id, int line, int col)
	{
		ERROR dopError = GetError(id);
		dopError.position.col = col;
		dopError.position.line = line;
		return dopError;
	}
}