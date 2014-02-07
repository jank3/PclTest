// pcl_test.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

#include <pcl/io/pxc_grabber.h>
#include <pcl/visualization/cloud_viewer.h>

void grabberCallback(pcl::visualization::CloudViewer &viewer, const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr &cloud)
{
    if (!viewer.wasStopped())
        viewer.showCloud(cloud);
}

int _tmain(int argc, _TCHAR* argv[])
{
    pcl::visualization::CloudViewer viewer("Senz3D Viewer");
    pcl::PXCGrabber grabber;

    boost::function<void (const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr&)> f = boost::bind(&grabberCallback, boost::ref(viewer), _1);
    grabber.registerCallback(f);
    grabber.start();

    while(!viewer.wasStopped())
        Sleep(100);

    grabber.stop();
	return 0;
}

