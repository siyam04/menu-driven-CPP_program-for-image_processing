#include<bits/stdc++.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


/// Menu and selection functions
void displayMenu();
int getSelection();

/// Image processing functions
int erodeImage();
int dilateImage();
int openingImage();
int closingImage();


/// Main
int main()
{
    int menu = 0;

    while(menu != 5)
    {
        displayMenu();

        menu = getSelection();

        switch (menu)
        {
            case 1:
                erodeImage();
                break;

            case 2:
                dilateImage();
                break;

            case 3:
                openingImage();
                break;

            case 4:
                closingImage();
                break;

            case 5:
                cout << "Exit Successful. Thank You." << endl;
                break;

            default:
                cout << "**Please Select the Valid Menu and Try Again..." << endl;
                break;
        }
    }

}


// Display menu
void displayMenu()
{
    cout << "\n----------------------------------------" << endl;
    cout << "MENU" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1 = Eroding Image (Thin Shape-Background Expansion) " << endl;
    cout << "2 = Dilating Image (Fat Shape-Foreground Expansion)" << endl;
    cout << "3 = Remove Dots from BackGround (Opening)" << endl;
    cout << "4 = Remove Dots from Image (Closing)" << endl;
    cout << "5 = Quit" << endl;
}


// Selecting menu
int getSelection()
{
    string input;

    cout << "\nEnter Your Choice:" << endl;
    cin >> input;

    if (input.length() == 1 && (input == "1" || input == "2" || input == "3" || input == "4" || input == "5"))
    {
        // converts string input to integer. Because return type of this function is integer.
        return input[0]-'0';
    }
    else
    {

        cout << "**INPUT ERROR!" << endl;
        return -1;

    }

}


/// Thin shape of image. BACKGROUND Expansion.
int erodeImage()
{
    Mat image1, output1;

    image1 = imread("j-e.png", 0);

    if(! image1.data)
    {
        cout << "Could not open or find the image!" <<endl;
        return -1;
    }

    imshow("Window 1", image1);

    erode(image1, output1, getStructuringElement(MORPH_RECT, Size(5, 5)));

    imshow("Window 2", output1);

    imwrite("erode_result_siyam.png", output1);

    waitKey(0);
    return 0;
}


/// Fat shape of image. FOREGROUND Expansion.
int dilateImage()
{
    Mat image2, output2;

    image2 = imread("j-d.png", 0);

    if(! image2.data)
    {
        cout << "Could not open or find the image!" <<endl;
        return -1;
    }

    imshow("Window 1", image2);

    dilate(image2, output2, getStructuringElement(MORPH_RECT, Size(5, 5)));

    imshow("Window 2", output2);

    imwrite("dilate_result_siyam.png", output2);

    waitKey(0);
    return 0;
}


/// Removes the dots from background of an image (opening)
int openingImage()
{
    Mat image3, output3;

    image3 = imread("opening.png", 0);

    if(! image3.data)
    {
        cout << "Could not open or find the image!" <<endl;
        return -1;
    }

    imshow("Window 1", image3);

    morphologyEx(image3, output3, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(5, 5)));

    imshow("Window 2", output3);

    imwrite("opening_result_siyam.png", output3);

    waitKey(0);
    return 0;
}


/// Removes the dots from image (closing)
int closingImage()
{
    Mat image4, output4;

    image4 = imread("closing.png", 0);

    if(! image4.data)
    {
        cout << "Could not open or find the image!" <<endl;
        return -1;
    }

    imshow("Window 1", image4);

    morphologyEx(image4, output4, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(5, 5)));

    imshow("Window 2", output4);

    imwrite("closing_result_siyam.png", output4);

    waitKey(0);
    return 0;
}



