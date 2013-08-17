#include <stdlib.h>

#include "matrix.h"

Matrix make_matrix(){
  Matrix result = (Matrix) malloc(4*sizeof(Row));

  for(int i=0; i<4; i++){
    result[i] = (Row) malloc(4*sizeof(double));
  }
  return result;
}

Matrix copy_matrix(Matrix original){
  Matrix result = make_matrix();

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      result[i][j] = original[i][j];
    }
  }
  return result;
}

void delete_matrix(Matrix matrix){
  for(int i=0; i<4; i++){
    free(matrix[i]);
  }
  free(matrix);
}

Matrix multiply(Matrix first, Matrix second){
  Matrix result = make_matrix();

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      result[i][j] = calculate_cell(first, second, i, j);
    }
  }
  return result;
}

//Calculates the value of a single cell when multiplying matrices.
double calculate_cell(Matrix first, Matrix second, int row, int column){
  double sum = 0;
  for(int i=0; i<4; i++){
    sum += first[row][i] * second[i][column];
  }
  return sum;
}

Matrix add(Matrix first, Matrix second){
  Matrix result;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      result[i][j] = first[i][j] + second[i][j];
    }
  }
  return result;
}

void zero_matrix(Matrix matrix){
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      matrix[i][j] = 0;
    }
  }
}

Matrix make_identity(){
  Matrix matrix = make_matrix();
  zero_matrix(matrix);
  for(int i=0; i<4; i++){
    matrix[i][i] = 1;
  }
  return matrix;
}

//Transforms the standard format matrix into a flat 16 element array.
float* make_flat(Matrix matrix){
  float* flat_matrix = (float*)malloc(sizeof(float)*16);
  
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      flat_matrix[i*4 + j] = matrix[i][j];
    }
  }
  return flat_matrix;
}
