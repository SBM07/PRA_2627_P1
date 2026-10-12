#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
public:
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
	static const int MINSIZE;
	void resize(int new_size){
		T* arr2 = new T[new_size];
		}

	};


