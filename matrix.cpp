#include <limits>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <fstream>




using namespace std;

int taille = 10;

class dataM{
private:



public:
	double resfloat[7][7];
	double resBigfloat[7][7];

	dataM(){
	resfloat[0][0] = 100;
	resfloat[0][1] = 200;
	resfloat[0][2] = 400;
	resfloat[0][3] = 500;
	resfloat[0][4] = 800;
	resfloat[0][5] = 1000;
	resfloat[0][6] = 2000;

	resBigfloat[0][0] = 100;
	resBigfloat[0][1] = 200;
	resBigfloat[0][2] = 400;
	resBigfloat[0][3] = 500;
	resBigfloat[0][4] = 800;
	resBigfloat[0][5] = 1000;
	resBigfloat[0][6] = 2000;
	}

	

	void viewFloat(){
		for (int i = 0;i<7;i++){
			printf("     %d      |",(int)resfloat[0][i]);
		}
		cout << "\n\n";
		for (int i = 1;i<7;i++){
			for (int j = 0 ; j< 7;j++){
				printf("   %f   |",resfloat[i][j]);
			}
			cout << "\n\n";
		}
	}

	void viewBigFloat(){
		for (int i = 0;i<7;i++){
			printf("     %d      |",(int)resBigfloat[0][i]);
		}
		cout << "\n\n";
		for (int i = 1;i<7;i++){
			for (int j = 0 ; j< 7;j++){
				printf("   %f   |",resBigfloat[i][j]);
			}
			cout << "\n\n";
		}
	}

	string toString(){
		string resu = "float\n\n";
		for (int i = 0;i<7;i++){
			resu = resu + "     " + to_string((int)resfloat[0][i]) + "      |";
		}
		resu = resu + "\n\n";
		for (int i = 1;i<7;i++){
			for (int j = 0 ; j< 7;j++){	
				resu = resu + "   " + to_string(resfloat[i][j]) + "   |";
			}
			resu = resu + "\n\n";
		}
		return resu;

	}

	string toStringB(){
		string resu = "long double\n\n";
		for (int i = 0;i<7;i++){
			resu = resu + "     " + to_string((int)resBigfloat[0][i]) + "      |";
		}
		resu = resu + "\n\n";
		for (int i = 1;i<7;i++){
			for (int j = 0 ; j< 7;j++){	
				resu = resu + "   " + to_string(resBigfloat[i][j]) + "   |";
			}
			resu = resu + "\n\n";
		}
		return resu;

	}

	string resTot(){
		return(toString() + toStringB());
	}


};

class matrix{
private:
	
	float MAX;
	long double UPPER_MAX;	
public:
	matrix(float max = 10000, long double DMAX = 1000000000){
	
	this->MAX = max;
	this->UPPER_MAX = DMAX;
	}

//section for creating and filling matrixes with random numbers
	float** createMatrix(){
		float** matrix = 0;
		matrix = new float*[taille];
		for (int i = 0;i<taille;i++){
			matrix[i] = new float[taille];
		}
		fillMatrix(matrix);
		return matrix;
	}


	long double** createBigMatrix(){
		long double** matrix = 0;
		matrix = new long double*[taille];
		for (int i = 0; i < taille ; i++ )
			matrix[i] = new long double[taille];
			fillMatrix(matrix);
		return matrix;
	}

	void CarveMatrix(float** mat){
		for (int i = 0;i < taille ;i++)
			for (int j = 0 ;j<taille;j++)
				mat[i][j] = 0;
	}

	void CarveMatrix(long double** mat){
		for (int i = 0;i < taille ; i++)
			for (int j = 0 ; j< taille;j++)
				mat[i][j] = 0;
	}

	void fillMatrix(float** mat){
		
		for(int i = 0;i<taille;i++)
			for (int j = 0;j<taille;j++){
				mat[i][j] = float(rand())/float((RAND_MAX)) * MAX;
			}
		
	}


