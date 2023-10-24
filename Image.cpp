#include "Image.h"
#include<fstream>
#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// ----------- Size Class --------------

/**
 * @brief Constructs an empty Size object with zero width and height.
 *
 */
Size::Size()
{
    width = 0;
    height = 0;
}

/**
 * @brief Constructs an empty Image object with width and height given by user.
 *
 * @param w: The width of the Size.
 * @param h: The height of thSize.
 */
Size::Size(int w, int h)
{
    width = w;
    height = h;
}

//----------- Point Class --------------

/**
 * @brief Constructs an empty Point object with zero x and y.
 *
 */
Point::Point()
{
    x = 0;
    y = 0;
}

/**
 * @brief Constructs an empty Point object with x and y given by user.
 *
 */
Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}

/**
* @brief Get the x coordinate of a point.
*
* @return unsigned int: x coordinate of a point.
*/
int Point::getX()
{
    return this->x;
}

/**
* @brief Get the y coordinate of a point.
*
* @return unsigned int: y coordinate of a point.
*/
int Point::getY()
{
    return this->y;
}

/**
* @brief Sets the x coordinate of a point.
*
* @return void
*/
void Point::setX(int _x)
{
    this->x = _x;
}

/**
* @brief Sets the y coordinate of a point.
*
* @return void
*/
void Point::setY(int _y)
{
    this->y = _y;
}

/**
* @brief Overloaded output stream operator for Point class.
*
* @param os: The output stream object.
* @param dt: The Point object to be printed.
*
* @return A reference to the output stream object.
*/
std::ostream& operator<<(std::ostream& os, const Point& dt)
{
    // Print the point
    os <<"(" << dt.x << " , "<< dt.y << ")";

    // Return the stream
    return os;
}

/**
* @brief Overloaded input stream operator for Point class.
*
* @param is: The input stream object.
* @param dt: The Point object to be readed.
*
* @return A reference to the input stream object.
*/
std::istream& operator>>(std::istream& is, Point& dt)
{
    is>>dt.x >> dt.y;
    return is;
}


//----------- Rectangular Class --------------


/**
 * @brief Constructs an empty Rectangle object with x and y coordinates zero and height and width zero.
 *
 */
Rectangle::Rectangle()
{
    x = 0;
    y = 0;
    height = 0;
    width = 0;
}

/**
 * @brief Constructs an empty Rectangle object with x and y coordinates and height and width given by user.
 *
 * @param _x: the x coordinate of the top left point
 * @param _y: the y coordinate of the top left point
 * 
 * @param w: the width of the rectangle
 * @param h: the height of the rectangle
 */
Rectangle::Rectangle(int _x, int _y, int w, int h)
{
    x = _x;
    y = _y;
    height = h;
    width = w;
}

/**
 * @brief Constructs an empty Rectangle object with x and y coordinates and height and width given by user.
 *
 * @param tl: the top left point
 * @param br: the bottom right point
 *
 */
Rectangle::Rectangle(Point tl, Point br)
{
    x = tl.getX();
    y = tl.getY();
    height = tl.getY() - br.getY();
    width = tl.getX() - br.getX();
}

/**
 * @brief Gets the x coordinate of the top left point
 *
 * @return the x coordinate of the top left point
 */
int Rectangle::getX()
{
    return this->x;
}

/**
 * @brief Gets the y coordinate of the top left point
 *
 * @return the y coordinate of the top left point
 */
int Rectangle::getY()
{
    return this->y;
}

/**
 * @brief Gets the width of the rectangle
 *
 * @return the width of the rectangle
 */
int Rectangle::getWidth()
{
    return this->width;
}

/**
 * @brief Gets the height of the rectangle
 *
 * @return the height of the rectangle
 */
int Rectangle::getHeight()
{
    return this->height;
}

/**
 * @brief Sets the X coordinate of the top left point
 *
 * @return void
 */
void Rectangle::setX(int _x)
{
    this->x = _x;
}

/**
 * @brief Sets the y coordinate of the top left point
 *
 * @return void
 */
void Rectangle::setY(int _y)
{
    this->y = _y;
}

