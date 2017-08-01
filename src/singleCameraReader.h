#ifndef SINGLECAMERAREADER_H
#define SINGLECAMERAREADER_H

#include "singleCamera.h"
#include <opencv2/opencv.hpp>

class singleCameraReader
{
    public:
    singleCameraReader( ) {}
    ~singleCameraReader( ) {}

    public:
    unsigned int getConnectCameraNum( );
    void setCameraProperty( double frameRate,
                            double brightness,
                            double exposure,
                            double gain,
                            bool is_auto_shutter,
                            double shutter );
    void printCameraProperty( );

    bool startCamera( unsigned int serialNum,
                      double frameRate,
                      double brightness,
                      double exposure,
                      double gain,
                      bool is_auto_shutter,
                      double shutter,
                      bool is_print_info = false );
    cv::Mat grabImage( );
    void stopCamera( );

    FlyCapture2::BusManager& BusManager( );
    singleCamera& Camera( );
    const int cameraNum( ) const;

    private:
    unsigned int cameraNumber;
    singleCamera camera;
    FlyCapture2::Error error;
    FlyCapture2::BusManager busMgr;
};

#endif // SINGLECAMERAREADER_H
