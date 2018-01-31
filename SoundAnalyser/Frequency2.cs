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
    public partial class Frequency2 : Form
    {
        private double[] x, y, filter, realValues, imValues;
        private Boolean added;
        /// <summary>
        /// Window for right channel showing frequency domain
        /// </summary>
        public Frequency2()
        {
            InitializeComponent();

            added = false;
        }
        /// <summary>
        /// Populates series with data poins and draws data
        /// </summary>
        /// <param name="x">double[] x values</param>
        /// <param name="y">double[] y values</param>
        public void drawFrequency(double[] x, double[] y)
        {
            this.x = x;
            this.y = y;

            chart1.Series.Clear();//clears chart

            Series s1 = new Series("Frequency Graph2");
            s1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.RangeColumn;

            if (!added)
            {
                chart1.Titles.Add("Frequency for right channel");
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
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("Select values first please.");
            }
            chart1.Series.Add(s1);

            chart1.Series[0].IsValueShownAsLabel = false;
            chart1.Series[0].IsVisibleInLegend = false;
        }
        /// <summary>
        /// Zooms into frequency graph
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void zoomIn_Click(object sender, EventArgs e)
        {
            double xStart = chart1.ChartAreas[0].CursorX.SelectionStart;
            double xEnd = chart1.ChartAreas[0].CursorX.SelectionEnd;

            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(xStart, xEnd);
        }
        /// <summary>
        /// Zooms out into orginal view
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void zoomOut_Click(object sender, EventArgs e)
        {
            chart1.ChartAreas[0].AxisX.ScaleView.ZoomReset(1);
            chart1.ChartAreas[0].AxisY.ScaleView.ZoomReset(1);
        }
        /// <summary>
        /// Selects the filtered values desired
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void filterSelect_Click(object sender, EventArgs e)
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

            for (int i = 0; i < x.Length; i++)
            {
                if (i >= xStart && i <= xEnd)
                {
                    filter[i] = 1;
                }
                else
                {
                    if (i >= xStart2 && i <= xEnd2)
                    {
                        filter[i] = 1;
                    }
                    else
                    {
                        filter[i] = 0;
                    }
                }
            }
        }
        /// <summary>
        /// Highlights the section that is being selected along with the mirror from the opposite side
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void chart1_SelectionRangeChanged_1(object sender, CursorEventArgs e)
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
                //sLine.BackColor = Color.Aqua;
                chart1.ChartAreas[0].AxisX.StripLines.Add(sLine);

                int beginning = (int)(x[x.Length - 1] / 2
                    - chart1.ChartAreas[0].CursorX.SelectionEnd + 0.5);
                mirror.Interval = 0;
                mirror.StripWidth = difference;
                mirror.IntervalOffset = (int)(x[x.Length - 1] / 2 + 0.5) + beginning;
                mirror.BackColor = Color.Pink;
                chart1.ChartAreas[0].AxisX.StripLines.Add(mirror);
            }
        }
        /// <summary>
        /// Highlights selected area after selection, mirror values also highlighted
        /// </summary>
        /// <param name="sender">Window</param>
        /// <param name="e">Event</param>
        private void chart1_SelectionRangeChanging_1(object sender, CursorEventArgs e)
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
        /// Gets the selected filter values
        /// </summary>
        /// <returns>double[] filter values</returns>
        public double[] getFilter()
        {
            return filter;
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
