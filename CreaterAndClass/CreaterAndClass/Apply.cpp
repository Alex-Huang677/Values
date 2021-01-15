#include "Values.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
	*Values����һ��ģ���࣬���ڴ���һ�����ݣ��ɻ��һ������
	�ĺ͡�ƽ���������ֵ����Сֵ����Ϊ�������
	*���ڼ�Ȩƽ��������������λ���Ͷ�ά�������ݵĴ�����ں���
	�İ汾�м���
	*/
	/*
	���캯��ԭ������
	Values();   ���ڳ�ʼ��һ������
	Values(T* arr,int size_);   ���ڶ���һ������
	Values(const std::vector<T>& arr);   ���ڶ���һ������
	*/
	Values<int> obj1;
	float arr1[3] = { 1.0f,2.0f,3.0f };
	Values<float> obj2(arr1,3);
	double arr2[3] = { 3,4,5 };
	vector<double> v_arr1(arr2, arr2 + 3);
	Values<double> v_obj1(v_arr1);
	/*
	��������ԭ������
	~Values();
	*/
	{
		Values<double> obj3;
		cout << Values<double>::GetNums() << endl;
	}
	cout << Values<double>::GetNums() << endl;
	/*
	���ƹ��캯��ԭ������
	Values(const Values& obj);
	��ֵ�����ԭ������
	Values& operator=(const Values& obj);
	Values& operator=(const std::vector<T>& arr);
	*/
	int arr3[3]= { 1,2,3 };
	Values<int> obj4(arr3,3);
	obj1 = obj4;
	Values<double> v_obj2 = v_arr1;
	/*
	<<���������ԭ������
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Values<T>& obj);
	//��������������Ϊ��Ԫ
	friend std::ostream& operator<<<>(std::ostream & os, const Values<T> & obj);
	<<���԰Ѷ���ĳ�Ա�����ָ�ʽ���
	����ֵΪ��x x x
	��Ϊ��
	ƽ����Ϊ��
	���ֵΪ��
	��СֵΪ��
	*/
	cout << obj4;
	cout << obj1;
	cout << v_obj1;
	cout << v_obj2;
	/*
	GetSize()�������ڻ�ȡ���󴢴�������С
	GetValues()�������ڻ�ȡ���󴢴������
	T* GetValues(T* arr) const;
	�ڵ��ô˺���֮ǰҪ�ȵ���GetSize()������ö��󴢴�������С��
	������һ����̬�����СΪ���󴢴�������С�����붯̬����
	tips��ʹ�ú�Ҫ����delete[]�㴴���Ķ�̬����
	GetSum()�������ڻ�ȡ����ĺ�
	T GetSum() const;
	GetAverage()�������ڻ�ȡ����ƽ����
	T GetAverage() const;
	GetMax()��GetMin()�������ڻ�ȡ�������ֵ����Сֵ
	T GetMax() const;
	T GetMin() const;
	*/
	int size4 = obj4.GetSize();
	int* p = new int[size4];
	obj4.GetValues(p);
	for (int i = 0; i < size4; i++)
	{
		cout << p[i];
	}
	cout << endl;
	delete[] p;
	int sum4 = obj4.GetSum();
	int average4 = obj4.GetAverage();
	int max4 = obj4.GetMax();
	int min4 = obj4.GetMin();
	cout << sum4 << average4 << max4 << min4 << endl;
	/*
	�������32��34����̬����GetNums()���ڷ���һ�����͵Ķ�������
	static int GetNums();
	*/
	cout << Values<double>::GetNums() << endl;
	/*
	* ����SetValues()��������Ϊһ������ĳ�Ա��ֵ
	void SetValues(T* arr, int size_);
	void SetValues(const std::vector<T> & arr);
	*/
	int arr4[3] = { 32,66,78 };
	vector<int> v_arr2(arr4, arr4 + 3);
	obj4.SetValues(arr4,3);
	cout << obj4 << endl;
	obj4.SetValues(v_arr2);
	cout << obj4;
	/*
	Values��������[]��ʹ���Ķ������������һ����������
	T operator[](int index);
	*/
	cout << obj4[2] << endl;
	/*
	Values�໹������<��>��Ҫ�������Ϊ���������Ϊһ����������
	<��=������ͬ
	Values& operator<(const std::vector<T>& arr);
	>���ڰ�Values���󴢴��ֵ������������
	std::vector<T>& operator>(const std::vector<T>& arr);
	*/
	obj4 < v_arr2;
	cout << obj4;
	vector<int> v_arr3;
	obj4 > v_arr3;
	cout << v_arr3[0] << v_arr3[1] << v_arr3[2] << endl;
	//�����Ŀǰ���ܾ���Щ
	//���߻������չ����
	return 0;
}