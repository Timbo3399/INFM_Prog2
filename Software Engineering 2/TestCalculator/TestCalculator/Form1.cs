using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestCalculator
{
    public partial class Form1 : Form
    {
        private Calculator _calc;
        public Form1()
        {
            InitializeComponent();
            _calc = new Calculator();
            _calc.CalcFinished += CalcOnCalcFinished;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            _calc.Add(numericUpDown1.Value,numericUpDown2.Value);
        }

        private void CalcOnCalcFinished(object sender, CalcEventArgs e)
        {
            label1.Text = e.Result.ToString();
        }
    }

    public class Calculator
    {
        public delegate void CalcEventHandler(object sender, CalcEventArgs e);
        public event CalcEventHandler CalcFinished ; 
        public void Add(decimal d1, decimal d2)
        {
            var res = d1 + d2;

            CalcFinished(this,new CalcEventArgs(res));

        }
    }

    public class CalcEventArgs : EventArgs
    {
        public decimal Result { get; private set; }

        public CalcEventArgs(decimal result)
        {
            Result = result;
        }
    }
}
