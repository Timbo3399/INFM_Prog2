using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Test01;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void button1_Click_1(object sender, EventArgs e)
        {

            var c = new Class1()
            {
                _name = "Test",
                count = 0
            };
            var num1 = numericUpDown1.Value;
            var num2 = numericUpDown2.Value;

            label1.Text = (num1 + num2).ToString();
        }
    }
}
