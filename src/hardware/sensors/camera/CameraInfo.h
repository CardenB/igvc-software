#ifndef CAMERAINFO_H
#define CAMERAINFO_H

#include <math.h>
#include <cmath>

#define deg2rad(a) a/180*M_PI
#define rad2deg(a) a*180/M_PI

namespace IGVC
{
  /*!
    * \brief Provides access to useful camera parameters.
    * Deprecated in favor of the ConfigManager. Will be removed soon.
    */
  class CameraInfo
  {
    public:
      //Actually useful functions
      CameraInfo();
      static CameraInfo CurrentCamera();
      static CameraInfo Bumblebee2_BB2_08S2C_38();
      double HFOV();
      double VFOV();
      double dPhi();
      double dTheta();
      //Getters
      double FocalLength();
      int PixelsPerRow();
      int PixelsPerColumn();
      double PixelSideLength();
      double Baseline();
      //Setters
      void FocalLength(double);
      void PixelsPerRow(int);
      void PixelsPerColumn(int);
      void PixelSideLength(double);
      void Baseline(double);
      //Dtor
      virtual ~CameraInfo();

    private:
      double _focalLength;
      int _pixelsPerRow;
      int _pixelsPerColumn;
      double _pixelSideLength;
      double _baseline;
  }
  __attribute__((__deprecated__));
}
#endif // CAMERAINFO_H
