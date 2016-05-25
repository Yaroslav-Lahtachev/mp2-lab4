# Реализация приоритетной очереди на основе d-кучи и ее применение для построения остовного дерева графа с помощью алгоритма Краскала. #


----------

## Содержание: ##

- [Постановка задачи](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Постановка-задачи)
- [Руководство пользователя](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Руководство-пользователя)
- [Руководство программиста](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Руководство-программиста)
	- [Используемые инструменты](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Используемые-инструменты)
	- [Общая структура проекта](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Общая-структура-проекта)
	- [Описание структуры программы]()
	- [Описание структур данных](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Описание-структур-данных)
		- [Структура данных "d-арное дерево"]()
		- [Структура данных "приоритетная очередь"]()
	- [Описание алгоритмов](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Описание-алгоритмов)
		- [Алгоритм Краскала](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Алгоритм-Краскала)
		- [Алгоритм Дейкстры](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Алгоритм-Дейкстры)
		- [Пирамидальная сортировка](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Пирамидальная-сортировка)
- [Заключение](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Заключение)
- [Литература](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Литература)

## Постановка задачи ##

Цель данной лабораторной работы — изучение структур данных типа "d-куча" и разделенные множества.

1. Написать тестирующую программу для каждой структуры данных с помощью Google C++ Testing Framework.
1. В качестве примера реализации приоритетной очереди, реализовать алгоритм Краскала. Создать приложение, демонстрирующее работу алгоритма, где входные данные — количество вершин и ребер и диапазон масс ребер, а результат — граф с раскрашенным остовным деревом.
1. Написать консольные приложения для демонстрации работы алгоритма Дейкстра и Пирамидальной сортировки.

## Руководство пользователя #

###*Запуск приложения и ввод данных*###

Данная программа предназначена для построения графа и нахождения минимального остовного дерева на основе данных, полученных от пользователя.

Для запуска программы, необходимо запустить файл `view_graph.exe` и далее вводить требуемые значения.

**Пример:**

Введите требуемые численные значения в специальные формы. 
И нажмите кнопку **"create random"** .

![start](/img/prog.png)

Получите сгенерированный граф на основе введенных данных.

![start](/img/prog2.png)

Далее выберете один из двух вариантов: пошаговое построение остовного дерева или построение этого дерева в одно нажатие кнопачки.

Результат работы **"step by step"**:

![start](/img/gif1.gif)

Результат работы **"find spanning tree"**:

![start](/img/gif2.gif)

Кнопка **"cancel"** отменяет все действия произведенные с графом.

Кнопка **"delete img"** удаляет изображаемый граф.

## Руководство программиста ##

###*Используемые инструменты*###

В ходе лабораторной работы использовались следующие инструменты:

- Фреймворк для написания автоматических тестов Google Test.
- Среда разработки Microsoft Visual Studio 2015.

###*Общая структура проекта*###

Структура проекта:

gtest — библиотека Google Test.
img — директория с изображениями, используемых в отчете к лабораторной работе.
include — директория для размещения заголовочных файлов.
samples — директория для размещения тестового приложения.
sln — директория с файлами решений и проектов для Visual Studio 2015
src — директория для размещения исходных кодов (cpp-файлы).
test — директория с модульными тестами и основным тестовым приложением, инициализирующим запуск тестов.
README.md — отчет о выполненной лабораторной работе.
Служебные файлы
.gitignore — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.

### Описание структуры проекта ###

Программа состоит из 7 проектов:

- d-tree-lib — статическая библиотека, которая содержит объявление и реализацию классов Data, Tree.
	- Data — класс описывающий веса(приоритеты) узлов.
	- Tree — класс содержащий базовые операции работающие с d-кучами.
- queue — статическая библиотека, содержащая реализацию приоритетной очереди на основе d-арного дерева. 
	- Queue — класс описывающий приоритетную очередь, содержит 5 виртуальных методов.
	- QueueHeap — класс наследник Queue, содержит реализацию 5-и унаследованных методов.  
- graph — статическая библиотека, которая содержит объявление и реализацию классов Graph и Edges.
	- Graph — класс описывающий сущность граф и содержащий 14 методов.
	- Edges — класс описывающий сущность ребро.