/**
 * @brief Sets the width of the rectangle
 *
 * @return void
 */
void Rectangle::setWidth(int w)
{
    this->width = w;
}

/**
 * @brief Sets the height of the rectangle
 *
 * @return void
 */
void Rectangle::setHeight(int h)
{
    this->height = h;
}


/**
* @brief Overloaded output stream operator for Rectangle class.
*
* @param os: The output stream object.
* @param dt: The Rectangle object to be printed.
*
* @return A reference to the output stream object.
*/
std::ostream& operator<<(std::ostream& os, const Rectangle& dt)
{
    os << "top right point: (" << dt.x << " , " << dt.y << ")"<<endl;
    os << "width: "<<dt.width<<" height: "<<dt.height;

    return os;
}

/**
* @brief Overloaded input stream operator for Rectangle class.
*
* @param is: The input stream object.
* @param dt: The Rectangle object to be printed.
*
* @return A reference to the input stream object.
*/
std::istream& operator>>(std::istream& is, Rectangle& dt)
{
    is >> dt.x >> dt.y >> dt.width >> dt.height;

    return is;
}

/**
* @brief Overloaded + operator for Rectangle class.
*
* @param r: The second rectangle used in the + operation.
*
* @return A Rectangle that stores the result of the + operation.
*/
Rectangle Rectangle::operator+(Rectangle& r)
{
    r.setX(r.x+x);
    r.setY(r.y+y);
    r.setWidth(width);
    r.setHeight(height);
    return r;
}

/**
* @brief Overloaded - operator for Rectangle class.
*
* @param r: The second rectangle used in the - operation.
*
* @return A Rectangle that stores the result of the - operation.
*/
Rectangle Rectangle::operator-(Rectangle& r)
{
    r.setX(r.x - x);
    r.setY(r.y - y);
    r.setWidth(width);
    r.setHeight(height);
    return r;
}

/**
* @brief Overloaded & operator for Rectangle class.
*
* @param r: The second rectangle used in the & operation.
*
* @return A Rectangle that stores the intersection of two rectangles.
*/
Rectangle Rectangle::operator&(Rectangle& r)
{
    int leftX = std::max(x, r.x);
    int topY = std::min(y, r.y);
    int rightX = std::min(x + width, r.x + r.width);
    int bottomY = std::max(y - height, r.y - r.height);

    if (rightX - leftX < 0 || topY - bottomY < 0)
    {
        Rectangle rez(0,0,0,0);

        return rez;
    }

    Rectangle rez(leftX, topY, rightX - leftX, topY - bottomY);

    return rez;
}

/**
* @brief Overloaded | operator for Rectangle class.
*
* @param r: The second rectangle used in the | operation.
*
* @return A Rectangle that stores the reunion of two rectangles.
*/
Rectangle Rectangle::operator|(Rectangle& r)
{

    int leftX = std::min(x, r.x);
    int topY = std::max(y, r.y);
    int rightX = std::max(x + width, r.x + r.width);
    int bottomY = std::min(y - height, r.y - r.height);

    //toate 4 coord pozitive
    Rectangle rez(leftX, topY, rightX - leftX, topY - bottomY);

    return rez;
}


// ----------- Image Class --------------

/**
 * @brief Constructs an empty Image object with null data and zero width and height.
 * 
 */
Image::Image()
{
    this->m_width = 0;
    this->m_height = 0;
    this->m_data = nullptr;
}

/**
 * @brief Constructs an Image object with width and height given by the user.
 *
 * @param w: The width of the image.
 * @param h: The height of the image.
 */
Image::Image(unsigned int w, unsigned int h)
{
    this->m_width = w;
    this->m_height = h;
    m_data = new unsigned char* [m_height];
    for (int i = 0; i < m_height; i++)
        m_data[i] = new unsigned char[m_width];
}

/**
 * @brief Constructs copy of a specified Image object.
 *
 * @param other: The Image object to be copied.
 */
