

  ## DESCRIPTION

  ### FISHEYE DISTORTION REMOVAL IN C++ 

&emsp;&emsp;&emsp; Step wise instruction to calibrate the camera and use it remove distortion from images or videos are as follows :

#### 1 &emsp; CAMERA CALIBRATION

<br />

#### - &emsp; Go in the camera_calibration directory which contains 2 files, .cpp file & config.yml file. 

        > g++ camera_calibration.cpp -o output `pkg-config --cflags --libs opencv` 

#### - &emsp; After the .cpp file is compiled succesfully. it'll create a calibrate_camera_config.yml, which we'll be needing to undistort the camera in further process of undistortion.

#### - &emsp; Copy the calibrated_camera_config.yml in undistort_images or undistort_videos directory as per the need.

<br />

#### 2 &emsp; UNDISTORT IMAGES
&emsp;&emsp;&emsp; Execute the following commands in order to undistort the images & save the undistorted ones in the same directory as distorted ones.

&emsp;&emsp;&emsp; Before executing the commands, verify that you have the path of all the images you want to undistort in image_list.xml file in src directory.

	> mkdir build
	> cd build
	> cmake ..
	> make
	> cd ../src/
	> g++ main.cpp undistort.cpp -o output `pkg-config --cflags --libs opencv`
	> ./output calibrated_camera_config.yml image_list.xml

&emsp;&emsp;&emsp; Undistorted Images will be in the same directory as distorted ones.

<br />

#### 3 &emsp; UNDISTORT VIDEOS
&emsp;&emsp;&emsp; Execute the following commands in order to have an undistorted video stream.

	> mkdir build
	> cd build
	> cmake ..
	> make
	> cd ../src/
	> g++ main.cpp -o output `pkg-config --cflags --libs opencv`
	> ./output calibrated_camera_config.yml


