#include <iostream>
using namespace std;

class subvector
{
	public:

		subvector()
		{
			capacity = 0;
			top = 0;
			data = new int[0];
		}

		~subvector()
		{
			delete[] data;
		}
		
		void push_back(int new_element)
		{
			if (capacity > top)
			{
				data[top] = new_element;
				top++;
			}
			else
			{
				int* new_data = new int[capacity * 2];
				new_data = data;
				new_data[top] = new_element;
				top++;
				delete[] data;
				data = new_data;
			}
		}

		void resize(unsigned int new_capacity)
		{
			if (new_capacity == capacity)
			{
				return;
			}
			else if (new_capacity > capacity)
			{
				int* new_data = new int[new_capacity];
				new_data = data;
				delete[] data;
				data = new_data;
				capacity = new_capacity;
			}
			else
			{
				int* new_data = new int[new_capacity];
				for (int i = 0; i < new_capacity; i++)
				{
					new_data[i] = data[i];
				}
				delete[] data;
				data = new_data;
				capacity = new_capacity;
				top = new_capacity;
			}
		}

		void shrink_to_fit()
		{
			int* new_data = new int[top];
			for (int i = 0; i < top; i++)
			{
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			capacity = top;
		}

		void clear()
		{
			for (int i = 0; i < top; i++)
			{
				data[i] = 0;
			}
			capacity = 0;
			top = 0;
		}

	private:

		unsigned int capacity;
		unsigned int top;
		int* data;
};

int main()
{

	return 0;
}