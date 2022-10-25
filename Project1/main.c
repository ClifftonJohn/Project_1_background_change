#include <math.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./headers/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./headers/stb_image_write.h"

/**
 * Create a new 1-dimensional array with the given size
 * @param[in] _size the size of the array
 * @param[out] _ empty 1-dimensional array filled with 0
 *
*/

/**
 * We need to delete the part of forecast
 * @param[in] image the input image
 * @param[in] width the width of the image
 * @param[in] height the height of the image
 * @param[in] channel the channel of the image (1)
 */

unsigned char *Pic_1d(int _size)
{
    return (unsigned char *)calloc(_size, sizeof(unsigned char));
}

// Producing new image
unsigned char * image_background_elimination(unsigned char *image_1, unsigned char* image_2, unsigned char* image_3, int width, int height, int channel)
{
    unsigned char *delete = Pic_1d(width * height * channel);
    for(int i = 0; i < height; i++)
{
        for(int j = 0; j < width; j++)
        {
            int differ = 0.0;
            for(int k = 0; k < channel; k++)
            {
                differ = differ + abs(image_2 [ i * width * channel + j * channel + k ] -  image_1 [ i * width * channel + j * channel + k ]);
            }
            if(differ < 160)
            {
                for(int k = 0; k < channel; k++)
                {
                    image_2 [ i * width * channel + j * channel + k ] = image_3 [ i * width * channel + j * channel + k ];
                }   
                delete = image_2;     
            }
        }
    }
    return delete;
}
//Fixing the transparrent issue of the final picture

/**
 * Rotate image with arbitrary angle
 * @param[in] image image to be rotated
 * @param[in] width width of image
 * @param[in] height height of image
 * @param[in] channel channel of image
 * @param[in] degree angle of rotation (2)
 * @param[out] _ rotated image
 */

int main()
{
    // Declare variables of the images
    int width, height, channel;

    // Since we have already had "resize.py" func, we can use it directly.
    // "./address/filename.""
    char pic_1[] = "C:/Users/THONG LOC/Desktop/C,C++/VGU-CA/CSE2021 - Programming 1/Project1/images1/background.png";
    char pic_2[] = "C:/Users/THONG LOC/Desktop/C,C++/VGU-CA/CSE2021 - Programming 1/Project1/images1/foreground.png";
    char pic_3[] = "C:/Users/THONG LOC/Desktop/C,C++/VGU-CA/CSE2021 - Programming 1/Project1/images1/new_background.png";
    char pic_final[] = "C:/Users/THONG LOC/Desktop/C,C++/VGU-CA/CSE2021 - Programming 1/Project1/images1/new_pic.png";

    // Reading image data
    // Using library
    unsigned char *image_1 = stbi_load(pic_1, &width, &height, &channel, 0);
    if (image_1 == NULL)
    {
        printf("\nError in loading the image\n");
        exit(1);
        //Skip to the next code line
    }
printf("The data of image 1:\n");
printf("Width = %d\nHeight = %d\nChannel = %d\n", width, height, channel);
    
    unsigned char *image_2 = stbi_load(pic_2, &width, &height, &channel, 0);
    if (image_2 == NULL)
    {
        printf("\nError in loading the image\n");
        exit(1);
    }
printf("The data of image 2:\n");
printf("Width = %d\nHeight = %d\nChannel = %d\n", width, height, channel);
    
    unsigned char *image_3 = stbi_load(pic_3, &width, &height, &channel, 0);
    if (image_3 == NULL)
    {
        printf("\nError in loading the image\n");
        exit(1);
    }
printf("The data of image 3:\n");
printf("Width = %d\nHeight = %d\nChannel = %d\n", width, height, channel);
    
unsigned char * res = image_background_elimination(image_1, image_2, image_3, width, height, channel);
// Make a new image.
// Save image
stbi_write_png (pic_final , width , height , channel , res , width * channel );
printf (" New image saved to %s\n", pic_final );
printf("\nDone.....\n");
return 0;
}