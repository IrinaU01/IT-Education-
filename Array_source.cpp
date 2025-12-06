#include <iostream>
using namespace std;


class MyArray
{
private:
	int* arr;
	mutable unsigned int size;
public:
	MyArray()
	{
		arr = nullptr;
		size = 0;
	}
	MyArray(unsigned int size, int* arr)
	{
		this->size = size;
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
	}
	MyArray(unsigned int size)
	{
		this->size = size;
		arr = new int[size] {};
	}
	MyArray(const MyArray& obj)
	{
		this->size = obj.size;
		this->arr = new int[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}
	void print() const
	{
		for (unsigned int i = 0; i < size; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	void setSize(unsigned int size)
	{
		int* new_arr = new int [size] {};
		if (size >= this->size)
		{
			for (int i = 0; i < this->size; i++)
			{
				new_arr[i] = arr[i];
			}

		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				new_arr[i] = arr[i];
			}
		}
	delete[] arr;
	arr = new_arr;
	this->size = size;
	}
	unsigned int getSize() const
	{
		this->size = 4;
		return this->size;
	}
	~MyArray()
	{
		if (arr != nullptr)
			delete[] arr;
	}
};


int main()
{
	const unsigned int N = 5;
	int arr[N] = { 6,3,4,6,2 };
	MyArray arr1{ N, arr };
	arr1.print();
	arr1.setSize(2);
	MyArray arr2 = arr1;
	arr2.print();
	arr1.setSize(10); /* нічого не буде, бо сетер нічого не повертає*/
}