Image::Image(const Image& other)
{
    m_width = other.m_width;
    m_height = other.m_height;
    m_data = new unsigned char* [m_height];
    for (int i = 0; i < m_height; i++)
    {
        m_data[i] = new unsigned char[m_width];
        // Copy the data from the original image
        std::memcpy(m_data[i], other.m_data[i], m_width * sizeof(unsigned char));
    }
}

/**
 * @brief Destroys the Image object and frees the memory.
 */
Image::~Image()
{
    // Free the memory used by the image data
    release();
}

/**
* @brief Get the width of the image.
*
* @return The width of the image.
*/
unsigned int Image::width() const
{
    return this->m_width;
}

/**
* @brief Get the height of the image.
*
* @return The height of the image.
*/
unsigned int Image::height() const
{
    return this->m_height;
}

/**
 * @brief Loads an image from the specified file.
 *
 * @param imagePath: The file path of the imagethat needs to be loaded.
 *
 * @return True, if the image was successfully loaded, false otherwise.
 */
bool Image::load(std::string imagePath)
{
    // Open the file for input
    ifstream fin(imagePath);

    // Read "magic number"
    string magic;
    getline(fin,magic);
    if (magic != "P2")
    {
        //Not a PGM file
        return false;
    }

    // Read the width and height of the image
    string sz;
    getline(fin, sz);
    if (!fin.is_open())
    {
        // Failed to open the file
        return false;
    }
    while (sz[0] == '#')
    {
        getline(fin, sz);
    }
    istringstream iss(sz);
    iss >> m_width >> m_height;

    // Read the maximum value for a pixel
    unsigned int maxval;
    getline(fin, sz);
    istringstream iss2(sz);
    iss2 >> maxval;

    if (maxval > 255)
    {
        // Unsupported maximum value
        return false;
    }

    // Allocate memory for the image data
    m_data = new unsigned char* [m_height];
    for (unsigned int i = 0; i < m_height; i++)
    {
        m_data[i] = new unsigned char[m_width];
    }

    int pixel;
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            fin >> pixel;
            m_data[i][j] = pixel;
        }
    }

    //Close the file
    fin.close();

    //Operation successful
    return true;
}

/**
 * @brief Saves the image data to a specified file.
 *
 * @param imagePath: the path to the output file.
 *
 * @return True, if the image was successfully saved, false otherwise.
 */
bool Image::save(std::string imagePath)
{
    // Open the file for output
    ofstream fout(imagePath);
    if (!fout.is_open())
    {
        // Failed to open the file
        return false;
    }

    // Write the PGM header
    fout << "P2\n" << m_width << " " << m_height << "\n" << "255\n";

    // Write the image data
    //fout.write(reinterpret_cast<const char*>(m_data[0]), m_width * m_height * sizeof(unsigned char));


    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
            fout << std::setw(3) << (int)m_data[i][j] << " ";
        fout << "\n";
    }


    // Close the file
    fout.close();

    // Operation successful
    return true;
}


/**
* @brief Overloaded output stream operator for Image class.
*
* @param os: The output stream object.
* @param dt: The Image object to be printed.
*
* @return A reference to the output stream object.
*/
ostream& operator<<(ostream& os, const Image& dt)
{
    // Print the image pixels in a 2D grid
    for (unsigned int i = 0; i < dt.m_height; i++)
    {
        for (unsigned int j = 0; j < dt.m_width; j++)
        {
            os << std::setw(3) << std::setfill(' ')<< static_cast<int>(dt.m_data[i][j]) << " ";
        }
        os << "\n";
    }

    // Return the stream
    return os;
}


/**
* @brief Overloaded operator + and perform element-wise addition of two images.
*
* @param i: The second Image used in the addition.
*
* @return Image The resulting image after addition. Empty if different sized images
*/
Image Image::operator+(const Image& i)
{
    //if the images have different sizes return an empty imave
    if (this->m_width != i.width() || this->m_height != i.height())
    {
        return Image();
    }

    Image rez(i.m_width, i.m_height);

    //add the elements of the images component wise
    for (int x = 0; x < m_height; x++)
    {
        for (int y = 0; y < m_width; y++)
        {
            int sum =int(this->m_data[x][y]) + int(i.m_data[x][y]);

            if (sum <= 255 && sum >= 0)
                rez.m_data[x][y] = char(sum);
            else
            {
                if(sum > 255)
                    rez.m_data[x][y] = 255;
                else
                {
                    if(sum < 0)
                        rez.m_data[x][y] = 0;
                }
            }
        }
    }
    return rez;
}

