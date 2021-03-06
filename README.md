# Architecture-of-Electronic-Computers

# First Lab

This repository will contain laboratories on the topic of computer architecture

* a. int sc_memoryInit () – инициализирует оперативную память Simple Computer, задавая всем еѐ ячейкам нулевые значения. В качестве «оперативной памяти» используется массив целых чисел, определенный статически в рамках библиотеки. Размер массива равен 100 элементам.
* b. int sc_memorySet (int address, int value) – задает значение указанной
ячейки памяти как value. Если адрес выходит за допустимые границы, то устанавливается флаг «выход за границы памяти» и работа функции прекращается с ошибкой;
* c. int sc_memoryGet (int address, int * value) – возвращает значение указанной ячейки памяти в value. Если адрес выходит за допустимые границы, то устанавливается флаг «выход за границы памяти» и работа функции прекращается с ошибкой.
Значение value в этом случае не изменяется.
* d. int sc_memorySave (char * filename) – сохраняет содержимое памяти в файл в
бинарном виде (используя функцию write или fwrite);
* e. int sc_memoryLoad (char * filename) – загружает из указанного файла содержимое оперативной памяти (используя функцию read или fread);
* f. int sc_regInit (void) – инициализирует регистр флагов нулевым значением;
* g. int sc_regSet (int register, int value) – устанавливает значение указанного регистра флагов. Для номеров регистров флагов должны использоваться маски, задаваемые макросами (#define). Если указан недопустимый номер регистра или некорректное значение, то функция завершается с ошибкой.
* h. int sc_regGet (int register, int * value) – возвращает значение указанного
флага. Если указан недопустимый номер регистра, то функция завершается с ошибкой.
* i. int sc_commandEncode (int command, int operand, int * value) – кодирует команду с указанным номером и операндом и помещает результат в value. Если указаны неправильные значения для команды или операнда, то функция завершается с
ошибкой. В этом случае значение value не изменяется.
* j. int sc_commandDecode (int value, int * command, int * operand) – декодирует значение как команду Simple Computer. Если декодирование невозможно, то
устанавливается флаг «ошибочная команда» и функция завершается с ошибкой.

# Second Lab

* int mt_clrscr (void)- производит очистку и перемещение курсора в левый верхний угол экрана;
* int mt_gotoXY (int, int) - перемещает курсор в указанную позицию. Первый
параметр номер строки, второй - номер столбца;
* int mt_getscreensize (int * rows, int * cols) - определяет размер экрана
терминала (количество строк и столбцов);
* int mt_setfgcolor (enum colors) - устанавливает цвет последующих выводимых
символов. В качестве параметра передаѐтся константа из созданного Вами перечислимого типа colors, описывающего цвета терминала;
* int mt_setbgcolor (enum colors) - устанавливает цвет фона последующих выводимых символов. В качестве параметра передаѐтся константа из созданного Вами
перечислимого типа colors, описывающего цвета терминала. 

# Third Lab

* int bc_printA (char * str) - выводит строку символов с использованием дополнительной кодировочной таблицы;
* int bc_box(int x1, int y1, int x2, int y2) - выводит на экран псевдографическую рамку, в которой левый верхний угол располагается в строке x1 и столбце
y1, а еѐ ширина и высота равна y2 столбцов и x2 строк;
* int bc_printbigchar (int [2], int x, int y, enum color, enum color) -
выводит на экран "большой символ" размером восемь строк на восемь столбцов, левый
верхний угол которого располагается в строке x и столбце y. Третий и четвѐртый параметры определяют цвет и фон выводимых символов. "Символ" выводится исходя из
значений массива целых чисел следующим образом. В первой строке выводится 8
младших бит первого числа, во второй следующие 8, в третьей и 4 следующие. В 5
строке выводятся 8 младших бит второго числа и т.д. При этом если значение бита = 0,
то выводится символ "пробел", иначе - символ, закрашивающий знакоместо
(ACS_CKBOARD);
* int bc_setbigcharpos (int * big, int x, int y, int value) - устанавливает значение знакоместа "большого символа" в строке x и столбце y в значение value;
* int bc_getbigcharpos(int * big, int x, int y, int *value) - возвращает
значение позиции в "большом символе" в строке x и столбце y;
* int bc_bigcharwrite (int fd, int * big, int count) - записывает заданное
число "больших символов" в файл. Формат записи определяется пользователем;
* int bc_bigcharread (int fd, int * big, int need_count, int * count)
считывает из файла заданное количество "больших символов". Третий параметр указывает адрес переменной, в которую помещается количество считанных символов или
0, в случае ошибки.

# Forth-Fifth Labs
## Интерфейс консоли управления. Он содержит следующие области:

* Memory – содержимое оперативной памяти Simple Computer.
* Accumulator – значение, находящееся в аккумуляторе;
* instructionCounter – значение регистра «счетчик команд»;
* Operation – результат декодирования операции;
* Flags – состояние регистра флагов («П» - переполнение при выполнении операции,
«0» - ошибка деления на 0, «М» - ошибка выхода за границы памяти, «Т» - игнорирование
тактовых импульсов, «Е» - указана неверная команда);
* Cell – значение выделенной ячейки памяти в области ―Memory‖ (используется для редактирования);
* Keys – подсказка по функциональным клавишам;
* Input/Otput – область, используемая Simple Computer в процессе выполнения программы
для ввода информации с клавиатуры и вывода еѐ на экран

## Флаги взаимодействия:
* l - загрузить состояние машины
* s - сохранить состояние машины
* i - очистить маишну
* t - передвинуться на одну ячейку машины вперед
* r - используя сигналы дойти до конца ячеек машины
* C - демонстрация всех возможных BigChars
* I - задать начальную конфигурация отрицательными числами
* Q - выход
* A,W,S,D - передвежение в рамках матрицы по машине

любая кнопка отличная от 'C' и 'Q' приведет в режим работы с интерфейсом
