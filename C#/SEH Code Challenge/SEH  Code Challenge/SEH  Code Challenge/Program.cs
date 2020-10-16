/*
 * Name:    Jaime Landers
 * Title:   SEH Code Challenge
 * Date:    10/15/20
 * Purpose: To demonstrate proficiency in C# for SEH America 
 * Notes:   None
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace SEH__Code_Challenge
{
    static class Program
    {
//        static readonly HttpClient client = new HttpClient();
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
