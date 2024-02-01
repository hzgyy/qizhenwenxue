# kd-tree
## 基本概念
kd tree全称k-dimentional tree，也就是k维树，即每个点都是一个k维的向量。\\
kd tree一定是一个binary search tree。其每一层使用其中一维坐标为索引进行分类。一般来说就是设定该维的一个阈值，比他小就放到左子树，比他大就放到右子树，由此来构建一棵二分搜索树。说的数学一点就是，所有的元素都在一个k维向量空间中，每一层就是选定一个分割的超平面，把原来的向量空间及其中的点分开。\\
在用kdtree来处理点云时，明显点云是三维的，所以是个3d-tree。\\
用途：kdtree常用来搜索最近邻接点（k nearest neighbors）或者搜索在一定半径中的点。\\
## build kdtree
构建时候运用了类似于quick sort的方法，即不停的去找pivot，然后根据pivot把点放到两边。\\
在选取pivot时，为了保持构建出的bst是尽可能平衡的，我们采用median-find algorithm来选取合适的pivot,\\
实际用pcl时候不用管怎么构建的细节。\\