/**
* @brief Overloaded operator - and perform element-wise subtraction of two images.
*
* @param i: The second Image used in the subtraction.
*
* @return Image The resulting image after subtraction. Empty if different sized images
*/
Image Image::operator-(const Image& i)
{
    //if the images have different sizes return an empty imave
    if (this->m_width != i.m_width || this->m_height != i.m_height)
    {
        return Image();
    }

    Image rez(i.m_width, i.m_height);

    //substract the elements of the images component wise
    for (int x = 0; x < m_height; x++)
    {
        for (int y = 0; y < m_width; y++)
        {
            int d = int(this->m_data[x][y]) - int(i.m_data[x][y]);
            if (d >= 0 && d <= 255)
                rez.m_data[x][y] = char(d);
            else
            {
                if (d > 255)
                    rez.m_data[x][y] = 255;
                else
                {
                    if (d < 0)
                        rez.m_data[x][y] = 0;
                }
            }
        }
    }
    return rez;
}



/**
* @brief Overloaded operator * and perform element-wise multiplication of two images.
*
* @param i: The second Image used in the multiplication.
*
* @return Image The resulting image after multiplication. Empty if different sized images
*/
Image Image::operator*(const Image& other)
{
    //if the images have different sizes return an empty imave

    if (this->m_width != other.width() || this->m_height != other.height() || this->m_width != this->m_height)
    {
        return Image();
    }

    Image rez(other.m_width, other.m_height);

    for (int i = 0; i < m_height; i++)
    {
        int cont = 0;
        int temp = 0;
        for (int x = 0; x < m_width; x++)
        {
            for (int y = 0; y < m_width; y++)
            {
                temp += int(this->m_data[i][cont % m_width]) * int(other.m_data[y][x]);

                cont++;
            }
            if(temp >= 0 && temp <= 255)
                rez.m_data[i][x] = char(temp);
            else
            {
                if(temp < 0)
                    rez.m_data[i][x] = 0;
                else
                if(temp > 255)
                    rez.m_data[i][x] = 255;
            }

            temp = 0;

        }
    }

    return rez;
}


/**
* @brief Performs the addition between the image and a scalar.
*
* @param scalar: The scalar value to be added.
*
* @return A reference to the resulting image.
*/
Image Image::operator+(const int scalar)
{
    Image rez(this->m_width, this->m_height);
    for (int i = 0; i <  m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            int temp = int(this->m_data[i][j]) + scalar;
            if(temp >= 0 && temp <= 255)
                rez.m_data[i][j] = char(temp);
            else
            {
                if(temp < 0)
                    rez.m_data[i][j] = '0';
                else
                if(temp > 255)
                    rez.m_data[i][j] = '255';
            }
        }
    }
    return rez;
}

/**
* @brief Overloaded operator - between the elements an image and a scalar.
*
* @param scalar: An integer value to be subtracted.
*
* @return A new image object resulting from the subtraction operation.
*/
Image Image::operator-(const int scalar)
{
    Image rez(this->m_width, this->m_height);
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            int temp = int(this->m_data[i][j]) - scalar;
            if (temp >= 0 && temp <= 255)
                rez.m_data[i][j] = char(temp);
            else
            {
                if (temp < 0)
                    rez.m_data[i][j] = 0;
                else
                if (temp > 255)
                    rez.m_data[i][j] = 255;
            }
        }
    }
    return rez;
}


/**
* @brief Overloaded operator * between the elements an image and a scalar.
*
* @param scalar: An integer value to be multiplied.
*
* @return A new image object resulting from the multiplication operation.
*/
Image Image::operator*(const int scalar)
{
    Image rez(this->m_width, this->m_height);
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            int temp = int(this->m_data[i][j]) * scalar;
            if (temp >= 0 && temp <= 255)
                rez.m_data[i][j] = char(temp);
            else
            {
                if (temp < 0)
                    rez.m_data[i][j] = 0;
                else
                if (temp > 255)
                    rez.m_data[i][j] = 255;
            }
        }
    }
    return rez;
}


