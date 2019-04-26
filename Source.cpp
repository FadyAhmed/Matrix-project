#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<sstream>
//using namespace std;
void rowXcol(double frist[],double second[],int rows1,int rows2,int column1,int column2,int row,
	int col,double result[],int resultindex)
{
		for( col;col<((rows2*column2));col+=column2)
		{
			
			result[resultindex] += frist[row] * second[col];
			row++;
		}
}
int num_of_spaces(std::string line_mat)
{
	int spaces = 0;
	int index_of_space = 0;
	int length = line_mat.length();
	for (int i = 0; i <= length; i++)
	{
		index_of_space = line_mat.find(' ', index_of_space + 1);
		if (index_of_space == -1)
		{
			break;
		}
		spaces++;
	}
	return spaces;
}
int num_of_colons(std::string line_mat)
{
	int colons = 0;
	int index_of_colon = 0;
	int length = line_mat.length();
	for (int i = 0; i <= length; i++)
	{
		index_of_colon = line_mat.find(';', index_of_colon + 1);
		if (index_of_colon == -1)
		{
			break;
		}
		colons++;
	}
	return colons;
}
double convert_to_double(std::string s)
{
	double v;
	v = atof(s.c_str());
	return v;
}
std::string convert_to_string(double d)
{
	std::string str;
	std::ostringstream ss;
	ss << d;
	str = ss.str();
	return str;
}

void convert_my_matrix_to_double(std::string elments[], double matrix[])
{
	for (int i = 0; i <= 99; i++)
	{
		std::string temp = elments[i];
		matrix[i] = convert_to_double(temp);
	}
}
void convert_my_matrix_to_string(double elments[], std::string matrix[])
{
	for (int i = 0; i <= 99; i++)
	{
		double temp = elments[i];
		matrix[i] = convert_to_string(temp);
	}
}

int num_of_rows(std::string s)
{
	int num_of_rows = num_of_colons(s) + 1;
	return num_of_rows;
}
int num_of_columns(std::string s)
{
	int num_of_columns = (num_of_spaces(s) + num_of_colons(s) + 1) / num_of_rows(s);
	return num_of_columns;
}


/*string construct_second_line(string line_mat, int start, int end)
{
	string x;

	for (int i = start; i < end; i++)
	{
		x = x + line_mat[i];
	}
	return x;
}*/
std::string construct_string(std::string line_mat,int start,int end)
{
	std::string x;
	if (line_mat[start] == ' '|| line_mat[start] == ';') start++;
	for (int i = start; i < end; i++)
	{
		x = x+ line_mat[i];
	}
	return x;
}
void parse(std::string line_mat, std::string elments[])
{
	std::string oneElement;
	int lastspace = 1;
	int j = 0;
	int p = 0;
	int step = 0;
	int lenght = 0;
	int index = 0;
	int length = line_mat.length();
	for (int i = 0; i <= length; i++)
	{
		if(line_mat[i]==' ' || line_mat[i] == ';'|| line_mat[i] == ']')
		{
			oneElement = construct_string(line_mat, lastspace, i);
			elments[j] = oneElement;
			lastspace = i;
			j++;
		}
		
	}
}
/*void colon_parsing(string line_mat, string elments[])
{
	string oneElement;
	int lastcolon = 1;
	int lenght = 0;
	int index_of_colon = 0;
	int length = line_mat.length();
	for (int i = 0; i <= length; i++)
	{
		index_of_colon = line_mat.find(';', index_of_colon + 1);
		if (index_of_colon == -1)
		{
			oneElement = construct_first_line(line_mat, lastcolon, length - 1);
			elments[i] = oneElement;
			break;
		}

		else
		{
			oneElement = construct_first_line(line_mat, lastcolon, index_of_colon);
		}
		elments[i] = oneElement;
		lastcolon = index_of_colon;
	}
}*/
/*void space_parsing(string elments[])
{
	string oneElement;
	int lastspace = 1;
	int lenght = 0;
	int index_of_space = 0;
	int index_of_colon = 0;
	string line_mat;
	int length ;
		for(int i=0;i<=99;i++)
		{
			line_mat = elments[i];
			length = line_mat.length();
			for (int i = 0; i <= length; i++) {
				index_of_space = line_mat.find(' ', index_of_space + 1);
				if (index_of_space == -1)
				{
					oneElement = construct_second_line(line_mat, lastspace, length - 1);
					elments[i] = oneElement;
					break;
				}

				else
				{
					oneElement = construct_second_line(line_mat, lastspace, index_of_space);
				}
				elments[i] = oneElement;
				lastspace = index_of_space;
			}
	}	
}*/
void add(double frist_matrix[], double second_matrix[], int rows1, int rows2, int column1,
	int column2, double result[])
{
	int h = 0;
	for (int i = 0; i < 1000; i++) { result[i] = 0; }

	for (int i = 0; i < 1000; i++)
	{
		result[i] = frist_matrix[i] + second_matrix[i];
	}
	std::string result_string[1000];
	convert_my_matrix_to_string(result, result_string);
	std::cout << "[";
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < column1; j++)
		{
			std::cout << result[h];
			if(j<column1-1){std::cout<< " ";}
			h++;
		}
		if (i<(rows1-1)){std::cout << ";";}
	}
	std::cout << "]";
}
void sub(double frist_matrix[], double second_matrix[], int rows1, int rows2, int column1,
	int column2, double result[])
{
	int h = 0;
	for (int i = 0; i < 1000; i++) { result[i] = 0; }

	for (int i = 0; i < 1000; i++)
	{
		result[i] = frist_matrix[i] - second_matrix[i];
	}
	std::string result_string[1000];
	convert_my_matrix_to_string(result, result_string);
	std::cout << "[";
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < column1; j++)
		{
			std::cout << result[h];
			if (j < column1 - 1) { std::cout << " "; }
			h++;
		}
		if (i < (rows1 - 1)) { std::cout << ";"; }
	}
	std::cout << "]";
}

