#include<iostream>
using namespace std;
void menu()// Меню программы
{
	cout << "Выберите одну их программ для выполнения" << endl;
	cout << "Пограмма 1 - позволяет вам ввести массив" << endl;
	cout << "Программ 2 - выводит массив, введенный в программе 1 " << endl;
	cout << "Программа 3 - сортирует числа по возростанию, опираясь на сумму цифр, стоящих на четных местах" << endl;
	cout << "Программа 4 - сортирует массив по возрастанию последней цифры в числе, в при совпадении послежних цифр - по убыванию" << endl;
	cout << "Программа 5 - Выход в контекстное меню" << endl;
	cout << "Ваш выбор: ";

}
void exit() {
	for (int i = 0; i < 10; i++) {
		cout << endl;

	}
}
int enter_size()//Функция для ввода размера массива
{
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	return size;// возвращает размер массива
}


int func1(int size, int *parr)//Функция, необходимая для выполнения 1 задания
{

	cout << "Вводите элементы массива(через пробел): "<< endl;
	for (int i=0; i < size; i++)
	{
		cin >> parr[i];
	}
	return *parr;

}
void func2(int size, int *parr)//Функция, необходимая для выполнения 2 задания
{
	cout << "Ваш массив:";
	for (int i = 0; i < size; i++)
	{
		cout << parr[i]<<" ";
	}
	cout << endl;
}
int func31(int a)// Функция для нахождениия  сумму четных цифр 
{
	int b = a;
	int c = a;
	int i = 0;
	int summ = 0;
	while (b > 0) {
		b /= 10;
		i++;
	}
	if (i % 2 == 0) {

		while (c > 0) {
			summ += c % 10;
			c /= 100;
		}
	}
	else {
		c /= 10;
		while (c > 0) {
			summ += c % 10;
			c /= 100;
		}
		i = 0;
	}
	return summ;
}

void func32(int size, int* parr)//Сортировка массива
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size - 1; j++)
		{
			if (func31(parr[i]) > func31(parr[j + 1]))
			{
				swap(parr[i], parr[j + 1]);


			}
		}
	}
	cout << "Отсортированный массив: ";
	for (int k = 0; k < size; k++)
	{
		cout << parr[k] << " ";
	}
}

void func4(int size,int *parr) {// cортировка для случая, когда заканчиваются на одинаковые цифры

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size - 1; j++)
		{
			if (parr[i]%10 != parr[i+1]%10)
				if (parr[i]%10 > parr[j + 1]%10){
					swap(parr[i], parr[j + 1]);
				}
			else {
				if (parr[i] < parr[j + 1]) {
					swap(parr[i], parr[j + 1]);
				}

			}
		}
	}
	cout << "Ваш массив: ";
	for (int g = 0; g < size; g ++ ) {
		cout << parr[g] << " ";
	}
}
int main()
{
	while (true) {


		setlocale(LC_ALL, "rus");
		int trigger;
		menu();
		cin >> trigger;
		if (trigger < 5) {


			int size = enter_size();
			int* parr = new int[size];
			switch (trigger)
			{
			case 1:
				func1(size, parr);
				exit();
				delete parr;
				break;
			case 2:
				func1(size, parr);
				func2(size, parr);
				exit();
				delete parr;
				break;
			case 3:
				func1(size, parr);
				func32(size, parr);
				exit();
				delete parr;
				break;
			case 4:
				func1(size, parr);
				func4(size, parr);
				exit();
				delete parr;
				break;

			default:
				cout << "Вы ввели недопустимое значение, попробуйте снова";
				exit();
				break;
			}
		}
		else if (trigger == 5)
		{
			exit();
			continue;
		}
		else {
			cout << "Вы ввели недопустимое значение, попробуйте снова";
			exit();
			continue;
		}
	}
	
}