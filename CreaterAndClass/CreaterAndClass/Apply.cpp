#include "Values.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
	*Values类是一个模板类，用于处理一组数据，可获得一组数据
	的和、平均数、最大值和最小值，并为数组计数
	*关于加权平均数、众数、中位数和二维数组数据的处理会在后面
	的版本中加入
	*/
	/*
	构造函数原形如下
	Values();   用于初始化一个对象
	Values(T* arr,int size_);   用于定义一个对象
	Values(const std::vector<T>& arr);   用于定义一个对象
	*/
	Values<int> obj1;
	float arr1[3] = { 1.0f,2.0f,3.0f };
	Values<float> obj2(arr1,3);
	double arr2[3] = { 3,4,5 };
	vector<double> v_arr1(arr2, arr2 + 3);
	Values<double> v_obj1(v_arr1);
	/*
	析构函数原型如下
	~Values();
	*/
	{
		Values<double> obj3;
		cout << Values<double>::GetNums() << endl;
	}
	cout << Values<double>::GetNums() << endl;
	/*
	复制构造函数原型如下
	Values(const Values& obj);
	赋值运算符原型如下
	Values& operator=(const Values& obj);
	Values& operator=(const std::vector<T>& arr);
	*/
	int arr3[3]= { 1,2,3 };
	Values<int> obj4(arr3,3);
	obj1 = obj4;
	Values<double> v_obj2 = v_arr1;
	/*
	<<运算符重载原型如下
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Values<T>& obj);
	//在类中重新声明为友元
	friend std::ostream& operator<<<>(std::ostream & os, const Values<T> & obj);
	<<可以把对象的成员按这种格式输出
	数据值为：x x x
	和为：
	平均数为：
	最大值为：
	最小值为：
	*/
	cout << obj4;
	cout << obj1;
	cout << v_obj1;
	cout << v_obj2;
	/*
	GetSize()函数用于获取对象储存的数组大小
	GetValues()函数用于获取对象储存的数组
	T* GetValues(T* arr) const;
	在调用此函数之前要先调用GetSize()函数获得对象储存的数组大小，
	再声明一个动态数组大小为对象储存的数组大小，后传入动态数组
	tips：使用后不要忘记delete[]你创建的动态数组
	GetSum()函数用于获取数组的和
	T GetSum() const;
	GetAverage()函数用于获取数组平均数
	T GetAverage() const;
	GetMax()、GetMin()函数用于获取数组最大值和最小值
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
	如代码行32和34，静态函数GetNums()用于返回一个类型的对象数量
	static int GetNums();
	*/
	cout << Values<double>::GetNums() << endl;
	/*
	* 函数SetValues()用于重新为一个对象的成员赋值
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
	Values类重载了[]，使它的对象可以像数组一样访问数据
	T operator[](int index);
	*/
	cout << obj4[2] << endl;
	/*
	Values类还重载了<和>，要求符号左为此类对象，右为一个向量对象
	<与=作用相同
	Values& operator<(const std::vector<T>& arr);
	>用于把Values对象储存的值赋给向量对象
	std::vector<T>& operator>(const std::vector<T>& arr);
	*/
	obj4 < v_arr2;
	cout << obj4;
	vector<int> v_arr3;
	obj4 > v_arr3;
	cout << v_arr3[0] << v_arr3[1] << v_arr3[2] << endl;
	//这个类目前功能就这些
	//作者会继续拓展功能
	return 0;
}