- sep-set — статическая библиотека, которая содержит объявление и реализацию класса separatedSet.
	- separatedSet — класс описывающий раздельные множества.
- Dijkstra — статическая библиотека, содержащая объявление и реализацию классов Dijkstra и DijkstraData.
	- Dijkstra — класс содержащий алгоритм Дейкстра.
	- DijkstraData — класс наследник Data. 
- Kruskl — статическая библиотека, содержащая объявление и реализацию классов Kruskl и KrusklEdges.
	- Kruskl — класс содержащий алгоритм Краскала.
	- KrusklEdges — класс наследник Data.
- HeapSort — статическая библиотека, содержащая объявление и реализацию классов HeapSort и DataHeap.
	- HeapSort — класс содержащий Метод пирамидальной сортировки.
	- DataHeap — класс наследник Data.
- sample-Dijkstra — консольное приложение, демонстрирующее работу алгоритма Дейкстры.
- sample-Kruskl — консольное приложение, демонстрирующее работу алгоритма Краскала.
- sample-heapsort — консольное приложение, демонстрирующее работу пирамидальной сортировки.
- view_graph — Windows Forms приложение.
- gtest — фреймворк Google Test.
- test — консольное приложение, использующее библиотеку Google Test, проверяющее корректность реализации всех классов. Содержит 78 тестов.

###Описание структур данных###

####Структура данных "d-арное дерево"####

Завершенное d-арное дерево – корневое дерево, у каждого узла которого, за исключением, быть может, одного узла, ровно d потомков. При этом возможна следующая нумерация узлов:

1. Корень имеет номер 0.
2. Если какой-то узел имеет номер i, то он имеет потомков с номерами *id* + 1,*id* + 2, ... , *id* + *d*.

В таком случае узел с номером i имеет предка (i-1)/d.

Если каждому узлу завершенного d-арного дерева приписать элемент приоритетной очереди так, чтобы вес каждого узла не превосходил весов элементов, находящихся в его потомках, то такое дерево называется d-кучей.

В данной лабораторной работе структура данных "d-арное дерево" представлена в виде класса Tree, который содержит в себе следующие методы:

- Конструктор по умолчанию.
- Деструктор.
- input — метод добавления новых узлов.
- inputGroup — метод добавления группы узлов.
- erase() — метод удаляющий последний узел.
- erase(int i) — метод удаляющий i-ый узел.
- transposing — метод меняющий два указанных узла местами.
- surfacing — метод всплытия i-ого узла.
- immersion — метод погружения i-ого узла.
- withdrawal — метод изъятия минимального узла.
- hilling — метод окучивания.
- minchild — метод нахождения минимального потомка i-ого узла.
- isFull — метод сигнализирующий о пустоте кучи.
- isEmpty — метод сигнализирующий о полноте кучи.


Данный набор методов достаточен для реализации приоритетной очереди.

####Структура данных "приоритетная очередь"####

Приоритетная очередь — это абстрактная структура данных на подобии стека или очереди, где у каждого элемента есть приоритет. Элемент с более высоким приоритетом находится перед элементом с более низким приоритетом. Если у элементов одинаковые приоритеты, они располагаются в зависимости от своей позиции в очереди. Обычно приоритетные очереди реализуются с помощью куч (heap).

QueueHeap(приоритетная очередь) является наследником класса Queue и переопределяет его методы.

- Конструктор по умолчанию.
- Конструктор с изначальным добавлением группы узлов.
- Деструктор.
- add — метод вставки элемента в приоритетную очередь с указанным ключом.
- popidx — метод выполняющий всплытие элемента приоритетной очереди с i-ым ключом.
- update — метод упорядочивающий приоритетную очередь.
- isFull — метод сигнализирующий о переполненности приоритетной очереди.
- isEmpty — метод сигнализирующий о пустоте приоритетной очереди.

Методы, реализованные в классе QueueHeap необходимы и достаточны для полноценного использования этой структуры данных в алгоритме Краскала и алгоритме Дейкстры.



### Описание алгоритмов ###

#### Алгоритм Краскала ####


Алгоритм Краскала относится к числу «жадных» алгоритмов, т.е. на каждом шаге получается максимальный выигрыш. 

Алгоритм состоит из нескольких действий:

