/**
*@file Task3_z_27
*@brief Solution (C++ code) of Task3.27 GL 
* (Розробити функцію, яка вилучає з заданого символьного рядка всі цифрові символи і повертає кількість вилучених цифр. 
*  Ввести послідовність символьних рядків. Викорис-товуючи розроблену функцію, надрукувати всі введені рядки без цифр.
*  Зазначити, з якого рядка вилучено найбільше символів.)
*Copyright 2014 by Roman Bojko
*/
#include <iostream>
#include <cctype>
using namespace std;

/**
  * @brief	Функція видаляє  всі цифрові символи з рядка
  * @param	[in,out]    pStr Вказівник на рядок який закінчується '\0'
  * @return	Кількість видалених символів
  */
unsigned removeNumbers(char *pStr);

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	cout <<"Програма яка вилучає з заданого символьного рядка всі цифрові символи і повертає кількість вилучених цифр"<<endl;
	cout <<"-------------"<<endl;
	int n = 0;
	do
	{
		cout << "Введіть кількість рядків: ";
		cin >> n;
	}
	while(n <= 0);
	if( n == 0 || n == 1){
		cout << "Введіть свій рядок:" << endl;
	
	}else{
		cout << "Введіть ваші рядки:" << endl;
	}
	

	cin.clear(); /**< Ця функція відновлює потік, якщо є помилка*/ 
	cin.sync(); /**< Очищається потік від наявних у ньому символів*/

	char **lines = new char*[n]; /**< Виділення пам’яті для масиву вказівників на n рядків*/
	for(int i = 0; i < n; i++)
	{
		lines[i] = new char[256]; /**< Виділення пам’яті для кожного рядка масиву*/
		cin.getline( lines[i], 256 );
	}

	for( int i = 0; i < n; i++ ) //**< Цикл який пробігається по рядках і знаходить цифрові символи */
	{
		int n = removeNumbers(lines[i]);
		cout <<"-------------"<<endl;
		cout << lines[i] << endl;
		cout << "\tКількість видалених символів: " << n << endl;
		cout <<"-------------"<<endl;
		
	}

	for( int i = 0; i < n; i++ )
		delete[] lines[i]; /**< Звільнення пам’яті від кожного рядка*/
	delete[] lines; /**< Звільнення пам’яті від масиву вказівників*/
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
		/**< Якщо символ є число - зміщення масиву вліво*/
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