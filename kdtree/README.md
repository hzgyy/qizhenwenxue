# kd-tree
## 基本概念
kd tree全称k-dimentional tree，也就是k维树，即每个点都是一个k维的向量。

kd tree一定是一个binary search tree。其每一层使用其中一维坐标为索引进行分类。一般来说就是设定该维的一个阈值，比他小就放到左子树，比他大就放到右子树，由此来构建一棵二分搜索树。说的数学一点就是，所有的元素都在一个k维向量空间中，每一层就是选定一个分割的超平面，把原来的向量空间及其中的点分开。

在用kdtree来处理点云时，明显点云是三维的，所以是个3d-tree。

用途：kdtree常用来搜索最近邻接点（k nearest neighbors）或者搜索在一定半径中的点。

## build kdtree
构建时候运用了类似于quick sort的方法，即不停的去找pivot，然后根据pivot把点放到两边。

在选取pivot时，为了保持构建出的bst是尽可能平衡的，我们采用median-find algorithm来选取合适的pivot,

实际用pcl时候不用管怎么构建的细节。

## K nearest Search
目的是检索在k-d树中与查询点距离最近的数据点。



## kdtree class template
pcl::KdTree< PointT >     #include <pcl/kdtree/kdtree.h>

pcl::KdTreeFLANN< PointT, Dist >    #include <pcl/kdtree/kdtree_flann.h>

FLANN的类继承于前者，FLANN--Fast Library for Approximate Nearest Neighbor，是一个第三方库，能够快速处理kdtree相关的任务，所以类内有些接口和前者会不一样。这里只说明这个类，一般也用这个类。
### 类内重命名
KdTree类的：
```cpp
using 	IndicesPtr = shared_ptr< Indices >
using 	IndicesConstPtr = shared_ptr< const Indices >
using 	PointCloud = pcl::PointCloud< PointT >
using 	PointCloudPtr = typename PointCloud::Ptr
using 	PointCloudConstPtr = typename PointCloud::ConstPtr
using 	PointRepresentation = pcl::PointRepresentation< PointT >
using 	PointRepresentationConstPtr = typename PointRepresentation::ConstPtr
using 	Ptr = shared_ptr< KdTree< PointT > >
using 	ConstPtr = shared_ptr< const KdTree< PointT > >
```
KdTreeFLANN类的
```cpp
using 	FLANNIndex = ::flann::Index< Dist >
using 	Ptr = shared_ptr< KdTreeFLANN< PointT, Dist > >
using 	ConstPtr = shared_ptr< const KdTreeFLANN< PointT, Dist > >
```

### build
`pcl::KdTreeFLANN< PointT, Dist >::KdTreeFLANN	(	bool 	sorted = true	)`
Default Constructor for KdTreeFLANN.


`pcl::KdTreeFLANN< PointT, Dist >::KdTreeFLANN	(	const KdTreeFLANN< PointT, Dist > & 	k	)`
Copy constructor.
### IO
```cpp
void pcl::KdTreeFLANN< PointT, Dist >::setInputCloud	(	const PointCloudConstPtr & 	cloud,
const IndicesConstPtr & 	indices = IndicesConstPtr() )	
```
Provide a pointer to the input dataset.把点云数据的指针提供给KdTreeFLANN类
参数：
- cloud	the const boost shared pointer to a PointCloud message
- indices	the point indices subset that is to be used from cloud - if NULL the whole cloud is used

先不写了，好像文档写的挺清楚的。
