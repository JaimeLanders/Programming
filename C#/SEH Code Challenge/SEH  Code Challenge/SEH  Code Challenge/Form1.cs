using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using HtmlAgilityPack;
using Microsoft.Office.Core;
using Microsoft.Office.Interop.PowerPoint;

namespace SEH__Code_Challenge
{

    public partial class Form1 : Form
    {
//        static readonly HttpClient client = new HttpClient();

        private bool imagesLoaded = false;

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
/*
            // Get title and body from Windows Forms
            if (titleTextBox.Text != null)
            {
                System.Windows.Forms.MessageBox.Show(titleTextBox.Text + "\n" +
                    bodyRichTextBox.Text);
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("Please enter a valid title");
            }
*/

//            string keywords = titleTextBox.Text;
            string keywords = "Hello World";
            titleTextBox.Text = keywords;

//            string body = bodyRichTextBox.Text;
            string body = "My name is **Jaime Landers**, what is **your name** friend?";
            bodyRichTextBox.Text = body;

            String result = "";

            // Parse body for bold text and add to search keywords
            for (int i = 0; i < body.Length; i++)
            {
                int lIndex = 0;
                int rIndex = 0;
                if (body[i].Equals('*') && body[i + 1].Equals('*'))
                {
                    lIndex = i + 2;
                    rIndex = body.IndexOf("**", lIndex, body.Length - lIndex);

                    result = result + body.Substring(lIndex, rIndex - lIndex) + " ";
//                    Console.WriteLine("result = " + result);
                    if (rIndex + 2 < body.Length)
                        i = rIndex;
                    else
                        break;
                }
            }

            // Add body keywords to title
            keywords = keywords + " " + result;

            // Format keywords for Google search URL
            keywords = keywords.Replace(' ', '+');

            // Get images from Google
            List<string> images = aGetUris(keywords);

            // Load images into Windows Form app
            pictureBox1.Load(images[1]);
            pictureBox8.Load(images[2]);
            pictureBox9.Load(images[3]);
            pictureBox7.Load(images[4]);
            pictureBox2.Load(images[5]);
            pictureBox3.Load(images[6]);
            pictureBox4.Load(images[7]);
            pictureBox5.Load(images[8]);
            pictureBox6.Load(images[9]);
        }

        private void tableLayoutPanel4_Paint(object sender, PaintEventArgs e)
        {

        }

        private void pictureBox1_Click_1(object sender, EventArgs e)
        {

        }
     
        private List<string> aGetUris(string keywords)
        {
            // Source: https://stackoverflow.com/questions/4257359/regular-expression-to-get-the-src-of-images-in-c-sharp/4257450#4257450

            var url = $"https://www.google.com/search?q={keywords}&tbm=isch&site=imghp";

            List<string> images = new List<string>();
            System.Net.WebClient client = new System.Net.WebClient();
            var htmlText = client.DownloadString(url);

            var htmlDoc = new HtmlAgilityPack.HtmlDocument()
            {
                OptionFixNestedTags = true,
                OptionAutoCloseOnEnd = true
            };

            htmlDoc.LoadHtml(htmlText);

            foreach (HtmlNode img in htmlDoc.DocumentNode.SelectNodes("//img"))
            {
                HtmlAttribute att = img.Attributes["src"];
//                Console.WriteLine("att = " + att.Value);
                images.Add(att.Value);
            }

            imagesLoaded = true;

            return images;

        }

        private void tableLayoutPanel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void generatePowerPointButton_Click(object sender, EventArgs e)
        {
            if (!imagesLoaded)
                MessageBox.Show("Please 'Get Images' before generating PowerPoint");
            else
            {
                int nChecked = 0;
//                List<String> images = null;
                string image = null;

                if (imageCheckBox1.Checked)
                {
                    nChecked++;
//                    images.Add(pictureBox1.ImageLocation);
                    image = pictureBox1.ImageLocation;
                }
                if (imageCheckBox2.Checked)
                    nChecked++;
                if (imageCheckBox3.Checked)
                    nChecked++;
                if (imageCheckBox4.Checked)
                    nChecked++;
                if (imageCheckBox5.Checked)
                    nChecked++;
                if (imageCheckBox6.Checked)
                    nChecked++;
                if (imageCheckBox7.Checked)
                    nChecked++;
                if (imageCheckBox8.Checked)
                    nChecked++;
                if (imageCheckBox9.Checked)
                    nChecked++;

                if (nChecked < 3)
                    MessageBox.Show("Please select at least 3 images");
                else
                {
                    MessageBox.Show(nChecked.ToString());

                    createPresentation(titleTextBox.Text, bodyRichTextBox.Text, image);
                }

            }
        }

        public void createPresentation(string title, string body, string image)
        {
            Microsoft.Office.Interop.PowerPoint.Application pptApplication = new Microsoft.Office.Interop.PowerPoint.Application();

            Microsoft.Office.Interop.PowerPoint.Slides slides;
            Microsoft.Office.Interop.PowerPoint._Slide slide;
            Microsoft.Office.Interop.PowerPoint.TextRange objText;

            string localImage = @"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image1.jpg";

            using (WebClient client = new WebClient())
            {
//                client.DownloadFile(new Uri(url), "c:\temp\image35.png");
//                client.DownloadFile(new Uri(image), "C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image1.jpg");
                client.DownloadFile(new Uri(image), localImage);
                // OR 
//              client.DownloadFileAsync(new Uri(url), @"c:\temp\image35.png");
            }

            // Create the Presentation File
            Presentation pptPresentation = pptApplication.Presentations.Add(MsoTriState.msoTrue);

            Microsoft.Office.Interop.PowerPoint.CustomLayout customLayout = pptPresentation.SlideMaster.CustomLayouts[Microsoft.Office.Interop.PowerPoint.PpSlideLayout.ppLayoutText];

            // Create new Slide
            slides = pptPresentation.Slides;
            slide = slides.AddSlide(1, customLayout);

            // Add title
            objText = slide.Shapes[1].TextFrame.TextRange;
//            objText.Text = "FPPT.com";
            objText.Text = title;
            objText.Font.Name = "Arial";
            objText.Font.Size = 32;

            objText = slide.Shapes[2].TextFrame.TextRange;
//            objText.Text = "Content goes here\nYou can add text\nItem 3";
            objText.Text = body;

            Microsoft.Office.Interop.PowerPoint.Shape shape = slide.Shapes[2];
//            slide.Shapes.AddPicture(@"C: \Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image1", Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, shape.Width, shape.Height);
            slide.Shapes.AddPicture(localImage, Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, shape.Width, shape.Height);

            slide.NotesPage.Shapes[2].TextFrame.TextRange.Text = "Test";
            pptPresentation.SaveAs(@"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge", Microsoft.Office.Interop.PowerPoint.PpSaveAsFileType.ppSaveAsDefault, MsoTriState.msoTrue);
            pptPresentation.Close();
            pptApplication.Quit();
        }
    }
}
