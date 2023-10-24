#ifndef IMAGE_FILTER_IMAGE_H
#define IMAGE_FILTER_IMAGE_H

#pragma once
#include <string>
#include <vector>


class Size
{
private:
    friend class SizeTest;
public:
    int width, height;
    Size();
    Size(int w, int h);
};

class Point
{

public:

    Point();
    Point(int _x, int _y);

    int getX();
    int getY();

    void setX(int _x);
    void setY(int _y);

    friend std::ostream& operator<<(std::ostream& os, const Point& dt);
    friend std::istream& operator>>(std::istream& is,  Point& dt);

private:
    int x;
    int y;
    friend class PointTest;
};

class Rectangle
{
public:
    Rectangle();
    Rectangle(int _x, int _y, int w, int h);
    Rectangle(Point p1, Point p2);
    int getX();
    int getY();
    int getWidth();
    int getHeight();

    void setX(int _x);
    void setY(int _y);
    void setWidth(int w);
    void setHeight(int h);

    Rectangle operator+(Rectangle& i);
    Rectangle operator-(Rectangle& i);

    Rectangle operator&(Rectangle& i);
    Rectangle operator|(Rectangle& i);

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& dt);
    friend std::istream& operator>>(std::istream& is, Rectangle& dt);
private:
    int x;
    int y;
    int width;
    int height;
    friend class RectangleTest;
};

class Image
{
public:



    Image();
    Image(unsigned int w, unsigned int h);
    Image(const Image& other);
    ~Image();
    bool load(std::string imagePath);
    bool save(std::string imagePath);
    Image& operator=(const Image& other);
    Image operator+(const Image& i);
    Image operator+(const int s);
    Image operator-(const Image& i);
    Image operator-(const int s);
    Image operator*(const Image& i);
    Image operator*(const int s);
    bool getROI(Image& roiImg, Rectangle roiRect);
    bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    bool isEmpty() const;
    Size sz() const;
    unsigned int width() const;
    unsigned int height() const;
    void setHeight(unsigned int h);
    void setWidth(unsigned int w);
    unsigned char& at(unsigned int x, unsigned int y);
    unsigned char& at(Point pt);
    unsigned char* row(int y);
    void release();
    friend std::ostream& operator<<(std::ostream& os, const Image& dt);
    static Image zeros(unsigned int width, unsigned int height);
    static Image ones(unsigned int width, unsigned int height);
    int sum();


private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned char** m_data;
    friend class ImageTest;
};

class ImageProcessing
{
public:
    virtual void process(Image& src, Image& dst) = 0;
};

class BrightnessAndContrast : public ImageProcessing
{
private:
    int alpha_beta[2];
    friend class BrightnessAndContrastTest;
public:
    BrightnessAndContrast();
    void setAlpha(int a);
    void setBeta(int b);

    int getAlpha();
    int getBeta();

    void process(Image& src, Image& dst) override;
};

class GamaCorrection : public ImageProcessing
{
private:
    float gama;
    friend class GamaCorrectionTest;
public:
    GamaCorrection();
    void setGama(float a);

    float getGama();

    void process(Image& src, Image& dst) override;
};

class ImageConvolution : public ImageProcessing
{
private:
    int k[3][3];
    int value;
    friend class ImageConvolutionTest;
public:
    ImageConvolution();
    void setKernal(std::string type);
    int getKernel(int i, int j);
    int getValue();


    Image transormToImg();

    void process(Image& src, Image& dst) override;
};

class Drawing : Image
{
private:
    friend class DrawingTest;
public:
    void drawCircle(Image& img, Point center, int radius, unsigned char color);
    void drawLine(Image& img, Point p1, Point p2, unsigned char color);
    void drawRectangle(Image& img, Rectangle r, unsigned char color);
    void drawRectangle(Image& img, Point tl, Point br, unsigned char color);

};

#endif //IMAGE_FILTER_IMAGE_H
