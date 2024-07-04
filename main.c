#include <stdint.h>
#include <stdio.h>

#define OK 0
#define INCORRECT_FILE_FORMAT 1
#define COULDNT_OPEN_FILE 2
#define NO_PATH_TO_FILE 3

static int ReadFile(char const *const filename)
{
    char *compression_types[] = {"none", "8-bit RLE algorithm was used", "4-bit RLE algorithm was used", "bitfields encoding was used"};

    uint32_t image_data_address;
    int32_t width;
    int32_t height;
    uint32_t pixel_count;
    uint16_t bits_per_pixel;
    uint8_t byte_depth;
    uint32_t *pixels;
    uint32_t image_size;
    uint16_t planes;
    uint32_t compression;
    uint32_t x_pixels_per_meter;
    uint32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;

    FILE *image = fopen(filename, "rb");
    if (!image)
    {
        printf("Could not open the file %s.", filename);
        fclose(image);
        return COULDNT_OPEN_FILE;
    }
    else
    {
        if (fgetc(image) == 'B' && fgetc(image) == 'M')
        {
            fread(&image_size, 4, 1, image);
            fseek(image, 12, SEEK_CUR);
            fread(&width, 4, 1, image);
            fread(&height, 4, 1, image);
            fread(&planes, 2, 1, image);
            fread(&bits_per_pixel, 2, 1, image);
            fread(&compression, 4, 1, image);
            fseek(image, 4, SEEK_CUR);
            fread(&x_pixels_per_meter, 4, 1, image);
            fread(&y_pixels_per_meter, 4, 1, image);
            fread(&colors_used, 4, 1, image);
            fread(&colors_important, 4, 1, image);
            printf("Width          	 : %d\n", width);
            printf("Height           : %d\n", height);
            printf("Planes           : %d\n", planes);
            printf("Bits/pixel       : %d\n", bits_per_pixel);
            printf("Compression      : %s\n", compression_types[compression]);
            printf("Image Size       : %d\n", image_size);
            printf("Pixels/meter     : %dx%d\n", x_pixels_per_meter, y_pixels_per_meter);
            printf("Colors used      : %d\n", colors_used);
            printf("Colors important : %d\n", colors_important);
        }
        else
        {
            printf("File %s is not a BMP file\n", filename);
            return INCORRECT_FILE_FORMAT;
        }
    }
    return OK;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Example of usage:\n./bmp_header_reader <path-to-image>");
        return NO_PATH_TO_FILE;
    }
    const char *const filename = argv[1];
    ReadFile(filename);
    return 0;
}

