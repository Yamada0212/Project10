#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// ���̂̒�`
/// </summary>
template<class T> class Solid {
public:
    virtual T  GetVolume() = 0;
    virtual T  GetSurface() = 0;
};

/// <summary>
/// ���^
/// </summary>
template<class T> class Box :Solid<T> {
private:
    T width;
    T height;
    T depth;

public:
    Box(
        T width,   //��
        T height,  //����
        T depth) {//���s
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
        this->radius = radius;//���a
        this->height = height;//����
        this->busline = busline;//���
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
    T rabius;//���a
    T heught;//����
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
    T rabius;//���a
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
    cout << "box�̑̐�=" << box.GetVolume() << endl;
    cout << "box�̕\�ʐ�=" << box.GetSurface() << endl;
    Cone<double> cone{ 3,2.5,5 };
    cout << " Cone�̑̐�=" << cone.GetVolume() << endl;
    cout << " Cone�̕\�ʐ�=" << cone.GetSurface() << endl;
    Cylinder<double> cylinder{ 3,2.5 };
    cout << "Cylinder�̑̐�=" << cylinder.GetVolume() << endl;
    cout << "Cylinder�̕\�ʐ�=" << cylinder.GetSurface() << endl;
    Sphere<double> sphere{ 3 };
    cout << " Sphere�̑̐�=" << sphere.GetVolume() << endl;
    cout << " Sphere�̕\�ʐ�=" << sphere.GetSurface() << endl;
}