/**
* @brief Overloaded operator = for assigning one image object to another.
*
* @param other: The image object to be copied.
*
* @return A reference to the current image object.
*/
Image& Image::operator=(const Image& other)
{
    m_width = other.m_width;
    m_height = other.m_height;
    m_data = new unsigned char* [m_height];
    for (int i = 0; i < m_height; i++)
    {
        m_data[i] = new unsigned char[m_width];
        // Copy the data from the original image
        std::memcpy(m_data[i], other.m_data[i], m_width * sizeof(unsigned char));
    }
    return *this;
}


/**
* @brief Check if the image is empty.
*
* @return True, if the image has no height or width, false otherwise.
*/
bool Image::isEmpty() const
{
    return (this->m_height==0 && this->m_width==0 && this->m_data == nullptr);
}

/**
* @brief Returns the size of the image using a Size object.
*
* @return The size of an image.
*/
Size Image::sz() const
{
    return Size(m_width,m_height);
}

/**
* @brief Sets the height of an image
*
* @return void
*/
void Image::setHeight(unsigned int h)
{
    m_height = h;
}

/**
* @brief Sets the width of an image
*
* @return void
*/
void  Image::setWidth(unsigned int w)
{
    m_width = w;
}

/**
* @brief Returns a reference to a specified x,y position in the image.
*
* @param x: The x-coordinate of the position.
* @param y: The y-coordinate of the position.
*
* @return A reference to the pixel value.
*
* @throws std::out_of_range if the specified coordinates are out of bounds.
*/
unsigned char& Image::at(unsigned int x, unsigned int y)
{
    if (x >= m_height || y >= m_width)
        throw std::out_of_range("index out of range");
    return m_data[x][y];
}


/**
* @brief Returns a reference to a specified x,y position in the image.
*
* @param pt: The x-coordinate and y-coordinate of the position.
*
* @return A reference to the pixel value.
*
* @throws std::out_of_range if the specified coordinates are out of bounds.
*/
unsigned char& Image::at(Point pt)
{
    if (pt.getX() >= m_height || pt.getY() >= m_width)
        throw std::out_of_range("index out of range");

    return m_data[pt.getX()][pt.getY()];
}


/**
* @brief Get a pointer to the beggining of a specified row in the image.
*
* @param y: The index of the row to retrieve.
*
* @return A pointer to the beggining of the row.
*/
unsigned char* Image::row(int y)
{
    return m_data[y];
}


/**
* @brief Releases the memory used by the image. 
*
* @return void
*/
void Image::release()
{
    for (unsigned int i = 0; i < m_height; i++)
        delete[] m_data[i];

    delete[] m_data;
    m_data = nullptr;
}


/**
* @brief Gets a region of interest (ROI) from the image and returns it as a new image.
*
* @param roiImg: The new image that will contain the ROI.
* @param roiRect: The rectangle that defines the boundaries of the ROI.
*
* @return true if the ROI is valid and if it was successfully extracted, false otherwise.
*/
bool Image::getROI(Image& roiImg, Rectangle roiRect)
{
    if (roiRect.getX() < 0 || roiRect.getY() < 0 || roiRect.getHeight() + roiRect.getX() > m_height || roiRect.getWidth() + roiRect.getY() > m_width)
    {
        return false;
    }

    //initializes the roiImage with tha same height & width as roiRect

    roiImg = Image(roiRect.getWidth(), roiRect.getHeight());

    for (int i = 0; i < roiRect.getHeight(); i++)
    {
        for (int j = 0; j < roiRect.getWidth(); j++)
        {
            roiImg.at(i,j) = at(roiRect.getX()+i, roiRect.getY() + j);
        }
    }
}


