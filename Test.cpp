#include "Image.h"
#include <cassert>
#include<iostream>

class SizeTest
{
public:
    static void runTests()
    {
        test_Def_Constructor_Size();
        test_Param_Constructor_Size();
        std::cout << "Size tests done" << std::endl;
    }
private:

    static void test_Def_Constructor_Size()
    {
        Size s;
        assert(s.width == 0);
        assert(s.height == 0);
    }

    static void test_Param_Constructor_Size()
    {
        Size s(2,7);
        assert(s.width == 2);
        assert(s.height == 7);
    }
};

class PointTest
{
public:
    static void runTests()
    {
        test_Def_Constructor_Point();
        test_Param_Constructor_Point();
        test_getX();
        test_getY();
        test_setX();
        test_setY();
        std::cout << "Point tests done" << std::endl;
    }
private:
    static void test_Def_Constructor_Point()
    {
        Point p;
        assert(p.x == 0);
        assert(p.y == 0);
    }

    static void test_Param_Constructor_Point()
    {
        Point p(2, 7);
        assert(p.x == 2);
        assert(p.y == 7);
    }

    static void test_getX()
    {
        Point p(2, 7);
        assert(p.getX() == 2);
    }

    static void test_getY()
    {
        Point p(2, 7);
        assert(p.getY() == 7);
    }

    static void test_setX()
    {
        Point p(2, 7);
        p.setX(3);
        assert(p.getX() == 3);
    }

    static void test_setY()
    {
        Point p(2, 7);
        p.setY(3);
        assert(p.getY() == 3);
    }
};


class RectangleTest
{
public:
    static void runTests()
    {
        test_Def_Constructor_Rectangle();
        test_Param_Constructor_Rectangle();
        test_Param_Constructor_Rectangle2();
        test_getX();
        test_getY();
        test_getWidth();
        test_getHeight();
        test_setX();
        test_setY();
        test_setWidth();
        test_setHeight();
        test_addition();
        test_subtraction();
        test_intersection();
        test_union();
        std::cout << "Rectangle tests done" << std::endl;
    }
private:
    static void test_Def_Constructor_Rectangle()
    {
        Rectangle r;
        assert(r.x == 0);
        assert(r.y == 0);
        assert(r.width == 0);
        assert(r.height == 0);
    }

    static void test_Param_Constructor_Rectangle()
    {
        Rectangle r(2, 7, 3, 4);
        assert(r.x == 2);
        assert(r.y == 7);
        assert(r.width == 3);
        assert(r.height == 4);
    }

    static void test_Param_Constructor_Rectangle2()
    {
        Point p1(2, 7);
        Point p2(5, 11);
        Rectangle r(p1, p2);
        assert(r.x == 2);
        assert(r.y == 7);
        assert(r.width != 3);
        assert(r.height != 4);
    }

    static void test_getX()
    {
        Rectangle r(2, 7, 3, 4);
        assert(r.getX() == 2);
    }

    static void test_getY()
    {
        Rectangle r(2, 7, 3, 4);
        assert(r.getY() == 7);
    }

    static void test_getWidth()
    {
        Rectangle r(2, 7, 3, 4);
        assert(r.getWidth() == 3);
    }

    static void test_getHeight()
    {
        Rectangle r(2, 7, 3, 4);
        assert(r.getHeight() == 4);
    }

    static void test_setX()
    {
        Rectangle r(2, 7, 3, 4);
        r.setX(3);
        assert(r.getX() == 3);
    }

    static void test_setY()
    {
        Rectangle r(2, 7, 3, 4);
        r.setY(3);
        assert(r.getY() == 3);
    }

    static void test_setWidth()
    {
        Rectangle r(2, 7, 3, 4);
        r.setWidth(5);
        assert(r.getWidth() == 5);
    }

    static void test_setHeight()
    {
        Rectangle r(2, 7, 3, 4);
        r.setHeight(5);
        assert(r.getHeight() == 5);
    }

    static void test_addition()
    {
        Rectangle r1(2, 7, 3, 4);
        Rectangle r2(5, 11, 3, 4);
        Rectangle r3 = r1 + r2;
        assert(r3.x == 7);
        assert(r3.y == 18);
        assert(r3.width == 3);
        assert(r3.height == 4);
    }

    static void test_subtraction()
    {
        Rectangle r1(2, 7, 3, 4);
        Rectangle r2(5, 11, 3, 4);
        Rectangle r3 = r1 - r2;
        assert(r3.x == 3);
        assert(r3.y == 4);
        assert(r3.width == 3);
        assert(r3.height == 4);
    }

