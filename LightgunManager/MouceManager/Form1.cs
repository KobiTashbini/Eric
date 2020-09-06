using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Management;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MouceManager
{
    public partial class Form1 : Form
    {
        Hashtable OutputHash = new Hashtable();
        static SerialPort dd;
        string arduinoReturnedValue = "NA";
        static string tempPort = ConfigurationManager.AppSettings.Get("comNumber");
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            ManagementObjectCollection mbsList = null;
            ManagementObjectSearcher mbs = new ManagementObjectSearcher("Select * From Win32_USBHub");
            mbsList = mbs.Get();

            foreach (ManagementObject mo in mbsList)
            {
                Console.WriteLine("USBHub device Friendly name:{0}", mo["Name"].ToString());
            }

            string[] portNames = SerialPort.GetPortNames();
            dd = new SerialPort();

            dd.BaudRate = 9600;
            dd.DtrEnable = true;
            dd.PortName = "COM" + tempPort.ToString();
            dd.Open();
            int dddd = dd.GetHashCode();
            // dd.DataReceived += 


        }




        static string port_DataReceived()
        {
         //   for (int i = 0; i < (10000 * dd.BytesToRead) / dd.BaudRate; i++)
      //          ;       //Delay a bit for the serial to catch up
          //  System.Threading.Thread.Sleep(200);
                   //        string result = dd.ReadExisting();
          //  if (result == null || result == "")
         //   {
            //    for (int i = 0; i < (10000 * dd.BytesToRead) / dd.BaudRate; i++)
      //              ;       //Delay a bit for the serial to catch up
             //   System.Threading.Thread.Sleep(500);
            ////         result = dd.ReadExisting();
            //   }
            //    if (result == null || result == "")
            //    {
            //       for (int i = 0; i < (10000 * dd.BytesToRead) / dd.BaudRate; i++)
            //     
            string result = "NA";
            try
            {
             //   dd.ReadTimeout = 1000;
                 result = dd.ReadLine();
            }
            catch (Exception e)
            {

                result = "EX";
            };       //Delay a bit for the serial to catch up
         
       //     }

          

            if (result == null)
            {
                result = "null";
            }
            if (result == "")
            {
                result = "empty";
            }

            //   string result = "NAAA";
            return result;
        }



        private void button1_Click(object sender, EventArgs e)
        {
            dd.Write("X");
            arduinoReturnedValue = port_DataReceived();
            X_RIGHT_LIMIT.Text = arduinoReturnedValue;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            dd.Write("x");
            arduinoReturnedValue = port_DataReceived();
            X_RIGHT_LIMIT.Text = arduinoReturnedValue;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            dd.Write("Y");
            arduinoReturnedValue = port_DataReceived();
            Y_UP_LIMIT.Text = arduinoReturnedValue;

        }

        private void button4_Click(object sender, EventArgs e)
        {
            dd.Write("y");
            arduinoReturnedValue = port_DataReceived();
            Y_UP_LIMIT.Text = arduinoReturnedValue;


        }

        private void button5_Click(object sender, EventArgs e)
        {
            dd.Write("W");
            arduinoReturnedValue = port_DataReceived();
            XSensitivity.Text = arduinoReturnedValue;


        }

        private void button6_Click(object sender, EventArgs e)
        {
            dd.Write("w");
            arduinoReturnedValue = port_DataReceived();
            XSensitivity.Text = arduinoReturnedValue;


        }

        private void button7_Click(object sender, EventArgs e)
        {
            dd.Write("H");
            arduinoReturnedValue = port_DataReceived();
            YSensitivityLabel.Text = arduinoReturnedValue;

        }

        private void button8_Click(object sender, EventArgs e)
        {
            dd.Write("h");
            arduinoReturnedValue = port_DataReceived();
            YSensitivityLabel.Text = arduinoReturnedValue;


        }

        private void button9_Click(object sender, EventArgs e)
        {
            dd.Write("Z");
            arduinoReturnedValue = port_DataReceived();

            Y_DOWN_LIMIT.Text = arduinoReturnedValue;


        }

        private void button10_Click(object sender, EventArgs e)
        {
            dd.Write("z");
            arduinoReturnedValue = port_DataReceived();
            Y_DOWN_LIMIT.Text = arduinoReturnedValue;

        }

        private void RestorNormal_Click(object sender, EventArgs e)
        {
            dd.Write("R");
            arduinoReturnedValue = port_DataReceived();
            GlobalMessage.Text = arduinoReturnedValue;

            X_RIGHT_LIMIT.Text = "857";
            X_LEFT_LIMIT.Text = "219";
            Y_UP_LIMIT.Text = "893";
            Y_DOWN_LIMIT.Text = "195";
            XSensitivity.Text = "218";
            YSensitivityLabel.Text = "209";
           
           
        }

        private void button11_Click(object sender, EventArgs e)
        {
            dd.Write("w");
            arduinoReturnedValue = port_DataReceived();
            X_LEFT_LIMIT.Text = arduinoReturnedValue;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            dd.Write("W");
            arduinoReturnedValue = port_DataReceived();
            X_LEFT_LIMIT.Text = arduinoReturnedValue;
        }
    }
}