/**
* @brief Gets a region of interest (ROI) from the imageand returns it as a new image.
*
* @param roiImg: The new image that will contain the ROI.
* @param x: The x-coordinate of the top-left corner of the ROI.
* @param y: The y-coordinate of the top-left corner of the ROI.
* @param width: The width of the ROI.
* @param height: The height of the ROI.
*
* @return true if the ROI is valid and if it was successfully extracted, false otherwise.
*/
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    if (x < 0 || y < 0 || height + x > m_height || width + y > m_width)
    {
        return false;
    }

    //initializes the roiImage with tha same height & width as roiRect
    roiImg = Image(width, height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            roiImg.at(i, j) = at(x + i, y + j);
        }
    }
}



/**
* @brief Creates a new image with all values zero.
*
* @param width: image width.
* @param height: image height.
*
* @return Image: A new image with all values zero.
*/
Image Image::zeros(unsigned int width, unsigned int height)
{
    Image rez;
    rez.setWidth(width);
    rez.setHeight(height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            rez.m_data[i][j] = 0;
    return rez;
}


/**
* @brief Creates a new image with all values one.
*
* @param width: image width.
* @param height: image height.
*
* @return Image: A new image with all values one.
*/
Image Image::ones(unsigned int width, unsigned int height)
{
    Image rez = Image(width, height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            rez.m_data[i][j] = '1';
    return rez;
}

/**
* @brief calculates the sum of all elements in a matrix
*
* @return returns the sum calculated.
*/
int Image::sum()
{
    int s = 0;
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
            s += m_data[i][j];
    }

    return s;
}



//--------------- BrightnessAndContrast Class ----------------


/**
* @brief Default constructor for BrightnessAndContrast class. 
* @brief Initializes the alpha to 1 and beta to 0.
*/
BrightnessAndContrast::BrightnessAndContrast()
{
    this->alpha_beta[0] = 1;
    this->alpha_beta[1] = 0;
}

/**
* @brief Sets alpha to a specified value.
*
* @param a: The new alpha value.
* 
* @return void
*/
void BrightnessAndContrast::setAlpha(int a)
{
    alpha_beta[0] = a;
}

/**
* @brief Sets beta to a specified value.
*
* @param b: The new alpha value.
*
* @return void
*/
void BrightnessAndContrast::setBeta(int b)
{
    alpha_beta[1] = b;
}

/**
* @brief Get the alpha value
*
* @return alpha value
*/
int BrightnessAndContrast::getAlpha()
{
    return alpha_beta[0];
}

/**
* @brief Get the beta value
*
* @return beta value
*/
int BrightnessAndContrast::getBeta()
{
    return alpha_beta[1];
}

/**
* @brief Applies brightness and contrast adjustment to an input Image and modifies it.
*
* @param src: The input Image.
* @param dst: The output Image where the adjustments will be saved.
*/
void BrightnessAndContrast::process(Image& src, Image& dst)
{
    dst.setHeight(src.height());
    dst.setWidth(src.width());

    for(int i=0; i< src.height(); i++)
        for (int j = 0; j < src.width(); j++)
        {
            int temp = alpha_beta[0] * int(src.at(i, j)) + alpha_beta[1];

            if(temp>=0 && temp <=255)
                dst.at(i, j) = char(temp);
            else
            {
                if (temp < 0)
                    dst.at(i, j) = 0;
                else
                if(temp >255)
                    dst.at(i, j) = 255;
            }
        }
}

//--------------- GamaCorrection Class ----------------

/**
* @brief Default constructor for the GamaCorrection class. Initializes gama to 1.
*/
GamaCorrection::GamaCorrection()
{
    this->gama = 1;
}

/**
* @brief Set gama value to a specified value.
*
* @param g: The new gama value.
*/
void GamaCorrection::setGama(float a)
{
    this->gama = a;
}

/**
* @brief Get the gama value.
*
* @return Gama.
*/
float GamaCorrection::getGama()
{
    return this->gama;
}


/**
* @brief Applies gamma correction to an input Image object and saves the result in an output Image object.
*
* @param src: The input Image object to be adjusted.
* @param dst: The output Image object where the adjusted image will be saved.
*/
void GamaCorrection::process(Image& src, Image& dst)
{
    dst.setHeight(src.height());
    dst.setWidth(src.width());

    for (int i = 0; i < src.height(); i++)
        for (int j = 0; j < src.width(); j++)
        {
            // Apply gamma correction to the pixel value
            float pixel_value = src.at(i,j);

            //calculate the value that must be added in the new image
            float corrected_value = pow(pixel_value, gama);

            if (corrected_value > 255)
            {
                dst.at(i, j) = 255;
            }
            else
            {
                // Save the corrected pixel value to the output image
                dst.at(i, j) = corrected_value;
            }
        }
}


//------------ ImageConvolution Class ------------------

/**
* @brief Default constructor for the ImageConvolution class. 
  @brief Initializes the kernel to the Identity kernel.
*/
ImageConvolution::ImageConvolution()
{
    value = 1;
    // initialize the kernal with the identity kernal
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                k[i][j] = 1;
            else
                k[i][j] = 0;
        }
    }
}

