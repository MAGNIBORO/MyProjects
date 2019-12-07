namespace Atio_Terminal
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.butCon = new System.Windows.Forms.Button();
            this.menuStrip2 = new System.Windows.Forms.MenuStrip();
            this.aToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nanoNGToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.configurationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fontToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.autoScrollToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.COMlist = new System.Windows.Forms.ComboBox();
            this.butScan = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.InBox = new System.Windows.Forms.TextBox();
            this.OutBox = new System.Windows.Forms.TextBox();
            this.menuStrip2.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // butCon
            // 
            this.butCon.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(51)))), ((int)(((byte)(52)))));
            this.butCon.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.butCon.FlatAppearance.MouseDownBackColor = System.Drawing.Color.SpringGreen;
            this.butCon.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.Highlight;
            this.butCon.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.butCon.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.butCon.Location = new System.Drawing.Point(12, 29);
            this.butCon.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.butCon.Name = "butCon";
            this.butCon.Size = new System.Drawing.Size(74, 50);
            this.butCon.TabIndex = 0;
            this.butCon.Text = "Connect";
            this.butCon.UseVisualStyleBackColor = false;
            this.butCon.Click += new System.EventHandler(this.Button1_Click);
            // 
            // menuStrip2
            // 
            this.menuStrip2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(110)))), ((int)(((byte)(110)))), ((int)(((byte)(110)))));
            this.menuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aToolStripMenuItem,
            this.configurationToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.lToolStripMenuItem});
            this.menuStrip2.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.menuStrip2.Location = new System.Drawing.Point(0, 0);
            this.menuStrip2.Name = "menuStrip2";
            this.menuStrip2.Size = new System.Drawing.Size(1364, 24);
            this.menuStrip2.TabIndex = 3;
            this.menuStrip2.Text = "menuStrip2";
            this.menuStrip2.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.MenuStrip2_ItemClicked);
            // 
            // aToolStripMenuItem
            // 
            this.aToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.nanoNGToolStripMenuItem});
            this.aToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.aToolStripMenuItem.Name = "aToolStripMenuItem";
            this.aToolStripMenuItem.Size = new System.Drawing.Size(54, 20);
            this.aToolStripMenuItem.Text = "Device";
            this.aToolStripMenuItem.Click += new System.EventHandler(this.AToolStripMenuItem_Click);
            // 
            // nanoNGToolStripMenuItem
            // 
            this.nanoNGToolStripMenuItem.Checked = true;
            this.nanoNGToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.nanoNGToolStripMenuItem.Name = "nanoNGToolStripMenuItem";
            this.nanoNGToolStripMenuItem.Size = new System.Drawing.Size(123, 22);
            this.nanoNGToolStripMenuItem.Text = "Nano NG";
            // 
            // configurationToolStripMenuItem
            // 
            this.configurationToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fontToolStripMenuItem});
            this.configurationToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.configurationToolStripMenuItem.Name = "configurationToolStripMenuItem";
            this.configurationToolStripMenuItem.Size = new System.Drawing.Size(93, 20);
            this.configurationToolStripMenuItem.Text = "Configuration";
            // 
            // fontToolStripMenuItem
            // 
            this.fontToolStripMenuItem.Name = "fontToolStripMenuItem";
            this.fontToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.fontToolStripMenuItem.Text = "Font";
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.clearToolStripMenuItem,
            this.autoScrollToolStripMenuItem});
            this.viewToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "View";
            // 
            // clearToolStripMenuItem
            // 
            this.clearToolStripMenuItem.Name = "clearToolStripMenuItem";
            this.clearToolStripMenuItem.Size = new System.Drawing.Size(129, 22);
            this.clearToolStripMenuItem.Text = "Clear";
            // 
            // autoScrollToolStripMenuItem
            // 
            this.autoScrollToolStripMenuItem.Checked = true;
            this.autoScrollToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.autoScrollToolStripMenuItem.Name = "autoScrollToolStripMenuItem";
            this.autoScrollToolStripMenuItem.Size = new System.Drawing.Size(129, 22);
            this.autoScrollToolStripMenuItem.Text = "AutoScroll";
            // 
            // lToolStripMenuItem
            // 
            this.lToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.lToolStripMenuItem.Name = "lToolStripMenuItem";
            this.lToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.lToolStripMenuItem.Text = "Log";
            this.lToolStripMenuItem.Click += new System.EventHandler(this.LToolStripMenuItem_Click);
            // 
            // COMlist
            // 
            this.COMlist.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(71)))), ((int)(((byte)(77)))), ((int)(((byte)(78)))));
            this.COMlist.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.COMlist.ForeColor = System.Drawing.Color.White;
            this.COMlist.FormattingEnabled = true;
            this.COMlist.Location = new System.Drawing.Point(260, 27);
            this.COMlist.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.COMlist.Name = "COMlist";
            this.COMlist.Size = new System.Drawing.Size(94, 21);
            this.COMlist.TabIndex = 6;
            this.COMlist.SelectedIndexChanged += new System.EventHandler(this.ComboBox1_SelectedIndexChanged);
            // 
            // butScan
            // 
            this.butScan.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(51)))), ((int)(((byte)(52)))));
            this.butScan.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.butScan.FlatAppearance.MouseDownBackColor = System.Drawing.Color.SpringGreen;
            this.butScan.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.Highlight;
            this.butScan.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.butScan.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.butScan.Location = new System.Drawing.Point(92, 29);
            this.butScan.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.butScan.Name = "butScan";
            this.butScan.Size = new System.Drawing.Size(74, 50);
            this.butScan.TabIndex = 7;
            this.butScan.Text = "Scan";
            this.butScan.UseVisualStyleBackColor = false;
            this.butScan.Click += new System.EventHandler(this.Button1_Click_1);
            // 
            // statusStrip1
            // 
            this.statusStrip1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(110)))), ((int)(((byte)(110)))), ((int)(((byte)(110)))));
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 627);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1364, 22);
            this.statusStrip1.TabIndex = 5;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.ActiveLinkColor = System.Drawing.Color.White;
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(65, 17);
            this.toolStripStatusLabel1.Text = "Connected";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(51)))), ((int)(((byte)(52)))));
            this.pictureBox1.Image = global::Atio_Terminal.Properties.Resources.logo4_section42;
            this.pictureBox1.Location = new System.Drawing.Point(0, 529);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(124, 96);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 8;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.LoadCompleted += new System.ComponentModel.AsyncCompletedEventHandler(this.PictureBox1_LoadCompleted);
            this.pictureBox1.Click += new System.EventHandler(this.PictureBox1_Click);
            // 
            // InBox
            // 
            this.InBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(140)))), ((int)(((byte)(140)))), ((int)(((byte)(140)))));
            this.InBox.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InBox.Location = new System.Drawing.Point(8, 85);
            this.InBox.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.InBox.Multiline = true;
            this.InBox.Name = "InBox";
            this.InBox.ReadOnly = true;
            this.InBox.Size = new System.Drawing.Size(1344, 448);
            this.InBox.TabIndex = 9;
            this.InBox.TextChanged += new System.EventHandler(this.TextBox1_TextChanged);
            // 
            // OutBox
            // 
            this.OutBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(140)))), ((int)(((byte)(140)))), ((int)(((byte)(140)))));
            this.OutBox.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OutBox.Location = new System.Drawing.Point(8, 619);
            this.OutBox.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.OutBox.Multiline = true;
            this.OutBox.Name = "OutBox";
            this.OutBox.Size = new System.Drawing.Size(1344, 53);
            this.OutBox.TabIndex = 10;
            this.OutBox.TextChanged += new System.EventHandler(this.OutBox_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(51)))), ((int)(((byte)(52)))));
            this.ClientSize = new System.Drawing.Size(1364, 649);
            this.Controls.Add(this.OutBox);
            this.Controls.Add(this.InBox);
            this.Controls.Add(this.butScan);
            this.Controls.Add(this.COMlist);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.butCon);
            this.Controls.Add(this.menuStrip2);
            this.Controls.Add(this.pictureBox1);
            this.Font = new System.Drawing.Font("Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.Name = "Form1";
            this.Text = "Atio Terminal";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseClick);
            this.menuStrip2.ResumeLayout(false);
            this.menuStrip2.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button butCon;
        private System.Windows.Forms.MenuStrip menuStrip2;
        private System.Windows.Forms.ToolStripMenuItem aToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem configurationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fontToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem autoScrollToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lToolStripMenuItem;
        private System.Windows.Forms.ComboBox COMlist;
        private System.Windows.Forms.Button butScan;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolStripMenuItem nanoNGToolStripMenuItem;
        private System.Windows.Forms.TextBox InBox;
        private System.Windows.Forms.TextBox OutBox;
    }
}

