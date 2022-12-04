using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNets
{
    
    class DataReader
    {
        BinaryReader labelReader;
        BinaryReader imageReader;
        FileStream ifsImage;
        FileStream ifsLabel;
        int dataSize;
        TrainingData[] trainData;
        bool isTrainData;
        double[][][][] training_Data;

        private void setStream(int chooseData)
        {
            if (chooseData == 0)
            {
                ifsImage = new FileStream("train-images.idx3-ubyte", FileMode.Open);
                ifsLabel = new FileStream("train-labels.idx1-ubyte", FileMode.Open);
                isTrainData = true;
                imageReader = new BinaryReader(ifsImage);
                labelReader = new BinaryReader(ifsLabel);
            } else
            {
                ifsImage = new FileStream("t10k-images.idx3-ubyte", FileMode.Open);
                ifsLabel = new FileStream("t10k-labels.idx1-ubyte", FileMode.Open);
                isTrainData = false;
                imageReader = new BinaryReader(ifsImage);
                labelReader = new BinaryReader(ifsLabel);
            }

            
        }

        private void closeStream()
        {
            labelReader.Close();
            imageReader.Close();
            ifsImage.Close();
            ifsLabel.Close();
        }

        public void read(int chooseData)
        {
            try
            {
                setStream(chooseData);
                if (isTrainData)
                {
                    dataSize = 60000;
                }
                else
                {
                    dataSize = 10000;
                }

                //discard headers
                imageReader.ReadInt32();
                imageReader.ReadInt32();
                imageReader.ReadInt32();
                imageReader.ReadInt32();

                labelReader.ReadInt32();
                labelReader.ReadInt32();

                byte[][] pixels = new byte[28][];
                for (int i = 0; i < pixels.Length; i++)
                {
                    pixels[i] = new byte[28];
                }

                byte label;
                trainData = new TrainingData[dataSize];
                for (int i = 0; i < dataSize; i++)
                {
                    label = labelReader.ReadByte();
                    for (int j = 0; j < 28; j++)
                    {
                        for (int k = 0; k < 28; k++)
                        {
                            pixels[j][k] = imageReader.ReadByte();
                        }
                    }

                    trainData[i] = new TrainingData(chooseData, pixels, label);
                }

                training_Data = new double[dataSize][][][];

                for(int i = 0; i < trainData.Length; i++)
                {
                    training_Data[i] = trainData[i].getTraining();
                }

                closeStream();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
            }
        }

        public double[][][][] getTD()
        {
            return training_Data;
        }
    }
}
