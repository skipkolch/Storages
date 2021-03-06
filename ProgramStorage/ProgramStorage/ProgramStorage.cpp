// ProgramStorage.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale>
#include <vector>
#include <conio.h>
#include "Storages.h" 

void DrawUI(); // Прорисовка пользовательского интерфейса
void CaseNewStorage(string*, string**, int**);  // Функция для работы с вставкой в коллекцию


int main()
{
	setlocale(LC_ALL, "rus"); // локализация

	bool stopProgramm = false;

	Storages* storages = new Storages();

	while (!stopProgramm)
	{
		DrawUI();

		int input;
		cin >> input; // то что пользователь ввел

		cin.clear(); // Очищаем буффер ввода 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорируем в буффере конец введенной строки

		switch (input)
		{
			case 1: {

				string strStorage; // Название склада
				string* strProducts = NULL; // Список продуктов
				int* N = NULL; // Количество продуктов

				CaseNewStorage(&strStorage, &strProducts, &N); // Получаем от пользователя данные и записываем их в переменные объявленные выше

				if( storages->NEW_STORAGE(strStorage, strProducts, *N) == 0) // Если ошибок нет
				{
					cout << "Add new storage successfully." << endl
						<< "Inut any key for exit .\n";
					_getch();
				}
				else
					cout << "Something wrong!" << endl;

				break;
			}
			case 2: {
				
				system("cls");

				string product; // Продукт для поиска

				cout << "Введите продукт: ";
				cin >> product;

				
				vector <string> result = storages->STORAGES_FOR_PRODUCT(product); // Используем метод поиска из класса
				
				if (!result.empty()) 
				{
					// Если что то нашли, т.е. результат не пустой
					cout << "Товар находится в складе:\n";

					for (int i = 0; i < result.size(); i++)
					{
						cout << i+1 << ") " << result[i] << endl; // Выводим по-элементно
					}

					cout << endl;
				}
				else
					cout << "Ничего не найденно." << endl;

				system("pause");
				break;
			}
			case 3: {

				system("cls");

				string storage; // Склад для поиска

				cout << "Введите название склада: ";
				cin >> storage;


				vector <string> result = storages->PRODUCTS_FOR_STORAGES(storage); // Используем метод поиска из класса

				if (!result.empty())
				{
					// Если что то нашли, т.е. результат не пустой
					cout << "Все товары, хранящиеся в складе:\n";

					for (int i = 0; i < result.size(); i++)
					{
						cout << i + 1 << ") " << result[i] << endl; // Выводим по-элементно
					}

					cout << endl;
				}
				else
					cout << "Ничего не найденно." << endl;

				system("pause");
				break;
			}
			case 4: {
			
				system("cls");

				vector <string> result = storages->ALL_STORAGES();// Используем метод вывода всех значений из класса

				if (!result.empty())
				{
					// Если что то нашли, т.е. результат не пустой
					cout << "Список всех складов вместе с товарами:\n";

					for (int i = 0; i < result.size(); i++)
					{
						cout << i + 1 << ") " << result[i] << endl; // Выводим по-элементно
					}

					cout << endl;
				}
				else
					cout << "Ничего не найденно." << endl;

				system("pause");
				break;
				break;
			}
			case 5: {

				cout << "Завершение программы." << endl;
				stopProgramm = true;
				break;
			}
			default:
			{
				cout << "Ошибка ввода.\nДля продолжения нажмите любую клавишу." << endl;
				_getch();
				break;
			}
		}

		
	}

	system("pause");
    return 0;
}

void DrawUI()
{
	system("cls"); // Очистка консоли

	cout << "1) NEW_STORAGES(storages, products[]) \n"
		<<  "2) STORAGES_FOR_PRODUCT(product) \n"
		<<  "3) PRODUCTS_FOR_STORAGES(storage) \n"
		<<  "4) ALL_STORAGES()\n"
		<<  "5) EXIT \n"
		<<  "---------------------------------------------------\n";
}

void CaseNewStorage(string* storage, string** products, int** N)
{
	system("cls");

	cout << "Storage :";
	cin >> *storage;

	cout << "-----------\nInput \"exit\" for exit.\n------------\n";

	cout << "Products:" << endl;

	string userInput;
	vector <string> prod; // используем вектор,т.к. заранее не знаем сколько пользователь введет товаров
	vector <string>::iterator it;

	do // повторяем пока пользователь не введет "exit"
	{
		cin >> userInput; // Считывам и записываем в вектор строк

		prod.push_back(userInput);

	} while (userInput != "exit");

	prod.pop_back(); // удаляем последний элемент из вектора, т.к. последним будет значение "exit"

	int size = prod.size(); // Создаем переменную для размера вектора 
	(*N) = &size;			// и присваиваем адрес переменной size переменной N, чтобы поменять значение N

	string* localArr = new string[size]();

	for (int i = 0; i < size; i++)
		localArr[i] = prod[i]; // Перезаписываем вектор в массив строк
	
	*products = localArr; // И меняем значение products, присваивая адрес массива
}
