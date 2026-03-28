using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tape
{
    public class Tape
    {
        public enum State
        {
            TapeIn,
            TapePlay,
            TapeOut,
            TapeRecord,
            TapeRewind,
            TapeFastForward,
            TapeStop
        }

        public enum Direction
        {
            Start,
            End,
            Running,
            Stopped,
            Rewinding,
            Forwarding
        }

        public enum Trigger
        {
            Play,
            Stop,
            FastForward,
            Rewind,
            Record,
            In,
            Out
        }

        private Dictionary<(State, Direction, Trigger), (State, Direction)> _stateTransitions;
        public State CurrentState { get; private set; }
        public Direction CurrentDirection { get; private set; }

        public Tape()
        {
            CurrentState = State.TapeOut;
            CurrentDirection = Direction.Start;
            _stateTransitions = new Dictionary<(State, Direction, Trigger), (State, Direction)>
            {
                // =========================
                // TapeIn
                // =========================
                { (State.TapeIn, Direction.Start, Trigger.In), (State.TapeIn, Direction.Running) },
                { (State.TapeIn, Direction.Running, Trigger.In), (State.TapeIn, Direction.End) },
                { (State.TapeIn, Direction.End, Trigger.In), (State.TapeStop, Direction.Start) },
                { (State.TapeIn, Direction.Start, Trigger.Play), (State.TapePlay, Direction.Start) },
                { (State.TapeIn, Direction.Running, Trigger.Play), (State.TapePlay, Direction.Start) },

                // =========================
                // TapeOut
                // =========================
                { (State.TapeOut, Direction.Start, Trigger.Out), (State.TapeOut, Direction.Start) },
                { (State.TapeOut, Direction.Running, Trigger.Out), (State.TapeOut, Direction.Running) },
                { (State.TapeOut, Direction.End, Trigger.Out), (State.TapeOut, Direction.End) },
                { (State.TapeOut, Direction.Start, Trigger.In), (State.TapeIn, Direction.Start) },
                { (State.TapeOut, Direction.Running, Trigger.In), (State.TapeIn, Direction.Running) },
                { (State.TapeOut, Direction.End, Trigger.In), (State.TapeIn, Direction.End) },

                // =========================
                // TapePlay
                // =========================
                { (State.TapePlay, Direction.Start, Trigger.Play), (State.TapePlay, Direction.Running) },
                { (State.TapePlay, Direction.Running, Trigger.Play), (State.TapePlay, Direction.End) },
                { (State.TapePlay, Direction.Start, Trigger.Stop), (State.TapeStop, Direction.Stopped) },
                { (State.TapePlay, Direction.Running, Trigger.Stop), (State.TapeStop, Direction.Stopped) },
                { (State.TapePlay, Direction.End, Trigger.Stop), (State.TapeStop, Direction.End) },

                // =========================
                // TapeStop
                // =========================
                { (State.TapeStop, Direction.Start, Trigger.Play), (State.TapePlay, Direction.Running) },
                { (State.TapeStop, Direction.Running, Trigger.Play), (State.TapePlay, Direction.End) },
                { (State.TapeStop, Direction.Start, Trigger.FastForward), (State.TapePlay, Direction.Forwarding) },
                { (State.TapeStop, Direction.Running, Trigger.FastForward), (State.TapePlay, Direction.Forwarding) },
                { (State.TapeStop, Direction.Running, Trigger.Out), (State.TapeOut, Direction.Running) },
                { (State.TapeStop, Direction.Start, Trigger.Out), (State.TapeOut, Direction.Start) },
                { (State.TapeStop, Direction.End, Trigger.Out), (State.TapeOut, Direction.End) },
                { (State.TapeStop, Direction.Stopped, Trigger.Out), (State.TapeOut, Direction.Stopped) },

                // =========================
                // RECORD
                // =========================
                { (State.TapeRecord, Direction.Start, Trigger.Record), (State.TapeRecord, Direction.Running) },
                { (State.TapeRecord, Direction.Running, Trigger.Stop), (State.TapeRecord, Direction.End) },
                { (State.TapeRecord, Direction.End, Trigger.Stop), (State.TapeStop, Direction.Start) },

                // =========================
                // FAST FORWARD
                // =========================
                { (State.TapeFastForward, Direction.Start, Trigger.FastForward), (State.TapeFastForward, Direction.Running) },
                { (State.TapeFastForward, Direction.Running, Trigger.Stop), (State.TapeFastForward, Direction.End) },
                { (State.TapeFastForward, Direction.End, Trigger.Stop), (State.TapeStop, Direction.Start) },

                // =========================
                // REWIND
                // =========================
                { (State.TapeRewind, Direction.Start, Trigger.Rewind), (State.TapeRewind, Direction.Running) },
                { (State.TapeRewind, Direction.Running, Trigger.Stop), (State.TapeRewind, Direction.End) },
                { (State.TapeRewind, Direction.End, Trigger.Stop), (State.TapeStop, Direction.Start) },
            };
        }

        public void ProcessTransition(Trigger trigger)
        {
            if (_stateTransitions.TryGetValue((CurrentState, CurrentDirection, trigger), out var result))
            {
                var (newState, newDirection) = result;

                Console.WriteLine($"Moving from {CurrentState} to {newState} due to {trigger}");
                CurrentState = newState;
                CurrentDirection = newDirection;
            }
            else
            {
                Console.WriteLine($"Invalid transition: {CurrentState} cannot handle {trigger}");
            }
        }
    }
}