    static void test_intersection()
    {

        Rectangle r1(2, 7, 3, 4);
        Rectangle r2(5, 11, 3, 4);
        //intersection in a point
        Rectangle r3 = r1 & r2;
        assert(r3.x == 5);
        assert(r3.y == 7);
        assert(r3.width == 0);
        assert(r3.height == 0);

        Rectangle r4(3, 6, 1, 1);
        Rectangle r5 = r1 & r4;
        //one rectangle is inside the other
        assert(r5.x == 3);
        assert(r5.y == 6);
        assert(r5.width == 1);
        assert(r5.height == 1);

        Rectangle r6(-4, 6, 2, 2);
        Rectangle r7 = r1 & r6;
        //no intersection]
        assert(r7.x == 0);
        assert(r7.y == 0);
        assert(r7.width == 0);
        assert(r7.height == 0);

        Rectangle r8(1,7,1,2);
        Rectangle r9 = r1 & r8;
        //intersection in a line
        assert(r9.x == 2);
        assert(r9.y == 7);
        assert(r9.width == 0);
        assert(r9.height == 2);

        Rectangle r10(3, 4, 3, 2);
        Rectangle r11 = r1 & r10;
        //intersection in a rectangle
        assert(r11.x == 3);
        assert(r11.y == 4);
        assert(r11.width == 2);
        assert(r11.height == 1);
    }

    static void test_union()
    {
        Rectangle r1(2, 7, 3, 4);
        Rectangle r2(5, 11, 3, 4);
        Rectangle r3 = r1 | r2;
        //union in a rectangle
        assert(r3.x == 2);
        assert(r3.y == 11);
        assert(r3.width == 6);
        assert(r3.height == 8);

        Rectangle r4(3, 6, 1, 1);
        Rectangle r5 = r1 | r4;
        //one rectangle is inside the other
        assert(r5.x == 2);
        assert(r5.y == 7);
        assert(r5.width == 3);
        assert(r5.height == 4);

        Rectangle r6(-4, 6, 2, 2);
        Rectangle r7 = r1 | r6;
        //union with one rectangle with negative coordinates
        assert(r7.x == -4);
        assert(r7.y == 7);
        assert(r7.width == 9);
        assert(r7.height == 4);

        Rectangle r8(1,7,3,2);
        Rectangle r9 = r1 | r8;
        //union in a line
        assert(r9.x == 1);
        assert(r9.y == 7);
        assert(r9.width == 4);
        assert(r9.height == 4);
    }
};

class ImageTest
{
public:
    static void runTests()
    {
        test_def_constructor();
        test_param_constructor();
        test_copy_constructor();
        test_assignmentOp();
        test_matrixAddition();
        test_scalarAddition();
        //test_matrixMultiplication();
        test_scalarMultiplication();
        test_matrixSubstraction();
        test_scalarSubstraction();
        test_getROI_Point();
        test_getROI_Coord();
        test_isEmpty();
        test_size();
        test_width();
        test_height();
        test_setWidth();
        //test_setHeight();
        test_at_coord();
        test_at_point();
        test_sum();
        std::cout << "Image tests done" << std::endl;
    };
private:
    static void test_def_constructor()
    {
        Image i;
        assert(i.width() == 0);
        assert(i.height() == 0);
    }

    static void test_param_constructor()
    {
        Image i(3, 4);
        assert(i.width() == 3);
        assert(i.height() == 4);
    }

    static void test_copy_constructor()
    {
        Image x;
        x.load("Load.txt");
        Image x2{x};
        assert(x2.width() == 24);
        assert(x2.height() == 7);
        assert(x2.at(0, 4) == 0);
        assert(x2.at(4, 7) == 7);
    }

    static void test_assignmentOp()
    {
        Image x;
        x.load("Load.txt");
        Image x2;
        x2 = x;
        assert(x2.width() == 24);
        assert(x2.height() == 7);
        assert(x2.at(0, 4) == 0);
        assert(x2.at(4, 7) == 7);
    }

    static void test_matrixAddition()
    {
        Image x;
        x.load("Load.txt");
        Image x3 = x + x;
        assert(x3.width() == 24);
        assert(x3.height() == 7);
        for (int i = 0; i < x3.width(); i++)
            for (int j = 0; j < x3.height(); j++)
                assert(x3.at(j, i) == x.at(j, i) + x.at(j, i));
    }

