using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNets
{
    class TrainingData
    {
        /*
         * label number of pixels
         */
        private byte number;

        /*
         * 28 by 28 image in bytes (greyscale)
         */
        private byte[][] pixels;
        private double[][][] dataSet;
        private double[][] testSample;

        /// <summary>
        /// Constructor for trainingdata, takes in data and label,
        /// the first constructor is to separate training data and testing
        /// data as they are stored differently
        /// </summary>
        /// <param name="chooseData"></param>
        /// <param name="data"></param>
        /// <param name="label"></param>
        public TrainingData(int chooseData, byte[][] data, byte label)
        {
            number = label;
            pixels = data;
            int count = 0;

            //Change from 28 x 28 to 784 x 1
            dataSet = new double[2][][];

            dataSet[0] = new double[data.Length * data[0].Length][];

            for(int i = 0; i < dataSet[0].Length; i++)
            {
                dataSet[0][i] = new double[1];
            }


            for(int i = 0; i < data.Length; i++)
            {
                for(int j = 0; j < data[i].Length; j++)
                {
                    dataSet[0][count++][0] = data[i][j] / 255.0;
                }
            }

            if (chooseData == 0)
            {
                //Set label to correct firing neuron in 10 x 1 array
                dataSet[1] = new double[10][];

                for (int i = 0; i < dataSet[1].Length; i++)
                {
                    dataSet[1][i] = new double[1];

                    if (i == label)
                    {
                        dataSet[1][i][0] = 1.0;
                    }
                    else
                    {
                        dataSet[1][i][0] = 0.0;
                    }
                }
            } else
            {
                dataSet[1] = new double[1][];
                dataSet[1][0] = new double[1];
                dataSet[1][0][0] = label;
            }
            

        }

        /// <summary>
        /// Overloaded constructor for fruits
        /// </summary>
        /// <param name="data"></param>
        /// <param name="length"></param>
        /// <param name="label"></param>
        public TrainingData(int dataType, byte[][] data, int length, byte label)
        {
            pixels = data;
            int count = 0;

            //Change from 100x100 to 10000x1
            dataSet = new double[2][][];

            dataSet[0] = new double[data.Length * data[0].Length][];

            for (int i = 0; i < dataSet[0].Length; i++)
            {
                dataSet[0][i] = new double[1];
            }

            //Normalize
            for (int i = 0; i < data.Length; i++)
            {
                for (int j = 0; j < data[i].Length; j++)
                {
                    dataSet[0][count++][0] = data[i][j] / 255.0;
                }
            }

            //Set label to correct firing neuron in 10 x 1 array
            dataSet[1] = new double[length][];

            if(dataType == 0)
            {
                for (int i = 0; i < dataSet[1].Length; i++)
                {
                    dataSet[1][i] = new double[1];

                    dataSet[1][i][0] = 0.0;
                }
            } else
            {
                dataSet[1] = new double[1][];
                dataSet[1][0] = new double[1];
                dataSet[1][0][0] = label;
            }
            

        }
        /// <summary>
        /// Overloaded constructor used for when identifying created samples
        /// </summary>
        /// <param name="data"></param>
        public TrainingData(byte[][] data)
        {
            int count = 0;
            testSample = new double[data.Length * data[0].Length][];

            for (int i = 0; i < testSample.Length; i++)
            {
                testSample[i] = new double[1];
            }


            for (int i = 0; i < data.Length; i++)
            {
                for (int j = 0; j < data[i].Length; j++)
                {
                    testSample[count++][0] = (255 - data[i][j]) / 255.0;
                }
            }
        }

        /// <summary>
        /// Returns dataset
        /// </summary>
        /// <returns></returns>
        public double[][][] getTraining()
        {
            return dataSet;
        }

        /// <summary>
        /// Return a single test sample
        /// </summary>
        /// <returns></returns>
        public double[][] getTestSample()
        {
            return testSample;
        }

        public void setData(byte[][] data)
        {
            int count = 0;

            for (int i = 0; i < data.Length; i++)
            {
                for (int j = 0; j < data[i].Length; j++)
                {
                    dataSet[0][count++][0] = (255 - data[i][j]) / 255.0;
                }
            }
        }

        public void setLabel(byte label)
        {
            for(int i = 0; i < dataSet[1].Length; i++)
            {
                if (i == label)
                {
                    dataSet[1][i][0] = 1;
                }
                else
                {
                    dataSet[1][i][0] = 0;
                }
            }
        }


    }
}
