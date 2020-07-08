 ### FISHEYE DISTORTION REMOVAL IN PYTHON

&emsp;&emsp;&emsp; Step wise instruction to calibrate the camera and use it remove distortion from images or videos are as follows :


#### 1 &emsp; IMAGE CAPTURE FOR CALIBRATION
&emsp;&emsp;&emsp; Execute the capture_images.py script and press SPACE key to save the image of chessboard for calibration.

&emsp;&emsp;&emsp; TAKE ATLEAST 25 images of chessboard in every angle and direction for optimal calibration.

	> python3 capture_images.py
 
####2 &emsp; CALIBRATION
&emsp;&emsp;&emsp; Execute the camera_calibrate.py to get the values of camera matrix and Coefficients
	
	> python3 camera_calibrate.py
	> save the values of output

	
####2 &emsp; UNDISTORT
&emsp;&emsp;&emsp; ADD the values obtain in calibration process in the undistort.py file & Execute the undistort.py to undistort & save the image.
	
	> python3 undistort.py /path/to/the/image/to/be/undistorted
