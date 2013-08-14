typedef double* Row;
typedef Row* Matrix;

//Matrix memory allocation/freeing function.
//  i.e., constructor, copiers, and destructors.
Matrix make_matrix();
Matrix copy_matrix(Matrix original);
void delete_matrix(Matrix matrix);

//Basic matrix arithmetic.
Matrix multiply(Matrix first, Matrix second);
Matrix add(Matrix first, Matrix second);

//Helper functions.
double calculate_cell(Matrix first, Matrix second, int row, int column);

