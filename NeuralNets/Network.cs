using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNets
{
    class Network
    {
        private int numLayers;
        private int[] sizes;
        private double[][][] weights, biases;
        private Matrix m;
        private Random random;
        private string progress;
        private Boolean update;

        /// <summary>
        /// Constructor sets the neuron layers and matrices 
        /// </summary>
        /// <param name="sizes"></param>
        public Network(int[] sizes)
        {

            numLayers = sizes.Length;
            this.sizes = sizes;
            biases = new double[numLayers - 1][][];
            m = new Matrix();
            random = new Random();
            update = false;

            //maybe change to 3d?
            for (int i = 1; i < numLayers; i++)
            {
                biases[i - 1] = new double[this.sizes[i]][];

                for (int j = 0; j < biases[i - 1].Length; j++)
                {
                    biases[i - 1][j] = new double[1];

                    for (int k = 0; k < biases[i - 1][j].Length; k++)
                    {

                        biases[i - 1][j][k] = random.NextDouble() * 4 - 2;
                    }
                }
            }

            weights = new double[numLayers - 1][][];

            //sets each of the varying matrices between layers
            for (int i = 1; i < numLayers; i++)
            {

                weights[i - 1] = new double[this.sizes[i]][];

                for (int j = 0; j < weights[i - 1].Length; j++)
                {
                    weights[i - 1][j] = new double[this.sizes[i - 1]];

                    //set all weights to value between 0 and 1
                    for (int k = 0; k < weights[i - 1][j].Length; k++)
                    {
                        weights[i - 1][j][k] = random.NextDouble() * 4 - 2;

                    }
                }
            }

        }

        /**
         * Activation function for neuron firing
         * @param z
         * @return
         */
        double[][] sigmoid(double[][] z)
        {

            for (int i = 0; i < z.Length; i++)
            {
                for (int j = 0; j < z[i].Length; j++)
                {
                    z[i][j] = 1.0 / (1.0 + Math.Exp(-z[i][j]));
                }
            }

            return z;
        }

        /// <summary>
        /// Activation function choice
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        double[][] tanh(double[][] x)
        {
            for (int i = 0; i < x.Length; i++)
            {
                for (int j = 0; j < x[i].Length; j++)
                {
                    x[i][j] = (Math.Exp(x[i][j]) - Math.Exp(-x[i][j])) / (Math.Exp(x[i][j])
                        + Math.Exp(-x[i][j]));
                }
            }

            return x;
        }

        double[][] feedForward(double[][] a)
        {

            for (int i = 0; i < weights.Length; i++)
            {
                double[][] tempW = weights[i];
                double[][] tempB = biases[i];

                double[][] temp = m.dot(tempW, a);
                temp = m.add(temp, tempB);

                a = sigmoid(temp);

               // a = tanh(temp);
            }

            return a;
        }

        /**
         * Stochastic gradient descent
         * @param training_data
         * @param epochs
         * @param miniBatchSize
         * @param eta
         * @param test_data
         */
        public void SGD(double[][][][] training_data, int epochs, int miniBatchSize,
                double eta, double[][][][] test_data)
        {

            //training data Length 50000, then into 2, 1 for input and 1 for output, size
            //of input 784, size of output is 10, inside each is an array of size 1 for the
            //neurons so 4d array
            int nTest = 0;

            if (test_data != null)
            {
                nTest = test_data.Length;
            }

            int n = training_data.Length;

            for (int i = 0; i < epochs; i++)
            {
                //training_data = shuffleArray(training_data);

                double[][][][][] miniBatches = new double[n / miniBatchSize][][][][];

                //Added following for loop cause c# requires initilization
                for(int j = 0; j < miniBatches.Length; j++)
                {
                    miniBatches[j] = new double[miniBatchSize][][][];
                }

                for (int k = 0; k < n; k += miniBatchSize)
                {

                    for (int j = k; j < k + miniBatchSize; j++)
                    {
                        miniBatches[k / 10][j - k] = training_data[j];
                    }
                }

                for (int j = 0; j < miniBatches.Length; j++)
                {
                    updateMiniBatches(miniBatches[j], eta);
                }

                update = true;

                if (test_data != null)
                {
                    string temp = "Epoch ";
                    temp += i;
                    temp += ": ";
                    temp += evaluate(test_data);
                    temp += " / ";
                    temp += nTest;

                    progress = temp;
                    
                    Console.WriteLine(progress);
                }
                else
                {
                    string temp = "Epoch ";
                    temp += i;
                    temp += " complete.";

                    progress = temp;
                }

                update = false;
            }

        }

        /**
         * Updates mini batches
         * @param miniBatch
         * @param eta
         */
        public void updateMiniBatches(double[][][][] miniBatch, double eta)
        {

            double[][][] nablaB = new double[biases.Length][][];
            double[][][] nablaW = new double[weights.Length][][];
            //change it to 0
            for (int i = 0; i < biases.Length; i++)
            {
                nablaB[i] = new double[biases[i].Length][];

                for (int j = 0; j < biases[i].Length; j++)
                {
                    nablaB[i][j] = new double[biases[i][j].Length];

                    for (int k = 0; k < biases[i][j].Length; k++)
                    {
                        nablaB[i][j][k] = 0.0;
                    }
                }
            }

            for (int i = 0; i < weights.Length; i++)
            {
                nablaW[i] = new double[weights[i].Length][];
                for (int j = 0; j < weights[i].Length; j++)
                {
                    nablaW[i][j] = new double[weights[i][j].Length];

                    for (int k = 0; k < weights[i][j].Length; k++)
                    {
                        nablaW[i][j][k] = 0.0;
                    }
                }
            }

            for (int i = 0; i < miniBatch.Length; i++)
            {
                double[][] x = new double[miniBatch[i][0].Length][];
                double[][] y = new double[miniBatch[i][1].Length][];

                for(int j = 0; j < x.Length; j++)
                {
                    x[j] = new double[1];
                }

                for (int j = 0; j < y.Length; j++)
                {
                    y[j] = new double[1];
                }

                x = miniBatch[i][0];
                y = miniBatch[i][1];

                double[][][][] changedValues = backprop(x, y);

                double[][][] deltaNablaB = changedValues[0];
                double[][][] deltaNablaW = changedValues[1];

                //Get the deltas for the biases and weights and add
                //them to original
                for (int j = 0; j < nablaB.Length; j++)
                {
                    double[][] nb = nablaB[j];
                    double[][] dnb = deltaNablaB[j];

                    nablaB[j] = m.add(nb, dnb);
                }

                for (int j = 0; j < nablaW.Length; j++)
                {
                    double[][] nw = nablaW[j];
                    double[][] dnw = deltaNablaW[j];

                    nablaW[j] = m.add(nw, dnw);
                }
            }

            double etaPerMiniBatch = eta / miniBatch.Length;

            for (int i = 0; i < weights.Length; i++)
            {
                double[][] w = weights[i];
                double[][] nw = nablaW[i];

                for (int j = 0; j < nw.Length; j++)
                {
                    for (int k = 0; k < nw[j].Length; k++)
                    {
                        nw[j][k] *= etaPerMiniBatch;
                    }
                }

                weights[i] = m.subtract(w, nw);
            }

            for (int i = 0; i < biases.Length; i++)
            {
                double[][] b = biases[i];
                double[][] nb = nablaB[i];

                for (int j = 0; j < nb.Length; j++)
                {
                    for (int k = 0; k < nb[j].Length; k++)
                    {
                        nb[j][k] *= etaPerMiniBatch;
                    }
                }

                biases[i] = m.subtract(b, nb);
            }
        }

        /**
         * Find difference between actual and desired and change weights accordingly
         * @param x
         * @param y
         * @return
         */
        private double[][][][] backprop(double[][] x, double[][] y)
        {
            double[][][] nablaB = new double[biases.Length][][];
            double[][][] nablaW = new double[weights.Length][][];
            //change it to 0
            for (int i = 0; i < biases.Length; i++)
            {
                nablaB[i] = new double[biases[i].Length][];

                for (int j = 0; j < biases[i].Length; j++)
                {
                    nablaB[i][j] = new double[biases[i][j].Length];

                    for (int k = 0; k < biases[i][j].Length; k++)
                    {
                        nablaB[i][j][k] = 0.0;
                    }
                }
            }

            for (int i = 0; i < weights.Length; i++)
            {
                nablaW[i] = new double[weights[i].Length][];
                for (int j = 0; j < weights[i].Length; j++)
                {
                    nablaW[i][j] = new double[weights[i][j].Length];

                    for (int k = 0; k < weights[i][j].Length; k++)
                    {
                        nablaW[i][j][k] = 0.0;
                    }
                }
            }

            double[][] activation = x;//feedforward

            //store activations layer by layer, first layer stores x
            double[][][] activations = new double[1 + biases.Length][][];
            activations[0] = x;

            //should be same Length as biases and weights as it appends once each loop in the
            //loop below?
            double[][][] zs = new double[biases.Length][][];

            for (int i = 0; i < biases.Length; i++)
            {
                double[][] b = biases[i];
                double[][] w = weights[i];

                //dot product and add biases
                double[][] z = m.dot(w, activation);
                z = m.add(z, b);

                zs[i] = new double[z.Length][];
                for (int k = 0; k < z.Length; k++)
                {
                    zs[i][k] = new double[z[k].Length];

                    for (int j = 0; j < z[k].Length; j++)
                    {
                        
                        zs[i][k][j] = z[k][j];
                    }
                }

                activation = sigmoid(z);

                //activation = tanh(z);
                activations[i + 1] = activation;
            }

            double[][] delta = costDerivative(activations[activations.Length - 1], y);
            double[][] delta2 = sigmoidPrime(zs[zs.Length - 1]);

            //double[][] delta2 = tanHPrime(zs[zs.Length - 1]);

            for (int i = 0; i < delta.Length; i++)
            {
                for (int j = 0; j < delta[i].Length; j++)
                {
                    delta[i][j] = delta[i][j] * delta2[i][j];
                }
            }

            nablaB[nablaB.Length - 1] = delta;

            double[][] temp = m.transpose(activations[activations.Length - 2]);
            nablaW[nablaW.Length - 1] = m.dot(delta, temp);

            for (int i = 2; i < numLayers; i++)
            {
                double[][] z = zs[zs.Length - i];

                double[][] sp = sigmoidPrime(z);
                //double[][] sp = tanHPrime(z);

                temp = m.transpose(weights[weights.Length - i + 1]);
                temp = m.dot(temp, delta);

                for (int j = 0; j < sp.Length; j++)
                {
                    for (int k = 0; k < sp[0].Length; k++)
                    {
                        temp[j][k] = temp[j][k] * sp[j][k];
                    }
                }

                delta = temp;

                nablaB[nablaB.Length - i] = delta;

                temp = m.transpose(activations[activations.Length - i - 1]);
                nablaW[nablaW.Length - i] = m.dot(delta, temp);
            }

            double[][][][] changedValues = new double[2][][][];

            changedValues[0] = nablaB;
            changedValues[1] = nablaW;

            return changedValues;
        }

        /**
         * The output neuron with the highest number is considered to have fired
         * and if it's same as expected result the number of correct is increased
         * @param testData
         * @return
         */
        private int evaluate(double[][][][] testData)
        {
            //test data is strange for testData[0][0] is equal to a double[0][0]
            //but testData[0][1] is a number, so it's probably a list with the first
            //element of the 3rd array, testData[0][0], storing a 2d array, while the 
            //second element only stores a number
            //The number is the correct answer to the image, so if image shows 7 number
            //would also be 7
            double[][] testResults = new double[testData.Length][];

            for(int i = 0; i < testResults.Length; i++)
            {
                testResults[i] = new double[2];
            }

            int sum = 0;

            for (int i = 0; i < testData.Length; i++)
            {
                double[][] x = testData[i][0];
                double[][] y = testData[i][1];

                x = feedForward(x);
                double max = findMax(x);

                testResults[i][0] = max;
                testResults[i][1] = y[0][0];
            }

            for (int i = 0; i < testResults.Length; i++)
            {
                if (testResults[i][0] == testResults[i][1])
                    sum++;
            }

            return sum;
        }

        /**
         * Calculates difference between actual output and desired output
         * @param output
         * @param y
         * @return
         */
        private double[][] costDerivative(double[][] output, double[][] y)
        {
            return m.subtract(output, y);
        }

        /**
         * Derivative of sigmoid function
         * @param z
         * @return
         */
        private double[][] sigmoidPrime(double[][] z)
        {
            double[][] temp = sigmoid(z);
            double[][] temp2 = new double[temp.Length][];

            for(int i = 0; i < temp2.Length; i++)
            {
                temp2[i] = new double[temp[i].Length];
            }

            for (int i = 0; i < temp2.Length; i++)
            {
                for (int j = 0; j < temp2[i].Length; j++)
                {
                    temp2[i][j] = 1 - temp[i][j];
                }
            }

            for (int i = 0; i < temp2.Length; i++)
            {
                for (int j = 0; j < temp2[i].Length; j++)
                {
                    temp[i][j] = temp[i][j] * temp2[i][j];
                }
            }
            return temp;
        }

        /// <summary>
        /// tanh prime function 1 - f(x)^2
        /// </summary>
        /// <param name="z"></param>
        /// <returns></returns>
        private double[][] tanHPrime(double[][] z)
        {
            double[][] temp = tanh(z);
            double[][] temp2 = new double[temp.Length][];

            for (int i = 0; i < temp2.Length; i++)
            {
                temp2[i] = new double[temp[i].Length];
            }

            for (int i = 0; i < temp2.Length; i++)
            {
                for (int j = 0; j < temp2[i].Length; j++)
                {
                    temp2[i][j] = 1 - temp[i][j] * temp[i][j];
                }
            }

            return temp2;
        }
        
        /**
         * Finds the highest value and returns it's position number
         * @param a
         * @return
         */
        private double findMax(double[][] a)
        {
            double max = 0;
            double result = 0;

            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a[i].Length; j++)
                {
                    if (max <= a[i][j])
                    {
                        max = a[i][j];//going through n x 1 ndarrays so the element
                        result = i;                //of the column number is counted
                    }
                }
            }

            return result;
        }

        /// <summary>
        /// Changes image from rgb to grey scale to allow for data parsing
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public byte[][] rgbToGrey(Bitmap input)
        {
            byte[][] pixel;
            pixel = new byte[input.Width][];
            for (int i = 0; i < pixel.Length; i++)
            {
                pixel[i] = new byte[input.Height];
            }
            for (int x = 0; x < input.Width; x++)
            {
                for (int y = 0; y < input.Height; y++)
                {
                    Color pixelColor = input.GetPixel(x, y);
                    //  0.3 · r + 0.59 · g + 0.11 · b
                    double grey = pixelColor.R * 0.3 + pixelColor.G * 0.59 + pixelColor.B * 0.11;
                    pixel[y][x] = (byte)(255 - grey);
                }
            }
            return pixel;
        }

        /// <summary>
        /// Identify a single test sample
        /// </summary>
        /// <param name="testSample"></param>
        /// <returns></returns>
        public int identify(double[][] testSample)
        {
            testSample = feedForward(testSample);
            double max = findMax(testSample);

            return (int)max;
        }
        
        /// <summary>
        /// Returns progress
        /// </summary>
        /// <returns></returns>
        public string getProgress()
        {
            return progress;
        }

        /// <summary>
        /// Returns update
        /// </summary>
        /// <returns></returns>
        public Boolean getUpdate()
        {
            return update;
        }

        /// <summary>
        /// Returns the biases
        /// </summary>
        /// <returns></returns>
        public double[][][] getBiases()
        {
            return biases;
        }

        /// <summary>
        /// Returns the weights
        /// </summary>
        /// <returns></returns>
        public double[][][] getWeights()
        {
            return weights;
        }
    }
}
