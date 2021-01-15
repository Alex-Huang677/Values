#ifndef VALUES_H_
#define VALUES_H_
#include <iostream>
#include <algorithm>
#include <vector>
template <typename T>
class Values;
template <typename T>
std::ostream& operator<<(std::ostream& os, const Values<T>& obj);
template <typename T>
class Values
{
private:
	T* nums;
	T sum;
	T average;
	T max;
	T min;
	int size;
	static int num_arrays;
	T SetSum()
	{
		T sum_ = T(0);
		for (int i = 0; i < size; i++)
		{
			sum_ += nums[i];
		}
		return sum_;
	}
public:
	Values();
	Values(T* arr,int size_);
	Values(const std::vector<T>& arr);
	~Values();
	Values(const Values& obj);
	int GetSize() const;
	T* GetValues(T* const arr) const;
	T GetSum() const;
	T GetAverage() const;
	T GetMax() const;
	T GetMin() const;
	static int GetNums();
	void SetValues(T* arr, int size_);
	void SetValues(const std::vector<T> & arr);
	Values& operator=(const Values& obj);
	Values& operator=(const std::vector<T>& arr);
	T operator[](int index);
	Values& operator<(const std::vector<T>& arr);
	std::vector<T>& operator>(std::vector<T>& arr);
	friend std::ostream& operator<<<>(std::ostream& os, const Values<T>& obj);
};
template <typename T>
int Values<T>::num_arrays = 0;
template <typename T>
int Values<T>::GetNums()
{
	return num_arrays;
}
template <typename T>
Values<T>::Values()
{
	nums = new T[1];
	size = 0;
	nums[0] = 0;
	sum = 0;
	average = 0;
	max = 0;
	min = 0;
	num_arrays++;
}
template <typename T>
Values<T>::Values(T* arr,int size_)
{	
	size = size_;
	nums = new T[size];
	for (int i = 0; i < size; i++)
	{
		nums[i] = arr[i];
	}
	sum = SetSum();
	average = sum / size;
	max = *(std::max_element(nums, nums + size));
	min = *(std::min_element(nums, nums + size));
	num_arrays++;
}
template <typename T>
Values<T>::Values(const std::vector<T> & arr)
{
	size = arr.size();
	nums = new T[size];
	for (int i = 0; i < size; i++)
	{
		nums[i] = arr[i];
	}
	sum = SetSum();
	average = sum / size;
	max = *(std::max_element(nums, nums + size));
	min = *(std::min_element(nums, nums + size));
	num_arrays++;
}
template<typename T>
Values<T>::~Values()
{
	delete[] nums;
	--num_arrays;
}
template <typename T>
Values<T>::Values(const Values& obj)
{
	int size_ = obj.size;
	nums = new T[size_];
	size = size_;
	for(int i =0;i<size_;i++)
	{
		nums[i] = obj.nums[i];
	}
	sum = obj.sum;
	average = obj.average;
	max = obj.max;
	min = obj.min;
	num_arrays++;
}
template <typename T>
int Values<T>::GetSize() const
{
	return size;
}
template <typename T>
T* Values<T>::GetValues(T* const arr) const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = nums[i];
	}
	return arr;
}
template <typename T>
T Values<T>::GetSum() const
{
	return sum;
}
template <typename T>
T Values<T>::GetAverage() const
{
	return average;
}
template <typename T>
T Values<T>::GetMax() const
{
	return max;
}
template <typename T>
T Values<T>::GetMin() const
{
	return min;
}
template <typename T>
Values<T>& Values<T>::operator=(const Values& obj)
{
	if (this == &obj)
		return *this;
	delete[] nums;
	int size_ = obj.size;
	nums = new T[size_];
	size = size_;
	for (int i = 0; i < size_; i++)
	{
		nums[i] = obj.nums[i];
	}
	sum = obj.sum;
	average = obj.average;
	max = obj.max;
	min = obj.min;
	return *this;
}
template <typename T>
Values<T>& Values<T>::operator=(const std::vector<T>& arr)
{
	delete[] nums;
	size = arr.size();
	nums = new T[size];
	for (int i = 0; i < size; i++)
	{
		nums[i] = arr[i];
	}
	sum = SetSum();
	average = sum / size;
	max = *(std::max_element(nums, nums + size));
	min = *(std::min_element(nums, nums + size));
	return *this;
}
template <typename T>
void Values<T>::SetValues(T* arr,int size_)
{
	delete[] nums;
	size = size_;
	nums = new T[size];
	for (int i = 0; i < size; i++)
	{
		nums[i] = arr[i];
	}
	sum = SetSum();
	average = sum / size;
	max = *(std::max_element(nums, nums + size));
	min = *(std::min_element(nums, nums + size));
	num_arrays++;
}
template <typename T>
void Values<T>::SetValues(const std::vector<T> & arr)
{
	delete[] nums;
	size = arr.size();
	nums = new T[size];
	for (int i = 0; i < size; i++)
	{
		nums[i] = arr[i];
	}
	sum = SetSum();
	average = sum / size;
	max = *(std::max_element(nums, nums + size));
	min = *(std::min_element(nums, nums + size));
	num_arrays++;
}
template <typename T>
Values<T>& Values<T>::operator<(const std::vector<T>& arr)
{
	*this = arr;
	return *this;
}
template <typename T>
T Values<T>::operator[](int index)
{
	return nums[index];
}
template <typename T>
std::vector<T>& Values<T>::operator>(std::vector<T>& arr)
{
	std::vector<T> arr_(nums,nums + size);
	arr = arr_;
	return arr;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const Values<T>& obj)
{
	int size_ = obj.size;
	os << "数据值为：";
	for (int i = 0; i < size_; i++)
	{
		os << obj.nums[i] << " ";
	}
	os << std::endl;
	os << "和为：" << obj.sum << std::endl;
	os << "平均数为：" << obj.average << std::endl;
	os << "最大值为：" << obj.max << std::endl;
	os << "最小值为：" << obj.min << std::endl;
	return os;
}
#endif