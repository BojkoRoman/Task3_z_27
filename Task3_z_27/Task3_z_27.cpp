/**
*@file Task3_z_27
*@brief Solution (C++ code) of Task3.27 GL 
* (��������� �������, ��� ������ � �������� ����������� ����� �� ������ ������� � ������� ������� ��������� ����. 
*  ������ ����������� ���������� �����. �������-������� ���������� �������, ����������� �� ������ ����� ��� ����.
*  ���������, � ����� ����� �������� �������� �������.)
*Copyright 2014 by Roman Bojko
*/
#include <iostream>
#include <cctype>
using namespace std;

/**
  * @brief	������� �������  �� ������ ������� � �����
  * @param	[in,out]    pStr �������� �� ����� ���� ���������� '\0'
  * @return	ʳ������ ��������� �������
  */
unsigned removeNumbers(char *pStr);

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	cout <<"�������� ��� ������ � �������� ����������� ����� �� ������ ������� � ������� ������� ��������� ����"<<endl;
	cout <<"-------------"<<endl;
	int n = 0;
	do
	{
		cout << "������ ������� �����: ";
		cin >> n;
	}
	while(n <= 0);
	if( n == 0 || n == 1){
		cout << "������ ��� �����:" << endl;
	
	}else{
		cout << "������ ���� �����:" << endl;
	}
	

	cin.clear(); /**< �� ������� �������� ����, ���� � �������*/ 
	cin.sync(); /**< ��������� ���� �� ������� � ����� �������*/

	char **lines = new char*[n]; /**< �������� ����� ��� ������ ��������� �� n �����*/
	for(int i = 0; i < n; i++)
	{
		lines[i] = new char[256]; /**< �������� ����� ��� ������� ����� ������*/
		cin.getline( lines[i], 256 );
	}

	for( int i = 0; i < n; i++ ) //**< ���� ���� ���������� �� ������ � ��������� ������ ������� */
	{
		int n = removeNumbers(lines[i]);
		cout <<"-------------"<<endl;
		cout << lines[i] << endl;
		cout << "\tʳ������ ��������� �������: " << n << endl;
		cout <<"-------------"<<endl;
		
	}

	for( int i = 0; i < n; i++ )
		delete[] lines[i]; /**< ��������� ����� �� ������� �����*/
	delete[] lines; /**< ��������� ����� �� ������ ���������*/
	system("pause");
	

	return 0;
}

unsigned removeNumbers(char *pStr)
{
	if(!pStr)
		return 0;

	unsigned n = 0;
	char *pEnd = pStr + strlen(pStr);

	while(*pStr)
	{
		/**< ���� ������ � ����� - ������� ������ ����*/
		if(isdigit(*pStr))
		{
			memcpy(pStr, pStr + 1, pEnd - pStr);
			n++;
			continue;
		}

		pStr++;
	}

	return n;
}