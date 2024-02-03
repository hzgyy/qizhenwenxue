# kd-tree
## 基本概念
kd tree全称k-dimentional tree，也就是k维树，即每个点都是一个k维的向量。

kd tree一定是一个binary search tree。其每一层使用其中一维坐标为索引进行分类。一般来说就是设定该维的一个阈值，比他小就放到左子树，比他大就放到右子树，由此来构建一棵二分搜索树。说的数学一点就是，所有的元素都在一个k维向量空间中，每一层就是选定一个分割的超平面，把原来的向量空间及其中的点分开。

在用kdtree来处理点云时，明显点云是三维的，所以是个3d-tree。

用途：kdtree常用来搜索最近邻接点（k nearest neighbors）或者搜索在一定半径中的点。

## build kdtree
构建时候运用了类似于quick sort的方法，即不停的去找pivot，然后根据pivot把点放到两边。

在选取pivot时，为了保持构建出的bst是尽可能平衡的，我们采用median-find algorithm来选取合适的pivot,

显然这个算法是$O(N)$的。

## K nearest Search
目的是检索在k-d树中与查询点距离最近的数据点。

算法详见：https://mkdoc-material.llango.com/getting-started/

总结：
我们得到一棵kdtree，输入查询点p，输入需要得到的点的个数k。

1. 首先根据每一层的指标和查询点的该指标比较，往左子树或者右子树走。直至走到叶子节点，并标记为已访问。
2. 将叶子节点加入结果的列表。
3. 往上回溯，如果列表未满或者距离小于现有结果中点的最大距离，就更新结果节点，并记录已访问。
4. 当一侧子树已全部访问过时。比较p和分割线之间的距离和目前结果中该指标的最大距离。
    - 若p和分割线之间的距离小于目前结果中该指标的最大距离，说明在另一侧子树中仍有可能存在点的距离比现有结果中的更小，所以在另一侧子树中调用1-3步。
    - p和分割线之间的距离大于目前结果中该指标的最大距离，说明在另一侧子树中仍有可能存在点的距离比现有结果中的更大，继续往上回溯。
5. 直到回溯到根节点，且检查过两侧子树或者另一侧子树不满足条件，算法终止。

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
输入：
```cpp
void pcl::KdTreeFLANN< PointT, Dist >::setInputCloud	(	const PointCloudConstPtr & 	cloud,
const IndicesConstPtr & 	indices = IndicesConstPtr() )	
```
Provide a pointer to the input dataset.把点云数据的指针提供给KdTreeFLANN类
参数：
- cloud	the const boost shared pointer to a PointCloud message
- indices	the point indices subset that is to be used from cloud - if NULL the whole cloud is used

输出
```cpp
PointCloudConstPtr pcl::KdTree< PointT >::getInputCloud	()	const
```
Get a pointer to the input point cloud dataset.

### KNN Search
```cpp
int pcl::KdTreeFLANN< PointT, Dist >::nearestKSearch	(	const PointT & 	point,
unsigned int 	k,
Indices & 	k_indices,
std::vector< float > & 	k_sqr_distances 
)	const
```

### Radius Search
```cpp
int pcl::KdTreeFLANN< PointT, Dist >::radiusSearch	(	const PointT & 	point,
double 	radius,
Indices & 	k_indices,
std::vector< float > & 	k_sqr_distances,
unsigned int 	max_nn = 0 
)	const
```