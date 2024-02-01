#include<pcl/common/centroid.h>
#include<pcl/point_cloud.h>
#include<pcl/console/parse.h>
#include<pcl/io/pcd_io.h>
#include<pcl/io/ply_io.h>
#include<iostream>
using namespace std;

int main(int argc, char** argv){
	pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
	vector<int> files = pcl::console::parse_file_extension_argument (argc, argv, ".ply");
	if(files.size() != 0){
		if(pcl::io::loadPLYFile (argv[1], *source_cloud) < 0){
			cout<<"input error"<<endl;
		}
	}else{
		if(pcl::io::loadPCDFile (argv[1], *source_cloud) < 0){
			cout<<"input error"<<endl;
		}
	}	
    // Create and accumulate points
    pcl::CentroidPoint<pcl::PointXYZ> centroid;
    //centroid.add (pcl::PointXYZ (1, 2, 3));
    //centroid.add (pcl::PointXYZ (5, 6, 7));
	auto it_end = (*source_cloud).end();
	for(auto it=(*source_cloud).begin();it != it_end; ++it){
		centroid.add(*it);
	}
    // Fetch centroid using `get()`
    pcl::PointXYZ c1;
    centroid.get (c1);
    cout<<"center1:"<<c1<<endl;
    // The expected result is: c1.x == 3, c1.y == 4, c1.z == 5
    // It is also okay to use `get()` with a different point type
    pcl::PointXYZRGB c2;
    centroid.get (c2);
    cout<<"center2:"<<c2<<endl;
    // The expected result is: c2.x == 3, c2.y == 4, c2.z == 5,
    // and c2.rgb is left untouched
}
