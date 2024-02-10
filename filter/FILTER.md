# filter
用于给点云滤波

## 基类
Filter<Point T> 继承于 PCLBase<Point T>
Filter类重要的方法：  
```cpp
void filter (PointCloud &output)
```
Calls the filtering method and returns the filtered dataset in output.相当于执行

FilterIndices<Point T> 继承于 Filter<Point T>  
用于filter处理indices的情况。
FilterIndices类重要的方法：
```cpp
void setNegative (bool negative)
```
Set whether the regular conditions for points filtering should apply, or the inverted conditions
```cpp
void filter (Indices &indices)
```
Calls the filtering method and returns the filtered point cloud indices.

具体的滤波器对象都继承于这两个类，具体见：
https://pointclouds.org/documentation/group__filters.html



## 直通滤波器 passthrough
就是单纯的按照某一维的数值的范围筛选。
pcl::PassThrough< PointT >

## voxelgrid filter
用于down-sampling（下采样），也就是在保留原点云数据特征的前提下，减少点的个数。
voxelgrid是一种down-sampling的方法，其具体是类似于octree建立voxels，在每一个voxel中取内部点的重心，以替代voxel里面其他所有点，从而实现点的减少。
pcl::VoxelGrid< PointT > 

## StatisticalOutlierRemoval filter
用于去除外点(outliers)，其思路很简单：
计算所求点到其n个邻点距离的分布，我们假定对于所有点，这一分布是高斯分布，我们可以计算出这一分布的均值和标准差。我们会设定一个允许的范围，往往是均值旁边超出这个范围的点就被认为是外点。  
关于这个范围如何定，pcl设定了一个参数stddev_mult(standard deviation multiplier,标准差增益)。最终的距离n个邻点平均距离的判断阈值为：mean+stddev_mult*stddev,只要大于这个阈值，就认定这个点为外点。

## extractindices filter
可以从点云中把一系列indices提取出来。
pcl::ExtractIndices< PointT >
操作可以用自带的函数：
```cpp
void pcl::ExtractIndices< PointT >::applyFilter	(	Indices & 	indices	)
void pcl::ExtractIndices< PointT >::applyFilter	(	PointCloud & 	output	)	
```
也可以去调用其基类的输出结果的函数：
```cpp
void filter (Indices &indices)
void filter (PointCloud &output)
```

## RadiusOutlierRemoval
是一种根据条件筛选点的方法。具体就是以每个点为圆心画某一设定半径的圆，数圆内有几个邻点。设定一个阈值，圆内邻点少于这个阈值的点被认为是外点，筛除。
```cpp
pcl::RadiusOutlierRemoval< PointT >
```

## ConditionalRemoval
可以认为设定一些条件来筛选点。
pcl::ConditionalRemoval< PointT > 重要方法如下：  
```cpp
void pcl::ConditionalRemoval< PointT >::setCondition(ConditionBasePtr condition)	
```

