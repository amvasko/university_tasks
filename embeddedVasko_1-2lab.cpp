
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
/*
Simeon Trendov, [22.03.2024 15:38]
1. Write a program that will print the elements of a one-dimensional array separated by spaces.

Simeon Trendov, [22.03.2024 15:52]
2. Write a program that will calculate the sum and the product of the numbers of an array of n elements.

Simeon Trendov, [22.03.2024 16:07]
3. Write a program that calculates separately the sum of the positive and the sum of the negative numbers of a sequence of n elements.

Simeon Trendov, [22.03.2024 16:17]
4. Write a program that calculates the average mark of a student if the number of subjects is read, and then his grades.

Simeon Trendov, [22.03.2024 16:26]
5. Write a program that examines how many times the letter K occurs in the array.

Simeon Trendov, [22.03.2024 16:35]
Homework: Write a program that determines the largest element in an array with n elements and its location.

*/
using namespace std;
void arrayToSeparate(int *arr,int n)
{
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand() % 30 + 1;
		cout << arr[i] << " ";
	}
	cout << "\n";
}

double calculateAverageMark(int *mas,int numSubjects) {
	double totalMarks = 0;

	for (int i = 0; i < numSubjects; ++i) {
		double mark;
		mark = rand() % 30 + 1;
		totalMarks += mark;
	}
	double avg = totalMarks / numSubjects;
	cout << "\nAverage marks" << avg<<'\n';
	return avg;
}

void arraySumAndMultiply(int* arr, int n)
{
	int sumResult, productResult;
	sumResult = 0;productResult = 1;
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand() % 30 + 1;
		sumResult += arr[i];
	}
		cout << "REsult sum`s is  " << sumResult << "\n";
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand() % 30 + 1;
		productResult *= arr[i];
	}
		cout << "REsult multiply`s is  " << productResult;
	cout << "\n";
}
void sumOfArr_MinusSign(int *arr,int n)
{
	int sResult = 0;
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = (rand() % 30 + 1) * (rand() % 2 == 0 ? 1 : -1);
		
		if(arr[i] < 0)
		{
			sResult += arr[i];
		}
	}
	cout << "Sum`s minus numbers equal: " << sResult;
}

int countOccurrencesOfK(const string& text) {
	int count = 0;
	for (char c : text) {
		if (c == 'K' || c == 'k') {
			count++;
		}
	}
	cout << "k occurences is " << count;
	printf("K occurences is %d in word %s",count,text);
	return count;
}
void findMaximumValue(int* arr, int n)
{
	int maximum = arr[0]; // Initialize maximum with the first element of the array

	// Iterate through the array to find the maximum value
	for (int i = 1; i < n; i++) // Start from the second element
	{
		if (arr[i] > maximum) // Compare current element with maximum
		{
			maximum = arr[i]; // Update maximum if current element is greater
		}
	}

	// Print the maximum value
	cout << "Maximum value is: " << maximum << endl;
}

/*
1. Write a program that will print out all of the elements in a row in the matrix whose rows sum is
bigger then the sum of the elements in the diagonal.

2. Write a program that takes the dimensions of a matrix and the matrix as input. The p
rogram
should find the two columns where the sum of the elements is the largest. Then the elements in
those columns should be swapped and reversed (the first becoming the last, the second becoming
the second to last, and so on). Finally, print the newly obtained matrix on the screen.
*/

void findBiggerDiagonalElements()
{
	int arr[5][5];
	int diagonalSumm = 0,rawSum = 0;
	for (size_t i = 0; i < 5; i++)
	{
		
		for (size_t j = 0; j< 5; j++)
		{
			arr[i][j] = rand() % 20 + 1;
			if (i == j) {
				diagonalSumm += arr[i][j];
			
				cout << diagonalSumm <<  "  \t";
			}
		}
		cout << "\n";
	}
}
void printRowsWithSumGreaterThanDiagonal(const vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	int diagonalSum = 0;
	for (int i = 0; i < rows; i++) {
		diagonalSum += matrix[i][i];
	}

	for (int i = 0; i < rows; i++) {
		int rowSum = 0;
		for (int j = 0; j < cols; j++) {
			rowSum += matrix[i][j];
		}
		if (rowSum > diagonalSum) {
			cout << "Row " << i + 1 << ": ";
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}
void swapAndReverseColumns(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	
	vector<int> colSums(cols, 0);
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			colSums[j] += matrix[i][j];
		}
	}

	int maxIndex1 = max_element(colSums.begin(), colSums.end()) - colSums.begin();
	colSums[maxIndex1] = 0; 
	int maxIndex2 = max_element(colSums.begin(), colSums.end()) - colSums.begin();


	for (int i = 0; i < rows; i++) {
		swap(matrix[i][maxIndex1], matrix[i][maxIndex2]);
	}
	for (int i = 0; i < rows; i++) {
		reverse(matrix[i].begin() + maxIndex1, matrix[i].begin() + maxIndex1 + 1);
		reverse(matrix[i].begin() + maxIndex2, matrix[i].begin() + maxIndex2 + 1);
	}
}
int main()
{
	const int length = 10;
	string someText = "Holla, kicking wicking,bakery";
	int *mas = new int[length];
	// 1 Task
	arrayToSeparate(mas, length);
	// 2 Task
	arraySumAndMultiply(mas, length);
	// 3 Task 
	sumOfArr_MinusSign(mas,length);
	// 4 Task 
	calculateAverageMark(mas, length);
	// 5 Task
	countOccurrencesOfK(someText);

	// HOMEWORK 6 && 7 task completed
	findMaximumValue(mas, length);
	//findBiggerDiagonalElements();
	vector<vector<int>> matrix = {
	   {1, 2, 3},
	   {4, 5, 6},
	   {7, 8, 9}
	};
	printRowsWithSumGreaterThanDiagonal(matrix);
	
	swapAndReverseColumns(matrix);

	for (const auto& row : matrix) {
		for (int element : row) {
			cout << element << " ";
		}
		cout << endl;
	}

	delete[] mas;

}

