template <typename type>

class vectorFlower

{

	int size; //������ �������

	type* data; //��������� �� ������

	void create(int n) //�������� �������

	{
		if (n < 0 || n > size) throw invalid_argument("Invalid value");
		data = new type[n];
		size = n;
	}

public:

	vectorFlower(int n) // �����������
	{
		create(n);
	}

	vectorFlower() // ����������� �� ���������
	{
		create(0);
	}

	~vectorFlower() // ����������
	{
		delete[] data;
	}

	int len() // ������� ������� �������
	{
		return size;
	}

	vectorFlower& push_back(type a) // ���������� �������� � ����� �������
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

	type& operator [] (int i) // �������� (��� ��������� �� �������)
	{
		if(i < 0 || i > size) throw out_of_range("Index is out of range array");
		return data[i];
	}

	void pop_back() // �������� �������� � ������ �������
	{
		if (size == 0) throw out_of_range("Index is out of range array");
		size--;
		type* res = new type[size];
		for (int i = 0; i < size; i++) data[i] = res[i];
		delete[]data;
		data = res;
	}
	type& back() // ��������� ������� �������
	{
		return data[size];
	}
};