/**
* @brief Sets the kernel to a specified type.
*
* @param type: The type of kernel to set. Possible values are "ik" (Identity kernel), "mbk" (Mean blur kernel),
* "gbk" (Gaussian blur kernel), "hsk" (Horizontal Sobel kernel), and "vsk" (Vertical Sobel kernel).
*
* @return void
*/
void ImageConvolution::setKernal(std::string type)
{
    if (type == "ik")
    {
        value = 1;
        // initialize the kernal with the identity kernal
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                    k[i][j] = 1;
                else
                    k[i][j] = 0;
            }
        }
    }
    else
    {
        if (type == "mbk")
        {
            value = 9;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    k[i][j] = 1;
                }
            }
        }
        else
        {
            if (type == "gbk")
            {
                value = 16;
                k[0][0] = 1;
                k[0][2] = 1;
                k[2][0] = 1;
                k[2][2] = 1;

                k[0][1] = 2;
                k[1][0] = 2;
                k[1][2] = 2;
                k[2][1] = 2;

                k[1][1] = 4;
            }
            else
            {
                if (type == "hsk")
                {
                    k[0][0] = 1;
                    k[0][1] = 2;
                    k[0][2] = 1;

                    k[1][0] = 0;
                    k[1][1] = 0;
                    k[1][2] = 0;

                    k[2][0] = -1;
                    k[2][1] = -2;
                    k[2][2] = -1;
                }
                else
                {
                    if (type == "vsk")
                    {
                        k[0][0] = 1;
                        k[1][0] = 2;
                        k[2][0] = 1;

                        k[0][1] = 0;
                        k[1][1] = 0;
                        k[2][1] = 0;

                        k[0][2] = -1;
                        k[1][2] = -2;
                        k[2][2] = -1;
                    }
                }
            }
        }
    }
}

/**
* @brief Gets the value of the kernel at the point of coordinates i and j.
*
* @param i: The row of the kernel.
* @param j: The column of the kernel.
* 
* @return the value of the kernel at the point of coordinates i and j
*/
int ImageConvolution::getKernel(int i, int j)
{
    return k[i][j];
}

/**
* @brief Gets the value of the number the kernal will be divided to.
*
* @return the value of the number the kernal will be divided to
*/
int ImageConvolution::getValue()
{
    return value;
}

/**
* @brief transforms a kernel in to an Image
*
* @return the karnal as an image
*/
Image ImageConvolution::transormToImg()
{
    Image newImg(3,3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            newImg.at(i,j) = k[i][j];
        }
    }

    return newImg;
}

/**
* @brief Apply convolution to the source image using the 
* @brief and stores the result in the destination image.
*
* @param src: The source image.
* @param dst: The destination image.
* 
* @return void
*/
void ImageConvolution::process(Image& src, Image& dst)
{
    Size s = src.sz();
    int x = s.height - 2;
    int y = s.width - 2;
    Image a(y,x);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            Image d;
            src.getROI(d, i, j, 3, 3);
            Image t = transormToImg();

            a.at(i,j) = (float)((d * t).sum()) / value;
        }
    }

    dst = a;
}


//---------------------Drawing---------------------//


