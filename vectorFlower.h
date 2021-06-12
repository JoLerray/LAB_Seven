template <typename type>

class vectorFlower

{

	int size; //Размер массива

	type* data; //Указатель на массив

	void create(int n) //Создание массива

	{
		if (n < 0 || n > size) throw invalid_argument("Invalid value");
		data = new type[n];
		size = n;
	}

public:

	vectorFlower(int n) // Конструктор
	{
		create(n);
	}

	vectorFlower() // Конструктор по умолчанию
	{
		create(0);
	}

	~vectorFlower() // Деструктор
	{
		delete[] data;
	}

	int len() // Возврат размера массива
	{
		return size;
	}

	vectorFlower& push_back(type a) // Добавление элемента в конец массива
	{
		type* res = new type[size + 1];
		res[size] = a;
		for (int i = 0; i < size; i++) 
			res[i] = data[i];
		delete [] data;
		data = res;
 		size++;
		return *this;
	}

	type& operator [] (int i) // Оператор (для обращения по индексу)
	{
		if(i < 0 || i > size) throw out_of_range("Index is out of range array");
		return data[i];
	}

	void pop_back() // Удаление элемента в конеце массива
	{
		if (size == 0) throw out_of_range("Index is out of range array");
		size--;
		type* res = new type[size];
		for (int i = 0; i < size; i++) data[i] = res[i];
		delete[]data;
		data = res;
	}
	type& back() // Последний элемент массива
	{
		return data[size];
	}
};