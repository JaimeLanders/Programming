using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SEH__Code_Challenge
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void imageCheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void titleTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void bodyRichTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void getImagesButton_Click(object sender, EventArgs e)
        {
            if (titleTextBox.Text != null)
            {
                System.Windows.Forms.MessageBox.Show(titleTextBox.Text);
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("Please enter a valid title");
            }
        }
    }
}
