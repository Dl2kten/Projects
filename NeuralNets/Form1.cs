using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace NeuralNets
{
    public partial class Form1 : Form
    {
        private Network net, fNet1, fNet2, fNet3, fNet4;
        private System.Windows.Forms.Timer myTimer;
        private TrainingData testSample;
        private Bitmap sample;
        private Fruits fruit;
        private FruitsTestData ftd;
        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Initializes variables and displays prompt
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Load(object sender, EventArgs e)
        {
            int[] neurons = { 784, 30, 10 };
            net = new Network(neurons);
            int[] layers = { 2500, 60, 60, 60, 60, 52 };
            fNet1 = new Network(layers);
            fNet2 = new Network(layers);
            fNet3 = new Network(layers);
            fNet4 = new Network(layers);

            fruit = new Fruits();
            ftd = new FruitsTestData();
            sample = null;

            displayBox.SelectionStart = displayBox.Text.Length;
            displayBox.ScrollToCaret();
            displayBox.ScrollBars = ScrollBars.Vertical;
            displayBox.Text = "Click on initilize network to start. \n";

            myTimer = new System.Windows.Forms.Timer();
            myTimer.Interval = 5000;
            myTimer.Tick += new EventHandler(OnTimedEvent);
        }

        private void OnTimedEvent(object sender, EventArgs e)
        {
            displayBox.AppendText("5");

            if (net.getUpdate())
            {
                string progress = net.getProgress();
                displayBox.AppendText(progress + "\n");
            }
        }

        /// <summary>
        /// Identifies image passed in and returns digit
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void identify_Click(object sender, EventArgs e)
        {
            if (testSample.getTestSample() != null)
            {
                int digit = net.identify(testSample.getTestSample());
                displayBox.AppendText("The image shown is: " + digit + ".\n");
            }
            else
            {
                displayBox.AppendText("Please load image first.");
            }
        }


        /// <summary>
		/// Identifies fruit in 1st section of folders
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void Id1_Click(object sender, EventArgs e)
        {
            Bitmap srcImage = sample;
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
            testSample = new TrainingData(temp);

            if (testSample.getTestSample() != null)
            {
                int digit = fNet1.identify(testSample.getTestSample());

                switch (digit)
                {
                    case 0:
                        displayBox.AppendText("The image shown is: Apple Braeburn.\n");
                        break;
                    case 1:
                        displayBox.AppendText("The image shown is: Apple Golden 1.\n");
                        break;
                    case 2:
                        displayBox.AppendText("The image shown is: Apple Golden 2.\n");
                        break;
                    case 3:
                        displayBox.AppendText("The image shown is: Apple Granny Smith.\n");
                        break;
                    case 4:
                        displayBox.AppendText("The image shown is: Apple Red 1.\n");
                        break;
                    case 5:
                        displayBox.AppendText("The image shown is: Apple Red 2.\n");
                        break;
                    case 6:
                        displayBox.AppendText("The image shown is: Apple Red Delicious.\n");
                        break;
                    case 7:
                        displayBox.AppendText("The image shown is: Apple Red Yellow.\n");
                        break;
                    case 8:
                        displayBox.AppendText("The image shown is: Appicot.\n");
                        break;
                    case 9:
                        displayBox.AppendText("The image shown is: Avocado Ripe.\n");
                        break;
                    case 10:
                        displayBox.AppendText("The image shown is: Banana.\n");
                        break;
                    case 11:
                        displayBox.AppendText("The image shown is: Banana Red.\n");
                        break;
                    case 12:
                        displayBox.AppendText("The image shown is: Cactus Fruit.\n");
                        break;
                    default:
                        displayBox.AppendText("The image shown is: can't tell.\n");
                        break;
                }
            }
            else
            {
                displayBox.AppendText("Please load image first.");
            }

        }

        /// <summary>
        /// Identifies fruits from second section
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Id2_Click(object sender, EventArgs e)
		{
			Bitmap srcImage = sample;
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
			testSample = new TrainingData(temp);

			if (testSample.getTestSample() != null)
			{
				int digit = fNet2.identify(testSample.getTestSample());

				switch (digit)
				{
					case 13:
						displayBox.AppendText("The image shown is: Carambula.\n");
						break;
					case 14:
						displayBox.AppendText("The image shown is: Cherry.\n");
						break;
					case 15:
						displayBox.AppendText("The image shown is: Clementine.\n");
						break;
					case 16:
						displayBox.AppendText("The image shown is: Cocos.\n");
						break;
					case 17:
						displayBox.AppendText("The image shown is: Dates.\n");
						break;
					case 18:
						displayBox.AppendText("The image shown is: Granadilla.\n");
						break;
					case 19:
						displayBox.AppendText("The image shown is: Grape Pink.\n");
						break;
					case 20:
						displayBox.AppendText("The image shown is: Grape White.\n");
						break;
					case 21:
						displayBox.AppendText("The image shown is: Grape White 2.\n");
						break;
					case 22:
						displayBox.AppendText("The image shown is: Grapefruit Pink.\n");
						break;
					case 23:
						displayBox.AppendText("The image shown is: Grapefruit White.\n");
						break;
					case 24:
						displayBox.AppendText("The image shown is: Guava.\n");
						break;
					case 25:
						displayBox.AppendText("The image shown is: Huckleberry.\n");
						break;
					default:
						displayBox.AppendText("The image shown is: can't tell.\n");
						break;
				}
			}
			else
			{
				displayBox.AppendText("Please load image first.");
			}
		}

        /// <summary>
        /// Identifies fruits from third section
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Id3_Click(object sender, EventArgs e)
		{
			Bitmap srcImage = sample;
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
			testSample = new TrainingData(temp);

			if (testSample.getTestSample() != null)
			{
				int digit = fNet3.identify(testSample.getTestSample());

				switch (digit)
				{
					case 26:
						displayBox.AppendText("The image shown is: Kaki.\n");
						break;
					case 27:
						displayBox.AppendText("The image shown is: Kumquats.\n");
						break;
					case 28:
						displayBox.AppendText("The image shown is: Lemon Meyer.\n");
						break;
					case 29:
						displayBox.AppendText("The image shown is: Limes.\n");
						break;
					case 30:
						displayBox.AppendText("The image shown is: Litchi.\n");
						break;
					case 31:
						displayBox.AppendText("The image shown is: Mandarine.\n");
						break;
					case 32:
						displayBox.AppendText("The image shown is: Mango.\n");
						break;
					case 33:
						displayBox.AppendText("The image shown is: Maracuja.\n");
						break;
					case 34:
						displayBox.AppendText("The image shown is: Nectarine.\n");
						break;
					case 35:
						displayBox.AppendText("The image shown is: Papaya.\n");
						break;
					case 36:
						displayBox.AppendText("The image shown is: Passion Fruit.\n");
						break;
					case 37:
						displayBox.AppendText("The image shown is: Peach.\n");
						break;
					case 38:
						displayBox.AppendText("The image shown is: Peach Flat.\n");
						break;
					default:
						displayBox.AppendText("The image shown is: can't tell.\n");
						break;
				}
			}
			else
			{
				displayBox.AppendText("Please load image first.");
			}
		}

        /// <summary>
        /// Initialize selected fruit network from combo box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void InitializeComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            double[][][][] trainingData;
            double[][][][] testData;
            displayBox.AppendText("Network initilized with [10000, 30, 52] \n");

            string file_path = "";
            FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog();
            folderBrowserDialog.ShowNewFolderButton = true;

            DialogResult result = folderBrowserDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                file_path = folderBrowserDialog.SelectedPath;
            }

            if (ftd.getFiles(file_path) == 1 || fruit.getFiles(file_path) == 1)
            {
                displayBox.AppendText("Invalid file location.\n");
                return;
            }

            int selectedIndex = InitializeComboBox.SelectedIndex;

            displayBox.AppendText("Reading and parsing training data" + (selectedIndex + 1) + "/4... \n");
            fruit.toBytes(selectedIndex);
            trainingData = fruit.getTrainingData();
            ftd.toBytes(selectedIndex);
            testData = ftd.getTestData();
            displayBox.AppendText("Finished reading and acquired data. \n");
            displayBox.AppendText("Now passing in to stochastic gradient descent with \n");

            switch (selectedIndex)
            {
                case 0:
                    fNet1.SGD(trainingData, 4, 10, 2.0, testData);
                    fNet1.SGD(trainingData, 10, 10, 0.9, testData);
                    break;
                case 1:
                    fNet2.SGD(trainingData, 5, 10, 3.0, testData);
                    fNet2.SGD(trainingData, 10, 10, 1.1, testData);
                    break;
                case 2:
                    fNet3.SGD(trainingData, 12, 10, 1.0, testData);
                    break;
                case 3:
                    fNet4.SGD(trainingData, 5, 10, 3.0, testData);
                    fNet4.SGD(trainingData, 10, 10, 1.2, testData);
                    break;
                default:
                    displayBox.AppendText("Huh? selected index for combo box out of bounds.");
                    break;
            }


            displayBox.AppendText("Reading and parsing testing data... \n");

            string progress = net.getProgress();
            displayBox.AppendText(progress + "\n");
        }

        /// <summary>
        /// Save trained data to specific fruit network
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SaveComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            double[][][] biases = null;
            double[][][] weights = null;

            int selectedIndex = InitializeComboBox.SelectedIndex;

            switch(selectedIndex)
            {
                case 0:
                    biases = fNet1.getBiases();
                    weights = fNet1.getWeights();
                    break;
                case 1:
                    biases = fNet2.getBiases();
                    weights = fNet2.getWeights();
                    break;
                case 2:
                    biases = fNet3.getBiases();
                    weights = fNet3.getWeights();
                    break;
                case 3:
                    biases = fNet4.getBiases();
                    weights = fNet4.getWeights();
                    break;
                default:
                    displayBox.AppendText("Save combo box index out of range.");
                    break;
            }

            String file_biases = "new_fBiases" + selectedIndex + ".txt";
            String file_weights = "new_fWeights" + selectedIndex + ".txt";



            using (StreamWriter b_writer = new StreamWriter(file_biases, false))
            {
                for (int i = 0; i < biases.Length; i++)
                {
                    for (int j = 0; j < biases[i].Length; j++)
                    {
                        for (int k = 0; k < biases[i][j].Length; k++)
                        {
                            b_writer.WriteLine(biases[i][j][k]);
                            //File.AppendAllText(file_biases, biases[i][j][k] + System.Environment.NewLine);
                        }
                    }
                }
            }

            using (StreamWriter f_writer = new StreamWriter(file_weights, false))
            {
                for (int i = 0; i < weights.Length; i++)
                {
                    for (int j = 0; j < weights[i].Length; j++)
                    {
                        for (int k = 0; k < weights[i][j].Length; k++)
                        {
                            f_writer.WriteLine(weights[i][j][k]);
                            //File.AppendAllText(file_weights, weights[i][j][k] + System.Environment.NewLine);
                        }
                    }
                }
            }
        }


        /// <summary>
        /// Identifies fruits from fourth section
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Id4_Click(object sender, EventArgs e)
		{
			Bitmap srcImage = sample;
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
			testSample = new TrainingData(temp);

			if (testSample.getTestSample() != null)
			{
				int digit = fNet4.identify(testSample.getTestSample());

				switch (digit)
				{
					case 39:
						displayBox.AppendText("The image shown is: Pear.\n");
						break;
					case 40:
						displayBox.AppendText("The image shown is: Pear Abate.\n");
						break;
					case 41:
						displayBox.AppendText("The image shown is: Pear Monster.\n");
						break;
					case 42:
						displayBox.AppendText("The image shown is: Pear Williams.\n");
						break;
					case 43:
						displayBox.AppendText("The image shown is: Pepino.\n");
						break;
					case 44:
						displayBox.AppendText("The image shown is: Pineapple.\n");
						break;
					case 45:
						displayBox.AppendText("The image shown is: Pitahaya Red.\n");
						break;
					case 46:
						displayBox.AppendText("The image shown is: Quince.\n");
						break;
					case 47:
						displayBox.AppendText("The image shown is: Raspberry.\n");
						break;
					case 48:
						displayBox.AppendText("The image shown is: Salak.\n");
						break;
					case 49:
						displayBox.AppendText("The image shown is: Strawberry.\n");
						break;
					case 50:
						displayBox.AppendText("The image shown is: Tamarillo.\n");
						break;
					case 51:
						displayBox.AppendText("The image shown is: Tangelo.\n");
						break;
					default:
						displayBox.AppendText("The image shown is: can't tell.\n");
						break;
				}
			}
			else
			{
				displayBox.AppendText("Please load image first.");
			}
		}





        /// <summary>
        /// Change rgb to grey
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
                    pixel[y][x] = (byte)(grey);
                }
            }

            return pixel;
        }

        /// <summary>
        /// Loads saved biases and weights to the four networks
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void loadFruitsBW_Click(object sender, EventArgs e)
        {
            string[] blines = File.ReadAllLines("fBiases1.txt");
            string[] wlines = File.ReadAllLines("fWeights.txt");
            //assuming your matrix is initialized with 0s
            double[][][] biases = fNet1.getBiases();
            double[][][] weights = fNet1.getWeights();
            int count = 0;

            for (int i = 0; i < biases.Length; i++)
            {
                for (int j = 0; j < biases[i].Length; j++)
                {
                    for (int k = 0; k < biases[i][j].Length; k++)
                    {
                        biases[i][j][k] = double.Parse(blines[count++]);
                    }
                }
            }

            count = 0;

            for (int i = 0; i < weights.Length; i++)
            {
                for (int j = 0; j < weights[i].Length; j++)
                {
                    for (int k = 0; k < weights[i][j].Length; k++)
                    {
                        weights[i][j][k] = double.Parse(wlines[count++]);
                    }
                }
            }

			string[] blines2 = File.ReadAllLines("fBiases2.txt");
			string[] wlines2 = File.ReadAllLines("fWeights2.txt");
			double[][][] biases2 = fNet2.getBiases();
			double[][][] weights2 = fNet2.getWeights();

			count = 0;

			for (int i = 0; i < biases.Length; i++)
			{
				for (int j = 0; j < biases[i].Length; j++)
				{
					for (int k = 0; k < biases[i][j].Length; k++)
					{
						biases2[i][j][k] = double.Parse(blines2[count++]);
					}
				}
			}

			count = 0;

			for (int i = 0; i < weights.Length; i++)
			{
				for (int j = 0; j < weights[i].Length; j++)
				{
					for (int k = 0; k < weights[i][j].Length; k++)
					{
						weights2[i][j][k] = double.Parse(wlines2[count++]);
					}
				}
			}

			string[] blines3 = File.ReadAllLines("fBiases3.txt");
			string[] wlines3 = File.ReadAllLines("fWeights3.txt");
			double[][][] biases3 = fNet3.getBiases();
			double[][][] weights3 = fNet3.getWeights();

			count = 0;

			for (int i = 0; i < biases.Length; i++)
			{
				for (int j = 0; j < biases[i].Length; j++)
				{
					for (int k = 0; k < biases[i][j].Length; k++)
					{
						biases3[i][j][k] = double.Parse(blines3[count++]);
					}
				}
			}

			count = 0;

			for (int i = 0; i < weights.Length; i++)
			{
				for (int j = 0; j < weights[i].Length; j++)
				{
					for (int k = 0; k < weights[i][j].Length; k++)
					{
						weights3[i][j][k] = double.Parse(wlines3[count++]);
					}
				}
			}

			string[] blines4 = File.ReadAllLines("fBiases4.txt");
			string[] wlines4 = File.ReadAllLines("fWeights4.txt");
			double[][][] biases4 = fNet4.getBiases();
			double[][][] weights4 = fNet4.getWeights();

			count = 0;

			for (int i = 0; i < biases.Length; i++)
			{
				for (int j = 0; j < biases[i].Length; j++)
				{
					for (int k = 0; k < biases[i][j].Length; k++)
					{
						biases4[i][j][k] = double.Parse(blines4[count++]);
					}
				}
			}

			count = 0;

			for (int i = 0; i < weights.Length; i++)
			{
				for (int j = 0; j < weights[i].Length; j++)
				{
					for (int k = 0; k < weights[i][j].Length; k++)
					{
						weights4[i][j][k] = double.Parse(wlines4[count++]);
					}
				}
			}
		}

        /// <summary>
        /// Loads in test sample
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void loadFruit_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd;
            String path;
            ofd = new OpenFileDialog();
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                path = ofd.FileName;
                pictureBox1.ImageLocation = path;
                sample = new Bitmap(path);
            }
        }


    }
}
