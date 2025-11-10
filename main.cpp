#include <iostream>

using namespace std;

template <typename T>

class GenericArray {

	protected:
		T *array;
		int array_size = 0;

	public:
		
		// Constuctors
		GenericArray() {array = 0;}

		// Destructor
		~GenericArray() {delete[] array; cout << "Destructor Called" << endl;}
		

		// Add Element
		void addElement(T element) {

			T *newArray = new T[array_size + 1];
			
			for (int i = 0; i < array_size; i++) {
				newArray[i] = array[i];
			}

			newArray[array_size] = element;

			array = newArray;
			array_size++;

		}

		// Print array
		void printArray() {

			cout << "Array:" << endl;
			for (int i = 0; i < array_size; i++) {
				cout << array[i] << " ";
			}
			cout << endl;

		} 

		// Value at index
		T at(T value) {

			if (value < array_size) {
				return array[value];
			}
			
			else {
				return 0;
			}

		}

		// Size of array
		int size() {return array_size;}

		// Sum of array elements
		T sum() {

			T sum = 0;

			for (int i = 0; i < array_size; i++) {
				sum += array[i];
			}

			return sum;

		}

		// Max value in array
		T max() {

			T max = array[0];

			for (int i = 1; i < array_size; i++) {
				if (array[i] > max) {max = array[i];}
			}

			return max;

		}

		// Min value in array
		T min() {

			T min = array[0];

			for (int i = 1; i < array_size; i++) {
				if (array[i] < min) {min = array[i];}
			}

			return min;

		}

		// Slice of array
		T* slice(int begin, int end) {

			int new_size = end - begin + 1;

			T *slice = new T[new_size];

			for (int i = 0; i < new_size; i++) {
				slice[i] = array[begin + i];
			}

			return slice;

		}

};

int main() {

	GenericArray<int> int_array;

	int_array.addElement(10);
	int_array.addElement(20);
	int_array.addElement(30);
	int_array.addElement(40);
	int_array.addElement(50);

	int_array.printArray();

	cout << "Size of array: " << int_array.size() << endl;
  cout << "Value of index 2: " << int_array.at(2) << endl;
	cout << "Sum of array: " << int_array.sum() << endl;
	cout << "Max value in array: " << int_array.max() << endl;
	cout << "Min value in array: " << int_array.min() << endl;

	int *temp = int_array.slice(1, 3);

	cout << "Array from index 1 to 3: " << endl;
	for (int i = 0; i <= (3 - 1); i++) {
		cout << temp[i] << " ";
	}
	cout << endl;

	return 0;

}
