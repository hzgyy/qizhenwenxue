# types
## PointT

PointT是一个模板形参，具体可指代的就是具体点云点云的类型。
```
PointXYZ
PointXYZI
PointXYZRGBA
PointXYZRGB
PointXY
InterestPoint
Normal
PointNormal
PointXYZRGBNormal
PointXYZINormal
PointWithRange
PointWithViewpoint
MomentInvariants
PrincipalRadiiRSD
Boundary
PrincipalCurvatures
BounPFHSignature125dary
FPFHSignature33
VFHSignature308
Narf36
BorderDescription
IntensityGradient
Histogram
PointWithScale
PointSurfel
```

## Indices 指标
```c++
using pcl::IndicesConstPtr = typedef shared_ptr<const Indices>
using pcl::Indices = typedef IndicesAllocator<>
using pcl::IndicesAllocator = typedef std::vector<index_t, Allocator>
Default index_t = int for PCL 1.11, std::int32_t for PCL >= 1.12
```

## PointCloud
#include <pcl/point_cloud.h>

PointCloud represents the base class in PCL for storing collections of 3D points

https://pointclouds.org/documentation/classpcl_1_1_point_cloud.html

初始化：由于是模板类，在初始化时需要指定存储的类型。例如
`pcl::PointCloud<pcl::PointXYZ> cloud;`

几个成员变量：
- width std::uint32_t
    指明点云数据集的宽度，有两种含义
    - 在unorganized datasets中，width指明所有点的个数(等同于下面的POINTS)
    - 在organized datasets中,width指明一行中总共的点的个数。
- heights std::uint32_t
    指明点云数据集的高度，也有两种含义
    - 在unorganized datasets中，设置为1，因此可用于判断点云数据是否organized
    - 在organized datasets中,height指明所有点的行数
- points std::vector< PointT, Eigen::aligned_allocator< PointT > > 
    是一个data array，存储所有的类型为PointT的点云数据
- is_dense bool
    指明点中的数据是否是有限的（值为true），或者存在无限或者空数据Inf/NaN（值为false）
- sensor_origin Eigen::Vector4f
    指明传感器的acquisition pose (origin/translation)
- sensor_orientation_ Eigen::Quaternionf 
    指明传感器的acquisition pose (rotation).

看文档吧，太多了…………

## PointRepresentation
#include <pcl/point_representation.h>

用于把一个points的结构体/对象转化为一个n维向量。

## pcl_base
```cpp
pcl::PCLBase< PointT > 
```
应该是表示pcl里面存储点云容器的基类，相当重要！  
为实现各种功能，都会对应各个功能继承pcl_base去建立一个自己的类  
主要方法：  
```cpp
virtual void setInputCloud (const PointCloudConstPtr &cloud)
```
 	Provide a pointer to the input dataset.
```cpp
PointCloudConstPtr const 	getInputCloud () const
```
    Get a pointer to the input point cloud dataset.
```cpp
virtual void setIndices (const IndicesPtr &indices)
```
 	Provide a pointer to the vector of indices that represents the input data.
```cpp
IndicesPtr 	getIndices ()
```
    Get a pointer to the vector of indices used.

## model type
```cpp
   enum SacModel
   {
     SACMODEL_PLANE,
     SACMODEL_LINE,
     SACMODEL_CIRCLE2D,
     SACMODEL_CIRCLE3D,
     SACMODEL_SPHERE,
     SACMODEL_CYLINDER,
     SACMODEL_CONE,
     SACMODEL_TORUS,
     SACMODEL_PARALLEL_LINE,
     SACMODEL_PERPENDICULAR_PLANE,
     SACMODEL_PARALLEL_LINES,
     SACMODEL_NORMAL_PLANE,
     SACMODEL_NORMAL_SPHERE,
     SACMODEL_REGISTRATION,
     SACMODEL_REGISTRATION_2D,
     SACMODEL_PARALLEL_PLANE,
     SACMODEL_NORMAL_PARALLEL_PLANE,
     SACMODEL_STICK,
     SACMODEL_ELLIPSE3D
   };
```

## 条件 condition
基类：
```cpp
pcl::ConditionBase< PointT >
```
子类：
```cpp
pcl::ConditionAnd< PointT >
pcl::ConditionOr< PointT > 
```
主要方法：
```cpp
void pcl::ConditionBase< PointT >::addComparison(ComparisonBaseConstPtr comparison)	
```
Add a new comparison.
```cpp
void addCondition (Ptr condition)
```
Add a nested condition to this condition. 

## 比较 comparison
基类
```cpp
pcl::ComparisonBase< PointT >
```
具体方法在具体的子类中实现。
```cpp
pcl::FieldComparison< PointT >
```
继承于ComparisonBase，
构造器：
```cpp
FieldComparison (const std::string &field_name, ComparisonOps::CompareOp op, double compare_val)
```
Construct a FieldComparison.