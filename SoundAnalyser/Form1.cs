using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;
using System.Diagnostics;
using System.Threading;

namespace Interface
{
    public partial class Form1 : Form
    {
        //consider just using byte buffer, change to ms
        [DllImport("dllAssignment.dll")]
        public static extern void mDBox();

        [DllImport("dllAssignment.dll")]
        public static extern IntPtr getBuffer();

        [DllImport("dllAssignment.dll")]
        public static extern int getLength();

        [DllImport("dllAssignment.dll")]
        //public static extern void setBuffer(byte[] pBuffer);
        public static extern void setBuffer(IntPtr pBuffer);

        [DllImport("dllAssignment.dll")]
        public static extern void setLength(int dwLength);

        [DllImport("dllAssignment.dll")]
        public static extern double getSampleRate();

        private TimeGraph TChild;
        private TimeGraph2 TChild2;
        private Frequency fChild;
        private Frequency2 fChild2;
        private bool opened, leftChannel, rightChannel;
        private double[] ptsX, ptsY, originalX, originalY, re, im,
            ptsXRight, ptsYRight;
        private double time, samples;

        private static int fileSamples, chunkID, riffType, fileSize,
            fmtID, fmtSize, fileSampleRate, fmtAvgBPS, data, dataSize;

        private static short channels, formatCode, fmtBlockAlign, bitDepth;

        private static short[] left, right;
        /// <summary>
        /// Main parent window to hold all child windows
        /// </summary>
        public Form1()
        {
            opened = false;
            leftChannel = false;
            rightChannel = false;
            time = 0;
            samples = 0;

            Random generator = new Random();

            InitializeComponent();
            TChild = new TimeGraph();
            // Set the Parent Form of the Child window.  
            TChild.MdiParent = this;
            // Display the new form.
            TChild.StartPosition = FormStartPosition.Manual;
            TChild.Location = new Point(0, 0);
            TChild.Show();

            TChild2 = new TimeGraph2();
            TChild2.MdiParent = this;
            TChild2.StartPosition = FormStartPosition.Manual;
            TChild2.Location = new Point(750, 0);
            TChild2.Show();

            fChild = new Frequency();
            fChild.MdiParent = this;
            fChild.StartPosition = FormStartPosition.Manual;
            fChild.Location = new Point(0, 495);
            fChild.Show();

            fChild2 = new Frequency2();
            fChild2.MdiParent = this;
            fChild2.StartPosition = FormStartPosition.Manual;
            fChild2.Location = new Point(455, 495);
            fChild2.Show();
        }
        /**
         * OpenRecorder menu option opens dll recorder
         * @param sender from the window
         * @param e events
         * */
        private void openRecorderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (opened == true)
            {
                Console.WriteLine("already open");
                return;
            }
            opened = true;
            mDBox();
            opened = false;
        }
        /**
         * Volume up menu item increase volume of recording
         * @param sender from the window
         * @param e events
         * */
        private void volumeUpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int length = getLength();
            Byte b;
            byte[] array = new Byte[length];
            Marshal.Copy(getBuffer(), array, 0, length);
            IntPtr array2 = getBuffer();

            for (int i = 0; i < length; i++)
            {
                b = (byte)((array[i] - 128) * 2);
                array[i] = (byte)(b + 128);
            }