    static void test_scalarAddition()
    {
        Image x;
        x.load("Load.txt");
        Image x2 = x + 5;
        assert(x2.width() == 24);
        assert(x2.height() == 7);
        for(int i = 0; i < x2.width(); i++)
            for(int j = 0; j < x2.height(); j++)
                assert(x2.at(j,i) == x.at(j,i) + 5);
    }

    /*static void test_matrixMultiplication()
    {
        Image x;
        x.load("Load.txt");
        Image x3 = x * x;
        assert(x3.width() == 24);
        assert(x3.height() == 7);
        for (int i = 0; i < x3.width(); i++)
            for (int j = 0; j < x3.height(); j++)
                assert(x3.at(j, i) == x.at(j, i) * x.at(j, i));
    }*/

    static void test_scalarMultiplication()
    {
        Image x;
        x.load("Load.txt");
        Image x2 = x * 5;
        assert(x2.width() == 24);
        assert(x2.height() == 7);
        for (int i = 0; i < x2.width(); i++)
            for (int j = 0; j < x2.height(); j++)
                assert(x2.at(j, i) == x.at(j, i) * 5);
    }

    static void test_matrixSubstraction()
    {
        Image x;
        x.load("Load.txt");
        Image x3 = x - x;
        assert(x3.width() == 24);
        assert(x3.height() == 7);
        for (int i = 0; i < x3.width(); i++)
            for (int j = 0; j < x3.height(); j++)
                assert(x3.at(j, i) == x.at(j, i) - x.at(j, i));
    }

    static void test_scalarSubstraction()
    {
        Image x;
        x.load("Load.txt");
        Image x2 = x - 5;
        assert(x2.width() == 24);
        assert(x2.height() == 7);
        for (int i = 0; i < x2.width(); i++)
            for (int j = 0; j < x2.height(); j++)
            {
                if(x.at(j, i) - 5 >= 0)
                    assert(x2.at(j, i) == x.at(j, i) - 5);
                else
                    assert(x2.at(j, i) == 0);
            }
    }

    static void test_getROI_Point()
    {
        Image x;
        x.load("Load.txt");
        Rectangle r(0, 0, 4, 4);
        Image x2;
        x.getROI(x2, r);
        assert(x2.width() == 4);
        assert(x2.height() == 4);
        for(int i = 0; i < x2.width(); i++)
            for(int j = 0; j < x2.height(); j++)
                assert(x2.at(j,i) == x.at(j,i));
    }

    static void test_getROI_Coord()
    {
        Image x;
        x.load("Load.txt");
        Image x2;
        x.getROI(x2, 0, 0, 4, 4);
        assert(x2.width() == 4);
        assert(x2.height() == 4);
        for (int i = 0; i < x2.width(); i++)
            for (int j = 0; j < x2.height(); j++)
                assert(x2.at(j, i) == x.at(j, i));
    }


    static void test_isEmpty()
    {
        Image x;
        assert(x.isEmpty() == true);
        x.load("Load.txt");
        assert(x.isEmpty() == false);
    }

    static void test_size()
    {
        Image x(4,7);
        assert(x.sz().width == 4);
        assert(x.sz().height == 7);
    }

    static void test_width()
    {
        Image x(4, 7);
        assert(x.width() == 4);
    }

    static void test_height()
    {
        Image x(4, 7);
        assert(x.height() == 7);
    }

    static void test_setWidth()
    {
        Image x(4, 7);
        x.setWidth(5);
        assert(x.width() == 5);
    }

    static void test_setHeight()
    {
        Image x(4, 7);
        x.setHeight(8);
        assert(x.height() == 8);
    }

    static void test_at_coord()
    {
        Image x;
        x.load("Load.txt");
        Image x2;
        x.getROI(x2, 0, 0, 4, 4);
        assert(x2.width() == 4);
        assert(x2.height() == 4);
        for (int i = 0; i < x2.width(); i++)
            for (int j = 0; j < x2.height(); j++)
                assert(x2.at(j, i) == x.at(j, i));
    }

    static void test_at_point()
    {
        Image x;
        Point p;
        x.load("Load.txt");
        Image x2;
        x.getROI(x2, 0, 0, 4, 4);
        assert(x2.width() == 4);
        assert(x2.height() == 4);
        for (int i = 0; i < x2.height(); i++)
            for (int j = 0; j < x2.width(); j++)
            {
                p.setX(i);
                p.setY(j);
                assert(x2.at(i,j) == x.at(p));
            }
    }

