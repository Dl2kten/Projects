namespace Interface
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stereoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.fourierToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.forwardFourierToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.leftChannelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rightChannelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.recorderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openRecorderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.volumeUpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.volumeDownToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawDataToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.setDataToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.filterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.convolutionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.convolveLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.convolveRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.AllowMerge = false;
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.toolStripMenuItem2,
            this.fourierToolStripMenuItem,
            this.recorderToolStripMenuItem,
            this.filterToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.MdiWindowListItem = this.toolStripMenuItem2;
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1582, 28);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileToolStripMenuItem,
            this.saveFileToolStripMenuItem});
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(57, 24);
            this.openToolStripMenuItem.Text = "Open";
            // 
            // openFileToolStripMenuItem
            // 
            this.openFileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openLToolStripMenuItem,
            this.openRToolStripMenuItem,
            this.stereoToolStripMenuItem});
            this.openFileToolStripMenuItem.Name = "openFileToolStripMenuItem";
            this.openFileToolStripMenuItem.Size = new System.Drawing.Size(147, 26);
            this.openFileToolStripMenuItem.Text = "Open File";
            // 
            // openLToolStripMenuItem
            // 
            this.openLToolStripMenuItem.Name = "openLToolStripMenuItem";
            this.openLToolStripMenuItem.Size = new System.Drawing.Size(176, 26);
            this.openLToolStripMenuItem.Text = "Left Channel";
            this.openLToolStripMenuItem.Click += new System.EventHandler(this.openLToolStripMenuItem_Click);
            // 
            // openRToolStripMenuItem
            // 
            this.openRToolStripMenuItem.Name = "openRToolStripMenuItem";
            this.openRToolStripMenuItem.Size = new System.Drawing.Size(176, 26);
            this.openRToolStripMenuItem.Text = "Right Channel";
            this.openRToolStripMenuItem.Click += new System.EventHandler(this.openRToolStripMenuItem_Click);
            // 
            // stereoToolStripMenuItem
            // 
            this.stereoToolStripMenuItem.Name = "stereoToolStripMenuItem";
            this.stereoToolStripMenuItem.Size = new System.Drawing.Size(176, 26);
            this.stereoToolStripMenuItem.Text = "Stereo";
            this.stereoToolStripMenuItem.Click += new System.EventHandler(this.stereoToolStripMenuItem_Click);
            // 
            // saveFileToolStripMenuItem
            // 
            this.saveFileToolStripMenuItem.Name = "saveFileToolStripMenuItem";
            this.saveFileToolStripMenuItem.Size = new System.Drawing.Size(147, 26);
            this.saveFileToolStripMenuItem.Text = "Save File";
            this.saveFileToolStripMenuItem.Click += new System.EventHandler(this.saveFileToolStripMenuItem_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(76, 24);
            this.toolStripMenuItem2.Text = "Window";
            // 
            // fourierToolStripMenuItem
            // 
            this.fourierToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.forwardFourierToolStripMenuItem});
            this.fourierToolStripMenuItem.Name = "fourierToolStripMenuItem";
            this.fourierToolStripMenuItem.Size = new System.Drawing.Size(67, 24);
            this.fourierToolStripMenuItem.Text = "Fourier";
            // 
            // forwardFourierToolStripMenuItem
            // 
            this.forwardFourierToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.leftChannelToolStripMenuItem,
            this.rightChannelToolStripMenuItem});
            this.forwardFourierToolStripMenuItem.Name = "forwardFourierToolStripMenuItem";
            this.forwardFourierToolStripMenuItem.Size = new System.Drawing.Size(188, 26);
            this.forwardFourierToolStripMenuItem.Text = "Forward Fourier";
            // 
            // leftChannelToolStripMenuItem
            // 
            this.leftChannelToolStripMenuItem.Name = "leftChannelToolStripMenuItem";
            this.leftChannelToolStripMenuItem.Size = new System.Drawing.Size(176, 26);
            this.leftChannelToolStripMenuItem.Text = "Left Channel";
            this.leftChannelToolStripMenuItem.Click += new System.EventHandler(this.leftChannelToolStripMenuItem_Click);
            // 
            // rightChannelToolStripMenuItem
            // 
            this.rightChannelToolStripMenuItem.Name = "rightChannelToolStripMenuItem";
            this.rightChannelToolStripMenuItem.Size = new System.Drawing.Size(176, 26);
            this.rightChannelToolStripMenuItem.Text = "Right Channel";
            this.rightChannelToolStripMenuItem.Click += new System.EventHandler(this.rightChannelToolStripMenuItem_Click);
            // 
            // recorderToolStripMenuItem
            // 
            this.recorderToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openRecorderToolStripMenuItem,
            this.volumeUpToolStripMenuItem,
            this.volumeDownToolStripMenuItem,
            this.drawDataToolStripMenuItem,
            this.setDataToolStripMenuItem});
            this.recorderToolStripMenuItem.Name = "recorderToolStripMenuItem";
            this.recorderToolStripMenuItem.Size = new System.Drawing.Size(81, 24);
            this.recorderToolStripMenuItem.Text = "Recorder";
            // 
            // openRecorderToolStripMenuItem
            // 
            this.openRecorderToolStripMenuItem.Name = "openRecorderToolStripMenuItem";
            this.openRecorderToolStripMenuItem.Size = new System.Drawing.Size(184, 26);
            this.openRecorderToolStripMenuItem.Text = "Open Recorder";
            this.openRecorderToolStripMenuItem.Click += new System.EventHandler(this.openRecorderToolStripMenuItem_Click);
            // 
            // volumeUpToolStripMenuItem
            // 
            this.volumeUpToolStripMenuItem.Name = "volumeUpToolStripMenuItem";
            this.volumeUpToolStripMenuItem.Size = new System.Drawing.Size(184, 26);
            this.volumeUpToolStripMenuItem.Text = "Volume Up";
            this.volumeUpToolStripMenuItem.Click += new System.EventHandler(this.volumeUpToolStripMenuItem_Click);
            // 
            // volumeDownToolStripMenuItem
            // 
            this.volumeDownToolStripMenuItem.Name = "volumeDownToolStripMenuItem";
            this.volumeDownToolStripMenuItem.Size = new System.Drawing.Size(184, 26);
            this.volumeDownToolStripMenuItem.Text = "Volume Down";
            this.volumeDownToolStripMenuItem.Click += new System.EventHandler(this.volumeDownToolStripMenuItem_Click);
            // 
            // drawDataToolStripMenuItem
            // 
            this.drawDataToolStripMenuItem.Name = "drawDataToolStripMenuItem";
            this.drawDataToolStripMenuItem.Size = new System.Drawing.Size(184, 26);
            this.drawDataToolStripMenuItem.Text = "Draw Data";
            this.drawDataToolStripMenuItem.Click += new System.EventHandler(this.drawDataToolStripMenuItem_Click);
            // 
            // setDataToolStripMenuItem
            // 
            this.setDataToolStripMenuItem.Name = "setDataToolStripMenuItem";
            this.setDataToolStripMenuItem.Size = new System.Drawing.Size(184, 26);
            this.setDataToolStripMenuItem.Text = "Set Data";
            this.setDataToolStripMenuItem.Click += new System.EventHandler(this.setDataToolStripMenuItem_Click);
            // 
            // filterToolStripMenuItem
            // 
            this.filterToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.convolutionToolStripMenuItem});
            this.filterToolStripMenuItem.Name = "filterToolStripMenuItem";
            this.filterToolStripMenuItem.Size = new System.Drawing.Size(54, 24);
            this.filterToolStripMenuItem.Text = "Filter";
            // 
            // convolutionToolStripMenuItem
            // 
            this.convolutionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.convolveLToolStripMenuItem,
            this.convolveRToolStripMenuItem});
            this.convolutionToolStripMenuItem.Name = "convolutionToolStripMenuItem";
            this.convolutionToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.convolutionToolStripMenuItem.Text = "Convolution";
            // 
            // convolveLToolStripMenuItem
            // 
            this.convolveLToolStripMenuItem.Name = "convolveLToolStripMenuItem";
            this.convolveLToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.convolveLToolStripMenuItem.Text = "Left Channel";
            this.convolveLToolStripMenuItem.Click += new System.EventHandler(this.convolveLToolStripMenuItem_Click);
            // 
            // convolveRToolStripMenuItem
            // 
            this.convolveRToolStripMenuItem.Name = "convolveRToolStripMenuItem";
            this.convolveRToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.convolveRToolStripMenuItem.Text = "Right Channel";
            this.convolveRToolStripMenuItem.Click += new System.EventHandler(this.convolveRToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ClientSize = new System.Drawing.Size(1582, 1037);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fourierToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem forwardFourierToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem recorderToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openRecorderToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem volumeUpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem volumeDownToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawDataToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openFileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem filterToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem convolutionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveFileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem setDataToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem leftChannelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rightChannelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openRToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stereoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem convolveLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem convolveRToolStripMenuItem;
    }
}

