# qizhenwenxue
数据集：
ETHACL：https://projects.asl.ethz.ch/datasets/doku.php?id=home

建议检查pcl和vtk版本

检查pcl版本：运行chap0/version里面的cmake

检查vtk版本：暴力点就到/usr/下sudo find | grep "VTK"

如果是pcl1.12 和 vtk 9.1，这两个版本之间不兼容，无法可视化，需要重装更高版本pcl。如果是别的版本应该不会有太多bug。