1. Создание коллекции из `ver` синглетонов универса {1, 2, ... , `ver`}. (`separatedSet *SArr=new separatedSet(ver);`)
2. Создание пустого множества ребер `tree`, которые входят в состав остовного дерева. (`Graph *tree=new Graph(ver)`)
3. Поиск ребра `e` с минимальным весом и удаление его из множества ребер (`e=q->popidx(0)`).
4. Определение разделенного множества `A` ,которому принадлежит n(e).(`n=((KrasklEdges*)e)->edge->n; A=SArr->subDef(n);`)
5. Определение разделенного множества `B` ,которому принадлежит k(e).(`k=((KrasklEdges*)e)->edge->k; B=SArr->subDef(k);`)
6. Если `A!=B` ,то объединяем разделенные множества и добавляем ребро `e` в множество `tree`. (`SArr->unionS(A, B); tree->inputEdge(n, k, w);`)
7. Шаги 3-6 повторяются до тех пор, пока `q!=∅` и `|Size| < ver − 1`. (`while(Size<ver-1 && !q->isEmpty())`)


#### Алгоритм Дейкстры ####

Алгоритм Дейкстры находит кратчайшие пути от одной из вершин графа до всех остальных. Алгоритм работает только для графов без рёбер отрицательного веса.

Алгоритм состоит из нескольких действий:

1.  Создание множества расстояний `dist[i]` со значениями равным бесконечности.
2.  Создание массива с нулевыми значениями `p[i]` содержащего по окончании работы алгоритма кратчайший путь от `startV` до `i`.
3.  Создание приоритетной очереди `q`.
4.  Пока приоритетная очередь не пуста (`!q->isEmpty`) повторяются действия:
	1.  Изымается вершина `currV` с минимальным приоритетом. (`currV=((DijkstraData*)q->popidx(0))->num;`)
	2.  В цикле от 0 до `edg`(количества ребер) ищем ребра совпадающие началом(*концом*) с `currV`.
	3.  Если такое ребро нашлось, то мы проверяем, является ли новый путь короче, чем ранее имевшийся до этой вершины.
		1.  Если да, то мы добаляем расстояние до этой вершины в множество `dist`.
		2.  Добавляем конец(*начало*) ребра в массив кратчайших путей `p`. 
		3.  Обновляем приоритетную очередь. (`q->update();`)
		4.  Далее мы возвращаемся в пункт 4.

#### Пирамидальная сортировка ####

Пирамидальная сортировка — алгоритм сортировки, работающий в худшем, в среднем и лучшем случае за `О(n log(n))`

Алгоритм состоит из нескольких действий:

на вход поступает массив значений `Elems`

1. В цикле от i=Size(кол-во элементов массива) до 1 выполняется:
	1. Транспонирование 0-ого и Size-1 элемента. (`heap->transposing(i, 0);`)
	2. i-ому элементу массива присваивается значение последнего элемента кучи. (`Elems[i] =(int)heap->erase()->priority;`) 
	3. Погружение(0). (`heap->immersion(0);`)
2. Первому элементу массива `Elems[0]` присваивается значение последнего оставшегося элемента кучи(`heap`) 



### Заключение ###

В ходе лабораторной работы была разработана программа, удовлетворяющая поставленным задачам. Реализованы классы d-арная куча и приоритетная очередь. Реализована пирамидальная сортировка, алгоритмы Краскала и Дейкстры. Так же были насаны примеры консольные приложения демонстрирующие работу данных методов. Для визуализации алгоритма Краскала было создано оконное приложение.

В процессе было написано 78 тестов, которые покрывают всевозможные ситуации использования методов класса. Все тесты успешно пройдены.

### Литература ###

- Левитин А. В. Глава 6. Метод преобразования: Пирамиды и пирамидальная сортировка // Алгоритмы. Введение в разработку и анализ — М.: Вильямс, 2006. — С. 275—284. — 576 с.
- Томас Х. Кормен, Чарльз И. Лейзерсон, Рональд Л. Ривест, Клиффорд Штайн. Алгоритмы: построение и анализ = Introduction to Algorithms. — 2-е изд. — М.: «Вильямс», 2006. — С. 1296.
- Белоусов А. И., Ткачев С. Б. Дискретная математика. — М.: МГТУ, 2006. — 744 с.
