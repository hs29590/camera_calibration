#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#ifndef _UNDISTORT_HPP
#define _UNDISTORT_HPP
#include <iostream>
#include <cstdlib>

using namespace cv;
using namespace std;

class UndistortImages{
    public:
        // Camera parameters
        cv::Mat cameraMatrix;
        cv::Mat distCoeffs;
        std::vector<std::string> inputImagesPaths;

        void readCameraParameters( char* );
        void loadImages( char* );
        void undistortImages();
};

#endif

void printHelp(char* programName){
    cout << " Correct usage: " << programName << " camera.yml" << " images_paths.xml "<< endl;
    cout << " camera.yml = file with camera matrix and distortion coefficients. " << endl;
    cout << " images_paths.xml = file with path to images that should be undistorted." << endl;
    exit(EXIT_FAILURE);
}

// Read a YAML file with the camera parameters (cameraMatrix and distCoeffs)
void UndistortImages::readCameraParameters( char* yml_filename ){
    FileStorage fs;
    fs.open(yml_filename, FileStorage::READ);
    if( !fs.isOpened() ){
        cerr << " Fail to open " << yml_filename << endl;
        exit(EXIT_FAILURE);
    }

    // Get camera parameters
    fs["camera_matrix"] >> cameraMatrix;
    fs["distortion_coefficients"] >> distCoeffs;

    // Print out the camera parameters
    cout << "\n -- Camera parameters -- " << endl;
    cout << "\n CameraMatrix = " << endl << " " << cameraMatrix << endl << endl;
    cout << " Distortion coefficients = " << endl << " " << distCoeffs << endl << endl;

    fs.release();
}

int main(int argc, char** argv){

    UndistortImages undistortImages;
    undistortImages.readCameraParameters( argv[1] );
    
    VideoCapture cap(0);
    while (1)
    {
	Mat frame, outputImage;
	cap >> frame;
    	
        cout<<"Size of the frame : "<<frame.size()<<endl; 
	undistort(frame, outputImage, undistortImages.cameraMatrix, undistortImages.distCoeffs);
	
	cout<<"Printinf the Image Now!!!";	
	imshow("Display", outputImage);
	waitKey(30);
    }

    return 0;
}
