// Written by Nicholas Munoz Sec 1004 Assignment 6 
#include<iostream>
using namespace std;
#include "matrix.h"



// Non Member Functions 
// function prototype
int fileOpen(ifstream &file, string fileName)
{

	file.open(fileName); // opens the file
	if(file.fail()) // checks if file is open
	{
		return -1;
	}

	return 0;

}
int fileRead(ifstream& file, int array2D[][cols])
{
	for (int i = 0; i < 10; i++)
	{	for( int j =0; j< 10; j++)
	{
		file >> array2D[i][j]; // reads in values into the array
	}
	}
	return 0;
}
void print_matrix(const int M[rows][cols], int n, int m)
{
	static const char* green = "\033[0;32m"; // sets text to green
	static const char* white = "\033[0;37m"; // sets text to white
	static const char* red = "\033[0;31m"; // sets text to red
	for (int i = 0; i < n; i++)
		cout << " -----";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << "|" <<red<< i << j <<white<< "   ";
		cout << "|" << endl;
		for (int j = 0; j < m; j++)
			cout << "|" << setw(4) << right << M[i][j]<<" ";
		cout << "|" << endl;
		for (int j = 0; j < m; j++)
			cout << "|     ";
		cout << "|" << endl;
		for (int j = 0; j < m; j++)
		{
			cout << " -----";
		}
		cout << endl;
	}
	cout << endl;



}
// Friend Functions 
ostream& operator << (ostream& s, const Matrix& c)
{	
	static const char* green = "\033[0;32m"; // sets text to green
	static const char* white = "\033[0;37m"; // sets text to white
	static const char* red = "\033[0;31m"; // sets text to red
	for (int i = 0; i < c.size; i++)
		s << " -----";
	s << endl;
	for (int i = 0; i < c.size; i++)
	{
		for (int j = 0; j < c.size; j++)
			s << "|     ";
		s << "|" << endl;
		for (int j = 0; j < c.size; j++)
			s << "| " <<green<< setw(3) << right << c.matrix[i][j]<<white <<" ";
		s << "|" << endl;
		for (int j = 0; j < c.size; j++)
			s << "|     ";
		s << "|" << endl;
		for (int j = 0; j < c.size; j++)
		{
			s << " -----";
		}
		s << endl;
	}
	s << endl;
 

	return s;
}

istream& operator >> (istream& s, Matrix& c)
{


	cout << "Enter matrix element (size)X(size)" << endl;
	for (int i = 0; i < c.size; i++)
	{
		for (int j = 0; j < c.size; j++)
		{
			
			cout << "row:["<<i<<"]"<< "column:[" << j << "]" << endl;
			s >> c.matrix[i][j];

		}
	}
	return s;


}

// Class Members 
// function to display the matrix
void Matrix:: display()
{

	static const char* green = "\033[0;32m"; // sets text to green
	static const char* white = "\033[0;37m"; // sets text to white
	static const char* red = "\033[0;31m"; // sets text to red
	for (int i = 0; i < size; i++)
		cout << " -----";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << "|" << red << i << j << white << "   ";
		cout << "|" << endl;
		for (int j = 0; j < size; j++)
			cout << "|"  << setw(4) << right << matrix[i][j] <<" ";
		cout << "|" << endl;
		for (int j = 0; j < size; j++)
			cout << "|     ";
		cout << "|" << endl;
		for (int j = 0; j < size; j++)
		{
			cout << " -----";
		}
		cout << endl;
	}
	cout << endl;
}
// function to deallocate the matrix
void Matrix::DeallocateMatrix()
{
	if (matrix != NULL) // checks if matrix is empty
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i]; // deletes each row
		}
		delete[] matrix; // deletes the matrix 
		matrix = nullptr;
	}
}
// this function
// checks the size of the passed in value
// and allocates a size x size
// matrix while 
// setting each entry to 0
Matrix::Matrix(int size)
{

	if ( size<MATRIX_SIZE_MIN|| size>MATRIX_SIZE_MAX)
	{
		this->size = 0; // sets size to 0 if invalid
		matrix = NULL; // sets matrix to Null
		cout << "Invalid matrix size;" << endl; // Prints Error
	}
	else
	{
		this->size = size; // sets size to passed parameter
		// allocate 2-d array
		matrix = new int* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new int[size];
		// initialize 2-d array
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		} // set each entry to 0
	}





}
// this function call the
// deallocate matrix function 
// and is the destructor 
Matrix::~Matrix()
{
	DeallocateMatrix();
}
// this function creates a matrix
void Matrix::createMatrix(int A[MATRIX_SIZE][MATRIX_SIZE])
{
	int index;
	int row;
	int column;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Enter matrix index for " << i << j << endl;
			do
			{
				{
					cin >> index;
					row = index / 10;
					column = index % 10;

				}
			} while (index < 0 || index > 99);

		matrix[i][j] = A[row][column];
		}
	}



}
// this function will copy the 
// values of the passed in matrix 
// into the class matrix
Matrix::Matrix(Matrix &x) // copy constructor 
{

	size = x.size;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	// initialize 2-d array
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			
			
				matrix[i][j] = x.matrix[i][j];
			
		}
	} // set each entry to corresponding values


}

// Operator Overloading Functions
// this function will add two matrices together
void Matrix:: operator+(Matrix x) // matrix 1 + matrix 2
{	
	Matrix temp(size);
	cout << "Result of Matrix1 + Matrix2: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp.matrix != NULL)
			{
				temp.matrix[i][j] = this->matrix[i][j] + x.matrix[i][j];
			}
			
		}

	}
	cout << temp << endl;
}
// function that will
// subtract the difference between
// two matrices
void Matrix:: operator-(Matrix x)
{

	Matrix temp(size);
	cout << "Result of Matrix1 - Matrix2: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp.matrix != NULL)
			{
				temp.matrix[i][j] = this->matrix[i][j] - x.matrix[i][j];
			}
		}

	}
	cout << temp << endl;
}
// function that will 
// increment the values of the matrix
void Matrix:: operator++() // pre increment
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j]++;
		}
	}
	
}
// function that will 
// increment the values of the matrix
void Matrix:: operator++(int x) // post increment
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j]++;
		}
	}

}
// function that will 
// decrement the values of the matrix
void Matrix:: operator--() // pre decrement
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j]--;
		}
	}

}
// function that will 
// decrement the values of the matrix
void Matrix:: operator--(int x) // post decrement
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j]--;
		}
	}

}
void Matrix::operator!()
{

	Matrix temp(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp.matrix!= NULL)
			{
				temp.matrix[i][j] = this->matrix[j][i];
			}
		}

	}
	cout << temp << endl;

}
// function that does 
// the multiplication of two matrices
void Matrix:: operator*(Matrix x)
{
	Matrix temp(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)

			{
				if (temp.matrix!=nullptr)
				{
					temp.matrix[i][j] += ((this->matrix[i][k]) * (x.matrix[k][j]));
				}
				
			}


		}
	}
	cout << temp << endl;
}
Matrix& Matrix:: operator=(Matrix& x)
{
	DeallocateMatrix();
	size = x.size;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	// initialize 2-d array
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = x.matrix[i][j];// set each entry to corresponding values
		}  
	}
	return *this;
}