/**
* @brief Draws a circle on an image
*
* @param img: The image where the rectangle will be drawn.
* @param center: The circle's center given as a Point
* @param radius: The circle's radius
* @param color: he color that will be used
*/
void Drawing::drawCircle(Image& img, Point center, int radius, unsigned char color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (y >= x)
    {
        img.at(center.getY() + y,center.getX() + x) = color;
        img.at(center.getY() + x, center.getX() + y) = color;
        img.at(center.getY() + y, center.getX() - x) = color;
        img.at(center.getY() + x, center.getX() - y) = color;
        img.at(center.getY() - y, center.getX() + x) = color;
        img.at(center.getY() - x, center.getX() + y) = color;
        img.at(center.getY() - y, center.getX() - x) = color;
        img.at(center.getY() - x, center.getX() - y) = color;

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}


/**
 * @brief Draws a line on the given image between two specified points using a given color.
 *
 * This function utilizes Bresenham's line algorithm to draw a straight line between 
 * two specified points grid of X and Y coordinates. The algorithm uses integer arithmetic 
 * to avoid floating-point calculations and minimizes the error between the intended 
 * line and the line being drawn.
 *
 * @param img: The image on which to draw the line.
 * @param p1: The starting point of the line.
 * @param p2: The ending point of the line.
 * @param color: The color to use for the line.
 */
void Drawing::drawLine(Image& img, Point p1, Point p2, unsigned char color)
{
    // Get the x and y coordinates of the two points
    int x1 = p1.getX();
    int y1 = p1.getY();
    int x2 = p2.getX();
    int y2 = p2.getY();

    // Calculate the absolute differences in x and y coordinates
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Determine the sign of the x and y directions
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    // Calculate the initial error
    int err = dx - dy;

    // Bresenham's line algorithm
    // Loop through each pixel on the line between the two points
    while (true)
    {
        // Set the color of the current pixel to the given color
        img.at(y1, x1) = color;

        // Check if the end point has been reached
        if (x1 == x2 && y1 == y2)
        {
            // Exit the loop
            break;
        }

        // Calculate the double error
        int e2 = 2 * err;

        // Update the error and x coordinate if the error is greater than -dy
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        // Update the error and y coordinate if the error is less than dx
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/**
 * @brief Draws a rectangle on a given image using a given color.
 *
 * @param img: The image where the rectangle will be drawn.
 * @param r: The rectangle that will be drawn.
 * @param color: The color that will be used.
 */
void Drawing::drawRectangle(Image& img, Rectangle r, unsigned char color)
{
    // Get the coordinates and dimensions of the rectangle
    int x = r.getX();
    int y = r.getY();
    int w = r.getWidth();
    int h = r.getHeight();

    // Draw the top and bottom lines of the rectangle
    drawLine(img, Point(x, y), Point(x + w, y), color);
    drawLine(img, Point(x, y + h), Point(x + w, y + h), color);

    // Draw the left and right lines of the rectangle
    drawLine(img, Point(x, y), Point(x, y + h), color);
    drawLine(img, Point(x + w, y), Point(x + w, y + h), color);
}

/**
 * @brief Draws a rectangle on a given image using a given color.
 *
 * @param img: The image where the rectangle will be drawn.
 * @param tl: The top-left point of the rectangle.
 * @param br: The bottom-right point of the rectangle.
 * @param color: The color that will be used.
 */
void Drawing::drawRectangle(Image& img, Point tl, Point br, unsigned char color)
{
    // Get the x and y coordinates of the top-left and bottom-right points
    int x1 = tl.getX();
    int y1 = tl.getY();
    int x2 = br.getX();
    int y2 = br.getY();

    // Calculate the width and height of the rectangle
    int w = x2 - x1;
    int h = y2 - y1;

    // Draw the top and bottom lines of the rectangle
    drawLine(img, Point(x1, y1), Point(x2, y1), color);
    drawLine(img, Point(x1, y2), Point(x2, y2), color);

    // Draw the left and right lines of the rectangle
    drawLine(img, Point(x1, y1), Point(x1, y2), color);
    drawLine(img, Point(x2, y1), Point(x2, y2), color);
}