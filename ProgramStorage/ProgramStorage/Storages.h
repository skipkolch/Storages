#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class Storages
{
private:

	multimap <string, string> mapStorages; // ��������� ������� � ������� (���� - �����, �������� - �����)
	multimap <string, string> ::iterator it; // �������� ��� ����������� �� ���������

public:
	Storages();

	int	NEW_STORAGE(string storages, string products[],int N);
	vector <string> STORAGES_FOR_PRODUCT(string product);
	vector <string>	PRODUCTS_FOR_STORAGES(string storage);
	vector <string> ALL_STORAGES();

	~Storages();
};

