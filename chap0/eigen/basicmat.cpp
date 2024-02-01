#include<iostream>
#include<ctime>
using namespace std;

#include<Eigen/Core>
#include<Eigen/Dense>

#define MATRIX_SIZE 50

int main(){
    //basic matrix types
    Eigen::Matrix<float,2,3> matrix_23;
    Eigen::Vector3d v_3d;
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
    Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_dynamic;
    Eigen::MatrixXd matrix_x;
    //IO
    matrix_23 << 1,2,3,4,5,6;
    v_3d << 3,2,1;
    matrix_33 = Eigen::Matrix3d::Random();
    cout << matrix_23 << endl;
    
    for(int i=0; i<2; i++){
        for(int j=0; j<3;j++)
            cout<<matrix_23(i,j);
        cout<<endl;
    }

    //矩阵相乘
    Eigen::Matrix<double,2,1> result = matrix_23.cast<double>() * v_3d;
    cout<<result<<endl;
    //维数出错的情况
    //Eigen::Matrix<double,2,3> error_dimention = matrix_23.cast<double>() * v_3d;
    //编译时就会报错YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES
    
    //矩阵运算
    cout<<"matrix 33"<<endl<<matrix_33<<endl;
    cout<<"transpose:"<<endl<<matrix_33.transpose()<<endl;
    cout<<"sum:"<<endl<<matrix_33.sum()<<endl;
    cout<<"Trace:"<<endl<<matrix_33.trace()<<endl;
    cout<<"10 times:"<<endl<<matrix_33*10<<endl;
    cout<<"Inverse:"<<endl<<matrix_33.inverse()<<endl;
    cout<<"Determinant:"<<endl<<matrix_33.determinant()<<endl;

    //特征值
    //先生成一个实对称矩阵
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose()*matrix_33);
    cout<<"eigen values = "<<endl<< eigen_solver.eigenvalues() << endl;
    cout<<"eigen vectors = "<<endl<<eigen_solver.eigenvectors()<<endl;

    //解方程,求解matrix_NN * X = v_Nd这个方程
    Eigen::Matrix<double,MATRIX_SIZE,MATRIX_SIZE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);
    Eigen::Matrix<double,MATRIX_SIZE,1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE,1);
    //直接求解
    Eigen::Matrix<double,MATRIX_SIZE,1> x = matrix_NN.inverse()*v_Nd;
    cout << "直接求解："<<endl<<x<<endl;
    //矩阵分解求解
    Eigen::Matrix<double,MATRIX_SIZE,1> x2= matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout<<"矩阵分解求解"<<endl<<x2<<endl;
    return 0;
}

