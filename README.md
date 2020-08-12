# QtStereoCamProject #
A Computer Vision VS2017 project developed in C++ and OpenCV. Its aim is to create a stereo vision system in order to understand and show each of the steps that make up the process, from the intrinsic and extrinsic calibration of the cameras to obtaining a 3D point cloud of the captured environment, including the corresponding disparity maps.

# Phases #
The phases carried out throughout the project were the following:
- Calibration and extraction of the intrinsic parameters of each camera.
- Application of these parameters to calibrate the stereo system.
- Rectification and elimination of the distortion artifacts from images.
- Obtaining a disparity map between two rectified and undistorted images.
- From this disparity map, calculate the 3D point cloud in mm.

A graphic interface in Qt has been implemented.

# The GUI #
The user interface is quite simple to use. It consists of two views within which three type of images can be displayed: the calibration images as they are being processed by the calibration process; the disparity matrix ; the images captured in real-time by the cameras in the Start Capture mode with a built-in feedback indicating when the program is correctly detecting the panel pattern in order to make sure that the images to be captured will be recognized later by the findChessboardCorners function in the calibration process.

While in the Start Capture mode, you can press the Take Pic button to capture and save the pair of images for later calibration. With the Calibrate Cameras button the calibration process will be initiated by taking the images contained in the specified folder. At the end of the process, the program will output the reprojection error obtained from the process. The Disparity Map button will start the computation process of the disparity matrix. When it finishes, it will save a disparity matrix image for debug purposes, and a txt with the 3d point cloud in millimeters.

To represent this cloud, a existing Matlab script can be used to convert the txt points to .ply format for its later reproduction using a 3D reader program, such as MeshLab.
It is also worth mentioning that the program has two sliders that change in real time the configuration of the cameras while they are in Start Capture mode. The numerical parameters are the parameters of the calibration panel. It is important that these parameters are set correctly before doing anything because they are required by the findChessboardCorners function to correctly identify the panel.

