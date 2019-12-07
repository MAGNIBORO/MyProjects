using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;

namespace Atio_Terminal
{
    public partial class Form1 : Form
    {
        static bool active = false;
        static SerialPort _serialPort;
        Thread readThread = new Thread(Read);
        Thread writeThread = new Thread(Write);
        

        public Form1()
        {
            InitializeComponent();
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
            CheckForIllegalCrossThreadCalls = false;
            ScanPorts(COMlist);
        }
        private void Button1_Click_1(object sender, EventArgs e)
        {
            ScanPorts(COMlist);
        }
        
        private void Button1_Click(object sender, EventArgs e)
        {
               active = !active;
            
               _serialPort = new SerialPort();

            try { _serialPort.PortName = COMlist.SelectedItem.ToString(); }
            catch (ArgumentNullException) { MessageBox.Show("Invalid Port"); }

               _serialPort.BaudRate = 38400;
               _serialPort.ReadTimeout = 500;
               _serialPort.WriteTimeout = 500;

            if (active)
            {
                
                //  readThread.Start();
                try {
                    _serialPort.Open();
                }
                catch(UnauthorizedAccessException a)
                { MessageBox.Show("Puerto En Uso"); }

                writeThread.Start();
            }
            else
            {
                writeThread.Abort();
              //  readThread.Join();
                _serialPort.Close();
            }

        }

        void ScanPorts(ComboBox a)
        {
            a.Items.Clear();

            foreach (string s in SerialPort.GetPortNames())
            {
                a.Items.Add(s);
            }
        }
        public static void Read()
        {
                try
                {
                    string message = _serialPort.ReadTo("\r");
                    Console.WriteLine(message);
                }
                catch (TimeoutException) { }
        }

        public static void Write()
        {
            _serialPort.WriteLine("a");
         /*   while(true)
            {
                string message;
                Form1 a = new Form1();


                if (!a.OutBox.Text.Equals(""))
                {
                    int last = a.OutBox.Text.Length;

                    if ((a.OutBox.Text[last - 1] == '\n') && (a.OutBox.Text[last - 2] == '\r'))
                    {
                        message = a.OutBox.Text;
                        _serialPort.WriteLine(message);
                        a.OutBox.Clear();
                    }

                }
            }*/
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void MenuStrip2_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void OutBox_TextChanged(object sender, EventArgs e)
        {
        }
        private void NoneToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void LToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }


        private void ComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void PictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void PictureBox1_LoadCompleted(object sender, AsyncCompletedEventArgs e)
        {

        }

        private void AToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void NanoNGToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }



    /*

        public class PortChat
        {



            // Display Port values and prompt user to enter a port.
            public static string SetPortName(string defaultPortName)
            {
                string portName;

                Console.WriteLine("Available Ports:");
                foreach (string s in SerialPort.GetPortNames())
                {
                    Console.WriteLine("   {0}", s);
                }

                Console.Write("Enter COM port value (Default: {0}): ", defaultPortName);
                portName = Console.ReadLine();

                if (portName == "" || !(portName.ToLower()).StartsWith("com"))
                {
                    portName = defaultPortName;
                }
                return portName;
            }
            // Display BaudRate values and prompt user to enter a value.
            public static int SetPortBaudRate(int defaultPortBaudRate)
            {
                string baudRate;

                Console.Write("Baud Rate(default:{0}): ", defaultPortBaudRate);
                baudRate = Console.ReadLine();

                if (baudRate == "")
                {
                    baudRate = defaultPortBaudRate.ToString();
                }

                return int.Parse(baudRate);
            }

            // Display PortParity values and prompt user to enter a value.
            public static Parity SetPortParity(Parity defaultPortParity)
            {
                string parity;

                Console.WriteLine("Available Parity options:");
                foreach (string s in Enum.GetNames(typeof(Parity)))
                {
                    Console.WriteLine("   {0}", s);
                }

                Console.Write("Enter Parity value (Default: {0}):", defaultPortParity.ToString(), true);
                parity = Console.ReadLine();

                if (parity == "")
                {
                    parity = defaultPortParity.ToString();
                }

                return (Parity)Enum.Parse(typeof(Parity), parity, true);
            }
            // Display DataBits values and prompt user to enter a value.
            public static int SetPortDataBits(int defaultPortDataBits)
            {
                string dataBits;

                Console.Write("Enter DataBits value (Default: {0}): ", defaultPortDataBits);
                dataBits = Console.ReadLine();

                if (dataBits == "")
                {
                    dataBits = defaultPortDataBits.ToString();
                }

                return int.Parse(dataBits.ToUpperInvariant());
            }

            // Display StopBits values and prompt user to enter a value.
            public static StopBits SetPortStopBits(StopBits defaultPortStopBits)
            {
                string stopBits;

                Console.WriteLine("Available StopBits options:");
                foreach (string s in Enum.GetNames(typeof(StopBits)))
                {
                    Console.WriteLine("   {0}", s);
                }

                Console.Write("Enter StopBits value (None is not supported and \n" +
                 "raises an ArgumentOutOfRangeException. \n (Default: {0}):", defaultPortStopBits.ToString());
                stopBits = Console.ReadLine();

                if (stopBits == "")
                {
                    stopBits = defaultPortStopBits.ToString();
                }

                return (StopBits)Enum.Parse(typeof(StopBits), stopBits, true);
            }
            public static Handshake SetPortHandshake(Handshake defaultPortHandshake)
            {
                string handshake;

                Console.WriteLine("Available Handshake options:");
                foreach (string s in Enum.GetNames(typeof(Handshake)))
                {
                    Console.WriteLine("   {0}", s);
                }

                Console.Write("Enter Handshake value (Default: {0}):", defaultPortHandshake.ToString());
                handshake = Console.ReadLine();

                if (handshake == "")
                {
                    handshake = defaultPortHandshake.ToString();
                }

                return (Handshake)Enum.Parse(typeof(Handshake), handshake, true);
            }
        }
        */


}






