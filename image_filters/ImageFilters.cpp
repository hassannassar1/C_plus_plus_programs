#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

class Filters
{
    private:
        int sobel_x[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}}; // Gx filter
        int sobel_y[3][3] = {{-1,-2,-1}, {0,0,0}, {1,2,1}}; // Gy filter
        int avg_filter[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}}; // Box blur filter
    public:
        Filters()
        {
        }

        /**
         * Take path string and return image.
         *
         * @param path Path to the image.
         * @return return Image.
         */
        Mat read_img(String path)
        {
            Mat img = imread(path); 
            return img;
        }

        /**
         * Applying Sobel Filter on gray_scale image or a channel of BGR image.
         *
         * @param img Image to be filtered.
         * @return return Sobel filtered Image.
         */
        Mat sobel_filter(Mat img)
        {
            Mat newimg = Mat::zeros(img.size(), img.type());

            // Loop over rows
            for (int j = 0; j<img.rows-2; j++) 
                {
                // Loop over columns
                for (int i = 0; i<img.cols-2; i++)
                {
                    // Calculate Gx of a pixel.
                    int pixval_x =
                    (sobel_x[0][0] * (int)img.at<uchar>(j,i)) + (sobel_x[0][1] * (int)img.at<uchar>(j+1,i)) + (sobel_x[0][2] * (int)img.at<uchar>(j+2,i)) +
                    (sobel_x[1][0] * (int)img.at<uchar>(j,i+1)) + (sobel_x[1][1] * (int)img.at<uchar>(j+1,i+1)) + (sobel_x[1][2] * (int)img.at<uchar>(j+2,i+1)) +
                    (sobel_x[2][0] * (int)img.at<uchar>(j,i+2)) + (sobel_x[2][1] * (int)img.at<uchar>(j+1,i+2)) + (sobel_x[2][2] * (int)img.at<uchar>(j+2,i+2));
                    
                    // Calculate Gy of a pixel.

                    int pixval_y =
                    (sobel_y[0][0] * (int)newimg.at<uchar>(j,i)) + (sobel_y[0][1] * (int)newimg.at<uchar>(j+1,i)) + (sobel_y[0][2] * (int)newimg.at<uchar>(j+2,i)) +
                    (sobel_y[1][0] * (int)newimg.at<uchar>(j,i+1)) + (sobel_y[1][1] * (int)newimg.at<uchar>(j+1,i+1)) + (sobel_y[1][2] * (int)newimg.at<uchar>(j+2,i+1)) +
                    (sobel_y[2][0] * (int)newimg.at<uchar>(j,i+2)) + (sobel_y[2][1] * (int)newimg.at<uchar>(j+1,i+2)) + (sobel_y[2][2] * (int)newimg.at<uchar>(j+2,i+2));
                    
                    // Calculate sum |Gx| + |Gy|
                    int sum = abs(pixval_x) + abs(pixval_y);

                    // For best performance, Check for pixels greater than 255.
                    if (sum > 255)
                    {
                        sum = 255; 
                    }
                    // Assign the new value to the new image.
                    newimg.at<uchar>(j,i) = sum;
                }
                }
            return newimg;
        }

        /**
         * Applying Box blur filter on gray_scale image or a channel of BGR image.
         *
         * @param img Image to be filtered.
         * @return return Box blured filtered Image.
         */
        Mat box_filter(Mat img)
        {
            Mat newimg = Mat::zeros(img.size(), img.type());

            // Loop over rows.
            for (int j = 0; j<img.rows-2; j++)
                {
                    // Loop over columns
                    for (int i = 0; i<img.cols-2; i++)
                    {
                        // Calculate sum of the new pixel values
                        int pixval =
                        (avg_filter[0][0] * (int)img.at<uchar>(j,i)) + (avg_filter[0][1] * (int)img.at<uchar>(j+1,i)) + (avg_filter[0][2] * (int)img.at<uchar>(j+2,i)) +
                        (avg_filter[1][0] * (int)img.at<uchar>(j,i+1)) + (avg_filter[1][1] * (int)img.at<uchar>(j+1,i+1)) + (avg_filter[1][2] * (int)img.at<uchar>(j+2,i+1)) +
                        (avg_filter[2][0] * (int)img.at<uchar>(j,i+2)) + (avg_filter[2][1] * (int)img.at<uchar>(j+1,i+2)) + (avg_filter[2][2] * (int)img.at<uchar>(j+2,i+2));
                        
                        // assign the new pixel values to the new image after averaging it.
                        newimg.at<uchar>(j,i) = pixval/9;
                    }
                }
            return newimg;
        }

        /**
         * Applying colored Sobel filter BGR image.
         *
         * @param img Image to be filtered.
         * @return return colored Sobel filtered Image.
         */
        Mat colored_sobel(Mat img)
        { 
            Mat output = Mat::zeros(img.size(), img.type());
            Mat channels[3];
            Mat blured_img[3];
            Mat newimg[3];

            // Use opencv to split channels
            split(img, channels);
            
            // Loop over channels
            for(int i=0; i<3; i++)
            {
                blured_img[i] = box_filter(channels[i]);
                newimg[i] = sobel_filter(blured_img[i]);
            }

            // Use opencv to merge channels again
            merge(newimg, 3, output);

            return output; 
        }
        
        /**
         * Check for specific color and replace it with Black color.
         *
         * @param img Image to be filtered.
         * @param color Array contains the BGR values of the color.
         * @return return a new image with the new colors.
         */
        Mat remove_color(Mat img, int *color)
        {
            Mat newimg = Mat::zeros(img.size(), img.type());
            Mat channels[3];

            // Use opencv to split channels
            split(img, channels);

            // Loop over rows
            for (int j = 0; j<img.rows; j++)
                {
                    // Loop over columns
                    for (int i = 0; i<img.cols; i++)
                    {
                        int b = (int)channels[0].at<uchar>(j,i);
                        int g = (int)channels[1].at<uchar>(j,i);
                        int r = (int)channels[2].at<uchar>(j,i);
                        
                        // Check for given color
                        if (b==color[0] && g==color[1] && r==color[2])
                        {
                            channels[0].at<uchar>(j,i) = 0;
                            channels[1].at<uchar>(j,i) = 0;
                            channels[2].at<uchar>(j,i) = 0;
                        }
                        
                    }
                }
            merge(channels, 3, newimg);
            
            return newimg;

        }
};


