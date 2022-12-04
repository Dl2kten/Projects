namespace NeuralNets
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.displayBox = new System.Windows.Forms.TextBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.loadFruit = new System.Windows.Forms.Button();
            this.Id1 = new System.Windows.Forms.Button();
            this.Id2 = new System.Windows.Forms.Button();
            this.Id3 = new System.Windows.Forms.Button();
            this.Id4 = new System.Windows.Forms.Button();
            this.loadFruitsBW = new System.Windows.Forms.Button();
            this.InitializeComboBox = new System.Windows.Forms.ComboBox();
            this.SaveComboBox = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // displayBox
            // 
            this.displayBox.Location = new System.Drawing.Point(11, 10);
            this.displayBox.Margin = new System.Windows.Forms.Padding(2);
            this.displayBox.Multiline = true;
            this.displayBox.Name = "displayBox";
            this.displayBox.Size = new System.Drawing.Size(583, 240);
            this.displayBox.TabIndex = 2;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.pictureBox1.Location = new System.Drawing.Point(696, 10);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(252, 240);
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // loadFruit
            // 
            this.loadFruit.Location = new System.Drawing.Point(696, 310);
            this.loadFruit.Name = "loadFruit";
            this.loadFruit.Size = new System.Drawing.Size(128, 25);
            this.loadFruit.TabIndex = 10;
            this.loadFruit.Text = "Load Fruit for Testing";
            this.loadFruit.UseVisualStyleBackColor = true;
            this.loadFruit.Click += new System.EventHandler(this.loadFruit_Click);
            // 
            // Id1
            // 
            this.Id1.Location = new System.Drawing.Point(696, 270);
            this.Id1.Name = "Id1";
            this.Id1.Size = new System.Drawing.Size(42, 23);
            this.Id1.TabIndex = 11;
            this.Id1.Text = "Id 1";
            this.Id1.UseVisualStyleBackColor = true;
            this.Id1.Click += new System.EventHandler(this.Id1_Click);
            // 
            // Id2
            // 
            this.Id2.Location = new System.Drawing.Point(744, 270);
            this.Id2.Name = "Id2";
            this.Id2.Size = new System.Drawing.Size(42, 23);
            this.Id2.TabIndex = 13;
            this.Id2.Text = "Id 2";
            this.Id2.UseVisualStyleBackColor = true;
            this.Id2.Click += new System.EventHandler(this.Id2_Click);
            // 
            // Id3
            // 
            this.Id3.Location = new System.Drawing.Point(792, 270);
            this.Id3.Name = "Id3";
            this.Id3.Size = new System.Drawing.Size(42, 23);
            this.Id3.TabIndex = 14;
            this.Id3.Text = "Id 3";
            this.Id3.UseVisualStyleBackColor = true;
            this.Id3.Click += new System.EventHandler(this.Id3_Click);
            // 
            // Id4
            // 
            this.Id4.Location = new System.Drawing.Point(840, 270);
            this.Id4.Name = "Id4";
            this.Id4.Size = new System.Drawing.Size(42, 23);
            this.Id4.TabIndex = 15;
            this.Id4.Text = "Id 4";
            this.Id4.UseVisualStyleBackColor = true;
            this.Id4.Click += new System.EventHandler(this.Id4_Click);
            // 
            // loadFruitsBW
            // 
            this.loadFruitsBW.Location = new System.Drawing.Point(313, 267);
            this.loadFruitsBW.Name = "loadFruitsBW";
            this.loadFruitsBW.Size = new System.Drawing.Size(116, 21);
            this.loadFruitsBW.TabIndex = 16;
            this.loadFruitsBW.Text = "Load Fruits B/W";
            this.loadFruitsBW.UseVisualStyleBackColor = true;
            this.loadFruitsBW.Click += new System.EventHandler(this.loadFruitsBW_Click);
            // 
            // InitializeComboBox
            // 
            this.InitializeComboBox.Items.AddRange(new object[] {
            "FNet1",
            "FNet2",
            "FNet3",
            "FNet4"});
            this.InitializeComboBox.Location = new System.Drawing.Point(12, 267);
            this.InitializeComboBox.Name = "InitializeComboBox";
            this.InitializeComboBox.Size = new System.Drawing.Size(127, 21);
            this.InitializeComboBox.TabIndex = 20;
            this.InitializeComboBox.Text = "Initialize Fruit Network";
            this.InitializeComboBox.SelectedIndexChanged += new System.EventHandler(this.InitializeComboBox_SelectedIndexChanged);
            // 
            // SaveComboBox
            // 
            this.SaveComboBox.FormattingEnabled = true;
            this.SaveComboBox.Items.AddRange(new object[] {
            "FNet1",
            "FNet2",
            "FNet3",
            "FNet4"});
            this.SaveComboBox.Location = new System.Drawing.Point(145, 267);
            this.SaveComboBox.Name = "SaveComboBox";
            this.SaveComboBox.Size = new System.Drawing.Size(162, 21);
            this.SaveComboBox.TabIndex = 19;
            this.SaveComboBox.Text = "Save Biases and Weights";
            this.SaveComboBox.SelectedIndexChanged += new System.EventHandler(this.SaveComboBox_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1002, 366);
            this.Controls.Add(this.SaveComboBox);
            this.Controls.Add(this.InitializeComboBox);
            this.Controls.Add(this.loadFruitsBW);
            this.Controls.Add(this.Id4);
            this.Controls.Add(this.Id3);
            this.Controls.Add(this.Id2);
            this.Controls.Add(this.Id1);
            this.Controls.Add(this.loadFruit);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.displayBox);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox displayBox;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button loadFruit;
        private System.Windows.Forms.Button Id1;
        private System.Windows.Forms.Button Id2;
        private System.Windows.Forms.Button Id3;
        private System.Windows.Forms.Button Id4;
        private System.Windows.Forms.Button loadFruitsBW;
        private System.Windows.Forms.ComboBox InitializeComboBox;
        private System.Windows.Forms.ComboBox SaveComboBox;
    }
}

