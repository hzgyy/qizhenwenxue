# octree 八叉树
以八叉树形式存储点云数据。也就是按照空间进行二分，所以自然地形成了八叉树。
基础概念:
分割最后的最小单元--voxel
voxel的边长--resolution

## 具体的类和继承关系
太多了，根据需求找就行
### 两个基类
```cpp
class  	pcl::octree::OctreeBase< LeafContainerT, BranchContainerT >

class  	pcl::octree::Octree2BufBase< LeafContainerT, BranchContainerT >
```
第二个类很有意思，它同时在内存中建立了两棵树，在进行两个点云地图的比较时会非常有用。同时他还采取了一些内存处理的技巧，可以显著的减少allocate和deallocate的次数，从而加速。我怀疑就是lazy detele……
### 几个迭代器
octree迭代器的abstract class
```cpp
pcl::octree::OctreeIteratorBase< OctreeT >
```
具体类
```cpp
pcl::octree::OctreeDepthFirstIterator< OctreeT >
 
pcl::octree::OctreeBreadthFirstIterator< OctreeT >

pcl::octree::OctreeFixedDepthIterator< OctreeT >

pcl::octree::OctreeLeafNodeDepthFirstIterator< OctreeT >

pcl::octree::OctreeLeafNodeBreadthFirstIterator< OctreeT >
```
### 点云octree类
```cpp
pcl::octree::OctreePointCloud< PointT, LeafContainerT, BranchContainerT, OctreeT >
```
继承于OctreeBase
### 几个特殊地点云octree类
```cpp
class  	pcl::octree::OctreePointCloudPointVector< PointT, LeafContainerT, BranchContainerT, OctreeT >
```
每个叶子节点都保存这个voxel中的点的索引的列表。
This octree can hold a list of point indices at each leaf node.
```cpp
class  	pcl::octree::OctreePointCloudSinglePoint< PointT, LeafContainerT, BranchContainerT, OctreeT >
```
每个叶子节点只保存一个点，这个点是最近一个被分配到这个叶子结点的点。
```cpp
pcl::octree::OctreePointCloudOccupancy< PointT, LeafContainerT, BranchContainerT >
```
每个叶子节点不保存任何点的信息，但能够用于判断这个voxel空间中是否有点占用。
```cpp
class  	pcl::octree::OctreePointCloudDensity< PointT, LeafContainerT, BranchContainerT >
```
在每个叶子节点中保存这个voxel中所有点的个数，也就是density密度。可用于空间密度查询。
```cpp
class  	pcl::octree::OctreePointCloudVoxelCentroid< PointT, LeafContainerT, BranchContainerT >
```
每个叶子节点保存这个voxel中点的centroid重心。
### 点云搜索类
```cpp
pcl::octree::OctreePointCloudSearch< PointT, LeafContainerT, BranchContainerT >
```
继承于OctreePointCloud
### 差别比较类
```cpp
pcl::octree::OctreePointCloudChangeDetector< PointT, LeafContainerT, BranchContainerT >
```
### 

All octrees support serialization and deserialization of the octree structure and the octree data content.