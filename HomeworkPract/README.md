## **Домашна №1**
## **Задача 1**

Създайте клас Jedi, който да има:
- name(char\*), rank(enum), midi-chlorian(double/float), planet(Planet), spicies(char\*), militaryRank(char\*).

Създайте клас Stormtrooper, който да има:
- id(char\*), rank(enum), type(char\*), planet(Planet).

Създайте клас Planet, който да има:
- name(char\*), planetSystem(char\*), republic(char\*) - име на притежаващата я република.

#### Нека всеки клас притежава методи за изкарване на цялата информация на конкретния обект(print()), конструктори (dafault-ен, copy-конструктор, operator= и конструктор с параметри) и деструктор, get-ъри и set-ъри за член-данните.

## **Домашна №2**
## **Задача 1**

Довършете всички задачи от миналата седмица.

Нека всеки клас бъде разделен в header и .cpp файлове като декларациите на функциите бъдат в .hpp/.h, а реализацията им в .cpp.

Променете функцията print()
- функцията да бъде шаблонна в хедър файла на класа Planet, но да се ползва в останалите класове след като се include-не Planet.h/.hpp в тях
- нека в себе си тя използва предефинирания оператор за изход <<

Добавете в класа Planet тип на пранетата като enum

![Planet Type](https://github.com/lacho55/OOP-IS-2020-2021-Practicum-Group-2/blob/main/Homework/PlanetTypes.PNG?raw=true)

## **Задача 2**

Напишете функция, която записва в конзолата джедаите, трупърите и планетите по следния начин:

[Джедаи](https://github.com/lacho55/OOP-IS-2020-2021-Practicum-Group-2/tree/main/Homework/example_jedi.txt)

[Stormtroopers](https://github.com/lacho55/OOP-IS-2020-2021-Practicum-Group-2/tree/main/Homework/example_stormtroopers.txt)

[Планети](https://github.com/lacho55/OOP-IS-2020-2021-Practicum-Group-2/tree/main/Homework/example_planets.txt)

Напишете функция, която чете текст в този формат и създава обект с такива данни.