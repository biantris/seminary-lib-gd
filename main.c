/* Bring in gd library functions */
#include "gd.h"

/* Bring in standard I/O so we can output the PNG to a file */
#include <stdio.h>

int main() {
  /* Declare the image */
  gdImagePtr im;
  /* Declare output files */
  FILE *pngout, *jpegout;
  /* Declare color indexes */
  int red;
  int white;

  /* Allocate the image: 64 pixels across by 64 pixels tall */
  im = gdImageCreate(500, 200);

  /* Allocate the color black (red, green and blue all minimum).
    Since this is the first color in a new image, it will
    be the background color. */
  red = gdImageColorAllocate(im, 255, 0, 0);

  /* Allocate the color white (red, green and blue all maximum). */
  white = gdImageColorAllocate(im, 255, 255, 255);

  /* Draw a line from the upper left to the lower right,
    using white color index. */
  gdImageLine(im, 500, 0, 0, 0, white);

  gdImageLine(im, 0, 0, 0, 500, white);



  gdImageLine(im, 50, 0, 50, 500, white);

  gdImageLine(im, 100, 0, 100, 500, white);

  gdImageLine(im, 150, 0, 150, 500, white);

  gdImageLine(im, 200, 0, 200, 500, white);
  
  gdImageLine(im, 250, 0, 250, 500, white);

  gdImageLine(im, 250, 0, 250, 500, white);

  gdImageLine(im, 300, 0, 300, 500, white);

  gdImageLine(im, 350, 0, 350, 500, white);

  gdImageLine(im, 400, 0, 400, 500, white);

  gdImageLine(im, 450, 0, 450, 500, white);

  /* Open a file for writing. "wb" means "write binary", important
    under MSDOS, harmless under Unix. */
  pngout = fopen("test.png", "wb");

  /* Do the same for a JPEG-format file. */
  jpegout = fopen("test.jpg", "wb");

  /* Output the image to the disk file in PNG format. */
  gdImagePng(im, pngout);

  /* Output the same image in JPEG format, using the default
    JPEG quality setting. */
  gdImageJpeg(im, jpegout, -1);

  /* Close the files. */
  fclose(pngout);
  fclose(jpegout);

  /* Destroy the image in memory. */
  gdImageDestroy(im);
}