    static void test_sum()
    {
        Image x;
        x.load("Load.txt");
        assert(x.sum() == 444);
    }
};

class BrightnessAndContrastTest
{
public:
    static void runTests()
    {
        test_Def_Const();
        test_setAlpha();
        test_setBeta();
        test_getAlpha();
        test_getBeta();
        test_Process();
        std::cout << "Brightness and Contrast tests done " << std::endl;
    }
private:

    static void test_Def_Const()
    {
        BrightnessAndContrast x;
        assert(x.getAlpha() == 1);
        assert(x.getBeta() == 0);
    }
    static void test_setAlpha()
    {
        BrightnessAndContrast x;
        x.setAlpha(2);
        assert(x.getAlpha() == 2);
    }
    static void test_setBeta()
    {
        BrightnessAndContrast x;
        x.setBeta(2);
        assert(x.getBeta() == 2);
    }
    static void test_getAlpha()
    {
        BrightnessAndContrast x;
        x.setAlpha(2);
        assert(x.getAlpha() == 2);
    }
    static void test_getBeta()
    {
        BrightnessAndContrast x;
        x.setBeta(2);
        assert(x.getBeta() == 2);
    }

    static void test_Process()
    {
        Image x;
        x.load("Load.txt");
        Image newImg(x.width(), x.height());
        BrightnessAndContrast ab;
        Point p;
        ab.setAlpha(2);
        ab.setBeta(2);
        ab.process(x,newImg);
        for(int i = 0; i<x.height(); i++)
            for (int j = 0; j < x.width(); j++)
            {
                if(x.at(i,j)*2+2 > 255)
                    assert(newImg.at(i, j) == 255);
                else
                    assert(newImg.at(i, j) == x.at(i, j)*2+2);
            }
    }
};

class GamaCorrectionTest
{
public:
    static void runTests()
    {
        test_Def_Const();
        test_setGama();
        test_getGama();
        test_Process();
        std::cout << "Gama Correction tests done " << std::endl;
    }
private:

    static void test_Def_Const()
    {
        GamaCorrection x;
        assert(x.getGama() == 1.0);
    }
    static void test_setGama()
    {
        GamaCorrection x;
        x.setGama(2.0);
        assert(x.getGama() == 2.0);
    }
    static void test_getGama()
    {
        GamaCorrection x;
        x.setGama(2.0);
        assert(x.getGama() == 2.0);
    }
    static void test_Process()
    {
        Image x;
        x.load("Load.txt");
        Image newImg(x.width(), x.height());
        GamaCorrection ab;
        Point p;
        ab.setGama(2);
        ab.process(x, newImg);
        for (int i = 0; i<x.height(); i++)
            for (int j = 0; j < x.width(); j++)
            {
                if (pow(x.at(i, j),2) > 255)
                    assert(newImg.at(i, j) == 255);
                else
                    assert(newImg.at(i, j) == pow(x.at(i, j),2));
            }
    }
};

class ImageConvolutionTest
{
public:
    static void runTests()
    {
        test_Def_Const();
        test_setKernel();
        //test_Process();
        std::cout << "Image Convolution tests done " << std::endl;
    }
private:

    static void test_Def_Const()
    {
        ImageConvolution x;
        assert(x.getValue() == 1);
        for(int i = 0; i<3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                    assert(x.getKernel(i,j) == 1);
                else
                    assert(x.getKernel(i,j) == 0);
            }
    }
    static void test_setKernel()
    {
        ImageConvolution x;
        x.setKernal("mbk");
        assert(x.getValue() == 9);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                assert(x.getKernel(i, j) == 1);
            }

