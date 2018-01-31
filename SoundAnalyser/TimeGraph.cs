using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Interface
{
    public partial class TimeGraph : Form
    {
        private double[] x, y, xCopy, yCopy;
        private int N;
        private Series s1;
        private Random generator;
        /// <summary>
        /// Displays wav files in time domain
        /// </summary>
        public TimeGraph()
        {
            InitializeComponent();
            DoubleBuffered = true;
            generator = new Random();
            /*
            x = new double[50];
            y = new double[50];

            double j = 0;

            for(int i = 0; i < x.Length; i++)
            {
                x[i] = (double) i;
                y[i] = Math.Sin(2 * Math.PI * j) + Math.Sin(6 * Math.PI * j);
                j += 0.1;
            }

            N = 0;
            */
            chartSetup();
            //chartDisplay2(x, y);
        }

        /**
         * Sets up the properties of the chart, including the series to be added,
         * the x and y axis and the labels, disables automatic zoom, allows for user
         * selection
         * */
        private void chartSetup()
        {
            Color myColor = new Color();
            int r = generator.Next(256);
            int g = generator.Next(256);
            int b = generator.Next(256);

            myColor = Color.FromArgb(r, g, b);
            s1 = new Series("Left Channel");
            s1.ChartType = SeriesChartType.FastLine;
            s1.BorderWidth = 2;
            s1.Color = myColor;
            chart1.Series.Add(s1);

            chart1.Titles.Add("Left Channel Wave");
            chart1.ChartAreas[0].AxisX.Minimum = 0;
            chart1.ChartAreas[0].AxisX.LabelStyle.Format = "{#.##}";
            chart1.ChartAreas[0].AxisX.Title = "Samples";
            chart1.ChartAreas[0].AxisX.TextOrientation = TextOrientation.Horizontal;

            chart1.ChartAreas[0].AxisY.Title = "Amplitude";
            chart1.ChartAreas[0].AxisY.LabelStyle.Format = "{#.#}";

            chart1.ChartAreas[0].CursorX.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoomable = false;
            chart1.ChartAreas[0].AxisX.ScrollBar.BackColor = System.Drawing.Color.LightSteelBlue;
            chart1.ChartAreas[0].AxisX.ScrollBar.ButtonStyle = ScrollBarButtonStyles.None;
            chart1.ChartAreas[0].AxisX.ScrollBar.LineColor = Color.Azure;
            chart1.ChartAreas[0].AxisX.ScrollBar.ButtonColor = Color.BurlyWood;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(0, 10000);

            chart1.ChartAreas[0].CursorX.AutoScroll = true;
            chart1.ChartAreas[0].CursorX.SelectionColor = Color.Aqua;
            chart1.ChartAreas[0].CursorY.AutoScroll = true;
            chart1.ChartAreas[0].CursorY.SelectionColor = Color.Aqua;

            chart1.ChartAreas[0].CursorY.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisY.ScaleView.Zoomable = false;

            chart1.ChartAreas[0].AxisY.ScrollBar.BackColor = System.Drawing.Color.LightSteelBlue;
            chart1.ChartAreas[0].AxisY.ScrollBar.ButtonStyle = ScrollBarButtonStyles.None;
            chart1.ChartAreas[0].AxisY.ScrollBar.LineColor = Color.Azure;
            chart1.ChartAreas[0].AxisY.ScrollBar.ButtonColor = Color.Aquamarine;

            chart1.ChartAreas[0].CursorX.SelectionColor = Color.PaleTurquoise;
            chart1.ChartAreas[0].CursorY.SelectionColor = Color.PaleTurquoise;
        }

        /**
         * Adds the points to the series to be displayed
         * @param takes in two double arrays for x and y
         * */
        public void chartDisplay2(double[] x, double[] y)
        {
            this.x = x;
            this.y = y;
            //change x by multiplying by 1/samplerate to get time?
            var data = s1.Points;

            data.SuspendUpdates();
            for (int i = s1.Points.Count - 1; i >= 0; i--)
            {
                if(s1.Points.Count > 0)
                    s1.Points.RemoveAt(i);
            }
            data.ResumeUpdates();

            data.SuspendUpdates();

            for (int i = 0; i < x.Length; i++)
            {
                data.AddXY(i, y[i]);
            }

            data.ResumeUpdates();
        }
        /**
         * Zooms in to selected area chosen by user
         * @param sender is the window
         * @param e is the event
         * */
        private void zoomInToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double xStart = chart1.ChartAreas[0].CursorX.SelectionStart;
            double xEnd = chart1.ChartAreas[0].CursorX.SelectionEnd;
            //double yStart = chart1.ChartAreas[0].CursorY.SelectionStart;
            //double yEnd = chart1.ChartAreas[0].CursorY.SelectionEnd;

            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(xStart, xEnd);// DateTimeIntervalType.Auto, true);
            //chart1.ChartAreas[0].AxisY.ScaleView.Zoom(yEnd, yStart, DateTimeIntervalType.Auto, true);
        }
        /// <summary>
        /// Cuts out the selected section of the graph
        /// </summary>
        /// <param name="sender">window</param>
        /// <param name="e">event</param>
        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int xStart = (int)chart1.ChartAreas[0].CursorX.SelectionStart;
            int xEnd = (int)chart1.ChartAreas[0].CursorX.SelectionEnd;

            if(xEnd > x.Length - 1)
            {
                xEnd = (int) (x.Length - 1);
            }

            int interval = xEnd - xStart + 1;
            int increment = xStart + interval;
            int xCount = xStart;
            double[] temp = new Double[x.Length - interval];
            double[] temp2 = new Double[y.Length - interval];
            xCopy = new Double[interval];
            yCopy = new Double[interval];

            for (int i = 0; i < interval; i++)
            {
                xCopy[i] = x[xCount];//increment after assignment
                yCopy[i] = y[xCount];
                xCount++;
            }
            /*Let's say there are 6 ints, 0 - 5, if you take out 2 and 3 the interval would be 1.
             * Needs to plus 1 to find the n.  6 - 2 = 4, if xStart is 2 it goes up to 3 so it would
             * be 0-3.
             */

            for (int i = xStart; i < x.Length - interval; i++)
            {
                y[i] = y[increment++];
            }

            for (int i = 0; i < temp.Length; i++)
            {
                temp[i] = x[i];
            }

            x = temp;

            for (int i = 0; i < temp2.Length; i++)
            {
                temp2[i] = y[i];
            }

            y = temp2;

            chartDisplay2(x, y);
        }
        /// <summary>
        /// Pastes cut/copy selection into desired portion of graph
        /// </summary>
        /// <param name="sender">window</param>
        /// <param name="e">event</param>
        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int xStart = (int)chart1.ChartAreas[0].CursorX.SelectionStart;
            int j = 0, k = 0;
            double[] temp = new Double[x.Length + xCopy.Length];
            double[] temp2 = new Double[x.Length + xCopy.Length];

            for (int i = 0; i < temp.Length; i++)
            {
                if (i >= xStart && j < xCopy.Length)
                {
                    temp2[i] = yCopy[j];
                    j++;
                }
                else
                {
                    temp2[i] = y[k];
                    k++;
                }
            }

            for (int i = 0; i < temp.Length; i++)
            {
                temp[i] = i;
            }

            x = temp;
            y = temp2;

            chartDisplay2(x, y);
        }
        /// <summary>
        /// Copies selected values to double[]
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int xStart = (int)chart1.ChartAreas[0].CursorX.SelectionStart;
            int xEnd = (int)chart1.ChartAreas[0].CursorX.SelectionEnd;

            if (xEnd > x.Length - 1)
            {
                xEnd = (int)(x.Length - 1);
            }

            int interval = xEnd - xStart + 1;
            int count = xStart;
            xCopy = new Double[interval];
            yCopy = new Double[interval];

            for (int i = 0; i < interval; i++)
            {
                xCopy[i] = x[count];//increment after assignment
                yCopy[i] = y[count];
                count++;
            }
        }
        /// <summary>
        /// Zooms out to view whole wave
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void zoomOutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            chart1.ChartAreas[0].AxisX.ScaleView.ZoomReset(1);
            chart1.ChartAreas[0].AxisY.ScaleView.ZoomReset(1);
        }
        /// <summary>
        /// Selects a portion of the graph and copies the values for forward fourier
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void selectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int xStart = (int)chart1.ChartAreas[0].CursorX.SelectionStart;
            int xEnd = (int)chart1.ChartAreas[0].CursorX.SelectionEnd;
            N = xEnd - xStart + 1;

            int count = xStart;
            xCopy = new Double[N];
            yCopy = new Double[N];

            for (int i = 0; i < N; i++)
            {
                if(count < x.Length)
                {
                    xCopy[i] = x[count];
                    yCopy[i] = y[count];
                    count++;
                }
            }
        }
        /// <summary>
        /// Applies square windowing technique to samples
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void squareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double[] w = new double[N];

            for(int i = 0; i < N; i++)
            {
                w[i] = 1;
            }

            for(int i = 0; i < N; i++)
            {
                yCopy[i] *= w[i];
            }
        }
        /// <summary>
        /// Applies triangle windowing technique to selected samples
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void triangleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double[] w = new double[N];

            for (int i = 0; i < N; i++)
            {
                w[i] = 1 - Math.Abs((i - (N - 1) / 2) / (N / 2));
            }

            for (int i = 0; i < N; i++)
            {
                yCopy[i] *= w[i];
            }
        }
        /// <summary>
        /// Applies hamming windowing technique to selected values
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void hammingToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double[] w = new double[N];

            for (int i = 0; i < N; i++)
            {
                w[i] = 0.54 - 0.46 * Math.Cos(2 * Math.PI* i / N);
            }

            for (int i = 0; i < N; i++)
            {
                yCopy[i] *= w[i];
            }
        }
        /// <summary>
        /// Gets the copy of x values
        /// </summary>
        /// <returns>double[] copy of x values</returns>
        public double[] getXValues()
        {
            return xCopy;
        }
        /// <summary>
        /// Gets the copy of y values
        /// </summary>
        /// <returns>double[] copy of y values</returns>
        public double[] getYValues()
        {
            return yCopy;
        }
        /// <summary>
        /// Gets the original x values
        /// </summary>
        /// <returns>double[] x values</returns>
        public double[] getX()
        {
            return x;
        }
        /// <summary>
        /// Gets the original y values
        /// </summary>
        /// <returns>double[] y values</returns>
        public double[] getY()
        {
            return y;
        }
        /// <summary>
        /// Gets the number of samples
        /// </summary>
        /// <returns>int number of samples</returns>
        public int getN()
        {
            return N;
        }
        /// <summary>
        /// Sets the x values
        /// </summary>
        /// <param name="x">double[] x values</param>
        public void setX(double[] x)
        {
            this.x = x;
        }
        /// <summary>
        /// Sets the y values
        /// </summary>
        /// <param name="y">double[] y values</param>
        public void setY(double[] y)
        {
            this.y = y;
        }
    }
}