	void fillMatrix(long double** mat){
		for (int i = 0 ;i<taille;i++)
			for (int j = 0 ; j < taille; j++)
				mat[i][j] = (long double)(rand())/(long double)((RAND_MAX)) * UPPER_MAX;
	}
	
/*************************************************************************************************************/
	void viewMatrix(float** mat){
		for (int i = 0;i < taille;i++){
			for (int j = 0;j<taille;j++){
				cout << mat[i][j] <<" ";
			}
			cout << "\n";
		}
	}
	
/*			section for adding and multiplying matrixes					*/
//two functions below are for adding matrixs
	void addMatrixIJ(float** mat1,float** mat2){
		float** mat = createMatrix();
		for (int i = 0 ; i < taille ; i++){
			for (int j = 0 ; j < taille ; j++){
				mat[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
		
	}

	void addMatrixIJ(long double** mat1,long double** mat2){
		long double** mat = createBigMatrix();
		for (int i = 0 ; i < taille ; i++){
			for (int j = 0 ; j < taille ; j++){
				mat[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
		
	}

	void addMatrixJI(float** mat1,float** mat2){
		float** mat = createMatrix();
		for (int i = 0; i < taille ; i++){
			for (int j = 0; j < taille ; j++){
				mat[j][i]= mat1[j][i] + mat2[j][i]; 
			}
		}
		
	}

	void addMatrixJI(long double** mat1,long double** mat2){
		long double** mat = createBigMatrix();
		for (int i = 0; i < taille ; i++){
			for (int j = 0; j < taille ; j++){
				mat[j][i]= mat1[j][i] + mat2[j][i]; 
			}
		}
		
	}  	

//nine function below are 9 different versions of matrix multiplcation
	void prodMatixIJK(float** mat1,float** mat2){
		float** mat = createMatrix();
		CarveMatrix(mat);
		for (int i = 0;i<taille;i++){
			for (int j = 0;j<taille;j++){
				for (int k = 0;k<taille;k++){
					mat[i][j] = mat[i][j] + (mat1[i][k]*mat2[k][j]);	
				}
			}
		}
		
		
	}

	void prodMatixJIK(float** mat1,float** mat2){
                  float** mat = createMatrix();
                  CarveMatrix(mat);
                  for (int j = 0;j < taille;j++){
                          for (int i = 0; i < taille; i++){
                                  for (int k = 0; k < taille;k++){
                                          mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                  }
                          }
                  }
                  
         }

	void prodMatixIKJ(float** mat1,float** mat2){
                  float** mat = createMatrix();
                  CarveMatrix(mat);
                  for (int i = 0; i < taille; i++){
                          for (int k = 0; k < taille ; k++){
                                  for (int j = 0 ; j < taille ; j++){
                                          mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                  }
                          }
                  }
                  
          }

	void prodMatixJKI(float** mat1,float** mat2){
                    float** mat = createMatrix();
                    CarveMatrix(mat);
                    for (int j = 0; j < taille; j++){
                            for (int k = 0; k < taille ; k++){
                                    for (int i = 0 ; i < taille ; i++){
                                            mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                    }
                            }
                    }
					
                    
            }

	void prodMatixKIJ(float** mat1,float** mat2){
                    float** mat = createMatrix();
                    CarveMatrix(mat);
					
                    for (int k = 0; k < taille; k++){
                            for (int i = 0; i < taille ; i++){
                                    for (int j = 0 ; j < taille ; j++){
                                            mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                    }
                            }
                    }
					
                    
            }

	void prodMatixKJI(float** mat1,float** mat2){
                    float** mat = createMatrix();
                    CarveMatrix(mat);
                    for (int k = 0; k < taille; k++){
                            for (int j = 0; j < taille ; j++){
                                    for (int i = 0 ; i < taille ; i++){
                                            mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                    }
                            }
                    }
                    
            }

			//big float territory

	void prodMatixIJK(long double** mat1,long double** mat2){
		long double** mat = createBigMatrix();
		CarveMatrix(mat);
		for (int i = 0;i<taille;i++){
			for (int j = 0;j<taille;j++){
				for (int k = 0;k<taille;k++){
					mat[i][j] = mat[i][j] + (mat1[i][k]*mat2[k][j]);	
				}
			}
		}
		
	}

	void prodMatixJIK(long double** mat1,long double** mat2){
                  long double** mat = createBigMatrix();
                  CarveMatrix(mat);
                  for (int j = 0;j < taille;j++){
                          for (int i = 0; i < taille; i++){
                                  for (int k = 0; k < taille;k++){
                                          mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                  }
                          }
                  }
                  
         }

	void prodMatixIKJ(long double** mat1,long double** mat2){
                  long double** mat = createBigMatrix();
                  CarveMatrix(mat);
                  for (int i = 0; i < taille; i++){
                          for (int k = 0; k < taille ; k++){
                                  for (int j = 0 ; j < taille ; j++){
                                          mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                  }
                          }
                  }
                  
          }

	void prodMatixJKI(long double** mat1,long double** mat2){
                    long double** mat = createBigMatrix();
                    CarveMatrix(mat);
                    for (int j = 0; j < taille; j++){
                            for (int k = 0; k < taille ; k++){
                                    for (int i = 0 ; i < taille ; i++){
                                            mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                    }
                            }
                    }
                    
            }

	void prodMatixKIJ(long double** mat1,long double** mat2){
                    long double** mat = createBigMatrix();
                    CarveMatrix(mat);
                    for (int k = 0; k < taille; k++){
                            for (int i = 0; i < taille ; i++){
                                    for (int j = 0 ; j < taille ; j++){
                                            mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                    }
                            }
                    }
                    
            }

	void prodMatixKJI(long double** mat1,long double** mat2){
                    long double** mat = createBigMatrix();
                    CarveMatrix(mat);
                    for (int k = 0; k < taille; k++){
                            for (int j = 0; j < taille ; j++){
                                    for (int i = 0 ; i < taille ; i++){
                                            mat[k][i] = mat[k][i] + (mat1[k][j]*mat2[j][i]);
                                    }
                            }
                    }
                    
            }




//the function below is to make the transposing form of a matrix or whatever the hell it's called
	float** transMat(float** mat){
		float** res = createMatrix();
		for (int i = 0;i<taille;i++){
			for (int j = 0;j<taille;j++){
			res[i][j] = mat[j][i];
			}
		}
		return res;
	}

};



int main(){
ofstream outs;
void v(float**);
void v(long double**);

clock_t t;
dataM addmatrix;
srand((unsigned int)time(NULL));
matrix p;





for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.addMatrixIJ(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.addMatrixIJ(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}



outs.open("IJ.txt");
outs << addmatrix.resTot();
outs.close();

for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.addMatrixJI(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.addMatrixJI(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("JI.txt");
outs << addmatrix.resTot();
outs.close();


addmatrix.resfloat[0][6]=1;
addmatrix.resBigfloat[0][6]=1;
/*********************************************************************************************************************************************************
 * *******************************************************************************************************************************************************
 * *******************************************************************************************************************************************************
 * *******************************************************************************************************************************************************/
for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.prodMatixIJK(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.prodMatixIJK(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("IJK.txt");
outs << addmatrix.resTot();
outs.close();

for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.prodMatixJIK(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.prodMatixJIK(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("JIK.txt");
outs << addmatrix.resTot();
outs.close();

for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.prodMatixIKJ(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.prodMatixIKJ(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("IKJ.txt");
outs << addmatrix.resTot();
outs.close();

for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.prodMatixJKI(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.prodMatixJKI(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("JKI.txt");
outs << addmatrix.resTot();
outs.close();

for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.prodMatixKIJ(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.prodMatixKIJ(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("KIJ.txt");
outs << addmatrix.resTot();
outs.close();

for (int i = 0; i < 7;i++){
	double time_taken_Add1 = 0;
	double time_taken_Add2 = 0;
	taille = addmatrix.resfloat[0][i];
	for (int j = 1; j < 6; j++){
	float** tab1 = p.createMatrix();
	float** tab2 = p.createMatrix();
	long double** tab3 = p.createBigMatrix();
	long double** tab4 = p.createBigMatrix();
	t = clock();
	p.prodMatixKJI(tab1,tab2);
	t = clock() - t;
	time_taken_Add1 = time_taken_Add1 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);

	t = clock();
	p.prodMatixKJI(tab3,tab4);
	t = clock() - t;
	time_taken_Add2 = time_taken_Add2 + (((double)t)/CLOCKS_PER_SEC);
	addmatrix.resBigfloat[j][i] = (((double)t)/CLOCKS_PER_SEC);
	}
	addmatrix.resfloat[6][i] = time_taken_Add1 / 5;
	addmatrix.resBigfloat[6][i] = time_taken_Add2 / 5;
}

outs.open("KJI.txt");
outs << addmatrix.resTot();
outs.close();


}





void v(float** m){
	for (int i = 0; i<taille;i++){
		for(int j = 0; j<taille;j++){
			cout << m[i][j] << "   ";
		}
		cout << "\n\n";
	}
}

void v(long double** m){
	for (int i = 0; i<taille;i++){
		for(int j = 0; j<taille;j++){
			cout << m[i][j] << "   ";
		}
		cout << "\n\n";
	}
}
