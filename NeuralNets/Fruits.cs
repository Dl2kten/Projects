using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NeuralNets
{
    class Fruits
    {
        String[][] imgs;
        byte[][] data;
        byte[][] blankD;
        //byte[][] newB;
        byte[][] pixel;
        byte[] raw;
        byte label;
        TrainingData tData;
        double[][][][] trainingData;

        public Fruits()
        {
           
        }

        /// <summary>
        /// Get jpeg of training images
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        public int getFiles(string file_Path)
        {
            String filePath = file_Path;
            String[] files = null;

            if (Directory.Exists(filePath))
            {
                files = Directory.GetDirectories(filePath, "*.*", SearchOption.AllDirectories);
            }

            if (files == null)
            {
                return 1;
            }
            else
            {
                imgs = new String[files.Length][];
            }
            //get all images in directory
            for (int i = 0; i < files.Length; i++)
            {
                imgs[i] = Directory.GetFiles(files[i], "*.jpg", SearchOption.AllDirectories);
            }
            
            //Below are instantiation of the arrays
            Bitmap srcImage = new Bitmap(imgs[0][0]);

            int newWidth = 50;
            int newHeight = 50;

            Bitmap b = new Bitmap(newWidth, newHeight);
            using (Graphics gr = Graphics.FromImage(b))
            {
                gr.SmoothingMode = SmoothingMode.HighQuality;
                gr.InterpolationMode = InterpolationMode.HighQualityBicubic;
                gr.PixelOffsetMode = PixelOffsetMode.HighQuality;
                gr.DrawImage(srcImage, new Rectangle(0, 0, newWidth, newHeight));
            }

            data = new byte[b.Height][];

            for (int i = 0; i < data.Length; i++)
            {
                data[i] = new byte[b.Width];
            }

            blankD = new byte[b.Height][];

            for (int i = 0; i < blankD.Length; i++)
            {
                blankD[i] = new byte[b.Width];
            }

            pixel = new byte[b.Height][];
            for (int i = 0; i < b.Height; i++)
            {
                pixel[i] = new byte[b.Width];
            }

            raw = new byte[3 * b.Width * b.Height];


            int sum = 0;
            //Divide data into four sections
            for (int i = 0; i < 13; i++)
            {
                sum += imgs[i].Length;
            }

            //set amount of data
            trainingData = new double[sum][][][];

            return 0;
        }

        /// <summary>
        /// Changes jpgs to input and output data sets
        /// </summary>
        public void toBytes(int section)
        {
            Bitmap srcImage;
            int count = 0;
            

            //get jpg data and set label
            for (int i = 0 + 13 * section; i < 13 * (section + 1); i++)
            {
                for(int j = 0; j < imgs[i].Length; j++)
                {
                    srcImage = new Bitmap(imgs[i][j]);
                    int newWidth = 50;
                    int newHeight = 50;

                    Bitmap b = new Bitmap(newWidth, newHeight);
                    using (Graphics gr = Graphics.FromImage(b))
                    {
                        gr.SmoothingMode = SmoothingMode.HighQuality;
                        gr.InterpolationMode = InterpolationMode.HighQualityBicubic;
                        gr.PixelOffsetMode = PixelOffsetMode.HighQuality;
                        gr.DrawImage(srcImage, new Rectangle(0, 0, newWidth, newHeight));
                    }

                    byte[][] temp = rgbToGrey(b);
                    tData = new TrainingData(0, blankD, imgs.Length, 100);

                    label = (byte)i;


                    tData.setData(temp);
                    tData.setLabel(label);

                    trainingData[count] = tData.getTraining();

                    count++;
                    //File.WriteAllBytes("Foo.txt", arrBytes);
                    //File.WriteAllBytes("Foo.txt", arrBytes.ToArray());

                }
            }

            shuffleArray(trainingData);
        }

        /// <summary>
        /// A faster way to get rgb values from jpg?
        /// </summary>
        /// <param name="bmp"></param>
        /// <returns></returns>
        private byte[] getBytes(Bitmap bmp)
        {
            if (bmp == null)
                throw new ArgumentNullException("bmp");
            if (bmp.PixelFormat != PixelFormat.Format24bppRgb)
                throw new InvalidOperationException("Image format not supported.");

            BitmapData data;

            //Lock the bitmap so we can access the raw pixel data
            data = bmp.LockBits(new Rectangle(0, 0, bmp.Width, bmp.Height),
                                ImageLockMode.ReadOnly, bmp.PixelFormat);

            //Accessing pointers must be in an unsafe context
            unsafe
            {
                int r, c,
                    w = bmp.Width,
                    h = bmp.Height,
                    bmpStride = data.Stride,
                    rawStride = 3 * w;
                byte* bmpPtr = (byte*)data.Scan0.ToPointer();

                //Allocate the raw byte buffer
                fixed (byte* rawPtr = raw)
                {
                    //Scan through the image and copy each pixel
                    for (r = 0; r < h; ++r)
                        for (c = 0; c < rawStride; c += 3)
                        {
                            rawPtr[r * rawStride + c] = bmpPtr[r * bmpStride + c];
                            rawPtr[r * rawStride + c + 1] = bmpPtr[r * bmpStride + c + 2];
                            rawPtr[r * rawStride + c + 2] = bmpPtr[r * bmpStride + c + 2];
                        }
                }
            }
            bmp.UnlockBits(data);

            return raw;
        }

        /// <summary>
        /// Format 1d array to 2d array
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        private void format2d(byte[] b)
        {

            for (int i = 0; i < b.Length; i++)
            {
                //newB[i][0] = b[i];
            }

        }

        public byte[][] rgbToGrey(Bitmap input)
        {

            for (int x = 0; x < input.Width; x++)
            {
                for (int y = 0; y < input.Height; y++)
                {
                    Color pixelColor = input.GetPixel(x, y);
                    //  0.3 · r + 0.59 · g + 0.11 · b
                    double grey = pixelColor.R * 0.3 + pixelColor.G * 0.59 + pixelColor.B * 0.11;
                    pixel[y][x] = (byte)(grey);
                }
            }

            return pixel;
        }

        /// <summary>
        /// Shuffles indices around, account for aliases
        /// </summary>
        /// <param name="array"></param>
        /// <returns></returns>
        private double[][][][] shuffleArray(double[][][][] array)
        {
            int index;
            double[][][] temp = new double[array[0].Length][][];
            Random random = new Random();

            for (int i = 0; i < temp.Length; i++)
            {
                temp[i] = new double[array[0][i].Length][];
            
                for (int j = 0; j < temp[i].Length; j++)
                {
                    temp[i][j] = new double[array[0][i][j].Length];
                }
            }

            for (int i = array.Length - 1; i > 0; i--)
            {
                index = random.Next(i);

                //temp = array[index]
                for (int l = 0; l < temp.Length; l++)
                {
                    for (int j = 0; j < temp[l].Length; j++)
                    {
                        for (int k = 0; k < temp[l][j].Length; k++)
                        {
                            temp[l][j][k] = array[index][l][j][k];
                        }
                    }
                }

                //array[index] = array[i]
                for (int l = 0; l < array[index].Length; l++)
                {
                    for (int j = 0; j < array[index][l].Length; j++)
                    {
                        for (int k = 0; k < array[index][l][j].Length; k++)
                        {
                            array[index][l][j][k] = array[i][l][j][k];
                        }
                    }
                }

                //array[i] = temp
                for (int l = 0; l < temp.Length; l++)
                {
                    for (int j = 0; j < temp[l].Length; j++)
                    {
                        for (int k = 0; k < temp[l][j].Length; k++)
                        {
                            array[i][l][j][k] = temp[l][j][k];
                        }
                    }
                }
            }

            return array;
        }

        /// <summary>
        /// Make sure not all data are same
        /// </summary>
        /// <returns></returns>
        public int checkForAlias()
        {
            int result = 0;

            for (int i = 0; i < data.Length - 1; i++)
            {
                for (int j = 0; j < data[i].Length; j++)
                {
                    if(data[i][j] != data[i + 1][j])
                    {
                        result = 1;
                        return result;
                    }
                }
            }

            return result;
        }

        public double[][][][] getTrainingData()
        {
            return trainingData;
        }
    }
}