            Marshal.Copy(array, 0, array2, length);
            setBuffer(array2);
        }
        /**
         * Volume down menu item decreases volume of recording
         * @param sender from the window
         * @param e events
         * */
        private void volumeDownToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int length = getLength();
            Byte b;
            byte[] array = new Byte[length];
            Marshal.Copy(getBuffer(), array, 0, length);
            IntPtr array2 = getBuffer();

            for (int i = 0; i < length; i++)
            {
                b = (byte)((array[i] - 128) * 0.5);
                array[i] = (byte)(b + 128);
            }

            Marshal.Copy(array, 0, array2, length);
            setBuffer(array2);
        }

        /// <summary>
        /// Passes data to dll recorder
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void setDataToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ptsX = TChild.getX();
            ptsY = TChild.getY();

            byte[] array = new byte[ptsY.Length];
            IntPtr array2 = getBuffer();

            for(int i = 0; i < ptsY.Length; i++)
            {
                array[i] = (byte)ptsY[i];
            }

            Marshal.Copy(array, 0, array2, ptsY.Length);
            setBuffer(array2);
        }

        /// <summary>
        /// Threads for forward fourier to up performance
        /// </summary>
        private void forwardFourierThreads()
        {
            Stopwatch sw = new Stopwatch();
            int sections = 6;

            if(leftChannel)
            {
                ptsX = TChild.getXValues();
                ptsY = TChild.getYValues();
            }
            
            if(rightChannel)
            {
                ptsX = TChild2.getXValues();
                ptsY = TChild2.getYValues();
            }

            double[] temp = new double[ptsY.Length];

            double[] temp1 = new double[ptsY.Length / sections];
            double[] temp2 = new double[ptsY.Length / sections];
            double[] temp3 = new double[ptsY.Length / sections];
            double[] temp4 = new double[ptsY.Length / sections];
            double[] temp5 = new double[ptsY.Length / sections];
            double[] temp6 = new double[ptsY.Length / sections];

            Thread t1 = new Thread(delegate () { temp1 = forwardFourier(0, ptsY.Length / sections, ptsY); });
            Thread t2 = new Thread(delegate () { temp2 = forwardFourier(1, ptsY.Length / sections, ptsY); });
            Thread t3 = new Thread(delegate () { temp3 = forwardFourier(2, ptsY.Length / sections, ptsY); });
            Thread t4 = new Thread(delegate () { temp4 = forwardFourier(3, ptsY.Length / sections, ptsY); });
            Thread t5 = new Thread(delegate () { temp5 = forwardFourier(4, ptsY.Length / sections, ptsY); });
            Thread t6 = new Thread(delegate () { temp6 = forwardFourier(5, ptsY.Length / sections, ptsY); });

            sw.Start();
            //temp = forwardFourier(1, N, ptsY);
            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();
            t5.Start();
            t6.Start();
            t2.Join();
            t3.Join();
            t1.Join();
            t4.Join();
            t5.Join();
            t6.Join();
            sw.Stop();

            Console.WriteLine("{0}", sw.Elapsed);

            for(int i = 0; i < temp.Length - 1; i++)
            {
                int innerSections = temp.Length / sections;

                if (i < temp1.Length)
                {
                    temp[i] = temp1[i];
                }

                if(i >= temp1.Length && i < innerSections * 2)
                {
                    temp[i] = temp2[i - temp1.Length];
                }

                if (i >= innerSections * 2 && i < innerSections * 3 - 1)
                {
                    temp[i] = temp3[i - innerSections * 2];
                }

                if (i >= innerSections * 3 && i < innerSections * 4 - 1)
                {
                    temp[i] = temp4[i - innerSections * 3];
                }

                if (i >= innerSections * 4 && i < innerSections * 5 - 1)
                {
                    temp[i] = temp5[i - innerSections * 4];
                }

                if (i >= innerSections * 5 && i < innerSections * 6 - 1)
                {
                    temp[i] = temp6[i - innerSections * 5];
                }
            }
            
            for(int i = 0; i < ptsX.Length; i++)
            {
                ptsX[i] = i;
            }

            ptsY = temp;

            if(leftChannel)
            {
                fChild.drawFrequency(ptsX, ptsY);
                leftChannel = false;
            } else
            {
                fChild2.drawFrequency(ptsX, ptsY);
                rightChannel = false;
            }

        }

        /// <summary>
        /// Performs forward fourier on the left channel window
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void leftChannelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            leftChannel = true;
            forwardFourierThreads();
        }

        /// <summary>
        /// Performs forward fourier on the right channel window
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void rightChannelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            rightChannel = true;
            forwardFourierThreads();
        }
        /**
         * forwardFourier changes values in the time domain to ones 
         * in the frequency domain, parts represent the section a particular 
         * thread is working on, N is the number of values within each thread,
         * sampleValues are all the sample values
         * @param parts represents the section a particular thread is working on
         * @param N is the number of values within each thread
         * @param sampleValues are all the sample values from the time graph
         * @return double[] amplitude of the frequency bins
         * */
        public double[] forwardFourier(int parts, int N, double[] sampleValues)
        {
            double sumReal = 0, sumIm = 0;
            re = new double[N];
            im = new double[N];
            double[] amplitude = new double[N];
            int interval = N * parts;
            //double[] theta = new double[N];

            for (int f = 0 + interval; f < N + interval; f++)
            {

                for (int t = 0; t < sampleValues.Length; t++)
                {
                    sumReal += sampleValues[t] * Math.Cos(2 * Math.PI * t * f / (sampleValues.Length));
                    sumIm -= sampleValues[t] * Math.Sin(2 * Math.PI * t * f / (sampleValues.Length));
                }

                re[f - interval] = (int)(Math.Round(sumReal));
                im[f - interval] = sumIm;
                amplitude[f - interval] = Math.Sqrt(Math.Pow(re[f - interval], 2) + Math.Pow(im[f - interval], 2))
                    / (sampleValues.Length / 2);
                //theta[f] = Math.Atan2(im[f], re[f]);
                sumReal = 0;
                sumIm = 0;
            }
            
            return amplitude;
        }

        /**
         * Inverse fourier menu option change frequency points
         * into time domain
         * @param sender from the window
         * @param e events
        * */
        /* Previously used this method for testing
        private void inverseFourierToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int N = fChild.getN();

            double[] yValue = inverseFourier(0, N, re, im);

            double[] xValue = new double[yValue.Length];

            for(int i = 0; i < xValue.Length; i++)
            {
                xValue[i] = i;
            }

            ptsX = xValue;
            ptsY = yValue;

            TChild.chartDisplay2(ptsX, ptsY);
        }*/
        /**
         * Inverse fourier function to change from frequency
         * domain to time domain
         * @param number of values, real vales, imaginary values
         * */
        private double[] inverseFourier(int parts, int N, double[] real, double[] imaginary)
        {
            double sumReal = 0, sumIm = 0;

            double[] re2 = new double[N];
            double[] im2 = new double[N];
            int interval = N * parts;

            for (int t = 0 + interval; t < N + interval; t++)
            {

                for (int f = 0; f < real.Length; f++)
                {
                    sumReal += real[f] * Math.Cos(2 * Math.PI * f * t / real.Length);
                    sumIm += real[f] * Math.Sin(2 * Math.PI * f * t / real.Length);
                    sumIm += imaginary[f] * Math.Cos(2 * Math.PI * f * t / real.Length);
                    sumReal -= imaginary[f] * Math.Sin(2 * Math.PI * f * t / real.Length);
                }

                int whole = (int)sumReal;
                re2[t - interval] = (double)whole / real.Length;
                im2[t - interval] = (int)(sumIm) / real.Length;
                sumReal = 0;
                sumIm = 0;
            }
            return re2;
        }
        /**
         * Regular menu option under filters is
         * the first way to filter: dft samples, mulitply by filter,
         * idft back into filtered samples
         * @params sender, event
         * */
         /* Filter method on a section through the other algorithm
        private void regularToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            double[] filterValue = fChild.getFilter();
            int N = fChild.getN();
            double[] realValue = re;
            double[] imValue = im;

            if (filterValue == null)
            {
                MessageBox.Show("Didn't select filter");
            }
            else
            {
                for (int i = 0; i < filterValue.Length; i++)
                {
                    realValue[i] = realValue[i] * filterValue[i];
                    imValue[i] = imValue[i] * filterValue[i];
                }

                double[] filteredSamples = inverseFourier(0, N, realValue, imValue);
                double[] x = new double[filteredSamples.Length];

                for (int i = 0; i < filteredSamples.Length; i++)
                {
                    x[i] = i;
                }

                ptsX = x;
                ptsY = filteredSamples;

                TChild.chartDisplay2(ptsX, ptsY);
            }
        }*/
        /// <summary>
        /// Applies idft to filter values
        /// </summary>
        /// <returns>double[] temp is the modified filtered values</returns>
        private double[] changeFilter()
        {
            int sections = 4;
            double[] filterValue = fChild.getFilter();
            double[] temp = new double[filterValue.Length];

            double[] temp1 = new double[filterValue.Length / sections];
            double[] temp2 = new double[filterValue.Length / sections];
            double[] temp3 = new double[filterValue.Length / sections];
            double[] temp4 = new double[filterValue.Length / sections];

            Thread t1 = new Thread(delegate () { temp1 = inverseFourier(0, filterValue.Length / sections, filterValue, filterValue); });
            Thread t2 = new Thread(delegate () { temp2 = inverseFourier(1, filterValue.Length / sections, filterValue, filterValue); });
            Thread t3 = new Thread(delegate () { temp3 = inverseFourier(2, filterValue.Length / sections, filterValue, filterValue); });
            Thread t4 = new Thread(delegate () { temp4 = inverseFourier(3, filterValue.Length / sections, filterValue, filterValue); });
           
            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();

            t1.Join();
            t2.Join();
            t3.Join();
            t4.Join();

            int part = filterValue.Length / sections;

            for(int i = 0; i < temp.Length; i++)
            {
                if(i < temp1.Length)
                {
                    temp[i] = temp1[i];
                }

                if(i >= temp1.Length && i < part * 2)
                {
                    temp[i] = temp2[i - part];
                }

                if(i >= part * 2 && i < part * 3)
                {
                    temp[i] = temp3[i - part * 2];
                }

                if(i >= part * 3 && i < part * 4)
                {
                    temp[i] = temp4[i - part * 3];
                }
            }

            return temp;
        }
        /**
         * Convolution menu item filters by convolving through all samples,
         * idft filter and then multiply the samples with the filtered weights
         * @param sender, event
         * */
        private async void convolution()
        {
            Stopwatch sw = new Stopwatch();

            double[] filterValue, tempX;
            if(leftChannel)
            {
                originalX = TChild.getX();//original x needed because ptsX array took on 
                                          //the values of the selected section of the graph
                originalY = TChild.getY();

                filterValue = fChild.getFilter();
            } else
            {
                originalX = TChild2.getX();
                originalY = TChild2.getY();

                filterValue = fChild2.getFilter();
            }

            Task task = new Task(() => {
                filterValue = changeFilter();
                });

            task.Start();
            await Task.WhenAll(task);

            double[] temp1 = new double[originalY.Length / 4 + filterValue.Length - 1];
            double[] temp2 = new double[originalY.Length / 4 + filterValue.Length - 1];
            double[] temp3 = new double[originalY.Length / 4 + filterValue.Length - 1];
            double[] temp4 = new double[originalY.Length / 4 + filterValue.Length - 1];

            for(int i = 0; i < temp1.Length; i++)
            {
                    temp1[i] = originalY[i];   
            }

            for (int i = 0; i < temp2.Length; i++)
            {
                temp2[i] = originalY[i + originalY.Length / 4];
            }

            for (int i = 0; i < temp3.Length; i++)
            {
                temp3[i] = originalY[i + 2 * originalY.Length / 4];
            }

            for (int i = 0; i < temp4.Length; i++)
            {
                if(i < originalY.Length / 4)
                {
                    temp4[i] = originalY[i + 3 * originalY.Length / 4];
                } else
                {
                    temp4[i] = 0;
                }
            }

            sw.Start();
            originalY = convolveValues(temp1, temp2, temp3, temp4, filterValue);
            sw.Stop();

            tempX = new double[originalY.Length];

            for(int i = 0; i < originalY.Length; i++)
            {
                tempX[i] = i;
            }
            //Need a separate original x and x array for some functions
            originalX = tempX;
            ptsY = originalY;

            if(leftChannel)
            {
                ptsX = tempX;
                ptsY = originalY;
                TChild.chartDisplay2(ptsX, ptsY);
                leftChannel = false;
            } else
            {
                ptsXRight = tempX;
                ptsYRight = originalY;
                TChild2.chartDisplay2(ptsXRight, ptsYRight);
                rightChannel = false;
            }
        }
        /// <summary>
        /// Runs convolution through threads and returns the combined values of all
        /// the threads
        /// </summary>
        /// <param name="valueSet1">Section 1 of the values</param>
        /// <param name="valueSet2">Section 2 of the values</param>
        /// <param name="valueSet3">Section 3 of the values</param>
        /// <param name="valueSet4">Section 4 of the values</param>
        /// <param name="filteredValues">filter values that have been through idft</param>
        /// <returns>combined filtered values</returns>
        private double[] convolveValues(double[] valueSet1, double[] valueSet2,
            double[] valueSet3, double[] valueSet4, double[] filteredValues)
        {
            double[] filtered1 = new double[valueSet1.Length];
            double[] filtered2 = new double[valueSet2.Length];
            double[] filtered3 = new double[valueSet3.Length];
            double[] filtered4 = new double[valueSet4.Length];
            double[] combined = new double[originalY.Length];

            Thread t1 = new Thread(delegate() { filtered1 = convolveIndividualValues(valueSet1, filteredValues); });
            Thread t2 = new Thread(delegate() { filtered2 = convolveIndividualValues(valueSet2, filteredValues); });
            Thread t3 = new Thread(delegate() { filtered3 = convolveIndividualValues(valueSet3, filteredValues); });
            Thread t4 = new Thread(delegate() { filtered4 = convolveIndividualValues(valueSet4, filteredValues); });

            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();

            t1.Join();
            t2.Join();
            t3.Join();
            t4.Join();

            for (int i = 0; i < combined.Length; i++)
            {
                if(i < filtered1.Length)
                {
                    combined[i] = filtered1[i];
                }

                if(i >= filtered1.Length && i < 2 * filtered1.Length)
                {
                    combined[i] = filtered2[i - filtered1.Length];
                }

                if (i >= filtered1.Length * 2 && i < 3 * filtered1.Length - 1)
                {
                    combined[i] = filtered3[i - 2 * filtered1.Length];
                }

                if (i >= filtered1.Length * 3 && i < 4 * filtered1.Length - 1)
                {
                    combined[i] = filtered2[i - 3 * filtered1.Length];
                }
            }

            return combined;
        }

        private double[] convolveIndividualValues(double[] sampleValues, double[] filterValues)
        {
            double[] temp = new double[sampleValues.Length - filterValues.Length + 1];

            for(int i = 0; i < sampleValues.Length - filterValues.Length; i++)
            {
                double sum = 0;
                for(int j = 0; j < filterValues.Length; j++)
                {
                    sum += sampleValues[i + j] * filterValues[j];
                }

                sampleValues[i] = sum;
            }

            for(int i = 0; i < temp.Length; i++)
            {
                temp[i] = sampleValues[i];
            }

            return temp;
        }
        /// <summary>
        /// Convolution for left channel
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void convolveLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            leftChannel = true;
            convolution();
        }
        /// <summary>
        /// Convolution for right channel
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void convolveRToolStripMenuItem_Click(object sender, EventArgs e)
        {
            rightChannel = true;
            convolution();
        }
        /// <summary>
        /// Opens file in left channel
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void openLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String fileName = " ";
            leftChannel = true;

            OpenFileDialog dialog = new OpenFileDialog();

            dialog.InitialDirectory = "C:\\";
            dialog.Title = "Select a Wav file";

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                fileName = dialog.FileName;
                ReadWav(fileName);
            }
        }
        /// <summary>
        /// Opens wave file in right channel
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void openRToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String fileName = " ";
            rightChannel = true;

            OpenFileDialog dialog = new OpenFileDialog();

            dialog.InitialDirectory = "C:\\";
            dialog.Title = "Select a Wav file";

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                fileName = dialog.FileName;
                ReadWav(fileName);
            }
        }
        /// <summary>
        /// Opens stereo wave file in both channels
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void stereoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String fileName = " ";

            OpenFileDialog dialog = new OpenFileDialog();

            dialog.InitialDirectory = "C:\\";
            dialog.Title = "Select a Wav file";

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                fileName = dialog.FileName;
                ReadWav(fileName);
            }
        }
        /// <summary>
        /// Saves file to desired location on laptop
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void saveFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.InitialDirectory = @"C:\";
            sfd.Title = "Save to somewhere";
            sfd.CheckPathExists = true;

            if(sfd.ShowDialog() == DialogResult.OK)
            {
                String s = sfd.FileName;

                WriteWav(s);
            }
        }
        /// <summary>
        /// Draws data from recorder
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void drawDataToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int length = getLength();
            samples = getSampleRate();
            time = 1 / samples;

            byte[] array = new Byte[length];
            Marshal.Copy(getBuffer(), array, 0, length);
            ptsY = new double[length];
            ptsX = new double[length];

            for (int i = 0; i < length; i++)
            {
                ptsY[i] = (double)array[i];
            }

            for (int i = 0; i < length; i++)
            {
                ptsX[i] = time * i;
            }

            TChild.chartDisplay2(ptsX, ptsY);
        }

        /** 
         * ReadWav reads in wave file into array
         * @param string file name to be read in
         * */
        private void ReadWav(string file)
        {
            FileStream fs = new FileStream(file, FileMode.Open, FileAccess.Read);
            BinaryReader reader = new BinaryReader(fs);

            double[] tempX, tempY;

            chunkID = reader.ReadInt32();
            fileSize = reader.ReadInt32();
            riffType = reader.ReadInt32();
            fmtID = reader.ReadInt32();
            fmtSize = reader.ReadInt32();
            formatCode = reader.ReadInt16();
            channels = reader.ReadInt16();
            fileSampleRate = reader.ReadInt32();
            fmtAvgBPS = reader.ReadInt32();
            fmtBlockAlign = reader.ReadInt16();
            bitDepth = reader.ReadInt16();

            if (fmtSize == 18)
            {
                // Read any extra values
                int fmtExtraSize = reader.ReadInt16();
                reader.ReadBytes(fmtExtraSize);
            }

            data = reader.ReadInt32();
            dataSize = reader.ReadInt32();

            //byte[] wav = reader.ReadBytes(dataSize);

            byte[] wav = File.ReadAllBytes(file);
            int pos = 44;
            fileSamples = (wav.Length - pos) / 2; //divide by two for two bytes per sample

            if (channels == 2)
            {
                fileSamples /= 2;//double
            }

            left = new short[fileSamples];
            tempX = new double[fileSamples];
            tempY = new double[fileSamples];
            
            if (channels == 2)
            {
                right = new short[fileSamples];
                ptsXRight = new double[fileSamples];
                ptsYRight = new double[fileSamples];
            }
            else
            {
                right = null;
            }

            for (int i = 0; i < fileSamples; i++)
            {
                left[i] = (short)((wav[pos + 1] << 8 | wav[pos]));
                pos += 2;

                if (channels == 2)
                {
                    right[i] = (short)((wav[pos + 1] << 8 | wav[pos]));
                    pos += 2;
                }
            }

            for(int i = 0; i < fileSamples; i++)
            {
                tempX[i] = i;
                tempY[i] = (double)left[i];
            }

            if(channels == 2)
            {
                for(int i = 0; i < fileSamples; i++)
                {
                    ptsXRight[i] = i;
                    ptsYRight[i] = (double)right[i];
                }
            }
            
            if(leftChannel)
            {
                TChild.setX(tempX);
                TChild.setY(tempY);

                ptsX = tempX;
                ptsY = tempY;

                TChild.chartDisplay2(ptsX, ptsY);
                leftChannel = false;
            } else
            {
                if(rightChannel)
                {
                    TChild2.setX(tempX);
                    TChild2.setY(tempY);

                    ptsXRight = tempX;
                    ptsYRight = tempY;

                    TChild2.chartDisplay2(ptsXRight, ptsYRight);
                    rightChannel = false;
                } else
                {
                    TChild.setX(tempX);
                    TChild.setY(tempY);

                    TChild2.setX(ptsXRight);
                    TChild2.setY(ptsYRight);

                    ptsX = tempX;
                    ptsY = tempY;

                    TChild.chartDisplay2(ptsX, ptsY);
                    TChild2.chartDisplay2(ptsXRight, ptsYRight);
                }
            }
            
        }

        /**
         * WriteWav combines bytes back into wave file for saving
         * @param string file to be saved
         * */
        private void WriteWav(string s)
        {
            FileStream fs = new FileStream(s, FileMode.Create, FileAccess.Write);
            BinaryWriter bf = new BinaryWriter(fs);

            int pos = 44;

            byte[] wav = new byte[fileSamples * 2 + 44];//didn't include the 44 as it's written below(?)

            if (channels == 2)
                wav = new byte[fileSamples * 4 + 44];

            bf.Write(chunkID);
            bf.Write(fileSize);
            bf.Write(riffType);
            bf.Write(fmtID);
            bf.Write(fmtSize);
            bf.Write(formatCode);
            bf.Write(channels);
            bf.Write(fileSampleRate);
            bf.Write(fmtAvgBPS);
            bf.Write(fmtBlockAlign);
            bf.Write(bitDepth);
            bf.Write(data);
            bf.Write(dataSize);

            for (int i = 0; i < fileSamples; i++)
            {
                byte firstHalf = (byte)(left[i] & 0xff);
                byte secondHalf = (byte)((left[i] >> 8) & 0xff);
                wav[pos] = firstHalf;
                bf.Write(wav[pos]);
                wav[pos + 1] = secondHalf;
                bf.Write(wav[pos + 1]);
                pos += 2;

                if (channels == 2)
                {
                    byte firstHalf2 = (byte)(right[i] & 0xff);
                    byte secondHalf2 = (byte)((right[i] >> 8) & 0xff);
                    wav[pos] = firstHalf2;
                    bf.Write(wav[pos]);
                    wav[pos + 1] = secondHalf2;
                    bf.Write(wav[pos]);
                    pos += 2;
                }
            }

        }
        
    }
}