int main(int argc, char** argv)
{
    // Load an image
    String path ;
    
    // If an image passed from the user
    if (argv[1] && string(argv[1])!="") 
    {
        path = argv[1];
    }

    // If no image passed from the user
    else 
    {
        path ="/home/hassan/Downloads/sobel/image-1.png"; // Use a default path
    }

    // Define object from Filters class that contains our operations
    Filters filters;
    
    // Load the image
    Mat img = filters.read_img(path);
    cout<<argv[2]<<" "<<argv[1];

    // Apply Orange Color Removal
    if (argv[2] && string(argv[2])=="color")
    {
        int color_to_remove[3] = {39, 127, 255}; // Remember to send in as (B, G, R).
        Mat output1 = filters.remove_color(img, color_to_remove);

        // display the images
        namedWindow("Removed Color Image", WINDOW_AUTOSIZE);
        imshow("Removed Color Image", output1);
        imwrite("removed_color.png", output1);
        waitKey(0);
        return 0;
    }

    // Apply Colored Sobel filter
    else
    {
    Mat output = filters.colored_sobel(img);
    
    // display the images
    namedWindow("Sobel Filtered Image", WINDOW_AUTOSIZE);
    imshow("Sobel Filtered Image", output);
    imwrite("sobel.png", output);
    waitKey(0);
    return 0;
    }
}

