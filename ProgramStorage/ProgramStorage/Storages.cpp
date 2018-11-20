#include "stdafx.h"
#include "Storages.h"
#include <vector>


Storages::Storages()
{
	this->it = this->mapStorages.begin(); // ������������� ���������
}

int Storages::NEW_STORAGE(string storage, string products[], int N)
{
	try
	{
		for (int i = 0; i < N; i++)
		{
			// ��������� ���� ������ ��������� � ����� �� ����� storage
			this->mapStorages.insert(make_pair(storage, products[i]));
		}
	}
	catch (...) // ������ ��� ����������
	{
		return -1; // ��������� ������
	}

	return 0;
}


vector <string> Storages::STORAGES_FOR_PRODUCT(string product)
{
	vector <string> result;

	for (this->it = mapStorages.begin(); it != mapStorages.end(); it++)
	{
		// �������� �� ���� ���������, ���� ���� ���������� �� ��������� � �������������� ������
		if (it->second == product)
			result.push_back(it->first); // ��������� ���� �� ��� ��������, �.�. ��������� �������� ������
	}

	return result;
}

vector <string>	Storages::PRODUCTS_FOR_STORAGES(string storage)
{
	vector <string> result;

	for (this->it = mapStorages.begin(); it != mapStorages.end(); it++)
	{
		// �������� �� ���� ���������, ���� ���� ���������� �� ��������� � �������������� ������
		if (it->first == storage)
			result.push_back(it->second); // ��������� �������� �� �����, �.�. ��������� ������������ ������
	}

	return result;
}

vector <string> Storages::ALL_STORAGES()
{
	vector <string> result;

	for (auto& item : this->mapStorages) // ������ �� ���� ���������
	{
		result.push_back(item.first + " : " + item.second + "\n"); //����� ������ � ��������
	}

	return result;
}


Storages::~Storages()
{
	this->mapStorages.clear(); // ������� ������
}
