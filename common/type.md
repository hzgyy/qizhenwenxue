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
