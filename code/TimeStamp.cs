using System;

namespace SimpleTimestamp
{
    public class TimeStamp
    {

        public void TsMessage(string username, string x)
        {
            Console.WriteLine("{0} - {1}: {2}",DateTime.Now ,username, x);
        }
    }
}
