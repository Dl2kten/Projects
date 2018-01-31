using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Interface
{
    public partial class Frequency : Form
    {
        private double[] x, y, filter, realValues, imValues;
        private Boolean added;
        /// <summary>
        /// Window for left channel showing frequency domain
        /// </summary>
        public Frequency()
        {
            InitializeComponent();
            x = new double[10];
            y = new double[10];

            for(int i = 0; i < x.Length; i++)
            {
                x[i] = i;
                y[i] = 1;
            }
            added = false;

            //drawFrequency(x, y);
            /* Originally had constructor take in two arrays but better to just have them in drawFrequency
            var series1 = chart1.Series[0];

            for (int i = 0; i < x.Length; i++)
            {
                series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.SplineRange;
                var index1 = series1.Points.AddXY(x[i], y[i]);
            }*/

        }

        /*This function is to display data passed in 
         in frequency domain
         */
        public void drawFrequency(double[] x, double[] y)
        {
            this.x = x;
            this.y = y;

            chart1.Series.Clear();//clears chart

            Series s1 = new Series("Frequency Graph");
            s1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.RangeColumn;

            if (!added)
            {
                chart1.Titles.Add("Frequency for left channel");
                added = true;
            }

            chart1.ChartAreas[0].AxisX.Title = "Frequency bins";
            chart1.ChartAreas[0].AxisY.Title = "Amplitude";

            //enable mouse selection
            chart1.ChartAreas[0].CursorX.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoomable = false;
            chart1.ChartAreas[0].AxisX.Minimum = 0;

            chart1.ChartAreas[0].CursorY.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisY.ScaleView.Zoomable = false;

            if (x != null)
            {
                for (int i = 0; i < x.Length; i++)
                {
                    s1.Points.AddXY(x[i], y[i]);
                }
            } else
            {
                System.Windows.Forms.MessageBox.Show("Select values first please.");
            }
            chart1.Series.Add(s1);

            chart1.Series[0].IsValueShownAsLabel = false;
            chart1.Series[0].IsVisibleInLegend = false;
        }

        /**
         * This button event lets user select the filter range
         * @param sender, event
         * */
        private void button1_Click(object sender, EventArgs e)
        {
            filter = new double[x.Length];

            int xStart = (int)chart1.ChartAreas[0].CursorX.SelectionStart;
            int xEnd = (int)chart1.ChartAreas[0].CursorX.SelectionEnd;
            int difference = xEnd - xStart;

            int middle = (int)(x[x.Length - 1] / 2 + 0.5);

            if (xEnd > middle)//can only select up to mirror value
                xEnd = middle;

            //sets up the mirrored frequencies to be selected as well
            int xStart2 = middle - xEnd;
            xStart2 += middle;
            int xEnd2 = xStart2 + difference;

            if (xStart == 0)//since there's no mirror for 0
                xEnd2--;

            for(int i = 0; i < x.Length; i++)
            {
                if(i >= xStart && i <= xEnd)
                {
                    filter[i] = 1;
                } else
                {
                    if (i >= xStart2 && i <= xEnd2)
                    {
                        filter[i] = 1;
                    } else
                    {
                        filter[i] = 0;
                    }
                }
            }
        }

        /**
         * Highlights selected area in different color, mirrored across middle
         * @param sender, event
         * */
        private void chart1_SelectionRangeChanged(object sender, CursorEventArgs e)
        {
            chart1.ChartAreas[0].AxisX.StripLines.Clear();
            double difference = chart1.ChartAreas[0].CursorX.SelectionEnd
                - chart1.ChartAreas[0].CursorX.SelectionStart;

            StripLine sLine = new StripLine();
            StripLine mirror = new StripLine();
            sLine.Interval = 0;
            if(difference >= 0)
            {
                sLine.StripWidth = difference;
                sLine.IntervalOffset = chart1.ChartAreas[0].CursorX.SelectionStart;
                //sLine.BackColor = Color.Aqua;
                chart1.ChartAreas[0].AxisX.StripLines.Add(sLine);

                int beginning = (int)(x[x.Length - 1] / 2
                    - chart1.ChartAreas[0].CursorX.SelectionEnd + 0.5);
                mirror.Interval = 0;
                mirror.StripWidth = difference;
                mirror.IntervalOffset = (int)(x[x.Length - 1] / 2 + 0.5) + beginning;
                mirror.BackColor = Color.Blue;
                chart1.ChartAreas[0].AxisX.StripLines.Add(mirror);
            }          
        }

        /**
         * Highlights selected area during selection, mirror across middle
         * @param sender, event
         * */
        private void chart1_SelectionRangeChanging(object sender, CursorEventArgs e)
        {
            chart1.ChartAreas[0].AxisX.StripLines.Clear();
            double difference = chart1.ChartAreas[0].CursorX.SelectionEnd
                - chart1.ChartAreas[0].CursorX.SelectionStart;

            StripLine sLine = new StripLine();
            StripLine mirror = new StripLine();
            sLine.Interval = 0;
            if (difference >= 0)
            {
                sLine.StripWidth = difference;
                sLine.IntervalOffset = chart1.ChartAreas[0].CursorX.SelectionStart;
                //sLine.ForeColor = Color.Blue; it's for text...
                chart1.ChartAreas[0].AxisX.StripLines.Add(sLine);

                int beginning = (int)(x[x.Length - 1] / 2
                    - chart1.ChartAreas[0].CursorX.SelectionEnd + 0.5);
                mirror.Interval = 0;
                mirror.StripWidth = difference;
                mirror.IntervalOffset = (int)(x[x.Length - 1] / 2 + 0.5) + beginning;
                mirror.BackColor = Color.Blue;
                chart1.ChartAreas[0].AxisX.StripLines.Add(mirror);
            }
        }
        /// <summary>
        /// Returns selected filter values
        /// </summary>
        /// <returns>double[] filter</returns>
        public double[] getFilter()
        {
            return filter;
        }
        /// <summary>
        /// Sets the real values from dft
        /// </summary>
        /// <param name="r">double[] real values</param>
        public void setRealValues(double[] r)
        {
            realValues = r;
        }
        /// <summary>
        /// Zooms into selected region
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void ZoomIn_Click(object sender, EventArgs e)
        {
            double xStart = chart1.ChartAreas[0].CursorX.SelectionStart;
            double xEnd = chart1.ChartAreas[0].CursorX.SelectionEnd;
            double yStart = chart1.ChartAreas[0].CursorY.SelectionStart;
            double yEnd = chart1.ChartAreas[0].CursorY.SelectionEnd;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(xStart, xEnd);
            chart1.ChartAreas[0].AxisY.ScaleView.Zoom(yEnd, yStart);
        }
        /// <summary>
        /// Zooms out to original view
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void ZoomOut_Click(object sender, EventArgs e)
        {
            chart1.ChartAreas[0].AxisX.ScaleView.ZoomReset(1);
            chart1.ChartAreas[0].AxisY.ScaleView.ZoomReset(1);
        }
        /// <summary>
        /// Sets the imaginary values from dft
        /// </summary>
        /// <param name="im">double[] imaginary values</param>
        public void setImValues(double[] im)
        {
            imValues = im;
        }
        /// <summary>
        /// Gets the real values passed in from dft
        /// </summary>
        /// <returns>double[] real values</returns>
        public double[] getReal()
        {
            return realValues;
        }
        /// <summary>
        /// Gets the imaginary values passed in from dft
        /// </summary>
        /// <returns>double[] imaginary values</returns>
        public double[] getIm()
        {
            return imValues;
        }
        /// <summary>
        /// Gets the number of samples
        /// </summary>
        /// <returns>int number of samples</returns>
        public int getN()
        {
            return x.Length;
        }
    }
}