void multiply(double frist_matrix[], double second_matrix[], int rows1, int rows2, int column1,
	int column2, double result[])
{
	int h = 0;
	int g = 0;
	int p = 0;
	int j = 0;
	int row = 0;
	int col = 0;
	int i = 0;
	int fristP = 0;
	//zeroing result matrix
	for (int i = 0; i < 1000; i++) { result[i] = 0; }
	//calculating results
	/*for (int i = 0; i < 1000; i++)
	{
		if((p-column2)==(rows2*column2)-1)
		{
			p = 0;
			g = column1;
			fristP = 0;
		}
		else
		{
			p = fristP;
			if (i == rows1) { g += column1; }
			else { g = 0; }
		}
			for (j = 0; j < column1; j++)
			{
				result[i] += frist_matrix[g] * second_matrix[p];
				p = p + column2;
				g++;
			}
			fristP++;
	}*/
	
		for (row = 0; row < rows1*column1; row+=column1)
		{
			for (col = 0; col < column2; col++)
			{
				rowXcol(frist_matrix, second_matrix, rows1, rows2, column1, column2, row,
					col, result, i);
				i++;
			}
		}
		
	

		std::string result_string[1000];
		convert_my_matrix_to_string(result, result_string);
		std::cout << "[";
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < column2; j++)
			{
				std::cout << result[h];
				if (j < column2 - 1) { std::cout << " "; }
				h++;
			}
			if (i < (rows1 - 1)) { std::cout << ";"; }
		}
		std::cout << "]";
}



int main()
{
	std::string line_mat1;
	getline(std::cin, line_mat1);
	std::string elments1[1000];
	double frist_matrix[1000];
	parse(line_mat1, elments1);
	convert_my_matrix_to_double(elments1, frist_matrix);

	int rows1 = num_of_rows(line_mat1);
	int columns1 = num_of_columns(line_mat1);

	std::string operation;
	getline(std::cin, operation) ;

	std::string line_mat2;
	getline(std::cin, line_mat2);
	std::string elments2[1000];
	double second_matrix[1000];
	parse(line_mat2, elments2);
	convert_my_matrix_to_double(elments2, second_matrix);

	int rows2 = num_of_rows(line_mat2);
	int columns2 = num_of_columns(line_mat2);

	if (operation[0] == '+')
	{
		if ((rows1 != rows2) || columns1 != columns2)
		{
			std::cout << "ERROR";
			return 0;
		}
		double result[1000];
		add(frist_matrix, second_matrix, rows1, rows2, columns1, columns2, result);
	}

	if (operation[0] == '-')
	{
		if ((rows1 != rows2) || columns1 != columns2)
		{
			std::cout << "ERROR";
			return 0;
		}
		double result[1000];
		sub(frist_matrix, second_matrix, rows1, rows2, columns1, columns2, result);
	}

	if (operation[0] == '*')
	{
		if (columns1 != rows2 )
		{
			std::cout << "ERROR";
			return 0;
		}
		double result[1000];
		multiply(frist_matrix, second_matrix, rows1, rows2, columns1, columns2, result);
	}

	return 0;
}

