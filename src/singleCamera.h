#ifndef CAMERAREADER_H
#define CAMERAREADER_H

#include <iostream>
#include <vector>

#include <flycapture/FlyCapture2.h>
#include <opencv2/core.hpp>

class singleCamera
{
    public:
    singleCamera( );
    singleCamera( unsigned int serialNum );
    ~singleCamera( );

    bool initCamera( FlyCapture2::Error& error, FlyCapture2::BusManager& BusMana );
    bool reInitCamera( FlyCapture2::Error& error, unsigned int serialNum, FlyCapture2::BusManager& BusMana );

    public:
    float getFrameRate( FlyCapture2::Error& error );
    float getBrightness( FlyCapture2::Error& error );
    float getAutoExposure( FlyCapture2::Error& error );
    float getSharpness( FlyCapture2::Error& error );
    float getWhiteBalance( FlyCapture2::Error& error );
    float getHue( FlyCapture2::Error& error );
    float getSaturation( FlyCapture2::Error& error );
    float getGamma( FlyCapture2::Error& error );
    float getIris( FlyCapture2::Error& error );
    float getShutter( FlyCapture2::Error& error );
    float getGain( FlyCapture2::Error& error );
    float getTriggerMode( FlyCapture2::Error& error );
    float getTriggerDelay( FlyCapture2::Error& error );

    bool setMetadata( FlyCapture2::Error& error );
    bool setFrameRate( FlyCapture2::Error& error, float rate );
    bool setBrightness( FlyCapture2::Error& error, float brightness );
    bool setAutoExposure( FlyCapture2::Error& error, float exposure );
    bool setGain( FlyCapture2::Error& error, float exposure );
    bool setGamma( FlyCapture2::Error& error, float gamma ); // useless
    bool setShutter( FlyCapture2::Error& error, float shutter );
    bool setShutterAuto( FlyCapture2::Error& error );

    bool isColorCamera( );

    public:
    bool connectCamera( FlyCapture2::Error& error );
    bool getCameraInfo( FlyCapture2::Error& error );
    const unsigned int getSerialNumber( ) const;
    void printCameraInfo( );
    bool getCameraConfiguration( FlyCapture2::Error& error );
    bool setCameraConfiguration( FlyCapture2::Error& error );
    bool startCapture( FlyCapture2::Error& error );
    bool captureOneImage( FlyCapture2::Error& error, cv::Mat& image );
    bool StopCapture( FlyCapture2::Error& error );
    bool disconnectCamera( FlyCapture2::Error& error );

    FlyCapture2::PGRGuid& UniquePGRGuid( );
    FlyCapture2::CameraInfo& camInfo( );
    FlyCapture2::FC2Config& camConfig( );
    void setSerialNumber( unsigned int serial );
    FlyCapture2::Camera* getPCamera( ) const;

    private:
    unsigned int serialNumber;    // serial Number of each camera
    FlyCapture2::PGRGuid guid;    // A GUID to the camera, uniquely identify a camera.
    FlyCapture2::Camera* pCamera; // point to the Camera
    FlyCapture2::FC2Config cameraConfig;
    FlyCapture2::CameraInfo cameraInfo;
};

#endif // CAMERAREADER_H
