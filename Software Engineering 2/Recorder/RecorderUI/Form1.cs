using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using VideoRecorder;
using Tape;

namespace RecorderUI
{
    public partial class Form1 : Form
    {

        private Recorder recorderStateMachine = new Recorder();
        private Tape.Tape tape1 = new Tape.Tape();
        public Form1()
        {
            InitializeComponent();
            setLabel();
        }

        private void setLabel()
        {
            label1.Text = recorderStateMachine.CurrentState.ToString();

            string stateText = "";
            string directionText = "";

            switch (tape1.CurrentState)
            {
                case Tape.Tape.State.TapeOut:
                    stateText = "Tape Out";
                    break;

                case Tape.Tape.State.TapeIn:
                    stateText = "Inserting Tape";
                    break;

                case Tape.Tape.State.TapePlay:
                    stateText = "Playing";
                    break;

                case Tape.Tape.State.TapeRecord:
                    stateText = "Recording";
                    break;

                case Tape.Tape.State.TapeRewind:
                    stateText = "Rewinding";
                    break;

                case Tape.Tape.State.TapeFastForward:
                    stateText = "Fast Forwarding";
                    break;

                case Tape.Tape.State.TapeStop:
                    stateText = "Stopped";
                    break;
            }

            switch (tape1.CurrentDirection)
            {
                case Tape.Tape.Direction.Start:
                    directionText = " (Start)";
                    break;

                case Tape.Tape.Direction.Running:
                    directionText = " (Running)";
                    break;

                case Tape.Tape.Direction.End:
                    directionText = " (End)";
                    break;

                case Tape.Tape.Direction.Stopped:
                    directionText = " (Stopped)";
                    break;

                case Tape.Tape.Direction.Forwarding:
                    directionText = " (FastForward)";
                    break;

                case Tape.Tape.Direction.Rewinding:
                    directionText = " (Rewind)";
                    break;
            }

            label2.Text = stateText + directionText;
        }

        private void play_Click(object sender, EventArgs e)
        {
            recorderStateMachine.ProcessTransition(Recorder.Trigger.Play);
            tape1.ProcessTransition(Tape.Tape.Trigger.Play);
            setLabel();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            recorderStateMachine.ProcessTransition(Recorder.Trigger.Stop);
            tape1.ProcessTransition(Tape.Tape.Trigger.Stop);
            setLabel();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            recorderStateMachine.ProcessTransition(Recorder.Trigger.Rewind);
            tape1.ProcessTransition(Tape.Tape.Trigger.Rewind);
            setLabel();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            recorderStateMachine.ProcessTransition(Recorder.Trigger.FastForward);
            tape1.ProcessTransition(Tape.Tape.Trigger.FastForward);
            setLabel();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            recorderStateMachine.ProcessTransition(Recorder.Trigger.Record);
            tape1.ProcessTransition(Tape.Tape.Trigger.Record);
            setLabel();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            tape1.ProcessTransition(Tape.Tape.Trigger.Out);
            setLabel();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            tape1.ProcessTransition(Tape.Tape.Trigger.In);
            setLabel();
        }
    }
}
