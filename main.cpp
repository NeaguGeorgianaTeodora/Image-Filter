#include<iostream>
#include"Image.h"
#include "Test.cpp"

using namespace std;



int main()
{
    Image x;

    x.load("Load.txt");

    Image x2{x};

    cout << x;
    x.save("Save.txt");

    cout << endl;

    //BrightnessAndContrast go;
    //Image newImg(x.width(), x.height());

    ////go.setAlpha(1000);
    //go.setBeta(-1000);
    //go.process(x, newImg);
    //cout << newImg;

    /*Image newImg(x.width(),x.height());

    GamaCorrection g;
    g.setGama(2);
    g.process(x2, newImg);

    cout << newImg;

    cout << endl;*/



    /*Image newImg1(x.width(), x.height());

    GamaCorrection g1;
    g1.setGama(3);
    g1.process(x, newImg1);
    cout << newImg1;*/

    /*Image demo;
    x.getROI(demo, 2, 2, 3, 3);
    cout << demo;

    ImageConvolution k;
    k.setKernal("ik");

    Image y;

    y = k.transormToImg();
    cout << endl;
    cout << y;

    Image z;
    z = demo * y;

    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            sum += z.m_data[i][j];
    }

    sum = sum / 16;

    cout << endl << sum;
    */
    /*Image w;
    ImageConvolution k;
    k.setKernal("ik");

    k.process(x, w);
    cout << endl << w;*/

    /*Rectangle r1(1,-1,3,3),r2(-1,-2,3,2);
    cout << (r1 | r2);*/
    Point p1(0,0), p2(0,4),c(10,4);
    Rectangle r(2, 2, 2, 2);
    Drawing a;
    //a.drawLine(x, p1, p2, 0);
    a.drawRectangle(x, r, 111);
    //a.drawRectangle(x,p1,c,135);
    //a.drawCircle(x, c, 2, 0);
    x.save("Save.txt");

    SizeTest::runTests();
    PointTest::runTests();
    RectangleTest::runTests();
    ImageTest::runTests();
    BrightnessAndContrastTest::runTests();
    GamaCorrectionTest::runTests();
    ImageConvolutionTest::runTests();
    DrawingTest::runTests();
    return 0;
}