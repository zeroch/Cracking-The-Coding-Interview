#include <vector>
#include <iostream>

using namespace std;
void printMatrix(vector<vector<int>> v)
{
	for(int i = 0; i< v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << '\t';
		}
		std::cout << endl;
	}
}

class NumMatrix {

public:
	vector<vector<vector<int>>> sum_map;

	// helper function dp to create a sum of a row
	vector<vector<int>> sumRow(vector<int> m_row)
	{
		vector<vector<int>> ret;
		int size = m_row.size();
		if (size == 0) return ret;
		ret.push_back(m_row); //make a copy;

		for(int i=1; i< size; ++i)
		{
			vector<int> temp;
			int j =0;
			for(; j < i; ++j) temp.push_back(0);
			for(; j<size; ++j)
			{
				int cur = ret[i-1][j-1] + m_row[j];
				temp.push_back(cur);
			}
			ret.push_back(temp);
		}
		return ret;
	}
	void generateSumMap(vector<vector<int>> matrix)
	{
		for(int i = 0; i< matrix.size(); ++i)
		{
			vector<vector<int>> m_sumRow = sumRow(matrix[i]);
			sum_map.push_back(m_sumRow);
		}
	}





	NumMatrix(vector<vector<int>> &matrix) {
	   generateSumMap(matrix);
	}

	int sumColRegion(int col1, int col2, int row)
	{
		vector<vector<int>> sumRow = sum_map[row];
		// in our dp discussion.
		int ret = sumRow[col2-col1][col2];
		return ret;
	}


	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int i = row1; i <= row2; i++)
		{
			sum += sumColRegion(col1,col2, i);
		}
		return sum;
	}

};

int main()
{
	vector<vector<int>> matrix;
	{	static const int arr[] = {3,0,1,4,2};
		vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		matrix.push_back(vec);
	}
	{	static const int arr[] = {5,6,3,2,1};
		vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		matrix.push_back(vec);
	}
	{	static const int arr[] = {1,2,0,1,5};
		vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		matrix.push_back(vec);
	}
	{	static const int arr[] = {4,1,0,1,7};
		vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		matrix.push_back(vec);
	}
	{	static const int arr[] = {1,0,3,0,5};
		vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		matrix.push_back(vec);
	}
	printMatrix(matrix);
	NumMatrix m_numMatrix = NumMatrix(matrix);
	cout << m_numMatrix.sumRegion(2,1,4,3) << endl;
	cout << m_numMatrix.sumRegion(1,1,2,2) << endl;
	cout << m_numMatrix.sumRegion(1,2,2,4) << endl;
	//vector<> matrix = [,[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]];
	//,sumRegion(2,1,4,3),sumRegion(1,1,2,2),sumRegion(1,2,2,4)
	//NumMatrix
	return 0;
}
