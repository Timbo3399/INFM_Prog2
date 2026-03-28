using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VideoRecorder
{

    public class Recorder
    {
        public enum State
        {
            Playing,
            Rewinding,
            FastForwarding,
            Standby,
            Recording
        }

        public enum Trigger
        {
            Play,
            Stop,
            FastForward,
            Rewind,
            Record,
            End,
            Begin
        }

        private Dictionary<(State, Trigger), State> _stateTransitions;
        public State CurrentState { get; private set; }

        public Recorder()
        {
            CurrentState = State.Standby;
            _stateTransitions = new Dictionary<(State, Trigger), State>
            {
                { (State.Standby, Trigger.Play), State.Playing },
                { (State.Standby, Trigger.Record), State.Recording },
                { (State.Standby, Trigger.FastForward), State.FastForwarding },
                { (State.Standby, Trigger.Rewind), State.Rewinding },
                { (State.Standby, Trigger.Stop), State.Standby },
                { (State.Playing, Trigger.Stop), State.Standby },
                { (State.Playing, Trigger.End), State.Standby },
                { (State.Playing, Trigger.Rewind), State.Rewinding },
                { (State.Playing, Trigger.FastForward), State.FastForwarding },
                { (State.Rewinding, Trigger.Stop), State.Standby },
                { (State.Rewinding, Trigger.Play), State.Playing },
                { (State.Rewinding, Trigger.FastForward), State.FastForwarding },
                { (State.Rewinding, Trigger.Begin), State.Standby },
                { (State.FastForwarding, Trigger.Stop), State.Standby },
                { (State.FastForwarding, Trigger.Play), State.Playing },
                { (State.FastForwarding, Trigger.End), State.Standby },
                { (State.FastForwarding, Trigger.Rewind), State.Rewinding },
                { (State.Recording, Trigger.Stop), State.Standby },
                { (State.Recording, Trigger.End), State.Standby },
            };
        }
        public void ProcessTransition(Trigger trigger)
        {
            if (_stateTransitions.TryGetValue((CurrentState, trigger), out State newState))
            {
                Console.WriteLine($"Moving from {CurrentState} to {newState} due to {trigger}");
                CurrentState = newState;
            }
            else
            {
                Console.WriteLine($"Invalid transition: {CurrentState} cannot handle {trigger}");
            }
        }
    }
}
