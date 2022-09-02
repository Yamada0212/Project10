#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// •¨‘Ì‚Ì’è‹`
/// </summary>
template<class T> class Solid {
public:
    virtual T  GetVolume() = 0;
    virtual T  GetSurface() = 0;
};

/// <summary>
/// ” Œ^
/// </summary>
template<class T> class Box :Solid<T> {
private:
    T width;
    T height;
    T depth;

public:
    Box(
        T width,   //•
        T height,  //‚‚³
        T depth) {//‰œs
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    T  GetVolume() {
        return width * height * depth;
    }
    T GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

template<class T> class Cone :Solid<T> {
private:
    T radius;
    T height;
    T busline;

public:
    Cone(double radius, double height, double busline) {
        this->radius = radius;//”¼Œa
        this->height = height;//‚‚³
        this->busline = busline;//•êü
    }
    T GetVolume() {
        return radius * radius * M_PI * height * 1 / 3;
    }
    T GetSurface() {
        return M_PI * radius * (busline + radius);
    }
};
template<class T> class  Cylinder :Solid<T> {
private:
    T rabius;//”¼Œa
    T heught;//‚‚³
public:
    Cylinder(double rabius, double heught) {
        this->rabius = rabius;
        this->heught = heught;
    }
    T GetVolume() {
        return rabius * rabius * M_PI * heught;
    }
    T GetSurface() {
        return 2 * M_PI * rabius * (heught + rabius);
    }
};

template<class T> class Sphere :Solid<T> {
private:
    T rabius;//”¼Œa
public:
    Sphere(double rabius) {
        this->rabius = rabius;
    }
    T GetVolume() {
        return 4 / 3 * M_PI * rabius * rabius * rabius;
    }
    T GetSurface() {
        return 4 * M_PI * rabius * rabius;
    }
};

int main()
{
    Box<double> box{ 3,5,2.5 };
    cout << "box‚Ì‘ÌÏ=" << box.GetVolume() << endl;
    cout << "box‚Ì•\–ÊÏ=" << box.GetSurface() << endl;
    Cone<double> cone{ 3,2.5,5 };
    cout << " Cone‚Ì‘ÌÏ=" << cone.GetVolume() << endl;
    cout << " Cone‚Ì•\–ÊÏ=" << cone.GetSurface() << endl;
    Cylinder<double> cylinder{ 3,2.5 };
    cout << "Cylinder‚Ì‘ÌÏ=" << cylinder.GetVolume() << endl;
    cout << "Cylinder‚Ì•\–ÊÏ=" << cylinder.GetSurface() << endl;
    Sphere<double> sphere{ 3 };
    cout << " Sphere‚Ì‘ÌÏ=" << sphere.GetVolume() << endl;
    cout << " Sphere‚Ì•\–ÊÏ=" << sphere.GetSurface() << endl;
}