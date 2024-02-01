#include<iostream>
#include<cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

int main(){
    //3D旋转矩阵
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    Eigen::AngleAxisd rotation_vector (M_PI/4, Eigen::Vector3d(0,1,1));
    cout .precision(3);
    cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << rotation_matrix << endl;
    Eigen::Vector3d v (1,0,0);
    //轴角量可以乘向量来表示旋转
    Eigen::Vector3d v_rotated = rotation_vector*v;
    cout << "(1,0,0) after rotation" << v_rotated.transpose() << endl;
    v_rotated = rotation_matrix * v;
    cout<<"use rotation matrix" << v_rotated.transpose() << endl;

    //旋转矩阵转换为欧拉角
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0);
    cout<<"yaw pich row = " << euler_angles.transpose()<<endl;

    //包含平移的变换
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate (rotation_vector);
    T.pretranslate (Eigen::Vector3d(0,0,0));
    cout << "Transform matrix = \n" << T.matrix() << endl;
    Eigen::Vector3d v_transformed = T*v;
    cout<<"v transformed = " << v_transformed.transpose() << endl;

    //四元数
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    //cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
    cout<<"quantarnion = \n"<<q.coeffs()<<endl;
    q = Eigen::Quaterniond(rotation_matrix);
    cout<<"rotation mat = \n"<<rotation_matrix<<endl; 
    cout<<"quantarnion2 = \n"<<q.coeffs()<<endl;
    Eigen::Matrix3d back (q);
    cout<<"back = \n"<< back<<endl;
    v_rotated = q*v;
    cout<<"after"<<(back*v).transpose()<<endl;
    cout<<"after rotation use quanternion = "<< v_rotated.transpose()<< endl;

    return 0;
}