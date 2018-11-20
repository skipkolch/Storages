#include "stdafx.h"
#include "Storages.h"
#include <vector>


Storages::Storages()
{
	this->it = this->mapStorages.begin(); // инициализация итератора
}

int Storages::NEW_STORAGE(string storage, string products[], int N)
{
	try
	{
		for (int i = 0; i < N; i++)
		{
			// вставляем весь список продуктов в склад по ключу storage
			this->mapStorages.insert(make_pair(storage, products[i]));
		}
	}
	catch (...) // ловить все исключения
	{
		return -1; // индикатор ошибки
	}

	return 0;
}


vector <string> Storages::STORAGES_FOR_PRODUCT(string product)
{
	vector <string> result;

	for (this->it = mapStorages.begin(); it != mapStorages.end(); it++)
	{
		// проходим по всей коллекции, если есть совпадение то вставляем в результирующий вектор
		if (it->second == product)
			result.push_back(it->first); // добавляем ключ по его значению, т.е. добавляем название склада
	}

	return result;
}

vector <string>	Storages::PRODUCTS_FOR_STORAGES(string storage)
{
	vector <string> result;

	for (this->it = mapStorages.begin(); it != mapStorages.end(); it++)
	{
		// проходим по всей коллекции, если есть совпадение то вставляем в результирующий вектор
		if (it->first == storage)
			result.push_back(it->second); // добавляем значение по ключу, т.е. добавляем наименование товара
	}

	return result;
}

vector <string> Storages::ALL_STORAGES()
{
	vector <string> result;

	for (auto& item : this->mapStorages) // проход по всей коллекции
	{
		result.push_back(item.first + " : " + item.second + "\n"); //Вывод ключей и значений
	}

	return result;
}


Storages::~Storages()
{
	this->mapStorages.clear(); // Очистка памяти
}
