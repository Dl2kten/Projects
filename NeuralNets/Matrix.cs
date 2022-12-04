using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNets
{
    class Matrix
    {
        public Matrix()
        {

        }

        /// <summary>
        /// Matrix dot product
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public double[][] dot(double[][] a, double[][] b)
        {
            double[][] product = new double[a.Length][];

            for(int i = 0; i < product.Length; i++)
            {
                product[i] = new double[b[0].Length];
            }

            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a[i].Length; j++)
                {
                    for (int k = 0; k < b[j].Length; k++)
                    {
                        product[i][k] += a[i][j] * b[j][k];
                    }
                }
            }

            return product;
        }

        /// <summary>
        /// Matrix add
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public double[][] add(double[][] a, double[][] b)
        {
            double[][] sum = new double[a.Length][];

            for (int i = 0; i < sum.Length; i++)
            {
                sum[i] = new double[a[0].Length];
            }

            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a[i].Length; j++)
                {
                    sum[i][j] = a[i][j] + b[i][j];
                }
            }

            return sum;
        }

        /// <summary>
        /// Matrix subtract
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public double[][] subtract(double[][] a, double[][] b)
        {
            double[][] difference = new double[a.Length][];

            for (int i = 0; i < difference.Length; i++)
            {
                difference[i] = new double[a[0].Length];
            }

            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a[i].Length; j++)
                {
                    difference[i][j] = a[i][j] - b[i][j];
                }
            }

            return difference;
        }

        /// <summary>
        /// Matrix transpose
        /// </summary>
        /// <param name="a"></param>
        /// <returns></returns>
        public double[][] transpose(double[][] a)
        {
            double[][] temp = new double[a[0].Length][];

            for (int i = 0; i < temp.Length; i++)
            {
                temp[i] = new double[a.Length];
            }

            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a[i].Length; j++)
                {
                    temp[j][i] = a[i][j];
                }
            }

            return temp;
        }
    }
}
