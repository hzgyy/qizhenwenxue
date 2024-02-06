# sample_consensus 采样一致性算法
该算法用来从一系列包含内点(inliers)和外点(outliers)的数据中，把所需的几何体分割出来。
思路：
1. 设定参数，包括
    - n 最大迭代此时
    - t 数据和模型匹配程度的阈值
    - d 表示模型合适的最小数据组数
2. 开始迭代，随机选取一组数据data1，根据这一组数据计算出拟合的模型的参数a1。
3. 计算除data1外的其他点和参数的符合程度,把符合要求的当作内点，存在data2中。
4. 遍历完所有点，若data2中的数据个数多于阈值d，则认为这组模型是有效的。把data2加入data1，重新计算模型参数。
5. 计算新模型参数对于inliers的error，与目前最佳比较，若更好就替换。
优点：
1. 可以排除一些坏点，弥补了最小二乘的缺点。
缺点：
1. 算法的复杂度高。
2. 且算法效果难以保证，迭代越多越好。

还有很多estimator：
- SAC_RANSAC - RANdom SAmple Consensus
- SAC_LMEDS - Least Median of Squares
- SAC_MSAC - M-Estimator SAmple Consensus
- SAC_RRANSAC - Randomized RANSAC
- SAC_RMSAC - Randomized MSAC
- SAC_MLESAC - Maximum LikeLihood Estimation SAmple Consensus
- SAC_PROSAC - PROgressive SAmple Consensus

## 用法：
### 基类 sample_consensus
build:
```cpp
pcl::SampleConsensus< T >::SampleConsensus	(	const SampleConsensusModelPtr & 	model,
bool 	random = false)	
```
函数：
https://pointclouds.org/documentation/classpcl_1_1_sample_consensus.html

### 实例RandomSampleConsensus
build:
```cpp
pcl::RandomSampleConsensus< PointT >::RandomSampleConsensus	(const SampleConsensusModelPtr & model)	

pcl::RandomSampleConsensus< PointT >::RandomSampleConsensus	(const SampleConsensusModelPtr & model,double threshold )	
```
计算参数：
```cpp
bool pcl::RandomSampleConsensus< PointT >::computeModel	(int debug_verbosity_level = 0)	
```

