#include <iostream>
using namespace std;

class Rtx5070 {
        bool _rayTracingOn;
        int _pixelsRendered;
        double _kilowattHoursUsed;
        double _powerMult;

    public:
        bool getRayTracingOn() const { return _rayTracingOn; }
        int getPixelsRendered() const { return _pixelsRendered; }
        double getKilowattHoursUsed() const { return _kilowattHoursUsed; }

        Rtx5070() {
            _rayTracingOn = false;
            _pixelsRendered = 0;
            _kilowattHoursUsed = 0;
            _powerMult = 0.25;
            cout << "New Rtx5070 object created." << endl;
        }

        ~Rtx5070() {
            cout << "Rtx5070 object deleted." << endl;
        }

        void enableRayTracing() {
            _rayTracingOn = true;
            _powerMult = 0.5;
        }

        void disableRayTracing() {
            _rayTracingOn = false;
            _powerMult = 0.25;
        }

        void toggleRayTracing() {
            if (_rayTracingOn) disableRayTracing();
            else enableRayTracing();
        }

        void playMinecraft(
            int resWidth = 1920,
            int resHeight = 1080,
            int playtimeSecs = 3600,
            int framerate = 144
        ) {
            _pixelsRendered += resWidth * resHeight * playtimeSecs * framerate;
            _kilowattHoursUsed += (playtimeSecs / 60) * _powerMult;
        }
};
