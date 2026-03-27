using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            Pen penlines = new Pen(Color.Black, 1);
            penlines.EndCap = LineCap.ArrowAnchor;
            e.Graphics.DrawLine(penlines, 10, 10, panel1.Width - 10, 10);
            e.Graphics.DrawLine(penlines, 10, 10, 10, panel1.Height - 10);
            e.Graphics.DrawEllipse(new Pen(Color.Black, 3), panel1.Width - 50, 50, 20, 20);
            e.Graphics.DrawEllipse(new Pen(Color.Black, 3), 50, panel1.Height - 50, 20, 20);
        }

        private void panel1_Resize(object sender, EventArgs e)
        {
            panel1.Invalidate();
        }
    }
}
