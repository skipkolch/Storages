#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class Storages
{
private:

	multimap <string, string> mapStorages; // коллекция складов и товаров (ключ - склад, значение - товар)
	multimap <string, string> ::iterator it; // итератор для прохождения по коллекции

public:
	Storages();

	int	NEW_STORAGE(string storages, string products[],int N);
	vector <string> STORAGES_FOR_PRODUCT(string product);
	vector <string>	PRODUCTS_FOR_STORAGES(string storage);
	vector <string> ALL_STORAGES();

	~Storages();
};

