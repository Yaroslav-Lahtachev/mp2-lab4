# Реализация приоритетной очереди на основе d-кучи и ее применение для построения остовного дерева графа с помощью алгоритма Краскала. #


----------

## Содержание: ##

- [Постановка задачи](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Постановка-задачи)
- [Руководство пользователя](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Руководство-пользователя)
- [Руководство программиста](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Руководство-программиста)
	- [Используемые инструменты](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Используемые-инструменты)
	- [Общая структура проекта](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Общая-структура-проекта)
	- [Описание структуры проекта](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Описание-структуры-проекта)
	- [Описание структур данных](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Описание-структур-данных)
		- [Структура данных "d-арное дерево"](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Структура-данных-d-арное-дерево)
		- [Структура данных "приоритетная очередь"](https://github.com/Yaroslav-Lahtachev/mp2-lab4/blob/master/README.md#Структура-данных-приоритетная-очередь)
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

![start](/img/prog.PNG)

Получите сгенерированный граф на основе введенных данных.

![start](/img/prog2.PNG)

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

- `gtest` — библиотека Google Test.
- `img` — директория с изображениями, используемых в отчете к лабораторной работе.
- `include` — директория для размещения заголовочных файлов.
- `samples` — директория для размещения тестового приложения.
- `sln` — директория с файлами решений и проектов для Visual Studio 2015.
- `src` — директория для размещения исходных кодов (cpp-файлы).
- `test` — директория с модульными тестами и основным тестовым приложением, инициализирующим запуск тестов.
- `README.md` — отчет о выполненной лабораторной работе.

Служебные файлы:
- `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.

### Описание структуры проекта ###

Программа состоит из 7 проектов:

- `d-tree-lib` — статическая библиотека, которая содержит объявление и реализацию классов `Data`, `Tree`.
	- `Data` — класс, описывающий веса(приоритеты) узлов.
	- `Tree` — класс, содержащий базовые операции работающие с d-кучами.
- `queue` — статическая библиотека, содержащая реализацию приоритетной очереди на основе d-арного дерева. 
	- `Queue` — класс, описывающий приоритетную очередь, содержит 5 виртуальных методов.
	- `QueueHeap` — класс, наследник Queue, содержит реализацию 5-и унаследованных методов.  
- `graph` — статическая библиотека, которая содержит объявление и реализацию классов `Graph` и `Edges`.
	- `Graph` — класс, описывающий сущность граф и содержащий 14 методов.
	- `Edges` — класс, описывающий сущность ребро.
- `sep-set` — статическая библиотека, которая содержит объявление и реализацию класса `separatedSet`.
	- `separatedSet` — класс, описывающий раздельные множества.
- `Dijkstra` — статическая библиотека, содержащая объявление и реализацию классов `Dijkstra` и `DijkstraData`.
	- `Dijkstra` — класс, содержащий алгоритм Дейкстра.
	- `DijkstraData` — класс-наследник Data. 
- `Kruskl` — статическая библиотека, содержащая объявление и реализацию классов Kruskl и KrusklEdges.
	- `Kruskl` — класс, содержащий алгоритм Краскала.
	- `KrusklEdges` — класс-наследник `Data`.
- `HeapSort` — статическая библиотека, содержащая объявление и реализацию классов `HeapSort` и `DataHeap`.
	- `HeapSort` — класс, содержащий Метод пирамидальной сортировки.
	- `DataHeap` — класс-наследник `Data`.
- `sample-Dijkstra` — консольное приложение, демонстрирующее работу алгоритма Дейкстры.
- `sample-Kruskl` — консольное приложение, демонстрирующее работу алгоритма Краскала.
- `sample-heapsort` — консольное приложение, демонстрирующее работу пирамидальной сортировки.
- `view_graph` — Windows Forms приложение.
- `gtest` — фреймворк Google Test.
- `test` — консольное приложение, использующее библиотеку Google Test, проверяющее корректность реализации всех классов. Содержит 78 тестов.

###Описание структур данных###

####Структура данных "d-арная куча"####

Завершенное d-арное дерево – корневое дерево, у каждого узла которого, за исключением, быть может, одного узла, ровно d потомков. При этом возможна следующая нумерация узлов:

1. Корень имеет номер 0.
2. Если какой-то узел имеет номер i, то он имеет потомков с номерами *id* + 1,*id* + 2, ... , *id* + *d*.

В таком случае узел с номером i имеет предка (i-1)/d.

Если каждому узлу завершенного d-арного дерева приписать элемент приоритетной очереди так, чтобы вес каждого узла не превосходил весов элементов, находящихся в его потомках, то такое дерево называется d-кучей.

**Базовые операции над d-кучами (транспонирование, всплытие, погружение) и их трудоемкость** 
Сохранить d-кучу можно в обычном массиве (сначала корень, потом ݀ его потомков, затем ݀ потомков первого потомка корня и т.д), но с точки зрения программной реализации это не совсем удобно, т.к. при выполнении некоторых операций с приоритетными очередями может потребоваться перепаковка элементов.

Сначала рассмотрим некоторые базовые операции над узлами d-кучи:
1. Транспонирование узлов с номерами i и j݆
```
	tmp = key[i];
	key[i] = key[j];
	key[j] = tmp;
```
2. Всплытие узла с номером ݅. Данная операция, как и следующая, используется для установления порядка в d-куче. Осуществляем транспонирование предка и потомка до тех пор, пока очередной предок не будет содержать ключ, который меньше ключа текущего потомка.
```
while (i > 0){
	P = (i - 1) / d;
	if (key[p] > key[i])
	{
		Транспонирование(i, p);
		i = p;
	}
	else
	{
		break;
	}
}
```
3. Погружение узла с номером ݅. Погружение выполняется в сторону потомка с наименьшим ключом.
```
c = minchild(i);
while (c != -1 && key[c] < key[i]){
	Транспонирование(c, i);
	i = c;
	c = minchild(i);
}
minchild(i)
{
	if (id + 1 > n) return -1;
	else
	{
		firstChild = id + 1;
		lastChild = min{id + d, n};
		minKey = key[firstChild];
		minChild = firstChild;
		for (int i = firstChild; i < lastChild; i++)
			if (key[i] < minKey)
			{
				minKey = key[i];
				minChild = i;
			}
		return minChild;
	}
}
```
**Операция изъятия элемента с минимальным ключом (весом)**
Данная операция реализуется достаточно просто, т.к. элемент с минимальным ключом находится в корне дерева, и состоит из следующих действий:
1. Убиваем узел с максимальным номером.

2. Перемещаем этот узел в корень.

3. Выполняем погружение корневого узла.

```
key[0] = key[n - 1];
n--;
Погружение(0);
```

**Операция окучивания**
Данная операция позволяет организовать из набора ключей d-кучу. Кучеобразность согласно определению 
предполагает, что веса потомков каждого узла больше веса этого узла. Оказывается, что если деревья с корнями,
имеющими номера n − 1, n − 2, ... , n - i окучены, применяя операцию погружения для узла n − i − 1, 
дерево с корнем n − i − 1 тоже оказывается окученным.
```
for (int i = n – 1; i >= 0; i--){
	Погружение(i);
}
```


####Структура данных "БПД"####

Бинарное поисковое дерево – такое бинарное дерево, узлам которого приписаны элементы взвешенного множества так, что выполняется следующее условие:
![start](/img/bpd.PNG)
т.е. для любого узла справедливо утверждать, что его левое поддерево содержит элементы с меньшими ключами, а правое поддерево – с большими ключами.

**Основные операции, псевдокод и их трудоемкость:**
Бинарное поисковое дерева реализуется в точности так же, как и бинарные деревья общего вида. При необходимости реализации некоторых операций вводится указатель на родителя. Узел бинарного дерева определяется набором из четырех компонент:
- Указатель на левого потомка.
- Указатель на правого потомка.
- Ключ узла.
- Информативные данные.

**Основные операции, которые могут производиться с бинарным поисковым деревом:**

1. Поиск элемента с заданным ключом. Фактически реализуется обычный бинарный поиск по поддеревьям.
// рекусивная процедура
```
Node* search(Node *root, int key){
	if (root == NULL) return NULL;
	if (root->key == key) return root;
	if (key < root->key) return search(root->left, key);
	else return search(root->right, key);
}
```
// итеративная процедура
```
Node* search(Node* root, int key){
	Node *curr = root;
	while (curr != NULL && curr->key != key);
	{
		if (key < curr->key) curr = curr->left;
		else curr = curr->right;
	}
	return curr;
}
```
2. Поиск элемента с максимальным ключом. Проход по крайней правой ветви дерева до конца.
```
Node* searchMax(Node* root){
	Node* curr = root;
	while (curr->right != NULL)
	{
		curr = curr->right;
	}
	return curr;
}
```
3. Поиск элемента с минимальным ключом. Проход по крайней левой ветви дерева до конца.
```
Node* searchMin(Node* root){
	Node* curr = root;
	while (curr->left != NULL)
	{
		curr = curr->left;	
	}
	return curr;
}
```
4. Поиск элемента со следующим ключом. Если элемент, для которого осуществляется поиск следующего, имеет правого потомка, то следующим будет минимальный элемент правого поддерева. Если же он не имеет правого потомка, то ищем узел, который является левым сыном для родителя рассматриваемого элемента.
```
Node* searchNext(Node* curr){
	Node *res = NULL;
	if (curr->right != NULL)
	{
		res = searchMin(curr);
		return res;
	}
	res = curr->parent;
	Node *tmp = curr;
	while (res != NULL && tmp == res->right)
	{
		tmp = res;
		res = res->parent;
	}
	return res;
}
```
5. Поиск элемента с предыдущим ключом. Если элемент, для которого осуществляется поиск предыдущего, имеет левого потомка, то предыдущим будет максимальный элемент левого поддерева. Если же он не имеет левого потомка, то ищем узел, который является правым сыном для родителя рассматриваемого элемента.
```
Node* searchPrev(Node* curr){
	Node *res = NULL;
	if (curr->left != NULL)
	{
		res = searchMax(curr);
		return res;
	}
	res = curr->parent;
	Node *tmp = curr;
	while (res != NULL && tmp == res->left)
	{
		tmp = res;
		res = res->parent;
	}
	return res;
}
```
6. Вставка нового элемента со своим ключом. Пусть необходимо вставить в непустое бинарное поисковое дерево узел с ключом key и некоторой информативной частью data. ܽИзвестно, что тогда в дереве всегда найдетcя узел Y, такой, если Y->key>key, то у узла Y
нет левого потомка, если же Y->key<key, то у узла Y нет правого потомка.
```
void insert(Node **root, Node *node){
	if (*root == NULL)
	{
		*root = node;
		return;
	}
	Node *x = *root, *y;
	while (x != NULL)
	{
		y = x;
		if (node->key < x->key) x = x->left;
		else x = x->right;
	}
	node->parent = y;
	if (node->key < y->key) y->left = node;
	else y->right = node;
}
```
7. Удаление указанного элемента. Данная операция является самой сложной с алгоритмической точки зрения, т.к. при удалении узла дерево должно остаться поисковым. Пусть z - узел, который необходимо удалить. Рассмотрим 3 случая:
	a. Узел z является листом, т.е. не имеет потомков. Тогда при удалении узла достаточно у родителя обнулить ссылку на этого 		   потомка.
	b. Узел z имеет одного потомка (Рис. 1). В этом случае достаточно перекинуть правую или левую ссылку в зависимости от того,      какой ребенок.
	![start](/img/ris3.PNG)
	Рис.1.

	c. Узел z имеет двух потомков (общий случай). Рассмотрим процедуру удаления узла с двумя потомками на примере дерева, показанного на Рис. 2:
	
	i. Определяем узел Y ,который имеет следующий ключ за удаляемым.
	
	ii. Помещаем узел Y на место узла z.
	
	iii. Потомка узла Y делаем потомком его старого родителя (пунктирная стрелка). Необходимо отметить, что узел Y не имеет левого      потомка в соответствии с алгоритмом поиска следующего узла. У него может быть только правый потомок.

![start](/img/ris4.PNG)
	Рис.2.
```	
void remove(Node *z){
	Node *y = NULL, *x = NULL;
	if (z->left != NULL && z->right != NULL)
	{
		y = searchNext(z); // 3d case
	}
	else
	{
		y = z; // 1st and 2d cases
	}
	if (y->left != NULL)
	{
		x = y->left;
	}
	else
	{
		x = y->right;
	}
	if (x != NULL) x->parent = y->parent;
	if (y->parent != NULL)
	{
		if (y == y->parent->left) y->parent->left = x;
		else y->parent->right = x;
	}
	if (y != z)
	{
		z->key = y->key;
		delete z->data;
		z->data = y->data;
	}
}
```
####Структура данных "АВЛ-деревья"####

Поисковое дерево называется АВЛ-сбалансированным, если для любого узла высоты его правого и левого поддеревьев отличаются не более чем на единицу. АВЛ-сбалансированность бинарного дерева при вставке и удалении узлов поддерживается посредством операций левого и правого вращений (Рис. 3.).
Рассмотрим две ситуации вставки элемента в левое поддерево, которые приводят к правому вращению:

1. Однократный правый поворот (Рис. 4.). Такая операция выполняется, когда в левое поддерево 
   левого потомка добавляется узел, в результате чего нарушается балансировка. При этом 
   корень левого поддерева становится корнем всего дерева, а его правое поддерево становится
   левым поддеревом «бывшего» корневого узла.

![start](/img/ris5.PNG) Рис.3
![start](/img/ris6.PNG) Рис.4

2. Двукратный правый поворот (Рис. 10). Двукратный поворот выполняется, если в правое поддерево
   левого потомка добавляется узел и, как следствие, дерево становится разбалансированным. 
   Такой поворот осуществляется в несколько шагов:

   a. Определяется узел В, следующий за корнем левого поддерева А.

   b. Узел В становится корнем дерева.
   
   c. Левое поддерево Т2 узла В становится правым поддеревом узла А.
   
   d. Правое поддерево Т3 узла В становится левым поддеревом узла С.

Для операции вставки в правое поддерево необходимо рассматривать деревья, зеркально отраженные
относительно корневого узла, что приведет к необходимости левого вращения.

Операция удаления узла из правого поддерева приводит к обратным ситуациям левого вращения, если рассматривать
правый граф, показанный на Рис. 3 и Рис. 4, с точки зрения удаления одного из закрашенных узлов.

**Алгоритм добавления элемента в АВЛ-сбалансированное дерево**
Дано: дерево Т и пара (K,V).
Задача: добавить пару (K, V) в дерево Т.

Алгоритм:
1. Если дерево пусто, заменить его на дерево с одним корневым узлом ((K,V),null, null) и остановиться.
2. Иначе сравнить K с ключом корневого узла X.
	a. Если K>=X, рекурсивно добавить (K,V) в правое поддерево Т.
	b. Если K<X, рекурсивно добавить (K,V) в левое поддерево Т.

**Алгоритм удаления узла из АВЛ-сбалансированного дерева**
Дано: дерево Т с корнем root и ключом K.
Задача: удалить из дерева Т узел с ключом K (если такой есть).

Алгоритм:
1. Если дерево T пусто, остановиться.
2. Иначе сравнить K с ключом X корневого узла root:
	a. Если K>X, рекурсивно удалить K из правого поддерева Т и выполнить балансировку;
	b. Если K<X, рекурсивно удалить K из левого поддерева Т и выполнить балинсировку;
	c. Если K=X, то необходимо рассмотреть три случая.

	i. Если обоих детей нет, то удаляем текущий узел и обнуляем ссылку на него у родительского узла;
	ii. Если одного из детей нет, то значения полей второго ребёнка ставим вместо 
	соответствующих значений корневого узла, затирая его старые значения, 
	и освобождаем память, занимаемую удаляемым узлом;
	iii. Если оба ребёнка присутствуют, то:
	
	1. найдём узел, являющийся самым левым узлом правого поддерева с корневым узлом Right(root);
	2. скопируем данные (кроме ссылок на дочерние элементы);
	3. рекурсивно удалим узел.

```
int rightTreeBalancing(BalanceTreeNode** node){
	int height = 0; // изменение высоты дерева после вставки
	switch ((*node)->GetBalance())
	{
		case -1:
		{
			// левое поддерево перевешивало
			// 1. Получаем левого потомка узла
			BalanceTreeNode *left = (BalanceTreeNode *)((*node)->left);
			// 2. Если у левого потомка перевешивает левое поддерево,
			// то это случай однократного поворота,
			if (left->GetBalance() == -1)
			{
				// делаем правого потомка левого поддерева левым поддеревом
				// узла, относительно которого выполняется балансировка
				(*node)->left = left->right;
				// правым поддеревом левого потомка становится дерево с
				// корнем в узле, предназначенного для балансировки
				left->right = (*node);
				(*node)->SetBalance(0);
				(*node) = left;
			}
			else
			{
				BalanceTreeNode *right = (BalanceTreeNode *)(left->right);
				left->right = right->left;
				right->left = left;
				(*node)->left = right->right;
				right->right = (*node);
				if (right->GetBalance() == -1) (*node)->SetBalance(1);
				else (*node)->SetBalance(0);
				if (right->GetBalance() == 1) (*node)->SetBalance(-1);
				else (*node)->SetBalance(0);
				(*node) = right;
				(*node)->SetBalance(0);
			}
			height = 0;
			break;
		}
		case 0;
		{
			// левое и правое поддеревья имели одинаковую высоту
			(*node)->SetBalance(-1); // после вставки левое перевешивает
			height = 1;
			break;
		}
		case 1:
		{
			// правое поддерево перевешивало
			(*node)->SetBalance(0); // после вставки высота одинаковая
			height = 0;
			break;
		}
	}
return height;
} 
```

####Структура данных "Таблицы"####

Таблица – это набор, состоящий из конечного множества элементов, причем каждый элемент характеризуется рядом признаков (свойств). Один из признаков называется ключом и позволяет отличать элементы таблицы. Ключ может однозначно определять элементы таблицы, если ключи всех элементов различны, а может неоднозначно, если в таблице присутствуют элементы с одинаковыми ключами. Таблица имеет две важные характеристики:
1. Максимальное количество записей, которое может содержаться в таблице.
2. Текущее количество записей, которые есть в таблице.
Поэтому необходимо контролировать ситуации переполнения и пустоты таблицы.
Основные операции над таблицами:
- Поиск записи с заданным ключом.
- Включение заданного элемента в таблицу.
- Исключение из таблицы записи с заданным ключом.

**Реализация таблиц**
**Реализация записи таблицы**
```
class TabRecord{
	protected:
		TKey key;
		TData *data;
	public:
	TabRecord(TKey _key, TData *_data)
	{
		key = _key;
		data = _data;
	}
	TData* GetData() { return data; }
	TKey GetKey() { return key; }
}
```
**Абстракция для представления произвольной таблицы**
```
class Table{
	protected:
		int tabSize;
		int dataCount;
		int currPos;
	public:
	Table(int _tabSize);
	// информационные методы
	int IsEmpty() const;
	int IsFull() const;
	int GetDataCount() const;
	// операции над таблицами
	virtual TabRecord* FindRecord(TKey key) = 0;
	virtual void InsertRecord(TKey key, TData* data) = 0;
	virtual void RemoveRecord(TKey key) = 0;
	// навигация по таблице
	virtual int Reset()
	{
		currPos = 0;
		return IsTabEnded();
	}
	virtual int GetNext()
	{
		if (!IsTabEnded()) currPos++;
		return IsTabEnded();
	}
	virtual int IsTabEnded() const { return currPos >= tabSize; }
	// доступ к текущей записи таблицы
	virtual TKey GetKey() const;
	virtual TData* GetData() const;
}
```
####Структура данных "Просматриваемые таблицы"####

Для просматриваемых таблиц характерно, что записи в таблице хранятся в том порядке, в котором они добавляются в таблицу.
Поэтому операция поиска записи с заданным ключом сводится к просмотру таблицы, собственно по этой причине эти таблицы получили такое название.
При этом трудоемкость поиска пропорциональна числу записейтаблицы. Как следствие, такую же трудоемкость имеет операция удаления. 
Вставка выполняется за константное число операций, т.к. по сути требуется только создание новой записи.

Реализация просматриваемых таблиц
```
class ScanTable: public Table{
	protected:
		TabRecord **records;
	public:
		ScanTable(int _tabSize):Table(_tabSize) { };
		// операции над таблицами
		virtual TabRecord* FindRecord(TKey key)
		{
		for (int i = 0; i < dataCount; i++)
		{
			if (records[i]->key == key)
			{
				currPos = i;
				return records[i];
			}
		}
		return NULL;
	}
	virtual void InsertRecord(TKey key, TData* data)
	{
		if (!IsFull())
		{
			records[dataCount++] = new TabRecord(key, data);
		}
	}
	virtual void RemoveRecord(TKey key)
	{
		if (!IsEmpty())
		{
			if (FindRecord(key) != NULL)
			{
				delete records[currPos];
				records[currPos] = records[--dataCount];
			}
		}
	}
}
```
####Структура данных "Упорядоченные таблицы"####

Упорядоченные таблицы – это таблицы, в которых записи располагаются в порядке возрастания (или убывания) ключей.
Упорядоченность таблиц может быть организованатолько при возможности введения линейного порядка на множестве ключей 
и поддерживается методами сортировки по ключам записей. Далее будем считать, что таблица упорядочена по возрастанию.
	Для организации поиска можно использовать алгоритм бинарного поиска, в результате чего трудоемкость поиска 
становится логарифмической от числа записей таблицы. 
	Операция вставки предполагает сдвиг вправо записей таблицы, чтобы не нарушить порядок следования ключей. 
Начиная с максимального элемента, просматриваем записи и сдвигаем вправо, пока не найдем запись с ключом,
который меньше или равен вставляемого.

Операция удаления также предполагает сдвиг записей:

1. Поиск удаляемой записи.

2. Удаление записи.

3. Сдвиг записей с большими ключами влево.

```
class SortTable: public ScanTable{
	protected:
		void SortData(); // метод сортировки записей по ключам
	public:
		SortTable(int _tabSize): ScanTable(_tabSize) { };
		SortTable(const ScanTable *table);
		// операции над таблицами
		virtual TabRecord* FindRecord(TKey key)
		{
			int i, i1 = 0, i2 = dataCount – 1;
			TabRecord *rec = NULL:
			while (i1 <= i2)
			{
				i = (i1 + i2) / 2;
				if (key == records[i]->key)
				{
					i1 = i + 1;
					i2 = i;
					rec = records[i];
				}
				else if (key > records[i]->key)
				{
					i1 = i + 1;
				}
				else
				{
					i2 = i – 1;
				}
			}
			currPos = i2;
			return rec;
		}
		virtual void InsertRecord(TKey key, TData* data)
		{
			if (!IsFull())
			{
				TabRecord* rec = FindRecord(key);
				for (int i = dataCount; i > currPos; i--)
				{
					records[i] = records[i – 1];
				}
				records[currPos] = new TabRecord(key, data);
				dataCount++;
			}
		}
		virtual void RemoveRecord(TKey key)
		{
			if (!IsEmpty())
			{
				TabRecord *rec = FindRecord(key);
				if (rec != NULL)
				{
					delete records[currPos];
					for (int i = currPos; i < dataCount - 1; i++)
					{
						records[i] = records[i + 1];
					}
					dataCount--;
				}
			}
		}
	}
```

####Схема наследования классов####

![start](/img/schem.PNG)

###Описание Классов###

####Программная реализация "d-арной куча"####

- Поля:

- `Key` (Data) - массив для хранения дерева.
- `Size` (int) - количество элементов в дереве.
- `d` (int) - арность кучи.

- Методы:

- `Tree(int d)` - конструктор. Принимает значение арности кучи.
- `~Tree()` - деструктор.
- `void input(Data *&i)` - метод добавления новых узлов.
- `void inputGroup(Data **keys, int num)` - метод добавления группы узлов.
- `Data* erase()` - метод удаляющий последний узел.
- `Data* erase(int i)` - метод удаляющий i-ый узел.
- `void transposing(int i, int j)` - метод меняющий два указанных узла местами.
- `void surfacing(int i)` - метод всплытия i-ого узла.
- `void immersion(int i)` - метод погружения i-ого узла.
- `void withdrawal(int i)` - метод изъятия минимального узла.
- `void hilling()` - метод окучивания.
- `int isFull()` - метод сигнализирующий о полноте кучи.
- `int isEmpty()` - метод сигнализирующий о пустоте кучи.
- `int minchild(int i)` - метод нахождения минимального потомка i-ого узла.

####Программная реализация "БПД"####

Узел дерева представлен классом Node, со следующими полями:

- `key` (float) - ключ.
- `data` (void*) - данные.
- `pleft` (Node*) - указатель на левого потомка.
- `pright` (Node*) - указатель на правого потомка.
- `parent` (Node*) - укаазатель на родителя.
- `root` (Node*) - корень дерева.

- Методы:

- `BinSearchTree()` - конструктор.
- `~BinSearchTree()` - деструктор.
- `Node* search(float key)` - поиск узла по ключу.
- `Node* searchPrev(Node *node)` - поиск предыдущего узла.
- `Node* searchNext(Node *node)` -  поиск следующего узла.
- `Node* searchMin(Node *node = 0)` - поиск минимального узла.
- `Node* searchMax(Node *node = 0)` - поиск максимального узла.
- `void DelNode(Node *node)` - удаление узла.
- `virtual void add(Node *&node)` - добавление узла.
- `virtual void del(float key)` - удаление узла по ключу.
- `virtual Node* pull(float key)` - изъятие узла по ключу. 
- `int isEmpty() const` - метод сигнализирующий о пустоте дерева. 

####Программная реализация "АВЛ-деревья"####

- Методы:

- `AVLTree()` - конструктор.
- `virtual ~AVLTree()` - деструктор.
- `virtual void add(AVLNode *&node)` - добавление узла.
- `virtual void del(float key)` - удаление узла по ключу.
- `virtual void del(Node* node)` - удаление узла.
- `virtual Node* pull(float key)` - изъятие узла по ключу. 
- `virtual Node* pull(Node* node)` - изъятие узла. 
- `int rotateRight(AVLNode *&node)` - правый поворот.
- `int rotateLeft(AVLNode *&node)` - левый поворот.
- `int DRotateRight(AVLNode *&node)` - двукратный правый поворот.
- `int DRotateLeft(AVLNode *&node)` - двукратный левый поворот.
- `int balanceDetection(AVLNode *node, int &dep)` -
- `int height(AVLNode *node)` -
- `int needBalance(AVLNode *&node)` -
- `void ins(AVLNode *&localRoot, AVLNode *&node)` - рекурсивная вставка узла.
- `Node* remuve(AVLNode *&localRoot, float key)` - рекурсивное удаление узла и его возвращение.

####Программная реализация "Таблица"####

Запись в таблице представлена классом TabRecord, содержащим в качестве поля ключ с 
определенным отношением порядка. База для всех таблиц представлена классом Table, содержащим:

- Поля(TabRecord):

- `Key` (int) - ключ.
- `data` (void*) - данные.

- Методы(TabRecord):

- `TabRecord(float key, void *data)` - конструктор.
- `float GetKey() const` - возвращение ключа.
- `void* GetData() const` - возвращение данных.

- Поля(Table):

- `Size` (int) - максимальный размер таблицы.
- `count` (int) - количество записей в таблице.
- `CurrPos` (int) - текущая позиция.

- Методы(Table):

- `Table(int Size)` - конструктор.
- `virtual ~Table()` - деструктор.
- `virtual TabRecord *find(float key)` - поиск записи по ключу.
- `virtual int add(float key, void *data) = 0` - добавление записи в таблицу.
- `virtual int del(float key) = 0` - удаление записи из таблицы.
- `virtual TabRecord* getm() = 0` - получение минимальной записи.
- `virtual TabRecord* getM() = 0` - получение максимальной записи.
- `int isEmpty() const` - проверка таблицы на пустоту.
- `int isFull() const` - проверка таблицы на полноту.
- `int getDataCount()` const - получение текущего количества записей.
- `virtual int Reset()` -  установка индекса навигации в стартовую позицию.
- `virtual int GetNext()` - перевод индекса навигации на следующую позицию.
- `virtual int isTableEnded()` - проверка на достижение конца таблицы.

####Программная реализация "Просматриваемые таблицы"####

- Поля:

- `recs` (TabRecord**) - массив указателей на записи.

- Методы:

- `ScanTable(int Size)` - конструктор.
- `virtual ~ScanTable()` - деструктор.
- `virtual TabRecord *find(float key)` - поиск записи по ключу.
- `virtual int add(float key, void* data)` - добавление записи в таблицу.
- `virtual int del(float key)` - удаление записи из таблицы.
- `virtual TabRecord* pull(float key)` - изъятие записи. 
- `virtual TabRecord* getm()` - получение минимальной записи.
- `virtual TabRecord* getM()` - получение максимальной записи.

####Программная реализация "Упорядоченные таблицы"####

- Методы:

- `ScanTable(int Size)` - конструктор.
- `virtual ~ScanTable()` - деструктор.
- `virtual TabRecord *find(float key)` - поиск записи по ключу.
- `virtual int add(float key, void* data)` - добавление записи в таблицу.
- `virtual int del(float key)` - удаление записи из таблицы.
- `virtual TabRecord* pull(float key)` - изъятие записи. 
- `virtual TabRecord* getm()` - получение минимальной записи.
- `virtual TabRecord* getM()` - получение максимальной записи.


####Структура данных "приоритетная очередь"####

Приоритетная очередь — это абстрактная структура данных на подобии стека или очереди, где у каждого элемента есть приоритет. Элемент с более высоким приоритетом находится перед элементом с более низким приоритетом. Если у элементов одинаковые приоритеты, они располагаются в зависимости от своей позиции в очереди. Обычно приоритетные очереди реализуются с помощью куч (heap).

QueueHeap является наследником класса Queue и переопределяет его методы.

- Поля:

- `*heap` (Tree) - указатель на кучу.

- Методы:

- `QueueHeap(int d=4)` - Конструктор.
- `QueueHeap(Data **keys, int num, int d)` - конструктор с добавлением гуппы элементов.
- `~QueueHeap()` - деструктор.
- `virtual void add(Data *&key)` — метод вставки элемента в приоритетную очередь с указанным ключом.
- `virtual Data* popidx(int i)` — метод выполняющий всплытие элемента приоритетной очереди с i-ым ключом.
- `virtual void update()` — метод упорядочивающий приоритетную очередь.
- `virtual int isFull()` — метод сигнализирующий о переполненности приоритетной очереди.
- `virtual int isEmpty()` — метод сигнализирующий о пустоте приоритетной очереди.

QueueTree так же является наследником класса Queue.

- Поля:

`*tree` (AVLTree) - указатель на дерево.

- Методы:

- `QueueTree()` - Конструктор.
- `QueueTree(Data **keys, int num)` - конструктор с добавлением гуппы элементов.
- `~QueueTree()` - деструктор.
- `virtual void add(Data *&key)` — метод вставки элемента в приоритетную очередь с указанным ключом.
- `virtual Data* popidx(int i)` — метод выполняющий всплытие элемента приоритетной очереди с i-ым ключом.
- `virtual void update()` — метод упорядочивающий приоритетную очередь.
- `virtual int isFull()` — метод сигнализирующий о переполненности приоритетной очереди.
- `virtual int isEmpty()` — метод сигнализирующий о пустоте приоритетной очереди.

QueueTable и это тоже является наследником класса Queue...

- Поля:

`*tab` (SortTable) - указатель на таблицу.

- Методы:

- `QueueTab()` - Конструктор.
- `QueueTab(int Size)` - конструктор с добавлением гуппы элементов.
- `~QueueTab()` - деструктор.
- `virtual void add(Data *&key)` — метод вставки элемента в приоритетную очередь с указанным ключом.
- `virtual Data* popidx(int i)` — метод выполняющий всплытие элемента приоритетной очереди с i-ым ключом.
- `virtual void update()` — метод упорядочивающий приоритетную очередь.
- `virtual int isFull()` — метод сигнализирующий о переполненности приоритетной очереди.
- `virtual int isEmpty()` — метод сигнализирующий о пустоте приоритетной очереди.




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
