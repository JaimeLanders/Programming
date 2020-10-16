using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using HtmlAgilityPack;
//using Microsoft.Office.Core;
//using Microsoft.Office.Interop.PowerPoint;
using Syncfusion.Presentation;

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
            List<string> images = getUrls(keywords);

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
     
        private List<string> getUrls(string keywords)
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
                List<string> images = new List<string>();
//                string image = null;

                if (imageCheckBox1.Checked)
                {
                    images.Add(pictureBox1.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox2.Checked)
                {
                    images.Add(pictureBox2.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox3.Checked)
                {
                    images.Add(pictureBox3.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox4.Checked)
                {
                    images.Add(pictureBox4.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox5.Checked)
                {
                    images.Add(pictureBox5.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox6.Checked)
                {
                    images.Add(pictureBox6.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox7.Checked)
                {
                    images.Add(pictureBox7.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox8.Checked)
                {
                    images.Add(pictureBox8.ImageLocation);
                    nChecked++;
                }
                if (imageCheckBox9.Checked)
                {
                    images.Add(pictureBox9.ImageLocation);
                    nChecked++;
                }

                if (nChecked < 3)
                    MessageBox.Show("Please select at least 3 images");
                else
                {
//                    MessageBox.Show(nChecked.ToString());

                    createPresentation(titleTextBox.Text, bodyRichTextBox.Text, images);
                }

            }
        }

        public void createPresentation(string title, string body, List<string> images)
        {
/*
            Microsoft.Office.Interop.PowerPoint.Application pptApplication = new Microsoft.Office.Interop.PowerPoint.Application();

            Microsoft.Office.Interop.PowerPoint.Slides slides;
            Microsoft.Office.Interop.PowerPoint._Slide slide;
            Microsoft.Office.Interop.PowerPoint.TextRange objText;


*//*            using (WebClient client = new WebClient())
            {
                int i = 0;
                foreach (string image in images)
                {
                    string localImage = @"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image{i}.jpg";
//                client.DownloadFile(new Uri(url), "c:\temp\image35.png");
//                client.DownloadFile(new Uri(image), "C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image1.jpg");
                    client.DownloadFile(new Uri(image), localImage);
                    // OR 
//              client.DownloadFileAsync(new Uri(url), @"c:\temp\image35.png");
                }
            }
*//*
            // Create the Presentation File
            Presentation pptPresentation = pptApplication.Presentations.Add(MsoTriState.msoTrue);

//            Microsoft.Office.Interop.PowerPoint.CustomLayout customLayout = pptPresentation.SlideMaster.CustomLayouts[Microsoft.Office.Interop.PowerPoint.PpSlideLayout.ppLayoutText];
            Microsoft.Office.Interop.PowerPoint.CustomLayout customLayout = pptPresentation.SlideMaster.CustomLayouts[Microsoft.Office.Interop.PowerPoint.PpSlideLayout.ppLayoutFourObjects];

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

            // Download and add images to slide
//            Microsoft.Office.Interop.PowerPoint.Shape shape = slide.Shapes[2];
            Microsoft.Office.Interop.PowerPoint.Shape shape = slide.Shapes[3];
//            slide.Shapes.AddPicture(@"C: \Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image1", Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, shape.Width, shape.Height);
            using (WebClient client = new WebClient())
            {
                int i = 0;
                foreach (string image in images)
                {
//                    string localImage = @"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image{i}.jpg";
                    string localImage = $@"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image{i}.jpg";
//                client.DownloadFile(new Uri(url), "c:\temp\image35.png");
//                client.DownloadFile(new Uri(image), "C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\image1.jpg");
                    client.DownloadFile(new Uri(image), localImage);
//                    slide.Shapes.AddPicture(localImage, Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, shape.Width, shape.Height);
                    slide.Shapes.AddPicture(localImage, Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, 140, 140);
                    // OR 
//              client.DownloadFileAsync(new Uri(url), @"c:\temp\image35.png");
                    if ( i == 0)
                        slide.Shapes.AddPicture(localImage, Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, 140, 140);
                    if (i == 1)
                        slide.Shapes.AddPicture(localImage, Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, 140, 140);
                    if (i > 2)
                        break;
                }
            }

//            slide.Shapes.AddPicture(localImage, Microsoft.Office.Core.MsoTriState.msoFalse, Microsoft.Office.Core.MsoTriState.msoTrue, shape.Left, shape.Top, shape.Width, shape.Height);

            slide.NotesPage.Shapes[2].TextFrame.TextRange.Text = "Test";
            pptPresentation.SaveAs(@"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge", Microsoft.Office.Interop.PowerPoint.PpSaveAsFileType.ppSaveAsDefault, MsoTriState.msoTrue);
            pptPresentation.Close();
            pptApplication.Quit();
*/
            //Create a new instance of PowerPoint Presentation file
            IPresentation pptxDoc = Presentation.Create();

            //Add a new slide to file and apply background color
            ISlide slide = pptxDoc.Slides.Add(SlideLayoutType.TitleOnly);

            //Specify the fill type and fill color for the slide background 
            slide.Background.Fill.FillType = FillType.Solid;
//            slide.Background.Fill.SolidFill.Color = ColorObject.FromArgb(232, 241, 229);
            slide.Background.Fill.SolidFill.Color = ColorObject.FromArgb(255, 255, 255);

            //Add title content to the slide by accessing the title placeholder of the TitleOnly layout-slide
            IShape titleShape = slide.Shapes[0] as IShape;
//            titleShape.TextBody.AddParagraph("Company History").HorizontalAlignment = HorizontalAlignmentType.Center;
            titleShape.TextBody.AddParagraph(title).HorizontalAlignment = HorizontalAlignmentType.Center;

            //Add description content to the slide by adding a new TextBox
            IShape descriptionShape = slide.AddTextBox(53.22, 141.73, 874.19, 77.70);
            //            descriptionShape.TextBody.Text = "IMN Solutions PVT LTD is the software company, established in 1987, by George Milton. The company has been listed as the trusted partner for many high-profile organizations since 1988 and got awards for quality products from reputed organizations.";
            descriptionShape.TextBody.Text = body;

            //Gets a picture as stream.
            //            Stream pictureStream = File.Open(@"C:\Users\Jaime Landers\Dropbox\Programming\C#\SEH Code Challenge\SEH  Code Challenge\SEH  Code Challenge\Image.jpg", FileMode.Open);

            //Adds the picture to a slide by specifying its size and position.
            //            slide.Shapes.AddPicture(pictureStream, 499.79, 238.59, 364.54, 192.16);

            using (WebClient client = new WebClient())
            {
                int i = 0;
                foreach (string image in images)
                {
                    string localImage = $@"..\..\image{i}.jpg";

                    client.DownloadFile(new Uri(image), localImage);
//                    client.DownloadFile(new Uri(images[i]), localImage);

                    //Gets a picture as stream.
                    Stream pictureStream = File.Open(localImage, FileMode.Open);

                    //Adds the picture to a slide by specifying its size and position.
                    if ( i == 0)
                        slide.Shapes.AddPicture(pictureStream, 199.79, 238.59, 140, 140);
                    else if (i == 1)
                        slide.Shapes.AddPicture(pictureStream, 349.79, 238.59, 140, 140);
                    else if (i == 2)
                        slide.Shapes.AddPicture(pictureStream, 499.79, 238.59, 140, 140);
                    else 
                        break;

                    pictureStream.Close();

                    i++;
                }
            }

            //Save the PowerPoint Presentation 
            pptxDoc.Save(@"..\..\SEH Challenge.pptx");

            //Close the PowerPoint presentation
            pptxDoc.Close();

        }
    }
}
