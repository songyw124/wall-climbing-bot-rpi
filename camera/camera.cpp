//
// Simple camera test and saving the frame.
// Usage : press 'q' to quit, press 'c' to Caputure the current frame.

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**) {
    // Initialize cap
    VideoCapture cap;

    // Parameters to open cap
    int deviceID = 0;
    int apiID = cv::CAP_V4L2;

    // Open selected camera using selected API
    cap.open(deviceID, apiID);

    // VideoCapture settings
    cap.set(CAP_PROP_FRAME_WIDTH, 1024);
    cap.set(CAP_PROP_FRAME_HEIGHT, 768);
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));

    // Check if VideoCapture open succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    
    //----- Camera grabbing loop -----//
    cout << "Start grabbing" << endl << "Press any q to terminate" << endl
            << "Press c to capture the image" << endl;

    // Frame matrix to store fetched frame from camera
    Mat frame;

    // Name and Num for the image
    String imgName = "./image/xx";
    int imgNum = 0;

    // Loop for the live image streaming
    while (1) {
        // Wait for a new frame from camera and store it
        cap.read(frame);
        // Check if frame is grabbed succesfully
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
    
        // Press c to save the data
        if (waitKey(1) == 'c' || waitKey(5) == 'C') {
            imgName = "./image/xx" + to_string(imgNum) + ".jpg";
            //
            imgNum++;
            imwrite(imgName, frame);
        }

        // Show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);

        // Press q to exit the capturing mode.
        if (waitKey(1) == 'q' || waitKey(1) == 'Q') {
            break;
        }
    }

    // The camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
