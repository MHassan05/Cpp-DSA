//#include <iostream>
//
//class myArray
//{
//	int total_size;
//	int used_size;
//	int* ptr;
//public:
//	myArray(int tSize = 0, int uSize = 0)
//	{
//		this->total_size = tSize;
//		this->used_size = uSize;
//		this->ptr = new int[tSize];
//	}
//
//	void show() {
//		for (int i = 0; i < this->used_size; i++)
//		{
//			std::cout << (this->ptr)[i] << std::endl;
//		}
//	}
//
//	void setVal() {
//		int n;
//		for (int i = 0; i < this->used_size; i++)
//		{
//			std::cout << "Enter element " << i << ": ";
//			std::cin >> n;
//			(this->ptr)[i] = n;
//		}
//	}
//
//
//	/*
//	* You can also write other functions like insertion and deletion but you need to update the
//	* values like used_size and totol_size
//	*/
//
//
//	~myArray()
//	{
//		delete[] ptr;
//	}
//};
//
//int main() {
//	myArray marks(10, 2);
//	std::cout << "We are running setVal now" << std::endl;
//	marks.setVal();
//
//	std::cout << "We are running show now" << std::endl;
//	marks.show();
//
//	return 0;
//}