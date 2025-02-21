#include <iostream>
#include "rtx5070.h"
using namespace std;

int main() {
    cout << endl;
    cout << "Program started." << endl;
    Rtx5070 gpu0;
    Rtx5070* gpu1Ptr = new Rtx5070();

    cout << endl;
    cout << "Playing Minecraft with raytracing on:" << endl;
    gpu0.enableRayTracing();
    gpu0.playMinecraft();
    cout << "  - Pixels rendered: " << gpu0.getPixelsRendered() << endl;
    cout << "  - Kilowatt-hours used: " << gpu0.getKilowattHoursUsed() << endl;

    cout << endl;
    cout << "Playing Minecraft with raytracing off:" << endl;
    gpu1Ptr->disableRayTracing();
    gpu1Ptr->playMinecraft();
    cout << "  - Pixels rendered: " << gpu1Ptr->getPixelsRendered() << endl;
    cout << "  - Kilowatt-hours used: " << gpu1Ptr->getKilowattHoursUsed() << endl;

    cout << endl;
    cout << "Program done." << endl;
    delete gpu1Ptr;
}
