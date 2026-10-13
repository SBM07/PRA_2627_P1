#include <ostream>
#include <stdexcept>
#include "List.h"
#ifndef LISTARRAY_H
#define LISTARRAY_H




template <typename T>
class ListArray : public List<T> {
public:
	
	void insert(int pos, T e) override {}
	void append(T e) override{}
	void prepend(T e) override {}
	T remove(int pos) override {return T(); }
	T get(int pos) override { return T(); }
	int search(T e) override { return -1; }
	bool empty() override { return true; }
	int size() override { return 0; }
	
	
	
	
	
	
	
	
	
	
	
	
	
	ListArray(){
		arr = new T[MINSIZE];
		int max;
		int n;
	}

	~ListArray() override{
		delete[] arr;
	}


	T operator[](int pos){
		if(pos < 0 || pos > this->size() - 1){
			throw std::out_of_range("Posición no válida");
		} return arr[pos];
		}
			
	


	friend std::ostream& operator<<(
    	std::ostream &out,
   	ListArray<T> &list){
	
		for(int i = 0; i < list.size(); i++){
		
			out << list[i] << " ";
		
		}

		return out;
	
		}
		

	




private:
	T* arr;
	int max;
	int n;
	void resize(int new_size){
		T* arr2 = new T[new_size];
		}
	static const int MINSIZE = 0;

	};
#endif