        x.setKernal("ik");
        assert(x.getValue() == 1);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                    assert(x.getKernel(i, j) == 1);
                else
                    assert(x.getKernel(i, j) == 0);
            }

        x.setKernal("gbk");
        assert(x.getValue() == 16);
        assert(x.getKernel(0,0) == 1);
        assert(x.getKernel(0,2) == 1);
        assert(x.getKernel(2,0) == 1);
        assert(x.getKernel(2,2) == 1);

        assert(x.getKernel(0, 1) == 2);
        assert(x.getKernel(1, 0) == 2);
        assert(x.getKernel(1, 2) == 2);
        assert(x.getKernel(2, 1) == 2);

        assert(x.getKernel(1, 1) == 4);

        x.setKernal("hsk");
        assert(x.getKernel(0, 0) == 1);
        assert(x.getKernel(0, 1) == 2);
        assert(x.getKernel(0,2) == 1);
        assert(x.getKernel(1,0) == 0);

        assert(x.getKernel(1,1) == 0);
        assert(x.getKernel(1, 2) == 0);
        assert(x.getKernel(2,0) == -1);
        assert(x.getKernel(2,1) == -2);

        assert(x.getKernel(2,2) == -1);

        x.setKernal("vsk");
        assert(x.getKernel(0, 0) == 1);
        assert(x.getKernel(0, 1) == 0);
        assert(x.getKernel(0, 2) == -1);
        assert(x.getKernel(1, 0) == 2);

        assert(x.getKernel(1, 1) == 0);
        assert(x.getKernel(1, 2) == -2);
        assert(x.getKernel(2, 0) == 1);
        assert(x.getKernel(2, 1) == 0);

        assert(x.getKernel(2, 2) == -1);
    }

    /*static void test_Process()
    {
        Image x;
        x.load("Load.txt");
        Image newImg(x.width(), x.height());
        ImageConvolution ab;
        Point p;
        ab.setKernal("mbk");
        ab.process(x, newImg);
        for (int i = 0; i<x.height(); i++)
            for (int j = 0; j < x.width(); j++)
            {
                assert(newImg.at(i, j) == x.at(i, j));
            }
    }*/
};

class DrawingTest
{
public:
    static void runTests()
    {
        test_DrawLine();
        test_DrawCircle();
        test_DrawRectangle_Rec();
        test_DrawRectangle_Coord();
        std::cout<< "Drawing tests done " << std::endl;
    }
private:

    static void test_DrawCircle()
    {
        Image x;
        x.load("Load.txt");
        Image x2{ x };
        Point c(10, 4);
        Drawing a;
        a.drawCircle(x2, c, 2, 111);
        assert(x2.at(3, 8) == 111);
        assert(x2.at(4, 8) == 111);
        assert(x2.at(5, 8) == 111);

        assert(x2.at(3, 12) == 111);
        assert(x2.at(4, 12) == 111);
        assert(x2.at(5, 12) == 111);

        assert(x2.at(6,9) == 111);
        assert(x2.at(6,11) == 111);
        assert(x2.at(6,10) == 111);

        assert(x2.at(2, 9) == 111);
        assert(x2.at(2, 11) == 111);
        assert(x2.at(2, 10) == 111);
    }

    static void test_DrawLine()
    {
        Image x;
        x.load("Load.txt");
        Image x2{ x };
        Point p1(0, 0), p2(0, 4);
        Drawing a;
        a.drawLine(x2, p1, p2, 111);
        assert(x2.at(0, 0) == 111);
        assert(x2.at(1, 0) == 111);
        assert(x2.at(2, 0) == 111);
        assert(x2.at(3, 0) == 111);
        assert(x2.at(4, 0) == 111);
        assert(x2.at(5, 0) != 111);
        assert(x2.at(5, 0) == 0);
    }

    static void test_DrawRectangle_Rec()
    {
        Image x;
        x.load("Load.txt");
        Image x2{ x };
        Rectangle r(2, 2, 2, 2);
        Drawing a;
        a.drawRectangle(x2, r, 111);
        assert(x2.at(2, 2) == 111);
        assert(x2.at(3, 2) == 111);
        assert(x2.at(4, 2) == 111);

        assert(x2.at(2, 3) == 111);
        assert(x2.at(3, 3) == 3);
        assert(x2.at(4, 3) == 111);

        assert(x2.at(2, 4) == 111);
        assert(x2.at(3, 4) == 111);
        assert(x2.at(4, 4) == 111);
    }

    static void test_DrawRectangle_Coord()
    {
        Image x;
        x.load("Load.txt");
        Image x2{ x };
        Point p1(2, 2), p2(4, 4);
        Rectangle r(2, 2, 2, 2);
        Drawing a;
        a.drawRectangle(x2, p1,p2, 111);
        assert(x2.at(2, 2) == 111);
        assert(x2.at(3, 2) == 111);
        assert(x2.at(4, 2) == 111);

        assert(x2.at(2, 3) == 111);
        assert(x2.at(3, 3) == 3);
        assert(x2.at(4, 3) == 111);

        assert(x2.at(2, 4) == 111);
        assert(x2.at(3, 4) == 111);
        assert(x2.at(4, 4) == 111);
    }
};