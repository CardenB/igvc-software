#ifndef STEREOSOURCE_H
#define STEREOSOURCE_H

#include <hardware/sensors/camera/StereoPair.hpp>
#include <common/datastructures/StereoImageData.hpp>
#include <boost/thread/thread.hpp>
#include <QObject>

class StereoSource : public QObject
{
    Q_OBJECT
public:
    StereoSource() : _running(true) {
        qRegisterMetaType<StereoImageData>("StereoImageData");
        qRegisterMetaType<ImageData>("ImageData");
    }
    inline bool Running() {return _running;}
    inline void Running(bool newState) {_running = newState;}
    inline void LockImages() {_imagesLock.lock();}
    inline void UnlockImages() {_imagesLock.unlock();}
    inline void LockRunning() {_runningLock.lock();}
    inline void UnlockRunning() {_runningLock.unlock();}
    virtual bool IsConnected() = 0;
    virtual ~StereoSource() {}

signals:
    void onNewData(StereoImageData);
    void onNewLeftImage(ImageData image);
    void onNewRightImage(ImageData image);

private:
    bool _running;
    boost::mutex _runningLock;
    boost::mutex _imagesLock;
};

#endif // STEREOSOURCE_H
